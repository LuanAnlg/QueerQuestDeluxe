#pragma once

#include "formlib.h"

class Personaje {
protected:
    System::Drawing::Rectangle rectanguloColision; // Rect�ngulo de colisi�n: posici�n (x, y) y tama�o (largo, ancho)
    formlib::Vec2 velocidad;                       // Velocidad en x y en y
    formlib::Vec2 fotogramaActual;                 // Fotograma actual en la coordenada (x, y)
    int fotogramaInicial;                          // Fotograma inicial de la animaci�n
    int cantidadFotogramas;                        // N�mero total de fotogramas en la animaci�n
    int duracionAnimacion;                         // Duraci�n total de la animaci�n en frames
    int tiempoAnimacion;                           // Tiempo transcurrido desde el �ltimo cambio de fotograma
    formlib::Direcciones direccion;                // Direcci�n actual del movimiento del objeto en el espacio (arriba, abajo, izquierda, derecha, o ninguna).

public:
    // Constructor de Personaje
    Personaje(formlib::Vec2 posicion, System::Drawing::Bitmap^ hojaSprites, formlib::Vec2 tamanoCorte,
        formlib::Vec2 velocidad, formlib::Vec2 fotograma, int cantidadFotogramas, int duracionAnimacion) :
        velocidad(velocidad),
        fotogramaActual(fotograma),
        cantidadFotogramas(cantidadFotogramas),
        duracionAnimacion(duracionAnimacion),
        tiempoAnimacion(0),
        direccion(formlib::Direcciones::Ninguno)
        {

        int anchoColision = hojaSprites->Width / static_cast<int>(tamanoCorte.x);
        int altoColision = hojaSprites->Height / static_cast<int>(tamanoCorte.y);
        rectanguloColision = System::Drawing::Rectangle(static_cast<int>(posicion.x), static_cast<int>(posicion.y), anchoColision, altoColision);

        fotogramaInicial = static_cast<int>(fotograma.x);
    }

    // Destructor de Personaje
    ~Personaje() = default;

    // Getter para el rect�ngulo de colisi�n
    System::Drawing::Rectangle getRectanguloColision() const {
        return rectanguloColision;
    }

    // Establece la direcci�n del personaje.
    void setDireccion(formlib::Direcciones nuevaDireccion) {
        direccion = nuevaDireccion;
    }

    // Devuelve la direcci�n actual del personaje.
    formlib::Direcciones getDireccion() const {
        return direccion;
    }

    // Dibuja el personaje en el contexto gr�fico proporcionado
    void dibujar(System::Drawing::Graphics^ graphics, System::Drawing::Bitmap^ hojaSprites) {

        // Actualiza la animaci�n del personaje
        tiempoAnimacion++;

        // Calcula cu�ndo cambiar de fotograma
        if (tiempoAnimacion >= duracionAnimacion / cantidadFotogramas) {
            fotogramaActual.x++;
            tiempoAnimacion = 0; // Reinicia el contador de tiempo
        }

        // Reinicia la animaci�n si llega al final
        if (fotogramaActual.x >= cantidadFotogramas + fotogramaInicial) {
            fotogramaActual.x = fotogramaInicial;
        }

        System::Drawing::Rectangle fotogramaVisible =
            System::Drawing::Rectangle(
                static_cast<int>(fotogramaActual.x * rectanguloColision.Width),
                static_cast<int>(fotogramaActual.y * rectanguloColision.Height),
                rectanguloColision.Width, rectanguloColision.Height
            );

        graphics->DrawImage(hojaSprites, rectanguloColision, fotogramaVisible, System::Drawing::GraphicsUnit::Pixel);
    }
};