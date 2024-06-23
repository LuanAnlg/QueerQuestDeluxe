#pragma once

#include "formlib.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

class Trivia {
private:
    std::vector<formlib::Pregunta> preguntas;  // Vector para almacenar las preguntas
    int cantidadPreguntas;                     // Número de preguntas restantes
    std::vector<bool> preguntados;             // Vector para seguir las preguntas ya formuladas

public:
    // Constructor que inicializa las preguntas según la dificultad
    Trivia(formlib::Dificultades dificultad) : cantidadPreguntas(15), preguntados(15, false) {
        // Determinar la ruta de los archivos según la dificultad
        std::string rutaDificultad = (dificultad == formlib::Dificultades::Facil) ? "facil" : "dificil";

        preguntas.resize(15);  // Redimensionar el vector de preguntas a 15

        // Cargar las preguntas desde los archivos
        for (int i = 0; i < 15; i++) {
            std::ifstream preguntaFile;
            std::string contenido;
            std::string ruta = "Preguntas\\pregunta_" + rutaDificultad + "_numero_" + std::to_string(i + 1) + ".txt";

            preguntaFile.open(ruta);
            if (!preguntaFile.is_open()) {
                std::cout << "No se pudo abrir el archivo: " + ruta << std::endl;
                return;  // Salir del constructor en caso de error
            }

            std::getline(preguntaFile, contenido);
            preguntas[i].opcion = static_cast<formlib::Opciones>(std::stoi(contenido));
            std::getline(preguntaFile, contenido);
            preguntas[i].pregunta = contenido;
            std::getline(preguntaFile, contenido);
            preguntas[i].opcionA = contenido;
            std::getline(preguntaFile, contenido);
            preguntas[i].opcionB = contenido;
            std::getline(preguntaFile, contenido);
            preguntas[i].opcionC = contenido;
            std::getline(preguntaFile, contenido);
            preguntas[i].respuesta = contenido;

            preguntaFile.close();
        }
    }

    // Destructor para limpiar el vector de preguntas
    ~Trivia() {
        preguntas.clear();
    }

    // Método para obtener una pregunta al azar que no haya sido formulada
    formlib::Pregunta preguntar() {
        int indice;
        do {
            indice = formlib::getAleatorio(0, 14);
        } while (preguntados[indice]);

        preguntados[indice] = true;
        cantidadPreguntas--;

        return preguntas[indice];
    }

    // Método para obtener la cantidad de preguntas restantes
    int getCantidadPreguntas() const {
        return cantidadPreguntas;
    }
};