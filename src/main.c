// main.c
#include <stdio.h>
#include "include\csv_reader.h"
#include "include\metrics.h"

#define MAX_ENTRIES 100

// Estructura para mapear códigos de métricas a funciones y descripciones
typedef struct {
    const char* code;              // Código de la métrica (ej. "pms")
    void (*func)(Venta[], int, void*); // Función que calcula la métrica
    const char* description;       // Descripción para la salida
} Metric;

// Wrappers para las funciones de metrics.c
void wrap_pizza_mas_vendida(Venta ventas[], int total, void* result) {
    *(const char**)result = pizza_mas_vendida(ventas, total);
}

void wrap_pizza_menos_vendida(Venta ventas[], int total, void* result) {
    *(const char**)result = pizza_menos_vendida(ventas, total);
}

// Lista de métricas soportadas
Metric metrics[] = {
    {"pms", wrap_pizza_mas_vendida, "Pizza mas vendida"},
    {"pls", wrap_pizza_menos_vendida, "Pizza menos vendida"},
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

    // Procesar cada código de métrica proporcionado
    for (int i = 2; i < argc; i++) {
        const char* code = argv[i];
        int found = 0;

        // Buscar la métrica en la lista
        for (int j = 0; j < num_metrics; j++) {
            if (strcmp(code, metrics[j].code) == 0) {
                found = 1;
                const char* result;
                // Llamar a la función correspondiente y obtener el resultado
                metrics[j].func(ventas, total_ventas, &result);
                // Imprimir el resultado
                printf("%s: %s\n", metrics[j].description, result ? result : "N/A");
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