#include "solver.hpp"

namespace delfina{

Solver::Solver(
    std::function<float(float, float)> derivative, 
    ParameterPack pack
    ): m_derivative{derivative}, m_parameters{pack}{
  m_dependent.reserve(MaxX()/StepSize());
  m_independent.reserve(MaxX()/StepSize());
  m_dependent.push_back(InitialY());
}

Solver::~Solver(){

}

void Solver::WriteTo(std::ostream& ost){
  for(std::size_t i = 0; i < m_dependent.size(); i++){
    ost << "x \t y\n";
    ost << m_independent[i] << "\t" << m_dependent[i] << '\n';
  }
}

}
