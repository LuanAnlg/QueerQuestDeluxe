#pragma once

#include "Personaje.h"

// La clase Robot hereda de la clase Personaje
class Robot : public Personaje {
public:
    // Constructor de la clase Robot
    // Inicializa un objeto Robot con una posición y una hoja de sprites
    Robot(formlib::Vec2 posicion, System::Drawing::Bitmap^ hojaSprites)
        : Personaje(posicion, hojaSprites, { 4, 5 }, { static_cast<float>(formlib::getCelda()), static_cast<float>(formlib::getCelda()) }, {2, 0}, 2, 10) {}

    // Destructor de la clase Robot
    ~Robot() = default;

    // Método para actualizar la posición del robot
    void actualizar(System::Drawing::Graphics^ graphics, formlib::Direcciones direccion) {
        // Movimiento del robot según la dirección especificada
        switch (direccion) {
        case formlib::Direcciones::Izquierda:
            rectanguloColision.X -= static_cast<int>(velocidad.x);
            // Si el robot sale del borde izquierdo, teletransportarlo al lado derecho
            if (rectanguloColision.X < 0) {
                rectanguloColision.X = static_cast<int>(graphics->VisibleClipBounds.Width - formlib::getCelda());
            }
            break;

        case formlib::Direcciones::Derecha:
            rectanguloColision.X += static_cast<int>(velocidad.x);
            // Si el robot sale del borde derecho, teletransportarlo al lado izquierdo
            if (rectanguloColision.Right > graphics->VisibleClipBounds.Width) {
                rectanguloColision.X = 0;
            }
            break;

        case formlib::Direcciones::Arriba:
            rectanguloColision.Y -= static_cast<int>(velocidad.y);
            // Si el robot sale del borde superior, teletransportarlo al borde inferior
            if (rectanguloColision.Y < 0) {
                rectanguloColision.Y = static_cast<int>(graphics->VisibleClipBounds.Height - formlib::getCelda());
            }
            break;

        case formlib::Direcciones::Abajo:
            rectanguloColision.Y += static_cast<int>(velocidad.y);
            // Si el robot sale del borde inferior, teletransportarlo al borde superior
            if (rectanguloColision.Bottom > graphics->VisibleClipBounds.Height) {
                rectanguloColision.Y = 0;
            }
            break;

        default:
            break; // No hacer nada si la dirección es Ninguno
        }
    }
};