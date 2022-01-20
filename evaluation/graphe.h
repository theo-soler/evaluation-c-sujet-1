#include <iostream>
#include <vector>
#include <climits>

//on définit un sommet par son nom et un numéro (correspondant en fait à sa position dans les liste et matrice d'adjacence) et un booléen initialiséà false qui permet de marquer le sommet dans les algorithmes de parcours
// toutes les méthodes étant en dehors de la classe sommet, il faut que ses attributs soient en public

class sommet{
    public :
    char nom;
    int numerotation;
    sommet(char nom, int numerotation);
    sommet() = default; //indique un constructeur par défaut si besoin
    bool visite = false;
};

//on définit une arrête par son numero et ses extrémités
class arrete{
    public :
    double numero;
    std :: vector <sommet> depart_arrivee;
    arrete(std :: vector <sommet> depart_arrivee, double numero);
};

// dans les 2 classes suivantes, je mets en public les méthodes qu'on va appeler dans le main

class representation_en_liste_adjacence{
    //chaque élément du vecteur est une paire avec first = sommet et second = liste des arretes sortantes
    std :: vector <std :: pair <sommet, std :: vector <arrete>>> liste_adjacence;
    public :
    void display_liste();
    void parcours_en_profondeur_recursif_la(sommet &sommet_de_depart);
    void parcours_en_profondeur_iteratif_la(sommet &sommet_de_depart);
    std :: vector <arrete> liste_chemin_possible_la(sommet &sommet);
    void marque(sommet &som);
    void parcours_en_largeur_la(int niveau_max);
    std :: pair <double, std :: vector <sommet>> djikstra(sommet &sommet_de_depart, sommet &sommet_arrivee); 
    representation_en_liste_adjacence(std :: vector <std :: pair <sommet, std :: vector <arrete>>>);
    std :: vector <std :: vector <arrete>> liste_vers_matrice_adjacence();
    void reset_liste();
};

//pour garder toutes les informations contenues dans la liste d'adjacence, je mets dans la matrice d'adjacences les arretes et non directement leur valeur

class representation_en_matrice_adjacence{
    std :: vector <std :: vector <arrete>> matrice_adjacence;
    public :
    representation_en_matrice_adjacence(std :: vector <std :: vector <arrete>>);
    std :: vector <std :: vector <arrete>> matrice_adj();
    std :: vector <std :: pair<sommet, std:: vector<arrete>>> matrice_vers_liste_adj();
    void display_matrice();
    void parcours_en_profondeur_recursif_ma(sommet &sommet_de_depart);
    void parcours_en_profondeur_iteratif_ma(sommet &sommet_de_depart);
    std :: vector<arrete> liste_chemin_possible_ma(sommet &sommet);
    void marque(sommet &som);
    void parcours_en_largeur_ma(int niveau_max);
    std :: vector <std :: vector <std :: pair <double, std :: vector <sommet>>>> floyd_warshall();
};


