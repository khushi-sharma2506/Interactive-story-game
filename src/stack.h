#define MAX_STACK 100
scene* Undo[MAX_STACK];
scene* Redo[MAX_STACK];
void run(scene*);
scene* undo();
scene* redo();
void display();
scene* gotosave(scene*);
