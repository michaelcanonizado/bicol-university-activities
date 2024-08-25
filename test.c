#include <stdio.h>

int main (void) {

    struct node {
        int data;
        struct node *next;
    };
    typedef struct node Node;

    Node *p, *q;
    Node a,b,c;

    p = &a;
    q = &b;

    a.data = 1;
    b.data = 2;
    c.data = 3;

    a.next = &b;
    b.next = &c;
    c.next = NULL;

    printf("\n\n ->%d\n\n", p->next->data);

    return 0;
}