#pragma once

#include "Robot.h"
#include "Aliado.h"
#include <vector>

class Grupo {
private:
    Robot* robot;                    // Objeto Robot del grupo
    std::vector<Aliado*> aliados;    // Vector de aliados del grupo

public:
    // Constructor de Grupo
    Grupo(formlib::Vec2 posicion, System::Drawing::Bitmap^ hojaSprites) {
        // Crear el robot con la posici�n inicial y la hoja de sprites
        robot = new Robot(posicion, hojaSprites);
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

    // M�todo para obtener la cantidad de aliados en el grupo
    int getCantidadAliados() const {
        return static_cast<int>(aliados.size());
    }

    // M�todo para agregar un nuevo aliado al grupo
    void agregarAliado(System::Drawing::Bitmap^ hojaSprites, formlib::Tipos tipo) {
        // Verificar si el grupo est� vac�o para calcular la posici�n inicial
        formlib::Vec2 nuevaPosicion;
        formlib::Direcciones nuevaDireccion = formlib::Direcciones::Ninguno;

        if (aliados.empty()) {
            nuevaPosicion = { static_cast<float>(robot->getRectanguloColision().X), static_cast<float>(robot->getRectanguloColision().Y) };
        }
        else {
            // Obtener la posici�n y direcci�n del �ltimo aliado en el grupo
            nuevaPosicion = { static_cast<float>(aliados.back()->getRectanguloColision().X), static_cast<float>(aliados.back()->getRectanguloColision().Y) };
            nuevaDireccion = aliados.back()->getDireccion();
        }

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

    // M�todo para eliminar al �ltimo aliado del grupo
    void eliminarAliado() {
        if (!aliados.empty()) {
            delete aliados.back();
            aliados.pop_back();
        }
    }

    // M�todo para actualizar la posici�n y direcci�n de los aliados y del robot
    void actualizar(System::Drawing::Graphics^ graphics, formlib::Direcciones direccion) {
        // Actualizar la direcci�n del robot
        robot->setDireccion(direccion);

        // Verificar si hay aliados para mover
        if (!aliados.empty()) {
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
        }

        // Actualizar la posici�n del robot seg�n la direcci�n
        robot->actualizar(graphics, direccion);
    }

    // M�todo para dibujar a los aliados y al robot
    void dibujar(System::Drawing::Graphics^ graphics, System::Drawing::Bitmap^ hojaSprites) {
        // Verificar si hay aliados para dibujar
        if (!aliados.empty()) {
            // Dibujar a los aliados en orden inverso
            for (int i = static_cast<int>(aliados.size()) - 1; i >= 0; --i) {
                aliados[i]->dibujar(graphics, hojaSprites);
            }
        }

        // Dibujar al robot
        robot->dibujar(graphics, hojaSprites);
    }
};