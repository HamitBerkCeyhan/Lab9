#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	struct student{
		int number;
		char name[20];
		int vize;
		int final;
	};
	struct student *ptr;
	int eb_ort=0, i, n, secim, ort, toplam=0, m=0, k, no;
	char *ad[20];
	printf("Sinifinizda kac Ogrenci var? ");
	scanf("%d",&n);
	printf("\n");
	ptr=(struct student *)malloc(n * sizeof(struct student));
	for(i=0; i<n; i++)
	{
		printf("Ogrencinin numara, ad, vize ve final bilgilerini giriniz: \n");
		scanf("%d %s %d %d",&(ptr+i)->number,&(ptr+i)->name,&(ptr+i)->vize,&(ptr+i)->final);
	}
	printf("\n");
	printf("Yapmak istediginiz Islemi Seciniz:\n\n");
	printf("1-Yeni Kayit Eklemek icin\n2-Kayit Listeleme icin\n3-Kayit Guncelleme icin\n4-Sinif Ortalamasini Hesaplamak icin\n5-Ortalamaya gore En Basarili Ogrenci icin \n\nSeciminiz: ");
        scanf("%d",&secim);
          if(secim == 1)
        {
    	  printf("\n");
    	  printf("Kac Adet Yeni Kayit Ekleyeceksiniz?: ");
    	  scanf("%d",&m);
    	  printf("\n");
    	  ptr=(struct student *)realloc(ptr,(n+m)*sizeof(struct student));
    	     for(i=n;i<(n+m);i++)
    	  {
    		printf("Ogrencinin numara, ad, vize ve final bilgilerini giriniz:  \n");
                scanf("%d %s %d %d",&(ptr+i)->number,&(ptr+i)->name,&(ptr+i)->vize,&(ptr+i)->final);
	   }	
	}
         else if(secim == 2)
        {
    	    for(i=0; i<(n+m); i++)
    	    {
    		printf("%d %s %d %d \n",(ptr+i)->number,(ptr+i)->name,(ptr+i)->vize,(ptr+i)->final);
	    }
	}
	else if(secim == 3)
	{
		printf("Hangi sirada ki kayidi yenilemek istiyorsunuz: ");
		scanf("%d",&k);
		printf("Ogrencinin numara, ad, vize ve final bilgilerini giriniz:  \n");
		scanf("%d %s %d %d",&(ptr+k)->number,&(ptr+k)->name,&(ptr+k)->vize,&(ptr+k)->final);
		printf("\n");
		for(i=0; i<(n+m); i++)
                {
    		printf("%d %s %d %d \n",(ptr+i)->number,(ptr+i)->name,(ptr+i)->vize,(ptr+i)->final);
		}
	}
	else if(secim == 4)
	{
		for(i=0; i<(n+m); i++)
		{
			toplam=toplam+ ((ptr+i)->vize)*0.4 + ((ptr+i)->final)*0.6;
		}
		ort=toplam/(n+m);
		printf("Ortlama: %d",ort);
	}
	else if(secim == 5)
	{
		for(i=0; i<(n+m); i++)
		{
			ort= ((ptr+i)->vize*0.4+(ptr+i)->final*0.6);
			if(ort>eb_ort)
			{
				eb_ort=ort;
				no=(ptr+i)->number;
				ad[20]=(ptr+i)->name;
			}
		}
		printf("Ortalamaya gore en basarili ogrenci = %d %s %d", no, ad, eb_ort);
	}
}
