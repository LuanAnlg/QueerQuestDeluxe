#pragma once

#include "Personaje.h"

// La clase Enemigo hereda de la clase Personaje
class Enemigo : public Personaje {

private:
    formlib::Tipos tipo;  // Tipo del enemigo

public:
    // Constructor de la clase Enemigo
    // Inicializa un objeto Enemigo con una posición y una hoja de sprites
    Enemigo(formlib::Vec2 posicion, System::Drawing::Bitmap^ hojaSprites)
        : Personaje(posicion, hojaSprites, { 4, 5 }, { 0, 0 }, { 2, static_cast<float>(formlib::getAleatorio(1, 3)) }, 2, 10) {

        // Establece el tipo del enemigo basado en el fotograma actual y conviértelo a Tipos
        tipo = static_cast<formlib::Tipos>(fotogramaActual.y);
    }

    // Destructor de la clase Enemigo
    ~Enemigo() = default;

    // Getter para obtener el tipo del enemigo
    formlib::Tipos getTipo() const {
        return tipo;
    }
};