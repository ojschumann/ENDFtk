// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "ENDFtk/file/4.hpp"
#include "definitions.hpp"
#include "views.hpp"

// namespace aliases
namespace python = pybind11;

// declarations - sections
void wrapSection_4( python::module& );

void wrapFile_4( python::module& module ) {

  // type aliases
  using Section = njoy::ENDFtk::section::Type< 4 >;
  using File = njoy::ENDFtk::file::Type< 4 >;
  using SectionRange = BidirectionalAnyView< Section >;

  // wrap views created by this file
  // none of these are supposed to be created directly by the user
  wrapBidirectionalAnyViewOf< Section >(
      module,
      "any_view< section::Type< 4 >, bidirectional >" );

  // create the submodule
  python::module submodule = module.def_submodule(

    "MF4",
    "MF4 - angular distributions of secondary particles"
  );

  // wrap sections
  wrapSection_4( submodule );

  // create the file
  python::class_< File > file(

    submodule,
    "File",
    "MF4 file - angular distributions of secondary particles"
  );

  // wrap the file
  addStandardUnenumeratedFileDefinitions< File, Section, SectionRange >( file );

  // add standard file definitions
  addStandardFileDefinitions< File >( file );
}