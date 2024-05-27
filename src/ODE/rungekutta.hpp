#ifndef RK_HPP
#define RK_HPP

#include <iostream>
#include <vector>
#include <cstdint>
#include <fstream>
#include <filesystem>
#include <functional>
#include <exception>
#include "solver.hpp"
#include "utilities.hpp"

namespace delfina{

  class RuneKutta: public Solver{
    public:
    RuneKutta(std::function<float(float, float)> derivative,
        ParameterPack pack): Solver(derivative, pack){}
    ~RuneKutta(){}
    virtual void Solve() override;
    virtual void Step() override {}
    virtual float Derivative(float x, float y){ return Solver::Derivative(x, y); }
  };

  class RuneKuttaExecutor{
    // this class encapsulates an execution of a complete solve of RuneKutta

  };
}

#endif
