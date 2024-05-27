#include "rungekutta.hpp"
#include <ostream>
#include <stdexcept>

namespace delfina{

void RuneKutta::Solve(){
  std::cout << "initial stepsize, X, Y = " << StepSize() 
            << ", " << InitialX() << ", " << InitialY() << '\n';
  for(delfina::iterator iter{InitialX(), 0}; 
      iter.x < MaxX(); iter.x += StepSize(), iter.i++){
    double currentY = m_dependent[iter.i];
    double currentX = iter.x;
    double k1 = StepSize() * Derivative(currentX, currentY);
    double k2 = StepSize() * Derivative(currentX + StepSize()/2, currentY + k1/2);
    double k3 = StepSize() * Derivative(currentX + StepSize()/2, currentY + k2/2);
    double k4 = StepSize() * Derivative(currentX + StepSize(), currentY + k3);
    double nextY = currentY + (k1 + 2*k2 + 2*k3 + k4)/6.0;
    // logging
    std::cout << "------" << '\n' 
              << "x_i: " << currentX << '\n'
              << "k1: " << k1 << '\n'
              << "k2: " << k2 << '\n'
              << "k3: " << k3 << '\n'
              << "k4: " << k4 << '\n'
              << "y+i: " << nextY << '\n';
    m_dependent.push_back(nextY);
    m_independent.push_back(currentX);
  }
}

}
