//5 Encuentra la fecha con mayor cantidad de pizzas vendidas
void fecha_mas_ventas_cantidad(Venta ventas[], int total, char* fecha, int* total_cantidad) {
    if (total == 0) {
        strcpy(fecha, "");
        *total_cantidad = 0;
        return;
    }
    typedef struct {
        char date[11];
        int total_quantity;
    } DateQuantity;
    DateQuantity date_quantities[1000] = {0};
    int num_dates = 0;

    for (int i = 0; i < total; i++) {
        char *current_date = ventas[i].order_date;
        int found = 0;
        for (int j = 0; j < num_dates; j++) {
            if (strcmp(date_quantities[j].date, current_date) == 0) {
                date_quantities[j].total_quantity += ventas[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found && num_dates < 1000) {
            strcpy(date_quantities[num_dates].date, current_date);
            date_quantities[num_dates].total_quantity = ventas[i].quantity;
            num_dates++;
        }
    }

    int max_quantity = -1;
    char max_date[11] = "";
    for (int i = 0; i < num_dates; i++) {
        if (date_quantities[i].total_quantity > max_quantity) {
            max_quantity = date_quantities[i].total_quantity;
            strcpy(max_date, date_quantities[i].date);
        }
    }
    strcpy(fecha, max_date);
    *total_cantidad = max_quantity;
}

//6 Encuentra la fecha con menor cantidad de pizzas vendidas
void fecha_menos_ventas_cantidad(Venta ventas[], int total, char* fecha, int* total_cantidad) {
    if (total == 0) {
        strcpy(fecha, "");
        *total_cantidad = 0;
        return;
    }
    typedef struct {
        char date[11];
        int total_quantity;
    } DateQuantity;
    DateQuantity date_quantities[1000] = {0};
    int num_dates = 0;

    for (int i = 0; i < total; i++) {
        char *current_date = ventas[i].order_date;
        int found = 0;
        for (int j = 0; j < num_dates; j++) {
            if (strcmp(date_quantities[j].date, current_date) == 0) {
                date_quantities[j].total_quantity += ventas[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found && num_dates < 1000) {
            strcpy(date_quantities[num_dates].date, current_date);
            date_quantities[num_dates].total_quantity = ventas[i].quantity;
            num_dates++;
        }
    }

    int min_quantity = date_quantities[0].total_quantity;
    char min_date[11] = "";
    strcpy(min_date, date_quantities[0].date);
    for (int i = 1; i < num_dates; i++) {
        if (date_quantities[i].total_quantity < min_quantity) {
            min_quantity = date_quantities[i].total_quantity;
            strcpy(min_date, date_quantities[i].date);
        }
    }
    strcpy(fecha, min_date);
    *total_cantidad = min_quantity;
}

//7 Calcula el promedio de pizzas por orden
float promedio_pizzas_por_orden(Venta ventas[], int total) {
    if (total == 0) return 0.0;
    typedef struct {
        int order_id;
        int total_quantity;
    } OrderQuantity;
    OrderQuantity order_quantities[1000] = {0};
    int num_orders = 0;

    for (int i = 0; i < total; i++) {
        int current_order_id = ventas[i].order_id;
        int found = 0;
        for (int j = 0; j < num_orders; j++) {
            if (order_quantities[j].order_id == current_order_id) {
                order_quantities[j].total_quantity += ventas[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found && num_orders < 1000) {
            order_quantities[num_orders].order_id = current_order_id;
            order_quantities[num_orders].total_quantity = ventas[i].quantity;
            num_orders++;
        }
    }

    if (num_orders == 0) return 0.0;
    int total_pizzas = 0;
    for (int i = 0; i < num_orders; i++) {
        total_pizzas += order_quantities[i].total_quantity;
    }
    return (float)total_pizzas / num_orders;
}

//8 Calcula el promedio de pizzas vendidas por día
float promedio_pizzas_por_dia(Venta ventas[], int total) {
    if (total == 0) return 0.0;
    typedef struct {
        char date[11];
        int total_quantity;
    } DateQuantity;
    DateQuantity date_quantities[1000] = {0};
    int num_dates = 0;

    for (int i = 0; i < total; i++) {
        char *current_date = ventas[i].order_date;
        int found = 0;
        for (int j = 0; j < num_dates; j++) {
            if (strcmp(date_quantities[j].date, current_date) == 0) {
                date_quantities[j].total_quantity += ventas[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found && num_dates < 1000) {
            strcpy(date_quantities[num_dates].date, current_date);
            date_quantities[num_dates].total_quantity = ventas[i].quantity;
            num_dates++;
        }
    }

    if (num_dates == 0) return 0.0;
    int total_pizzas = 0;
    for (int i = 0; i < num_dates; i++) {
        total_pizzas += date_quantities[i].total_quantity;
    }
    return (float)total_pizzas / num_dates;
}
