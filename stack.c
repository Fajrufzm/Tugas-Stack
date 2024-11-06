#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int top;
} Stack;

// Function prototypes
void initialize(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, int value);
void pop(Stack *s);
void stackTop(Stack *s);
void stackCount(Stack *s);
void destroyStack(Stack *s);
void printStack(Stack *s);

int main() {
    Stack s;
    initialize(&s);

    char choice;
    int value;

    do {
        system("cls");
        printf("Choose an option:\n");
        printf("1. Push to stack\n");
        printf("2. Pop from stack\n");
        printf("3. Display top of stack\n");
        printf("4. Check if stack is empty\n");
        printf("5. Check if stack is full\n");
        printf("6. Count elements in stack\n");
        printf("7. Destroy stack\n");
        printf("8. Print stack\n");
        printf("Press 'q' to quit.\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case '2':
                pop(&s);
                break;
            case '3':
                stackTop(&s);
                break;
            case '4':
                if (isEmpty(&s))
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;
            case '5':
                if (isFull(&s))
                    printf("Stack is full.\n");
                else
                    printf("Stack is not full.\n");
                break;
            case '6':
                stackCount(&s);
                break;
            case '7':
                destroyStack(&s);
                printf("Stack destroyed.\n");
                break;
            case '8':
                printStack(&s);
                break;
            case 'q':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\nPress any key to continue...");
        getchar();
    } while (choice != 'q');

    return 0;
}

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        s->data[++s->top] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
    } else {
        printf("Popped %d from the stack\n", s->data[s->top--]);
    }
}

void stackTop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty, no top element\n");
    } else {
        printf("Top element is %d\n", s->data[s->top]);
    }
}

//hitung
void stackCount(Stack *s) {
    printf("There are %d elements in the stack\n", s->top + 1);
}

// Destroy
void destroyStack(Stack *s) {
    s->top = -1;
    printf("Stack cleared.\n");
}

// Print
void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->data[i]);
        }
        printf("\n");
    }
}
