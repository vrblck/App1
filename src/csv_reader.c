// csv_reader.c
#include "csv_reader.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int leer_csv(const char *filename, Venta ventas[], int *total_ventas) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error al abrir el archivo");
        return -1;
    }

    char line[MAX_LINE];
    *total_ventas = 0;

    // Leer la primera línea (encabezados)
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return -1;
    }

    while (fgets(line, sizeof(line), file)) {
        if (*total_ventas >= MAX_ENTRIES) {
            break;
        }

        Venta venta;
        char *token;
        char *rest = line;

        // Procesar cada campo manualmente
        token = strtok(rest, ","); // pizza_id
        if (token) venta.pizza_id = atoi(token);

        token = strtok(NULL, ","); // order_id
        if (token) venta.order_id = atoi(token);

        token = strtok(NULL, ","); // pizza_name_id
        if (token) strncpy(venta.pizza_name_id, token, sizeof(venta.pizza_name_id));

        token = strtok(NULL, ","); // quantity
        if (token) venta.quantity = atoi(token);

        token = strtok(NULL, ","); // order_date
        if (token) strncpy(venta.order_date, token, sizeof(venta.order_date));

        token = strtok(NULL, ","); // order_time
        if (token) strncpy(venta.order_time, token, sizeof(venta.order_time));

        token = strtok(NULL, ","); // unit_price
        if (token) venta.unit_price = atof(token);

        token = strtok(NULL, ","); // total_price
        if (token) venta.total_price = atof(token);

        token = strtok(NULL, ","); // pizza_size
        if (token) strncpy(venta.pizza_size, token, sizeof(venta.pizza_size));

        token = strtok(NULL, ","); // pizza_category
        if (token) strncpy(venta.pizza_category, token, sizeof(venta.pizza_category));

        token = strtok(NULL, "\""); // pizza_ingredients (manejar comillas)
        if (token) strncpy(venta.pizza_ingredients, token, sizeof(venta.pizza_ingredients));

        token = strtok(NULL, ","); // pizza_name
        if (token) strncpy(venta.pizza_name, token, sizeof(venta.pizza_name));

        // Agregar la venta al arreglo
        ventas[*total_ventas] = venta;
        (*total_ventas)++;

        
    }

    fclose(file);
    return 0;
}