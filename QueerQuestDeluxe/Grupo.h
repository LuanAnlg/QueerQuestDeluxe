#pragma once

#include "Robot.h"
#include "Aliado.h"

#include <vector>

class Grupo {
private:
    Robot* robot;
    std::vector<Aliado*> aliados;

public:
    // Constructor de Grupo
    Grupo(formlib::Vec2 posicion, System::Drawing::Bitmap^ hojaSprites) {
        // Crear el robot con la posici�n inicial y la hoja de sprites
        robot = new Robot(posicion, hojaSprites);

        // Crear algunos aliados al inicio del grupo
        aliados.push_back(new Aliado({ posicion.x - static_cast<float>(formlib::getCelda()), posicion.y }, hojaSprites, formlib::Tipos::Chico));
        aliados.push_back(new Aliado({ posicion.x - static_cast<float>(formlib::getCelda() * 2), posicion.y }, hojaSprites, formlib::Tipos::Chica));
    }

    // Destructor de Grupo
    ~Grupo() {
        // Liberar memoria de los aliados
        for (auto aliado : aliados) {
            delete aliado;
        }
        aliados.clear();

        // Liberar memoria del robot
        delete robot;
    }

    // Getter para obtener una copia del objeto Robot actual.
    Robot getRobot() {
        return *robot;
    }


    // M�todo para agregar un nuevo aliado al grupo
    void agregar(System::Drawing::Bitmap^ hojaSprites, formlib::Tipos tipo) {
        // Obtener la posici�n y direcci�n del �ltimo aliado en el grupo
        formlib::Vec2 nuevaPosicion = { static_cast<float>(aliados.back()->getRectanguloColision().X), static_cast<float>(aliados.back()->getRectanguloColision().Y) };
        formlib::Direcciones nuevaDireccion = aliados.back()->getDireccion();

        // Calcular la nueva posici�n y direcci�n para el nuevo aliado
        switch (nuevaDireccion) {
        case formlib::Direcciones::Izquierda:
            nuevaPosicion.x += formlib::getCelda();
            break;
        case formlib::Direcciones::Derecha:
            nuevaPosicion.x -= formlib::getCelda();
            break;
        case formlib::Direcciones::Arriba:
            nuevaPosicion.y -= formlib::getCelda();
            break;
        case formlib::Direcciones::Abajo:
            nuevaPosicion.y += formlib::getCelda();
            break;
        default:
            break;
        }

        // Crear un nuevo aliado con la posici�n y tipo especificados
        aliados.push_back(new Aliado(nuevaPosicion, hojaSprites, tipo));
    }

    // M�todo para actualizar la posici�n y direcci�n de los aliados y del robot
    void actualizar(System::Drawing::Graphics^ graphics, formlib::Direcciones direccion) {
        // Actualizar la direcci�n del robot
        robot->setDireccion(direccion);

        // Mover a los aliados
        for (int i = static_cast<int>(aliados.size()) - 1; i >= 1; --i) {
            // Obtener la posici�n y direcci�n del aliado anterior
            formlib::Vec2 nuevaPosicion = { static_cast<float>(aliados[i - 1]->getRectanguloColision().X), static_cast<float>(aliados[i - 1]->getRectanguloColision().Y) };
            formlib::Direcciones nuevaDireccion = aliados[i - 1]->getDireccion();

            // Establecer la nueva posici�n y direcci�n para el aliado actual
            aliados[i]->setPosicion(nuevaPosicion);
            aliados[i]->setDireccion(nuevaDireccion);
        }

        // Mover al primer aliado a la posici�n del robot
        formlib::Vec2 nuevaPosicion = { static_cast<float>(robot->getRectanguloColision().X), static_cast<float>(robot->getRectanguloColision().Y) };
        formlib::Direcciones nuevaDireccion = robot->getDireccion();

        // Establecer la posici�n y direcci�n del primer aliado
        aliados[0]->setPosicion(nuevaPosicion);
        aliados[0]->setDireccion(nuevaDireccion);

        // Actualizar la posici�n del robot seg�n la direcci�n
        robot->actualizar(graphics, direccion);
    }

    // M�todo para dibujar a los aliados y al robot
    void dibujar(System::Drawing::Graphics^ graphics, System::Drawing::Bitmap^ hojaSprites) {
        // Dibujar a los aliados en orden inverso
        for (int i = static_cast<int>(aliados.size()) - 1; i >= 0; --i) {
            aliados[i]->dibujar(graphics, hojaSprites);
        }

        // Dibujar al robot
        robot->dibujar(graphics, hojaSprites);
    }
};
