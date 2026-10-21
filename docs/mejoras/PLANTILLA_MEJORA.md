# Propuesta de mejora

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/mejoras/<matrícula>/mejora.md (por ejemplo, docs/mejoras/123456/mejora.md)
y llena tu copia.

La propuesta es solo diseño: no se programa.
Puede tocar cualquier parte de la solución del equipo y se resuelve con los temas del parcial.
Dentro de un equipo no puede haber dos propuestas iguales.
-->

Propuesta de mejora elaborada por: [Inserta aquí tu respuesta]

**Matrícula:** [26076]
**Título de la propuesta:** [Mostrar en la boleta cuáles materias reprobó el alumno]

1. Impacto

Es una mejora, no una corrección. Ahorita la boleta dice cuántas materias reprobó el alumno (“Materias reprobadas: 2”), pero no dice cuáles. Si el maestro quiere saber en qué materias anda mal tiene que fijarse en las tres calificaciones y comparar contra la aprobatoria él mismo, que es justo lo que el programa debería hacer por uno.

Con el cambio, la boleta agrega una línea tipo “Reprobo: Matematicas, Diseno de Programas”. Beneficia al maestro o a quien use el programa, que ve de un vistazo en qué debe apoyar al alumno, y también al alumno, porque la boleta le dice que materias tiene que recuperar y no nada mas cuántas.

Tambien deja el código más ordenado. Hoy hay tres if casi idénticos, uno por materia, y con la mejora se juntan en un solo ciclo.

2. Qué implica en el diseño

Lo que cambia es solo la función mostrarBoleta, el menú y los demás archivos quedan igual.

Constante nueva NOMBRES_MATERIAS: un arreglo de tres textos (“Espanol”, “Matematicas”, “Diseno de Programas”). Es constante porque los nombres de las materias no cambian mientras corre el programa, y va a la par con MATERIAS_BOLETA, que ya existe. Si algún día agregan una materia se cambian los dos juntos.
Arreglo local calificaciones[MATERIAS_BOLETA]: se llena con las tres calificaciones del alumno encontrado. Lo necesito porque hoy las notas viven en tres arreglos distintos y no puedo recorrerlas con un ciclo. Con este arreglo la posición 0 es Español, la 1 Matemáticas y la 2 Programas, igual que en NOMBRES_MATERIAS.
Ciclo for nuevo: reemplaza los tres if de reprobadas y también la suma del promedio. Recorre de 0 a MATERIAS_BOLETA - 1, suma cada calificación a un acumulador suma (inicia en 0) y, si es menor a CALIFICACION_APROBATORIA, sube reprobadas y guarda el nombre de la materia en un texto listaReprobadas. Elegí for porque ya se cuántas vueltas son.
Variable nueva listaReprobadas: un std::string que inicia vacío. Antes de agregar un nombre reviso si ya tiene algo para ponerle la coma.
Impresión: si reprobadas > 0 se imprime la línea con las materias, y si no se imprime nada extra para no mostrar una línea vacía.

La decisión múltiple de estado y los casos de rechazo (lista vacía y nombre no encontrado) se quedan como están.

3. Receta
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

    [NUEVO] calificaciones[0] = espanol[posicion]
    [NUEVO] calificaciones[1] = matematicas[posicion]
    [NUEVO] calificaciones[2] = programas[posicion]

    reprobadas = 0
    [NUEVO] suma = 0
    [NUEVO] listaReprobadas = ""

    [CAMBIA] PARA m = 0 HASTA MATERIAS_BOLETA - 1       (antes eran tres SI separados)
    [NUEVO]      suma = suma + calificaciones[m]
    [CAMBIA]     SI calificaciones[m] < CALIFICACION_APROBATORIA ENTONCES
                     reprobadas = reprobadas + 1
    [NUEVO]          SI listaReprobadas no esta vacia ENTONCES
    [NUEVO]              listaReprobadas = listaReprobadas + ", "
    [NUEVO]          FIN SI
    [NUEVO]          listaReprobadas = listaReprobadas + NOMBRES_MATERIAS[m]
                 FIN SI
    [CAMBIA] FIN PARA

    [CAMBIA] promedio = suma / MATERIAS_BOLETA          (antes sumaba los tres arreglos)

    SI reprobadas == 0 ENTONCES estado = "Aprobado"
    SINO SI reprobadas == MATERIAS_BOLETA ENTONCES estado = "Reprobado (reprobo todas)"
    SINO estado = "Reprobado"

    imprimir boleta completa
    [NUEVO] SI reprobadas > 0 ENTONCES
    [NUEVO]     imprimir "Reprobo: ", listaReprobadas
    [NUEVO] FIN SI
FIN


