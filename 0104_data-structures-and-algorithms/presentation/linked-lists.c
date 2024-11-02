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
void reverseList();
void printList();

int main(void) {
    char *menuOptions[] = {
        "Insert an item at start",
        "Insert an item at end",
        "Insert an item at index",
        "Search for an item",
        "Delete an item",
        "Reverse the list",
        "Print list"
    };
    int numOfMenuOptions = sizeof(menuOptions)/sizeof(menuOptions[0]);
    int chosenOption;

    while(1) {
        printf("\n");
        for (int i = 0; i < numOfMenuOptions; i++) {
            printf("%d) %s\n",i+1, menuOptions[i]);
        }
        printf("Please choose an operation: ");
        scanf("%d", &chosenOption);

        switch(chosenOption) {
            case 1:
                insertNodeAtStart(7);
                break;
            case 2:
                insertNodeAtEnd(8);
                break;
            case 3:
                insertNodeAtIndex(0, 1);
                break;
            case 4:
                searchForItem(7);
                break;
            case 5:
                deleteNodeAtIndex(1);
                break;
            case 6:
                reverseList();
                break;
            case 7:
                printList();
                break;
            default:
                return 0;
        }
        printf("\n");
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

void reverseList() {
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

void printList(void) {
    Node *tempNode = listHead;
    printf("\nHEAD -> ");
    while(tempNode != NULL) {
        printf("%d -> ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("NULL\n\n");
}