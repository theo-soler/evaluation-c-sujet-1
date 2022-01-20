#include "graphe.h"


//convertit la liste d'adjacence en matrice d'adjacence
std :: vector <std :: vector <arrete>> representation_en_liste_adjacence :: liste_vers_matrice_adjacence(){
    sommet som_null {'x', 0}; //on définit l'absence d'arrete comme une arrete de poids nul allant d'un sommet noté x à lui même
    std ::vector <sommet> dep_arr_nul {som_null, som_null};
    arrete arrete_null = arrete(dep_arr_nul, 0);
    std :: vector <arrete> col(liste_adjacence.size(), arrete_null);
    std :: vector <std :: vector <arrete>> matrice (liste_adjacence.size(), col); //on initialise la matrice avec des arretes nulles
    //on la remplit
    for (std::pair<sommet, std::vector<arrete>> iterator : liste_adjacence){
        for (arrete ar : iterator.second){
            matrice[iterator.first.numerotation][ar.depart_arrivee[1].numerotation] = ar;
        }
    }
    return matrice;
}

//marque le sommet voulu comme visité à toutes ses occurences dans la matrice
void representation_en_liste_adjacence :: marque(sommet &som){
    for (int i = 0; i < liste_adjacence.size(); i++){
        for (int j = 0; j < liste_adjacence[i].second.size(); j++){
            if (liste_adjacence[i].second[j].depart_arrivee[1].nom == som.nom){
                liste_adjacence[i].second[j].depart_arrivee[1].visite = true;
            }
            if (liste_adjacence[i].second[j].depart_arrivee[0].nom == som.nom){
                liste_adjacence[i].second[j].depart_arrivee[0].visite = true;
            }
        }
        if(liste_adjacence[i].first.nom == som.nom){
            liste_adjacence[i].first.visite = true;
        }
    }
}

//renvoie la liste des arrêtes accessibles à partir d'un sommet
std :: vector<arrete> representation_en_liste_adjacence :: liste_chemin_possible_la(sommet &sommet_de_depart){
    std :: vector<arrete> liste;
    for (int j = 0; j < liste_adjacence[sommet_de_depart.numerotation].second.size(); j++){
        if (liste_adjacence[sommet_de_depart.numerotation].second[j].depart_arrivee[1].visite == false){
            liste.push_back(liste_adjacence[sommet_de_depart.numerotation].second[j]);
        }
    }
    return liste;
}

