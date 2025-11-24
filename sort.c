#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *n);
void swap(int *x, int *y);
int bubble_sort(int *a, int n);
void output_sorted(const int *a, int n);

int main() {
    int n = 0;
    int *data = NULL;
    
    if (input(&data, &n) != 0) {
        return 1;
    }
    
    bubble_sort(data, n);
    output_sorted(data, n);
    
    // Освобождаем память
    free(data);
    return 0;
}

int input(int **a, int *n) {
    char c;
    
    // Сначала читаем количество элементов
    if (scanf("%d", n) != 1 || *n <= 0) {
        printf("n/a");
        return 1;
    }
    
    // Выделяем память под указанное количество элементов
    *a = (int*)calloc(*n, sizeof(int));
    if (*a == NULL) {
        printf("n/a");
        return 1;
    }
    
    // Проверяем разделитель после количества
    if (scanf("%c", &c) == 1 && c != ' ' && c != '\n') {
        printf("n/a");
        free(*a);
        return 1;
    }
    
    // Теперь читаем сами элементы массива
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &(*a)[i]) != 1) {
            printf("n/a");
            free(*a);
            return 1;
        }
        
        // Проверяем разделитель после каждого элемента
        if (i < *n - 1) {
            if (scanf("%c", &c) == 1 && c != ' ') {
                printf("n/a");
                free(*a);
                return 1;
            }
        }
    }
    
    // Проверяем, что после последнего элемента идет перенос строки
    if (scanf("%c", &c) == 1 && c != '\n') {
        printf("n/a");
        free(*a);
        return 1;
    }
    
    return 0;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int bubble_sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
    return 0;
}

void output_sorted(const int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            printf("%d ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
}