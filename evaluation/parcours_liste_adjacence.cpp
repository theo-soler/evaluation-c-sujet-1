#include "graphe.h"
#include <stack>
#include<bits/stdc++.h>

void representation_en_liste_adjacence :: parcours_en_profondeur_recursif_la(sommet &sommet_de_depart){
    std :: cout << " on a visité le sommet " << sommet_de_depart.nom << std :: endl;
    marque(sommet_de_depart); //on marque le sommet comme visité
    if (liste_chemin_possible_la(sommet_de_depart).size() != 0){
        std :: vector <arrete> liste = liste_chemin_possible_la(sommet_de_depart);
        for (int i = 0; i < liste.size(); i++){
            std :: cout << " on part sur l'arrête " << liste[i].numero << std :: endl;
            parcours_en_profondeur_recursif_la(liste[i].depart_arrivee[1]); //on appelle la fonction sur le sommet suivant
        }
    }
    else{
    std :: cout << "On est bloqué !" << std:: endl; //s'il n'y a plus de sommet suivant, la fonction ne renvoie rien et on "remonte d'un cran"
    }
}


void representation_en_liste_adjacence :: parcours_en_profondeur_iteratif_la(sommet &sommet_de_depart){
    std :: cout << "g";
    std :: stack<sommet> pile_de_visite; 
    pile_de_visite.push(sommet_de_depart); //pile de parcours initialisée
    arrete current_arr = liste_chemin_possible_la(pile_de_visite.top())[0]; //le chemin qu'on s'apprête à emprunter
    std :: cout << "on est sur le sommet " << pile_de_visite.top().nom << std :: endl;
    while(not pile_de_visite.empty()){
        while(liste_chemin_possible_la(pile_de_visite.top()).size() > 0){
            marque(pile_de_visite.top()); //on marque le sommet actuel comme visité
            current_arr = liste_chemin_possible_la(pile_de_visite.top())[0];
            std :: cout << "on prend l'arrête " << current_arr.numero << std :: endl;
            pile_de_visite.push(current_arr.depart_arrivee[1]); //le nouveau sommet passe au sommet de la pile
            std :: cout << "on est sur le sommet " << pile_de_visite.top().nom << std :: endl;
        }
        marque(pile_de_visite.top()); //dans le cas ou on est bloqué, on marque le sommet et on dépile
        pile_de_visite.pop();
        if(pile_de_visite.empty() == false){
            std :: cout << "revenons en arrière" << std :: endl;
        }
    }
    std :: cout << "Parcours terminé !" << std :: endl;
}


void representation_en_liste_adjacence :: parcours_en_largeur_la(int niveau_max){
    std :: queue<std :: pair <sommet, int>> file_de_visite;
    std :: pair <sommet, int> premier_elt;
    premier_elt.second = 0;
    premier_elt.first = liste_adjacence[0].first;
    marque(premier_elt.first);
    file_de_visite.push(premier_elt); //la file de visite est initialisée
    if (niveau_max == 0){
        niveau_max = INT_MAX;
    }
    //tant qu'il y a des elements à visiter et qu'on est pas allé trop loin du sommet de départ, l'exploration continue
    while (file_de_visite.empty() == false and file_de_visite.front().second <= niveau_max){
        std :: cout << "On est sur le sommet " << file_de_visite.front().first.nom << " au niveau " << file_de_visite.front().second << std :: endl;
        for (arrete arr : liste_adjacence[file_de_visite.front().first.numerotation].second){ //on parcourt les sommets auxquels on a accès et on les marque comme "déjà ajoutés à la file"
            if (arr.depart_arrivee[1].visite == false){
                std :: pair <sommet, int> nouv_elt;
                nouv_elt.first = arr.depart_arrivee[1];
                nouv_elt.second = file_de_visite.front().second + 1;
                file_de_visite.push(nouv_elt);
                marque(nouv_elt.first);
            }
        }
        file_de_visite.pop(); //on enlève l'elt le plus vieux
    }
}