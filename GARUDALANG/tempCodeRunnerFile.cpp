#include <iostream>
#include <string>

using namespace std;

// Struktur node untuk stack
typedef struct node {
    char data;
    struct node* next;
} node;

typedef struct Stack {
    int count;
    node* top;
} Stack;

Stack stack;

void createStack() {
    stack.count = 0;
    stack.top = NULL;
}

void push(char ch);    
void pop();            
char stackTop();       
bool emptyStack();     


bool isValidSyntax(const string &code) {
    createStack();

    for (char ch : code) {
        if (ch == '(' || ch == '[' || ch == '{' || ch == '<') {
            push(ch); 
        }
        else if (ch == ')' || ch == ']' || ch == '}' || ch == '>') {
            if (emptyStack()) {
                return false;  
            }

            char topChar = stackTop();
            if ((ch == ')' && topChar != '(') ||
                (ch == ']' && topChar != '[') ||
                (ch == '}' && topChar != '{') ||
                (ch == '>' && topChar != '<')) {
                return false;  // Pasangan bracket tidak cocok
            }
            pop();  // Hapus karakter pembuka yang sesuai
        }
    }

    return emptyStack();  // Jika stack kosong setelah pengecekan, semua bracket valid
}

int main() {
    string code;

    // Input kode yang akan diperiksa
    cout << "Masukkan kode untuk diperiksa validitasnya:" << endl;
    getline(cin, code);

    // Memeriksa validitas kode
    if (isValidSyntax(code)) {
        cout << "Kode valid!" << endl;
    } else {
        cout << "Kode tidak valid!" << endl;
    }

    return 0;
}

//========================================================

// menambah data ke stack (Push)
void push(char ch) {
    node* pNew = new node;

    pNew->data = ch;
    pNew->next = stack.top;
    stack.top = pNew;
    stack.count++;
}

//========================================================

// hapus data dari stack (Pop)
void pop() {
    node* dltPtr;

    if (emptyStack()) {
        return;
    } else {
        dltPtr = stack.top;
        stack.top = stack.top->next;
        stack.count--;
        delete dltPtr;
    }
}

//========================================================

// Stack Top
char stackTop() {
    if (emptyStack()) {
        return '\0'; // Jika stack kosong
    }
    return stack.top->data;
}

//========================================================

// Empty Stack
bool emptyStack() {
    return stack.count == 0;
}
