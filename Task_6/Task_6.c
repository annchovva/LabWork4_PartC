#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("-Главное меню-\n");
    printf("Задание 6.\n");
    printf("Память для массива выделить динамически\n");
    printf("Построить магический квадрат.\n");
    printf("Порядок квадрата задается пользователем\n");
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
    long long i, j, n;
    printf("Введите порядок магического квадрата:\n");
    printf("n = ");
    while (scanf("%lld", &n) != 1 || getchar() != '\n' || n <= 0) {
        printf("Введите целое положительное число!\n");
        printf("n = ");
        while (getchar() != '\n'); 
    }

    long long **magic = (long long**)malloc((n) * sizeof(long long *));
        for (i = 0; i < n; i++) {
            magic[i] = (long long *)malloc((n) * sizeof(long long));
            for (j = 0; j < n; j++){
                magic[i][j]=0;
            }
        }    
    //нечетного порядка
    if (n % 2) {
        
        int row = 0, col = n / 2;
        for (int num = 1; num <= n * n; num++) {
            magic[row][col] = num;
            int new_row = (row - 1 + n) % n;
            int new_col = (col + 1) % n;
            if (magic[new_row][new_col] != 0) {
                row = (row + 1) % n;
            } else {
                row = new_row;
                col = new_col;
            }
        }
        printf("Полученный магический квадрат:\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf(" %lld\t", magic[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    else if (n == 2) {
        printf("Магического квадрата с заданным порядком не существует!");
    }
    //четного порядка
    else {     
        //делится на 2 
        if ((n - 2) % 4 == 0) {
            long long k = (n - 2) / 4, num = 0;
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++){
                    magic[i][j] = -2;
                }
            }
            for (i = 0; i < n; i++) {
                magic[i][i] = -1;
                magic[i][n - 1 - i] = -1;
            }        
            for (i = 0; i < 2 * k; i++) {
                for (j = i; j < 2 * k; j++){
                    magic[i][j + 1] = -3;
                    magic[i][n - j - 2] = -3;
                    magic[n - 1 - i][j + 1] = -3;
                    magic[n - 1 - i][n - j - 2] = -3;
                }
            }
            for (i = 0; i < k + 1; i++) {
                for (j = i; j < 2 * k + 1 - i; j++) {
                    magic[k + j][i] = -4;
                    magic[k + j][n - 1 - i] = -4;
                    magic[i][k + j] = -4;
                    magic[n - 1 - i][k + j] = -4;
                }
            }
            for (i = 0; i < k; i++){
                for (j = i; j < k; j++) {
                    magic[k + 1 + j][i] = -3;
                    magic[n - k - 2 - j][i] = -3;
                    magic[i][k + 1 + j] = -2;
                    magic[i][n - k - 2 - j] = -2;
                }
            }
            for (i = 0; i < k - 1; i++){
                for (j = i; j < k - 1; j++) {
                    magic[k + 2 + j][n - 1 - i] = -3;
                    magic[n - k - 3 - j][n - 1 - i] = -3;
                    magic[n - 1 - i][k + 2 + j] = -2;
                    magic[n - 1 - i][n - k - 3 - j] = -2;
                }
            }
            for (i = 0; i < n; i++){
                for (j = 0; j < n; j++){
                    num++;
                    if (magic[j][i] == -1){
                        magic[j][i] = num;
                    }
                    if (magic[n - 1 - j][i] == -2){
                        magic[n - 1 - j][i] = num;
                    }
                    if (magic[j][n - 1 - i] == -3){
                        magic[j][n - 1 - i] = num;
                    }
                    if (magic[n - 1 - j][n - 1 - i] == -4){
                        magic[n - 1 - j][n - 1 - i] = num;
                    }
                }
            }  
        }    
        //делится на 4
        else if (n % 4 == 0) {
            int k = n / 4, num = 0;
                for (i = 0; i < n; i++){
                    for (j = 0; j < n; j++){
                        magic[i][j] = i * n + j + 1;
                    }
                }
                for (i = 0; i < k; i++){
                    for (j = 0; j < k; j++){
                        for (long long g = 0; g < 4; g++){
                            magic[4 * i + g][(j * 4) + g] = 0;
                            magic[(i + 1) * 4 - g - 1][(j * 4) + g] = 0;
                        }
                    }
                }      
                for (i = n - 1; i >= 0; i--){
                    for (j = n - 1; j >= 0; j--){
                        num++;
                        if (magic[i][j] == 0){
                                magic[i][j] = num;
                        } 
                    }
                }   
            }
        printf("Полученный магический квадрат:\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf(" %lld\t", magic[i][j]);
            }
            printf("\n");
        }
        printf("\n");           
    }

    for (int i = 0; i < n ; i++) {   
        free(magic[i]);  
    }
    free(magic);
    magic = NULL;
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