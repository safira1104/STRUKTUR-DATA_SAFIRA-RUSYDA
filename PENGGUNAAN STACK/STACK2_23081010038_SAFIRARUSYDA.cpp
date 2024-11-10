#include <iostream>
#include <string>
#include <cctype>
#include <cmath> 
#include <sstream> 

using namespace std;

//========================================================

typedef struct node {
    int data; 
    struct node *next;
} node;

typedef struct Stack {
    int count;
    node *top;
} Stack;

Stack stack;

//========================================================

void createStack();   
void push(int ch);   
void pop();              
int stackTop();       
bool emptyStack();      
int precedence(char op);
bool isOperand(char ch);
bool isValidExpression(const string& exp);
string infixToPostfix(const string &exp);
int evaluatePostfix(const string &exp);

//========================================================

int main() {
    int pilih;
    string infixExp;

    createStack();

    do {
        system("cls");
        cout << "Masukkan pilihan" << endl;
        cout << "1. Konversi Infix ke Postfix" << endl;
        cout << "2. Evaluasi ekspresi Postfix" << endl;
        cout << "0. Keluar" << endl;
        cout << "MASUKKAN PILIHAN: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            cout << "Masukkan ekspresi infiks: ";
            getline(cin, infixExp);

            if (!isValidExpression(infixExp)) {
                cout << "Ekspresi tidak valid (kurung tidak seimbang)." << endl;
                cin.get();
                continue;
            }

            string postfixExp = infixToPostfix(infixExp);
            cout << "Ekspresi dalam bentuk posfiks: " << postfixExp << endl;
            cin.get();
        }

        if (pilih == 2) {
            cout << "Masukkan ekspresi postfix: ";
            getline(cin, infixExp);

            int result = evaluatePostfix(infixExp);
            cout << "Hasil evaluasi ekspresi postfix: " << result << endl;
            cin.get();
        }

    } while (pilih != 0);

    return 0;
}

//========================================================

// Fungsi untuk membuat stack baru
void createStack() {
    stack.count = 0;
    stack.top = NULL;
}

bool isOperand(char ch) {
    return isdigit(ch);
}

// Fungsi untuk menentukan presedensi operator
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}

// Fungsi untuk memeriksa apakah ekspresi infiks valid (kurung seimbang)
bool isValidExpression(const string& exp) {
    createStack();  

    for (char ch : exp) {
        if (ch == '(') {
            push('(');  
        } else if (ch == ')') {
            if (emptyStack()) {
                return false; 
            }
            pop(); 
        }
    }
    return emptyStack(); 
}

// Fungsi untuk mengonversi infiks ke posfiks
string infixToPostfix(const string &exp) {
    createStack();
    string postfix;
    string currentNum = ""; // Untuk menangani angka multi-digit

    for (char ch : exp) {
        // Abaikan spasi
        if (ch == ' ') continue;

        
        if (isdigit(ch)) {
            currentNum += ch; 
        } else {

            if (!currentNum.empty()) {
                postfix += currentNum + " "; 
                currentNum = ""; 
            }

            if (ch == '(') {
                push(ch);
            }
          
            else if (ch == ')') {
                while (!emptyStack() && stackTop() != '(') {
                    postfix += stackTop();
                    postfix += " "; 
                    pop();
                }
                pop(); 
            }
            // Jika karakter adalah operator
            else {
                while (!emptyStack() && precedence(stackTop()) >= precedence(ch)) {
                    postfix += stackTop();
                    postfix += " "; 
                    pop();
                }
                push(ch);
            }
        }
    }

    if (!currentNum.empty()) {
        postfix += currentNum + " ";
    }

    // Mengosongkan stack yang tersisa
    while (!emptyStack()) {
        postfix += stackTop();
        postfix += " "; 
        pop();
    }

    return postfix;
}

int evaluatePostfix(const string &exp) {
    createStack();  
    stringstream ss(exp);
    string token;

    while (ss >> token) {

        if (isdigit(token[0])) {
            push(stoi(token)); 
        } else {

            int operand2 = stackTop();
            pop();
            int operand1 = stackTop();
            pop();


            switch (token[0]) {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1 / operand2); break;
                case '^': push(pow(operand1, operand2)); break;
            }
        }
    }


    return stackTop();
}

// Fungsi untuk memasukkan data ke dalam stack
void push(int ch) {
    node *pNew = new node;
    if (pNew != NULL) {
        pNew->data = ch;
        pNew->next = stack.top;
        stack.top = pNew;
        stack.count++;
    }
}

// Fungsi untuk mengeluarkan data dari stack
void pop() {
    if (!emptyStack()) {
        node *dltPtr = stack.top;
        stack.top = stack.top->next;
        stack.count--;
        delete dltPtr;
    }
}

// Fungsi untuk melihat data paling atas stack
int stackTop() {
    if (!emptyStack()) {
        return stack.top->data;
    }
    return 0; 
}

// Fungsi untuk mengecek apakah stack kosong
bool emptyStack() {
    return stack.count == 0;
}
