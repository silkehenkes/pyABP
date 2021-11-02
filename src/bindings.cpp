
#include <pybind11/pybind11.h>

#include "System.h"


namespace py = pybind11;
using namespace pybind11::literals;


PYBIND11_MODULE(pyABP, m) {
	// documentation (it does not work without having something more than the class here, WTF)
	m.doc() = "Tutorial template code for molecular dynamics using C++ and pybind";
	
	py::class_<System>(m, "System")
		.def(py::init<>())
		.def(py::init<py::dict &>())
		.def("step", &System::step)
		.def("output", &System::output);
		
}


