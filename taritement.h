#ifndef TARITEMENT_H_INCLUDED
#define TARITEMENT_H_INCLUDED
int construction(char *ligne,int pos,char s,char *ch)
{
    int i,j;
    for(i=pos,j=0;ligne[i]!=s;i++)
            ch[j++]=ligne[i];
        ch[j]='\0';
    //puts(ch);
    return i+1;
}
void enregistrement(liste l)
{
    int i;
    FILE *fp;
    fp=fopen("fichier.txt","w");
    while(l)
    {

        fprintf(fp,"|%ld|%s|%s|%s|%d/%d/%d|%s|%s|%d|\n",l->info.telephone,l->info.nom,l->info.prenom,l->info.email,l->info.DA.j,l->info.DA.m,l->info.DA.a,l->info.adr.rue,l->info.adr.ville,l->info.adr.code_postale);
        l=l->suiv;
    }
    fclose(fp);
    printf ("\nEnregistrement du tableau dans le fichier %s \n","fihcier.txt");
}

liste recuperation()
{

    FILE *fp;
    liste p=NULL;
    struct contact c;
    int pos;
    char ligne[100];
    char ch[5];
    char e[30];
    fp=fopen("fichier.txt","r");

    if(fp==NULL)
         printf("LISTE CONTACT  VIDE\\");
    else
       while(fgets(ligne,100,fp)!=NULL)
       {
            pos=construction(ligne,1,'|',e);
            c.telephone=atol(e);
            pos=construction(ligne,pos,'|',c.nom);
            pos=construction(ligne,pos,'|',c.prenom);
            pos=construction(ligne,pos,'|',c.email);
            pos=construction(ligne,pos,'/',ch);
            c.DA.j=atoi(ch);
            pos=construction(ligne,pos,'/',ch);
            c.DA.m=atoi(ch);
            pos=construction(ligne,pos,'|',ch);
            c.DA.a=atoi(ch);
            pos=construction(ligne,pos,'|',c.adr.ville);
            pos=construction(ligne,pos,'|',c.adr.rue);
            pos=construction(ligne,pos,'|',e);
            c.adr.code_postale=atoi(e);
            p=AJOUT_QUEUE(p,c);

       }
    fclose(fp);
    return p;
}


void affiche_nom (liste l)
{
       int ok=0;
       liste p;
       char n[20];
       printf("\donner le nom de contact a chercher \n");
       scanf("%d",&n);

       while (p && ok==0)
       {
              if (n==p->info.nom)
              {
                     ok=1;
        printf("|%ld|%s|%s|%s|%d/%d/%d|%s|%s|%d|\n",l->info.telephone,l->info.nom,l->info.prenom,l->info.email,l->info.DA.j,l->info.DA.m,l->info.DA.a,l->info.adr.rue,l->info.adr.ville,l->info.adr.code_postale);
              }
              else
                      p=p->suiv;
       }
if(ok==0)
       printf("\n Nom Introuvable  \n ");
}
void affiche_tel (liste l)
{
       int ok=0;
       long int t;
       liste p=l;
       printf("\donner le numero de telephone a chercher \n");
       scanf("%d",&t);

       while (p && ok==0)
       {
              if (t==p->info.telephone)
              {
                     ok=1;
        printf("|%ld|%s|%s|%s|%d/%d/%d|%s|%s|%d|\n",l->info.telephone,l->info.nom,l->info.prenom,l->info.email,l->info.DA.j,l->info.DA.m,l->info.DA.a,l->info.adr.rue,l->info.adr.ville,l->info.adr.code_postale);

              }
              else
            p=p->suiv;
       }
       if(ok==0)
       printf("\n Numero de Telephone  Introuvable \n ");

}

void indicatif (liste l)
{
    int ind,r,ok=0;
    liste p=l;
    printf("donner l indicatif a chercher  ");
    scanf("%d",&ind);
    while (p)
    {       r=p->info.telephone/1000000;
           if (r==ind)
           {
              ok=1;
        printf("|%ld|%s|%s|%s|%d/%d/%d|%s|%s|%d|\n",l->info.telephone,l->info.nom,l->info.prenom,l->info.email,l->info.DA.j,l->info.DA.m,l->info.DA.a,l->info.adr.rue,l->info.adr.ville,l->info.adr.code_postale);
           }
       p=p->suiv;
    }
 if(ok==0)
       printf("\n Aucun numero n est trouvee \n ");
}
void tri1(liste l)
{
    int ok;
    liste p;
   float aux;
    do
    {   p=l;
        ok=1;
        while(p->suiv !=NULL)
            if(p->info.telephone <p->suiv->info.telephone)
             {
                    aux=p->info.telephone;
                    p->info.telephone=p->suiv->info.telephone;
                    p->suiv->info.telephone=aux;
                    ok=0;
            }
        p=p->suiv;
    }while(! (ok==1));
}
void modifie_tel(liste l)

{  int m,ok=0;
   long int t;
   liste p=l;
       printf("\nDonner le nom de contact a modifier : \n");
       scanf("%d",&m);
        while (p && ok==0)
       {
              if (m==p->info.nom)
              {
                     ok=1;
                     printf("donner le nouveau num de telephone : \n");
                     scanf("%ld",&p->info.telephone);


              }
              else
            p=p->suiv;
       }
       if (ok==0)
              printf("\n nom introuvable \n");
       else
              {printf("modification terminee \n");

             }

}
void modifie_adress(liste l)

{  int m,ok=0;
   liste p=l;
       printf("\nDonner le nom de contact a modifier : ");
       scanf("%d",&m);
        while (p && ok==0)
       {
              if (m==p->info.nom)
              {
                     ok=1;
                     printf("donner la nouvelle ville : ");
                     fflush(stdin);
              gets(p->info.adr.ville);
                       printf("donner la nouvelle rue : ");
                    fflush(stdin);
              gets(p->info.adr.rue);
                       printf("donner la nouvelle code postale : ");
                     scanf("%d",&p->info.adr.code_postale);


              }
              else
            p=p->suiv;
       }
       if (ok==0)
              printf("\n nom introuvable \n");
       else
              {
               printf("modification terminee \n");

             }

}


void tri_dec(liste l)
{
    liste p=l ,p2;
    float aux;
  while(p->suiv)
  {
   p2=p->suiv ;
    while (p2)
    {
        if (p->info.telephone<p2->info.telephone)
        {
         aux =p->info.telephone ;
         p->info.telephone=p2->info.telephone;
         p2->info.telephone=aux ;
        }
        p2=p2->suiv ;
     }
    p=p->suiv;
  }
}



#endif // TARITEMENT_H_INCLUDED
