#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdint>

namespace delfina{

  struct iterator{
    iterator(float begin_x, std::size_t begin_i): x{begin_x}, i{begin_i}{}
    float x;
    std::size_t i;
  };

  struct ParameterPack{
    double stepsize;
    double initialIndependent;
    double initialDependent;
    double maxIndependent;
    double maxDependent;
  };

}

#endif
