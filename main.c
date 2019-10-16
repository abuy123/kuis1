//LIBRARY
#include <stdio.h>      //LIBRARY C
#include <stdlib.h>     //LIBRARY FILE
#include <string.h>     //LIBRARY STRING
int main(){

    int i, j;       //untuk perulangan
    int v_total=0;  //untuk hitung total vokal
    int k_total=0;  //untuk hitung total konsonan

    char kata[200];  //karakter maksimal hanya 50 digit
    char vokal[100] = "aAiIUuEeOo";           //variabel karakter huruf vokal
    char konsonan[100] = "0123456789bBcCdDfFgGhHjJkKlLmMnNpPqQrRsStTvVwWxXyYzZ";      //variabel karakter huruf konsonan

    FILE *kuis;      //nama file yang akan di hitung
    kuis = fopen("kuis.txt", "r");    //membuka file yang akan di hitung

    char tampungan[100][100];
    //strcpy(tampungan, kuis);
    int z, y = 0;
    do{
        fscanf(kuis, "%s", &tampungan[y]);
        y++;
    }while(strcmp(tampungan[y-1], "XXX") != 0);

       
    int panjang = 0;    //untuk panjang kata
    for(z=0; z<100; z++){
        panjang = panjang + strlen(tampungan[z]);
        z++;
    }

    //perulangan selama panjangnya karakter di kuis.txt
    for(i=0; i<panjang; i++){
        for(j=0; j<strlen(vokal); j++){       //perulangan untuk menghitung huruf vokal
            if(tampungan[i][j]==vokal[j]){
                v_total++;                   //maka huruf vokal akan bertambah 1
            j++;
            }
        }

        for(j=0; j<strlen(konsonan); j++){    //perulangan untuk menghitung huruf konsonan
            if(tampungan[i][j]==konsonan[j]){
                k_total++;                //maka huruf konsonan akan bertambah 1
            j++;
            }
        }
    }

    int hasil = v_total + k_total;    //hasil adalah total kata, ditambah 1 karena patokannya dari spasi
    fclose(kuis);

    //OUTPUT    
    printf("Jumlah Kata : %d \n", hasil);
    printf("Jumlah Vokal : %d \n", v_total);
    printf("Jumlah Konsonan : %d \n", k_total);

    return 0;
}
