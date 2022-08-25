#include "paciente.h"

using cola::Paciente;

bool Paciente::higherPriority(const Paciente& p) const{
    if(p.gravedad < this->gravedad) return false;
    if(p.edad<=12 && this->edad>12) return false;
    if(p.edad>=65 && this->edad<65) return false;
    return true;
}

std::string Paciente::toString() const{
    std::string paciente{};
    paciente += std::to_string(gravedad) + '\t';
    paciente += std::to_string(edad) + '\t';
    paciente += nombre + "\t\t";
    paciente += sintomas + '\n';
    return paciente;
}

Paciente::Paciente()
    :nombre{},sintomas{},edad{},gravedad{}{}
