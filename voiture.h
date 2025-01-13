#ifndef VOITURE_H
#define VOITURE_H
typedef struct {
    int id;
    char marque[50];
    char modele[50];
    char type_carburant[20];
    int nombre_places;
    char transmission[20];
    float prix_location_par_jour;
    int disponibilite;
} Voiture;


void afficher_menu_principal();
void ajouter_voiture(Voiture *voitures);
void supprimer_voiture(Voiture *voitures, int *n);
void rechercher_par_marque(char *marque_recherchee, Voiture *voitures, int n);
void rechercher_par_disponibilite(int disponible, Voiture *voitures, int n);
void trier_par_marque(Voiture *voitures, int n);
void trier_par_prix_location(Voiture *voitures, int n);
void sauvegarder_donnees(Voiture *voitures, int n);
void charger_donnees(Voiture *voitures, int *n);


#endif // VOITURE_H
