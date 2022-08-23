#ifndef COLA_H
#define COLA_H
#include "nodo.h"
namespace std{
    using std::Nodo;
    class Cola{
    private:
        Nodo* head;
        Nodo* tail;
    public:
        void enqueue(Paciente paciente);
        Paciente dequeue();
        std::string toString();
        Cola();
        ~Cola();
    };
}
#endif
