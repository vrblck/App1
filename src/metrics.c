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
                strncat(result, ", ", sizeof(result) - strlen(result) - 1);
            }
            strncat(result, pizzas[i].pizza_name, sizeof(result) - strlen(result) - 1);
        }
    }

    return result;
}