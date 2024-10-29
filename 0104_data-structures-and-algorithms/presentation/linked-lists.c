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
    insertNodeAtStart(3);
    insertNodeAtStart(4);

    insertNodeAtEnd(1);
    insertNodeAtEnd(0);

    printList();

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

void printList(void) {
    Node *tempNode = listHead;
    printf("\nHEAD -> ");
    while(tempNode != NULL) {
        printf("%d -> ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("NULL\n\n");
}