#include <pybind11/pybind11.h>
#include "my_lib.h"
#include <pybind11/numpy.h>

namespace py = pybind11;
void read_data_wrap(py::array_t<uint16_t> array){
    read_data((uint16_t*)array.data(0), array.size());
}



PYBIND11_MODULE(my_lib_module, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------
        .. currentmodule:: my_lib_module
        .. autosummary::
           :toctree: _generate
           add
           subtract
    )pbdoc";

    m.def("add", &add, R"pbdoc(
        Add two numbers
        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers
        Some other explanation about the subtract function.
    )pbdoc");

    m.def("read_data", &read_data_wrap , "pbdoc()");

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}