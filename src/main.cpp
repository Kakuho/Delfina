#include "ODE/rungekutta.hpp"

// y = x^2 
// dy/dx = 2x
double derivative(double x, double y){
  // calculates the derivative f(x,y) given input x, y
  return y - (x*x) +1;
};

void TryAbstractions(){
  delfina::ParameterPack settings{
    .stepsize = 0.5,
    .initialIndependent = 0, 
    .initialDependent = 0.5,
    .maxIndependent = 2
  };
  delfina::RuneKutta rk{derivative,
    settings
  };
  std::cout << rk.Derivative(0, 0.5) << '\n';
  rk.Solve();
}

int main(){
  TryAbstractions();
}
