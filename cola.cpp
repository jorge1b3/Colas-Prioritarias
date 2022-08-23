#include "cola.h"
#include "nodo.h"
#include <string>
#include <stdexcept>
using std::Cola;
using std::Paciente;
Paciente& Cola::get(int position){
    return head->paciente;
}

void Cola::enqueue(Paciente paciente){
    if(!head){
        tail = new Nodo(paciente,nullptr);
        head = tail;
        return;
    }
    Nodo* nodo {nullptr};
    Nodo* back {head};
    while(back){
        if(paciente.mostPriority(back->paciente)) break;
        nodo = back;
        back = back->back;  
    }
    nodo->back = new Nodo(paciente,back);
}

Paciente Cola::dequeue(){
    if(!head) throw std::out_of_range("No hay personas en la cola\n");
    Nodo* next {head};
    head = head->back;
   Paciente valReturn = next->paciente;
    delete next;
    return valReturn;
}

std::string Cola::toString(){
    if(!head) throw std::out_of_range("No hay personas en la cola\n");
    Nodo* nodo = head;
    std::string lista{"Gravedad\tEdad\tNombre\t\tSintoma\n"};
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
