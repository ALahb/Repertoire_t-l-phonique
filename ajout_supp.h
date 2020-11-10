#ifndef AJOUT_SUPP_H_INCLUDED
#define AJOUT_SUPP_H_INCLUDED

#include<malloc.h>
struct date
{
    int j,m,a;
};
struct adresse{
char ville[20],rue[20];
int code_postale;
};
struct contact
{
    long int telephone;
    char nom[20],prenom[20],email[50];
    struct adresse adr;
    struct date DA;

};
struct cellule
{
    struct contact info;
    struct cellule * suiv;
};
typedef struct cellule * liste;

liste AJOUT_TETE(liste l, struct contact x )
{
	 liste p;
	 p=(struct cellule *) malloc(sizeof( struct cellule));
	 p->suiv=l;
	 p->info=x;
	 l=p;
	 return l;
}

liste AJOUT_QUEUE(liste l, struct contact x  )
{
	 liste p,p1;
	 if(l==NULL)
		  l=AJOUT_TETE(l,x);
	 else
	 {
		  p1=l;
		  while(p1->suiv!=NULL)
		  {
				p1=p1->suiv;
		  }
		  p=(struct cellule *)malloc(sizeof(struct cellule));
		  p->info=x;
		  p->suiv=NULL;
		  p1->suiv=p;
	 }
	 return l;
}

void INSERT_POS(liste l, int pos,struct contact x )
{
	 liste p,p1=l;
	 int i=1;
	 while(i<pos-1)
	 {   p1=p1->suiv;
		  i++;
	 }
	 p=(struct cellule *)malloc(sizeof(struct cellule));
	 p->info=x;
	 p->suiv=p1->suiv;
	 p1->suiv=p;
}

int TAILLE(liste l)
{   liste  p=l;
	 int x=0;
	 while(p!=NULL)
	 {   x++;
		  p=p->suiv;
	 }
    return  x;
}
void AFFICHE(liste l)
{
    if (l == NULL)
        printf("Liste Vide");
	 else
        while(l!=NULL)
        {
        printf("|%ld|%s|%s|%s|%d/%d/%d|%s|%s|%d|\n",l->info.telephone,l->info.nom,l->info.prenom,l->info.email,l->info.DA.j,l->info.DA.m,l->info.DA.a,l->info.adr.rue,l->info.adr.ville,l->info.adr.code_postale);
        l=l->suiv;
        }
}

liste  SUPP_TETE(liste l)
{   liste p=l;
    l=l->suiv;
    free(p);
	 return(l);
}

void SUPP_QUEUE(liste l)
{   liste p=l;
    while((p->suiv)->suiv != NULL )
        p=p->suiv;
    free(p->suiv);
	 p->suiv=NULL;
}


void SUPP_POS(liste  l,int pos)
{   liste p1=l,p2;
    int i=1;
    while ( i<pos-1)
	 {   i++;
        p1=p1->suiv;
    }
    p2=p1->suiv;
	 p1->suiv=p2->suiv;
    free(p2);
}
liste supp_tel(liste l)
{
    liste p=l,q;
    long int x;
    int ok = 0;
    do{
    printf("\Donner le numero a supprimer: ");
    scanf("%d",&x);}while(!(testnum(x)));
        if (p->info.telephone == x)
        {
            l = p->suiv;
            free(p);
        }
        else
        {
            while(p->suiv!=NULL)
                if ((p->suiv)->info.telephone == x)
                {
                    ok = 1;
                    break;
                }
                else
                    p=p->suiv;

                if (ok)
                {
                    q=p->suiv;
                    p->suiv = q->suiv;
                    free(q);
                }
                else
                    printf("\n %d Ce telephone n'existe pas dans la liste\n",x);
        }
    return l;
}

liste supp_ville(liste l)
{
    liste p=l,q=NULL;
    int ok = 0;
    char ch[20];
    printf("\nDonner la ville: ");
    fflush(stdin);
    gets(ch);
    while(p){
        if (strcmp((p->info.adr.ville),ch)==0)
        {
            ok=1;
           if (q == NULL)
            {
                l = p->suiv;
                free(p);
                p=l;

            }
            else
            {
               q ->suiv = p->suiv;
               free(p);
               p = q->suiv;
            }
        }
        else
        {
            q = p;
            p = p->suiv;
        }
        }
        if(ok==0)
            printf("cet ville n'existe pas!\n");
            else
                printf("SUPRESSION TERMINEE!");
    return l;
}


int testnum(long int x){
    char s[20];
    sprintf(s, "%ld", x);

    if((s[0]=='5' || s[0]=='2' ||s[0]=='9' || s[0]=='7') && strlen(s)==8)
        return 1;

    else
        return 0;

}
int test1(liste l,long int c)
{
    liste p=l;
    int ok=0;
    while(p && ok==0)
    {
        if(c==p->info.telephone)
        {
            ok=1;

        }
        else
              p=p->suiv;
    }
    return ok;
}
liste CREATION(liste l)
{
	int pos,t,rep,i=0,x=20,y=4;

	liste p;
	l=NULL;
	struct contact e;

	do
	{

		t=TAILLE(l);
		do
		{      printf("\n");
		printf("\n");
			 gotoxy(x,y);textattr(13); printf("donnez la position entre 1 et %d : ",t+1);
			scanf("%d",&pos);
		}while(pos>t+1||pos<1);
              printf("\n");
              y=y+2;

		gotoxy(x,y);printf(" SAISIE DES INFORMATIONS \n");printf("\n");printf("\n");
		i++;
		y=y+4;
		gotoxy(x,y);textattr(11); printf("Telephone %d\n",i);

              p=(struct cellule *)malloc(sizeof(struct cellule));

               do
            {
                printf("Donner le numero de telephone: ");
                fflush(stdin);
                 scanf("%d",&e.telephone);
            }while(!((test1(l,e.telephone)==0)&& testnum(e.telephone)));




              printf("Donner la nom : ");
              fflush(stdin);
              gets(e.nom);



              printf("Donner le prenom : ");
              fflush(stdin);
              gets(e.prenom);

             printf("Donner la rue : ");
             fflush(stdin);
              gets(e.adr.rue);

             printf("Donner la ville : ");
             fflush(stdin);
              gets(e.adr.ville);

            do{
             printf("Donner code postale : ");
              scanf("%d",&e.adr.code_postale);
              }while((e.adr.code_postale)==0);

             printf("Donner la date de naissance:\n ");

            do
            {
                 printf("Donner le jour : ");
                fflush(stdin);
                  scanf("%d",&e.DA.j);
        }while(e.DA.j<1 || e.DA.j>31);

        do
        {
                  printf("Donner le mois : ");
                fflush(stdin);
                scanf("%d",&e.DA.m);
        }while(e.DA.m<1 || e.DA.m>12);


              do
              {
                printf("Donner l'annee : ");
                fflush(stdin);
                 scanf("%d",&e.DA.a);
              }while(e.DA.a < 1900);


              printf("Donner l'email: ");
              fflush(stdin);
              gets(e.email);


	   // do
             //{



		if (pos==1)
			l=AJOUT_TETE(l,e);
		else
			if (pos==t+1)
				l=AJOUT_QUEUE(l,e);
			else
				INSERT_POS(l,pos,e);
		do
		{
			printf("\nvoulez vous continuez la saisie? ( 1:OUI 0:NON )   :  ");
			scanf("%d",&rep);
		}while((rep!=1)&&(rep!=0)  ) ;
		y=y+20;

	}while(rep!=0);
return l;
}
struct contact saisie (liste l)
{ liste p;
struct contact t;
      p=(struct cellule*)malloc(sizeof(struct cellule));
           do
            {
                printf("Donner la telephone : ");
                fflush(stdin);
                scanf("%d",&t.telephone);
            }while(!((test1(l,t.telephone)==0)&& testnum(t.telephone)));


            printf("Donner la nom : ");
            fflush(stdin);
            gets(t.nom);

            printf("Donner le prenom : ");
            fflush(stdin);
            gets(t.prenom);


             printf("Donner la rue : ");
             fflush(stdin);
              gets(t.adr.rue);

             printf("Donner la ville : ");
             fflush(stdin);
              gets(t.adr.ville);

            do

            {
             printf("Donner code postale : ");
             fflush(stdin);
              scanf("%d",&t.adr.code_postale);
              }while((t.adr.code_postale)==0);

             printf("\nDonner la date de naissance: \n");

            do
            {
                 printf("Donner le jour : ");
                fflush(stdin);
                  scanf("%d",&t.DA.j);
        }while(t.DA.j<1 || t.DA.j>31);

        do
        {
                  printf("Donner le mois : ");
                fflush(stdin);
                scanf("%d",&t.DA.m);
        }while(t.DA.m<1 || t.DA.m>12);


              do
              {
                printf("Donner l'annee : ");
                fflush(stdin);
                 scanf("%d",&t.DA.a);
              }while(t.DA.a < 1900);


              printf("Donner l'email: ");
              fflush(stdin);
              gets(t.email);

return t;


}


#endif // AJOUT_SUPP_H_INCLUDED
