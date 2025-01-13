#include <stdio.h>
#include <stdlib.h>
#include"voiture.h"
#include <string.h>

int ID = 0,MAX = 100;

int main() {
    int choix;
    int n;
    char utilisateur[30];
    printf("Entrer votre nom: ");
    scanf("%s", utilisateur);
    fflush(stdin);


    Voiture voitures[MAX];
	charger_donnees(voitures, &MAX);
    do {
        afficher_menu_principal();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_voiture(&voitures[MAX]);
                MAX++;
                break;
            case 2:
                modifier_voiture(voitures, MAX);
                break;
            case 3:
                supprimer_voiture(voitures, &MAX);
                break;
            case 4:
                afficher_voitures_disponibles(voitures, MAX);
                break;
            case 5: {
                char marque_recherchee[20];
                printf("Entrer la marque a rechercher : ");
                scanf("%s", marque_recherchee);
                fflush(stdin);
                rechercher_par_marque(marque_recherchee, voitures, MAX);
                break;
            }
            case 6: {
                int disponible;
                printf("Entrer la disponibilite a rechercher (1 pour disponible / 0 pour non disponible) : ");
                scanf("%d", &disponible);
                rechercher_par_disponibilite(disponible, voitures, MAX);
                break;
            }
            case 7: {
                trier_par_marque(voitures, MAX);
                printf("Les voitures ont ete triees par marque.\n");
                break;
            }
            case 8: {
                trier_par_prix_location(voitures, MAX);
                printf("Les voitures ont ete triees par prix de location par jour.\n");
                break;
            }
            case 9:
                sauvegarder_donnees(voitures, MAX);
                break;
            case 10:
                printf("\n\nAu Revoir %s!.", utilisateur);
                printf("\nMerci d'avoir utilise notre application de gestion de location de voitures!\n");
                break;
            default:
                printf("Option invalide. Veuillez choisir une option valide.\n");
                break;
        }
    } while (choix != 10);

    return 0;
}
