#include "graphe.h"

sommet :: sommet(char nom, int numerotation):
    nom(nom),
    numerotation(numerotation)
{}

arrete :: arrete(std :: vector <sommet> depart_arrivee, double numero)
    :
    depart_arrivee(depart_arrivee),
    numero(numero)
{}

representation_en_liste_adjacence :: representation_en_liste_adjacence(std :: vector <std :: pair <sommet, std :: vector <arrete>>> liste_adjacence)
    :
    liste_adjacence(liste_adjacence)
{}

representation_en_matrice_adjacence :: representation_en_matrice_adjacence(std :: vector <std :: vector <arrete>> matrice_adjacence)
    :
    matrice_adjacence(matrice_adjacence)
{}