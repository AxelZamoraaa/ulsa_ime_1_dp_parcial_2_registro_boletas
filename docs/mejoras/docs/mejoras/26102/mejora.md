Propuesta de mejora elaborada por: Emiliano Ferrer
**Matrícula:** 26102
**Título de la propuesta:** Clasificación automática de estatus académico y alertas de riesgo/beca por alumno

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

Es una **mejora**.
Resuelve la falta de un diagnóstico claro sobre la situación académica de cada estudiante. En lugar de solo mostrar números, el sistema clasifica de forma automática a los alumnos en categorías como: "Candidato a Beca" (promedio ≥ 9.0 sin materias reprobadas), "Alumno Regular" (promedio entre 6.0 y 8.9), o "En Riesgo Académico" (si tiene 2 o más materias reprobadas).

Beneficia a los tutores, coordinadores académicos y docentes para identificar inmediatamente a los alumnos que requieren intervención prioritaria o apoyos institucionales.

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (arreglos, constantes, funciones, menú)? Justifica cada cambio.

- **Menú principal (main.cpp):** Se agrega una nueva opción al menú principal ("8. Reporte de Estatus Académico y Alertas") antes de la opción de Salir.
- **Estructuras / Tipos de datos (`registro.h`):** Se puede añadir un campo o función auxiliar para calcular el `estatus` (cadena de texto) dentro de los datos del alumno.
- **Funciones de Diagnóstico (`estadisticas.h` / `estadisticas.cpp`):** Se crea la función `determinarEstatusAlumno()`, la cual evalúa el promedio general y el conteo de materias reprobadas del estudiante para asignarle su categoría.
- **Vista de Reportes:** Se crea la función `mostrarReporteEstatus()`, que recorre a todos los alumnos y los agrupa/muestra según su estatus académico.

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con '[NUEVO]' y cada paso que cambia con '[CAMBIA]'. Los pasos sin marca son los que ya existen.