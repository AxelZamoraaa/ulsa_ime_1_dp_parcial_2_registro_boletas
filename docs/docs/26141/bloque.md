## 1. Autor

**Nombre:** [Alan Rodrigo Guardiola Martinez ]
**Matrícula:** [ 26141 ]
**Bloque y opción elegida:** [aprobados ]
**Archivo de código:** [aprovados.h ]

## 2. Propósito

¿Qué hace tu bloque y para qué le sirve a quien usa el programa?

[Muestra cuantos alumnos aprobaron y reprobaron cada materia al igual que muestra en que materia hubo mas reprobados y compararlos.]

## 3. Entradas y salidas

¿Qué recibe tu bloque (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

[ Entradas: los arreglos de calificaciones de español, matematicas y diseño de programas tambien recibe arreglos de nombres.
Salidas: muestra el titulo del reporte, la cantidad de aprobados y reprobados por materia y la materia con mas reprobados.]

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu bloque y qué hace cada una?**

["contarAprobados" recorre las calificaciones de una materia y cuenta cuántas son iguales o mayores que la calificación aprobatoria.
"conNumero" devuelve una palabra en singular si la cantidad es 1 y en plural en los demás casos, por ejemplo, “1 aprobado” o “2 aprobados".
"mostrarAprobados" verifica que haya alumnos, obtiene los conteos de las tres materias, calcula los reprobados y muestra el reporte. También determina cuál materia tiene más reprobados.]

**¿Qué ciclo usaste y por qué ese?**

[Ciclo "for" porque se cauntas calificaciones debo revisar]

**¿Qué acumuladores o contadores usaste y con qué valor inician?**

[aprobados inicia en 0 en contarAprobados y aumenta cada vez que encuentra una calificación aprobatoria. En mostrarAprobados, apEspanol, apMatematicas y apProgramas guardan los aprobados de cada materia. repEspanol, repMatematicas y repProgramas se calculan restando los aprobados al total de alumnos.]

**¿Dónde está tu decisión múltiple y qué casos cubre?**

[Uso decisiones if para revisar si cada calificación alcanza el 7. También uso if, else if y else para decidir cuál materia tiene más reprobados. Si hay empate, se muestra primero Español; si no, se compara Matemáticas con Diseño de Programas]

**¿Qué constantes definiste y por qué son constantes?**

[Definí TITULO_APROBADOS para guardar el título del reporte, porque no cambia durante la ejecución. También se usa CALIFICACION_APROBATORIA, definida en registro.h, cuyo valor es 7 y representa la calificación mínima para aprobar.]

**¿Qué casos de rechazo maneja tu bloque y qué mensaje muestra en cada uno?**

[Si no hay alumnos registrados (total == 0), el bloque no puede hacer el reporte. Muestra “No hay alumnos registrados.” y termina la función. No pide datos por teclado ni valida calificaciones, porque esas tareas se realizan en otros bloques]

## 5. Receta

contarAprobados(calificaciones, total)
    aprobados ← 0

    PARA i DESDE 0 HASTA total - 1
        SI calificaciones[i] >= 7
            aprobados ← aprobados + 1

    REGRESAR aprobados


conNumero(n, palabra)
    SI n == 1
        REGRESAR palabra
    SINO
        REGRESAR palabra + "s"


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
    MOSTRAR aprobados y reprobados de Español
    MOSTRAR aprobados y reprobados de Matemáticas
    MOSTRAR aprobados y reprobados de Diseño de Programas

    SI repEspanol >= repMatematicas Y repEspanol >= repProgramas
        MOSTRAR "Materia con más reprobados: Español"
    SINO SI repMatematicas >= repProgramas
        MOSTRAR "Materia con más reprobados: Matemáticas"
    SINO
        MOSTRAR "Materia con más reprobados: Diseño de Programas"

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Sí. Con los seis alumnos del escenario, conté como aprobatorias las calificaciones iguales o mayores que 7.
Español: 4 aprobados y 2 reprobados.
Matemáticas: 4 aprobados y 2 reprobados.
Diseño de Programas: 5 aprobados y 1 reprobado.
Español y Matemáticas empatan con 2 reprobados. Como el código prioriza Español en caso de empate, el reporte muestra: “Materia con más reprobados: Español]

## 6. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
