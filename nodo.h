#ifndef NODO_H
#define NODO_H
#include "paciente.h"
namespace std{
using std::Paciente;
    struct Nodo{
        Paciente paciente;
        Nodo* back;
        Nodo(Paciente p, Nodo* b):paciente{p},back{b}{}
    };
}
#endif
