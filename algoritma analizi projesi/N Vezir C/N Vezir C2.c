#include<stdio.h> 
#include<stdlib.h> 
    
void Yazdir(int n,int x[]){ 
    int i,j; 
    char c[100][100]; 
    for(i=1;i<=n;i++) { 
        for(j=1;j<=n;j++) { 
            c[i][j]='O'; 
        } 
    }
	 
    for(i=1;i<=n;i++) { 
        c[i][x[i]] ='V'; 
    } 
    
    for(i=1;i<=n;i++){ 
        for(j=1;j<=n;j++) { 
           	printf(" %c",c[i][j]); 
        } 
        printf("\n"); 
	}   
} 
        
int Kontrol(int x[],int n){     
   int i; 
    for(i=1;i<n;i++) { 
        if((x[i] == x[n]) || (i-x[i] == n-x[n]) || (i+x[i]==n +x[n])) //son eklenen ekeman ile önceki elemanlarýn yerleþimini kontrol eder.
		   { 
        	return 0; 
        } 
    } 
    return 1; 
} 
    
void nVezir(int n){ 
    int x[100],sayac=0,k=1,i; 
    
    x[k] = 0; 
    while(k != 0) 
    { 
        x[k] +=1; 
        while((x[k] <= n) && ( !Kontrol(x,k))) 
        { 
            x[k] +=1; 
        } 
        if(x[k] <= n) 
        { 
            if(k == n) 
            { 
                sayac++; 
                printf("\n  Cozum %d\n",sayac);
				Yazdir(n,x); 
                printf("\n",sayac); 
            } 
            else 
            { 
                k++; 
                x[k]=0; 
            } 
        } 
        else 
        { 
            k--; 
        }         
    } 
    printf("Toplam Cozum sayisi : %d",sayac);
} 
int main() 
{ 
    int n; 
    printf("Vezir Sayisini giriniz :"); 
    scanf("%d",&n); 
        
    nVezir(n); 
        
    return 0; 
  } 
   
   
