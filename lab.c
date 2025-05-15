#include <stdio.h>
#include "lab.h"

void menu() {
    printf("\n===== Glavnoe menu =====\n");
    printf("1. Reshenie kvadratnogo uravneniya\n");
    printf("2. Vychislenie summy ryada\n");
    printf("3. Analiz stroki\n");
    printf("4. Ydalenie cifr sroki\n");
    printf("5. Suma chetnih i net\n");
    printf("6. Obnulit << AVG\n");
    printf("0. Vyxod\n");
}

void lr1() {
    int p = 4;
    int q = 3;
    int x1, x2;
    int found = 0;
    
    printf("\n=== Reshenie uravneniya x^2 + %dx + %d ===\n", p, q);
    
    for(x1 = -999; x1 < 999; x1++) {
        x2 = -p - x1;
        if(x1 * x2 == q) {
            printf("Korni uravneniya: x1 = %d, x2 = %d\n", x1, x2);
            found = 1;
            break;
        }
    }
    getchar();
    getchar();
}

void lr2() {
    int N;
    printf("\n=== Vychislenie summy ryada ===\n");
    printf("Vvedite kolichestvo elementov N: ");
    scanf("%d", &N);
    
    double sum = 1.0;
    double a = 1.0;
    
    for(int i = 2; i <= N; ++i) {
        a *= (2.0 * i - 1) / (3 * i - 2);
        sum += a;
    }
    
    printf("Summa pervyh %d elementov ryada: %.15f\n", N, sum);
    getchar();
    getchar();
}

void lr3() {
    printf("\n=== Analiz stroki ===\n");
    printf("Vvedite stroku: ");
    
    // Очистка буфера ввода перед чтением строки
    while(getchar() != '\n');
    
    int len = 0, first_len = 0;
    char c, prev = ' ';
    int words_equal = 1;
    int word_count = 0;
    
    while((c = getchar()) != '\n' && c != EOF) {
        if(c != ' ') {
            len++;
        }
        else if(prev != ' ') {
            word_count++;
            if(!first_len) {
                first_len = len;
            }
            else if(len != first_len) {
                words_equal = 0;
                // Можно сразу выйти из цикла при обнаружении разной длины
                break;
            }
            len = 0;
        }
        prev = c;
    }
    
    // Проверка последнего слова (если строка не заканчивается пробелом)
    if(len > 0) {
        word_count++;
        if(!first_len) {
            first_len = len;
        }
        else if(len != first_len) {
            words_equal = 0;
        }
    }
    
    // Вывод результатов
    if(word_count == 0) {
        printf("Stroka ne soderzhit slov\n");
    }
    else if(word_count == 1) {
        printf("V stroke odno slovo ");
    }
    else {
        printf(words_equal ? "slova odinakovoj dlina \n" : "Slova imeyut raznuyu dlinu\n");
    }
    getchar();
    getchar();
}

void lr4() {
    char text[1000];  // Массив для хранения строки
    char result[1000]; // Массив для результата без цифр
    int i, j = 0;     // Счётчики для циклов

    printf("Vvedite stroku: ");
    getchar();
    fgets(text, sizeof(text), stdin); // Читаем строку с клавиатуры

    // Проходим по каждому символу строки
    for (i = 0; text[i] != '\0'; i++) {
        // Если символ НЕ цифра (проверяем по ASCII кодам)
        if (text[i] < '0' || text[i] > '9') {
            result[j] = text[i]; // Копируем символ в результат
            j++; // Увеличиваем счётчик для массива результата
        }
    }
    result[j] = '\0'; // Добавляем конец строки

    printf("Stroka bez cifr: %s\n", result);
    getchar();
    getchar();
}

void lr5() {

    int arr[10]; // Пример массива
    int sum_even = 0, sum_odd = 0;
    int SIZE = 10;
    int i;
      printf("Vvedite %d chisel:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    // Вычисляем суммы элементов с четными и нечетными индексами
    for (i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            sum_even += arr[i]; // Четные индексы (0, 2, 4...)
        } else {
            sum_odd += arr[i];  // Нечетные индексы (1, 3, 5...)
        }
    }

    printf("suma chetnih: %d\n", sum_even);
    printf("suma nechetnih: %d\n", sum_odd);

    // Обнуляем элементы в зависимости от сравнения сумм
    if (sum_odd < sum_even) {
        // Обнуляем элементы с нечетными индексами
        for (i = 0; i < 10; i++) {
            if (i % 2 != 0) {
                arr[i] = 0;
            }
        }
    } else {
        // Обнуляем элементы с четными индексами
        for (i = 0; i < 10; i++) {
            if (i % 2 == 0) {
                arr[i] = 0;
            }
        }
    }

    // Выводим измененный массив
    printf("new massiv:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    getchar();
    getchar();
}

void lr6() {
    
    int N;
    int K;
    printf("Vvedite N i K\n N - kol-vo strok\n K - kol-vo stolbcov");
    printf("N=");
    scanf("%d", &N);
    printf("K=");
    scanf("%d", &K);

    int arr[N][K];
    int i, j;
    double total_sum = 0.0;
    double total_avg;

    // Ввод массива с клавиатуры
    printf("Vvesti masiv %d x %d:\n", N, K);
    for (i = 0; i < N; i++) {
        for (j = 0; j < K; j++) {
            scanf("%d", &arr[i][j]);
            total_sum += arr[i][j];
        }
    }

    // Вычисление общего среднего
    total_avg = total_sum / (N * K);
    printf("avg massiva: %.2f\n", total_avg);
    // Вычисление среднего для каждой строки
    for (i = 0; i < N; i++) {
        double row_sum = 0.0;
        double row_avg;

        // Считаем сумму элементов строки
        for (j = 0; j < K; j++) {
            row_sum += arr[i][j];
        }

        row_avg = row_sum / K;
        printf("avg stroki %d: %.2f\n", i, row_avg);

        // Если среднее строки меньше общего среднего — обнуляем строку
        if (row_avg < total_avg) {
            for (j = 0; j < K; j++) {
                arr[i][j] = 0;
            }
            printf("stroka %d obnulena\n", i);
        }
    }

    // Вывод измененного массива
    printf("Rezultat:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < K; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    getchar();
    getchar();
}