#include "metrics.h"
#include <string.h>
#include <stdio.h>

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
    float total_quantity = 0;
    for (int i = 0; i < total; i++) {
        total_quantity += ventas[i].quantity;
    }
    return total_quantity == 0 ? 0.0 : total_price / total_quantity;
}

float calcular_cantidad_total(Venta ventas[], int total) {
    float sum = 0;
    for (int i = 0; i < total; i++) {
        sum += ventas[i].quantity;
    }
    return sum;
}

// Estructura para contar pizzas
typedef struct {
    char pizza_name[50];
    float total_quantity;
} PizzaCount;

const char* pizza_mas_vendida(Venta ventas[], int total) {
    static PizzaCount pizzas[100];
    int num_pizzas = 0;
    memset(pizzas, 0, sizeof(pizzas));

    // Contar cantidades de cada pizza
    for (int i = 0; i < total; i++) {
        const char* current_pizza = ventas[i].pizza_name;
        int found = 0;

        for (int j = 0; j < num_pizzas; j++) {
            if (strcmp(pizzas[j].pizza_name, current_pizza) == 0) {
                pizzas[j].total_quantity += ventas[i].quantity;
                found = 1;
                break;
            }
        }

        if (!found && num_pizzas < 100) {
            strncpy(pizzas[num_pizzas].pizza_name, current_pizza, sizeof(pizzas[num_pizzas].pizza_name) - 1);
            pizzas[num_pizzas].pizza_name[sizeof(pizzas[num_pizzas].pizza_name) - 1] = '\0';
            pizzas[num_pizzas].total_quantity = ventas[i].quantity;
            num_pizzas++;
        }
    }

    // Encontrar la cantidad máxima
    if (num_pizzas == 0) return "N/A";

    float max_quantity = pizzas[0].total_quantity;
    for (int i = 1; i < num_pizzas; i++) {
        if (pizzas[i].total_quantity > max_quantity) {
            max_quantity = pizzas[i].total_quantity;
        }
    }

    // Construir una lista de pizzas con la cantidad máxima
    static char result[500] = "";
    result[0] = '\0'; // Asegurar que el resultado esté vacío

    for (int i = 0; i < num_pizzas; i++) {
        if (pizzas[i].total_quantity == max_quantity) {
            if (strlen(result) > 0) {
                strncat(result, ", ", sizeof(result) - strlen(result) - 1); // Agregar separador
            }
            strncat(result, pizzas[i].pizza_name, sizeof(result) - strlen(result) - 1);
        }
    }

    return result;
}

const char* pizza_menos_vendida(Venta ventas[], int total) {
    static PizzaCount pizzas[100];
    int num_pizzas = 0;
    memset(pizzas, 0, sizeof(pizzas));

    // Contar cantidades de cada pizza
    for (int i = 0; i < total; i++) {
        const char* current_pizza = ventas[i].pizza_name;
        int found = 0;

        for (int j = 0; j < num_pizzas; j++) {
            if (strcmp(pizzas[j].pizza_name, current_pizza) == 0) {
                pizzas[j].total_quantity += ventas[i].quantity;
                found = 1;
                break;
            }
        }

        if (!found && num_pizzas < 100) {
            strncpy(pizzas[num_pizzas].pizza_name, current_pizza, sizeof(pizzas[num_pizzas].pizza_name) - 1);
            pizzas[num_pizzas].pizza_name[sizeof(pizzas[num_pizzas].pizza_name) - 1] = '\0';
            pizzas[num_pizzas].total_quantity = ventas[i].quantity;
            num_pizzas++;
        }
    }

    // Encontrar la cantidad mínima
    if (num_pizzas == 0) return "N/A";

    float min_quantity = pizzas[0].total_quantity;
    for (int i = 1; i < num_pizzas; i++) {
        if (pizzas[i].total_quantity < min_quantity) {
            min_quantity = pizzas[i].total_quantity;
        }
    }

    // Construir una lista de pizzas con la cantidad mínima
    static char result[500] = "";
    result[0] = '\0'; // Asegurar que el resultado esté vacío

    for (int i = 0; i < num_pizzas; i++) {
        if (pizzas[i].total_quantity == min_quantity) {
            if (strlen(result) > 0) {
                strncat(result, ", ", sizeof(result) - strlen(result) - 1); // Agregar separador
            }
            strncat(result, pizzas[i].pizza_name, sizeof(result) - strlen(result) - 1);
        }
    }

    return result;
}

//4 Encuentra la fecha con menor monto de ventas
void fecha_menos_ventas_dinero(Venta ventas[], int total, char* fecha, float* total_dinero) {
    if (total == 0) {
        strcpy(fecha, "N/A");
        *total_dinero = 0.0;
        return;
    }

    // Inicializar con el primer valor
    *total_dinero = ventas[0].total_price;
    strncpy(fecha, ventas[0].order_date, 11);

    // Encontrar la fecha con el monto mínimo
    for (int i = 1; i < total; i++) {
        if (ventas[i].total_price < *total_dinero) {
            *total_dinero = ventas[i].total_price;
            strncpy(fecha, ventas[i].order_date, 11);
        }
    }
}

//5 Encuentra la fecha con mayor cantidad de pizzas vendidas
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

//6 Encuentra la fecha con menor cantidad de pizzas vendidas
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

//7 Calcula el promedio de pizzas por orden
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

//8 Calcula el promedio de pizzas vendidas por día
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

//9 Encuentra el ingrediente más vendido por cantidad
void ingrediente_mas_vendido(Venta ventas[], int total, char* ingrediente_max) {
    typedef struct {
        char ingrediente[50];
        int cantidad;
    } IngredienteCount;

    IngredienteCount ingredientes[100] = {0};
    int num_ingredientes = 0;

    for (int i = 0; i < total; i++) {
        char ingredientes_local[200];
        strcpy(ingredientes_local, ventas[i].pizza_ingredients);
        
        // Removemos comillas iniciales y finales si existen
        if (ingredientes_local[0] == '"') {
            memmove(ingredientes_local, ingredientes_local + 1, strlen(ingredientes_local));
        }
        if (ingredientes_local[strlen(ingredientes_local) - 1] == '"') {
            ingredientes_local[strlen(ingredientes_local) - 1] = '\0';
        }

        char* token = strtok(ingredientes_local, ",");
        while (token != NULL) {
            int found = 0;
            for (int j = 0; j < num_ingredientes; j++) {
                if (strcmp(ingredientes[j].ingrediente, token) == 0) {
                    ingredientes[j].cantidad++;
                    found = 1;
                    break;
                }
            }
            if (!found && num_ingredientes < 100) {
                strncpy(ingredientes[num_ingredientes].ingrediente, token, sizeof(ingredientes[num_ingredientes].ingrediente) - 1);
                ingredientes[num_ingredientes].cantidad = 1;
                num_ingredientes++;
            }

            token = strtok(NULL, ",");
        }
    }

    int max_cantidad = 0;
    static char max_ingrediente[50] = "";

    for (int i = 0; i < num_ingredientes; i++) {
        if (ingredientes[i].cantidad > max_cantidad) {
            max_cantidad = ingredientes[i].cantidad;
            strcpy(max_ingrediente, ingredientes[i].ingrediente);
        }
    }

    strcpy(ingrediente_max, max_cantidad > 0 ? max_ingrediente : "N/A");
}

//10 Cuenta la cantidad de pizzas por categoría
void pizzas_por_categoria(Venta ventas[], int total) {
    typedef struct {
        char categoria[30];
        int total_pizzas;
    } CategoriaCount;

    CategoriaCount categorias[20] = {0};
    int num_categorias = 0;

    for (int i = 0; i < total; i++) {
        const char* current_categoria = ventas[i].pizza_category;
        int found = 0;

        for (int j = 0; j < num_categorias; j++) {
            if (strcmp(categorias[j].categoria, current_categoria) == 0) {
                categorias[j].total_pizzas += ventas[i].quantity;
                found = 1;
                break;
            }
        }

        if (!found && num_categorias < 20) {
            strncpy(categorias[num_categorias].categoria, current_categoria, sizeof(categorias[num_categorias].categoria) - 1);
            categorias[num_categorias].total_pizzas = ventas[i].quantity;
            num_categorias++;
        }
    }

    printf("\nPizzas vendidas por categoría:\n");
    for (int i = 0; i < num_categorias; i++) {
        printf("Categoría: %s - Total Vendidas: %d\n", categorias[i].categoria, categorias[i].total_pizzas);
    }
}

void fecha_mas_ventas_dinero(Venta ventas[], int total, char* fecha, float* total_dinero) {
    *total_dinero = 0.0;
    strcpy(fecha, "N/A");

    for (int i = 0; i < total; i++) {
        if (ventas[i].total_price > *total_dinero) {
            *total_dinero = ventas[i].total_price;
            strncpy(fecha, ventas[i].order_date, 10);
            fecha[10] = '\0'; // Asegurar terminación nula
        }
    }
}

void cantidad_pizzas_por_categoria(Venta ventas[], int total, int* categorias) {
    // Inicializar categorías
    categorias[0] = categorias[1] = categorias[2] = categorias[3] = 0;

    for (int i = 0; i < total; i++) {
        if (strcmp(ventas[i].pizza_category, "Classic") == 0) {
            categorias[0] += ventas[i].quantity;
        } else if (strcmp(ventas[i].pizza_category, "Veggie") == 0) {
            categorias[1] += ventas[i].quantity;
        } else if (strcmp(ventas[i].pizza_category, "Specialty") == 0) {
            categorias[2] += ventas[i].quantity;
        } else {
            categorias[3] += ventas[i].quantity;
        }
    }
}
