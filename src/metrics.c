// metrics.c
#include "metrics.h"
#include <string.h>

float calcular_total(Venta ventas[], int total) {
    float sum = 0;
    for (int i = 0; i < total; i++) {
         sum += ventas[i].total_price;
    }
    return sum;
}

float calcular_promedio_precio(Venta ventas[], int total) {
    if (total == 0) return 0.0;
    float total_price = calcular_total(ventas, total);
    int total_quantity = 0;
    for (int i = 0; i < total; i++) {
        total_quantity += ventas[i].quantity;
    }
    return total_quantity == 0 ? 0.0 : total_price / total_quantity;
}

float calcular_cantidad_total(Venta ventas[], int total) {
    int sum = 0;
    for (int i = 0; i < total; i++) {
        sum += ventas[i].quantity;
    }
    return (float)sum; // Retorna float para consistencia con MetricFunction
}

// Encuentra la pizza más vendida por cantidad total
const char* pizza_mas_vendida(Venta ventas[], int total) {
    if (total == 0) return NULL;
    typedef struct {
        char pizza_name_id[50];
        int total_quantity;
    } PizzaQuantity;
    PizzaQuantity pizza_quantities[100] = {0};
    int num_pizzas = 0;

    for (int i = 0; i < total; i++) {
        char *current_id = ventas[i].pizza_name_id;
        int found = 0;
        for (int j = 0; j < num_pizzas; j++) {
            if (strcmp(pizza_quantities[j].pizza_name_id, current_id) == 0) {
                pizza_quantities[j].total_quantity += ventas[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found && num_pizzas < 100) {
            strcpy(pizza_quantities[num_pizzas].pizza_name_id, current_id);
            pizza_quantities[num_pizzas].total_quantity = ventas[i].quantity;
            num_pizzas++;
        }
    }

    if (num_pizzas == 0) return NULL;
    int max_quantity = -1;
    char max_pizza_id[50] = "";
    for (int i = 0; i < num_pizzas; i++) {
        if (pizza_quantities[i].total_quantity > max_quantity) {
            max_quantity = pizza_quantities[i].total_quantity;
            strcpy(max_pizza_id, pizza_quantities[i].pizza_name_id);
        }
    }

    for (int i = 0; i < total; i++) {
        if (strcmp(ventas[i].pizza_name_id, max_pizza_id) == 0) {
            static char result[50];
            strcpy(result, ventas[i].pizza_name);
            return result;
        }
    }
    return NULL;
}

// Encuentra la pizza menos vendida por cantidad total
const char* pizza_menos_vendida(Venta ventas[], int total) {
    if (total == 0) return NULL;
    typedef struct {
        char pizza_name_id[50];
        int total_quantity;
    } PizzaQuantity;
    PizzaQuantity pizza_quantities[100] = {0};
    int num_pizzas = 0;

    for (int i = 0; i < total; i++) {
        char *current_id = ventas[i].pizza_name_id;
        int found = 0;
        for (int j = 0; j < num_pizzas; j++) {
            if (strcmp(pizza_quantities[j].pizza_name_id, current_id) == 0) {
                pizza_quantities[j].total_quantity += ventas[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found && num_pizzas < 100) {
            strcpy(pizza_quantities[num_pizzas].pizza_name_id, current_id);
            pizza_quantities[num_pizzas].total_quantity = ventas[i].quantity;
            num_pizzas++;
        }
    }

    // Debug: Print pizza_quantities
    printf("Pizza Quantities:\n");
    for (int i = 0; i < num_pizzas; i++) {
        printf("Pizza ID: %s, Total Quantity: %d\n",
               pizza_quantities[i].pizza_name_id, pizza_quantities[i].total_quantity);
        }

    if (num_pizzas == 0) return NULL;
    int min_quantity = pizza_quantities[0].total_quantity;
    char min_pizza_id[50] = "";
    strcpy(min_pizza_id, pizza_quantities[0].pizza_name_id);
    for (int i = 1; i < num_pizzas; i++) {
        if (pizza_quantities[i].total_quantity < min_quantity) {
            min_quantity = pizza_quantities[i].total_quantity;
            strcpy(min_pizza_id, pizza_quantities[i].pizza_name_id);
        }
    }


    // Debug: Print the minimum pizza
    printf("Min Quantity: %d, Min Pizza ID: %s\n", min_quantity, min_pizza_id);


    for (int i = 0; i < total; i++) {
        if (strcmp(ventas[i].pizza_name_id, min_pizza_id) == 0) {
            static char result[50];
            strcpy(result, ventas[i].pizza_name);
            return result;
        }
    }
    return NULL;
}

// Encuentra la fecha con mayor monto de ventas
void fecha_mas_ventas_dinero(Venta ventas[], int total, char* fecha, float* total_dinero) {
    if (total == 0) {
        strcpy(fecha, "");
        *total_dinero = 0.0;
        return;
    }
    typedef struct {
        char date[11];
        float total_price;
    } DateSales;
    DateSales date_sales[1000] = {0};
    int num_dates = 0;

    for (int i = 0; i < total; i++) {
        char *current_date = ventas[i].order_date;
        int found = 0;
        for (int j = 0; j < num_dates; j++) {
            if (strcmp(date_sales[j].date, current_date) == 0) {
                date_sales[j].total_price += ventas[i].total_price;
                found = 1;
                break;
            }
        }
        if (!found && num_dates < 1000) {
            strcpy(date_sales[num_dates].date, current_date);
            date_sales[num_dates].total_price = ventas[i].total_price;
            num_dates++;
        }
    }

    float max_sales = -1.0;
    char max_date[11] = "";
    for (int i = 0; i < num_dates; i++) {
        if (date_sales[i].total_price > max_sales) {
            max_sales = date_sales[i].total_price;
            strcpy(max_date, date_sales[i].date);
        }
    }
    strcpy(fecha, max_date);
    *total_dinero = max_sales;
}

// Encuentra la fecha con menor monto de ventas
void fecha_menos_ventas_dinero(Venta ventas[], int total, char* fecha, float* total_dinero) {
    if (total == 0) {
        strcpy(fecha, "");
        *total_dinero = 0.0;
        return;
    }
    typedef struct {
        char date[11];
        float total_price;
    } DateSales;
    DateSales date_sales[1000] = {0};
    int num_dates = 0;

    for (int i = 0; i < total; i++) {
        char *current_date = ventas[i].order_date;
        int found = 0;
        for (int j = 0; j < num_dates; j++) {
            if (strcmp(date_sales[j].date, current_date) == 0) {
                date_sales[j].total_price += ventas[i].total_price;
                found = 1;
                break;
            }
        }
        if (!found && num_dates < 1000) {
            strcpy(date_sales[num_dates].date, current_date);
            date_sales[num_dates].total_price = ventas[i].total_price;
            num_dates++;
        }
    }

    float min_sales = date_sales[0].total_price;
    char min_date[11] = "";
    strcpy(min_date, date_sales[0].date);
    for (int i = 1; i < num_dates; i++) {
        if (date_sales[i].total_price < min_sales) {
            min_sales = date_sales[i].total_price;
            strcpy(min_date, date_sales[i].date);
        }
    }
    strcpy(fecha, min_date);
    *total_dinero = min_sales;
}

// Encuentra la fecha con mayor cantidad de pizzas vendidas
void fecha_mas_ventas_cantidad(Venta ventas[], int total, char* fecha, int* total_cantidad) {
    if (total == 0) {
        strcpy(fecha, "");
        *total_cantidad = 0;
        return;
    }
    typedef struct {
        char date[11];
        int total_quantity;
    } DateQuantity;
    DateQuantity date_quantities[1000] = {0};
    int num_dates = 0;

    for (int i = 0; i < total; i++) {
        char *current_date = ventas[i].order_date;
        int found = 0;
        for (int j = 0; j < num_dates; j++) {
            if (strcmp(date_quantities[j].date, current_date) == 0) {
                date_quantities[j].total_quantity += ventas[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found && num_dates < 1000) {
            strcpy(date_quantities[num_dates].date, current_date);
            date_quantities[num_dates].total_quantity = ventas[i].quantity;
            num_dates++;
        }
    }

    int max_quantity = -1;
    char max_date[11] = "";
    for (int i = 0; i < num_dates; i++) {
        if (date_quantities[i].total_quantity > max_quantity) {
            max_quantity = date_quantities[i].total_quantity;
            strcpy(max_date, date_quantities[i].date);
        }
    }
    strcpy(fecha, max_date);
    *total_cantidad = max_quantity;
}

// Encuentra la fecha con menor cantidad de pizzas vendidas
void fecha_menos_ventas_cantidad(Venta ventas[], int total, char* fecha, int* total_cantidad) {
    if (total == 0) {
        strcpy(fecha, "");
        *total_cantidad = 0;
        return;
    }
    typedef struct {
        char date[11];
        int total_quantity;
    } DateQuantity;
    DateQuantity date_quantities[1000] = {0};
    int num_dates = 0;

    for (int i = 0; i < total; i++) {
        char *current_date = ventas[i].order_date;
        int found = 0;
        for (int j = 0; j < num_dates; j++) {
            if (strcmp(date_quantities[j].date, current_date) == 0) {
                date_quantities[j].total_quantity += ventas[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found && num_dates < 1000) {
            strcpy(date_quantities[num_dates].date, current_date);
            date_quantities[num_dates].total_quantity = ventas[i].quantity;
            num_dates++;
        }
    }

    int min_quantity = date_quantities[0].total_quantity;
    char min_date[11] = "";
    strcpy(min_date, date_quantities[0].date);
    for (int i = 1; i < num_dates; i++) {
        if (date_quantities[i].total_quantity < min_quantity) {
            min_quantity = date_quantities[i].total_quantity;
            strcpy(min_date, date_quantities[i].date);
        }
    }
    strcpy(fecha, min_date);
    *total_cantidad = min_quantity;
}

// Calcula el promedio de pizzas por orden
float promedio_pizzas_por_orden(Venta ventas[], int total) {
    if (total == 0) return 0.0;
    typedef struct {
        int order_id;
        int total_quantity;
    } OrderQuantity;
    OrderQuantity order_quantities[1000] = {0};
    int num_orders = 0;

    for (int i = 0; i < total; i++) {
        int current_order_id = ventas[i].order_id;
        int found = 0;
        for (int j = 0; j < num_orders; j++) {
            if (order_quantities[j].order_id == current_order_id) {
                order_quantities[j].total_quantity += ventas[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found && num_orders < 1000) {
            order_quantities[num_orders].order_id = current_order_id;
            order_quantities[num_orders].total_quantity = ventas[i].quantity;
            num_orders++;
        }
    }

    if (num_orders == 0) return 0.0;
    int total_pizzas = 0;
    for (int i = 0; i < num_orders; i++) {
        total_pizzas += order_quantities[i].total_quantity;
    }
    return (float)total_pizzas / num_orders;
}

// Calcula el promedio de pizzas vendidas por día
float promedio_pizzas_por_dia(Venta ventas[], int total) {
    if (total == 0) return 0.0;
    typedef struct {
        char date[11];
        int total_quantity;
    } DateQuantity;
    DateQuantity date_quantities[1000] = {0};
    int num_dates = 0;

    for (int i = 0; i < total; i++) {
        char *current_date = ventas[i].order_date;
        int found = 0;
        for (int j = 0; j < num_dates; j++) {
            if (strcmp(date_quantities[j].date, current_date) == 0) {
                date_quantities[j].total_quantity += ventas[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found && num_dates < 1000) {
            strcpy(date_quantities[num_dates].date, current_date);
            date_quantities[num_dates].total_quantity = ventas[i].quantity;
            num_dates++;
        }
    }

    if (num_dates == 0) return 0.0;
    int total_pizzas = 0;
    for (int i = 0; i < num_dates; i++) {
        total_pizzas += date_quantities[i].total_quantity;
    }
    return (float)total_pizzas / num_dates;
}

// Encuentra el ingrediente más vendido por cantidad
const char* ingrediente_mas_vendido(Venta ventas[], int total) {
    if (total == 0) return NULL;
    typedef struct {
        char ingredient[50];
        int total_quantity;
    } IngredientQuantity;
    IngredientQuantity ingredient_quantities[100] = {0};
    int num_ingredients = 0;

    for (int i = 0; i < total; i++) {
        char ingredients_copy[100];
        strcpy(ingredients_copy, ventas[i].pizza_ingredients);
        char *token = strtok(ingredients_copy, ", ");
        while (token != NULL && num_ingredients < 100) {
            int found = 0;
            for (int j = 0; j < num_ingredients; j++) {
                if (strcmp(ingredient_quantities[j].ingredient, token) == 0) {
                    ingredient_quantities[j].total_quantity += ventas[i].quantity;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(ingredient_quantities[num_ingredients].ingredient, token);
                ingredient_quantities[num_ingredients].total_quantity = ventas[i].quantity;
                num_ingredients++;
            }
            token = strtok(NULL, ", ");
        }
    }

    if (num_ingredients == 0) return NULL;
    int max_quantity = -1;
    static char result[50];
    for (int i = 0; i < num_ingredients; i++) {
        if (ingredient_quantities[i].total_quantity > max_quantity) {
            max_quantity = ingredient_quantities[i].total_quantity;
            strcpy(result, ingredient_quantities[i].ingredient);
        }
    }
    return max_quantity >= 0 ? result : NULL;
}

// Cuenta la cantidad de pizzas por categoría
void cantidad_pizzas_por_categoria(Venta ventas[], int total, int* categorias) {
    const char* category_names[] = {"Classic", "Veggie", "Supreme", "Chicken", "Specialty"};
    const int num_categories = 5;
    for (int i = 0; i < num_categories; i++) {
        categorias[i] = 0;
    }
    for (int i = 0; i < total; i++) {
        for (int j = 0; j < num_categories; j++) {
            if (strcmp(ventas[i].pizza_category, category_names[j]) == 0) {
                categorias[j] += ventas[i].quantity;
                break;
            }
        }
    }
}
