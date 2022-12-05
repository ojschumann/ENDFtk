// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "ENDFtk/section/33.hpp"
#include "definitions.hpp"
#include "views.hpp"

// namespace aliases
namespace python = pybind11;

namespace mf33 {

  // declarations - components
  void wrapReactionBlock( python::module&, python::module& );
  void wrapDerivedRedundant( python::module&, python::module& );
  void wrapDerivedRatioToStandard( python::module&, python::module& );
  void wrapCovariancePairs( python::module&, python::module& );
  void wrapSquareMatrix( python::module&, python::module& );
  void wrapRectangularMatrix( python::module&, python::module& );
}

void wrapSection_33( python::module& module, python::module& viewmodule ) {

  // type aliases
  using Section = njoy::ENDFtk::section::Type< 33 >;
  using ReactionBlock = Section::ReactionBlock;
  using ReactionBlockRange = RandomAccessAnyView< ReactionBlock >;

  // wrap components
  mf33::wrapReactionBlock( module, viewmodule );
  mf33::wrapDerivedRedundant( module, viewmodule );
  mf33::wrapDerivedRatioToStandard( module, viewmodule );
  mf33::wrapCovariancePairs( module, viewmodule );
  mf33::wrapSquareMatrix( module, viewmodule );
  mf33::wrapRectangularMatrix( module, viewmodule );

  // wrap views created by this section
  // none of these are supposed to be created directly by the user
  wrapRandomAccessAnyViewOf< ReactionBlock >(
      module,
      "any_view< MF33::ReactionBlock, random_access >" );

  // create the section
  python::class_< Section > section(

    module,
    "Section",
    "MF33 section - covariances of cross sections"
  );

  // wrap the section
  section
  .def(

    python::init< int, double, double, std::vector< ReactionBlock >&& >(),
    python::arg( "mt" ), python::arg( "zaid" ), python::arg( "awr" ),
    python::arg( "reactions" ),
    "Initialise the section\n\n"
    "Arguments:\n"
    "    self        the section\n"
    "    mt          the MT number\n"
    "    zaid        the ZA  identifier\n"
    "    awr         the atomic mass ratio\n"
    "    reactions   the reactions (subsections) (at least 1)\n"
  )
  .def(

    python::init< int, double, double, int >(),
    python::arg( "mt" ), python::arg( "zaid" ), python::arg( "awr" ),
    python::arg( "mtl" ),
    "Initialise the section\n\n"
    "Arguments:\n"
    "    self        the section\n"
    "    mt          the MT number\n"
    "    zaid        the ZA  identifier\n"
    "    awr         the atomic mass ratio\n"
    "    mtl         the lumped covariance index\n"
  )
  .def_property_readonly(

    "MTL",
    &Section::MTL,
    "the lumped covariance index"
  )
  .def_property_readonly(

    "lumped_covariance_index",
    &Section::lumpedCovarianceIndex,
    "the lumped covariance index"
  )
  .def_property_readonly(

    "NL",
    &Section::NL,
    "the number of reaction blocks (subsections)"
  )
  .def_property_readonly(

    "number_reactions",
    &Section::numberReactions,
    "the number of reaction blocks (subsections)"
  )
  .def_property_readonly(

    "reactions",
    [] ( const Section& self ) -> ReactionBlockRange
       { return self.reactions(); },
    "the reactions (subsections) defined in this section"
  );

  // add standard section definitions
  addStandardSectionDefinitions< Section >( section );
}