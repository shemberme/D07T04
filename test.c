#include <stdio.h>
#include <ncurses.h>

#define WIDTH 80
#define HEIGHT 25

void input_matrix(char matrix[HEIGHT][WIDTH]); // отрисовка матрицы
int new_change_speed(char key, int *end_game, int time_sec); // изменение скорости
void init_ncurses(); // инициализация нкурсес



int main(void) {
    char matrix1[HEIGHT][WIDTH];
    input_matrix(matrix1);
    int time_milisec = 11; // начальная скорость
    int end_game = 1; // игра продолжается пока 1
    while (end_game == 1) {
        clear(); //перед началом отрисовки очищаем экран

        initscr();
        
        endwin();
    }
}
int new_change_speed(char key, int *end_game, int time_sec) {
    // увеличение/уменьшение скорости/завершение игры
    if (key == 'a' && time_sec > 1) {
        time_sec = time_sec - 1; // если кнопка 'a' и время больше 1 уменьшаем задержку
    } else if (key == 'z' && time_sec < 20) {
        time_sec = time_sec + 1; // если кнопка 'z' и время меньше 20 увеличиваем задержку
    } else if (key == ' ') { // нажата пробел - завершаем игру
        *end_game = 0; // меняем флаг по указателю на 0
    }
    return time_sec; // возвращаем новое время задержки
}
void init_ncurses() {
    freopen("/dev/tty", "r", stdin);
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
}