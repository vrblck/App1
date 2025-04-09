// csv_reader.h
#ifndef CSV_READER_H
#define CSV_READER_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1024

// Declaración de la función para contar líneas en el CSV
int contar_lineas_csv(const char* filename);

// Define dinámico para MAX_ENTRIES
#define MAX_ENTRIES contar_lineas_csv("data/ventas.csv")

typedef struct {
    float pizza_id;              // ID de la pizza (puede tener decimales)
    float order_id;              // ID del pedido (puede tener decimales)
    char pizza_name_id[50];      // ID del nombre de la pizza
    float quantity;              // Cantidad vendida (puede tener decimales)
    char order_date[11];         // Fecha del pedido (formato: dd/mm/yyyy)
    char order_time[9];          // Hora del pedido (formato: hh:mm:ss)
    float unit_price;            // Precio unitario
    float total_price;           // Precio total
    char pizza_size[2];          // Tamaño de la pizza (S, M, L, etc.)
    char pizza_category[20];     // Categoría de la pizza (Classic, Veggie, etc.)
    char pizza_ingredients[200]; // Ingredientes de la pizza
    char pizza_name[50];         // Nombre de la pizza
} Venta;

int leer_csv(const char* filename, Venta ventas[], int* total_ventas);

#endif // CSV_READER_H