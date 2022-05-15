#include <pybind11/pybind11.h>

class animal {
  public:
    animal(const std::string &name) : name(name) { }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }
    std::string name;
};

namespace py = pybind11;


PYBIND11_MODULE(animal,m)
{ 
  py::class_<animal>(m,"animal")
    .def(py::init<const std::string &>())
    .def("setName", &animal::setName)
    .def("getName", &animal::getName);
}
