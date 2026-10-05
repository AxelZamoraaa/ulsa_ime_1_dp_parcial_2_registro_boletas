# Proyecto Parcial 2: Sistema de Registro y Boletas de un Grupo Escolar

**Materia:** Diseño de Programas (C++)
**Alcance:** Unidades I a V, arreglos y funciones simples
**Repositorio base:** https://github.com/narizwallace/ulsa_ime_1_dp_parcial_2_registro_boletas
**Entrega:** martes 20 de octubre, 11:59 PM, en Classroom
**Exposición:** miércoles 21 de octubre

## 1. Objetivo

Construir en equipo un programa que registra a los alumnos de un grupo y genera reportes sobre sus calificaciones. Cada integrante diseña, programa, documenta y expone un bloque propio, y el equipo completo responde por la solución integrada.

## 2. El problema

### 2.1 Lo que hace el programa

El programa guarda hasta 6 alumnos. De cada uno guarda su nombre y su calificación en tres materias: Español, Matemáticas y Diseño de Programas.

Los datos viven en **cuatro arreglos paralelos**: uno de nombres y uno de calificaciones por materia. El mismo índice corresponde al mismo alumno en los cuatro.

Reglas:

- Cada calificación es un número de 0 a 10, con decimales.
- Una materia se aprueba con 7.0 o más.
- El promedio de un alumno es la suma de sus tres calificaciones entre 3.
- Un alumno está aprobado solo si aprueba las tres materias.
- El nombre no puede quedar vacío.
- Ningún reporte funciona con la lista vacía: avisa y regresa al menú.
- Toda entrada por teclado se lee con `leerEntero`, `leerDecimal` o `leerCadena`.
- No se usan variables globales.

### 2.2 Lo que agrega cada bloque

Cada integrante agrega una opción al menú. Un integrante toma la captura; los demás eligen opciones distintas de este catálogo.

| Opción | Qué hace | Qué la distingue |
| --- | --- | --- |
| Captura (obligatoria) | Pide el nombre y las tres calificaciones y los guarda | Vuelve a pedir cada dato mientras sea inválido |
| Estadísticas por materia | Promedio del grupo en cada materia, y la materia más alta y la más baja | Tres acumuladores y una comparación |
| Aprobados y reprobados | Cuenta aprobados y reprobados en cada materia | Contadores por materia |
| Boleta individual | Busca a un alumno y muestra calificaciones, promedio y estado | Búsqueda y caso "no encontrado" |
| Materias reprobadas por alumno | Lista a quienes reprueban al menos una materia y cuántas | Contador por alumno |
| Mejor y peor desempeño | Alumno con el promedio más alto y el más bajo | Comparación de extremos y regla de empate |
| Cuadro de honor | Lista a quienes tienen un promedio sobre un umbral | Filtro con una constante de umbral |
| Distribución por rangos | Cuenta cuántos promedios caen en cada rango | Varios contadores |
| Consulta por materia | Pide una materia y muestra la calificación de cada alumno en ella, con el promedio de la materia | Selección de arreglo con decisión múltiple |

El equipo puede proponer otra opción, siempre que cumpla el contrato mínimo de la sección 3.2.

### 2.3 Integración

El programa principal muestra un menú que se repite hasta elegir "Salir". Tiene una opción por bloque individual, más "Mostrar lista" y "Salir". Si el usuario teclea una opción que no existe, avisa y vuelve a mostrar el menú.

### 2.4 Escenario obligatorio

En la exposición, el equipo ejecuta estos pasos en orden:

1. Elegir un reporte con la lista vacía (rechazo).
2. Capturar 6 alumnos. En uno de ellos, teclear primero una calificación fuera de rango (rechazo).
3. Intentar capturar un alumno más (rechazo por lista llena).
4. Mostrar la lista.
5. Ejecutar cada reporte del equipo.
6. Provocar el rechazo propio de al menos un reporte.
7. Teclear una opción de menú que no existe (rechazo).
8. Salir.

### 2.5 Ejemplo de salida

Este ejemplo es ilustrativo: cada equipo usa sus propios alumnos, calificaciones y reportes. Corresponde a un equipo de cinco que eligió estadísticas por materia, aprobados y reprobados, boleta individual y materias reprobadas por alumno. Se muestran fragmentos.

```
1. Capturar alumno
2. Mostrar lista
3. Estadisticas por materia
4. Aprobados y reprobados
5. Boleta individual
6. Materias reprobadas por alumno
7. Salir
Opcion: 3
No hay alumnos registrados.

Opcion: 1
Nombre: Ana
Espanol: 11
Calificacion invalida. Debe estar entre 0 y 10.
Espanol: 9
Matematicas: 8
Diseno de Programas: 10
Alumno 1 registrado.
...
Opcion: 1
La lista esta llena (6 alumnos).

Opcion: 2
--- LISTA DEL GRUPO ---
   Nombre   Esp    Mat    DP
1. Ana      9.0    8.0   10.0
2. Luis     7.0    6.0    8.0
3. Marta    6.0    5.0    7.0
4. Jorge    8.0    7.0    9.0
5. Sofia   10.0    9.0    8.0
6. Raul     5.0    7.0    6.0

Opcion: 3
--- ESTADISTICAS POR MATERIA ---
Espanol: 7.5
Matematicas: 7.0
Diseno de Programas: 8.0
Mas alta: Diseno de Programas
Mas baja: Matematicas

Opcion: 4
--- APROBADOS Y REPROBADOS ---
Espanol: 4 aprobados, 2 reprobados
Matematicas: 4 aprobados, 2 reprobados
Diseno de Programas: 5 aprobados, 1 reprobado

Opcion: 5
Nombre a buscar: Marta
--- BOLETA ---
Alumno: Marta
Espanol: 6.0   Matematicas: 5.0   Diseno de Programas: 7.0
Promedio: 6.0   Materias reprobadas: 2   Estado: Reprobado

Opcion: 5
Nombre a buscar: Hugo
No se encontro al alumno Hugo.

Opcion: 6
--- MATERIAS REPROBADAS POR ALUMNO ---
Luis   1
Marta  2
Raul   2
Alumnos con materias reprobadas: 3

Opcion: 9
Opcion invalida.

Opcion: 7
Hasta luego.
```

Los textos que imprime el programa van sin acentos ni "ñ", para evitar problemas de codificación en la terminal.

## 3. Bloques y responsables

### 3.1 Tabla de bloques

| Bloque | Responsable | Contenido |
| --- | --- | --- |
| 0 | Equipo | Implementar la base común a partir de `include/registro.h` |
| 1 | Un integrante | Captura |
| 2 a 5 | Un integrante por bloque | Un reporte del catálogo |
| 6 | Equipo | Menú e integración en `src/main.cpp` |

> **Importante:** un equipo de seis integrantes tiene un reporte más. Sus bloques individuales son del 1 al 6 y la integración es el bloque 7.

### 3.2 Contrato mínimo del bloque individual

Tu bloque debe cumplir todo lo siguiente. Cómo lo cumples es decisión tuya, y debes poder justificarla.

1. Vive en un archivo `.h` propio dentro de `include`, que solo tú modificas.
2. Tu archivo inicia con `#pragma once`.
3. Tiene al menos una función propia, que recibe los cuatro arreglos como parámetros.
4. Usa al menos un ciclo.
5. Usa al menos un acumulador o un contador.
6. Tiene al menos una decisión múltiple.
7. Define al menos una constante propia.
8. Maneja al menos un caso de rechazo, con un mensaje claro.
9. Tiene su receta en pseudocódigo, escrita por ti antes de programar.

### 3.3 Bloques de equipo

- **Base común (bloque 0):** el equipo implementa las funciones declaradas en `include/registro.h`.
- **Integración (último bloque):** el equipo escribe el menú en `src/main.cpp` y conecta todos los bloques.

Los archivos de equipo deben tener aportaciones de todos los integrantes.

## 4. Entregables

| Entregable | Responsable | Ubicación |
| --- | --- | --- |
| Base común | Equipo | `include/registro.h` |
| Menú e integración | Equipo | `src/main.cpp` |
| README del equipo | Equipo | `README.md` |
| Código del bloque | Cada integrante | Archivo `.h` propio en `include` |
| Documentación y receta | Cada integrante | `docs/<matrícula>/bloque.md` |
| Propuesta de mejora | Cada integrante | `docs/mejoras/<matrícula>/mejora.md` |

### 4.1 Documentación individual

Copia `docs/PLANTILLA_BLOQUE.md` a `docs/<matrícula>/bloque.md` y llénala: autor, propósito del bloque, decisiones de diseño, receta y bitácora de dudas y errores. No modifiques la plantilla original.

### 4.2 Propuesta de mejora

Cada integrante propone una mejora o una corrección a la solución del equipo. Es solo diseño: no se programa.

- Copia `docs/mejoras/PLANTILLA_MEJORA.md` a `docs/mejoras/<matrícula>/mejora.md`. No modifiques la plantilla original.
- Inicia con la etiqueta "Propuesta de mejora elaborada por: " y tu nombre.
- Contenido mínimo: el impacto (como mejora o como corrección), qué cambia en el diseño con cada cambio justificado, y una receta que distingue los pasos nuevos de los existentes.
- Puede tocar cualquier parte de la solución y se resuelve con los temas del parcial.
- Dentro de un equipo no puede haber dos propuestas iguales.

### 4.3 Cálculo a mano

Antes de ejecutar el escenario, el equipo predice la salida en una tabla del README, con una fila por bloque. Lo que imprime el programa debe coincidir. Si el cálculo necesita una regla (por ejemplo, qué pasa en un empate), el equipo la deja por escrito.

Ejemplo, con los mismos datos de la sección 2.5:

| Bloque | Valores elegidos | Resultado esperado |
| --- | --- | --- |
| Captura | 6 alumnos, un intento con 11 | 6 registrados, 1 rechazo, 1 aviso de lista llena |
| Estadísticas por materia | Sumas 45.0, 42.0 y 48.0 entre 6 | 7.5, 7.0 y 8.0; más alta Diseño de Programas, más baja Matemáticas |
| Aprobados y reprobados | Mínimo 7.0 | 4 y 2, 4 y 2, 5 y 1 |
| Boleta individual | Buscar Marta y Hugo | Marta: promedio 6.0, 2 materias reprobadas, Reprobado; Hugo no encontrado |
| Materias reprobadas por alumno | Calificaciones menores a 7.0 | Luis 1, Marta 2, Raul 2; total 3 alumnos |

## 5. Repositorio base

Enlace: https://github.com/narizwallace/ulsa_ime_1_dp_parcial_2_registro_boletas

Un solo integrante del equipo hace fork del repositorio base. Es un punto de partida: los archivos de los bloques individuales los crea cada responsable.

| Archivo | Contenido |
| --- | --- |
| `PROYECTO.md` | Esta guía |
| `README.md` | Plantilla del equipo |
| `include/registro.h` | Interfaz de la base común: solo declaraciones, comentadas |
| `include/utilerias.h` | `leerEntero`, `leerDecimal` y `leerCadena`, ya implementadas |
| `src/main.cpp` | Esqueleto que compila, con los pasos del escenario como comentarios |
| `docs/PLANTILLA_BLOQUE.md` | Plantilla de la documentación individual |
| `docs/mejoras/PLANTILLA_MEJORA.md` | Plantilla de la propuesta de mejora |
| `.gitignore` | Ignora el ejecutable y archivos del sistema |
| `.vscode/` | Configuración del editor |

Todos los archivos `.h` van en la carpeta `include` y contienen sus funciones completas, igual que `utilerias.h`. La carpeta `src` contiene solo `main.cpp`. Para incluir un archivo se escribe solo su nombre:

```cpp
#include "registro.h"
```

La interfaz define las constantes compartidas (`MAX_ALUMNOS`, `CALIFICACION_MINIMA`, `CALIFICACION_MAXIMA` y `CALIFICACION_APROBATORIA`) y declara tres funciones, cada una con una sola tarea:

- `calificacionValida`: dice si una calificación está entre 0 y 10.
- `agregarAlumno`: guarda el nombre y las tres calificaciones, y devuelve el nuevo total de alumnos. Si la lista está llena, no guarda nada y devuelve el mismo total.
- `mostrarLista`: imprime la lista numerada con las tres calificaciones.

El equipo escribe la implementación en el mismo `include/registro.h`, debajo de las declaraciones. Si cambian la interfaz, lo anotan en el README.

Para compilar y ejecutar, desde la carpeta del proyecto:

```
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o boletas
./boletas
```

## 6. Colaboración en GitHub

- Quien hizo el fork invita a los demás como colaboradores, y todos trabajan en ese repositorio.
- Cada quien hace commits desde su propia cuenta, con nombre y correo configurados.
- Los archivos de un bloque individual solo los modifica su responsable.
- La autoría se revisa con git-fame.

> **Importante:** un bloque sin commits de su responsable no recibe la calificación individual.

## 7. Entrega

- Fecha límite: martes 20 de octubre, 11:59 PM.
- Cada integrante entrega en Classroom, de forma individual, el enlace al repositorio del equipo.
- Los commits posteriores a la fecha límite no cuentan. No se aceptan entregas a destiempo.

> **Importante:** quien no entregue su enlace a tiempo pierde 10 puntos de su evaluación individual.

## 8. Exposición

- Cada integrante presenta su bloque funcionando dentro del escenario.
- Cada integrante responde una pregunta sobre el bloque de un compañero.
- Cada integrante cierra con su propuesta de mejora.
- El equipo ejecuta el escenario completo y explica el resultado contra su cálculo a mano.

## 9. Evaluación

| Individual (60) | Puntos | Equipo (40) | Puntos |
| --- | --- | --- | --- |
| Código de su bloque | 30 | Integración: escenario completo y correcto | 25 |
| Documentación y receta | 10 | README y receta del menú | 10 |
| Propuesta de mejora | 10 | Cálculo a mano que coincide con la salida | 5 |
| Exposición | 10 | | |

## 10. Criterios de aceptación

- [ ] El programa compila sin advertencias con `g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o boletas`.
- [ ] El escenario obligatorio se ejecuta completo, con todos sus rechazos.
- [ ] La salida coincide con el cálculo a mano del README.
- [ ] Cada bloque individual cumple los 9 puntos del contrato.
- [ ] No hay variables globales.
- [ ] Cada integrante tiene commits en su bloque y en los archivos de equipo.
- [ ] Están la documentación y la propuesta de mejora de cada integrante.
- [ ] El README está completo.
- [ ] Cada integrante entregó el enlace en Classroom.
