# App1

## **Profesora**
- **María Loreto Arriagada** <br>
  <loreto.arriagada.v@edu.uai.cl>

## **Ayudante**
- **Diego Duhalde** <br>
  <dduhalde@alumnos.uai.cl>

## **Integrantes**  
- **Valentina Roselló**  
  *GitHub: @vrblck*
- **Jesús Salazar**  
  *GitHub: @jesu9510*  
- **Alexander Vera**  
  *GitHub: @alexanderveratry*  
- **María Loreto Gaya**  
  *GitHub: @Lore131989*  
- **Diego Gajardo**  
  *GitHub: @Wajax8*
---

# **Tarea 1: Pizzería en C**

## 1. Objetivos

1. Aprender a estructurar un programa en varios archivos fuente de manera ordenada, lógica y modular.  
2. Utilizar herramientas clásicas de apoyo a la programación como GIT, make, debuggers, etc.  
3. Utilizar punteros y, en especial, punteros a funciones.  
4. Desarrollar un sistema capaz de leer un archivo CSV y aplicar sobre él varias métricas (fórmulas matemáticas simples).

---

## 2. Implementación del código

> **TICS200 App #1 – Pizzería**

### 2.1. Archivos importantes
- Formato de `ventas.csv`:  
```
pizza_id,order_id,pizza_name_id,quantity,order_date,order_time,unit_price,total_price,pizza_size,pizza_category,pizza_ingredients,pizza_name
1.00,1.00,hawaiian_m,1.00,1/1/2015,11:38:36,13.25,13.25,M,Classic,"Sliced Ham, Pineapple, Mozzarella Cheese",The Hawaiian Pizza
2.00,2.00,classic_dlx_m,1.00,1/1/2015,11:57:40,16.00,16.00,M,Classic,"Pepperoni, Mushrooms, Red Onions, Red Peppers, Bacon",The Classic Deluxe Pizza
3.00,2.00,five_cheese_l,1.00,1/1/2015,11:57:40,18.50,18.50,L,Veggie,"Mozzarella Cheese, Provolone Cheese, Smoked Gouda Cheese, Romano Cheese, Blue Cheese, Garlic",The Five Cheese Pizza
  ```
 
- Ejemplo de ejecución en terminal:  
```bash
bin/app1 data/ventas.csv metrica0 metrica1 ...
```

- **Métricas a pedir** (ejecutadas según se especifique en los parámetros de la consola):
  1. `pms`: Pizza más vendida / Most sold pizza 
  2. `pls`: Pizza menos vendida / Least sold pizza 
  3. `dms`: Fecha con más ventas en términos de dinero / Date with highest sales amount  
  4. `dls`: Fecha con menos ventas en términos de dinero / / Date with lowest sales amount  
  5. `dmsp`: Fecha con más ventas en términos de cantidad de pizzas / Date with highest number of sales  
  6. `dlsp`: Fecha con menos ventas en términos de cantidad de pizzas / Date with lowest number of sales
  7. `apo`: Promedio de pizzas por orden / Average pizzas per order
  8. `apd`: Promedio de pizzas por día / Average pizzas per day
  9. `ims`: Ingrediente más vendido / Most sold ingredient
  10. `hp`: Cantidad de pizzas por categoría vendidas / Number of pizzas sold by category

## Ejemplo de uso:
- Compilación:
```bash
make clean && make
```

- Ejecución:
```bash
bin/app1 data/ventas.csv pms pls dms dls dmsp dlsp apo apd ims hp
```

- Salida esperada:
```bash
pms: Most sold pizza: The Margherita Pizza
pls: Least sold pizza: The Veggie Deluxe Pizza, The Meat Lovers Pizza
dms: Date with highest sales amount: 1/6/2015: 36.00
dls: Date with lowest sales amount: 1/4/2015: 13.00
dmsp: Date with highest number of sales: 1/3/2015: 5
dlsp: Date with lowest number of sales: 1/4/2015: 2
apo: Average pizzas per order: 1.64
apd: Average pizzas per day: 3.24
ims: Most sold ingredient:  Mozzarella Cheese
hp: Number of pizzas sold by category: Classic: 114, Veggie: 17, Specialty: 31, Other: 0
```
---

## 5. Formato de Entrega (vía repositorio GitHub)

1. **Fork del repositorio base**  
   - Deberán **forkear** el siguiente repositorio: [App1 en GitHub](https://github.com/UAI-Lenguaje-y-Paradigmas/App1).  
   - En ese repositorio forkeado, **agregar** a todos los integrantes del grupo como colaboradores. (Los cuales aparecen al principio de este archivo) 
  