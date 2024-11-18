#include <stdio.h>
#include <stdlib.h>

int displayOptions(char *menuOptions[], int menuOptionsSize, char *header);
void linearDataStructures(void);
void arrays(void);
void linkedLists(void);
void linkedListsTraverse(void);
void linkedListsInsert(void);
void linkedListsDelete(void);
void linkedListsSearch(void);
void linkedListsReverse(void);
void linkedListsMerge(void);

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

int displayOptions(char *menuOptions[], int menuOptionsSize, char *header) {
    int selectedOption = 0;

    printf("\n%s", header);

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

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Linear Data Structures");

    switch (selectedOption) {
        case 1:
            arrays();
            break;
        case 2:
            linkedLists();
        case 5:
            main();
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
        "Merge 2 arrays",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Arrays");

    switch(selectedOption) {
        case 7:
            linearDataStructures();
        default:
            break;
    }
}

void linkedLists(void) {
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
            linkedListsTraverse();
            break;
        case 2:
            linkedListsInsert();
            break;
        case 3:
            linkedListsDelete();
            break;
        case 4:
            linkedListsSearch();
            break;
        case 5:
            linkedListsReverse();
            break;
        case 6:
            linkedListsMerge();
            break;
        case 7:
            linearDataStructures();
        default:
            break;
    }
}
void linkedListsTraverse(void) {
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Linked List - Traverse");

    printf("Selected: %d", selectedOption);
}
void linkedListsInsert(void) {
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Linked List - Insert");

    printf("Selected: %d", selectedOption);
}
void linkedListsDelete(void){
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Linked List - Delete");

    printf("Selected: %d", selectedOption);
}
void linkedListsSearch(void) {
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Linked List - Search");

    printf("Selected: %d", selectedOption);
}
void linkedListsReverse(void) {
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Linked List - Reverse");

    printf("Selected: %d", selectedOption);
}
void linkedListsMerge(void) {
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Linked List - Merge");

    printf("Selected: %d", selectedOption);
}
