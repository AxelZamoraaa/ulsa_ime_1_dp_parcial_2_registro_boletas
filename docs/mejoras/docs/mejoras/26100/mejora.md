
Propuesta de mejora elaborada por: Regina Murillo 

**Matrícula:** 26100
**Título de la propuesta:** Eliminar alumno, corregir errores de captura sin reiniciar el programa

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

Es una mejora, ya que al momento de capturar un alumno, si por error escribes alguna calificación mal, no hay manera de quitarlo y la unica manera de solucionar es volver a empezar el programa. 

La propuesta de la opción Eliminar alumno en el menu, buscaria al alumno por nombre, pediria confirmación de eliminarlo y lo quitaria sin dejar una afectación en el codigo, de esta manera puedes volver a capturar al alumno con los datos correctos, sin necesidad de reiniciar el codigo y peder el avance. 

Beneficiaria al maestro ya que podria volver a repetir las calificaciones en caso de un error. 

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (arreglos, constantes, funciones, menú)? Justifica cada cambio.


Se agrega una función nueva, eliminarAlumno. Busca al alumno por nombre, pide confirmación y lo quita. Por qué: no hay forma de quitar a un alumno. Se hace en una función.

Al eliminar, se recorren los datos en los cuatro arreglos a la vez. Los alumnos que están después del eliminado suben un lugar, y al final el total baja en 1. Ejemplo con el escenario: si eliminas a Marta (posición 3 de la lista), Jorge, Sofia y Raul suben un lugar y el total pasa de 6 a 5.
Si se moviera solo uno, las calificaciones quedarían con el nombre equivocado. Y sin huecos, los reportes siguen funcionando igual.

Antes de eliminar se pide confirmación, SI o NO, si deseas realizar esa acción cualquier opción que no sea 1 o 2 no borra a nadie para que un error de teclado no borre a un alumno por accidente.

El menú de main.cpp tiene tres cambios pequeños: se agrega case 7 para eliminar alumno, "Salir" pasa a ser case 8 para que el usuario pueda llegar a la opción nueva sin perder todo.


## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
INICIO

    REPETIR

        SEGUN opcion
            1. Capturar alumno
            2. Mostrar lista
            3. Estadisticas por materia
            4. Aprobados y reprobados
            5. Boleta individual
            6. Materias reprobadas por alumno
            [NUEVO] 7: total = eliminarAlumno
            [CAMBIA] 8: Salir
            otro caso: mostrar "Opcion invalida."
    [CAMBIA] MIENTRAS opcion sea distinta de 8


[NUEVO] FUNCION eliminarAlumno(nombres, espanol, matematicas, programas, total)
    // Toda la funcion es nueva.
    SI total == 0 ENTONCES
        mostrar "No hay alumnos registrados."
        DEVOLVER total
    FIN SI

    nombreBuscado = leerCadena("Nombre del alumno a eliminar: ")
    posicion = -1

    PARA i DESDE 0 HASTA total - 1
        SI nombres[i] == nombreBuscado ENTONCES
            posicion = i
            SALIR DEL CICLO
        FIN SI
    FIN PARA

    SI posicion == -1 ENTONCES
        mostrar "No se encontro al alumno " + nombreBuscado + "."
        DEVOLVER total
    FIN SI

    mostrar "Eliminar a " + nombres[posicion] + "?"
    mostrar "1. Si"
    mostrar "2. No"
    confirmacion = leerEntero("Opcion: ")

    SI confirmacion != 1 ENTONCES
        mostrar "Eliminacion cancelada."
        DEVOLVER total
    FIN SI

    // Se recorren los alumnos posteriores un lugar hacia atras, en los cuatro arreglos.
    // Ejemplo del escenario: al eliminar a Marta (posicion 2), Jorge, Sofia y Raul
    // suben un lugar y el total pasa de 6 a 5.
    PARA i DESDE posicion HASTA total - 2
        nombres[i] = nombres[i + 1]
        espanol[i] = espanol[i + 1]
        matematicas[i] = matematicas[i + 1]
        programas[i] = programas[i + 1]
    FIN PARA

    total = total - 1
    mostrar "Alumno eliminado correctamente."
    DEVOLVER total
FIN FUNCION