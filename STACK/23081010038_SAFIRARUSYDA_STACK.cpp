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
void emptyStack(); 
void fullStack(); 
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
     cout<<"4. Empty Stack"<<endl;
     
     cout<<"5. Full Stack"<<endl;
     cout<<"6. Stack Count"<<endl;
     cout<<"7. Destroy Stack"<<endl;
     cout<<"8. Display Stack"<<endl;

     cout<<"MASUKKAN PILIHAN (tekan 0 untuk keluar) : ";
     cin>>pilih;
     cin.ignore();

     if (pilih == 1)
     		push();
     else if (pilih == 2)
			pop();
      else if (pilih == 3)
         stackTop(); 
     else if (pilih == 4)
         emptyStack();
      else if (pilih == 5)
         fullStack();
      else if ( pilih == 6)
         stackCount();
      else if (pilih == 7)
         destroyStack();
      else if (pilih == 8)
         displayStack();

  } while (pilih != 0);
  
  return 0;
}

//========================================================

void push(){
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

   if (stack.count == 0)
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
    if (stack.count == 0)
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

void emptyStack(){
    if (stack.count != 0)
    {
        cout<<"stack tidak kosong. jumlah data dalam stack : "<<stack.count<<endl;
        cin.get();
    }else{
        cout<<"stack kosong";
        cin.get();
    }
    
}

//========================================================
//full stack

void fullStack(){
    node *pNew = new(nothrow) node;
    if (pNew == NULL) {
        cout << "Stack penuh (memori tidak cukup untuk menambahkan elemen baru)." << endl;
    } else {
        cout << "Masih ada cukup memori, stack belum penuh." << endl;
        delete pNew;
    }
    cin.get();

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
  if (stack.count == 0) {
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