#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;
Node *listHead = NULL;

Node *createNode(int data);
void insertNodeAtStart(int data, Node *listHead);
void printList(Node *listHead);

int main(void) {
    char *menuOptions[] = {
        "Insert an item at start",
        "Insert an item at end",
        "Insert an item at index",
        "Search for an item",
        "Delete an item",
        "Print list"
    };
    int numOfMenuOptions = sizeof(menuOptions)/sizeof(menuOptions[0]);
    int chosenOption;

    printf("\n");
    for (int i = 0; i < numOfMenuOptions; i++) {
        printf("%d) %s\n",i+1, menuOptions[i]);
    }
    printf("Please choose an operation: ");
    scanf("%d", &chosenOption);

    while(1) {
        switch(chosenOption) {
            case 1:
                insertNodeAtStart(7, listHead);
                break;
            case 2:
                printf("opt 2");
                break;
            case 3:
                printf("opt 3");
                break;
            case 4:
                printf("opt 4");
                break;
            case 5:
                printf("opt 5");
                break;
            case 6:
                printList(listHead);
                break;
            default:
                return 0;
        }
    }

    printf("\n\n");
    return 0;
}

Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNodeAtStart(int data, Node *listHead) {
    Node *newNode = createNode(data);
    newNode->next = listHead;
    listHead = newNode; 
}

void printList(Node *listHead) {
    Node *tempNode = listHead;
    while(tempNode != NULL) {
        printf("%d -> ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("NULL\n");
}