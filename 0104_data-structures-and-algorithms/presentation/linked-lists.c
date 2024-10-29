#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;
Node *listHead = NULL;

Node *createNode(int data);
void insertNodeAtStart(int data);
void insertNodeAtEnd(int data);
void insertNodeAtIndex(int data, int index);
int searchForItem(int data);
void deleteNodeAtIndex(int index);
void printList();

int main(void) {
    // char *menuOptions[] = {
    //     "Insert an item at start",
    //     "Insert an item at end",
    //     "Insert an item at index",
    //     "Search for an item",
    //     "Delete an item",
    //     "Print list"
    // };
    // int numOfMenuOptions = sizeof(menuOptions)/sizeof(menuOptions[0]);
    // int chosenOption;

    // while(1) {
    //     printf("\n");
    //     for (int i = 0; i < numOfMenuOptions; i++) {
    //         printf("%d) %s\n",i+1, menuOptions[i]);
    //     }
    //     printf("Please choose an operation: ");
    //     scanf("%d", &chosenOption);

    //     switch(chosenOption) {
    //         case 1:
    //             insertNodeAtStart(7, listHead);
    //             printf("opt 1");
    //             break;
    //         case 2:
    //             printf("opt 2");
    //             break;
    //         case 3:
    //             printf("opt 3");
    //             break;
    //         case 4:
    //             printf("opt 4");
    //             break;
    //         case 5:
    //             printf("opt 5");
    //             break;
    //         case 6:
    //             printList();
    //             break;
    //         default:
    //             return 0;
    //     }
    //     printf("\n\n");
    // }

    insertNodeAtStart(2);
    insertNodeAtStart(4);
    insertNodeAtStart(5);

    insertNodeAtEnd(1);
    insertNodeAtEnd(0);

    insertNodeAtIndex(3, 2);
    insertNodeAtIndex(3, 2);
    insertNodeAtIndex(6, 0); 
    insertNodeAtIndex(7, 0);
    insertNodeAtIndex(7, 0);

    deleteNodeAtIndex(5);
    deleteNodeAtIndex(0);

    printList();

    int itemToSearch = 4;
    int itemIndex = searchForItem(itemToSearch);
    if (itemIndex != -1) {
        printf("%d is in the list at index %d\n", itemToSearch, itemIndex);
    } else {
        printf("%d is not in the list!\n", itemToSearch);
    }

    itemToSearch = 99;
    itemIndex = searchForItem(itemToSearch);
    if (itemIndex != -1) {
        printf("%d is in the list at index %d\n", itemToSearch, itemIndex);
    } else {
        printf("%d is not in the list!\n", itemToSearch);
    }

    return 0;
}

Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNodeAtStart(int data) {
    Node *newNode = createNode(data);
    newNode->next = listHead;
    listHead = newNode; 
}

void insertNodeAtEnd(int data) {
    Node *tempNode = listHead;
    while(1) {
        if (tempNode->next == NULL) {
            Node *newNode = createNode(data);
            tempNode->next = newNode;
            break;
        }
        tempNode = tempNode->next;
    }
}

void insertNodeAtIndex(int data, int index) {
    Node *prevNode = NULL;
    Node *currNode = listHead;
    int currIndex = 0;

    if (index == 0) {
        Node *newNode = createNode(data);
        newNode->next = listHead;
        listHead = newNode;
        return;
    }

    while(index != currIndex) {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }

    Node *newNode = createNode(data);
    newNode->next = currNode;
    prevNode->next = newNode;
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

void deleteNodeAtIndex(int index) {
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
}

void printList(void) {
    Node *tempNode = listHead;
    printf("\nHEAD -> ");
    while(tempNode != NULL) {
        printf("%d -> ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("NULL\n\n");
}