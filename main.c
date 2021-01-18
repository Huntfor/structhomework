#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct HASTALAR_
{
    char ad[50];
    long long int tcNO;
    int yas;
    int yesilKart;
} hasta;

typedef struct RANDEVULAR_
{
    int randevuNO;
    int polNO;
    char saat[6];
    float ucr;
    hasta *hastalar;
} randevu;
int toplamRandevuSayisi=0;
randevu *randevular;
hasta *hastalar;


void randevuEkle()
{
    int i=toplamRandevuSayisi,secim;
    if (toplamRandevuSayisi==0)
    {
        randevular=(randevu*)calloc(1,sizeof(randevu));

    }
    else
    {
        randevular=(randevu*)realloc(randevular,sizeof(randevu)*(toplamRandevuSayisi+1));
    }

    (randevular+i)->hastalar=(hasta*)calloc(1,sizeof(hasta));


    (randevular+i)->randevuNO=(1+toplamRandevuSayisi);
    printf("Randevu no : %d\n\n",(randevular+i)->randevuNO);

    printf("Hastanin adini giriniz : ");
    scanf("%s",(randevular+i)->hastalar->ad);

    printf("\nHastanin TC numarasini giriniz : ");
    scanf("%lld",&(randevular+i)->hastalar->tcNO);

    printf("\nYas giriniz : ");
    scanf("%d",&(randevular+i)->hastalar->yas);
    while(1==1)
    {
        printf("\nHastanin yesil karti var mi?\n1.Var\n2.Yok\nSecim : ");

        scanf("%d",&secim);
        if(secim==1)
        {
            (randevular+i)->hastalar->yesilKart=1;
            break;
        }
        else if(secim==2)
        {
            (randevular+i)->hastalar->yesilKart=0;
            break;
        }
        else
        {
            printf("Gecersiz giris! Tekrar denemek icin bir tusa basiniz\n");
            getch();
        }
    }

    printf("\nPoliklinik no giriniz: ");
    scanf("%d",&(randevular+i)->polNO);

    printf("\nRandevu saatini araya nokta koyarak giriniz: ");
    scanf("%s",(randevular+i)->saat);



    toplamRandevuSayisi++;

    printf("Randevu kaydedilmistir. Ana menuye donmek icin bir tusa basiniz...");
    getch();
    system("CLS");
}
void listele()

{
    int secim;
    printf("Listelemek istediginiz turu seciniz\n1.Hasta\n2.Randevu\n\nSecim : ");
    scanf("%d",&secim);
    switch (secim)
    {
    case 1:
        for(int i=0; i<toplamRandevuSayisi; i++)
        {
            printf("---------------------------------------------------------------------------------\n");
            printf("Hastanin TC numarasi : %d",(randevular+i)->hastalar->tcNO);
            printf("\nHastanin ismi : %s",(randevular+i)->hastalar->ad);
            printf("\nHasta yas : %d",(randevular+i)->hastalar->yas);
            if((randevular+i)->hastalar->yesilKart==1)
                printf("\nHastanin yesil kart durumu : var ");
            else
                printf("\nHastanin yesil kart durumu : yok");
            printf("\n---------------------------------------------------------------------------------\n");
        }
        break;
    case 2:
        for(int i=0; i<toplamRandevuSayisi; i++)
        {
            printf("---------------------------------------------------------------------------------\n");
            printf("Randevu no : %d",(randevular+i)->randevuNO);
            printf("\n\nHasta adi : %s",(randevular+i)->hastalar->ad);
            printf("\n\nPoliklinik No : %d",(randevular+i)->polNO);
            printf("\n\nSaat : %s",(randevular+i)->saat);
            printf("\n---------------------------------------------------------------------------------\n");
        }
        break;
    }
    printf("\nAna menuye donmek icin bir tusa basiniz...");
    getch();
    system("CLS");
}

void randevuGuncelle()
{
    int arananNO,i =0,secim=-1;
    printf("Guncellenecek randevu numarasini giriniz : ");
    scanf("%d",&arananNO);
    (randevular+arananNO)->polNO=25;
    while(i<toplamRandevuSayisi)
    {
        if((randevular+i)->randevuNO==arananNO)
        {
            printf("Randevu no : %d\n\n",(randevular+i)->randevuNO);

            printf("Hastanin adini giriniz : ");
            scanf("%s",(randevular+i)->hastalar->ad);

            printf("\nHastanin TC numarasini giriniz : ");
            scanf("%lld",&(randevular+i)->hastalar->tcNO);

            printf("\nYas giriniz : ");
            scanf("%d",&(randevular+i)->hastalar->yas);
            while(1==1)
            {
                printf("\nHastanin yesil karti var mi?\n1.Var\n2.Yok\nSecim : ");

                scanf("%d",&secim);
                if(secim==1)
                {
                    (randevular+i)->hastalar->yesilKart=1;
                    break;
                }
                else if(secim==2)
                {
                    (randevular+i)->hastalar->yesilKart=0;
                    break;
                }
                else
                {
                    printf("Gecersiz giris! Tekrar denemek icin bir tusa basiniz\n");
                    getch();
                }
            }

            printf("\nPoliklinik no giriniz: ");
            scanf("%d",&(randevular+i)->polNO);

            printf("\nRandevu saatini araya nokta koyarak giriniz: ");
            scanf("%s",(randevular+i)->saat);
            printf("Randevu guncelleme islemi tamamlandi. Ana menuye donmek icin bir tusa basiniz...");
            getch();
            system("CLS");
        }
        i++;
    }
    if(arananNO>toplamRandevuSayisi)
    {
        printf("Randevu bulunamadi. Ana menuye donmek icin bir tusa basiniz...");
        getch();
        system("CLS");

    }
}

void randevuSil()
{
    int silinecek,i;
    printf("Silinecek randevu numarasini giriniz : ");
    scanf("%d",&silinecek);
    if(silinecek>toplamRandevuSayisi||silinecek<=0)

        printf("Gecersiz giris!");

    else
        {
            for(i=(silinecek-1);i<toplamRandevuSayisi;i++)
            {
                *(randevular+i)=*(randevular+i+1);
                (randevular+i)->randevuNO=((randevular+i)->randevuNO)-1;
            }

            toplamRandevuSayisi--;

            randevular = (randevu*) realloc(randevular,sizeof(randevu)*toplamRandevuSayisi);

            printf("Hasta basariyla silindi.");

        }
        printf(" Ana menuye donmek icin bir tusa basiniz...");
        getch();
        system("CLS");

}

void ara()
{
    int secim,i=0,randNo,tc,bul=0;
    printf("Aramak istdigniz turu secniz\n1.Randevu\n2.Hasta\n\nSecim : ");
    scanf("%d",&secim);
    if(secim==1)
    {
        printf("\n\nAramak randevu numarasýný giriniz : ");
        scanf("%d",&randNo);
        while(i<toplamRandevuSayisi)
        {
            if((randevular+i)->randevuNO==randNo)
            {
                bul=1;
                printf("\n\nRandevu no : %d",(randevular+i)->randevuNO);
                printf("\nRandevunun oldugu poliklinik numarasi: %d",(randevular+i)->polNO);
                printf("\nRandevunun saati : %s",(randevular+i)->saat);
                printf("\n");
                break;
            }
            i++;
        }
        if(bul ==0)
        {
            printf("\nRandevu bulunamadi.");
        }
        printf("Ana menuye donmek icin bir tusa basiniz...");
        getch();

    }

    if(secim==2)
    {
        printf("Hastanin TC numarasini giriniz : ");
        scanf("%lld",&tc);
        while(i<toplamRandevuSayisi)
        {
            if(((randevular+i)->hastalar)->tcNO==tc)
            {
                bul=1;
                printf("\nHastanin TC numarasi : %lld",(randevular+i)->hastalar->tcNO);
                printf("\nHastanin adi : %s",(randevular+i)->hastalar->ad);
                printf("\nHastanin yasi : %d",(randevular+i)->hastalar->yas);
                if((randevular+i)->hastalar->yesilKart==1)
                    printf("\nHastanin yesil kart durumu : var");
                else
                    printf("\nHastanin yesil kart durumu : yok");
                printf("\n Ana menuye donmek icin bir tusa basiniz...");
                getch();
                break;
            }
            i++;
        }
        if(bul==0)
        {
            printf("\nHasta bulunamadi! Ana menuye donmek icin bir tusa basiniz...");
            getch();
        }
    }
    system("CLS");
}
void ucretHesapla()
{


int no,i=0;
float ucret;
printf("Hesaplanacak randevunu numarasini giriniz : ");
scanf("%d",&no);
while(i<toplamRandevuSayisi)
{

    if((randevular+i)->randevuNO==no)
    {
        if((randevular+i)->polNO==10)//kbb
            ucret=50;
        else if((randevular+i)->polNO==11)//Cerrahi
            ucret=200;
        else if((randevular+i)->polNO==12)//Çocuk hastalýklarý
            ucret=30;
        else if((randevular+i)->polNO==13)//Dermatoloji
            ucret=60;
        else if((randevular+i)->polNO==14)//Noroloji
            ucret=100;
        else if((randevular+i)->polNO==15)//onkoloji
            ucret=350;
        if(((randevular+i)->hastalar)->yas>65)
            ucret=ucret-(ucret*25/100);
        if(((randevular+i)->hastalar)->yesilKart==1)
            ucret=ucret-(ucret/10);

        (randevular+i)->ucr=ucret;
        printf("Ucret : %.2f",ucret);
    }

    i++;

}
printf("\nAna menuye donmek iicin bir tusa basiniz...");
getch();
system("CLS");
}
int main()
{
    int dongu=1,secim;

    while(dongu==1)
    {

        secim=-1;
        printf("1.Randevu ekle\n2.Listele\n3.Randevu guncelle\n4.Randevu sil\n5.Ara\n6.Ucret Hesapla\n0.Cikis\nSecim : ");
        scanf("%d",&secim);
        switch(secim)
        {
        case 1:
            system("CLS");
            randevuEkle();
            break;
        case 2:
            system("CLS");
            listele();
            break;
        case 3:
            system("CLS");
            randevuGuncelle();
            break;
        case 4:
            system("CLS");
            randevuSil();
            break;
        case 5:
            system("CLS");
            ara();
            break;
        case 6:
            system("CLS");
            ucretHesapla();
            break;
        case 0:
            exit(0);
            break;
        }
    }

    return 0;
}
