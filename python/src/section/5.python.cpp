// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "ENDFtk/section/5.hpp"
#include "definitions.hpp"
#include "views.hpp"

// namespace aliases
namespace python = pybind11;

// declarations - components
void wrapOutgoingEnergyDistribution( python::module& );
void wrapTabulatedSpectrum( python::module& );
void wrapDistributionFunction( python::module& );
void wrapParameter( python::module& );
void wrapEffectiveTemperature( python::module& );
void wrapGeneralEvaporationSpectrum( python::module& );
void wrapEvaporationSpectrum( python::module& );
void wrapMaxwellianFissionSpectrum( python::module& );
void wrapWattSpectrum( python::module& );
void wrapMadlandNixSpectrum( python::module& );
void wrapProbability( python::module& );
void wrapPartialDistribution( python::module& );

void wrapSection_5( python::module& module ) {

  // type aliases
  using Section = njoy::ENDFtk::section::Type< 5 >;
  using PartialDistribution = njoy::ENDFtk::section::Type< 5 >::PartialDistribution;
  using PartialDistributionRange = RandomAccessAnyView< PartialDistribution >;

  // wrap views created by this section
  // none of these are supposed to be created directly by the user
  wrapRandomAccessAnyViewOf< PartialDistribution >(
      module,
      "any_view< PartialDistribution, random_access >" );

  // create the section
  python::class_< Section > section(

    module,
    "Section",
    "MF5 section - energy distributions of secondary particles"
  );

  // wrap components
  wrapOutgoingEnergyDistribution( module );
  wrapTabulatedSpectrum( module );
  wrapDistributionFunction( module );
  wrapParameter( module );
  wrapEffectiveTemperature( module );
  wrapGeneralEvaporationSpectrum( module );
  wrapEvaporationSpectrum( module );
  wrapMaxwellianFissionSpectrum( module );
  wrapWattSpectrum( module );
  wrapMadlandNixSpectrum( module );
  wrapProbability( module );
  wrapPartialDistribution( module );

  // wrap the section
  section
  .def(

    python::init< int, double, double, std::vector< PartialDistribution >&& >(),
    python::arg( "mt" ), python::arg( "zaid" ), python::arg( "awr" ),
    python::arg( "partials" ),
    "Initialise the section\n\n"
    "Arguments:\n"
    "    self        the section\n"
    "    mt          the MT number\n"
    "    zaid        the ZA  identifier\n"
    "    awr         the atomic mass ratio\n"
    "    partials    the partial distributions (at least 1)"
  )
  .def_property_readonly(

    "NK",
    &Section::NK,
    "The number of subsections with partial distributions"
  )
  .def_property_readonly(

    "number_partial_distributions",
    &Section::numberPartialDistributions,
    "The number of subsections with partial distributions"
  )
  .def_property_readonly(

    "partial_distributions",
    [] ( const Section& self ) -> PartialDistributionRange
       { return self.partialDistributions(); },
    "The partial distributions defined in this section"
  );

  // add standard section definitions
  addStandardSectionDefinitions< Section >( section );
}