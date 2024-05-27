#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <iostream>
#include <vector>
#include <cstdint>
#include <fstream>
#include <filesystem>
#include <functional>
#include <exception>
#include "utilities.hpp"

namespace delfina{

  class Solver{
    public:

      explicit Solver(std::function<float(float, float)> derivative, 
          ParameterPack pack);
      Solver& operator=(const Solver&) = delete;
      virtual ~Solver();
      virtual void Solve() = 0;
      virtual void Step() = 0;
      void WriteTo(std::ostream& ost);

    protected:

      float Derivative(float x, float y){ return m_derivative(x, y); }
      float StepSize()  const { return m_parameters.stepsize; }
      float MaxX()      const { return m_parameters.maxIndependent; }
      float InitialX()  const { return m_parameters.initialIndependent; }
      float InitialY()  const { return m_parameters.initialDependent; }
      std::vector<float> m_dependent;
      std::vector<float> m_independent;

    private:

      std::function<float(float, float)> m_derivative;
      ParameterPack m_parameters;
  };

}

#endif
