// metrics.h
#ifndef METRICS_H
#define METRICS_H

#include "csv_reader.h"

typedef float (*MetricFunction)(Venta ventas[], int total);

float calcular_total(Venta ventas[], int total);
float calcular_promedio_precio(Venta ventas[], int total);
float calcular_cantidad_total(Venta ventas[], int total);

// Métricas a pedir
const char* pizza_mas_vendida(Venta ventas[], int total);
const char* pizza_menos_vendida(Venta ventas[], int total);
void fecha_mas_ventas_dinero(Venta ventas[], int total, char* fecha, float* total_dinero);
void fecha_menos_ventas_dinero(Venta ventas[], int total, char* fecha, float* total_dinero);
void fecha_mas_ventas_cantidad(Venta ventas[], int total, char* fecha, int* total_cantidad);
void fecha_menos_ventas_cantidad(Venta ventas[], int total, char* fecha, int* total_cantidad);
float promedio_pizzas_por_orden(Venta ventas[], int total);
float promedio_pizzas_por_dia(Venta ventas[], int total);
void ingrediente_mas_vendido(Venta ventas[], int total, char* ingrediente_max);
void cantidad_pizzas_por_categoria(Venta ventas[], int total, int* categorias);

#endif // METRICS_H