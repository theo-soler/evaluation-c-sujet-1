#include "graphe.h"

//codes servant à afficher le graphe dans les deux représentations

void representation_en_matrice_adjacence :: display_matrice(){
    for (int i = 0; i< matrice_adjacence.size(); i++){
        for (int j = 0; j < matrice_adjacence.size(); j++){
            std :: cout << matrice_adjacence[i][j].numero << " ";
        }
        std :: cout << "" << std :: endl;
    }
}

void representation_en_liste_adjacence :: display_liste(){
    for (std :: pair<sommet, std ::vector<arrete>> pr : liste_adjacence){
        std :: cout << pr.first.nom << " : ";
        for (arrete arr : pr.second){
            std :: cout << arr.numero << " de " << arr.depart_arrivee[0].nom << " vers " << arr.depart_arrivee[1].nom << ", ";
        }
        std ::cout << "" << std :: endl;
    }
}