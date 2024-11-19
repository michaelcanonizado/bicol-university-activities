#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#ifdef _WIN32
	#include <windows.h>
#else
    #include <sys/ioctl.h>
	#include <unistd.h>
    #include <termios.h>
#endif

#define MAX_CRUMB_LENGTH 50

typedef struct AllocatedArraysNode {
    int *value;
    struct AllocatedArraysNode *next;
} AllocatedArraysNode;
AllocatedArraysNode *allocatedArraysHead = NULL;

typedef struct BreadcrumbsNode {
    char crumb[MAX_CRUMB_LENGTH];
    struct BreadcrumbsNode *next;
} BreadcrumbsNode;
BreadcrumbsNode *breadcrumbsHead = NULL;

void clearScreen();

int displayOptions(char *menuOptions[], int menuOptionsSize);
void displayHeader(void);
void breadCrumbPush(char *text);
void displayBreadcrumbs(char *path[], int pathLength);
void displayConfirmExit(void);

void printAllocatedArrayList(void);
void freeAllAllocatedArrays(void);
AllocatedArraysNode* createNewAllocatedArrayNode(int *allocatedArray);

int isValidInteger(const char *str);
int *getUserIntegerInputs(const char *prompt, int *arrayLength);

void linearDataStructuresMenu(void);
void sortingMenu(void);
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
    clearScreen();

    char *menuOptions[] = {
        "Linear Data Structures", 
        "Non-Linear Data Structures", 
        "Strings", 
        "Sorting",
        "Searching",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    char *path[] = {"Main Menu"};
    displayBreadcrumbs(path, 1);
    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    switch (selectedOption) {
        case 1:
            linearDataStructuresMenu();
            break;
        case 4:
            sortingMenu();
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
void clearScreen() {
    /* Function to clear the in-view area of the terminal */
#ifdef _WIN32
	system("cls");
#else
	printf("\033[2J");
	printf("\033[H");
#endif
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
void displayHeader(void) {
    int width = 80;
    char header[] = "Data Structures and Algorithms Final Project";
    int headerLength = strlen(header);
    int headerPadding = (width - headerLength) / 2;

    for (int i = 0; i < width; i++) {
        printf("-");
    }

    printf("\n");
    for (int i = 0; i < headerPadding; i++) {
        printf(" ");
    }
    printf("%s", header);
    for (int i = 0; i < headerPadding; i++) {
        printf(" ");
    }
    printf("\n");

    for (int i = 0; i < width; i++) {
        printf("-");
    }
}
void breadCrumbPush(char text[MAX_CRUMB_LENGTH]) {
    BreadcrumbsNode *node = (BreadcrumbsNode*)malloc(sizeof(BreadcrumbsNode));

    if (node == NULL) {
        printf("\n\nAllocated Node for breadcrumb is NULL!");
        exit(-1);
    }

    strcpy(node->crumb, text);
    node->next = breadcrumbsHead;
    breadcrumbsHead = node;
}
void displayBreadcrumbs(char *path[], int pathLength) {
    displayHeader();

    printf("\n");
    for (int i = 0; i < pathLength; i++) {
        printf("%s", path[i]);
        if (i < pathLength - 1) {
            printf(" > ");
        }
    }
}
void displayConfirmExit(void) {
    char response;
    do {
        printf("\nEnter Y/y to exit: ");
        scanf(" %c", &response);
        response = toupper(response);
        if (response != 'Y') {
            while (getchar() != '\n');
        }
    } while(response != 'Y');
}

AllocatedArraysNode* createNewAllocatedArrayNode(int *allocatedArray) {
    AllocatedArraysNode *node = (AllocatedArraysNode*)malloc(sizeof(AllocatedArraysNode));

    if (node == NULL) {
        printf("\n\nAllocated Node for array tracker is NULL!");
        exit(-1);
    }

    node->value = allocatedArray;
    node->next = NULL;
    return node;
}
void printAllocatedArrayList(void) {
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

int isValidInteger(const char *str) {
    /* If string empty, not valid */
    if (*str == '\0') {
        return 0;
    }
    /* If there is negative sign, offset the string */
    if (*str == '-') {
        str++;
    }

    /* Go through each character if all is an integer */
    while (*str) {
        /* If a non integer is found, string is invalid */
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }

    return 1;
}
int *getUserIntegerInputs(const char *prompt, int *arrayLength) {
    char inputStr[100], *inputStrCopy;
    const char delimiter[] = ","; 
    char *token1, *token2;
    int validInputCount = 0;

    printf("\n%s", prompt);
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
        allocatedArray[allocatedArrayIndex++] = atoi(token1);
        token1 = strtok(NULL, delimiter);
    }

    /* Track allocated memory in linked list */
    AllocatedArraysNode *node = createNewAllocatedArrayNode(allocatedArray);
    node->next = allocatedArraysHead;
    allocatedArraysHead = node;

    *arrayLength = validInputCount;
    return allocatedArray;
}


/* 2nd Layer Menus */
void linearDataStructuresMenu(void) {
    clearScreen();

    char *menuOptions[] = {
        "Arrays",
        "Linked Lists",
        "Stacks",
        "Queues",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    char *path[] = {
        "Main Menu",
        "Linear Data Structures"
    };
    displayBreadcrumbs(path, 2);
    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

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
    clearScreen();

    char *menuOptions[] = {
        "Linear Search",
        "Binary Search",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    char *path[] = {
        "Main Menu",
        "Searching"
    };
    displayBreadcrumbs(path, 2);
    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

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
void sortingMenu(void) {
    clearScreen();

    char *path[] = {
        "Main Menu",
        "Sorting"
    };
    displayBreadcrumbs(path, 2);

    int arrayLength = 0;
    int *array = getUserIntegerInputs("Please enter unsorted integers separated by commas: ", &arrayLength);

    char *menuOptions[] = {
        "Bubble Sort",
        "Counting Sort",
        "Heap Sort",
        "Insertion Sort",
        "Merge Sort",
        "Quicksort",
        "Radix Sort",
        "Random Sort",
        "Selection Sort",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    switch (selectedOption) {
        case 10:
            main();
        default:
            break;
    }
}




/* 3rd Layer Menus */
void arraysMenu(void) {
    clearScreen();

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

    char *path[] = {
        "Main Menu",
        "Arrays"
    };
    displayBreadcrumbs(path, 2);
    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    switch(selectedOption) {
        case 7:
            linearDataStructuresMenu();
        default:
            break;
    }
}

void linkedListsMenu(void) {
    clearScreen();

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

    char *path[] = {   
        "Main Menu",
        "Linear Data Structures",
        "Linked Lists"
    };
    displayBreadcrumbs(path, 3);
    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

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
    clearScreen();

    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    char *path[] = {   
        "Main Menu",
        "Linear Data Structures",
        "Linked Lists",
        "Traverse"
    };
    displayBreadcrumbs(path, 4);
    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    printf("Selected: %d", selectedOption);
}
void linkedListsInsertMenu(void) {
    clearScreen();
    
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    char *path[] = {   
        "Main Menu",
        "Linear Data Structures",
        "Linked Lists",
        "Insert"
    };
    displayBreadcrumbs(path, 4);
    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    printf("Selected: %d", selectedOption);
}
void linkedListsDeleteMenu(void){
    clearScreen();
    
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    char *path[] = {   
        "Main Menu",
        "Linear Data Structures",
        "Linked Lists",
        "Delete"
    };
    displayBreadcrumbs(path, 4);
    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    printf("Selected: %d", selectedOption);
}
void linkedListsSearchMenu(void) {
    clearScreen();

    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    char *path[] = {   
        "Main Menu",
        "Linear Data Structures",
        "Linked Lists",
        "Search"
    };
    displayBreadcrumbs(path, 4);
    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    printf("Selected: %d", selectedOption);
}
void linkedListsReverseMenu(void) {
    clearScreen();
    
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    char *path[] = {   
        "Main Menu",
        "Linear Data Structures",
        "Linked Lists",
        "Reverse"
    };
    displayBreadcrumbs(path, 4);
    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    printf("Selected: %d", selectedOption);
}
void linkedListsMergeMenu(void) {
    clearScreen();
    
    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    char *path[] = {   
        "Main Menu",
        "Linear Data Structures",
        "Linked Lists",
        "Merge"
    };
    displayBreadcrumbs(path, 4);
    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    printf("Selected: %d", selectedOption);
}

void linearSearchMenu(void) {
    clearScreen();
    
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
    clearScreen();
    
    char *path[] = {   
        "Main Menu",
        "Searching",
        "Binary Search"
    };
    displayBreadcrumbs(path, 3);

    int arrayLength = 0;
    int *array = getUserIntegerInputs("Please enter your integers separated by commas: ", &arrayLength);

    printf("\n[");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d,", array[i]);
    }
    printf("]");

    printAllocatedArrayList();

    displayConfirmExit();
    searchingMenu();
}
