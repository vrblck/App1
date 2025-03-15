// csv_reader.c
#include "include/csv_reader.h"
#include <string.h>

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
        if (sscanf(line, "%d,%10[^,],%49[^,],%d,%f", &venta.id, venta.fecha, venta.pizza, &venta.cantidad, &venta.precio_unitario) == 5) {
            ventas[*total_ventas] = venta;
            (*total_ventas)++;
        }
    }

    fclose(file);
    return 0;
}