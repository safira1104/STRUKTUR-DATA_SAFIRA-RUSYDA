#include <iostream>

using namespace std;

/* Tambahkan Fungsionalitas program :

Push queue 
Pop Stack
Stack Top
Empty Stack
Full Stack
Stack Count
Destroy Stack
*/
//========================================================



struct node {
	int data;
    struct node *next;
};
typedef struct node node;

struct queue {
	int count;
    node *front;
    node *rear;
};
typedef struct queue queue;

queue myQueue;

queue createQueue(void){
 myQueue.count = 0;
 myQueue.front = NULL;
 myQueue.rear = NULL;
 return(myQueue);
}

void enqueue();
void dequeue();  
void queuefront();
void queuerear();
bool emptyqueue(); 
bool fullqueue(); 
void queueCount (); 
void destroyqueue();


//========================================================

int main()
{
  node *head;
  int pilih;

  head = NULL;
  createQueue();

  do{
     system("cls");
     cout<<"masukkan pilihan"<<endl;
     cout<<"1. tambah data ke queue (Enqueue)"<<endl;
     cout<<"2. Hapus data dari queue (Dequeue)"<<endl;
     cout<<"3. queue front"<<endl;
     cout<<"4. queue rear"<<endl;
     cout<<"5. Destroy queue"<<endl;
     cout<<"6. full queue"<<endl;
     cout<<"7. empty queue"<<endl;
     cout<<"8. queue qount"<<endl;
     

     cout<<"MASUKKAN PILIHAN (tekan 0 untuk keluar) : ";
     cin>>pilih;
     cin.ignore();

     if (pilih == 1)
     		enqueue();
     else if (pilih == 2)
			dequeue();
      else if (pilih == 3)
         queuefront(); 
      else if ( pilih == 4)
         queuerear();
      else if (pilih == 5)
         destroyqueue();
      else if (pilih == 6){
         cout << (fullqueue() ? "Queue penuh!" : "Queue tidak penuh.") << endl;
         cin.get();
      }
      else if (pilih == 7){
         cout << (emptyqueue() ? "Queue kosong!" : "Queue tidak kosong.") << endl;
         cin.get(); 
        }        
      else if (pilih == 8)
         queueCount();

  } while (pilih != 0);
  
  return 0;
}

//========================================================

void enqueue(){

   if (fullqueue()) {
    cout <<  "queue penuh! Tidak bisa menambahkan data." << endl;
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
      pNew->next = NULL;

      if (myQueue.front == NULL)
      {
        myQueue.front = pNew;
      }else{
        myQueue.rear->next = pNew;
      }
      myQueue.rear = pNew;
      myQueue.count++;
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

void dequeue(){

   if (emptyqueue())
   {
      cout<< "queue kosong"<<endl;
      cin.get();  
      return;
   }
    node *dltPtr = myQueue.front; 
    myQueue.front = myQueue.front->next;

    if (myQueue.front == NULL)
    {
        myQueue.rear = NULL;
    }

    cout << "Data " << dltPtr->data << " berhasil dihapus." << endl;
    delete dltPtr;
    myQueue.count--;
    cin.get(); 
    
}
//========================================================

void queuefront(){
    if (emptyqueue())
    {
        cout<< "queue kosong"<<endl;
        cin.get();
    }else{
        
        cout<<"data paling depan queue : "<<myQueue.front->data<<endl;
        cin.get();
    }
    
}

//========================================================

void queuerear(){
    if (emptyqueue())
    {
        cout<< "queue kosong"<<endl;
        cin.get();
    }else{
        
        cout<<"data paling belakang queue : "<<myQueue.rear->data<<endl;
        cin.get();
    }
    
}

//========================================================
//empty queue

bool emptyqueue(){
    return myQueue.count == 0;
 
}

//========================================================
//full queue

bool fullqueue(){
    return myQueue.count >= 3;
}

//========================================================
//Cari data 

void queueCount(){
    cout << "Jumlah data dalam queue: " << myQueue.count << endl;
    cin.get();

}

//========================================================
//jumlah data 
void destroyqueue(){
    while ( myQueue.front != NULL) {
        node *temp = myQueue.front;
        myQueue.front = myQueue.front->next;
        delete temp;
    }
    myQueue.rear = NULL;
    myQueue.count = 0;
    cout <<  "queue berhasil dikosongkan" << endl;
    cin.get();
}

//========================================================
