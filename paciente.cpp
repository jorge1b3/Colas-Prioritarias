#include "paciente.h"

using cola::Paciente;

bool Paciente::higherPriority(const Paciente& p) const{
    if(this->gravedad<p.gravedad) return true;
    if(p.edad>12 && this->edad<=12) return  true;
    if(this->edad>=65 && p.edad<65) return true;
    return false;
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
