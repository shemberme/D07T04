#include <stdio.h>
#include <math.h>
#define NMAX 30

#define square(x) ((x)*(x))

// Прототипы функций
int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int search(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        printf("%d", search(data, n));
    } else {
        printf("n/a");
    }
    return 0;
}

// Ввод массива с проверкой лишних символов
int input(int *a, int *n) {
    char next_char;
    
    // Читаем количество элементов
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        return 1;
    }
    
    // Читаем элементы массива
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }
    
    // Проверяем, что после последнего элемента нет лишних символов
    // кроме пробела или переноса строки
    if (scanf("%c", &next_char) == 1) {
        if (next_char != ' ' && next_char != '\n') {
            return 1; // Найден лишний символ
        }
    }
    
    return 0;
}

// Математическое ожидание
double mean(int *a, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

// Дисперсия (смещенная)
double variance(int *a, int n) {
    double mean_val = mean(a, n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += square(a[i] - mean_val);
    }
    return sum / n;
}

// Поиск числа по критериям
int search(int *a, int n) {
    double mean_val = mean(a, n);
    double std_dev = sqrt(variance(a, n)); // Стандартное отклонение
    
    for (int i = 0; i < n; i++) {
        int x = a[i];
        // Проверяем все условия:
        // 1. Чётное, 2. ≥ мат.ожидания, 3. Правило 3-х сигм, 4. Не 0
        if (x % 2 == 0 && 
            x >= mean_val && 
            fabs(x - mean_val) <= 3 * std_dev && 
            x != 0) {
            return x; // Первое подходящее число
        }
    }
    return 0; // Если ничего не найдено
}