#include "graphe.h"
#include <stack>
#include<bits/stdc++.h>

//convertit une matrice d'adjacence en liste d'adjacence
std :: vector <std :: pair<sommet, std:: vector<arrete>>> representation_en_matrice_adjacence :: matrice_vers_liste_adj(){
    std::vector <std :: pair<sommet, std:: vector<arrete>>> liste_adj;
    for (int i = 0; matrice_adjacence.size(); i++){
        std :: vector <arrete> liste_arrete_sortante {};
        for (int j = 0; matrice_adjacence.size(); j++){
            if (matrice_adjacence[i][j].numero > 0){
                liste_arrete_sortante.push_back(matrice_adjacence[i][j]);
            }
        std :: pair<sommet, std:: vector<arrete>> nouvel_elt;
        nouvel_elt.first = liste_arrete_sortante[0].depart_arrivee[0];
        nouvel_elt.second = liste_arrete_sortante;
        liste_adj.push_back(nouvel_elt);
        }
    }
    return(liste_adj);
}

//marque le sommet voulu à toutes ses occurrences dans la matrice
void representation_en_matrice_adjacence :: marque(sommet &som){
    for (int i = 0; i < matrice_adjacence.size(); i++){
        matrice_adjacence[i][som.numerotation].depart_arrivee[1].visite = true;
        matrice_adjacence[som.numerotation][i].depart_arrivee[0].visite = true;
    }
}

//renvoie les arretes dont le sommet d'arrivée n'est pas encore marqué provenant du sommet voulu
std :: vector<arrete> representation_en_matrice_adjacence :: liste_chemin_possible_ma(sommet &sommet_de_depart){
    std :: vector<arrete> liste;
    for (int j = 0; j < matrice_adjacence.size(); j++){
        if (matrice_adjacence[sommet_de_depart.numerotation][j].numero != 0 and matrice_adjacence[sommet_de_depart.numerotation][j].depart_arrivee[1].visite == 0){
            liste.push_back(matrice_adjacence[sommet_de_depart.numerotation][j]);
        }
    }
    return liste;
}