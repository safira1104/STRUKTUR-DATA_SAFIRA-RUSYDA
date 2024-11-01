#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/* Tambahkan Fungsionalitas program :

Tambahkan data di akhir linked list
Hapus data di awal linked list
Hapus data di tengah linked list
Hapus data di akhir linked list
Pencarian data dalam linked list
Menampilkan informasi jumlah data di linked list
Menampilkan hasil penjumlahan dari semua data di linked list*/
//========================================================

struct node {
	int data;
    struct node *left;
    struct  node *right;
    
    
};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head); 
void tambahAkhir(node **head); // fungsi 1
void tranverse(node *head);
void hapusAwal(node **head); // fungsi 2
void hapusData(node **head); // fungsi 3
void hapusAkhir(node **head); // fungsi 4
void cariData(node **head); // fungsi 5
void jumlahData(node **head); // fungsi 6
void totalData (node **head); // fungsi 7


//========================================================

int main()
{
  node *head;
  int pilih;

  head = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. tambah data di awal\n");
     printf("2. tambah data di tengah list\n");
     printf("3. tambah data di akhir list \n"); //fungsi 1
     printf("4. cetak isi list\n");
     printf("5. hapus data di awal\n");
     printf("6. hapus data ditengah list\n");
     printf("7. hapus data di akhir list\n");
     printf("8. cari data didalam list\n");
     printf("9. jumlah data didalam list\n");
     printf("10. hasil penjumlahan semua data dalam list\n");

     printf("MASUKKAN PILIHAN (tekan 0 untuk keluar) : ");
     fflush(stdin);
     scanf("%d", &pilih);
     if (pilih == 1)
     		tambahAwal(&head);
     else if (pilih == 2)
			tambahData(&head);
      else if (pilih == 3)
         tambahAkhir(&head); 
     else if (pilih == 4){
     		tranverse(head);
         getch();
     }
     else if (pilih == 5)
         hapusAwal(&head);
      else if (pilih == 6)
         hapusData(&head);
      else if ( pilih == 7)
         hapusAkhir(&head);
      else if (pilih == 8)
         cariData(&head);
      else if (pilih == 9)
         jumlahData(&head);
      else if (pilih == 10)
         totalData(&head);
      
      
  } while (pilih != 0);
  
  return 0;
}
//========================================================

void tambahAwal(node **head){
  int bil;
  node *pNew;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
  	  pNew->data = bil;
      pNew->left = NULL;
      pNew->right = *head;
      //add before first logical node or to an empty list
      *head = pNew;

      if (*head != NULL)
      {
        (*head)->left = pNew;
      }

  *head = pNew;
  }  
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================
void tambahData(node **head){
  int pos, bil;
  node *pNew, *pCur;

  system("cls");
  tranverse(*head);
  printf("\nposisi penyisipan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("\nbilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pCur = *head;
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> right;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nalokasi memeori gagal");
     getch();
  }
  else{

     pNew->data = bil;
     pNew->left = pCur;
     pNew->right = pCur->right;

     if (pCur-> right != NULL)
     {
      pNew -> right->left = pNew;
     }
     pCur->right = pNew;
  }
}

//========================================================

void tranverse(node *head){
   //traverse a linked list
	node *pWalker;

   system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	printf("%d", pWalker -> data);
   	pWalker = pWalker -> right;

    if (pWalker != NULL)
    {
      printf(" <-> ");
    }  
      
	}
   printf(" -> NULL\n");
}

//========================================================
// menambah data diakhir list 

void tambahAkhir(node **head){
   int bil; 
   node *pnew, *pcur;

   system("cls");
   fflush(stdin);
   printf("masukkan sebuah bilangan : ");
   fflush(stdin);
   scanf("%d", &bil);
   
   pnew = (node *)malloc(sizeof(node));
   if (pnew != NULL)
   {
      pnew -> data = bil;
      pnew -> right = NULL;
      
      if (*head == NULL)
      {
          pnew->left = NULL;
         *head = pnew;
      }else{

         pcur = *head;
         while (pcur->right != NULL)
         {
            pcur = pcur->right;
         }
         
        pcur->right= pnew;
        pnew->left = pcur;
      }
      
   
   }else{
      printf("\nalokasi memori gagal");
      getch();
   }
   
}

//========================================================
//hapus data awal 

void hapusAwal(node **head){
   node *pcur;
   if (*head == NULL)
   {
      printf("list kosong\n");

      getch();  
   }else{
      pcur = *head;

      if (pcur->right == NULL)
      {
        *head = NULL;
      }else{
        *head = pcur->right;
        pcur->right->left  = NULL;

      }
      
      free(pcur);
      printf("\ndata berhasil dihapus");
      getch();
   }
   
}
//========================================================
//hapus data tengah 

void hapusData(node **head){
   int  bil;
   node *pcur, *ppre;

   system("cls");
   tranverse(*head);  
   printf("\nbilangan :  ");
   fflush(stdin);
   scanf("%d", &bil);  


   pcur = *head;
   ppre = NULL;

   while (pcur != NULL && pcur->data != bil)
   {
         ppre=pcur;
         pcur = pcur->right;    
   }
   
   if (pcur == NULL )
   {
      printf("\ndata tidak ditemukan");
      getch();
      return;
   }
   
   if (ppre == NULL)
   {
      *head = pcur->right;
      if (*head != NULL)
      {
        (*head)->left = NULL;
      }
      
   }else
   {
      ppre -> right = pcur-> right;
      if (pcur->right != NULL)
      {
        pcur->right->left = ppre;
      }
      
   }


   free(pcur);
   printf("\ndata berhasil dihapus");
   getch();
}

//========================================================
//hapus data akhir

void hapusAkhir(node **head){
   node *pcur, *ppre;
   if (*head == NULL)
   {
      printf("\nlist kosong");
      getch();
      return;
      
   }
   
   pcur = *head;
   ppre = NULL;
   while (pcur->right != NULL)
   {  
      ppre = pcur;
      pcur = pcur->right;
   }

   if (ppre == NULL)
   {
      *head = NULL;
   }else
   {
      ppre -> right = NULL;
   }
   
   free(pcur);
   printf("\ndata berhasil dihapus");
   getch();
   
}

//========================================================
//Cari data 
void cariData(node **head){
   int target, index = 0, found = 0;
   node *pcur;

   system("cls");
   fflush(stdin);
   printf("masukkan angka yang dicari: ");
   fflush(stdin);
   scanf("%d", &target);

   if (*head == NULL){
      printf("\nlist kosong");
      getch();
      return;
   }

   pcur = *head;
  

   while (pcur != NULL )
   {
      if(pcur->data == target){
         printf("\ndata %d ditemukan pada index : %d ", target, index);
         found = 1;
         break;
      }

      pcur= pcur->right;
      index++;
      
   }

    if(!found){
      printf("\ndata tidak ditemukan");
      
    }
   
  getch();
}
//========================================================
//jumlah data 

void jumlahData(node **head){
   int count = 0;
   node *pcur;
   if (*head == NULL)
   {
     printf("\nlist kosong");
     getch();
     return;
   }

   pcur= *head;
   

   while (pcur != NULL)
   {
      count++;
      pcur=pcur->right;
   }

   printf("jumlah data dalam list adalah %d ",count);
   getch();  
}

//========================================================
//Total data 
void totalData(node **head){
   int total;
   node *pcur;

   if (*head == NULL)
   {
      printf("\nlist kosong");
      getch();
   }

   pcur = *head;

   while (pcur != NULL)
   {
      total += pcur->data;
      pcur= pcur->right;
   }

   printf("Total penjumlahan data dalam list adalah %d ", total);
   getch();
   
   
}