#include <stdio.h>
#include <stdlib.h>

int displayOptions(char *menuOptions[], int menuOptionsSize);
void linearDataStructures(void);
void arrays(void);

int main(void) {
    char *menuOptions[] = {
        "Linear Data Structures", 
        "Non-Linear Data Structures", 
        "Strings", 
        "?",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    switch (selectedOption)
    {
    case 1:
        linearDataStructures();
        break;
    
    default:
        break;
    }

    return 0;
}

int displayOptions(char *menuOptions[], int menuOptionsSize) {
    int selectedOption = 0;

    do {
        for (int i = 0; i < menuOptionsSize; i++) {
            printf("\n%d) %s", i+1, menuOptions[i]);
        }
        printf("\nPlease choose an option: ");
        scanf("%d", &selectedOption);
    } while(selectedOption <= 0 || selectedOption > menuOptionsSize);

    return selectedOption;
}

void linearDataStructures(void) {
    char *menuOptions[] = {
        "Array",
        "Linked List",
        "Stacks",
        "Queues",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    printf("Selected: %d", selectedOption);
}