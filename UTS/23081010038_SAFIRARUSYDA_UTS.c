#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
	char nama[100];
    char jenis_kelamin;
    struct node *next;
};
typedef struct node node;




void tambahMahasiswa(node **pList);
void tranverse(node *pList);
void keluarMahasiswa(node **pList);
void tambahSaudarakembar(node **, char *, char);
void pisahLingkaran(node **pList);



//========================================================

int main()
{
  node *pList;
  int pilih;

  pList = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. Tambah data Mahasiswa\n");
     printf("2. Mahasiswa keluar lingkaran\n");
     printf("3. Tampilkan urutan Mahasiswa\n");
     printf("4. pisahkan menjadi 2 lingkaran \n");


     printf("MASUKKAN PILIHAN (tekan 0 untuk keluar) : ");
     fflush(stdin);
     scanf("%d", &pilih);
     if (pilih == 1)
     	tambahMahasiswa(&pList);
      else if (pilih == 2)
         keluarMahasiswa(&pList);
      else if (pilih == 3){
      tranverse(pList);
      getch();
      }
      else if (pilih == 4)
         pisahLingkaran(&pList);


  } while (pilih != 0);

  return 0;
}

//========================================================

/*node *createNode(void){
  node *ptr;

  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}*/

//========================================================

void tambahMahasiswa(node **pList){
  char nama[100];
  char jenis_kelamin;
  int count = 0;
  bool adairsyad = false;  
  bool adaarsyad = false;  
  node *pNew, *pcur;

  system("cls");

  if (*pList != NULL) {
        pcur = *pList;
        do {
            count++;
            pcur = pcur->next;
        } while (pcur != *pList);
    }

    if (count >= 20) {
        printf("Lingkaran sudah penuh, tidak bisa menambah lebih dari 20 orang.\n");
        getch();
        return;
    }

  fflush(stdin);
  printf("Masukkan nama Mahasiswa (huruf awal huruf besar) : ");
  fflush(stdin);
  scanf("%s", &nama);

  printf("masukkan jenis kelamin P/L : ");
  fflush(stdin);
  scanf(" %c", &jenis_kelamin);

  pNew = (node *)malloc(sizeof(node));

    if (strcmp(nama, "Irsyad") == 0 || strcmp(nama, "Arsyad") == 0) {
        printf("\nIrsyad dan Arsyad harus masuk ke dalam lingkaran bersama-sama.\n");
        
        tambahSaudarakembar(pList, "Irsyad", 'L');

        tambahSaudarakembar(pList, "Arsyad", 'L');
        
        return;
    }

   if (strcmp(nama, "Cindy") == 0) {
    pcur = *pList;
    int wanita_count = 0; 
    if (*pList != NULL) {
        do {
            if (pcur->jenis_kelamin == 'P') {
                wanita_count++; 
            }
            pcur = pcur->next;
        } while (pcur != *pList);
    }

  
    if (wanita_count < 2) {
        printf("Cindy tidak dapat bergabung karena harus ada minimal 2 mahasiswi lain.\n");
        getch();
        return; // Cindy tidak ikut lingkaran
    }
}

  if (pNew != NULL){
  	  strcpy(pNew->nama, nama);  
      pNew->jenis_kelamin = jenis_kelamin;

      if (*pList == NULL)
      {
        pNew->next = pNew;
      //add before first logical node or to an empty list
        *pList = pNew;
      }else
      {
         pcur = *pList;
         while (pcur->next != *pList)
         {
            pcur = pcur->next;
         }

         pNew->next = *pList;
         pcur->next = pNew;
         *pList = pNew;
      }
      printf("data berhasil ditambahkan\n");
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================
//fungsi tambah irsyad dan arsyad
void tambahSaudarakembar(node **pList, char nama[], char jenis_kelamin) {
    node *pNew, *pcur;

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        strcpy(pNew->nama, nama);
        pNew->jenis_kelamin = jenis_kelamin;

        if (*pList == NULL) {
            pNew->next = pNew;
            *pList = pNew;
        } else {
            pcur = *pList;
            while (pcur->next != *pList) {
                pcur = pcur->next;
            }
            pNew->next = *pList;
            pcur->next = pNew;
            *pList = pNew;
        }
        printf("Saudara kembar %s berhasil ditambahkan ke lingkaran.\n", nama);
    } else {
        printf("Alokasi memori gagal\n");
    }
}
//========================================================
//mahasiswa keluar lingkaran

void keluarMahasiswa(node **pList) {
   char nama[100];
   bool irsyad_present = false;
   bool arsyad_present = false;
   node *pcur = *pList, *ppre = NULL; // Inisialisasi pcur dan ppre

   system("cls");

   if (*pList == NULL) {
      printf("\nTidak ada mahasiswa dalam lingkaran.");
      getch();
      return;
   }

   tranverse(*pList);
   printf("\nNama mahasiswa yang akan keluar lingkaran: ");
   fflush(stdin);
   scanf("%s", nama);

   // Mencari Irsyad dan Arsyad di lingkaran
   do {
      if (strcmp(pcur->nama, "Irsyad") == 0) {
         irsyad_present = true;
      } else if (strcmp(pcur->nama, "Arsyad") == 0) {
         arsyad_present = true;
      }
      pcur = pcur->next;
   } while (pcur != *pList);

   
   if (strcmp(nama, "Irsyad") == 0 || strcmp(nama, "Arsyad") == 0) {
      
      node *temp = *pList; 
      if (temp->next == temp) { 
         free(temp);
         *pList = NULL; 
         printf("\nIrsyad dan Arsyad keluar dari lingkaran.");
         getch();
         return;
      }
      do {
         node *nextNode = temp->next; 
         free(temp);
         temp = nextNode; 
      } while (temp != *pList);
      *pList = NULL; 
      printf("\nIrsyad dan Arsyad keluar dari lingkaran.");
      getch();
      return;
   }

   pcur = *pList;
   int wanita_count = 0;
   int cindy_present = 0;


   do {
      if (pcur->jenis_kelamin == 'P') {
         wanita_count++;
      }
      if (strcmp(pcur->nama, "Cindy") == 0) {
         cindy_present = 1; 
      }
      pcur = pcur->next;
   } while (pcur != *pList);

   if (cindy_present && wanita_count == 3 && strcmp(nama, "Cindy") != 0) {
      printf("\nTidak bisa mengeluarkan %s, karena hanya ada 2 wanita yang tersisa dan Cindy masih dalam lingkaran.\n", nama);
      getch();
      return;
   }

   pcur = *pList; 
   ppre = NULL;

   do {
      if (strcmp(pcur->nama, nama) == 0) {
         break;
      }
      ppre = pcur;
      pcur = pcur->next;
   } while (pcur != *pList);

   if (pcur == *pList && strcmp(pcur->nama, nama) != 0) {
      printf("\nMahasiswa tidak ada dalam lingkaran.");
      getch();
      return;
   }


   if (pcur == *pList) {
      if (pcur->next == *pList) { 
         free(pcur);
         *pList = NULL; 
      } else {
         ppre = *pList;
         while (ppre->next != *pList) {
            ppre = ppre->next;
         }
         ppre->next = pcur->next; 
         *pList = pcur->next; 
         free(pcur);
      }
   } else {
      ppre->next = pcur->next; 
      free(pcur);
   }

   printf("\nMahasiswa %s keluar dari lingkaran.", nama);
   getch();
}


//========================================================
//urutan bernyanyi

void tranverse(node *pList){
   //traverse a circular list
	node *pWalker, *pLast;


   system("cls");
	pWalker = pList;

   if (pList == NULL)
   {
      printf("\nTidak ada mahasiswa dalam lingkaran");
      getch();
      return;
   }


   printf("\nlist data Mahasiswa dalam lingkaran:\n");
   do
   {
    if (pWalker == pList) {
            printf("- %s, '%c' sedang bernyanyi -> \n", pWalker->nama, pWalker->jenis_kelamin);
        } else {
            printf("- %s, '%c' -> \n", pWalker->nama, pWalker->jenis_kelamin);
        }

        pLast= pWalker;
        pWalker = pWalker->next;
   } while (pWalker !=pList);

    printf("\n %s bergandengan dengan mahasiswa pertama", pLast->nama);
    getch();
}



//========================================================
//Pisahkan Lingkaran
void pisahLingkaran(node **pList) {
    if (*pList == NULL) {
        printf("List kosong, tidak ada mahasiswa.\n");
        return; 
    }

    node *pCur = *pList;        
    node *pLastPria = NULL;
    node *pLastWanita = NULL;   


    node *headPria = NULL;    
    node *headWanita = NULL;    


    do {
        
        node *pNew = (node *)malloc(sizeof(node));
        if (pNew == NULL) {
            printf("Alokasi memori gagal.\n");
            return; 
        }


        strcpy(pNew->nama, pCur->nama);
        pNew->jenis_kelamin = pCur->jenis_kelamin;

        if (pCur->jenis_kelamin == 'L') { 
            if (headPria == NULL) {
                headPria = pNew;          
                pNew->next = headPria;     
            } else {
                pLastPria->next = pNew;    
                pNew->next = headPria;     
            }
            pLastPria = pNew;             
        } else if (pCur->jenis_kelamin == 'P') { // Jika mahasiswa wanita
            if (headWanita == NULL) {
                headWanita = pNew;         
                pNew->next = headWanita;    
            } else {
                pLastWanita->next = pNew;   
                pNew->next = headWanita;    
            }
            pLastWanita = pNew;            
        }

        pCur = pCur->next;  
    } while (pCur != *pList);  

    printf("\nLingkaran mahasiswa pria dan wanita:\n");

    if (headPria != NULL && headWanita != NULL) {
        printf("\nMahasiswa pria:\n");
        tranverse(headPria);      
        printf("\nMahasiswi wanita:\n");
        tranverse(headWanita);
    } else if(headPria == NULL){
        printf("Tidak ada mahasiswa dalam lingkaran.\n");
    }else if(headWanita == NULL){
        printf("Tidak ada mahasiswa dalam lingkaran.\n");

    }


}
