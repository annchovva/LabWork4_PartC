#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("-Главное меню-\n");
    printf("Задание 5.\n");
    printf("Память для массива выделить динамически.\n");
    printf("На вход подаётся поле для игры в 'сапёр' размером n*m символов,\n");
    printf("где символ '.' означает пустое место, а символ '*' - бомбу.\n");
    printf("Требуется дополнить это поле числами, как в оригинальной игре.\n");
    printf("Выполнила Горбачёва Анна, гр.453504\n");
    printf("1 - Результат\n");
    printf("0 - Выход\n");
}

int get_input() {
    char input;
    while (1) {
        input = getchar();
        while (getchar() != '\n'); 
        if (input == '0' || input == '1') {
            return input - '0';
        } else {
            printf("Введите 0 или 1: ");
        }
    }
}

void result() {
    int n, m, N;

    printf("Введите размеры поля: \n");
    printf("n = ");
    while (scanf("%d", &n) != 1 || getchar() != '\n' || n <= 0) {
        printf("Введите целое положительное число!\n");
        printf("n = ");
        while (getchar() != '\n'); 
    }

    printf("m = ");
    while (scanf("%d", &m) != 1 || getchar() != '\n' || m <= 0) {
        printf("Введите целое положительное число!\n");
        printf("m = ");
        while (getchar() != '\n'); 
    }

    printf("Введите количество бомб: \n");
    while (scanf("%d", &N) != 1 || getchar() != '\n' || N <= 0) {
        printf("Введите целое положительное число!\n");
        printf("n = ");
        while (getchar() != '\n'); 
    }

    char **arr = (char **)malloc(n * sizeof(char **));
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(m * sizeof(int));
    }

    for (int i = 1; i <= N; i++) {
        int pow, col;
        printf("Где находится %d бомба?\n", i);
        printf("строка: ");
        while (scanf("%d", &pow) != 1 || getchar() != '\n') {
        printf("Введите целое положительное число!\n");
        printf("строка: ");
        while (getchar() != '\n');
        }

        printf("столбец: ");
        while (scanf("%d", &col) != 1 || getchar() != '\n') {
        printf("Введите целое положительное число!\n");
        printf("столбец: ");
        while (getchar() != '\n');
        }
            if ((col > m || col < 1) || (pow > n || pow < 1)) 
            {
                printf("Координаты выходят за пределы поля, введите еще раз.\n");
                i--;
                continue;
            }

        pow -= 1; 
        col -= 1;

        arr[pow][col] = '*';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != '*') {
                arr[i][j] = '.';
            }    
            else {
                continue;
            }
        }
    }

    printf("Исходное поле: \n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf(" %c\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != '*') {
                int res = 0;
                for (int ni = i - 1; ni <= i + 1; ni++) {
                    for (int nj = j - 1; nj <= j + 1; nj++) {
                        if (ni >= 0 && ni < n &&nj >= 0 && nj < m && arr [ni][nj] == '*') {
                            res++;
                        }
                    }
                }
                if (res != 0) {
                    arr[i][j] = '0' + res;
                }        
            }
        }
    }

    printf("Итоговое поле: \n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf(" %c\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }    
    free(arr);
    arr = NULL;
}

int main() {
    while (1) {
        menu();
        printf("Выберите действие: ");
        int choice = get_input();
        if (choice == 1) {
            result();
        } else if (choice == 0) {
            printf("Вы вышли из программы.\n");
            break;
        }
        printf(".\n.\n.\n");
        printf("Желаете повторить программу? (1 - да, 0 - нет): ");
        int retry = get_input();
        if (retry == 0) {
            printf("Вы вышли из программы.\n");
            break;
        }
    }
    return 0;
}