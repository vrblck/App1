# **Tarea 1: Pizzería en C**

## **Curso:** TICS200 - Lenguaje y Paradigmas de Programación  
## **Universidad:** Universidad Adolfo Ibáñez  
## **Semestre:** 2025-1  

### **Profesora**  
- **María Loreto Arriagada**  
  📧 loreto.arriagada.v@edu.uai.cl   

### **Ayudante**  
- **Diego Duhalde**  
  📧 dduhalde@alumnos.uai.cl  

### **Integrantes**  
- **Valentina Roselló**  
  *GitHub: @vrblck*
- **Jesús Salazar**  
  *GitHub: @jesu9510*  
- **Nombre y Apellido**  
  *GitHub: @usuario*  
- **Nombre y Apellido**  
  *GitHub: @usuario*  
- **Nombre y Apellido**  
  *GitHub: @usuario*  
---

## **1. Descripción de la tarea**

...


### **Objetivos de aprendizaje**
1. ...
2. ...
3. ...
4. ...

---

## **2. Especificaciones del programa**

- El programa debe ser un **ejecutable** llamado `app1`.
- Se ejecutará desde la terminal recibiendo como **argumentos** el nombre del archivo CSV y las métricas a calcular.
- **Ejemplo de ejecución en Codespace de GitHub en `codespacevrblck`**:
  ```bash
  bin/app1 data/ventas.csv pms pls
  ```
  Esto calculará las métricas "pizza más vendida" (`pms`) y "pizza menos vendida" (`pls`).

### **2.1. Formato del archivo CSV**
Cada línea del archivo representa una venta de pizza con los siguientes datos, a continuación, se mostrará un fragmento del archivo:
```
pizza_id,order_id,pizza_name_id,quantity,order_date,order_time,unit_price,total_price,pizza_size,pizza_category,pizza_ingredients,pizza_name
1.00,1.00,hawaiian_m,1.00,1/1/2015,11:38:36,13.25,13.25,M,Classic,"Sliced Ham, Pineapple, Mozzarella Cheese",The Hawaiian Pizza
2.00,2.00,classic_dlx_m,1.00,1/1/2015,11:57:40,16.00,16.00,M,Classic,"Pepperoni, Mushrooms, Red Onions, Red Peppers, Bacon",The Classic Deluxe Pizza
```

### **2.2. Métricas a calcular**
| Código  | Métrica |
|---------|---------|
| `pms`   | Pizza más vendida / Most sold pizza |
| `pls`   | Pizza menos vendida / Least sold pizza |
| `dms`   | Día con más ventas en términos de dinero / Date with highest sales amount|
| `dls`   | Día con menos ventas en términos de dinero / Date with lowest sales amount|
| `dmsp`  | Día con más ventas en cantidad de pizzas / Date with highest number of sales |
| `dlsp`  | Día con menos ventas en cantidad de pizzas / Date with lowest number of sales |
| `apo`   | Promedio de pizzas por orden / Average pizzas per order|
| `apd`   | Promedio de pizzas por día / Average pizzas per day|
| `ims`   | Ingrediente más vendido / Most sold ingredient|
| `hp`    | Cantidad de pizzas vendidas por categoría / Number of pizzas sold by category|

---

## **3. Implementación técnica**

### **3.1. Modularidad del código**
El código está estructurado en múltiples archivos `.c` y `.h`, por ejemplo:
- `csv_reader.h`, `metrics.h` → Definiciones de estructuras.
- `metrics.c` → Implementación de funciones de cálculo de métricas.
- `csv_reader.c` → Implementación de `ventas.csv`.
- `main.c` → Función principal del programa.

### **3.2. Uso de Makefile**
Debe incluirse un `Makefile` con reglas para compilar el código y generar el ejecutable `app1` con directorios compatibles a Linux (que se usa en Codespace de GitHub)

---

## **4. Entrega y Evaluación**

### **4.1. Formato de entrega**
- **Repositorio GitHub:** Se debe hacer un **fork** del repo base.
- **Estructura del repositorio**:
  ```
  /app1
    ├── .vscode/
    │   ├── c_cpp_properties.json
    │   ├── launch.json
    │   ├── settings.json
    │   ├── tasks.json     
    ├── bin/
    │   ├── app1
    ├── data/
    │   ├── ventas.csv
    ├── include/
    │   ├── csv_reader.h
    │   ├── metrics.h
    ├── obj/
    │   ├── csv_reader.o
    │   ├── main.o
    │   ├── metrics.o
    ├── src/
    │   ├── csv_reader.c    
    │   ├── main.c
    │   ├── metrics.c
    ├── Makefile
    ├── NUL
    ├── README.md
  ```

### **4.2. Explicación de cada archivo**
| Archivo | Explicación |
|---------|-------------|
| `.vscode/...` | ... |
| `bin/app1` | ... |
| `data/ventas.csv` | ... |
| `include/csv_reader.h` | ... |
| `include/metrics.h` | ... |
| `obj/...` | ... |
| `src/csv_reader.c` | ... |
| `src/main.c` | ... |
| `src/metrics.c` | ... |
| `Makefile` | ... |
| `NUL` | ... |

### **4.3. Reflexión y uso de IA**
Debe incluirse en el informe un apartado sobre **aprendizajes adquiridos** y **uso de herramientas como ChatGPT o Copilot GitHub**, si corresponde.

---

## **5. Ejemplo de Ejecución**
### **Compilación**
```bash
make
```
### **Ejecución**
```bash
bin/app1 data/ventas.csv pms pls dms dls dmsp dlsp apo apd ims hp
```
### **Salida esperada**
```bash
pms: Most sold pizza:  Mozzarella Cheese, Basil,The Margherita Pizza
pls: Least sold pizza:  Pineapple, Mozzarella Cheese,The Hawaiian Pizza
dms: Date with highest sales amount: 1/6/2015: 62.50
dls: Date with lowest sales amount: 1/16/2015: 29.25
dmsp: Date with highest number of sales: 1/3/2015: 5
dlsp: Date with lowest number of sales: 1/4/2015: 2
apo: Average pizzas per order: 1.64
apd: Average pizzas per day: 3.24
ims: Most sold ingredient: Tomato
```

---
