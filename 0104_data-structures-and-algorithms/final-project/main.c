#include <stdio.h>
#include <stdlib.h>

int displayOptions(char *menuOptions[], int menuOptionsSize, char *header);
void linearDataStructuresMenu(void);
void arraysMenu(void);
void linkedListsMenu(void);
void linkedListsTraverseMenu(void);
void linkedListsInsertMenu(void);
void linkedListsDeleteMenu(void);
void linkedListsSearchMenu(void);
void linkedListsReverseMenu(void);
void linkedListsMergeMenu(void);

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

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Main Menu");

    switch (selectedOption) {
        case 1:
            linearDataStructuresMenu();
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

int displayOptions(char *menuOptions[], int menuOptionsSize, char *header) {
    int selectedOption = 0;
    
    do {
        printf("\n%s", header);
        for (int i = 0; i < menuOptionsSize; i++) {
            printf("\n%d) %s", i+1, menuOptions[i]);
        }
        printf("\nPlease choose an option: ");
        scanf("%d", &selectedOption);
    } while(selectedOption <= 0 || selectedOption > menuOptionsSize);

    return selectedOption;
}

void linearDataStructuresMenu(void) {
    char *menuOptions[] = {
        "Arrays",
        "Linked Lists",
        "Stacks",
        "Queues",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Linear Data Structures");

    switch (selectedOption) {
        case 1:
            arraysMenu();
            break;
        case 2:
            linkedListsMenu();
        case 5:
            main();
        default:
            break;
    }
}

void arraysMenu(void) {
    char *menuOptions[] = {
        "Traverse",
        "Insert",
        "Delete",
        "Search",
        "Sort",
        "Merge 2 arrays",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Arrays");

    switch(selectedOption) {
        case 7:
            linearDataStructuresMenu();
        default:
            break;
    }
}

void linkedListsMenu(void) {
    char *menuOptions[] = {
        "Traverse",
        "Insert",
        "Delete",
        "Search",
        "Reverse",
        "Merge 2 lists",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Linked Lists");

   switch (selectedOption) {
        case 1:
            linkedListsTraverseMenu();
            break;
        case 2:
            linkedListsInsertMenu();
            break;
        case 3:
            linkedListsDeleteMenu();
            break;
        case 4:
            linkedListsSearchMenu();
            break;
        case 5:
            linkedListsReverseMenu();
            break;
        case 6:
            linkedListsMergeMenu();
            break;
        case 7:
            linearDataStructuresMenu();
        default:
            break;
    }
}
void linkedListsTraverseMenu(void) {
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Linked List - Traverse");

    printf("Selected: %d", selectedOption);
}
void linkedListsInsertMenu(void) {
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Linked List - Insert");

    printf("Selected: %d", selectedOption);
}
void linkedListsDeleteMenu(void){
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Linked List - Delete");

    printf("Selected: %d", selectedOption);
}
void linkedListsSearchMenu(void) {
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Linked List - Search");

    printf("Selected: %d", selectedOption);
}
void linkedListsReverseMenu(void) {
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Linked List - Reverse");

    printf("Selected: %d", selectedOption);
}
void linkedListsMergeMenu(void) {
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Linked List - Merge");

    printf("Selected: %d", selectedOption);
}
