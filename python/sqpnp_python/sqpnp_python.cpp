//
// Created by jnshi on 3/10/23.
//

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/eigen.h>

#include <sqpnp/types.h>
#include <sqpnp/sqpnp.h>

namespace py = pybind11;

PYBIND11_MODULE(sqpnp_python, m) {

  py::class_<sqpnp::SQPSolution>(m, "SQPSolution")
      .def_readwrite("r", &sqpnp::SQPSolution::r)
      .def_readwrite("r_hat", &sqpnp::SQPSolution::r_hat)
      .def_readwrite("t", &sqpnp::SQPSolution::t)
      .def_readwrite("num_iterations", &sqpnp::SQPSolution::num_iterations)
      .def_readwrite("sq_error", &sqpnp::SQPSolution::num_iterations);

}
