#include"voiture.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void afficher_menu_principal() {
    printf("\nBienvenue dans l'application de gestion de location de voitures\n");
    printf("1. Ajouter une voiture\n");
    printf("2. Modifier une voiture\n");
    printf("3. Supprimer une voiture\n");
    printf("4. Afficher la liste des voitures \n");
    printf("5. Rechercher des voitures par marque\n");
    printf("6. Rechercher des voitures par disponibilite\n");
    printf("7. Trier les voitures par marque\n");
    printf("8. Trier les voitures par prix de location par jour\n");
    printf("9. Sauvegarder les donnees dans un fichier texte\n");
    printf("10. Quitter\n");
    printf("Choisissez une option : ");
}

void ajouter_voiture(Voiture *voitures) {

    printf("\nVeuillez saisir les informations de la voiture :\n");
    printf("Marque : ");
    scanf("%s", voitures->marque);
    fflush(stdin);
    printf("Modele : ");
    scanf("%s", voitures->modele);
    fflush(stdin);
    printf("Type de carburant : ");
    scanf("%s", voitures->type_carburant);
    fflush(stdin);
    printf("Nombre de places : ");
    scanf("%d", &voitures->nombre_places);
    printf("Transmission (automatique ou manuelle) : ");
    scanf("%s", voitures->transmission);
    fflush(stdin);

    printf("Prix de location par jour : ");
    scanf("%f", &voitures->prix_location_par_jour);

    do {
        printf("Disponibilite (1 pour disponible / 0 pour non disponible) : ");
        scanf("%d", &voitures->disponibilite);
        if (voitures->disponibilite > 1 || voitures->disponibilite < 0) {
            printf("Disponibilite non valide! Entrez une disponibilite entre 0 et 1\n");
        }
    } while (voitures->disponibilite > 1 || voitures->disponibilite < 0);

    printf("\nLa voiture a ete ajoutee avec succes.\n");
    int ID=0;
    voitures->id = ID ;
    ID++;
}

Voiture modifier_voiture(Voiture *voitures, int n) {
    int id_modification;
    printf("\nEntrez l'ID de la voiture que vous souhaitez modifier : ");
    scanf("%d", &id_modification);

    int i;
    for (i = 0; i < n; i++) {
        if ((voitures+i)->id == id_modification) {
            printf("\nEntrez les nouvelles informations :\n");
            printf("Marque : ");
            scanf("%s", (voitures+i)->marque);
            fflush(stdin);
            printf("Modele : ");
            scanf("%s", (voitures+i)->modele);
            fflush(stdin);
            printf("Type de carburant : ");
            scanf("%s", (voitures+i)->type_carburant);
            fflush(stdin);
            printf("Nombre de places : ");
            scanf("%d", &(voitures+i)->nombre_places);
            printf("Transmission (automatique ou manuelle) : ");
            scanf("%s", (voitures+i)->transmission);
            fflush(stdin);
            printf("Prix de location par jour : ");
            scanf("%f", &(voitures+i)->prix_location_par_jour);

            printf("\nLa voiture a ete modifiee avec succes.\n");
        return *voitures;
        }
    }

    printf("\nAucune voiture avec cet ID n'a ete trouvee.\n");
    return *voitures;
}

void supprimer_voiture(Voiture *voitures, int *n) {
    int id_suppression;
    printf("\nEntrez l'ID de la voiture que vous souhaitez supprimer : ");
    scanf("%d", &id_suppression);

    int i;
    for (i = 0; i < *n; i++) {
        if (voitures[i].id == id_suppression) {
            int j;
            for (j = i; j < *n - 1; j++) {
                voitures[j] = voitures[j + 1];
            }

            (*n)--;

            printf("\nLa voiture a ete supprimee avec succes.\n");
            return;
        }
    }

    printf("\nAucune voiture avec cet ID n'a ete trouvee.\n");
}

Voiture afficher_voitures_disponibles(Voiture *voitures, int n) {
    printf("\nListe des voitures disponibles :\n");
    printf("ID | Marque | Modele | Type de carburant | Nombre de places | Transmission | Prix de location par jour | Disponibilite\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    int i;
    for (i = 0; i < n; i++) {

            printf("%d | %s | %s | %s | %d | %s | %.2f | %d\n", (voitures+i)->id, (voitures+i)->marque,
                   (voitures+i)->modele, (voitures+i)->type_carburant, (voitures+i)->nombre_places, (voitures+i)->transmission,
                   (voitures+i)->prix_location_par_jour, (voitures+i)->disponibilite);

    }
    return *voitures;
}

void rechercher_par_marque(char *marque_recherchee, Voiture *voitures, int n) {
    printf("\nVoitures de la marque '%s' :\n", marque_recherchee);
    printf("ID | Marque | Modele | Type de carburant | Nombre de places | Transmission | Prix de location par jour | Disponibilite\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(voitures[i].marque, marque_recherchee) == 0) {
            printf("%d | %s | %s | %s | %d | %s | %.2f | %d\n", voitures[i].id, voitures[i].marque,
                   voitures[i].modele, voitures[i].type_carburant, voitures[i].nombre_places, voitures[i].transmission,
                   voitures[i].prix_location_par_jour, voitures[i].disponibilite);
                   fflush(stdin);
        }
    }
}

void rechercher_par_disponibilite(int disponible, Voiture *voitures, int n) {
    printf("Voitures ");
    if (disponible) {
        printf("non ");
    }
    printf("disponibles :\n");
    printf("ID | Marque | Modele | Type de carburant | Nombre de places | Transmission | Prix de location par jour | Disponibilite\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    int i;
    for (i = 0; i < n; i++) {
        if (voitures[i].disponibilite == disponible) {
            printf("%d | %s | %s | %s | %d | %s | %.2f | %d\n", voitures[i].id, voitures[i].marque,
                   voitures[i].modele, voitures[i].type_carburant, voitures[i].nombre_places, voitures[i].transmission,
                   voitures[i].prix_location_par_jour, voitures[i].disponibilite);
        }
    }
}

void trier_par_marque(Voiture *voitures, int n) {
    int i, j;
    Voiture temp;
    for (i = 1; i < n; i++) {
        temp = voitures[i];
        j = i - 1;
        while (j >= 0 && strcmp(voitures[j].marque, temp.marque) > 0) {
            voitures[j + 1] = voitures[j];
            j = j - 1;
        }
        voitures[j + 1] = temp;
    }
}

void trier_par_prix_location(Voiture *voitures, int n) {
    int i, j;
    Voiture temp;
    for (i = 1; i < n; i++) {
        temp = voitures[i];
        j = i - 1;
        while (j >= 0 && voitures[j].prix_location_par_jour > temp.prix_location_par_jour) {
            voitures[j + 1] = voitures[j];
            j = j - 1;
        }
        voitures[j + 1] = temp;
    }
}

void sauvegarder_donnees(Voiture *voitures, int n) {
    FILE *fichier;
    fichier = fopen("voitures.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    fprintf(fichier, "ID | Marque | Modele | Type de carburant | Nombre de places | Transmission | Prix de location par jour | Disponibilite\n");
    fprintf(fichier, "----------------------------------------------------------------------------------------------------------------------\n");
    int i;
    for (i = 0; i < n; i++) {
        fprintf(fichier, "%d | %s | %s | %s | %d | %s | %.2f | %d\n", voitures[i].id, voitures[i].marque,
                voitures[i].modele, voitures[i].type_carburant, voitures[i].nombre_places, voitures[i].transmission,
                voitures[i].prix_location_par_jour, voitures[i].disponibilite);
    }

    fclose(fichier);
    printf("\nLes donnees ont ete sauvegardees dans le fichier 'voitures.txt'.\n");
}
void charger_donnees(Voiture *voitures, int *n) {
    FILE *fichier;
    fichier = fopen("voitures.txt", "r");
    if (fichier == NULL) {
        printf("Le fichier de donnees n'existe pas ou ne peut pas etre ouve.rt.\n");
        return;
    }

    char ligne[256];
    fgets(ligne, sizeof(ligne), fichier);
    *n = 0;
    while (fgets(ligne, sizeof(ligne), fichier) != NULL && *n < 100) {
        Voiture nouvelle_voiture;
        sscanf(ligne, "%d | %s | %s | %s | %d | %s | %f | %d", &nouvelle_voiture.id, nouvelle_voiture.marque,
               nouvelle_voiture.modele, nouvelle_voiture.type_carburant, &nouvelle_voiture.nombre_places,
               nouvelle_voiture.transmission, &nouvelle_voiture.prix_location_par_jour, &nouvelle_voiture.disponibilite);
        voitures[*n] = nouvelle_voiture;
        (*n)++;
    }

    fclose(fichier);
    printf("\nLes donnees ont ete chargees a partir du fichier 'voitures.txt'.\n");
}

