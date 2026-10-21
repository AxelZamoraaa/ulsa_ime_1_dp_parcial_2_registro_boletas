**Matrícula:** 26295
**Título de la propuesta:** Usar una constante para la calificación máxima y no aceptar nombres que solo tengan espacios

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

Es una corrección. Arregla dos problemas en la captura de alumnos:

El número 10 está escrito directo en el mensaje de error (no puede ser mayor a 10). Para el mínimo sí usamos una constante, pero para el máximo no, Si algún día el máximo cambia, el mensaje diría algo falso
Si alguien escribe un nombre con solo espacios (" "), el programa lo acepta. Después ese alumno sale sin nombre en la boleta y en las listas

Beneficia a la persona que usa el programa, porque ve mensajes correctos, y a mis compañeros, porque sus bloques reciben nombres que sí sirven

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (arreglos, constantes, funciones, menú)? Justifica cada cambio.

Constante nueva: CALIFICACION_MAXIMA = 10.0 en registro.h, junto a CALIFICACION_MINIMA. Así los dos límites están en el mismo lugar y se cambian una sola vez

Función calificacionValida: ahora compara contra las dos constantes, sin números escritos a mano

Función pedirCalificacion: solo cambia el último mensaje de error, que ahora usa la constante en lugar del 10

Función nueva quitarEspacios: le quita los espacios que tenga al principio y al final a un texto

Función pedirNombre: ahora limpia el nombre con quitarEspacios antes de ver si quedó vacío

Lo que no cambia: los arreglos, el menú y main. Todo el cambio está dentro de la captura

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
FUNCION quitarEspacios(texto)                                   [NUEVO]
    Quitar los espacios del principio y del final del texto     [NUEVO]
    Devolver el texto limpio                                    [NUEVO]

FUNCION pedirNombre()
    Repetir:
        Pedir el nombre
        Limpiar el nombre con quitarEspacios                    [CAMBIA]
        Si el nombre está vacío, mostrar "El nombre no puede quedar vacio."
    Mientras el nombre esté vacío
    Devolver el nombre

FUNCION calificacionValida(calificacion)
    Devolver verdadero si la calificación está entre
    CALIFICACION_MINIMA y CALIFICACION_MAXIMA                   [CAMBIA]

FUNCION pedirCalificacion(materia)
    Repetir:
        Pedir la calificación de la materia
        Si es válida, terminar
        Si es menor al mínimo, mostrar "La calificacion no puede ser negativa."
        Si no, mostrar "La calificacion no puede ser mayor a"
        y el valor de CALIFICACION_MAXIMA                       [CAMBIA]
    Mientras la calificación no sea válida
    Devolver la calificación

FUNCION capturarAlumno(arreglos, total)
    Si la lista está llena:
        Mostrar el mensaje de lista llena
        Devolver total sin cambios
    Pedir el nombre
    Pedir la calificación de Español
    Pedir la calificación de Matemáticas
    Pedir la calificación de Diseño de Programas
    Guardar al alumno con agregarAlumno
    Mostrar "Alumno N registrado."
    Devolver el nuevo total```
