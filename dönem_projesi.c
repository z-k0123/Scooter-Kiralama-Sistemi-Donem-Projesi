#include <stdio.h>
#include <stdlib.h>

//Scooter kiralama sistemi

int main(){
    int bakiye=0, ucret=0, yuklenen=0, menu=0, dakika=0, sifre=0, telno=0, toplam=0, secim=0;
    char siradaki;
    int scooter_turleri[3]={2,5,8}; //scooterlarin turune gore dakika fiyati

    giris(telno, sifre);

    while(1){
    printf("Yapmak istediginiz islemin numarasini girin.\n 1.Bakiye yukle \n 2.Kalan bakiye sorgula \n 3. Scooter'a dakika yukle \n 4. Cikis\n");
    scanf("%d",&menu);

    if(menu==1){
        printf("Yuklemek istediginiz miktari girin: ");
        scanf("%d",&yuklenen);
        bakiye+=yuklenen;
        continue;
    }
    if(menu==2){
        printf("Kalan bakiye: %d \n",bakiye);
        continue;
    }
    if(menu==3){
        printf("Kullanmak istediginiz scooter turunu secin.\n0)yavas\n1)orta hizli\n2)hizli\n");
        scanf("%d",&secim);
        printf("Scooter'i kullanmak istediginiz dakikayi girin. ");
        scanf("%d",&dakika);
        ucret=dakika*scooter_turleri[secim];
        bakiye=bakiye-ucret;
        if(bakiye<0){
            printf("Yetersiz bakiye.\n");
            bakiye=0;
            }
        else{
            printf("Gidilecek %d dakikalik yol icin ucret: %d tl.\n",dakika,ucret);
            toplam+=ucret;
        }
        continue;
        }
    if(menu==4){
        printf("siradaki kullaniciya gecis yapilsin mi? E/H \n");
        scanf("%s",&siradaki);
        if(siradaki=='E'){
            giris(telno,sifre);
            bakiye=0;
            continue;
            }
        else if(siradaki=='H'){
            printf("Scooterlardan elde edilen toplam kazanc: %d TL",toplam);
            break;
        }
        else{
            printf("Gecerli islem girmediginiz icin oturum kapatilmistir.\n Scooterlardan elde edilen toplam kazanc: %d TL",toplam);
            break;
        }
        }
    }
    FILE *dosya = fopen("kazanc.txt","a");
    fprintf(dosya, "%d\n",toplam);
    fclose(dosya);
    return 0;
}

void giris(int telno, int sifre){
    printf("Telefon numaranizi giriniz: ");
    scanf("%d",&telno);
    printf("Telefonunuza gelen sifreyi giriniz: ");
    scanf("%d",&sifre);
}

