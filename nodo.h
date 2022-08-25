#ifndef NODO_H
#define NODO_H
#include <utility>

#include "paciente.h"
namespace cola{
using cola::Paciente;
    struct Nodo{
        Paciente paciente;
        Nodo* back;
        Nodo(Paciente p, Nodo* b):paciente{std::move(p)},back{b}{}
    };
}
#endif
