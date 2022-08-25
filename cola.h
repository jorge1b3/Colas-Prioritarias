#ifndef COLA_H
#define COLA_H
#include "nodo.h"
namespace cola{
    using cola::Nodo;
    class Cola{
    private:
        Nodo* head;
        Nodo* tail;
    public:
        void enqueue(const Paciente& paciente);
        Paciente dequeue();
        std::string toString();
        Cola();
        ~Cola();
    };
}
#endif
