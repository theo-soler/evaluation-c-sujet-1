#include "graphe.h"

//algorithme de djikstra trouvant le plus court chemin entre deux sommets indiqués en argument

std :: pair <double, std :: vector <sommet>> representation_en_liste_adjacence :: djikstra(sommet &sommet_de_depart, sommet &sommet_arrivee){
    std :: vector <sommet> liste_finalisee = {sommet_de_depart}; //on crée une liste qui contiendra les sommets du graphe du plus proche au plus lointain
    std :: vector <sommet> sommet_origine = {sommet_de_depart}; // on crée une liste dont l'element en position i sera : le sommet dont on arrive quand on realise le plus court chemin pour aller du sommet de depart au sommet en position i de la liste finalisee
    std :: vector <double> liste_distances(liste_adjacence.size(), INT16_MAX); // on crée une liste contenant les distances respectives de ces plus courts chemins initialisées à l'infini sauf pour le sommet de départ
    liste_distances[0] = 0; //le sommet de départ est à une distance 0 de lui-même
    marque(sommet_de_depart); //on le marque comme déjà dans la liste finalisée

    //on remplit ces 3 listes progressivement
    while (liste_finalisee.size() < liste_adjacence.size()){
        std :: vector <sommet> liste_dispo; //liste des sommets accessibles
        std :: vector <sommet> liste_dispo_origine; //liste des sommets d'origine de ces sommets accessibles
        std :: vector <double> nouv_liste_dist; //liste des distances associés a chaque sommet accessible
        for (sommet som : liste_finalisee){
            for (int i = 0; i < liste_adjacence[som.numerotation].second.size(); i++){
                if(liste_adjacence[som.numerotation].second[i].depart_arrivee[1].visite == false){ //a ce niveau on a selectionné les sommets accessibles
                    //on actualise les distances des plus courts chemins si on a trouvé à cette étape un meilleur chemin que précédemment
                    if(liste_distances[liste_adjacence[som.numerotation].second[i].depart_arrivee[1].numerotation] > liste_distances[liste_adjacence[som.numerotation].first.numerotation] + liste_adjacence[som.numerotation].second[i].numero){
                        liste_distances[liste_adjacence[som.numerotation].second[i].depart_arrivee[1].numerotation] = liste_distances[liste_adjacence[som.numerotation].first.numerotation] + liste_adjacence[som.numerotation].second[i].numero;                   
                    }
                    //on remplit les listes de l'étape
                    double distance_actualisee = liste_distances[liste_adjacence[som.numerotation].second[i].depart_arrivee[1].numerotation];
                    liste_dispo.push_back(liste_adjacence[som.numerotation].second[i].depart_arrivee[1]);
                    liste_dispo_origine.push_back(liste_adjacence[som.numerotation].second[i].depart_arrivee[0]);
                    nouv_liste_dist.push_back(distance_actualisee);   
                }
            }   
        }
        //il s'agit maintenant de trouver le sommet le plus proche de sommet de depart à cette étape
        sommet sommet_proche;
        double min = nouv_liste_dist[0];
        sommet_proche = liste_dispo[0];
        int pos_min = 0;
        for (int j = 0; j < liste_dispo.size(); j++){
            if (nouv_liste_dist[j] < min){
                sommet_proche = liste_dispo[j];
                min = nouv_liste_dist[j];
                pos_min = j;
            }
        }
        //on remplit les listes
        sommet_origine.push_back(liste_dispo_origine[pos_min]);
        liste_finalisee.push_back(sommet_proche);
        liste_distances[sommet_proche.numerotation] = min;
        marque(sommet_proche); //on le marque comme "dans la liste"
    }

    //il faut maintenant trouver le plus court chemin demandé
    //pour cela, on remonte liste_finalisee en utilisant sommet_origine pour parcourir le chemin et liste_distance pour indiquer la distance réalisée
    std :: pair <double, std :: vector <sommet>> chemin;
    chemin.first = liste_distances[sommet_arrivee.numerotation]; //on a la distance du chemin voulu grace a liste_distance
    std :: vector <sommet> chemin_voulu;
    sommet remontee = sommet_arrivee;
    while(remontee.nom != sommet_de_depart.nom){
        chemin_voulu.push_back(remontee);
        int pos = 0;
        while(liste_finalisee[pos].nom != remontee.nom){
            pos = pos + 1;
        }
        remontee = sommet_origine[pos];
    }
    chemin_voulu.push_back(sommet_de_depart);
    int l = chemin_voulu.size();
    for (int k = 0; k< l; k++){
        std :: cout << "on passe sur le sommet " << chemin_voulu[l-k-1].nom << std ::endl;
        std :: cout << "on a parcouru " << liste_distances[chemin_voulu[l-k-1].numerotation] << std :: endl;
    }

    chemin.second = chemin_voulu;

    return chemin;
}