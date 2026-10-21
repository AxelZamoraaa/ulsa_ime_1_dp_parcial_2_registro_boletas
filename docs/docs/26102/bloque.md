## 1. Autor

**Nombre:** [Emiliano Ferrer de la Cruz]
**Matrícula:** [26102]
**Bloque y opción elegida:** [main]
**Archivo de código:** [main.cpp]

## 2. Propósito

¿Qué hace tu bloque y para qué le sirve a quien usa el programa?

Este bloque administra la ejecución principal del simulador de registro de boletas. Despliega un menú interactivo en consola que le permite al usuario seleccionar entre las distintas opciones del sistema (capturar alumnos, ver lista, calcular estadísticas, consultar aprobados/reprobados, emitir boletas o consultar materias reprobadas) y mantiene el programa en ejecución continua hasta que el usuario elija salir

## 3. Entradas y salidas

¿Qué recibe tu bloque (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

Recibe desde el teclado la opción seleccionada del menú mediante un número entero (opcion), e interactúa con los arreglos globales o estructuras que contienen la información de los alumnos y sus calificaciones. Imprime en pantalla el menú de opciones, mensajes de confirmación, advertencias en caso de opciones o datos inválidos, y las vistas de consulta invocadas

## 4. Decisiones de diseño


**¿Qué funciones tiene tu bloque y qué hace cada una?**

mostrarMenu(): Se encarga exclusivamente de imprimir en la consola el encabezado y las 7 opciones numeradas disponibles. 

 main(): Controla el flujo general, administra el ciclo de vida del programa, valida las entradas del menú y coordina las llamadas a las funciones de los archivos de cabecera (.h).  

**¿Qué ciclo usaste y por qué ese?**

Utilicé un ciclo do-while porque se necesita que el menú interactivo se muestre en pantalla al menos una vez y se siga repitiendo indefinidamente mientras la opción ingresada sea diferente de 7 (Salir)

**¿Qué acumuladores o contadores usaste y con qué valor inician?**

totalAlumnos: Contador de tipo entero inicializado en 0 para llevar el registro de cuántos alumnos han sido capturados.  
 opcion: Variable entera inicializada en 0 que almacena la opción seleccionada por el usuario. 

**¿Dónde está tu decisión múltiple y qué casos cubre?**

Está en la estructura switch(opcion) dentro del ciclo do-while. Cubre los siguientes casos:   Caso 1: Llama a la función de capturar alumno. 
Caso 2: Muestra la lista de alumnos registrados.  
Caso 3: Muestra las estadísticas generales por materia.   
Caso 4: Despliega la lista de aprobados y reprobados.   
Caso 5: Muestra la boleta individual de un alumno.   
Caso 6: Muestra las materias reprobadas por alumno.   
Caso 7: Muestra el mensaje de salida y finaliza el ciclo.  
default: Maneja opciones numéricas no válidas (fuera del rango 1 al 7).   

**¿Qué constantes definiste y por qué son constantes?**

MAX_ALUMNOS = 50: Define la cantidad máxima de alumnos que se pueden almacenar en los arreglos.   OPCION_SALIR = 7: Define el valor numérico para terminar el programa.   Son constantes para evitar valores mágicos en el código y asegurar que los límites del sistema no cambien durante la ejecución. 

**¿Qué casos de rechazo maneja tu bloque y qué mensaje muestra en cada uno?**
Entrada fuera de rango: Si el usuario escribe un número menor a 1 o mayor a 7, muestra: Opción no válida. Por favor, seleccione un número del 1 al 7.   Entrada no numérica: Si el usuario ingresa una letra o símbolo, limpia el búfer y muestra: Error: Ingrese un número válido.   Intentar consultar sin registros: Si el usuario elige las opciones 2 a 6 sin haber registrado alumnos previa captura, muestra: No hay alumnos registrados en el sistema.   Límite de capacidad alcanzado: Si se intenta capturar un nuevo alumno cuando totalAlumnos es igual a MAX_ALUMNOS, muestra: Error: Se ha alcanzado la capacidad máxima de alumnos. 

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
Definir constantes MAX_ALUMNOS = 50 y OPCION_SALIR = 7.   Inicializar la variable totalAlumnos en 0.   Iniciar ciclo do-while:
a. Mostrar el menú de opciones (1 al 7).
b. Leer la variable opcion ingresada por el usuario.
c. Si la entrada no es un número válido:
- Limpiar el búfer de entrada y mostrar mensaje de error.
- Volver al inicio del ciclo.
d. Evaluar la variable opcion con una estructura switch:
- Caso 1: Si totalAlumnos < MAX_ALUMNOS, capturar alumno e incrementar totalAlumnos en 1; de lo contrario, mostrar error de capacidad.
- Caso 2 a 6: Si totalAlumnos > 0, llamar a la función correspondiente de la opción; de lo contrario, mostrar mensaje "No hay alumnos registrados".
- Caso 7: Mostrar mensaje "Saliendo del programa...".
- Default: Mostrar mensaje "Opción no válida".   Repetir el ciclo mientras opcion sea diferente de OPCION_SALIR.   Retornar 0 y finalizar el programa.
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

Sí. Al probar la receta a mano noté que si el usuario intentaba consultar la lista o la boleta antes de capturar a cualquier estudiante, el programa intentaba procesar datos inexistentes en los arreglos. Lo corregí agregando la condición de rechazo totalAlumnos > 0 antes de permitir ejecutar las opciones 2 a 6.

## 6. Bitácora de dudas y errore

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | [El menú se ciclaba infinitamente si el usuario ingresaba una letra en lugar de un número.] | [Implementé cin.clear() y cin.ignore() para limpiar la memoria del teclado tras detectar un error de lectura.] |
| 2 | [Al presionar la opción 7 para salir, el menú se imprimía una vez más antes de terminar.] | [Cambié la condición final del ciclo a while(opcion != OPCION_SALIR) para salir inmediatamente sin volver a iterar.   ] |
| 3 | [Se perdían los registros al intentar ingresar a un segundo alumno] | [IModifiqué el paso de parámetros mandando el índice actual totalAlumnos y asegurando que se incrementara sólo tras una captura exitosa] |
