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

[Inserta aquí tu respuesta]

**¿Qué ciclo usaste y por qué ese?**

[Inserta aquí tu respuesta]

**¿Qué acumuladores o contadores usaste y con qué valor inician?**

[Inserta aquí tu respuesta]

**¿Dónde está tu decisión múltiple y qué casos cubre?**

[Inserta aquí tu respuesta]

**¿Qué constantes definiste y por qué son constantes?**

[Inserta aquí tu respuesta]

**¿Qué casos de rechazo maneja tu bloque y qué mensaje muestra en cada uno?**

[Inserta aquí tu respuesta]

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
mostrarEstadisticas(nombres, espanol, matematicas, programas, total)
    constante TITULO_ESTADISTICAS ← "ESTADISTICAS POR MATERIA"

    SI total == 0
        MOSTRAR "No hay alumnos registrados."
        regresar

    sumaEspanol ← 0
    sumaMatematicas ← 0
    sumaProgramas ← 0

    PARA i DESDE 0 HASTA total-1
        sumaEspanol ← sumaEspanol + espanol[i]
        sumaMatematicas ← sumaMatematicas + matematicas[i]
        sumaProgramas ← sumaProgramas + programas[i]

    // Promedio del salón por materia
    promEspanol ← sumaEspanol / total
    promMatematicas ← sumaMatematicas / total
    promProgramas ← sumaProgramas / total

    // Materia más alta y su promedio
    SI promEspanol >= promMatematicas Y promEspanol >= promProgramas
        masAlta ← "Espanol"
        promAlta ← promEspanol
    SINO SI promMatematicas >= promProgramas
        masAlta ← "Matematicas"
        promAlta ← promMatematicas
    SINO
        masAlta ← "Diseno de Programas"
        promAlta ← promProgramas

    // Materia más baja y su promedio
    SI promEspanol <= promMatematicas Y promEspanol <= promProgramas
        masBaja ← "Espanol"
        promBaja ← promEspanol
    SINO SI promMatematicas <= promProgramas
        masBaja ← "Matematicas"
        promBaja ← promMatematicas
    SINO
        masBaja ← "Diseno de Programas"
        promBaja ← promProgramas

    MOSTRAR TITULO_ESTADISTICAS
    MOSTRAR "Espanol:", promEspanol
    MOSTRAR "Matematicas:", promMatematicas
    MOSTRAR "Diseno de Programas:", promProgramas
    MOSTRAR "Mas alta:", masAlta, "(" promAlta ")"
    MOSTRAR "Mas baja:", masBaja, "(" promBaja ")"
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Inserta aquí tu respuesta]

## 6. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
