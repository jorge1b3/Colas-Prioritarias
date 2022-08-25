#include "cola.h"
#include "nodo.h"
#include <stdexcept>
using cola::Cola;
using cola::Paciente;

void Cola::enqueue(const Paciente& paciente){
    if(!head){
        tail = new Nodo(paciente,nullptr);
        head = tail;
        return;
    }
    Nodo* nodo {nullptr};
    Nodo* back {head};
    while(back){
        if(paciente.higherPriority(back->paciente)) break;
        nodo = back;
        back = back->back;
    }
    if(!nodo){
        head = new Nodo(paciente,head);
        return;
    }
    nodo->back = new Nodo(paciente,back);
    if(!back){
        tail = nodo->back;
    }
}

Paciente Cola::dequeue(){
    if(!tail) throw std::out_of_range("La cola esta vacia\n");
    Nodo* next {head};
    head = head->back;
    if(!head) tail = nullptr;
    Paciente valReturn = next->paciente;
    delete next;
    return valReturn;
}

std::string Cola::toString(){
    if(!head) throw std::out_of_range("La cola esta vacia\n");
    Nodo* nodo = head;
    std::string lista{"Gravedad\tEdad\tNombre\t\tSintoma\n"};
    while(nodo){
        lista+= nodo->paciente.toString();
        nodo = nodo->back;
    }
    return lista;
}

Cola::Cola():
    head{nullptr},tail{}{}

Cola::~Cola(){
    Nodo* next {head};
    while(head){
        head = head->back;
        delete next;
        next = head;
    }
}
