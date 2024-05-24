#include <iostream>
#include <vector>

// example ode: dydx = x^2, y(0) = 10

double derivative(double x, double y){
  // calculates the derivative f(x,y) = x^2 at x = input
  // this is going to be parameterised
  return x*x;
};

int main(){
  double stepsizeH = 0.05;
  // calculate for a single step:
  double currentW = 10;
  double currentT = stepsizeH;
  double k1 = stepsizeH * derivative(currentT, currentW);
  double k2 = stepsizeH * derivative(currentT + stepsizeH/2, currentW + k1/2);
  double k3 = stepsizeH * derivative(currentT + stepsizeH/2, currentW + k2/2);
  double k4 = stepsizeH * derivative(currentT + stepsizeH, currentW + k3);
  double nextW = currentW + (k1 + 2*k2 + 2*k3 + k4)/6.0;
  // 
  std::cout << "h: " << stepsizeH << '\n'
            << "y0: " << currentW << '\n'
            << "------" << '\n'
            << "t1: " << currentT << '\n'
            << "k1: " << k1 << '\n'
            << "k2: " << k2 << '\n'
            << "k3: " << k3 << '\n'
            << "k4: " << k4 << '\n'
            << "y1: " << nextW << '\n';
}
