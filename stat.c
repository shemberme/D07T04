#include <stdio.h>
#define NMAX 10

#define square(x) ((x)*(x))

int input(int *a, int *n);
void output(int *a, int n);
void swap(int *x, int *y);
int bubble_sort(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main()
{
    int n = 0, data[NMAX];
    if (input(data, &n) == 0) {
        output(data, n);
        printf("\n");
        bubble_sort(data, n);
        output_result(max(data, n),
                      min(data, n),
                      mean(data, n),
                      variance(data, n));
    }
    return 0;
}
int input(int *a, int *n) {
    int count;
    char c;
    
    // Сначала читаем количество элементов
    if (scanf("%d", &count) != 1) {
        printf("n/a\n");
        return 1;
    }
    
    // Проверяем, что количество в допустимых пределах
    if (count <= 0 || count > NMAX) {
        printf("n/a\n");
        return 1;
    }
    
    // Проверяем следующий символ после числа
    if (scanf("%c", &c) == 1 && c != ' ' && c != '\n') {
        printf("n/a\n");
        return 1;
    }
    
    // Теперь читаем сами элементы массива
    for (int i = 0; i < count; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("n/a\n");
            return 1;
        }
        
        // Проверяем разделитель после каждого элемента
        if (i < count - 1) {
            if (scanf("%c", &c) == 1 && c != ' ') {
                printf("n/a\n");
                return 1;
            }
        }
    }
    
    // Проверяем, что после последнего элемента идет перенос строки
    if (scanf("%c", &c) == 1 && c != '\n') {
        // Если есть лишние символы - ошибка
        printf("n/a\n");
        return 1;
    }
    
    *n = count;
    return 0;
}
void output(int *a, int n) {
    for(int i = 0; i<n;i++) {
        if(i != n-1) {
            printf("%d ", a[i]);
        } else {printf("%d", a[i]);}
        
    }
}
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;

}
int bubble_sort(int *a, int n) {
    for (int i = 0; i < n-1; i++){
        for( int j = 0; j < n-i-1; j++) {
            if (a[j]> a[j +1 ] ) {
                swap(&a[j],&a[j+1]);
            }
        }
    }
    return 0;
}
int max(int *a, int n) {
    return a[n-1];
}
int min(int *a, int n) {
    return a[n-n];
}
double mean(int *a, int n) {
    double sum = 0;
    for (int i = 0; i<n;i++) {
        sum += a[i];
    } 
    return sum / n;
}
double variance(int *a, int n) {
    double mean_val = mean(a , n); 
    double sum = 0;
    for(int i = 0;i< n;i++) {
        sum += square(a[i] - mean_val);
    }
    return sum / n;
}
void output_result(int max_v,int min_v,double mean_v,double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v,min_v,mean_v,variance_v);
}
