#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include "ajout_supp.h"
#include "taritement.h"
#include"conio.c"

//menu pricipale statique
void MENU()
{
	  gotoxy(33,3);textattr(13);printf("\3\3\3\3 MENU GENERAL \3\3\3\3");
   gotoxy(17,4);   printf(" ____________________________________________________\n\n");
    gotoxy(17,5);   printf("|                                                    |");
     gotoxy(17,6);printf("|1- CREATION DU REPERTOIRE TELEPHONIQUE              |\n ");
     gotoxy(17,7);printf("|2- MISE A JOUR DES TELEPHONES                       | \n");

     gotoxy(17,8);printf("|3- RECHERCHE,AFFICHAGE ET TRI                       | \n");
     gotoxy(17,9);printf("|4- ENREGISTREMENT ET CHARGEMENT DANS UN FICHIER     | \n");
     gotoxy(17,10);printf("|5- QUITTER                                          | \n");
     gotoxy(17,11);printf("|                                                    |\n");
     gotoxy(17,12);printf("|                                                    | \n");
      gotoxy(17,13);  printf("|____________________________________________________|");
     gotoxy(17,14);printf("\t\t\t\t\t                                              ");
        printf("\n");
        printf("\n");

}
	//menu mise a jour
void menu2 ()
{
     clrscr();gotoxy(24,3);textattr(13);printf("\3\3\3\3 MENU MISE A JOUR \3\3\3\3");
     gotoxy(17,4);   printf(" _______________________________________\n\n");
     gotoxy(17,5);   printf("|                                       |");
     gotoxy(17,6);printf("| 1) AJOUTER UN NOUVEL TELEPHONE        | \n ");
     gotoxy(17,7);printf("| 2) SUPPRIMER UN TELEPHONE             | \n");
     gotoxy(17,8);printf("| 3) MODIFIER LES DONNEES D'UN TELEPHONE| \n");
     gotoxy(17,9);printf("| 4) RETOUR AU MENU GENERALE            |\n");
     gotoxy(17,10);  printf("|_______________________________________|");
     gotoxy(17,11);printf("\t\t\t\t\t\t\t\t");
}
	//menu de Recherche
void menu3 ()
{
     clrscr();gotoxy(27,3);textattr(13);printf("\3\3\3\3 MENU AJOUTER \3\3\3\3");
    gotoxy(17,4);   printf(" _______________________________________\n\n");
    gotoxy(17,5);   printf("|                                       |");
     gotoxy(17,6);printf("| 1) AJOUT EN TETE                      |\n ");
     gotoxy(17,7);printf("| 2) AJOUT EN QUEUE                     | \n");
     gotoxy(17,8);printf("| 3) AJOUT DANS UNR POSITION            | \n");
     gotoxy(17,9);printf("| 4) RETOUR AU MENU MIS A JOUR          | \n");
      gotoxy(17,10);  printf("|_______________________________________|");
     gotoxy(17,11);printf("\t\t\t\t\t\t\t\t");
        printf("\n");
        printf("\n");
}

	//menu de suppression
void menu4 ()
{
   clrscr();gotoxy(27,3);textattr(13);printf("\3\3\3\3 MENU SUPPRESSION \3\3\3\3");
     gotoxy(17,4);   printf(" __________________________________________\n\n");
    gotoxy(17,5);   printf("|                                              |");
     gotoxy(17,6);printf("| 1) SUPPRESSION EN TETE                         |\n ");
     gotoxy(17,7);printf("| 2) SUPPRESSION EN QUEUE                        | \n");
     gotoxy(17,8);printf("| 3) SUPPRESSION A PARTIR D'UNE POSITION         | \n");
     gotoxy(17,9);printf("| 4) SUPPRESSION D'UN TELEPHONE DONNE              | \n");
     gotoxy(17,10);printf("| 5) SUPPRESSION DES TELEPHONES D'UN VILLE DONNEE | \n");
     gotoxy(17,11);printf("| 6) SUPPRESSION DESTELEPHONEs D'UN INDICATIF DONNEE | \n");

     gotoxy(17,12);printf("| 7) RETOUR AU MANU MISE A JOUR            | \n");
     gotoxy(17,13);  printf("|__________________________________________|");
     gotoxy(17,14);printf("\t\t\t\t\t\t\t\t");

        printf("\n");
        printf("\n");
}

	//menu de modification
void menu5 ()
{
   clrscr();gotoxy(25,3);textattr(13);printf("\3\3\3\3 MENU MODIFICATION \3\3\3\3");
   gotoxy(17,4);   printf(" __________________________________________\n\n");
     gotoxy(17,5);   printf("|                                          |");
    gotoxy(17,6);printf("| 1) ADRESSE                               |\n ");
    gotoxy(17,7);printf("| 2) TELEPHONE                             | \n");
    gotoxy(17,8);printf("| 3) RETOUR AU MENU MISE A JOUR            | \n");
    gotoxy(17,9);  printf("|__________________________________________|");
    gotoxy(17,10);printf("\t\t\t\t\t\t\t\t");
        printf("\n");
        printf("\n");

}
void menu6 ()
{
    clrscr();gotoxy(20,3);textattr(13);printf("\3\3\3\3 MENU RECHERCHE ET AFFICHAGE \3\3\3\3");
    gotoxy(17,4);   printf(" __________________________________________\n\n");
    gotoxy(17,5);   printf("|                                          |");
     gotoxy(17,6);printf("| 1) CONTENU DE LA LISTE DES TELEPHONES       |\n ");
     gotoxy(17,7);printf("| 2) RECHERCHE PAR TELEPHONE               | \n");

     gotoxy(17,8);printf("| 3) RECHERCHE PAR NOM                     | \n");
     gotoxy(17,9);printf("| 4) RECHERCHE PAR INDICATIF TELEPHONE     | \n");
    gotoxy(17,10);printf("| 5) RECHERCHE PAR VILLE     | \n");

     gotoxy(17,11);printf("| 6) TRI 1                                 | \n");
     gotoxy(17,12);printf("| 7) TRI 2                                | \n");
     gotoxy(17,13);printf("| 8) RETOUR AU MENU GENERALE              | \n");
      gotoxy(17,14);  printf("|__________________________________________|");
     gotoxy(17,15);printf("\t\t\t\t\t\t\t\t");

}
void menu7 ()
{
    clrscr();gotoxy(17,3);textattr(13);printf("\3\3\3\3 MENU ENREGISTREMENT ET CHARGEMENT \3\3\3\3");
  gotoxy(17,4);   printf(" __________________________________________\n\n");
   gotoxy(17,5);   printf("|                                          |");
    gotoxy(17,6);printf("| 1) ENREGISTREMENT                        |\n ");
    gotoxy(17,7);printf("| 2) CHARGEMENT                            | \n");
    gotoxy(17,8);printf("| 3) RETOUR AU MANU GENERALE               | \n");
    gotoxy(17,9);  printf("|__________________________________________|");
    gotoxy(17,10);printf("\t\t\t\t\t\t\t\t");

}
//program principal

void main ()
{

	int i,choix1,choix2,choix3,choix4,pos,m,s;
	struct contact x;
       liste l=NULL;
       FILE* file;
  do
  {
		do
		{  system("cls");
			menu:	MENU();
			gotoxy(26,23);textcolor(13) ;printf("DONNER VOTRE CHOIX SVP \1  : ");
			scanf("%d",&choix1);
		}while(choix1<1||choix1>5);
		clrscr();
		switch (choix1)
		{
			case 1:system("cls");
			       gotoxy(20,3);textattr(13);  printf("VOUS AVEZ CHOISI LA PARTIE ** CREATION **\n");printf("\n");
			       l=CREATION(l);
			        printf("LISTE CREE \n");
                              AFFICHE(l);
			         gotoxy(40,40);printf("appuyer sur une touche pour retourner au menu");
                                                  getch();system("cls");goto menu;



                     case 2:printf("VOUS AVEZ CHOISI LA PARTIE ** MISE A JOUR DE LA LISTE DES TELEPHONES **\n");
                                                 do
							{ 	bloc2:
							       system("cls");
								menu2();
								gotoxy(20,20);textcolor(13);printf("\n\n \t\t\tONNER VOTRE CHOIX SVP \1  : ");
								scanf("%d",&choix2);
							}while(choix2<1||choix2>14);
							system("cls");
							switch (choix2)
								{
								case 1 :printf("VOUS AVEZ CHOISI LA PARTIE ** AJOUTER **\n");
                                                        do   bloc3:
                                                      { system("cls");
                                                        menu3();
                                                        gotoxy(20,20);textcolor(13);printf("\n\n \t\t\tDONNER VOTRE CHOIX SVP \1  : ");
                                                        scanf("%d",&choix3);
                                                      }while(choix3<1||choix3>14);
                                                       system("cls");

                                                  switch (choix3)
                                                  {
                                            case 1 :
                                                     x=saisie(l);
                                                    l=AJOUT_TETE(l,x);
                                                    AFFICHE(l);
                                                    printf("\n ENREGISTREMENT BIEN AJOUTEE \n");
                                                    gotoxy(20,20);printf("appuyer sur une touche pour retourner au menu");
                                                  getch();system("cls");goto bloc2;
                                            case 2 : x=saisie(l);
                                                    l=AJOUT_QUEUE(l,x);
                                                     AFFICHE(l);
                                                    printf("\n ENREGISTREMENT BIEN AJOUTEE \n");
                                                    gotoxy(20,20);printf("appuyer sur une touche pour retourner au menu");
                                                  getch();system("cls");goto bloc2;
                                            case 3 : x=saisie(l);
                                                    printf("\n DONNER LA POSITION \n");
                                                    scanf("%d",&pos);
                                                    INSERT_POS(l,pos,x);
                                                     AFFICHE(l);
                                                    printf("\n ENREGISTREMENT BIEN AJOUTER \n");
                                                    gotoxy(20,20);printf("appuyer sur une touche pour retourner au menu");
                                                    getch();system("cls"); goto bloc2;
                                            case 4 :
                                                   system("cls"); goto bloc2;
                                            }
                                  case 2 : printf("VOUS AVEZ CHOISI LA PARTIE ** SUPPRESSION **\n");
                                            do   bloc4:
                                                {   system("cls");
                                                    menu4();
                                                    gotoxy(20,20);printf("\n\n \t\t\tDONNER VOTRE CHOIX SVP \1   : ");
                                                        scanf("%d",&choix3);
                                        }while(choix3<1||choix3>7);
                                           system("cls");
                                        switch (choix3)
                                            {
                                            case 1 :
                                                    l=SUPP_TETE(l);
                                                    printf("\n SUPPRESSION TERMINEE\n");
                                                    gotoxy(20,20);printf("appuyer sur une touche pour retourner au menu");
                                                  getch();system("cls");goto bloc2;
                                            case 2 :SUPP_QUEUE(l);
                                                    printf("\n SUPPRESSION TERMINEE\n");
                                                    gotoxy(20,20);printf("appuyer sur une touche pour retourner au menu");
                                                  getch();goto bloc2;
                                            case 3 :printf("\n DONNER LA POSITION\n");
                                                    scanf("%d",&pos);
                                                    SUPP_POS(l,pos);
                                                    printf("\n SUPPRESSION TERMINEE\n");
                                                    gotoxy(20,20);printf("appuyer sur une touche pour retourner au menu");
                                                  getch();system("cls");goto bloc2;
                                            case 4 :

                                                    l=supp_tel(l);
                                                      printf("\n SUPPRESSION TERMINEE\n");
                                                    gotoxy(40,40);printf("appuyer sur une touche pour retourner au menu");
                                                  getch();system("cls");goto bloc2;
                                            case 5 :printf("\n donner le VILLE  \n");
                                                    scanf("%d",&s);
                                                    supp_ville(l);
                                                    printf("\n  SUPPRESSION TERMINEE\n");
                                                    gotoxy(40,40);printf("appuyer sur une touche pour retourner au menu");
                                                    getch();system("cls");goto bloc2;

                                            case 6 :printf("\n donner le indicatif  \n");
                                                    scanf("%d",&s);
                                                    indicatif(l);
                                                    printf("\n  SUPPRESSION TERMINEE\n");
                                                    gotoxy(40,40);printf("appuyer sur une touche pour retourner au menu");
                                                    getch();system("cls");goto bloc2;
                                            case 7 :
                                                    system("cls"); goto bloc2;
                                            }



                                     case 3:printf("VOUS AVEZ CHOISI LA PARTIE ** MODIFICATION ** \n");


                                        do   bloc5:
                                                { 	system("cls");
                                                    menu5();
                                                    gotoxy(20,20);textcolor(13) ;printf("\n\n \t\t\tDONNER VOTRE CHOIX SVP \1: ");
                                                        scanf("%d",&choix3);
                                        }while(choix3<1||choix3>3);
                                            system("cls");
                                        switch (choix3)
                                            {
                                            case 1 :
                                                     printf("\n VOUS ALLEZ MODIFIER L ADRESSE \n");
                                                    modifie_adress (l);

                                                    gotoxy(20,20);printf("appuyer sur une touche pour retourner au menu");
                                                  getch();system("cls");goto bloc2;
                                            case 2 :
                                                    printf("\n VOUS ALLEZ MODIFIER LE TELEPHONE \n");
                                                     modifie_tel(l);
                                                    gotoxy(40,40);printf("appuyer sur une touche pour retourner au menu");
                                                     getch();system("cls");goto bloc2;


                                            case 3 : system("cls"); goto menu;
                                             }
                                   case 4 : system("cls");goto menu;
								}




              case 3: printf("VOUS AVEZ CHOISI LA PARTIE ** RECHERCHE ET AFFICHAGE **");
			                       do   bloc6:
							{ 	system("cls");
								menu6();
								gotoxy(20,20);textcolor(13) ;printf("   Donner Votre Choix SVP   : ");
								scanf("%d",&choix3);
							}while(choix3<1||choix3>8);
							system("cls");
							switch (choix3)
								{
								case 1 : printf("\n CONTENU DE LA LISTE : \n");
                                            l=recuperation(file,l);
								            AFFICHE(l);
											gotoxy(20,20);printf("appuyer sur une touche pour retourner au menu");
											getch();system("cls");goto bloc3;



								case 2:     affiche_tel(l);
											gotoxy(20,20);printf("appuyer sur une touche pour retourner au menu");
											getch();goto menu;

								case 3:
                                             affiche_nom(l);
											gotoxy(20,20);printf("appuyer sur une touche pour retourner au menu");
											getch();goto menu;


								case 4 :
								         indicatif(l);
											gotoxy(20,20);printf("appuyer sur une touche pour retourner au menu");
											getch();
								case 6 :
								            tri_dec(l);
								            printf("CONTENU DE LA LISTE APRES TR\nI");
								            AFFICHE(l);
											gotoxy(20,20);printf("appuyer sur une touche pour retourner au menu");
											getch();

								case 7 :
								            tri_dec(l);
								            printf("CONTENU DE LA LISTE APRES TR\nI");
								            AFFICHE(l);
											gotoxy(20,20);printf("appuyer sur une touche pour retourner au menu");
											getch();
								case 8 : system("cls");goto menu;

								}


			case 4 :printf("VOUS AVEZ CHOISI LA PARTIE ** ENREGISTREMENT ET CHARGEMENT DANS UN FICHIER **"); do   bloc7:
							{ 	system("cls");
								menu7();
								gotoxy(20,20);textcolor(13) ;printf("  DONNER VOTRE CHOIX SVP \1  : ");
								scanf("%d",&choix3);
							}while(choix3<1||choix3>3);
							clrscr();
							switch (choix3)
								{
								case 1 :enregistrement(l);
                                                          printf(" LISTE ENREGISTREE");

											gotoxy(20,20);printf("appuyer sur une touche pour retourner au menu");
											getch();system("cls");goto menu;

								case 2 :l=recuperation(file,l);           printf(" \nCONTENUE DE LA LISTE \n");
                                                                      AFFICHE(l);


                                                                    gotoxy(20,20); printf("appuyer sur une touche pour retourner au menu");
											getch();system("cls");goto menu;

								case 3:system("cls");goto menu;


								}


			case 5:
                                 system("cls");

		                     for(i=0;i<3;i++)
						  {
                                          gotoxy(8,8);textcolor(13);printf("\nCE PROJET EST ELABORE PAR");textcolor(6);printf(" ****rania *****\n ");
                                         gotoxy(12,12);textcolor(13);printf("\n");printf("\n MERCI POUR VOTRE ATTENTION ! ^_^ \n "); }

		                      exit(0);

		 } }
  while(choix1!=6);
}
