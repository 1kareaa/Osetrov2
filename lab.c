#include <stdio.h>
#include "lab.h"

void menu() 
{
    printf("\n===== Glavnoe menu =====\n");
    printf("1. Reshenie kvadratnogo uravneniya\n");
    printf("2. Vychislenie summy ryada\n");
    printf("3. Analiz stroki\n");
    printf("4. Ydalenie cifr sroki\n");
    printf("5. Suma chetnih i net\n");
    printf("6. Obnulit << AVG\n");
    printf("0. Vyxod\n");
}


void lr1() 
{
    int T = 1;
    while (T)
    {
        int p = 4;  // Уравнение x^2+4x+3 
        int q = 3;
        int x1, x2;
        printf("\n=== Reshenie uravneniya x^2 + %dx + %d ===\n", p, q);

        for(x1 = -999; x1 < 999; x1++) // Используем теормему Виета, перебираем х1 от -999 до 998, по условию(х1+х2=-р) находим х2, и среди всех вариантов находим тот, который соответствует условию(x1*x2=q)
        {
            x2 = -p - x1;
            if(x1 * x2 == q) 
            {
                printf("Korni uravneniya: x1 = %d, x2 = %d\n", x1, x2);
                break;
           }
        }
        printf("1 (povtor)                 0 (vyxod)   \n"); //остаться или уйти в меню
        scanf("%d", &T);
        while (getchar() != '\n'); // очистка буфера
        } 
    }   

void lr2() 
{
    int T = 1;
    while(T)
    {
        int N;
        printf("\n=== Vychislenie summy ryada ===\n");
        printf("Vvedite kolichestvo elementov N = ");
        scanf("%d", &N);
        
        double sum = 0.0; //итговая сумма
        double a = 1.0; //счетчик элемента
        int numerator = 1;           //числитель
        int denominator = 1;         //знаменатель
        for(int i = 1; i <= N; i++) 
        {
            numerator *= (2 * i + 1);
            denominator *= (3 * i + 1);
            sum += a;
            a = (double)numerator / denominator; //переводим числитель и знаменатель в дабл потому что их частное может быть со знаками после запятой
        }
        printf("Summa pervyh %d elementov ryada: %.15f\n", N, sum); //выводим результат до 15 знака после запятой (включительно)
        printf("1 (povtor)                 0 (vyxod)   \n"); //остаться или уйти в меню
        scanf("%d", &T);
        while (getchar() != '\n'); // очистка буфера
    }
}

void lr3() 
{
    int T = 1;
    while(T)
    {
        printf("\n=== Analiz stroki na slova odinakovoj dliny ===\n");
        printf("Vvedite stroku: ");
        
        int len = 0, first_len = 0; //кол во букв
        char c, prev = ' '; //текущий и предыдущий символы
        int words_equal = 1; //флаг
        int word_count = 0;
        
        while((c = getchar()) != '\n') //пока не будет пробела 
        {
            if(c != ' ') 
            {
                len++; //счетчик букв
            }
            else if(prev != ' ') //если перед буквой был пробел - значит слово закончилсь, считаем его
            {
                word_count++; //счетчик слов
                if(!first_len) //если 1го слова нет
                {
                    first_len = len;//ставим значение длины в значени длины первого слова
                }
                else if(len != first_len)
                {
                    words_equal = 0; //флаг
                    // Можно сразу выйти из цикла при обнаружении разной длины
                    break;
                }
                len = 0;
            }
            prev = c;
        }
        
        // Проверка последнего слова (если строка не заканчивается пробелом)
        if(len > 0) 
        {
            word_count++;
            if(!first_len) {
                first_len = len;
            }
            else if(len != first_len) {
                words_equal = 0; //флаг
            }
        }
        

        if(word_count == 0)     // вывод результатов
        {
            printf("Stroka ne soderzhit slov\n");
        }
        else if(word_count == 1)  
        {
            printf("V stroke odno slovo ");
        }
        else 
        {
            printf(words_equal ? "Slova odinakovoj dlina \n" : "Slova imeyut raznuyu dlinu\n"); //если флаг = 1 слова одинаковой длины, если 0 то нет
        }
        
        printf("1 (povtor)                 0 (vyxod)   \n"); //остаться или уйти в меню
        scanf("%d", &T);
        while (getchar() != '\n'); // очистка буфера
    }
}

void lr4() 
{
    int T = 1;
    char text[1000];
    char result[1000];
    int i, j = 0;
    while(T)
    {   
        j = 0;
        printf("\n=== Ydalenie cifr v stoke ===\n");
        printf("Vvedite stroku: ");
        fgets(text, sizeof(text), stdin); // читаем строку с клавиатуры
        for (i = 0; text[i] != '\0'; i++)  // проходим по каждому символу строки
        {
            if (text[i] < '0' || text[i] > '9')   // если символ НЕ цифра (проверяем по ASCII кодам)
            {
                result[j] = text[i]; // rопируем символ во 2й массив (цифры не копируются)
                j++; //счётчик для массива результата
            }
        }
        result[j] = '\0'; // добавляем конец строки}
    
        printf("Stroka bez cifr: %s\n", result);
        printf("1 (povtor)                 0 (vyxod)   \n"); //остаться или уйти в меню
        scanf("%d", &T);
        while (getchar() != '\n'); // очистка буфера
    }

}

void lr5() 
{
    int T = 1;
    while(T)
    {   
        printf("\n=== Obnulenie chisel s men'shim AVG  ===\n");
        int arr[10]; 
        int sum_even = 0, sum_odd = 0;
        int SIZE = 10;
        int i;
        printf("Vvedite %d chisel:\n", SIZE);
        for (i = 0; i < SIZE; i++) 
        {
            scanf("%d", &arr[i]);
        }
        while (getchar() != '\n')

        for (i = 0; i < 10; i++)      // вычисляем суммы элементов с четными и нечетными индексами
        {
            if (i % 2 == 0) //если остаток от деления на 2 = 0
            {
                sum_even += arr[i]; // считаем четные индексы
            } else {
                sum_odd += arr[i];  // считаем нечетные индексы
            }
        }

        printf("suma chetnih: %d\n", sum_even);
        printf("suma nechetnih: %d\n", sum_odd);

        if (sum_odd < sum_even) // обнуляем элементы в зависимости от сравнения сумм
        {
            for (i = 0; i < 10; i++) // обнуляем элементы с нечетными индексами
            {
                if (i % 2 != 0) 
                {
                    arr[i] = 0;
                }
            }
        } else 
        {
            for (i = 0; i < 10; i++)      // обнуляем элементы с четными индексами
            {
                if (i % 2 == 0) 
                {
                    arr[i] = 0;
                }
            }
        }

        printf("new massiv:\n");    // вывод измененного массива
        for (i = 0; i < 10; i++) 
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("1 (povtor)                 0 (vyxod)   \n"); //остаться или уйти в меню
        scanf("%d", &T);
        while (getchar() != '\n'); // очистка буфера
    }
}
void lr6() 
{
    int T = 1;
    while(T)
    {
        printf("\n=== Obnulenie stroki s avg men'she obshego  ===\n");
        int N;
        int K;
        printf("Vvedite N i K\n N - kol-vo strok\n K - kol-vo stolbcov\n");
        printf("N=");
        scanf("%d", &N);
        printf("K=");
        scanf("%d", &K);

        int arr[N][K];
        int i, j;
        double total_sum = 0.0;
        double total_avg;

        printf("Vvesti masiv %d x %d:\n", N, K);  // ввод массива с клавиатуры
        for (i = 0; i < N; i++) 
        {
            for (j = 0; j < K; j++) {
                scanf("%d", &arr[i][j]);
                total_sum += arr[i][j]; //сразу считаем ссуму всех элементов для общего среднего
            }
        }
        
        total_avg = total_sum / (N * K);    // вычисление общего среднего
        printf("avg massiva: %.2f\n", total_avg);

        for (i = 0; i < N; i++)  // вычисление среднего для каждой строки
        {
            double row_sum = 0.0;
            double row_avg;

        
            for (j = 0; j < K; j++)   // считаем сумму элементов строки
            {
                row_sum += arr[i][j];
            }

            row_avg = row_sum / K;
            printf("avg stroki %d: %.2f\n", i, row_avg);

            if (row_avg < total_avg)  // если среднее строки меньше общего среднего — обнуляем строку
            {
                for (j = 0; j < K; j++) 
                {
                    arr[i][j] = 0;
                }
            }
        }

        printf("Rezultat bez dop zadania:\n"); // вывод измененного массива
        for (i = 0; i < N; i++) 
        {
            for (j = 0; j < K; j++) 
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    
        printf("Rezultat transponirovannoy matricy:\n");
        for (j = 0; j < K; j++) 
        {
            for (i = 0; i < N; i++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        printf("1 (povtor)                 0 (vyxod)   \n"); //остаться или уйти в меню
        scanf("%d", &T);
        while (getchar() != '\n'); // очистка буфера
    }
}
