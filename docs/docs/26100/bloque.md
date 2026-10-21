## 1. Autor

**Nombre:** Regina Murillo Arellano
**Matrícula:** 26100
**Bloque y opción elegida:** Estadísticas
**Archivo de código:** estadisticas.h 

## 2. Propósito

¿Qué hace tu bloque y para qué le sirve a quien usa el programa?

El bloque de estadisticas sirve para calcular el promedio del grupo en cada materia, esto le sirve a la persona que usa el programa porque puede ver rapidamente en que materia le va mejor y en cual no, de una manera rapida sin hacer cuentas a mano, viendo al grupo completo en estos promedios. 

## 3. Entradas y salidas

¿Qué recibe tu bloque (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

Entradas: el arreglo (nombres), arreglos (calificaciones) y el total
Salidas: el titulo del reporte, el promedio de cada materia por salón (la materia más alta con su promedio y la mas baja con su promedio)

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu bloque y qué hace cada una?**

mostrarEstadisticas, hace que el reporte valide que haya alumnos, suma las calificaciones, calcula promedios e imprime resultados. 

**¿Qué ciclo usaste y por qué ese?**

for con i desde 0 a total -1; lo use porqeu es las veces que se repite por alumno registrado
for; junta lineas y condiciones 

**¿Qué acumuladores o contadores usaste y con qué valor inician?**

sumaEspanol, sumaMatematicas, sumaProgramas todos estos incian en 0, porque si se usa otro numero los promedios saldrian mal
i; el arreglo
masAlta, masBaja, promAlta, promBaja; para dar los valores de los promedios de las más alta y la más baja 

**¿Dónde está tu decisión múltiple y qué casos cubre?**

if, else; comparan los promedios de las tres materias
<=, >=; para identificar la metaria más alta o más baja en promedio


**¿Qué constantes definiste y por qué son constantes?**

TITULO_ESTADISTICAS; es constante porque nunca cambia durante la ejecución del codigo 

**¿Qué casos de rechazo maneja tu bloque y qué mensaje muestra en cada uno?**

Si alumnos = 0; rechaza ya que no puede sacar un promedio 

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
mostrarEstadisticas(nombres, espanol, matematicas, programas, total)
    constante TITULO_ESTADISTICAS "ESTADISTICAS POR MATERIA"

    SI total == 0
        MOSTRAR "No hay alumnos registrados."
        regresar

    sumaEspanol  0
    sumaMatematicas 0
    sumaProgramas  0

    PARA i DESDE 0 HASTA total-1
        sumaEspanol + espanol[i]
        sumaMatematicas + matematicas[i]
        sumaProgramas + programas[i]

    // Promedio del salón por materia
    promEspanol = sumaEspanol / total
    promMatematicas = sumaMatematicas / total
    promProgramas = sumaProgramas / total

    // Materia más alta y su promedio
    SI promEspanol >= promMatematicas Y promEspanol >= promProgramas
        masAlta = "Espanol"
        promAlta = promEspanol
    SINO SI promMatematicas >= promProgramas
        masAlta = "Matematicas"
        promAlta = promMatematicas
    SINO
        masAlta = "Diseno de Programas"
        promAlta = promProgramas

    // Materia más baja y su promedio
    SI promEspanol <= promMatematicas Y promEspanol <= promProgramas
        masBaja = "Espanol"
        promBaja = promEspanol
    SINO SI promMatematicas <= promProgramas
        masBaja = "Matematicas"
        promBaja = promMatematicas
    SINO
        masBaja = "Diseno de Programas"
        promBaja = promProgramas

    MOSTRAR TITULO_ESTADISTICAS
    MOSTRAR "Espanol:", promEspanol
    MOSTRAR "Matematicas:", promMatematicas
    MOSTRAR "Diseno de Programas:", promProgramas
    MOSTRAR "Mas alta:", masAlta, "(" promAlta ")"
    MOSTRAR "Mas baja:", masBaja, "(" promBaja ")"
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

Sí, con los 6 alumnos del escenario (Ana, Luis, Marta, Jorge, Sofia y Raul), total = 6:

Español: 9 + 7 + 6 + 8 + 10 + 5 = 45, entre 6 = 7.5
Matemáticas: 8 + 6 + 5 + 7 + 9 + 7 = 42, entre 6 = 7.0
Diseño de Programas: 10 + 8 + 7 + 9 + 8 + 6 = 48, entre 6 = 8.0

Más alta: Español (7.5) no es >= 8.0; Matemáticas (7.0) no es >= 8.0; entra al SINO: Diseño de Programas, con promedio 8.0.
Más baja: Español (7.5) no es <= 7.0; Matemáticas (7.0) <= 8.0, así que: Matemáticas, con promedio 7.0.
Resultado; Mas alta: Diseno de Programas (8), Mas baja: Matematicas (7).


## 6. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
