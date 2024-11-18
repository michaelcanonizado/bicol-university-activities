#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct AllocatedArraysNode {
    int *value;
    struct AllocatedArraysNode *next;
} AllocatedArraysNode;
AllocatedArraysNode *allocatedArraysHead = NULL;

int displayOptions(char *menuOptions[], int menuOptionsSize, char *header);
int isValidInteger(const char *str);
int *getUserIntegerInputs(int *size);
void printAllocatedArrayList(void);
AllocatedArraysNode* createNewAllocatedArrayNode(int *allocatedArray);
void freeAllAllocatedArrays(void);

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
void binarySearchMenu(void);

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
            printAllocatedArrayList();
            freeAllAllocatedArrays();
            printAllocatedArrayList();
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

AllocatedArraysNode* createNewAllocatedArrayNode(int *allocatedArray) {
    AllocatedArraysNode *node = (AllocatedArraysNode*)malloc(sizeof(allocatedArray));

    if (node == NULL) {
        printf("\n\nAllocated Node for array tracker is NULL!");
        exit(-1);
    }

    node->value = allocatedArray;
    node->next = NULL;
    return node;
}
int isValidInteger(const char *str) {
    if (*str == '\0') {
        return 0;
    }
    if (*str == '-') {
        str++;
    }

    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    
    return 1;
}
int *getUserIntegerInputs(int *size) {
    char inputStr[100], *inputStrCopy;
    const char delimiter[] = ","; 
    char *token1, *token2;
    int validInputCount = 0;

    printf("\nPlease enter your integers separated by commas: ");
    scanf("%s",inputStr);

    /* Count number of valid inputs, value will be
    needed to allocate memoery for array. */
    inputStrCopy = strdup(inputStr);
    token2 = strtok(inputStrCopy, delimiter);
    while (token2 != NULL) {
        if (isValidInteger(token2)) {
            validInputCount++;
        }
        token2 = strtok(NULL, delimiter);
    }
    free(inputStrCopy);

    /* Allocate space for array */
    int *allocatedArray = (int*)malloc(validInputCount * sizeof(int));
    int allocatedArrayIndex = 0;

    /* Load valid inputs to the allocated array */
    token1 = strtok(inputStr, delimiter);
    while (token1 != NULL) {
        /* If is invalid, move to the next token */
        if (!isValidInteger(token1)) {
            token1 = strtok(NULL, delimiter);
            continue;
        }

        /* If valid, parse to an integer and load
        to the array */
        printf("\n%s", token1);
        allocatedArray[allocatedArrayIndex++] = atoi(token1);
        token1 = strtok(NULL, delimiter);
    }

    /* Track allocated memory in linked list */
    AllocatedArraysNode *node = createNewAllocatedArrayNode(allocatedArray);
    node->next = allocatedArraysHead;
    allocatedArraysHead = node;

    *size = validInputCount;
    return allocatedArray;
}
void printAllocatedArrayList(void) {
    // Function to print the linked list of Bignums

    AllocatedArraysNode *tempNode = allocatedArraysHead;

    if (allocatedArraysHead == NULL) {
        printf("\nNode list empty!\n");
        return;
    }

    printf("\nHEAD -> ");
    while(tempNode != NULL) {
        printf("%p -> ", tempNode->value);
        tempNode = tempNode->next;

        if (tempNode == NULL) {
            printf("NULL");
        }
    }
}
void freeAllAllocatedArrays(void) {
    // Store head node in a temporary ndoe.
    AllocatedArraysNode *tempHeadNode = allocatedArraysHead;
    // Go through all nodes in linked list
    while(tempHeadNode != NULL) {

        if (allocatedArraysHead->value == NULL) {
            printf("\nBignum in list is NULL");
            printf("\n\tFunction: freeAllBignums()");
        }

        // Point temporary head node to next node
        tempHeadNode = tempHeadNode->next;
        free(allocatedArraysHead);

        // Store new head to original head node
        allocatedArraysHead = tempHeadNode;
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
        case 2:
            binarySearchMenu();
        case 3:
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
    int numOfInputs = 0;
    int target;

    printf("\nEnter number of inputs: ");
    scanf("%d", &numOfInputs);

    int *inputs = (int*)malloc(numOfInputs * sizeof(int));

    if (inputs == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < numOfInputs; i++) {
        int currInput = 0;
        printf("Element %d: ", i);
        scanf("%d", &currInput);
        inputs[i] = currInput;
    }

    printf("What do you want to search for?: ");
    scanf("%d", &target);

    for (int i = 0; i < numOfInputs; i++) {
        if (inputs[i] == target) {
            printf("Target %d found at index: %d!\n", target, i);
            return;
        }
    }

    printf("Target %d is not in the list!\n", target);
}
void binarySearchMenu(void) {
    int arraySize = 0;
    int *array = getUserIntegerInputs(&arraySize);

    printf("\n[");
    for (int i = 0; i < arraySize; i++) {
        printf("%d,", array[i]);
    }
    printf("]");

    printAllocatedArrayList();
}