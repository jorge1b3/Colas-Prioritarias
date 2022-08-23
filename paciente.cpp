#include "paciente.h"
#include <string>

using std::Paciente;

bool Paciente::mostPriority(Paciente p){
    if(p.gravedad < this->gravedad) return true;
    if(p.edad<=12 && this->edad>12) return true;
    if(p.edad>=65 && this->edad<65) return true;
    return false;
}

std::string Paciente::toString(){
    std::string paciente{};
    paciente += to_string(gravedad) + '\t';
    paciente += to_string(edad) + '\t';
    paciente += nombre + '\t';
    paciente += sintomas + '\n';
    return paciente;
}

Paciente::Paciente(std::string n,std::string s,int e, int g)
    :nombre{n},sintomas{s},edad{e},gravedad{g}{}

Paciente::Paciente()
    :nombre{},sintomas{},edad{},gravedad{}{}
