## 1. Autor

**Nombre:** [Erick Aguilar Martinez]
**Matrícula:** [26076]
**Bloque y opción elegida:** [Boletas]
**Archivo de código:** [Boletas.h]


2. Propósito

Mi bloque muestra la boleta de un alumno que ya está registrado. El usuario escribe el nombre, el programa lo busca en la lista y le saca las tres calificaciones (Español, Matemáticas y Diseño de Programas), el promedio, cuántas materias reprobó y si quedó aprobado o reprobado. Sirve para que el maestro o quien use el programa no tenga que ir calculando esto a mano cada vez que quiere saber como va un alumno.

3. Entradas y salidas

Entra por parámetros: el arreglo nombres, los arreglos espanol, matematicas y programas (uno por materia, y la posición de cada alumno es la misma en los cuatro) y total, que es cuantos alumnos hay registrados.

Entra por teclado: el nombre del alumno a buscar, con leerCadena.

Sale: la función es void, asi que no devuelve nada. Lo que produce es lo que imprime: la boleta con nombre, las tres calificaciones, el promedio, las materias reprobadas y el estado. Si algo sale mal imprime un mensaje de rechazo y termina.

4. Decisiones de diseño

¿Qué funciones tiene tu bloque y qué hace cada una?

Mi bloque tiene una sola función, mostrarBoleta. Hace todo el trabajo: pide el nombre, lo busca, cuenta reprobadas, saca el promedio, decide el estado e imprime. Pensé en separarla en funciones mas chicas (una para buscar, otra para calcular) pero para el tamaño del ejercicio me pareció que se entendia bien junta. Tambien uso leerCadena de utilerias.h, que no la hice yo, solo la llamo.

¿Qué ciclo usaste y por qué ese?

Un for para buscar el nombre en el arreglo. Lo elegí porque ya se cuantas vueltas son (de 0 hasta total) y el for junta el contador, la condición y el incremento en una sola línea. Un while también hubiera servido pero habría tenido que declarar y subir el contador por separado. Algo que note es que mi ciclo no se detiene cuando encuentra el nombre, sigue hasta el final, así que si hubiera dos alumnos con el mismo nombre se queda con el último.

¿Qué acumuladores o contadores usaste y con qué valor inician?

reprobadas inicia en 0. Voy sumando 1 por cada materia con calificación menor a CALIFICACION_APROBATORIA.
posicion inicia en -1. Lo uso como bandera: si al terminar el ciclo sigue en -1 es que el nombre no existe, porque -1 nunca puede ser un índice válido.
i es el contador del for, inicia en 0.

¿Dónde está tu decisión múltiple y qué casos cubre?

Está en el cálculo del estado, con if / else if / else. Cubre tres casos: si reprobadas == 0 el estado es “Aprobado”, si reprobadas == MATERIAS_BOLETA es “Reprobado (reprobo todas)”, y en cualquier otro caso (reprobó una o dos) es “Reprobado”. No usé switch porque las condiciones comparan contra variables y no contra valores fijos sueltos, y el if me quedo mas natural.

¿Qué constantes definiste y por qué son constantes?

Definí MATERIAS_BOLETA = 3, el número de materias de la boleta. Lo uso para sacar el promedio y para saber cuando reprobó todas. Es constante porque no cambia mientras corre el programa, y si algún día agregan una materia solo lo cambio en un lugar en vez de buscar todos los 3 del código. CALIFICACION_APROBATORIA tambien se usa aquí pero viene de registro.h, no la definí yo.

¿Qué casos de rechazo maneja tu bloque y qué mensaje muestra en cada uno?

Dos:

No hay alumnos (total == 0): muestra “No hay alumnos registrados.” y sale con return.
El nombre no está en la lista (posicion == -1): muestra “No se encontro al alumno” con el nombre que escribieron, y también sale con return.

Los dos van antes de los cálculos para no operar con datos que no existen.

5. Receta
INICIO mostrarBoleta(nombres, espanol, matematicas, programas, total)
    SI total == 0 ENTONCES
        imprimir "No hay alumnos registrados."
        TERMINAR
    FIN SI

    leer buscado
    posicion = -1

    PARA i = 0 HASTA total - 1
        SI nombres[i] == buscado ENTONCES
            posicion = i
        FIN SI
    FIN PARA

    SI posicion == -1 ENTONCES
        imprimir "No se encontro al alumno", buscado
        TERMINAR
    FIN SI

    reprobadas = 0
    SI espanol[posicion] < CALIFICACION_APROBATORIA ENTONCES reprobadas = reprobadas + 1
    SI matematicas[posicion] < CALIFICACION_APROBATORIA ENTONCES reprobadas = reprobadas + 1
    SI programas[posicion] < CALIFICACION_APROBATORIA ENTONCES reprobadas = reprobadas + 1

    promedio = (espanol + matematicas + programas) / MATERIAS_BOLETA

    SI reprobadas == 0 ENTONCES estado = "Aprobado"
    SINO SI reprobadas == MATERIAS_BOLETA ENTONCES estado = "Reprobado (reprobo todas)"
    SINO estado = "Reprobado"

    imprimir boleta completa
FIN

¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?

Sí, la probé con tres casos. Con Ana (Español 8, Matemáticas 5, Programas 9) me dio 1 reprobada, promedio 7.33 y estado “Reprobado”. Con un alumno que tuviera 10, 9 y 8 daba 0 reprobadas, promedio 9 y “Aprobado”. Y con uno que sacó 4, 3 y 2 daba 3 reprobadas y “Reprobado (reprobo todas)”. Al hacerlo a mano me di cuenta de que en la primera versión no tenía el caso de lista vacía, y si el usuario pedía una boleta sin alumnos registrados el programa se iba directo a buscar en un arreglo vacío. Ahi agregué el total == 0. Tambien me faltaba separar el caso de reprobar todas, antes solo tenia “Aprobado” y “Reprobado”.

6. Bitácora de dudas y errores
#	Duda o error	Cómo lo resolví
1	No sabia que valor ponerle a posicion antes del ciclo. Con 0 el programa creía que siempre encontraba a alguien (al primer alumno).	Le puse -1, porque no existe un alumno en esa posición y así puedo saber si el ciclo no encontró nada.
2	El promedio me salía sin decimales al principio, por ejemplo 7 en vez de 7.33.	Lo guardé en una variable double y los arreglos de calificaciones también son double, así la división ya no se trunca.
3	Si el usuario escribía un nombre que no estaba, el programa mostraba una boleta con basura.	Agregué el if (posicion == -1) con su return antes de calcular nada
