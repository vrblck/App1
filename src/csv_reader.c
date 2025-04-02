// csv_reader.c
#include "csv_reader.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

        // Ajustar sscanf para manejar ingredientes entre comillas
        if (sscanf(line, "%f,%f,%49[^,],%f,%10[^,],%8[^,],%f,%f,%1[^,],%19[^,],\"%199[^\"]\",%49[^\n]",
                   &venta.pizza_id, &venta.order_id, venta.pizza_name_id, &venta.quantity,
                   venta.order_date, venta.order_time, &venta.unit_price, &venta.total_price,
                   venta.pizza_size, venta.pizza_category, venta.pizza_ingredients, venta.pizza_name) == 12) {
            ventas[*total_ventas] = venta;
            (*total_ventas)++;
        }
    }

    fclose(file);
    return 0;
}
