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
#define MAX_PROGRAM_WIDTH 80

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

void hideCursor();
void showCursor();
void clearScreen();

int displayOptions(char *menuOptions[], int menuOptionsSize);
void breadCrumbPush(char *text);
void breadCrumbPop(void);
void displayBreadcrumbs(BreadcrumbsNode *head);
void displayHorizontalLine(void);
void displayHeader(void);
void displayConfirmExit(void);

void printAllocatedArrayList(void);
void freeAllAllocatedArrays(void);
AllocatedArraysNode* createNewAllocatedArrayNode(int *allocatedArray);

int isValidInteger(const char *str);
int *getUserIntegerInputs(const char *prompt, int *arrayLength);

void mainMenu(void);
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
void arrays1DimensionMenu(void);
void arrays2DimensionMenu(void);

int main(void) {
    breadCrumbPush("Main Menu");
    mainMenu();
    return 0;
}

/* Utility Functions */
void hideCursor() {
    /* Function to hide the cursor */
    #ifdef _WIN32
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &info);
    #else
        printf("\e[?25l");
    #endif
}
void showCursor() {
    /* Function to show the cursor */
    #ifdef _WIN32
        HANDLE consoleHandle = GetStdHandle  (STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = TRUE;
        SetConsoleCursorInfo(consoleHandle, &info);
    #else
        printf("\e[?25h");
    #endif
}
void clearScreen() {
    /* Function to clear the in-view area of the terminal */
    hideCursor();
    #ifdef _WIN32
	    system("cls");
    #else
	    printf("\033[2J");
	    printf("\033[H");
    #endif
    showCursor();
}

int displayOptions(char *menuOptions[], int menuOptionsSize) {
    int selectedOption = 0;
    
    printf("\nOptions: ");
    do {
        for (int i = 0; i < menuOptionsSize; i++) {
            printf("\n   %3d) %s", i+1, menuOptions[i]);
        }
        printf("\nPlease choose an option: ");
        scanf("%d", &selectedOption);
    } while(selectedOption <= 0 || selectedOption > menuOptionsSize);

    return selectedOption;
}
void breadCrumbPush(char text[MAX_CRUMB_LENGTH]) {
    /* Pushes a crumb into the breadcrumb stack */

    BreadcrumbsNode *node = (BreadcrumbsNode*)malloc(sizeof(BreadcrumbsNode));

    if (node == NULL) {
        printf("\n\nAllocated Node for breadcrumb is NULL!");
        exit(-1);
    }

    strcpy(node->crumb, text);
    node->next = breadcrumbsHead;
    breadcrumbsHead = node;
}
void breadCrumbPop(void) {
    /* Breadcrumb stack will be popped twice as
    a crumb is pushed into the stack after
    in each menu() */

    if (breadcrumbsHead == NULL) {
        return;
    }
    BreadcrumbsNode *tempNode = breadcrumbsHead;
    breadcrumbsHead = breadcrumbsHead->next;
    free(tempNode);
}
void displayBreadcrumbs(BreadcrumbsNode *head) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    /* Recrusive function to print singly linked
    list starting from the end.
    
    E.g:

    Stack/Linked List: HEAD -> "Binary Search" -> "Searching" -> "Main Menu" -> NULL
    
    Ouput: "Main Menu > Searching > Binary Search"
     */
    displayBreadcrumbs(head->next);
    printf("%s",head->crumb);
    /* If current node is the top, dont print ">" */
    if (head != breadcrumbsHead) {
        printf(" > ");
    }
}
void displayHorizontalLine(void) {
    printf("\n");
    for (int i = 0; i < MAX_PROGRAM_WIDTH; i++) {
        printf("-");
    }
}
void displayHeader(void) {
    char header[] = "Data Structures and Algorithms Final Project";
    int headerLength = strlen(header);
    int headerPadding = (MAX_PROGRAM_WIDTH - headerLength) / 2;

    /* Program Header */
    displayHorizontalLine();

    printf("\n");
    printf("\n");
    for (int i = 0; i < headerPadding; i++) {
        printf(" ");
    }
    printf("%s", header);
    for (int i = 0; i < headerPadding; i++) {
        printf(" ");
    }
    printf("\n");

    displayHorizontalLine();

    /* Breadcrumbs */
    displayBreadcrumbs(breadcrumbsHead);
    displayHorizontalLine();
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
            printf("\nAllocated array in node is NULL!");
            printf("\n\tFunction: freeAllAllocatedArarys()");
        }

        // Point temporary head node to next node
        tempHeadNode = tempHeadNode->next;
        free(allocatedArraysHead->value);
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

/* 1st layer Menu */
void mainMenu(void) {
    clearScreen();
    displayHeader();

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
            breadCrumbPush("Linear Data Structures");
            linearDataStructuresMenu();
            break;
        case 4:
            breadCrumbPush("Sorting");
            sortingMenu();
            break;
        case 5:
            breadCrumbPush("Searching");
            searchingMenu();
            break;
        case 6:
            printf("\nClosing Program...");
            printf("\nGood Bye!");
            printAllocatedArrayList();
            freeAllAllocatedArrays();
            printAllocatedArrayList();
            return;
        default:
            break;
    }
}

/* 2nd Layer Menus */
void linearDataStructuresMenu(void) {
    clearScreen();
    displayHeader();

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
            breadCrumbPush("Arrays");
            arraysMenu();
            break;
        case 2:
            breadCrumbPush("Linked List");
            linkedListsMenu();
            break;
        case 5:
            breadCrumbPop();
            mainMenu();
            break;
        default:
            break;
    }
}
void searchingMenu(void) {
    clearScreen();
    displayHeader();

    char *menuOptions[] = {
        "Linear Search",
        "Binary Search",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    switch (selectedOption) {
        case 1:
            breadCrumbPush("Linear Search");
            linearSearchMenu();
            break;
        case 2:
            breadCrumbPush("Binary Search");
            binarySearchMenu();
            break;
        case 3:
            breadCrumbPop();
            mainMenu();
            break;
        default:
            break;
    }
}
void sortingMenu(void) {
    clearScreen();
    displayHeader();

    int arrayLength = 0;
    int *array = getUserIntegerInputs("Please enter unsorted integers separated by commas: ", &arrayLength);

    clearScreen();
    displayHeader();

    printf("\nUnsorted Array: [");
    for(int i = 0; i < arrayLength; i++) {
        printf("%d", array[i]);
        if (i < arrayLength - 1) {
            printf(",");
        }
    }
    printf("]");
    displayHorizontalLine();

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
        "Change Array",
        "Exit"
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    switch (selectedOption) {
        case 10:
            sortingMenu();
            break;
        case 11:
            breadCrumbPop();
            mainMenu();
            break;
        default:
            break;
    }
}




/* 3rd Layer Menus */
void arraysMenu(void) {
    clearScreen();
    displayHeader();

    char *menuOptions[] = {
        "1 Dimensional Array",
        "2 Dimensional Array",
        "Exit",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);
    
    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    switch(selectedOption) {
        case 1:
            breadCrumbPush("1 Dimensional Array");
            arrays1DimensionMenu();
            break;
        case 2:
            breadCrumbPush("2 Dimensional Array");
            arrays2DimensionMenu();
            break;
        case 3:
            breadCrumbPop();
            linearDataStructuresMenu();
        default:
            break;
    }
}

void linkedListsMenu(void) {
    clearScreen();
    displayHeader();

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

    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

   switch (selectedOption) {
        case 1:
            breadCrumbPush("Traverse");
            linkedListsTraverseMenu();
            break;
        case 2:
            breadCrumbPush("Insert");
            linkedListsInsertMenu();
            break;
        case 3:
            breadCrumbPush("Delete");
            linkedListsDeleteMenu();
            break;
        case 4:
            breadCrumbPush("Search");
            linkedListsSearchMenu();
            break;
        case 5:
            breadCrumbPush("Reverse");
            linkedListsReverseMenu();
            break;
        case 6:
            breadCrumbPush("Merge");
            linkedListsMergeMenu();
            break;
        case 7:
            linearDataStructuresMenu();
            break;
        default:
            break;
    }
}
void linkedListsTraverseMenu(void) {
    clearScreen();
    displayHeader();

    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);


    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    printf("Selected: %d", selectedOption);
}
void linkedListsInsertMenu(void) {
    clearScreen();
    displayHeader();

    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    printf("Selected: %d", selectedOption);
}
void linkedListsDeleteMenu(void){
    clearScreen();
    displayHeader();

    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    printf("Selected: %d", selectedOption);
}
void linkedListsSearchMenu(void) {
    clearScreen();
    displayHeader();

    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    printf("Selected: %d", selectedOption);
}
void linkedListsReverseMenu(void) {
    clearScreen();
    displayHeader();

    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);

    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    printf("Selected: %d", selectedOption);
}
void linkedListsMergeMenu(void) {
    clearScreen();
    displayHeader();

    char *menuOptions[] = {
        "Temp",
    };
    int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);


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
    displayHeader();

    int arrayLength = 0;
    int *array = getUserIntegerInputs("Please enter your integers separated by commas: ", &arrayLength);

    clearScreen();
    displayHeader();

    printf("\n[");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d,", array[i]);
    }
    printf("]");

    printAllocatedArrayList();

    displayConfirmExit();
    breadCrumbPop();
    searchingMenu();
}
void arrays1DimensionMenu(void) {
    clearScreen();
    displayHeader();

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
    
    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    switch(selectedOption) {
        case 7:
            breadCrumbPop();
            arraysMenu();
            break;
        default:
            break;
    }
}
void arrays2DimensionMenu(void) {
    clearScreen();
    displayHeader();

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
    
    int selectedOption = displayOptions(menuOptions, menuOptionsSize);

    switch(selectedOption) {
        case 7:
            breadCrumbPop();
            arraysMenu();
            break;
        default:
            break;
    }
}


