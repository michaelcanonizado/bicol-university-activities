#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int selectedOption = 0;
    char *menuOptions[] = {
        "Linear Data Structures", 
        "Non-Linear Data Structures", 
        "Strings", 
        "?",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    do {
        for (int i = 0; i < menuOptionsSize; i++) {
            printf("\n%d) %s", i+1, menuOptions[i]);
        }
        printf("\nPlease choose an option: ");
        scanf("%d", &selectedOption);

        printf("Selected: %d", selectedOption);

    } while(selectedOption <= 0 || selectedOption > menuOptionsSize);

    return 0;
}



