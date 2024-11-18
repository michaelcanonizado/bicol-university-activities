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
        "Sorting",
        "Searching",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    switch (selectedOption) {
        case 1:
            linearDataStructures();
            break;
        case 6:
            printf("\nClosing Program...");
            printf("\nGood Bye!");
            return 0;
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
        "Arrays",
        "Linked Lists",
        "Stacks",
        "Queues",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    switch (selectedOption) {
        case 1:
            arrays();
            break;
    
        default:
            break;
    }
}

void arrays(void) {
    char *menuOptions[] = {
        "Traverse",
        "Insert",
        "Delete",
        "Search",
        "Sort",
        "Merge",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    printf("Selected: %d", selectedOption);
}