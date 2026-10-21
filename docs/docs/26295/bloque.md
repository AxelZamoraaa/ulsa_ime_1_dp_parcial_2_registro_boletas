## 1. Autor

**Nombre:** Sergio Axel Zamora Coronado
**Matrícula:** 26295
**Bloque y opción elegida:** captura
**Archivo de código:** Capturas.h

## 2. Propósito

¿Qué hace tu bloque y para qué le sirve a quien usa el programa?

Mi bloque que escaptura.h se encarga de registrar a un alumno nuevo en el sistema, le pide al usuario el nombre y las calificaciones de Español, Matemáticas y Diseño de Programas, y no deja pasar datos inválidos, vuelve a preguntar hasta que el dato es correcto. Después manda todo a agregarAlumno para guardarlo en los arreglos.
sirve para que el resto del programa (estadísticas, aprobados, boleta, reprobados) trabaje siempre con datos limpios.

## 3. Entradas y salidas

¿Qué recibe tu bloque (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

Entradas:

Parámetros de capturarAlumno: los arreglos nombres, español, matematicas, programas y el entero total (cuántos alumnos hay registrados)
Parámetro de pedirCalificacion: el nombre de la materia, que solo se usa para mostrar la pregunta
Datos del teclado: el nombre del alumno (texto) y tres calificaciones (decimales)

Salidas:

Lo que imprime: los mensajes de error El nombre no puede quedar vacio, etc,  el aviso de lista llena y la confirmación “Alumno N registrado.”
Lo que devuelve: pedirNombre devuelve el nombre string, pedirCalificacion devuelve la calificación válida double y capturarAlumno devuelve el nuevo total de alumnos

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu bloque y qué hace cada una?**

pedirCalificacion(materia): pide una calificación de la materia indicada, la valida y repite hasta que sea correcta. Devuelve el valor válido.
pedirNombre: pide el nombre y repite mientras se deje vacío. Devuelve el nombre.
capturarAlumno coordina todo. Revisa que haya espacio, pide nombre y las tres calificaciones, llama a agregarAlumno y devuelve el total actualizado

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
[Inserta aquí tu respuesta]
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Inserta aquí tu respuesta]

## 6. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
