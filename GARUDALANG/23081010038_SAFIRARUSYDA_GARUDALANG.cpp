#include <iostream>
#include <string>
#include <cstdlib>  

using namespace std;


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
                return false;  
            }
            pop();
        }
    }

    return emptyStack();  
}

int main() {
    string code;
    string allCode = "";  
    char pilih;

    do {
        system("cls");  


        cout << "Masukkan kode untuk diperiksa validitasnya (ketik 'END' untuk selesai):" << endl;


        while (true) {
            getline(cin, code);

            if (code == "END") {
                break;  
            }

            allCode += code + "\n";  
        }

        // Memeriksa seluruh kode
        if (isValidSyntax(allCode)) {
            cout << "Kode valid!" << endl;
        } else {
            cout << "Kode tidak valid!" << endl;
        }

        // Reset allCode setelah memeriksa kode
        allCode = "";


        cout << "Tekan 0 untuk keluar, atau tekan tombol lain untuk memeriksa kode lain: ";
        cin >> pilih;
        cin.ignore();  

    } while (pilih != '0'); 

    return 0;
}

//========================================================

// Menambah data ke stack (Push)
void push(char ch) {
    node* pNew = new node;

    pNew->data = ch;
    pNew->next = stack.top;
    stack.top = pNew;
    stack.count++;
}

//========================================================

// Hapus data dari stack (Pop)
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
        return '\0'; 
    }
    return stack.top->data;
}

//========================================================

// Empty Stack
bool emptyStack() {
    return stack.count == 0;
} 
