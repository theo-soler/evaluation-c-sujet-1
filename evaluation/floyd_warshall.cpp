#include "graphe.h"


//algorithme de floyd warshall renvoyant les chemins les plus courts entre toute combinaison de 2 points du graphe

std :: vector <std :: vector <std :: pair <double, std :: vector <sommet>>>> representation_en_matrice_adjacence :: floyd_warshall(){

    std :: pair <double, std :: vector <sommet>> elt;
    elt.first = INT_MAX;
    std :: vector<std :: pair <double, std :: vector <sommet>>> col = {matrice_adjacence.size(), elt};
    std :: vector<std :: vector <std :: pair <double, std :: vector <sommet>>>> matrice_de_chemins_min = {matrice_adjacence.size(), col}; //initialise la matrice qui contiendra en chaque position ij la distance minimale entre les sommets i et j et le chemin à parcourir

    //on remplit déjà les cases de la matrices correspondant à deux sommets directement reliés et les cases diagonales
    for(int i = 0; i < matrice_adjacence.size(); i ++){
        for (int j = 0; j < matrice_adjacence.size(); j++){
            if(matrice_adjacence[i][j].numero != 0){
                matrice_de_chemins_min[i][j].first = matrice_adjacence[i][j].numero;
                matrice_de_chemins_min[i][j].second = {matrice_adjacence[i][j].depart_arrivee[0], matrice_adjacence[i][j].depart_arrivee[1]};
            }
            if (i == j){
                matrice_de_chemins_min[i][j].first = 0;
                matrice_de_chemins_min[i][j].second = {};
            }
        }
    }

    //on utilise maintenant la relation de récurrence de floyd warshall pour remplir itérativement la matrice
    for(int k = 0; k < matrice_adjacence.size(); k ++){
        for (int i = 0; i < matrice_adjacence.size(); i++){
            for (int j = 0; j < matrice_adjacence.size(); j++){
                if (matrice_de_chemins_min[i][k].first + matrice_de_chemins_min[k][j].first < matrice_de_chemins_min[i][j].first){
                    matrice_de_chemins_min[i][j].first = matrice_de_chemins_min[i][k].first + matrice_de_chemins_min[k][j].first;
                    std :: vector<sommet> chemin;
                    for (int p = 0; p < matrice_de_chemins_min[i][k].second.size(); p++){
                        if(p>0){
                            if (matrice_de_chemins_min[i][k].second[p].nom != matrice_de_chemins_min[i][k].second[p-1].nom){
                                chemin.push_back(matrice_de_chemins_min[i][k].second[p]);
                            }
                        }
                        else {
                            chemin.push_back(matrice_de_chemins_min[i][k].second[p]);
                        }
                    }
                    for (int p = 0; p < matrice_de_chemins_min[k][j].second.size(); p++){
                        if(p>0){
                            if (matrice_de_chemins_min[k][j].second[p].nom != matrice_de_chemins_min[k][j].second[p-1].nom){
                                chemin.push_back(matrice_de_chemins_min[k][j].second[p]);
                            }
                        }
                        else {
                            chemin.push_back(matrice_de_chemins_min[k][j].second[p]);
                        }
                    }
                    matrice_de_chemins_min[i][j].second = chemin;
                }
            }
        }
    }

    //on affiche tous les chemins trouvés
    for(int k = 0; k < matrice_adjacence.size(); k ++){
        for (int i = 0; i < matrice_adjacence.size(); i++){
            for (sommet som: matrice_de_chemins_min[k][i].second){
                
                std :: cout << som.nom << " -> ";
                
            }
            if(matrice_de_chemins_min[k][i].second.size() == 0){ std :: cout << "On reste sur place. ";}
            std :: cout << "Le chemin a été fait en une distance de " << matrice_de_chemins_min[k][i].first << std :: endl;
            std :: cout << "" << std :: endl;
            
        }
    }
    return matrice_de_chemins_min;
}


//problème au niveau de la jonction : les 2 piles se superposent avec un sommet en commun mais c'est pas très grave
