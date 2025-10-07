#include "graph.h"
#include <stdio.h>

#define MAX_STACK 100

scene* Undo[MAX_STACK];
scene* Redo[MAX_STACK];
int top = 0;
int topredo = 0;

void run(scene* node) {
    if (!node) return;

    if (top < MAX_STACK)
        Undo[top++] = node;
    else
        printf("Undo stack is full\n");

    for (int i = 0; i < topredo; i++)
        Redo[i] = NULL;
    topredo = 0;
}

scene* undo() {
    if (top <= 1) {
        printf("Nothing to undo\n");
        return Undo[0];
    }

    Redo[topredo++] = Undo[--top];
    return Undo[top];
}

scene* redo() {
    if (topredo == 0) {
        printf("Nothing to redo\n");
        return (top > 0) ? Undo[top - 1] : NULL;
    }

    Undo[top++] = Redo[--topredo];
    return Undo[top - 1];
}

void display() {
    if (top == 0) {
        printf("No scenes in Undo stack\n");
        return;
    }

    printf("\nVisited Scenes:\n");
    for (int i = 0; i < top; i++) {
        printf("---------------------------------------------------------------------------------------------------------------------------------\n");
        printf("%s\n", Undo[i]->description);
    }
}

scene* gotosave(scene* node) {
    if (!node) {
        printf("No saved node provided\n");
        return (top > 0) ? Undo[top - 1] : NULL;
    }

    while (top > 0 && Undo[top - 1] != node)
        top--;

    if (top == 0) {
        printf("Saved point not found in history\n");
        return node;
    }

    printf("Jumped back to saved point: %s\n", node->description);
    return Undo[top - 1];
}
