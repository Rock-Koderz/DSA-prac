// Implement stack as an abstract data type using singly linked list and use this ADT for conversion of infix expression to postfix, prefix and evaluation of postfix and prefix expression.

#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    char data;
    Node* next;
};

// Stack structure using singly linked list
struct Stack {
    Node* top;
};

// Function to initialize the stack
void initStack(Stack& stack) {
    stack.top = nullptr;
}

// Function to push an element onto the stack
void push(Stack& stack, char value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = stack.top;
    stack.top = newNode;
}

// Function to pop an element from the stack
char pop(Stack& stack) {
    if (stack.top == nullptr) {
        cout << "Stack underflow" << endl;
        return '\0';
    }
    char value = stack.top->data;
    Node* temp = stack.top;
    stack.top = stack.top->next;
    delete temp;
    return value;
}

// Function to peek the top element of the stack
char peek(Stack& stack) {
    if (stack.top == nullptr) {
        cout << "Stack is empty" << endl;
        return '\0';
    }
    return stack.top->data;
}

// Function to check if the stack is empty
bool isEmpty(Stack& stack) {
    return stack.top == nullptr;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get precedence of an operator
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(const char* infix, char* postfix) {
    Stack stack;
    initStack(stack);
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(stack, c);
        } else if (c == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack);
        } else if (isOperator(c)) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(c)) {
                postfix[j++] = pop(stack);
            }
            push(stack, c);
        }
    }
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0';
}

// Function to reverse a string
void reverse(char* str) {
    int n = 0;
    while (str[n] != '\0') n++;
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert infix to prefix
void infixToPrefix(const char* infix, char* prefix) {
    char reversedInfix[100];
    char reversedPrefix[100];
    int n = 0;
    while (infix[n] != '\0') {
        reversedInfix[n] = infix[n];
        n++;
    }
    reversedInfix[n] = '\0';
    reverse(reversedInfix);
    for (int i = 0; i < n; i++) {
        if (reversedInfix[i] == '(') reversedInfix[i] = ')';
        else if (reversedInfix[i] == ')') reversedInfix[i] = '(';
    }
    infixToPostfix(reversedInfix, reversedPrefix);
    reverse(reversedPrefix);
    for (int i = 0; reversedPrefix[i] != '\0'; i++) {
        prefix[i] = reversedPrefix[i];
    }
    prefix[n] = '\0';
}

// Function to evaluate postfix expression
int evaluatePostfix(const char* postfix) {
    Stack stack;
    initStack(stack);
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (c >= '0' && c <= '9') {
            push(stack, c - '0');
        } else if (isOperator(c)) {
            int b = pop(stack);
            int a = pop(stack);
            switch (c) {
                case '+': push(stack, a + b); break;
                case '-': push(stack, a - b); break;
                case '*': push(stack, a * b); break;
                case '/': push(stack, a / b); break;
            }
        }
    }
    return pop(stack);
}

// Function to evaluate prefix expression
int evaluatePrefix(const char* prefix) {
    Stack stack;
    initStack(stack);
    int n = 0;
    while (prefix[n] != '\0') n++;
    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];
        if (c >= '0' && c <= '9') {
            push(stack, c - '0');
        } else if (isOperator(c)) {
            int a = pop(stack);
            int b = pop(stack);
            switch (c) {
                case '+': push(stack, a + b); break;
                case '-': push(stack, a - b); break;
                case '*': push(stack, a * b); break;
                case '/': push(stack, a / b); break;
            }
        }
    }
    return pop(stack);
}

int main() {
    const char* infix = "3+(2*5)-8/4";
    char postfix[100];
    char prefix[100];

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << prefix << endl;
    cout << "Postfix Evaluation: " << evaluatePostfix(postfix) << endl;
    cout << "Prefix Evaluation: " << evaluatePrefix(prefix) << endl;

    return 0;
}

/*

#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    char data;
    Node* next;
};

// Stack structure using singly linked list
struct Stack {
    Node* top;
};

// Function to initialize the stack
void initStack(Stack& stack) {
    stack.top = nullptr;
}

// Function to push an element onto the stack
void push(Stack& stack, char value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = stack.top;
    stack.top = newNode;
}

// Function to pop an element from the stack
char pop(Stack& stack) {
    if (stack.top == nullptr) {
        cout << "Stack underflow" << endl;
        return '\0';
    }
    char value = stack.top->data;
    Node* temp = stack.top;
    stack.top = stack.top->next;
    delete temp;
    return value;
}

// Function to peek the top element of the stack
char peek(Stack& stack) {
    if (stack.top == nullptr) {
        cout << "Stack is empty" << endl;
        return '\0';
    }
    return stack.top->data;
}

// Function to check if the stack is empty
bool isEmpty(Stack& stack) {
    return stack.top == nullptr;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get precedence of an operator
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(const char* infix, char* postfix) {
    Stack stack;
    initStack(stack);
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(stack, c);
        } else if (c == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack);
        } else if (isOperator(c)) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(c)) {
                postfix[j++] = pop(stack);
            }
            push(stack, c);
        }
    }
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0';
}

// Function to reverse a string
void reverse(char* str) {
    int n = 0;
    while (str[n] != '\0') n++;
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert infix to prefix
void infixToPrefix(const char* infix, char* prefix) {
    char reversedInfix[100];
    char reversedPrefix[100];
    int n = 0;
    while (infix[n] != '\0') {
        reversedInfix[n] = infix[n];
        n++;
    }
    reversedInfix[n] = '\0';
    reverse(reversedInfix);
    for (int i = 0; i < n; i++) {
        if (reversedInfix[i] == '(') reversedInfix[i] = ')';
        else if (reversedInfix[i] == ')') reversedInfix[i] = '(';
    }
    infixToPostfix(reversedInfix, reversedPrefix);
    reverse(reversedPrefix);
    for (int i = 0; reversedPrefix[i] != '\0'; i++) {
        prefix[i] = reversedPrefix[i];
    }
    prefix[n] = '\0';
}

// Function to evaluate postfix expression
int evaluatePostfix(const char* postfix) {
    Stack stack;
    initStack(stack);
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (c >= '0' && c <= '9') {
            push(stack, c - '0');
        } else if (isOperator(c)) {
            int b = pop(stack);
            int a = pop(stack);
            switch (c) {
                case '+': push(stack, a + b); break;
                case '-': push(stack, a - b); break;
                case '*': push(stack, a * b); break;
                case '/': push(stack, a / b); break;
            }
        }
    }
    return pop(stack);
}

// Function to evaluate prefix expression
int evaluatePrefix(const char* prefix) {
    Stack stack;
    initStack(stack);
    int n = 0;
    while (prefix[n] != '\0') n++;
    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];
        if (c >= '0' && c <= '9') {
            push(stack, c - '0');
        } else if (isOperator(c)) {
            int a = pop(stack);
            int b = pop(stack);
            switch (c) {
                case '+': push(stack, a + b); break;
                case '-': push(stack, a - b); break;
                case '*': push(stack, a * b); break;
                case '/': push(stack, a / b); break;
            }
        }
    }
    return pop(stack);
}

int main() {
    char infix[100];
    char postfix[100];
    char prefix[100];

    cout << "Enter an infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << prefix << endl;
    cout << "Postfix Evaluation: " << evaluatePostfix(postfix) << endl;
    cout << "Prefix Evaluation: " << evaluatePrefix(prefix) << endl;

    return 0;
}

*/