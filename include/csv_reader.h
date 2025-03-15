// csv_reader.h
#ifndef CSV_READER_H
#define CSV_READER_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1024
#define MAX_ENTRIES 100

typedef struct {
    int id;
    char fecha[11];
    char pizza[50];
    int cantidad;
    float precio_unitario;
} Venta;

int leer_csv(const char *filename, Venta ventas[], int *total_ventas);

#endif // CSV_READER_H