#include "graph.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

// Helper to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Helper to clear screen
void clearScreen() {
    system(CLEAR);
}

int main() {
    scene* head = create();
    scene* save = NULL;
    char c;

    while (1) {
        clearScreen();
        printf("%s\n", head->description);
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        printf("OPTIONS: ");
        printf("U : Undo    ");
        printf("R : Redo    ");
        printf("S : Save this point    ");
        printf("G : Go to saved point    ");
        printf("E : Exit game    ");
        printf("D : Display stack\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        printf("Enter choice: ");
        scanf(" %c", &c); // space before %c ignores leftover '\n'
        printf("---------------------------------------------------------------------------------------------------------------------------------\n");
        switch (c) {
            case '1':
                run(head);
                if (head->choice1)
                    head = head->choice1;
                else
                    printf("No path for choice 1.\n");
                break;

            case '2':
                run(head);
                if (head->choice2)
                    head = head->choice2;
                else
                    printf("No path for choice 2.\n");
                break;

            case '3':
                run(head);
                if (head->choice3)
                    head = head->choice3;
                else
                    printf("No path for choice 3.\n");
                break;

            case 'U':
                head = undo();
                break;

            case 'R':
                head = redo();
                break;

            case 'S':
                save = head;
                printf("Progress saved at current scene.\n");
                break;

            case 'G':
                if (save)
                    head = gotosave(save);
                else
                    printf("No saved point found.\n");
                break;

            case 'D':
                display();
                break;

            case 'E':
                printf("\nExiting the game. Goodbye.\n");
                exit(0);

            default:
                printf("Wrong choice, try again.\n");
                break;
        }
        printf("\nPress Enter to continue...");
        clearInputBuffer();
        getchar();
    }

    return 0;
}
