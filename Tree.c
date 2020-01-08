#include <stdio.h>
#include <stdlib.h>

typedef struct agac
{
	short veri;
	struct agac *sol,*sag;
}agac;

agac *kok=NULL;

ekle(short neyi)
{
	agac *yeni=malloc(sizeof(agac));
	yeni->veri=neyi;
	yeni->sol=NULL;
	yeni->sag=NULL;
	if(kok==NULL)
	{
		kok=yeni;
	}
	else
	{
		agac *nomad=kok;
		agac *mother=kok;
		//nomad ý iteliyoruz
		while(nomad!=NULL)
		{
			mother=nomad; // anneye baglýyoruz geziciyi..
			if(neyi > nomad->veri)
			{
				nomad=nomad->sag;
			}
			else
			{
				nomad=nomad->sol;
			}
		}
		
		//yeni yi baðlýyoruz
		if(neyi > mother->veri)
		{
			mother->sag=yeni;
		}
		else
		{
			mother->sol=yeni;
		}
	}
}

goster(agac *nomad)
{
	if(nomad!=NULL)
	{
		
		goster(nomad->sag);
		printf("%d,",nomad->veri);
		goster(nomad->sol);		
	}
}

ara(short neyi)
{
	agac *nomad=kok;
	
	while(nomad!=NULL && nomad->veri!=neyi)
	{
		if(neyi  >  nomad->veri)
		{
			nomad=nomad->sag;
		}
		else
		{
			nomad=nomad->sol;
		}
	}
	if(nomad==NULL) printf("Bulunmadi..\n");
	else if(nomad!=NULL)
	{
		printf("Aradiginiz = %d\n",nomad->veri);
	}
}
agac *minbul(agac *dugum)
{
	if(dugum==NULL)
	{
		return NULL;
	}
	if(dugum->sol != NULL)
	{
		return minbul(dugum->sol);
	}
	else
	{
		return dugum;
	}
}
enkucuk()
{
	agac *nomad=kok;
	while(nomad->sol!=NULL)
	{
		nomad=nomad->sol;
	}
	printf("\nenkucuk=%d\n",nomad->veri);
}

agac *sil(agac *nomad, short neyi)
{
	if(nomad==NULL)
	{
		printf("Bulamadim!");	
	}
	else if(neyi < nomad->veri)
	{
		nomad->sol=sil(nomad->sol,neyi);
	}
	else if(neyi > nomad->veri)
	{
		nomad->sag=sil(nomad->sag,neyi);
	}
	else
	{
		if(nomad->sag != NULL && nomad->sol!=NULL)
		{
			agac *temp;
			temp=minbul(nomad->sag);
			nomad->veri=temp->veri;
			nomad->sag=sil(nomad->sag,temp->veri);	
		}
		else
		{
			if(nomad->sol == NULL)
			{
				nomad=nomad->sag;
			}
			else if(nomad->sag == NULL)
			{
				nomad=nomad->sol;				
			}
		}	
	}
	return nomad;
}

main()
{
	
	ekle(10);
	ekle(55); 
	//ara(50);
	ekle(2);
	ekle(40);
	
	//goster(kok);
	sil(kok,40);
	goster(kok);
	//enkucuk();
}
