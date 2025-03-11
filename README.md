# App1
A continuación se presenta una **propuesta** de cómo podrías reestructurar el enunciado y la rúbrica para incorporar los nuevos requisitos: **Informe de diseño y justificación de la solución**, **Sección de reflexiones finales o autoevaluación** y **Explicación de uso de IA**. La idea es que el documento resultante mantenga la lógica de la tarea original, pero añadiendo secciones que fomenten que el alumnado realmente comprenda y explique lo que ha hecho (incluso si ha utilizado ChatGPT u otras herramientas de IA).

---

## 1. Objetivos de la tarea

1. Aprender a **estructurar** un programa en C en varios archivos fuente de forma ordenada y modular.  
2. **Familiarizarse** con herramientas clásicas de apoyo a la programación: GIT, make, debuggers, etc.  
3. **Utilizar punteros**, tanto a datos como a funciones.  
4. Lograr **manejar lectura y parseo de archivos CSV** y aplicar operaciones sencillas sobre los datos.  

---

## 2. Enunciado general

*(Aquí mantendrías la descripción original del problema de la Pizzería, las métricas solicitadas, el formato del CSV, los requerimientos funcionales, restricciones, etc.)*

Por ejemplo:  
- Tu programa deberá leer el archivo `ventas.csv` y, dependiendo de los parámetros de consola (pms, pls, dms, dls, etc.), **imprimir** los resultados correspondientes a cada métrica.

### 2.1 Requerimientos funcionales

*(Copiarías la sección original que indica las 10 métricas, cómo se invoca el programa, etc.)*

### 2.2 Restricciones y otros detalles

*(Mantener lo relativo a “punteros a funciones”, “uso de struct order”, “no se validan campos vacíos”, etc.)*

---

## 3. **Nuevos entregables y estructura final**

Además de cumplir con la implementación en C de acuerdo con el enunciado, se requiere entregar:

1. **Código fuente**  
   - Dividido en archivos .c y .h de forma lógica.  
   - Un `Makefile` que **permita compilar** sin errores.  
   - Uso de GIT (opcionalmente se puede pedir un enlace a un repositorio o evidencia de commits, si aplica).

2. **Informe de diseño y justificación de la solución**  
   - **Objetivo**: Explicar de manera **breve** (2-3 páginas máximo) cómo se organizó el código, las estructuras de datos empleadas (e.g., `struct` para las órdenes), la justificación de la modularidad y el uso de punteros a funciones.  
   - **Contenido sugerido**:  
     - Diagrama de flujo o pseudocódigo general.  
     - Razones de diseño (por qué se decidió leer el CSV de cierta forma, por qué se guardan los ingredientes en un array dinámico, etc.).  
     - Explicación breve de la interacción entre archivos (por ejemplo, `main.c`, `metrics.c`, `utils.c`, etc.).  
     - Referencias a cualquier recurso externo utilizado.

3. **Sección de reflexiones finales o autoevaluación**  
   - Cada integrante del grupo (o el grupo en conjunto, dependiendo de la modalidad) redactará uno o dos párrafos indicando:  
     - *Qué fue lo más complejo o interesante de la tarea*.  
     - *Cómo enfrentaron los errores* (debugging, testing, manejo de memoria, etc.).  
     - Lecciones aprendidas que consideren valiosas para futuros proyectos en C o similares.

4. **Explicación de cómo usaron IA**  
   - Incluir uno o dos párrafos explicando si se utilizó ChatGPT u otra herramienta de IA para asistencia en la solución.  
   - Describir *qué tipo de ayuda brindó la herramienta* (por ejemplo, búsqueda de errores, propuesta de estructuras de datos, generación de pseudocódigo).  
   - Indicar *cómo validaron la información generada* (contraste con documentación oficial, pruebas propias, etc.).  
   - No es necesario incluir *todo* lo que generó la IA, sino una explicación crítica de cómo se integró (o se descartó) lo que propuso la herramienta.

---

## 4. Formato de entrega

- **Archivo comprimido** (zip) con el nombre `grupoX-app1.zip`.  
- Dentro del ZIP, una carpeta `tarea1/` que contenga:  
  1. El código fuente en C (archivos .c y .h),  
  2. El `Makefile`,  
  3. El **Informe de diseño** (en PDF o Markdown),  
  4. La **Sección de reflexiones** (puede estar dentro del mismo PDF o en un PDF/MD aparte),  
  5. La **Explicación de uso de IA** (también puede ir en el mismo PDF),  
  6. Un breve **README** que indique cómo compilar y ejecutar el programa.

---

## 5. Rúbrica actualizada

| **Criterios generales**                                           | **Ponderación** | **Descripción**                                                                                                                                                                                                                                                                                    |
|:-----------------------------------------------------------------:|:---------------:|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **1. Funcionamiento del programa**                               |       40%       | <ul><li>El programa se compila y corre sin errores de ejecución (segmentation fault, etc.).</li><li>El formato de la salida de cada una de las funciones (métricas) es acorde al enunciado.</li><li>Los resultados generados son correctos según el problema (parcial si solo cumplen algunas).</li></ul> |
| **2. Paradigma Procedural**                                      |       25%       | <ul><li>Lógica clara y coherente con el problema.</li><li>Uso adecuado de funciones y modularidad, evitando variables globales innecesarias.</li><li>Incluye comentarios descriptivos que facilitan la comprensión (explicando la lógica de cada función/archivo).</li></ul>                                                                    |
| **3. Lenguaje C**                                                |       20%       | <ul><li>Uso apropiado de punteros a función según se solicita.</li><li>Gestión de memoria dinámica correcta (malloc/free), sin fugas detectables.</li><li>Lectura de archivos dinámica y parseo correcto del CSV (uso de structs, manejo de líneas e ingredientes, parse adecuado).</li></ul>                                                 |
| **4. Informe de diseño, reflexiones finales y uso de IA**        |       15%       | <ul><li><strong>Informe de diseño y justificación</strong>: claridad al explicar la arquitectura y decisiones (5%).</li><li><strong>Reflexiones finales o autoevaluación</strong>: identificación de desafíos, aprendizajes (5%).</li><li><strong>Explicación de uso de IA</strong>: transparencia sobre si y cómo se utilizó, con enfoque crítico (5%).</li></ul> |

**Total:** 100%  

Como en la pauta original, la nota máxima es 7.0. Los porcentajes aquí se transforman luego a la calificación final. Por ejemplo, si un grupo cumple al 100% cada criterio, se adjudica la nota 7.0.

### Penalizaciones y bonus

- **Atraso en la entrega**: Cada día de atraso resta 1 punto al máximo alcanzable (comenzando a las 00:00 del día siguiente).  
- **Menos integrantes que lo propuesto (2-3)**: puede existir un ligero aumento (extra) o se puede mantener según la política del curso.  
- **Más integrantes que lo propuesto**: penalización estándar descrita en el enunciado (-1.0).  
- **Organización en diferentes archivos .c y .h**: ya se considera dentro de la nota, pero se puede añadir un bonus marginal si está especialmente bien segmentado y documentado.

---

## 6. Ejemplo de entrega final

1. `tarea1/Makefile`  
2. `tarea1/src/main.c`, `tarea1/src/metrics.c`, `tarea1/include/metrics.h`, etc.  
3. `tarea1/Informe_de_diseño.pdf`  
4. `tarea1/Reflexiones_y_uso_de_IA.md` (o .pdf)  
5. `tarea1/README.md` explicando cómo compilar y cómo ejecutar las métricas.

El profesor o ayudante **compilará** con:

```bash
cd tarea1
make
./app1 ventas.csv pms pls dms ...
```

y verificará cada funcionalidad.
