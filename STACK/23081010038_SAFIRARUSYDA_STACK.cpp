#include <iostream>

using namespace std;

/* Tambahkan Fungsionalitas program :

Push Stack 
Pop Stack
Stack Top
Empty Stack
Full Stack
Stack Count
Destroy Stack
*/
//========================================================

typedef struct Stack {
	int count;
    struct node *top;
}Stack;

Stack stack;

struct node {
	int data;
    struct node *next;
};
typedef struct node node;

void createStack(){
    stack.count = 0;
    stack.top = NULL;
    return;
}

void push();
void pop();  
void stackTop();
bool emptyStack(); 
bool fullStack(); 
void stackCount (); 
void destroyStack();
void displayStack();

//========================================================

int main()
{
  node *head;
  int pilih;

  head = NULL;
  createStack();

  do{
     system("cls");
     cout<<"masukkan pilihan"<<endl;
     cout<<"1. tambah data ke stack (Push)"<<endl;
     cout<<"2. Hapus data dari stack (Pop)"<<endl;
     cout<<"3. Stack Top"<<endl;
     cout<<"4. Stack Count"<<endl;
     cout<<"5. Destroy Stack"<<endl;
     cout<<"6. Display Stack"<<endl;

     cout<<"MASUKKAN PILIHAN (tekan 0 untuk keluar) : ";
     cin>>pilih;
     cin.ignore();

     if (pilih == 1)
     		push();
     else if (pilih == 2)
			pop();
      else if (pilih == 3)
         stackTop(); 
      else if ( pilih == 4)
         stackCount();
      else if (pilih == 5)
         destroyStack();
      else if (pilih == 6)
         displayStack();

  } while (pilih != 0);
  
  return 0;
}

//========================================================

void push(){

   if (fullStack()) {
    cout << "Stack penuh! Tidak bisa menambahkan data." << endl;
    cin.get();
    return;
   }

  int bil;
  node *pNew = new node;

  cout<<"masukkan bilangan : ";
  cin>>bil;
  cin.ignore();

  if (pNew != NULL){
  	  pNew->data = bil;
      pNew->next = stack.top;
      stack.top = pNew;
      stack.count++;
      cout<<"data berhasil ditambahkan"<<endl;
      cin.get();
  }
  else{
      cout<<"Alokasi memori gagal"<<endl;
      cin.get();
  }
}

//========================================================
//hapus data 

void pop(){
   node *dltPtr;
   int dataOut;

   if (emptyStack())
   {
      cout<<"stack kosong"<<endl;
      cin.get();  
   }else{
      dltPtr = stack.top;
      dataOut = dltPtr ->data;
      stack.top = stack.top->next;
      stack.count--;
      delete dltPtr;
      cout<<"data berhasil dihapus"<<endl;
      cin.get();
   }
}
//========================================================

void stackTop(){
    int dataOut;
    if (emptyStack())
    {
        cout<<"stack kosong"<<endl;
        cin.get();
    }else{
        dataOut = stack.top->data;
        cout<<"data teratas stack : "<<dataOut;
        cin.get();
    }
    
}

//========================================================
//empty stack

bool emptyStack(){
    return stack.count == 0;
 
}

//========================================================
//full stack

bool fullStack(){
     node *pNew = new(nothrow) node;
    if (pNew == NULL) {
        return true;
    }
    delete pNew;
    return false;
}

//========================================================
//Cari data 

void stackCount(){
    cout << "Jumlah data dalam stack: " << stack.count << endl;
    cin.get();

}

//========================================================
//jumlah data 
void destroyStack(){
    while (stack.top != NULL) {
        node *temp = stack.top;
        stack.top = stack.top->next;
        delete temp;
    }
    stack.count = 0;
    cout << "Stack berhasil dikosongkan" << endl;
    cin.get();
}

//========================================================
//jumlah data 
void displayStack(){
  if (emptyStack()) {
        cout << "Stack kosong" << endl;
    } else {
        node *pWalker = stack.top;  
        cout << "Isi stack dari atas ke bawah:" << endl;
        while (pWalker != NULL) {
            cout << pWalker->data << " ";
            pWalker = pWalker->next;
        }
        cout << endl;
    }
    cin.get();


}