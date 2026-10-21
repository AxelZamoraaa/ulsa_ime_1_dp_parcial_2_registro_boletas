#pragma once
#include <iostream>
#include <string>
#include "utilerias.h"
#include "registro.h"

const std::string MENSAJE_LISTA_LLENA = "la lista esta llena";

double pedirCalificacion(std::string materia) {
    double calificacion;
    bool valida = false;
    do{
        calificacion = leerDecimal(materia + ": ");
        if(calificacionValida(calificacion)){
            valida = true;
        } else if (calificacion < CALIFICACION_MINIMA) {
            std::cout << "La calificacion no puede ser negativa. \n";
        } else { 
            std::cout << "La calificacion no puede ser mayor a 10. \n";

        }
    }while (!valida);
    return calificacion;
}

std:: string pedirNombre() {
    std::string nombre;
    do {
        nombre = leerCadena("Nombre: ");
        if (nombre == "") {
            std::cout << "El nombre no puede quedar vacio.\n";
        }
    } while (nombre == "");
    return nombre;
}


int capturarAlumno(std::string nombres[], double espanol[], double matematicas[],
                   double programas[], int total) {
    if (total >= MAX_ALUMNOS) {
        std::cout << MENSAJE_LISTA_LLENA << " (" << MAX_ALUMNOS << " alumnos).\n";
        return total;
    }
    std::string nombre = pedirNombre();
    double calEspanol = pedirCalificacion("Espanol");
    double calMatematicas = pedirCalificacion("Matematicas");
    double calProgramas = pedirCalificacion("Diseno de Programas");

    total = agregarAlumno(nombres, espanol, matematicas, programas, total,
                          nombre, calEspanol, calMatematicas, calProgramas);
    std::cout << "Alumno " << total << " registrado.\n";
    return total;
}