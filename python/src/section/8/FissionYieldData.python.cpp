// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

// local includes
#include "ENDFtk/section/8/FissionYieldData.hpp"
#include "definitions.hpp"
#include "tools/views/views-python.hpp"

// namespace aliases
namespace python = pybind11;

void wrap_8_FissionYieldData( python::module& module, python::module& viewmodule ) {

  // type aliases
  using Component = njoy::ENDFtk::section::FissionYieldData;

  // wrap views of this component
  // none of these are supposed to be created directly by the user
  wrapRandomAccessAnyViewOf< Component >(
      viewmodule,
      "any_view< FissionYieldData, random_access >" );

  // create the component
  python::class_< Component > component(

    module,
    "FissionYieldData",
    "MF8 component - fission yield data for a specific incident energy (or \n"
    "                energy independent yields)"
  );

  // wrap the component
  component
  .def(

    python::init< std::vector< unsigned int >&&, std::vector< unsigned int >&&,
                  std::vector< std::array< double, 2 > >&&,
                  double, int >(),
    python::arg( "identifiers" ), python::arg( "states" ),
    python::arg( "yields" ), python::arg( "energy" ) = 0.,
    python::arg( "interpolation" ) = 0,
    "Initialise the component\n\n"
    "Arguments:\n"
    "    self            the component\n"
    "    identifiers     the fission product identifiers (ZA identifier)\n"
    "    states          the isomeric state for each fission product\n"
    "    yields          the fission yield values and uncertainties\n"
    "    energy          the incident neutron energy (equal to zero for\n"
    "                    energy independent yields)\n"
    "    interpolation   the interpolation type (equal to zero for\n"
    "                    energy independent yields)"
  )
  .def_property_readonly(

    "LE",
    &Component::LE,
    "Whether or not the fission yield data is energy independent"
  )
  .def_property_readonly(

    "is_energy_independent",
    &Component::isEnergyIndependent,
    "Whether or not the fission yield data is energy independent"
  )
  .def_property_readonly(

    "I",
    &Component::I,
    "The interpolation type (or LE value)"
  )
  .def_property_readonly(

    "interpolation_type",
    &Component::interpolationType,
    "The interpolation type (or LE value)"
  )
  .def_property_readonly(

    "E",
    &Component::E,
    "The incident energy value"
  )
  .def_property_readonly(

    "incident_energy",
    &Component::incidentEnergy,
    "The incident energy value"
  )
  .def_property_readonly(

    "NFP",
    &Component::NFP,
    "The number of fission products"
  )
  .def_property_readonly(

    "number_fission_products",
    &Component::numberFissionProducts,
    "The number of fission products"
  )
  .def_property_readonly(

    "ZAFP",
    [] ( const Component& self ) -> IntRange
       { return self.ZAFP(); },
    "The fission product ZA identifiers"
  )
  .def_property_readonly(

    "fission_product_identifiers",
    [] ( const Component& self ) -> IntRange
       { return self.fissionProductIdentifiers(); },
    "The fission product ZA identifiers"
  )
  .def_property_readonly(

    "FPS",
    [] ( const Component& self ) -> IntRange
       { return self.FPS(); },
    "The fission product isomeric states"
  )
  .def_property_readonly(

    "isomeric_states",
    [] ( const Component& self ) -> IntRange
       { return self.isomericStates(); },
    "The fission product isomeric states"
  )
  .def_property_readonly(

    "Y",
    [] ( const Component& self ) -> DoubleRange2D
       { return self.Y(); },
    "The fission yield values and uncertainties"
  )
  .def_property_readonly(

    "Ypy",
    [](const Component& self ) {

      // Array shape and stride
      std::vector<size_t> shape = { self.NFP(), 2 };
      std::vector<size_t> stride = { 4*sizeof(double),  sizeof(double) };

      // create an array descriptor. If the handle (last parameter) is not void, the data is not copied.
      // python::none() is the most simple type to achive this
      auto array = python::array(
                       shape,
                       stride,
                       self.listPtr() + 2, // drop(2)
                       python::none());

      // make the array read-only. hack from https://github.com/pybind/pybind11/issues/481
      reinterpret_cast<python::detail::PyArray_Proxy*>(array.ptr())->flags &= ~python::detail::npy_api::NPY_ARRAY_WRITEABLE_;

      // Rerutn the array
      return array;

    },
    "The fission yield values and uncertainties as numpy array"
  )
  .def_property_readonly(

    "ZAFPpy",
    [](const Component& self ) {

      // Array shape and stride. The underlying data are  still doubles
      std::vector<size_t> shape = { self.NFP() };
      std::vector<size_t> stride = { 4*sizeof(double) };

      // create an array descriptor. If the handle (last parameter) is not void, the data is not copied.
      // python::none() is the most simple type to achive this
      auto array = python::array(
                       shape,
                       stride,
                       self.listPtr(),
                       python::none());

      // make the array read-only. hack from https://github.com/pybind/pybind11/issues/481
      reinterpret_cast<python::detail::PyArray_Proxy*>(array.ptr())->flags &= ~python::detail::npy_api::NPY_ARRAY_WRITEABLE_;

      // Function to convert array to ont. This will do a copy and reduce performance.
      // Could be a proper function in a real implementation.
      auto toInt = [](const python::array_t<long long>& a) -> python::array_t<long long> { return a; };

      // Return integer array
      return toInt(array);
    },
    "The fission product ZA identifiers as numpy array"
  )
  .def_property_readonly(

    "fission_yields",
    [] ( const Component& self ) -> DoubleRange2D
       { return self.fissionYields(); },
    "The fission yield values and uncertainties"
  );

  // add standard component definitions
  addStandardComponentDefinitions< Component >( component );
}
