#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("-Главное меню-\n");
    printf("Задание 4.\n");
    printf("Память для массива выделить динамически.\n");
    printf("Дан трёхмерный динамический массив размером n^3 целых неотрицательных чисел.\n");
    printf("Необходимо определить диагональ с наибольшей суммой чисел.\n");
    printf("Для обхода диагоналей нельзя использовать вложенные циклы.\n");
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
    int n;

    printf("Введите размерность массива: n = ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Введите целое положительное число!\n");
        printf("n = ");
        while (getchar() != '\n'); 
    }

    int ***arr = (int ***)malloc(n * sizeof(int **));
    for (int i = 0; i < n; i++) {
        arr[i] = (int **)malloc(n * sizeof(int *));
        for (int j = 0; j < n; j++) {
            arr[i][j] = (int *)malloc(n * sizeof(int));
        }
    }

    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("a[%d][%d][%d] = ", i, j, k);
                while (scanf("%d", &arr[i][j][k]) != 1 || arr[i][j][k] < 0) {
                    printf("Введите целое положительное число!\n");
                    printf("a[%d][%d][%d] = ", i, j, k);
                    while (getchar() != '\n'); 
                }
            }
        }
    }

    int d1 = 0, d2 = 0, d3 = 0, d4 = 0;

    for (int i = 0; i < n; i++) {
        d1 += arr[i][i][i];
        d2 += arr[i][n - 1 - i][i];
        d3 += arr[n - 1 - i][i][i];
        d4 += arr[n - 1 - i][n - 1 - i][i];
    }

    printf("d1 = %d\n", d1);
    printf("d2 = %d\n", d2);
    printf("d3 = %d\n", d3);
    printf("d4 = %d\n", d4);
    
    if (d1 > d2 && d1 > d3 && d1 > d4) {
        printf("Диагональ с наибольшей суммой чисел: d1\n");
    } else if (d2 > d1 && d2 > d3 && d2 > d4) {
        printf("Диагональ с наибольшей суммой чисел: d2\n");
    } else if (d3 > d1 && d3 > d2 && d3 > d4) {
        printf("Диагональ с наибольшей суммой чисел: d3\n");
    } else if (d4 > d1 && d4 > d2 && d4 > d3){
        printf("Диагональ с наибольшей суммой чисел: d4\n");
    } else if (d1 == d2 && d1 > d3 && d1 > d4) {
        printf("Диагонали с наибольшей суммой чисел: d1 и d2\n");
    } else if (d1 == d3 && d1 > d2 && d1 > d4) {
        printf("Диагонали с наибольшей суммой чисел: d1 и d3\n");
    } else if (d1 == d4 && d1 > d2 && d1 > d3) {
        printf("Диагонали с наибольшей суммой чисел: d1 и d4\n");
    } else if (d2 == d3 && d2 > d1 && d2 > d4) {
        printf("Диагонали с наибольшей суммой чисел: d2 и d3\n");
    } else if (d2 == d4 && d2 > d1 && d2 > d3) {
        printf("Диагонали с наибольшей суммой чисел: d2 и d4\n");
    } else if (d3 == d4 && d3 > d1 && d3 > d2) {
        printf("Диагонали с наибольшей суммой чисел: d3 и d4\n");
    } else if (d1 == d2 && d1 == d3 && d1 > d4) {
        printf("Диагонали с наибольшей суммой чисел: d1, d2 и d3\n");
    } else if (d1 == d2 && d1 == d4 && d1 > d3) {
        printf("Диагонали с наибольшей суммой чисел: d1, d2 и d4\n");
    } else if (d1 == d3 && d1 == d4 && d1 > d2) {
        printf("Диагонали с наибольшей суммой чисел: d1, d3 и d4\n");
    } else if (d2 == d3 && d2 == d4 && d2 > d1) {
        printf("Диагонали с наибольшей суммой чисел: d2, d3 и d4\n");
    } else if (d1 == d2 && d1 == d3 && d1 == d4) {
        printf("Сумма чисел в диагоналях равна.\n");
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            free(arr[i][j]);
        }
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