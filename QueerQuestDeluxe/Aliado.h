#pragma once

#include "Personaje.h"

// La clase Aliado hereda de la clase Personaje
class Aliado : public Personaje {
public:
    // Constructor de la clase Aliado
    // Inicializa un objeto Aliado con una posición, una hoja de sprites y un tipo de personaje
    Aliado(formlib::Vec2 posicion, System::Drawing::Bitmap^ hojaSprites, formlib::Tipos tipo)
        : Personaje(posicion, hojaSprites, { 4, 5 }, { 0,0 }, { 0, static_cast<float>(tipo) }, 2, 10) {}

    // Destructor de la clase Aliado
    ~Aliado() = default;

    // Setter para actualizar la posición del Aliado
    void setPosicion(formlib::Vec2 posicion) {
        rectanguloColision.X = static_cast<int>(posicion.x);
        rectanguloColision.Y = static_cast<int>(posicion.y);
    }
};