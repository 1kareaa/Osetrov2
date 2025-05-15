#include <stdio.h>
#include "os.h" 

int main() {
    int choice;
    
    do {
        menu();
        printf("Vvesti nomer programy");
        scanf("%d", &choice);
        
        switch(choice) {
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
    } while(choice != 0);
    
    return 0;
}