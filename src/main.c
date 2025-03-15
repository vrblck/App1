#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_VALUES 1000

typedef double (*metric_function)(double *, int);

double mean(double *values, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += values[i];
    }
    return sum / size;
}

double max(double *values, int size) {
    double max_val = values[0];
    for (int i = 1; i < size; i++) {
        if (values[i] > max_val) {
            max_val = values[i];
        }
    }
    return max_val;
}

double min(double *values, int size) {
    double min_val = values[0];
    for (int i = 1; i < size; i++) {
        if (values[i] < min_val) {
            min_val = values[i];
        }
    }
    return min_val;
}

int read_csv(const char *filename, double *values) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error al abrir el archivo");
        return -1;
    }
    
    char line[MAX_LINE];
    int count = 0;
    while (fgets(line, sizeof(line), file) && count < MAX_VALUES) {
        values[count++] = atof(line);
    }
    
    fclose(file);
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <archivo_csv> <metrica>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    double values[MAX_VALUES];
    int size = read_csv(argv[1], values);
    if (size < 0) return EXIT_FAILURE;
    
    metric_function metric = NULL;
    
    if (strcmp(argv[2], "mean") == 0) {
        metric = mean;
    } else if (strcmp(argv[2], "max") == 0) {
        metric = max;
    } else if (strcmp(argv[2], "min") == 0) {
        metric = min;
    } else {
        fprintf(stderr, "Métrica no reconocida. Use 'mean', 'max' o 'min'.\n");
        return EXIT_FAILURE;
    }
    
    printf("Resultado: %.2f\n", metric(values, size));
    return EXIT_SUCCESS;
}