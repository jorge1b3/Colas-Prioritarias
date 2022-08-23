#include "cola.h"
#include "paciente.h"
#include <iostream>

std::Paciente ingresarPaciente(){
    using std::Paciente;
    Paciente p{};
    std::cout<<"El nombre del paciente: ";
    std::cin>>p.nombre;
    std::cout<<"Ingrese los síntomas del paciente: ";
    std::cin>>p.sintomas;
    std::cout<<"Ingrese la edad del paciente: ";
    std::cin>>p.edad;
    std::cout<<"Ingrese la gravedad del paciente, en una escala del 1 al 5: ";
    std::cin>>p.gravedad;
    return p;
}

int main(){
    using std::Cola;
    bool salir {false};
    Cola cola{};
    while(!salir){
        std::cout<<"Ingrese que desea hacer:\n"
            <<"1) Ingresar paciente.\n" 
            <<"2) Pasar paciente.\n"
            <<"3) Mostrar cola\n"
            <<"4) Salir \n"
            <<"Seleccione: ";
        int option{};
        std::cin>>option;
        switch (option) {
            case 1:{
                       cola.enqueue(ingresarPaciente());
                       break;
                   }
            case 2:{
                       std::cout<<cola.dequeue().toString();
                       break;
                   }
            case 3:{
                       std::cout<<cola.toString();
                       break;
                   }
            case 4:{
                       std::cout<<"Hasta Luego"<<std::endl;
                       salir = true;
                       break;
                   }
            default:{
                        std::cout<<"Opción no válida";
                        break;
                    }
        }
    }
    return 0;
}
