#include "paciente.h"
#include <string>

using std::Paciente;

bool Paciente::higherPriority(Paciente p){
    if(p.gravedad < this->gravedad) return false;
    if(p.edad<=12 && this->edad>12) return false;
    if(p.edad>=65 && this->edad<65) return false;
    return true;
}

std::string Paciente::toString(){
    std::string paciente{};
    paciente += to_string(gravedad) + '\t';
    paciente += to_string(edad) + '\t';
    paciente += nombre + "\t\t";
    paciente += sintomas + '\n';
    return paciente;
}

Paciente::Paciente(std::string n,std::string s,int e, int g)
    :nombre{n},sintomas{s},edad{e},gravedad{g}{}

Paciente::Paciente()
    :nombre{},sintomas{},edad{},gravedad{}{}
