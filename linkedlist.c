#include <stdio.h>
#include <stdlib.h>

struct Node__ {
    int value;
    struct Node__* next;
};

typedef struct Node__ Node;
typedef Node* NodePtr;

void printList(Node* startPtr) {
    Node* current = startPtr;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("END\n");
}

void appendHead(Node** startPtr, int value) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->value = value;
    if (*startPtr == NULL) {
        *startPtr = temp;
        temp->next = NULL;
    } else {
        temp->next = *startPtr;
        *startPtr = temp;
    }
}

void appendTail(Node** startPtr, int value) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL; // temp will be the last Node
    if (*startPtr == NULL) {
        *startPtr = temp;
    } else {
        Node* current = *startPtr;
        while (current->next != NULL) current = current->next;
        current->next = temp;
    }
}

int getValue(Node* startPtr, int index) {
    for (int i = 0; i < index; i++) {
        if (startPtr->next == NULL) return -1;
        startPtr = startPtr->next;
    }
    return startPtr->value;
}

void delete(Node** startPtr, int value) {
    Node* current = *startPtr;
    Node* previous = NULL;
    while (current != NULL && current->value != value) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        if (previous != NULL) previous->next = current->next;
        else *startPtr = current->next;
        free(current);
    }
}

int main() {
    Node* startPtr;
    startPtr = NULL;

    appendTail(&startPtr, 1);
    appendHead(&startPtr, 24);
    appendHead(&startPtr, 36);
    appendHead(&startPtr, 18);

    appendTail(&startPtr, 1200);
    appendTail(&startPtr, 888);
    
    delete(&startPtr, 24);
    delete(&startPtr, 36);
    delete(&startPtr, 18);
    delete(&startPtr, 1200);
    delete(&startPtr, 888);

    printList(startPtr);
    
}
