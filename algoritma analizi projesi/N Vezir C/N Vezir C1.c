#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



int sayi = 0;     //cozum sayisi 
int *tahta;       //her eleman bir sirayi gosterir 
int VEZIRLER;     // vezir sayisi

int tahtaTamam(int sira){
	int r;

    for (r = 0; r < sira; r++) 
	    if (tahta[sira] == tahta[r] || tahta[sira] == tahta[r] << sira-r || tahta[sira] == tahta[r] >> sira-r) //tahtaya eklenen son eleman ile önceki elemanlarýn kontrolü
			return 0;             
	return 1;         
}

void EkranaBas(){// cozumu goster
	int t, r;
    printf("\n  Cozum %d\n", ++sayi);
    for (r = 0; r < VEZIRLER; r++) {
			for (t = 1<<VEZIRLER-1; t > 0; t >>= 1)
    		printf(" %c", tahta[r] == t ? 'V' :  'O');
	    printf("\n");
	}
}

void Diz(int sira)   // bir sonraki siraya dizer  
{
    if (sira == VEZIRLER)     // tum siralar dolu ve kontrol  edilmis 
     EkranaBas();
    else
      for (tahta[sira]=1; tahta[sira]<1<<VEZIRLER;  tahta[sira]<<=1)
         if (tahtaTamam(sira))
         Diz(sira+1);  // bir sonraki sirayi dene 
}

int main ()
{	
    printf("Vezir Sayisini giriniz :"); 
	scanf("%d",&VEZIRLER);
	
   	tahta=(int*) malloc(VEZIRLER*sizeof(int));   //malloc ile vezir sayisina gore yeni dizi olusturuldu.

	Diz(0);       // ilk siradan basla 
    printf("\n\n%d vezir probleminin %u cozumu vardir.\n",VEZIRLER, sayi);
    free(tahta);
    return 0;
}

