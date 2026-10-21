Propuesta de mejora elaborada por: [Alan Rodrigo Guardiola Martinez ]

**Matrícula:** [26141 ]
**Título de la propuesta:** [Mostrar todas las materias empatadas con más reprobados]

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

[Es una mejora. Actualmente, si dos o más materias tienen la misma cantidad máxima de alumnos reprobados, el reporte muestra solamente una. Esto puede ocultar que existe un empate. La propuesta mostraría todas las materias que comparten la cantidad más alta de reprobados. Beneficia a quien consulta el reporte porque presenta la comparación completa y evita dar prioridad a una materia sobre otra cuando están empatada]

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (arreglos, constantes, funciones, menú)? Justifica cada cambio.

[Se cambia la parte final de la función mostrarAprobados, donde se decide qué materia tiene más reprobados. Primero se obtiene la cantidad máxima entre Español, Matemáticas y Diseño de Programas. Después se muestra cada materia cuyo número de reprobados sea igual a ese máximo.
No se necesitan nuevos arreglos, constantes ni opciones de menú. Se reutilizan los contadores repEspanol, repMatematicas y repProgramas.]

## 3. Receta

mostrarAprobados(nombres, espanol, matematicas, programas, total)
    SI total == 0
        MOSTRAR "No hay alumnos registrados."
        REGRESAR

    apEspanol ← contarAprobados(espanol, total)
    apMatematicas ← contarAprobados(matematicas, total)
    apProgramas ← contarAprobados(programas, total)

    repEspanol ← total - apEspanol
    repMatematicas ← total - apMatematicas
    repProgramas ← total - apProgramas

    MOSTRAR el título del reporte
    MOSTRAR aprobados y reprobados de cada materia

    [CAMBIA] mayorReprobados ← el mayor valor entre
             repEspanol, repMatematicas y repProgramas

    [CAMBIA] MOSTRAR "Materia(s) con más reprobados:"

    [NUEVO] SI repEspanol == mayorReprobados
        MOSTRAR "Español"

    [NUEVO] SI repMatematicas == mayorReprobados
        MOSTRAR "Matemáticas"

    [NUEVO] SI repProgramas == mayorReprobados
        MOSTRAR "Diseño de Programas"