#include <stdio.h>
#include "lab.h" 


int main() 
{
    int choice;
    
    do
    {
        menu();
        printf("Vvesti nomer programy\n");
        scanf("%d", &choice);
        getchar(); //гечар тут забирает символ чтобы он не ушел в lr1, lr2 итд
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
        }
    } while(choice != 0);
    
    return 0;
}
