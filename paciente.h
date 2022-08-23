#ifndef PACIENTE_H
#define PACIENTE_H
#include <string>
namespace std{
    class Paciente{
        public:
        std::string nombre;
        std::string sintomas;
        int edad;
        int gravedad;
        bool higherPriority(Paciente pacienteAComparar);
        std::string toString();
        Paciente(std::string nombre,std::string sintomas,int edad,int gravedad);
        Paciente();
    };
}
#endif
