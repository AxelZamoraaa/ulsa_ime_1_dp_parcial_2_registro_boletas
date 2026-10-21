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

Usé do while en pedirCalificacion y en pedirNombre, se necesita pedir el dato por lo menos una vez antes de poder validarlo y eso es justo lo que garantiza el do while (el while normal evalúa la condición antes de entrar, cuando todavía no hay dato que revisar). El ciclo se repite mientras el dato sea inválido, sin límite fijo de intentos, porque no sé cuántas veces se va a equivocar el usuario

**¿Qué acumuladores o contadores usaste y con qué valor inician?**

El de total (contador de alumnos): no se inicia en mi bloque, llega como parámetro con los alumnos ya registrados (empieza en 0 desde main) y sube en 1 cada vez que se registra uno, a través de agregarAlumno.
valida (bandera booleana en pedirCalificacion): inicia en false y cambia a true cuando la calificación pasa la validación, lo que rompe el ciclo

**¿Dónde está tu decisión múltiple y qué casos cubre?**

En pedirCalificacion, con un if, else if , else:

Si calificacionValida(calificacion)  es válida, se acepta
Si calificacion < CALIFICACION_MINIMA es negativa, se rechaza
En cualquier otro caso → es mayor al máximo, se rechaza

Usé if/else if y no switch porque las condiciones son rangos de valores decimales, y el switch solo funciona con valores exactos

**¿Qué constantes definiste y por qué son constantes?**

MENSAJE_LISTA_LLENA: es el texto del aviso de lista llena, es constante para que el mensaje esté en un solo lugar y no se escriba distinto en varios sitios.
MAX_ALUMNOS y CALIFICACION_MINIMA : son reglas del sistema que no deben cambiar mientras corre el programa, si el límite cambia, se modifica en un solo lugar

**¿Qué casos de rechazo maneja tu bloque y qué mensaje muestra en cada uno?**

Nombre vacío: El nombre no puede quedar vacio.
Calificación negativa: La calificacion no puede ser negativa.
Calificación mayor a 10: La calificacion no puede ser mayor a 10.
Lista llena: lista esta llena MAX_ALUMNOS alumnos no captura nada y devuelve el mismo total

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
FUNCION pedirNombre()
    REPETIR
        nombre ← leer("Nombre: ")
        SI nombre es vacío ENTONCES
            mostrar "El nombre no puede quedar vacio."
    MIENTRAS nombre sea vacío
    DEVOLVER nombre

FUNCION pedirCalificacion(materia)
    valida ← falso
    REPETIR
        calificacion ← leer(materia + ": ")
        SI calificacion es válida ENTONCES
            valida ← verdadero
        SINO SI calificacion < CALIFICACION_MINIMA ENTONCES
            mostrar "La calificacion no puede ser negativa."
        SINO
            mostrar "La calificacion no puede ser mayor a 10."
    MIENTRAS valida sea falso
    DEVOLVER calificacion

FUNCION capturarAlumno(arreglos, total)
    SI total >= MAX_ALUMNOS ENTONCES
        mostrar MENSAJE_LISTA_LLENA
        DEVOLVER total
    nombre ← pedirNombre()
    calEspanol ← pedirCalificacion("Espanol")
    calMatematicas ← pedirCalificacion("Matematicas")
    calProgramas ← pedirCalificacion("Diseno de Programas")
    total ← agregarAlumno(arreglos, total, nombre, calEspanol, calMatematicas, calProgramas)
    mostrar "Alumno " + total + " registrado."
    DEVOLVER total
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Inserta aquí tu respuesta]

## 6. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | Al principio no sabía si usar while o do while para validar| Vi que el dato se debe pedir al menos una vez antes de revisarlo, así que usé do while |
| 2 | Un solo mensaje de error para cualquier calificación inválida no le decía al usuario qué había hecho mal | Separé los casos con else if para mostrar un mensaje distinto si es negativa o mayor a 10 |
| 3 | La lista podía llenarse y el programa seguía pidiendo datos que luego no cabían | Agregué al inicio de capturarAlumno la revisión de total >= MAX_ALUMNOS, que avisa y devuelve el total sin cambios |
