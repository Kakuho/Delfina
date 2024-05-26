#include <iostream>
#include <vector>
#include <cstdint>
#include <fstream>
#include <filesystem>
#include <functional>

namespace delfina{

  struct iterator{
    iterator(float begin_t, std::size_t begin_i): t{begin_t}, i{begin_i}{}
    double t;
    std::size_t i;
  };

  struct ParameterPack{
    double stepsize;
    double initialIndependent;
    double initialDependent;
    double maxIndependent;
    double maxDependent;
  };

  class Solver{
    public:
      Solver(std::function<float(float, float)> derivative, ParameterPack& pack);
      Solver& operator=(const Solver&) = delete;
      virtual ~Solver() = 0;
      virtual void Solve() = 0;
      virtual void Step() = 0;
      void WriteTo(std::ostream& ost);
    private:
      std::vector<double> m_dependent;
      std::vector<double> m_independent;
      ParameterPack m_parameters;
  };

  class RuneKutta: public Solver{
    RuneKutta(std::function<float(float,float)> derivative);
    virtual void Solve() override;
    virtual void Step() override;
  };
}

/*
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
*/
