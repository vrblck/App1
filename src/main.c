// main.c
#include <stdio.h>
#include <string.h>
#include "csv_reader.h"
#include "metrics.h"

#define MAX_ENTRIES 500

// Structure to map metric codes to functions and descriptions
typedef struct {
    const char* code;              // Metric code (e.g., "pms")
    void (*func)(Venta[], int, void*); // Function that calculates the metric
    const char* description;       // Description for the output
} Metric;

// Wrappers for metrics
void wrap_pizza_mas_vendida(Venta ventas[], int total, void* result) {
    const char* pizza = pizza_mas_vendida(ventas, total);
    snprintf((char*)result, 500, "%s", pizza); // Ajustar tamaño del buffer
}

void wrap_pizza_menos_vendida(Venta ventas[], int total, void* result) {
    const char* pizza = pizza_menos_vendida(ventas, total);
    snprintf((char*)result, 500, "%s", pizza); // Ajustar tamaño del buffer
}

void wrap_fecha_mas_ventas_dinero(Venta ventas[], int total, void* result) {
    static char fecha[11];
    static float total_dinero;
    fecha_mas_ventas_dinero(ventas, total, fecha, &total_dinero);
    snprintf((char*)result, 50, "%s: %.2f", fecha, total_dinero);
}

void wrap_fecha_menos_ventas_dinero(Venta ventas[], int total, void* result) {
    static char fecha[11];
    static float total_dinero;
    fecha_menos_ventas_dinero(ventas, total, fecha, &total_dinero);
    snprintf((char*)result, 50, "%s: %.2f", fecha, total_dinero);
}

void wrap_fecha_mas_ventas_cantidad(Venta ventas[], int total, void* result) {
    static char fecha[11];
    static int total_cantidad;
    fecha_mas_ventas_cantidad(ventas, total, fecha, &total_cantidad);
    snprintf((char*)result, 50, "%s: %d", fecha, total_cantidad);
}

void wrap_fecha_menos_ventas_cantidad(Venta ventas[], int total, void* result) {
    static char fecha[11];
    static int total_cantidad;
    fecha_menos_ventas_cantidad(ventas, total, fecha, &total_cantidad);
    snprintf((char*)result, 50, "%s: %d", fecha, total_cantidad);
}

void wrap_promedio_pizzas_por_orden(Venta ventas[], int total, void* result) {
    float promedio = promedio_pizzas_por_orden(ventas, total);
    snprintf((char*)result, 50, "%.2f", promedio);
}

void wrap_promedio_pizzas_por_dia(Venta ventas[], int total, void* result) {
    float promedio = promedio_pizzas_por_dia(ventas, total);
    snprintf((char*)result, 50, "%.2f", promedio);
}

void wrap_ingrediente_mas_vendido(Venta ventas[], int total, void* result) {
    ingrediente_mas_vendido(ventas, total, (char*)result);
}


void wrap_cantidad_pizzas_por_categoria(Venta ventas[], int total, void* result) {
    int categorias[4] = {0}; // Assuming 4 categories: Classic, Veggie, Specialty, Other
    cantidad_pizzas_por_categoria(ventas, total, categorias);
    snprintf((char*)result, 50, "Classic: %d, Veggie: %d, Specialty: %d, Other: %d", categorias[0], categorias[1], categorias[2], categorias[3]);
}

// List of supported metrics
Metric metrics[] = {
    {"pms", wrap_pizza_mas_vendida, "Most sold pizza"},
    {"pls", wrap_pizza_menos_vendida, "Least sold pizza"},
    {"dms", wrap_fecha_mas_ventas_dinero, "Date with highest sales amount"},
    {"dls", wrap_fecha_menos_ventas_dinero, "Date with lowest sales amount"},
    {"dmsp", wrap_fecha_mas_ventas_cantidad, "Date with highest number of sales"},
    {"dlsp", wrap_fecha_menos_ventas_cantidad, "Date with lowest number of sales"},
    {"apo", wrap_promedio_pizzas_por_orden, "Average pizzas per order"},
    {"apd", wrap_promedio_pizzas_por_dia, "Average pizzas per day"},
    {"ims", wrap_ingrediente_mas_vendido, "Most sold ingredient"},
    {"hp", wrap_cantidad_pizzas_por_categoria, "Number of pizzas sold by category"}
};

int num_metrics = sizeof(metrics) / sizeof(metrics[0]);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <csv_file> <metric_code>...\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    Venta ventas[MAX_ENTRIES];
    int total_ventas;

    if (leer_csv(filename, ventas, &total_ventas) != 0) {
        printf("Error reading CSV file.\n");
        return 1;
    }

    for (int i = 2; i < argc; i++) {
        const char* code = argv[i];
        int found = 0;

        for (int j = 0; j < num_metrics; j++) {
            if (strcmp(code, metrics[j].code) == 0) {
                found = 1;
                char result[500] = ""; // Aumentar el tamaño del buffer
                metrics[j].func(ventas, total_ventas, result);
                printf("%s: %s: %s\n", code, metrics[j].description, result);
                break;
            }
        }

        if (!found) {
            printf("Metric code not found: %s\n", code);
        }
    }

    return 0;
}
