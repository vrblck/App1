// metrics.c
#include "include/metrics.h"
#include <string.h>

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
    int total_quantity = 0;
    for (int i = 0; i < total; i++) {
        total_quantity += ventas[i].quantity;
    }
    return total_quantity == 0 ? 0.0 : total_price / total_quantity;
}

float calcular_cantidad_total(Venta ventas[], int total) {
    int sum = 0;
    for (int i = 0; i < total; i++) {
        sum += ventas[i].quantity;
    }
    return (float)sum; // Retorna float para consistencia con MetricFunction
}

const char* pizza_mas_vendida(Venta ventas[], int total) {
    // Implementación de la métrica
    // ...
}

const char* pizza_menos_vendida(Venta ventas[], int total) {
    // Implementación de la métrica
    // ...
}

void fecha_mas_ventas_dinero(Venta ventas[], int total, char* fecha, float* total_dinero) {
    // Implementación de la métrica
    // ...
}

void fecha_menos_ventas_dinero(Venta ventas[], int total, char* fecha, float* total_dinero) {
    // Implementación de la métrica
    // ...
}

void fecha_mas_ventas_cantidad(Venta ventas[], int total, char* fecha, int* total_cantidad) {
    // Implementación de la métrica
    // ...
}

void fecha_menos_ventas_cantidad(Venta ventas[], int total, char* fecha, int* total_cantidad) {
    // Implementación de la métrica
    // ...
}

float promedio_pizzas_por_orden(Venta ventas[], int total) {
    // Implementación de la métrica
    // ...
}

float promedio_pizzas_por_dia(Venta ventas[], int total) {
    // Implementación de la métrica
    // ...
}

const char* ingrediente_mas_vendido(Venta ventas[], int total) {
    // Implementación de la métrica
    // ...
}

void cantidad_pizzas_por_categoria(Venta ventas[], int total, int* categorias) {
    // Implementación de la métrica
    // ...
}