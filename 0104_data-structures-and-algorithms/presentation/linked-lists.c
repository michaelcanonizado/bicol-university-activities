#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;
Node *listHead = NULL;
int listLength = 0;

int prompt(const char *message);
Node *createNode(int data);
int insertNodeAtStart(int data);
int insertNodeAtEnd(int data);
int insertNodeAtIndex(int data, int index);
int searchForItem(int data);
int deleteNodeAtIndex(int index);
int reverseList();
int printList();

int main(void) {
    char *menuOptions[] = {
        "Insert an item at start",
        "Insert an item at end",
        "Insert an item at index",
        "Search for an item",
        "Delete an item",
        "Reverse the list"
    };
    int numOfMenuOptions = sizeof(menuOptions)/sizeof(menuOptions[0]);
    int chosenOption;

    while(1) {
        printf("-----------------LINKED-LIST-----------------");
        printf("\nItems in list: %d\n", listLength);
        printList();
        printf("---------------------------------------------\n");

        for (int i = 0; i < numOfMenuOptions; i++) {
            printf("%d) %s\n",i+1, menuOptions[i]);
        }
        printf("Please choose an operation: ");
        scanf("%d", &chosenOption);

        int data, index;

        switch(chosenOption) {
            case 1:
                data = prompt("Number: ");
                insertNodeAtStart(data);
                break;
            case 2:
                data = prompt("Number: ");
                insertNodeAtEnd(data);
                break;
            case 3:
                data = prompt("Number: ");
                index = prompt("Index: ");
                int res = insertNodeAtIndex(data, index);

                if (res == 1) {
                    printf("\n\n\nINDEX INVALID! WILL CAUSE AN OVERFLOW!");
                    break;
                } 

                break;
            case 4:
                data = prompt("Number: ");
                searchForItem(data);
                break;
            case 5:
                index = prompt("Index: ");
                deleteNodeAtIndex(index);
                break;
            case 6:
                reverseList();
                break;
            default:
                return 0;
        }
        printf("\n");
    }

    return 0;
}

int prompt(const char *message) {
    int userInput;
    int result;

    while (1) {
        printf("%s", message);

        // Use scanf to read an integer, checking if the input was valid
        result = scanf("%d", &userInput);

        // Check if scanf successfully read an integer
        if (result == 1) {
            // Clear any remaining characters from the input buffer
            while (getchar() != '\n');
            return userInput;
        } else {
            // If input was invalid, clear the buffer and show an error message
            printf("Invalid input. Please enter a valid integer.\n");
            while (getchar() != '\n'); // Clear the invalid input
        }
    }
}

Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int insertNodeAtStart(int data) {
    Node *newNode = createNode(data);
    newNode->next = listHead;
    listHead = newNode; 
    listLength++;
    return 0;
}

int insertNodeAtEnd(int data) {
    Node *tempNode = listHead;
    while(1) {
        if (tempNode->next == NULL) {
            Node *newNode = createNode(data);
            tempNode->next = newNode;
            break;
        }
        tempNode = tempNode->next;
    }
    listLength++;

    return 0;
}

int insertNodeAtIndex(int data, int index) {
    if (index > listLength) {
        return 1;
    }

    Node *prevNode = NULL;
    Node *currNode = listHead;
    int currIndex = 0;

    if (index == 0) {
        Node *newNode = createNode(data);
        newNode->next = listHead;
        listHead = newNode;
        return 0;
    }

    while(index != currIndex) {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }

    Node *newNode = createNode(data);
    newNode->next = currNode;
    prevNode->next = newNode;

    listLength++;

    return 0;
}

int searchForItem(int data) {
    Node *tempNode = listHead;
    int currIndex = 0;

    while (tempNode != NULL) {
        if (tempNode->data == data) {
            return currIndex;
        } 
        
        tempNode = tempNode->next;
        currIndex++;
    }

    return -1;
}

int deleteNodeAtIndex(int index) {
    Node *prevNode = NULL;
    Node *toDeleteNode = NULL;
    Node *currNode = listHead;
    int currIndex = 0;

    if (index == 0) {
        toDeleteNode = listHead;
        listHead = listHead->next;
        free(toDeleteNode);
        return;
    }

    while(currIndex != index) {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }

    toDeleteNode = currNode;
    prevNode->next = currNode->next;
    free(toDeleteNode);

    listLength--;

    return 0;
}

int reverseList() {
    Node *tempNode1 = NULL;
    Node *tempNode2 = NULL;

    while(listHead != NULL) {
        tempNode2 = listHead->next;
        listHead->next = tempNode1;
        tempNode1 = listHead;
        listHead = tempNode2;
    }
    listHead = tempNode1;
}

int printList(void) {
    Node *tempNode = listHead;
    printf("\nHEAD -> ");
    while(tempNode != NULL) {
        printf("%d -> ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("NULL\n");
    return 0;
}