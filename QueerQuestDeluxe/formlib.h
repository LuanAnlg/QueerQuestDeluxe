
//   __                     _ _ _
//  / _|                   | (_) |
// | |_ ___  _ __ _ __ ___ | |_| |__
// |  _/ _ \| '__| '_ ` _ \| | | '_ \
// | || (_) | |  | | | | | | | | |_) |
// |_| \___/|_|  |_| |_| |_|_|_|_.__/

#pragma once

#include <string>

namespace formlib {

    // Estructura para representar un vector 2D
    struct Vec2 {                                          
        float x;  // Posición en el eje x                     
        float y;  // Posición en el eje y                     
    };

    // Estructura para representar un vector 3D
    struct Vec3 {                                          
        float x;  // Posición en el eje x                     
        float y;  // Posición en el eje y                     
        float z;  // Posición en el eje z                     
    };

    // Estructura para representar colores en formato ARGB
    struct ARGB {                                          
        int a;  // Valor de Alfa [0 - 255]                     
        int r;  // Valor de Rojo [0 - 255]                     
        int g;  // Valor de Verde [0 - 255]                    
        int b;  // Valor de Azul [0 - 255]                     
    };

    // Enumeración para representar direcciones
    enum class Direcciones {                              
        Izquierda,  // Valor 0                                  
        Derecha,    // Valor 1                                  
        Arriba,     // Valor 2                                  
        Abajo,      // Valor 3                                  
        Ninguno     // Valor 4                                  
    };

    // Enumeración para representar opciones
    enum class Opciones {                                 
        A,  // Valor 0                                            
        B,  // Valor 1                                            
        C,  // Valor 2                                            
        D,  // Valor 3                                            
        N   // Valor 4                                            
    };

    // Enumeración para representar tipos de personajes
    enum class Tipos {                                   
        Robot,  // Valor 0                                          
        Chico,  // Valor 1                                          
        Chica,  // Valor 2                                          
        Chique, // Valor 3                                          
        Vacio   // Valor 4                                          
    };

    // Estructura para representar una pregunta con opciones y respuesta
    struct Pregunta {                                     
        std::string pregunta;  // Texto de la pregunta, puede usar "\n" para nuevas líneas
        std::string opcionA;   // Texto de la opción A, puede usar "\n" para nuevas líneas
        std::string opcionB;   // Texto de la opción B, puede usar "\n" para nuevas líneas
        std::string opcionC;   // Texto de la opción C, puede usar "\n" para nuevas líneas
        std::string respuesta; // Texto de la respuesta, puede usar "\n" para nuevas líneas
    };

    // Función para obtener un número aleatorio entre min y max (ambos inclusive)
    int getAleatorio(int min, int max) {
        System::Random Aleatorio;
        return Aleatorio.Next(min, (max + 1));
    }

    // Retorna el tamaño constante de una celda, que es 64
    int getCelda() {
        return 64;
    }

    // Funciones para obtener colores específicos

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