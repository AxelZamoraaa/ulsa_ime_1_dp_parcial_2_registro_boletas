# Proyecto Parcial 2: Sistema de Registro y Boletas de un Grupo Escolar

> **Importante:** este README es del equipo y debe tener aportaciones de todos los integrantes. La guía completa está en [`PROYECTO.md`](PROYECTO.md).

## 1. Integrantes

| Bloque | Matrícula | Nombre | Usuario de GitHub | Opción elegida |
| --- | --- | --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | Captura |
| 2 | 26100 | Regina Murillo Arellano | reginamurilloa | Estadisticas |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 4 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 5 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

<!-- Si el equipo es de seis integrantes, agreguen una fila para el bloque 6. -->

## 2. Opciones del menú

Escriban las opciones del menú en el orden en que aparecen en el programa.

[Inserta aquí tu respuesta]

## 3. Cómo compilar y ejecutar

Desde la carpeta del proyecto:

```
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o boletas
./boletas
```

## 4. Reglas del programa

Escriban las reglas que su programa sigue y que el cálculo a mano necesita. Por ejemplo: qué pasa cuando hay un empate, cómo se busca un nombre, con cuántos decimales se imprime.

[Inserta aquí tu respuesta]

## 5. Datos del escenario

Los 6 alumnos que capturan en el escenario obligatorio.

| # | Nombre | Español | Matemáticas | Diseño de Programas |
| --- | --- | --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 4 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 5 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 6 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

## 6. Cálculo a mano

Predigan la salida del escenario antes de ejecutarlo. Una fila por bloque individual. Lo que imprime el programa debe coincidir.

| Bloque | Valores elegidos | Resultado esperado |
| --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 4 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 5 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

<!-- Si el equipo es de seis integrantes, agreguen una fila para el bloque 6. -->

**¿La salida del programa coincidió con el cálculo a mano? Si no, ¿qué corrigieron?**

[Inserta aquí tu respuesta]

## 7. Receta del menú

Receta en pseudocódigo del programa principal: el menú y cómo se conecta con cada bloque.

```
INICIO
    nombres[6], esp[6], mat[6], dp[6]
    total ← 0

    REPETIR
        MOSTRAR menú:
            1. Capturar alumno
            2. Mostrar lista
            3. Promedio por alumno
            4. Aprobados/reprobados
            5. Salir
            OTRO: "Opción no válida"

CAPTURAR
    SI total == 6 → "Lista llena", regresar
    REPETIR nom ← leerCadena() HASTA QUE nom no esté vacío
    esp[total] ← pedirCal("Español")
    mat[total] ← pedirCal("Matemáticas")
    dp[total]  ← pedirCal("Diseño de Programas")
    total ← total + 1

PEDIRCAL(materia)
    REPETIR
        cal ← leerDecimal()
        SI cal < 0 O cal > 10 → "Calificación inválida"
    HASTA QUE cal esté entre 0 y 10
    REGRESAR cal

MOSTRAR LISTA
    SI total == 0 → "Lista vacía", regresar
    PARA i DESDE 0 HASTA total-1
        MOSTRAR nombres[i], esp[i], mat[i], dp[i]

PROMEDIOS
    SI total == 0 → "Lista vacía", regresar
    PARA i DESDE 0 HASTA total-1
        MOSTRAR nombres[i], (esp[i] + mat[i] + dp[i]) / 3

APROBADOS
    SI total == 0 → "Lista vacía", regresar
    PARA i DESDE 0 HASTA total-1
        SI esp[i] >= 7 Y mat[i] >= 7 Y dp[i] >= 7
            MOSTRAR nombres[i], "APROBADO"
        SINO
            MOSTRAR nombres[i], "REPROBADO"
```

## 8. Documentación individual

Enlace a la documentación y a la propuesta de mejora de cada integrante.

| Bloque | Documentación | Propuesta de mejora |
| --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 4 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 5 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

<!-- Si el equipo es de seis integrantes, agreguen una fila para el bloque 6. -->

## 9. Cambios a la interfaz

Si cambiaron algo de la interfaz de `include/registro.h` (una constante, un parámetro, una función), expliquen qué cambiaron y por qué. Si no cambiaron nada, escriban "Sin cambios".

[Inserta aquí tu respuesta]
