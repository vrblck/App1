// main.c
#include <stdio.h>
#include <string.h>
#include "csv_reader.h"
#include "metrics.h"

#define MAX_ENTRIES 100

// Estructura para mapear códigos de métricas a funciones y descripciones
typedef struct {
    const char* code;              // Código de la métrica (ej. "pms")
    void (*func)(Venta[], int, void*); // Función que calcula la métrica
    const char* description;       // Descripción para la salida
} Metric;

// Wrappers for metrics
void wrap_pizza_mas_vendida(Venta ventas[], int total, void* result) {
    const char* pizza = pizza_mas_vendida(ventas, total);
    snprintf((char*)result, 50, "%s", pizza); // Copy the string into the result buffer
}

void wrap_pizza_menos_vendida(Venta ventas[], int total, void* result) {
    const char* pizza = pizza_menos_vendida(ventas, total);
    snprintf((char*)result, 50, "%s", pizza); // Copy the string into the result buffer
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
    const char* ingrediente = ingrediente_mas_vendido(ventas, total);
    snprintf((char*)result, 50, "%s", ingrediente ? ingrediente : "N/A");
}

// Lista de métricas soportadas
Metric metrics[] = {
    {"pms", wrap_pizza_mas_vendida, "Pizza más vendida"},
    {"pls", wrap_pizza_menos_vendida, "Pizza menos vendida"},
    {"fmd", wrap_fecha_mas_ventas_dinero, "Fecha con mayor monto de ventas"},
    {"fnd", wrap_fecha_menos_ventas_dinero, "Fecha con menor monto de ventas"},
    {"fmc", wrap_fecha_mas_ventas_cantidad, "Fecha con mayor cantidad de ventas"},
    {"fnc", wrap_fecha_menos_ventas_cantidad, "Fecha con menor cantidad de ventas"},
    {"ppo", wrap_promedio_pizzas_por_orden, "Promedio de pizzas por orden"},
    {"ppd", wrap_promedio_pizzas_por_dia, "Promedio de pizzas por día"},
    {"imv", wrap_ingrediente_mas_vendido, "Ingrediente más vendido"},
    // Puedes agregar más métricas aquí
};

int num_metrics = sizeof(metrics) / sizeof(metrics[0]);

int main(int argc, char* argv[]) {
    // Validar que se proporcionen al menos el archivo y una métrica
    if (argc < 3) {
        printf("Uso: %s <archivo.csv> <codigo_metrica1> [codigo_metrica2] ...\n", argv[0]);
        return 1;
    }

    // Obtener el nombre del archivo CSV
    const char* filename = argv[1];
    Venta ventas[MAX_ENTRIES];
    int total_ventas = 0;

    // Leer el archivo CSV
    if (leer_csv(filename, ventas, &total_ventas) != 0) {
        printf("Error al leer el archivo CSV.\n");
        return 1;
    }
    // Debug: Print the contents of the ventas array
    

    // Procesar cada código de métrica proporcionado
    for (int i = 2; i < argc; i++) {
        const char* code = argv[i];
        int found = 0;

        // Buscar la métrica en la lista
        for (int j = 0; j < num_metrics; j++) {
            if (strcmp(code, metrics[j].code) == 0) {
                found = 1;

                // Allocate a buffer for the result
                char result[50] = {0};

                // Call the metric function
                metrics[j].func(ventas, total_ventas, result);

                // Print the result
                printf("%s: %s\n", metrics[j].description, result);
                break;
            }
        }

        // Si no se encuentra la métrica, mostrar un error
        if (!found) {
            printf("Métrica desconocida: %s\n", code);
        }
    }

    return 0;
}

