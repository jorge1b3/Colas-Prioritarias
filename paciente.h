#ifndef PACIENTE_H
#define PACIENTE_H
#include <string>
namespace cola{
    class Paciente{
        public:
        std::string nombre;
        std::string sintomas;
        int edad;
        int gravedad;
        [[nodiscard]] bool higherPriority(const Paciente& pacienteAComparar) const;
        [[nodiscard]] std::string toString() const;
        Paciente();
    };
}
#endif
