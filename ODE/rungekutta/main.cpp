#include <iostream>
#include <vector>
#include <cstdint>
#include <fstream>
#include <filesystem>
#include <functional>

// y = x^2 
// dy/dx = 2x
double derivative(double x, double y){
  // calculates the derivative f(x,y) given input x, y
  return 2*x;
};

namespace delfina{
  struct iterator{
    iterator(double begin_t, std::size_t begin_i): t{begin_t}, i{begin_i}{}
    double t;
    std::size_t i;
  };

  template<typename T>
  class RuneKutta{
    RuneKutta(std::function<T(T,T)> derivative);
    void Solve() const;
    void Step() const;
  };
}

void SaveToFile(const std::vector<double>& domain, const std::vector<double>& range){
  if(std::remove("./output.csv")){
    std::cout << "removed dirty file" << '\n';
  }
  else{
    std::cout << "no outputfile, creaing file now" << '\n';
  }
  std::ofstream out{"./output.csv"};
  out << "x, y\n";
  for(std::size_t i = 0; i < domain.size(); i++){
    out << domain[i] << ", " << range[i] << '\n';
  }
}

int main(){
  double stepsizeH = 0.5;
  double maxT = 100;
  double initialT = 0;
  double initialW = 0.5;
  // initialise the histories
  std::vector<double> Wvalues;
  std::vector<double> Tvalues;
  Wvalues.reserve(maxT/stepsizeH);
  Tvalues.reserve(maxT/stepsizeH);
  Wvalues.push_back(initialW);
  // calculate for a single step:
  for(delfina::iterator iter{initialT, 0}; iter.t < maxT; iter.t += stepsizeH, iter.i++){
    double currentW = Wvalues[iter.i];
    double currentT = iter.t;
    double k1 = stepsizeH * derivative(currentT, currentW);
    double k2 = stepsizeH * derivative(currentT + stepsizeH/2, currentW + k1/2);
    double k3 = stepsizeH * derivative(currentT + stepsizeH/2, currentW + k2/2);
    double k4 = stepsizeH * derivative(currentT + stepsizeH, currentW + k3);
    double nextW = currentW + (k1 + 2*k2 + 2*k3 + k4)/6.0;
    // logging
    std::cout << "------" << '\n' 
              << "t_i: " << currentT << '\n'
              << "k1: " << k1 << '\n'
              << "k2: " << k2 << '\n'
              << "k3: " << k3 << '\n'
              << "k4: " << k4 << '\n'
              << "y+i: " << nextW << '\n';

    Wvalues.push_back(nextW);
    Tvalues.push_back(currentT);
  }
  SaveToFile(Tvalues, Wvalues);
}
