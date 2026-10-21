## 1. Autor

**Nombre:** [Pablo Mussa]
**Matrícula:** [26165]
**Bloque y opción elegida:** [reprobados]
**Archivo de código:** [reprobadas.h]

## 2. Propósito

¿Qué hace tu bloque y para qué le sirve a quien usa el programa?

[ver quienes reprobaron]

## 3. Entradas y salidas

¿Qué recibe tu bloque y qué produce?

Mi bloque recibe los nombres de los alumnos, sus calificaciones de Español, Matemáticas y Programación, y el total de alumnos registrados. Produce en pantalla una lista de los alumnos que reprobaron al menos una materia, indicando cuántas materias reprobaron. También muestra un mensaje final con el resumen de los resultados.

## 4. Decisiones de diseño

¿Qué funciones tiene tu bloque y qué hace cada una?

Mi bloque tiene la función mostrarReprobadas(), que revisa las calificaciones de cada alumno, cuenta las materias reprobadas e imprime sus nombres y la cantidad de materias que reprobaron. También verifica si hay alumnos registrados y muestra un mensaje cuando no hay datos.

¿Qué ciclo usaste y por qué ese?

Utilicé un ciclo for porque conozco el total de alumnos registrados y necesito revisar las calificaciones de cada uno desde el primero hasta el último.

¿Qué acumuladores o contadores usaste y con qué valor inician?

Utilicé dos contadores:

* alumnosConReprobadas: inicia en 0 y cuenta cuántos alumnos reprobaron al menos una materia.
* reprobadas: inicia en 0 para cada alumno y cuenta cuántas materias reprobó entre Español, Matemáticas y Programación.

¿Dónde está tu decisión múltiple y qué casos cubre?

La decisión múltiple está al final de la función, utilizando if, else if y else. Cubre tres casos:

* Si ningún alumno reprobó materias, muestra: "Ningun alumno reprobo materias."
* Si todos los alumnos reprobaron al menos una materia, muestra: "Todos los alumnos reprobaron al menos una materia" y la cantidad.
* Si solo algunos alumnos reprobaron, muestra: "Alumnos con materias reprobadas:" y la cantidad.

¿Qué constantes definiste y por qué son constantes?

Utilicé la constante TITULO_REPROBADAS, que contiene el título "--- MATERIAS REPROBADAS POR ALUMNO ---". También utilizo CALIFICACION_APROBATORIA, definida en el archivo registro.h, para comparar las calificaciones. Son constantes porque sus valores representan datos fijos que no necesitan cambiar durante la ejecución del programa.

¿Qué casos de rechazo maneja tu bloque y qué mensaje muestra en cada uno?

Mi bloque maneja el caso en el que no hay alumnos registrados. Si el valor de total es 0, muestra el mensaje "No hay alumnos registrados." y termina la función con return. También identifica cuando ningún alumno reprobó y muestra el mensaje correspondiente.

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

INICIO
    SI el total de alumnos es 0 ENTONCES
        Mostrar "No hay alumnos registrados"
        Terminar función
    FIN SI
    Mostrar el título de materias reprobadas
    Inicializar alumnosConReprobadas = 0
    PARA cada alumno DESDE 0 HASTA total - 1 HACER
        Inicializar reprobadas = 0
        SI Español es menor que la calificación aprobatoria
            Aumentar reprobadas en 1
        FIN SI
        SI Matemáticas es menor que la calificación aprobatoria
            Aumentar reprobadas en 1
        FIN SI
        SI Programación es menor que la calificación aprobatoria
            Aumentar reprobadas en 1
        FIN SI
        SI reprobadas es mayor que 0 ENTONCES
            Mostrar nombre del alumno y materias reprobadas
            Aumentar alumnosConReprobadas en 1
        FIN SI
    FIN PARA
    SI alumnosConReprobadas es igual a 0 ENTONCES
        Mostrar "Ningun alumno reprobo materias"
    SINO SI alumnosConReprobadas es igual a total ENTONCES
        Mostrar que todos reprobaron al menos una materia
        Mostrar la cantidad de alumnos
    SINO
        Mostrar la cantidad de alumnos con materias reprobadas
    FIN SI
FIN

¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?

Sí, revisé manualmente cómo se contarían las materias reprobadas de cada alumno. Comprobé que el contador de materias inicia en cero para cada alumno y que el contador general solo aumenta cuando un alumno reprueba al menos una materia. También verifiqué los casos en los que ningún alumno reprueba, todos reprueban o solo algunos reprueban.

## 6. Bitácora de dudas y errores

#	Duda o error	Cómo lo resolví
1	Cómo contar las materias reprobadas de cada alumno:	Utilicé el contador reprobadas, que aumenta cuando una calificación es menor que la aprobatoria.
2	Cómo contar a los alumnos que reprobaron al menos una materia:	Utilicé alumnosConReprobadas, que aumenta una sola vez por cada alumno que tiene una o más materias reprobadas.
3	Cómo mostrar un mensaje diferente según los resultados:	Utilicé if, else if y else para distinguir entre ningún alumno, todos los alumnos o solo algunos alumnos con materias reprobadas.