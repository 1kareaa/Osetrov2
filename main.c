#include <stdio.h>
#include "lab.h" 


int main() 
{
    int choice;
    int result;
    do
    {
        menu();
        printf("Vvesti nomer programy\n");
        result = scanf("%d", &choice);//проверка возвращаемого значения
        while(getchar() != '\n'); // очистка буфера при неверном вводе
        
        if(result != 1) // если ввод не был успешно преобразован в число
        {
            printf("Oshibka vvoda. Vvedite chislo.\n");
            continue; // пропускаем оставшуюся часть цикла и начинаем заново
        }
        
        switch(choice) 
        {
            case 1:
                lr1();
                break;
            case 2:
                lr2();
                break;
            case 3:
                lr3();
                break;
            case 4:
                lr4();
                break;
            case 5:
                lr5();
                break;
            case 6:
                lr6();
                break;
            case 0:
                printf("vixod...\n");
                break;
            default:
                printf("drugie cifry\n");
        }
    }
    while(choice != 0);
    
    return 0;
}
