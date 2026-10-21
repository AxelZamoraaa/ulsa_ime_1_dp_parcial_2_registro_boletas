# Proyecto Parcial 2: Sistema de Registro y Boletas de un Grupo Escolar

> **Importante:** este README es del equipo y debe tener aportaciones de todos los integrantes. La guía completa está en [`PROYECTO.md`](PROYECTO.md).

## 1. Integrantes

| Bloque | Matrícula | Nombre | Usuario de GitHub | Opción elegida |
| --- | --- | --- | --- | --- |
| 1 |  26295 | [Sergio Axel Zamora Coronado] | [AxelZamoraaa] | Captura |
| 2 | 26100 | Regina Murillo Arellano | reginamurilloa | Estadisticas |
| 3 | 26141 | Alan Rodrigo Guardiola Martinez | [Inserta aquí tu respuesta] | Aprobados y reprobados |
| 4 | 26076 | Erick Aguilar Martinez | Erick1867 | Boleta individual |
| 5 | 26165 | Pablo Mussa | Pablomussa | Materias reprobadas |
| 6 | 26102 | Emiliano Ferrer de la Cruz | [Inserta aquí tu respuesta] | Integracion (main.cpp) |



## 2. Opciones del menú

Escriban las opciones del menú en el orden en que aparecen en el programa.

1. Capturar alumno
2. Mostrar lista
3. Estadisticas por materia
4. Aprobados y reprobados
5. Boleta individual
6. Materias reprobadas por alumno
7. Salir

## 3. Cómo compilar y ejecutar

Desde la carpeta del proyecto:

```
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o boletas
./boletas
```

## 4. Reglas del programa

Escriban las reglas que su programa sigue y que el cálculo a mano necesita. Por ejemplo: qué pasa cuando hay un empate, cómo se busca un nombre, con cuántos decimales se imprime.

1.- Cada calificación es un número de 0 a 10, con decimales. El nombre no puede quedar vacío. Si el dato es inválido, se vuelve a pedir

2.- 2.- El promedio de cada materia es la suma de sus calificaciones entre el total de alumnos registrados. Si no hay alumnos registrados, el reporte muestra "No hay alumnos registrados." y regresa al menú.

3.- Una materia se aprueba con 7.0 o más. En aprobados, el empate de "materia con más reprobados" se resuelve igual que en estadísticas.

4.- El promedio es la suma de las tres calificaciones entre 3, un alumno está aprobado solo si aprueba las tres, la búsqueda de nombre en la boleta es exacta y distingue mayúsculas de minúsculas

5.- Los decimales se imprimen con un dígito (por ejemplo, 9.0). Ningún reporte funciona con la lista vacía: avisa y regresa al menú. El reporte de reprobadas solo lista a quienes reprueban al menos una materia

## 5. Datos del escenario

Los 6 alumnos que capturan en el escenario obligatorio.

| # | Nombre | Español | Matemáticas | Diseño de Programas |
| --- | --- | --- | --- | --- |
| 1 | Ana | 9.0 | 8.0 | 10.0 |
| 2 | Luis | 7.0 | 6.0 | 8.0 |
| 3 | Marta | 6.0 | 5.0 | 7.0 |
| 4 | Jorge | 8.0 | 7.0 | 9.0 |
| 5 | Sofia | 10.0 | 9.0 | 8.0 |
| 6 | Raul | 5.0 | 7.0 | 6.0 |

## 6. Cálculo a mano

Predigan la salida del escenario antes de ejecutarlo. Una fila por bloque individual. Lo que imprime el programa debe coincidir.

| Bloque | Valores elegidos | Resultado esperado |
| --- | --- | --- |
| 1 | 6 alumnos, un intento con 11 en español y un séptimo intento | 6 registrados, 1 rechazado por calificación y 1 aviso de lista llena |
| 2 | 6 alumnos del escenario: sumas 45.0, 42.0 y 48.0 entre 6| Espanol: 7.5, Matematicas: 7.0, Diseno de Programas: 8.0, Mas alta: Diseno de Programas 8.0, Mas baja: Matematicas 7.0 |
| 3 | Mínimo para aprobar 7.0 |  Español 4 y 2, Matemáticas 4 y 2, Diseño de Programas 5 y 1; materia con más reprobados: Español |
| 3 | Calificación mínima aprobatoria: 7.0 | Español: 4 aprobados y 2 reprobados; Matemáticas: 4 y 2; Diseño de Programas: 5 y 1. Más reprobados: Español (empate con Matemáticas, se prioriza Español). |
| 4 | Buscar Marta y Hugo  | Marta: promedio 6.0, 2 materias reprobadas, Reprobado. Hugo: no encontrado |
| 5 | Calificaciones menores a 7.0 | Luis 1, Marta 2, Raul 2; total 3 alumnos |
| 6 | Elegir una opción inexistente y después salir | Muestra "Opcion invalida." y luego "Hasta luego." |

<!-- Si el equipo es de seis integrantes, agreguen una fila para el bloque 6. -->

**¿La salida del programa coincidió con el cálculo a mano? Si no, ¿qué corrigieron?**

si

## 7. Receta del menú

Receta en pseudocódigo del programa principal: el menú y cómo se conecta con cada bloque.

```
INICIO
  declarar arreglos nombres, espanol, matematicas, programas (tamano MAX_ALUMNOS)
  total = 0
  REPETIR
    mostrar el menu de 7 opciones
    opcion = leerEntero("Opcion: ")
    SEGUN opcion
      1: total = capturarAlumno(arreglos, total)
      2: mostrarLista(arreglos, total)
      3: mostrarEstadisticas(arreglos, total)
      4: mostrarAprobados(arreglos, total)
      5: mostrarBoleta(arreglos, total)
      6: mostrarReprobadas(arreglos, total)
      7: mostrar "Hasta luego."
      otro caso: mostrar "Opcion invalida."
  MIENTRAS opcion sea distinta de 7
FIN



## 8. Documentación individual 


Enlace a la documentación y a la propuesta de mejora de cada integrante.

| Bloque | Documentación | Propuesta de mejora |
| --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [docs/26100/bloque.md] | [Inserta aquí tu respuesta] |
| 3 | [docs/26141/bloque.md] | [mejoras/26141/mejora.md] |
| 4 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 5 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 6 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 1 Axel | [docs/26295/bloque.md] | [docs/mejoras/26295/mejora.md] |
| 2 Regina| [docs/26100/bloque.md] | [docs/mejoras/26100/mejora.md] |
| 3 Alan| [docs/26141/bloque.md] | [docs/mejoras/26141/mejora.md] |
| 4 Erick| [docs/26076/bloque.md] | [docs/mejoras/26076/mejora.md] |
| 5 Pablo| [docs/26165/bloque.md] | [docs/mejoras/26165/mejora.md] |
| 6 Ferrer| [docs/26102/bloque.md] | [docs/mejoras/26102/mejora.md] |

## 9. Cambios a la interfaz

Si cambiaron algo de la interfaz de `include/registro.h` (una constante, un parámetro, una función), expliquen qué cambiaron y por qué. Si no cambiaron nada, escriban "Sin cambios".

sin cambios
