# Propuesta de mejora

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/mejoras/<matrícula>/mejora.md (por ejemplo, docs/mejoras/123456/mejora.md)
y llena tu copia.

La propuesta es solo diseño: no se programa.
Puede tocar cualquier parte de la solución del equipo y se resuelve con los temas del parcial.
Dentro de un equipo no puede haber dos propuestas iguales.
-->

Propuesta de mejora elaborada por: [Erick Aguilar]

**Matrícula:** [26076]
**Título de la propuesta:** [Ranking de alumnos ordenado por promedio]

1. Impacto

Es una mejora. Ahorita el programa te deja ver la lista de alumnos en el orden en que se capturaron, y las estadísticas por materia dan promedios del grupo, pero no hay forma de saber quién es el mejor alumno o quién va hasta abajo sin sacar las cuentas uno mismo. Con esto se agrega una opción “Ranking por promedio” que muestra a todos ordenados del promedio más alto al más bajo.

Le sirve al maestro para ver rápido a quién felicitar y a quién darle seguimiento. No se parece al análisis general de Pablo porque ese junta datos del grupo completo, y esto ordena alumno por alumno. Tampoco toca la opción 6, que solo dice qué materias reprobó cada uno.

2. Qué implica en el diseño
Menú: se agrega la opción 7 “Ranking por promedio” y “Salir” pasa a ser la 8. Hay que mover también el límite de la validación de la opción.
Función nueva calcularPromedios: recibe los tres arreglos de calificaciones y total, y llena un arreglo promedios con el promedio de cada alumno. Está aparte para no repetir la cuenta que ya hace mostrarBoleta.
Función nueva mostrarRanking: arma el ranking e imprime. No ordena los arreglos originales, porque si los movemos se descompone la relación entre nombres y calificaciones (la posición de cada alumno es la misma en los cuatro arreglos). En vez de eso crea un arreglo orden con los índices 0, 1, 2... y es ese el que se acomoda.
Arreglos locales promedios[MAX_ALUMNOS] y orden[MAX_ALUMNOS]: el primero guarda los promedios y el segundo la posición de cada alumno en el ranking. MAX_ALUMNOS es la constante del tamaño de los arreglos; si en registro.h se llama distinto, uso ese nombre.
Ciclos anidados (burbuja): un for por fuera que repite las pasadas y uno por dentro que compara vecinos. Usé for porque se sabe cuántas vueltas son (depende de total). Si el promedio del de abajo es mayor que el del de arriba, se intercambian en orden. La comparación es estricta (<), así que en un empate se queda primero el que se capturó antes.
Variable auxiliar: guarda un índice mientras se hace el intercambio.
Constante MATERIAS_BOLETA: ya existe y se usa para dividir en calcularPromedios.
Casos de rechazo: si total == 0 imprime “No hay alumnos registrados.” y sale. Con un solo alumno no se rechaza, el ranking sale con una línea nomás.
3. Receta
INICIO menu principal
    repetir
        imprimir opciones 1 a 6                         (sin cambios)
        [NUEVO] imprimir "7. Ranking por promedio"
        [CAMBIA] imprimir "8. Salir"                    (antes era la 7)
        leer opcion
        [CAMBIA] SEGUN opcion                           (ahora llega hasta 8)
            casos 1 a 6: igual que antes
            [NUEVO] caso 7: mostrarRanking(nombres, espanol, matematicas, programas, total)
            [CAMBIA] caso 8: salir
    hasta que opcion == 8                               (antes 7)
FIN

[NUEVO] FUNCION calcularPromedios(espanol, matematicas, programas, total, promedios)
[NUEVO]     PARA i = 0 HASTA total - 1
[NUEVO]         promedios[i] = (espanol[i] + matematicas[i] + programas[i]) / MATERIAS_BOLETA
[NUEVO]     FIN PARA
[NUEVO] FIN FUNCION

[NUEVO] FUNCION mostrarRanking(nombres, espanol, matematicas, programas, total)
[NUEVO]     SI total == 0 ENTONCES
[NUEVO]         imprimir "No hay alumnos registrados."
[NUEVO]         TERMINAR
[NUEVO]     FIN SI
[NUEVO]     calcularPromedios(espanol, matematicas, programas, total, promedios)
[NUEVO]     PARA i = 0 HASTA total - 1
[NUEVO]         orden[i] = i
[NUEVO]     FIN PARA
[NUEVO]     PARA pasada = 0 HASTA total - 2
[NUEVO]         PARA j = 0 HASTA total - 2 - pasada
[NUEVO]             SI promedios[orden[j]] < promedios[orden[j + 1]] ENTONCES
[NUEVO]                 auxiliar = orden[j]
[NUEVO]                 orden[j] = orden[j + 1]
[NUEVO]                 orden[j + 1] = auxiliar
[NUEVO]             FIN SI
[NUEVO]         FIN PARA
[NUEVO]     FIN PARA
[NUEVO]     imprimir "--- RANKING ---"
[NUEVO]     PARA lugar = 0 HASTA total - 1
[NUEVO]         imprimir lugar + 1, nombres[orden[lugar]], promedios[orden[lugar]]
[NUEVO]     FIN PARA
[NUEVO] FIN FUNCION

