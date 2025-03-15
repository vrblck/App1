// csv_reader.h
#ifndef CSV_READER_H
#define CSV_READER_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1024
#define MAX_ENTRIES 100

typedef struct {
    int pizza_id;
    int order_id;
    char pizza_name_id[50];	
    int quantity;
    char order_date[11];
    char order_time[9];
    float unit_price;
    float total_price;
    char pizza_size[2];
    char pizza_category[20];
    char pizza_ingredients[100];
    char pizza_name[50];

} Venta;

int leer_csv(const char *filename, Venta ventas[], int *total_ventas);

#endif // CSV_READER_H