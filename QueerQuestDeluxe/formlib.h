
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

    // Enumeración para representar las dificultades
    enum class Dificultades {
        Facil,  // Valor 0
        Dificil // Valor 1
    };

    // Estructura para representar una pregunta con opciones y respuesta
    struct Pregunta {
        Opciones opcion;
        std::string pregunta;  // Texto de la pregunta, puede usar "\n" para nuevas líneas
        std::string opcionA;   // Texto de la opción A, puede usar "\n" para nuevas líneas
        std::string opcionB;   // Texto de la opción B, puede usar "\n" para nuevas líneas
        std::string opcionC;   // Texto de la opción C, puede usar "\n" para nuevas líneas
        std::string respuesta; // Texto de la respuesta, puede usar "\n" para nuevas líneas
    };

    enum class Resultado {
        gano,     // Valor 0
        perdio,   // Valor 1
        sacrifico // Valor 2
    };

    // Función para obtener un número aleatorio entre min y max (ambos inclusive)
    int getAleatorio(int min, int max);

    // Retorna el tamaño constante de una celda, que es 64
    int getCelda();

    // Funciones para obtener colores específicos

    // Colores Blanco y Negro
    System::Drawing::Color Negro();
    System::Drawing::Color Blanco();

    // Colores de la Paleta LGBT
    System::Drawing::Color Rojo();
    System::Drawing::Color Naranja();
    System::Drawing::Color Amarillo();
    System::Drawing::Color Verde();
    System::Drawing::Color Azul();
    System::Drawing::Color Violeta();

    // Colores de la Paleta PICO-8
    System::Drawing::Color P8Negro();
    System::Drawing::Color P8AzulOscuro();
    System::Drawing::Color P8MoradoOscuro();
    System::Drawing::Color P8VerdeOscuro();
    System::Drawing::Color P8Marron();
    System::Drawing::Color P8GrisOscuro();
    System::Drawing::Color P8GrisClaro();
    System::Drawing::Color P8Blanco();
    System::Drawing::Color P8Rojo();
    System::Drawing::Color P8Naranja();
    System::Drawing::Color P8Amarillo();
    System::Drawing::Color P8Verde();
    System::Drawing::Color P8Azul();
    System::Drawing::Color P8Lavanda();
    System::Drawing::Color P8Rosa();
    System::Drawing::Color P8DuraznoClaro();
}