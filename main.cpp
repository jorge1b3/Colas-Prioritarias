#include "cola.h"
#include "paciente.h"
#include <iostream>
#include <limits>
#include <cstdlib>

void clear_screen();

void pause();

cola::Paciente ingresarPaciente();

int main(){
    using cola::Cola;
    bool salir {false};
    Cola cola{};
    while(!salir){
        clear_screen();
        std::cout
            <<"Ingrese que desea hacer:\n"
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
                    std::cout<<"\nPaciente ingresado correctamente\n";
                    pause();
                    break;
                   }
            case 2:{
                    try{
                        std::cout<<cola.dequeue().toString();
                    }
                    catch(std::out_of_range& e)
                    {
                        std::cout<<e.what();
                    }
                    pause();
                    break;
                   }
            case 3:{
                    try{
                        std::cout<<cola.toString();
                    }
                    catch(std::out_of_range& e)
                    {
                        std::cout<<e.what();
                    }
                    pause();
                    break;
                   }
            case 4:{
                    std::cout<<"Hasta Luego"<<std::endl;
                    salir = true;
                    pause();
                    break;
                   }
            default:{
                    std::cout<<std::flush;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout<<"Opción no válida\n";
                    pause();
                    break;
                    }
        }
    }
    return 0;
}

void pause(){
    std::cout<<"\nIngrese cualquier tecla para continuar...";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
cola::Paciente ingresarPaciente(){
    using cola::Paciente;
    Paciente p{};
    std::cout<<"El nombre del paciente: ";
    std::getline(std::cin>>std::ws,p.nombre);
    std::cout<<"Ingrese los síntomas del paciente: ";
    std::getline(std::cin>>std::ws,p.sintomas);
    std::cout<<"Ingrese la edad del paciente: ";
    std::cin>>p.edad;
    std::cout<<"Ingrese la gravedad del paciente, en una escala del 1 al 5: ";
    std::cin.clear();
    std::cin>>p.gravedad;
    return p;
}

void clear_screen(){
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}
