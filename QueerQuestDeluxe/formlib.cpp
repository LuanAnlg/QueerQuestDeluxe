#include "formlib.h"
#include <random>

namespace formlib {

    int getAleatorio(int min, int max) {
        System::Random Aleatorio;
        return Aleatorio.Next(min, (max + 1));
    }

    int getCelda() {
        return 64;
    }

    // Colores Blanco y Negro
    System::Drawing::Color Negro() {
        return System::Drawing::Color::FromArgb(255, 0, 0, 0);
    }
    System::Drawing::Color Blanco() {
        return System::Drawing::Color::FromArgb(255, 255, 255, 255);
    }

    // Colores de la Paleta LGBT
    System::Drawing::Color Rojo() {
        return System::Drawing::Color::FromArgb(255, 250, 0, 24);
    }
    System::Drawing::Color Naranja() {
        return System::Drawing::Color::FromArgb(255, 250, 165, 44);
    }
    System::Drawing::Color Amarillo() {
        return System::Drawing::Color::FromArgb(255, 255, 255, 65);
    }
    System::Drawing::Color Verde() {
        return System::Drawing::Color::FromArgb(255, 0, 128, 24);
    }
    System::Drawing::Color Azul() {
        return System::Drawing::Color::FromArgb(255, 0, 0, 249);
    }
    System::Drawing::Color Violeta() {
        return System::Drawing::Color::FromArgb(255, 134, 0, 125);
    }

    // Colores de la Paleta PICO-8
    System::Drawing::Color P8Negro() {
        return System::Drawing::Color::FromArgb(255, 0, 0, 0);
    }
    System::Drawing::Color P8AzulOscuro() {
        return System::Drawing::Color::FromArgb(255, 29, 43, 83);
    }
    System::Drawing::Color P8MoradoOscuro() {
        return System::Drawing::Color::FromArgb(255, 126, 37, 83);
    }
    System::Drawing::Color P8VerdeOscuro() {
        return System::Drawing::Color::FromArgb(255, 0, 135, 81);
    }
    System::Drawing::Color P8Marron() {
        return System::Drawing::Color::FromArgb(255, 171, 82, 54);
    }
    System::Drawing::Color P8GrisOscuro() {
        return System::Drawing::Color::FromArgb(255, 95, 87, 79);
    }
    System::Drawing::Color P8GrisClaro() {
        return System::Drawing::Color::FromArgb(255, 194, 195, 199);
    }
    System::Drawing::Color P8Blanco() {
        return System::Drawing::Color::FromArgb(255, 255, 241, 232);
    }
    System::Drawing::Color P8Rojo() {
        return System::Drawing::Color::FromArgb(255, 255, 0, 77);
    }
    System::Drawing::Color P8Naranja() {
        return System::Drawing::Color::FromArgb(255, 255, 163, 0);
    }
    System::Drawing::Color P8Amarillo() {
        return System::Drawing::Color::FromArgb(255, 255, 236, 39);
    }
    System::Drawing::Color P8Verde() {
        return System::Drawing::Color::FromArgb(255, 0, 228, 54);
    }
    System::Drawing::Color P8Azul() {
        return System::Drawing::Color::FromArgb(255, 41, 173, 255);
    }
    System::Drawing::Color P8Lavanda() {
        return System::Drawing::Color::FromArgb(255, 131, 118, 156);
    }
    System::Drawing::Color P8Rosa() {
        return System::Drawing::Color::FromArgb(255, 255, 119, 168);
    }
    System::Drawing::Color P8DuraznoClaro() {
        return System::Drawing::Color::FromArgb(255, 255, 204, 170);
    }
}
