#pragma once
#include <iostream>
#include <string>
#include "utilerias.h"
#include "registro.h"
 
const int MATERIAS_BOLETA = 3;
 
void mostrarBoleta(std::string nombres[], double espanol[], double matematicas[],
                   double programas[], int total) {
    if (total == 0) {
        std::cout << "No hay alumnos registrados.\n";
        return;
    }
 
    std::string buscado = leerCadena("Nombre a buscar: ");
 
    int posicion = -1;
    for (int i = 0; i < total; i++) {
        if (nombres[i] == buscado) {
            posicion = i;
        }
    }
 
    if (posicion == -1) {
        std::cout << "No se encontro al alumno " << buscado << ".\n";
        return;
    }
 

    int reprobadas = 0;
    if (espanol[posicion] < CALIFICACION_APROBATORIA) {
        reprobadas++;
    }
    if (matematicas[posicion] < CALIFICACION_APROBATORIA) {
        reprobadas++;
    }
    if (programas[posicion] < CALIFICACION_APROBATORIA) {
        reprobadas++;
    }
 
    double promedio = (espanol[posicion] + matematicas[posicion] + programas[posicion])
                      / MATERIAS_BOLETA;
 
    std::string estado;
    if (reprobadas == 0) {
        estado = "Aprobado";
    } else if (reprobadas == MATERIAS_BOLETA) {
        estado = "Reprobado (reprobo todas)";
    } else {
        estado = "Reprobado";
    }
 
    std::cout << "--- BOLETA ---\n";
    std::cout << "Alumno: " << nombres[posicion] << "\n";
    std::cout << "Espanol: " << espanol[posicion]
              << " Matematicas: " << matematicas[posicion]
              << " Diseno de Programas: " << programas[posicion] << "\n";
    std::cout << "Promedio: " << promedio
              << " Materias reprobadas: " << reprobadas
              << " Estado: " << estado << "\n";
}