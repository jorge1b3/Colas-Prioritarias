#include "cola.h"
#include "nodo.h"
#include <string>
using std::Cola;
using std::Paciente;
Paciente& Cola::get(int position){
    return head->paciente;
}

void Cola::enqueue(Paciente paciente){
    if(!head){
        tail = new Nodo(paciente,nullptr);
        head = tail;
    }
    Nodo* nodo {head};
    Nodo* next {nullptr};
    while(!paciente.mostPriority(nodo->paciente)){
        next = nodo;
        nodo = nodo->back;
    }
    nodo = new Nodo(paciente,nodo->back);
    if(!next) return;
    next->back = nodo;
}

Paciente Cola::dequeue(){
    //if(!head) return null;
    Nodo* next {head};
    head = head->back;
   Paciente valReturn = next->paciente;
    delete next;
    return valReturn;
}

std::string Cola::toString(){
    Nodo* nodo = head;
    std::string lista{};
    while(nodo){
        lista+= nodo->paciente.toString();
        nodo = nodo->back;
    }
    return lista;
}

Cola::Cola():
    head(nullptr),tail(nullptr){}

Cola::~Cola(){
    Nodo* next {head};
    while(head){
        head = head->back;
        delete next;
        next = head;
    }
}
