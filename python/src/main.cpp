#include "pybind11/pybind11.h"

#include "xtensor/xmath.hpp"
#include "xtensor/xarray.hpp"

#define FORCE_IMPORT_ARRAY
#include "xtensor-python/pyarray.hpp"
#include "xtensor-python/pyvectorize.hpp"

#include <iostream>
#include <numeric>
#include <string>
#include <sstream>


// our headers
#include "colpp/colpp.hpp"
#include "colpp/colpp_config.hpp"

namespace py = pybind11;



namespace col {


    // implementation in def_myclass.cpp
    void def_class(py::module & m);

    // implementation in def_myclass.cpp
    void def_build_config(py::module & m);

    // implementation in def.cpp
    void def_build_config(py::module & m);

}


// Python Module and Docstrings
PYBIND11_MODULE(_colpy , module)
{
    xt::import_numpy();

    module.doc() = R"pbdoc(
        _colpy  python bindings

        .. currentmodule:: _colpy 

        .. autosummary::
           :toctree: _generate

           BuildConfiguration
           MyClass
    )pbdoc";

    col::def_build_config(module);
    col::def_class(module);

    // make version string
    std::stringstream ss;
    ss<<COLPP_VERSION_MAJOR<<"."
      <<COLPP_VERSION_MINOR<<"."
      <<COLPP_VERSION_PATCH;
    module.attr("__version__") = ss.str().c_str();
}