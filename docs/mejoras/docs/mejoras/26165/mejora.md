Propuesta de mejora elaborada por: [resumen general de rendimiento]

**Matrícula:** [26165]
**Título de la propuesta:** [Rendimiento de grupo]

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

[Una mejora, agrega un resumen general del grupo que muestre cuántas materias se aprobaron y reprobaron en total, además del porcentaje de aprobación y reprobación. Así sería más fácil conocer el rendimiento académico de todo el grupo.]

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (arreglos, constantes, funciones, menú)? Justifica cada cambio.

Se le agregaria:
int totalMaterias = totalAprobadas + totalReprobadas;

cout << "\n--- RESUMEN GENERAL ---\n";
cout << "Materias aprobadas: " << totalAprobadas << "\n";
cout << "Materias reprobadas: " << totalReprobadas << "\n";

if (totalMaterias > 0) {
    double porcentajeAprobadas =
        (totalAprobadas * 100.0) / totalMaterias;

    double porcentajeReprobadas =
        (totalReprobadas * 100.0) / totalMaterias;

    cout << "Porcentaje de aprobacion: "
         << porcentajeAprobadas << "%\n";

    cout << "Porcentaje de reprobacion: "
         << porcentajeReprobadas << "%\n";
}

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
[INICIO

    SI el total de alumnos es 0 ENTONCES
        Mostrar "No hay alumnos registrados"
        Terminar función
    FIN SI

    Mostrar el título de materias reprobadas
    Inicializar alumnosConReprobadas = 0

    [NUEVO] Inicializar totalAprobadas = 0
    [NUEVO] Inicializar totalReprobadas = 0

    PARA cada alumno DESDE 0 HASTA total - 1 HACER
        Inicializar reprobadas = 0

        [CAMBIA] SI Español es menor que la calificación aprobatoria ENTONCES
            Aumentar reprobadas en 1
            [NUEVO] Aumentar totalReprobadas en 1
        [CAMBIA] SINO
            [NUEVO] Aumentar totalAprobadas en 1
        FIN SI

        [CAMBIA] SI Matemáticas es menor que la calificación aprobatoria ENTONCES
            Aumentar reprobadas en 1
            [NUEVO] Aumentar totalReprobadas en 1
        [CAMBIA] SINO
            [NUEVO] Aumentar totalAprobadas en 1
        FIN SI

        [CAMBIA] SI Programación es menor que la calificación aprobatoria ENTONCES
            Aumentar reprobadas en 1
            [NUEVO] Aumentar totalReprobadas en 1
        [CAMBIA] SINO
            [NUEVO] Aumentar totalAprobadas en 1
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

    [NUEVO] Calcular totalMaterias = totalAprobadas + totalReprobadas

    [NUEVO] Mostrar "RESUMEN GENERAL"
    [NUEVO] Mostrar total de materias aprobadas
    [NUEVO] Mostrar total de materias reprobadas

    [NUEVO] SI totalMaterias es mayor que 0 ENTONCES
        [NUEVO] Calcular porcentajeAprobadas =
                (totalAprobadas * 100) / totalMaterias

        [NUEVO] Calcular porcentajeReprobadas =
                (totalReprobadas * 100) / totalMaterias

        [NUEVO] Mostrar porcentaje de aprobación
        [NUEVO] Mostrar porcentaje de reprobación
    FIN SI

FIN]