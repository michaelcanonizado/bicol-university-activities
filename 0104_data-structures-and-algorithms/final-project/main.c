#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct AllocatedArraysNode {
    int *value;
    size_t size;
    struct AllocatedArraysNode *next;
} AllocatedArraysNode;
AllocatedArraysNode *allocatedArraysHead = NULL;

int displayOptions(char *menuOptions[], int menuOptionsSize, char *header);
void getUserIntegerInputs(void);

void linearDataStructuresMenu(void);
void searchingMenu(void);

void arraysMenu(void);
void linkedListsMenu(void);
void linkedListsTraverseMenu(void);
void linkedListsInsertMenu(void);
void linkedListsDeleteMenu(void);
void linkedListsSearchMenu(void);
void linkedListsReverseMenu(void);
void linkedListsMergeMenu(void);

void linearSearchMenu(void);

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
        case 5:
            searchingMenu();
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

/* Utility Functions */
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
int isValidInteger(const char *str) {
    // Check if the string is empty
    if (*str == '\0') {
        return 0;
    }

    // Allow for an optional leading negative sign
    if (*str == '-') {
        str++; // Skip the negative sign
    }

    // Ensure all characters are digits
    while (*str) {
        if (!isdigit(*str)) {
            return 0; // Return 0 if any non-digit character is found
        }
        str++;
    }
    
    return 1;
}
void getUserIntegerInputs(void) {
    int array[5] = {0};
    char inputStr[100];
    const char delimiter[] = ","; 
    char *token;
    int numOfInputs = 0;
    int inputStrLength = 0;

    printf("\nPlease enter your inputs(integers): ");
    scanf("%s",inputStr);

    while (inputStr[inputStrLength] != '\0') {
        if ()
        inputStrLength++;
    }

    token = strtok(inputsStr, delimiter);

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delimiter);
    }
}




/* 2nd Layer Menus */
void linearDataStructuresMenu(void) {
    char *menuOptions[] = {
        "Arrays",
        "Linked Lists",
        "Stacks",
        "Queues",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Main Menu > Linear Data Structures");

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
void searchingMenu(void) {
    char *menuOptions[] = {
        "Linear Search",
        "Binary Search",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Main Menu > Searching");

    switch (selectedOption) {
        case 1:
            linearSearchMenu();
        case 5:
            main();
        default:
            break;
    }
}





/* 3rd Layer Menus */
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

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Main Menu > Arrays");

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

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Main Menu > Linear Data Structures > Linked Lists");

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

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Main Menu > Linear Data Structures > Linked Lists > Traverse");

    printf("Selected: %d", selectedOption);
}
void linkedListsInsertMenu(void) {
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Main Menu > Linear Data Structures > Linked Lists > Insert");

    printf("Selected: %d", selectedOption);
}
void linkedListsDeleteMenu(void){
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Main Menu > Linear Data Structures > Linked Lists > Delete");

    printf("Selected: %d", selectedOption);
}
void linkedListsSearchMenu(void) {
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Main Menu > Linear Data Structures > Linked Lists > Search");

    printf("Selected: %d", selectedOption);
}
void linkedListsReverseMenu(void) {
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Main Menu > Linear Data Structures > Linked Lists > Reverse");

    printf("Selected: %d", selectedOption);
}
void linkedListsMergeMenu(void) {
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize, "Main Menu > Linear Data Structures > Linked Lists > Merge");

    printf("Selected: %d", selectedOption);
}

void linearSearchMenu(void) {
    getUserIntegerInputs();
}