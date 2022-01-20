#include "read.h"

//on execute en prenant le graphe présent sur le fichier test.graph
//les différentes fonctions demandées sont en commentaire : decommenter la ligne voulue
//attention : dans les programmes de parcours, je marque les sommets visités comme visités sans réinitialiser à la fin donc
// si on lance 2 fonctions de parcours à la suite, la deuxième ne va rien parcourir

int main(int argc, char** argv){
    std :: vector <std :: pair <sommet, std :: vector <arrete>>> liste_adja = lecture_liste_adj("fichier.graph");
    representation_en_liste_adjacence liste_adjacence = representation_en_liste_adjacence(liste_adja);
     std :: vector <std :: vector <arrete>> matrice = liste_adjacence.liste_vers_matrice_adjacence();
     representation_en_matrice_adjacence matrice_adjacence = representation_en_matrice_adjacence(matrice);
    //matrice_adjacence.display_matrice();
    //liste_adjacence.display_liste();
    //matrice_adjacence.parcours_en_profondeur_recursif_ma(matrice[0][1].depart_arrivee[0]);
    //liste_adjacence.parcours_en_profondeur_recursif_la(liste_adja[0].first);
    //matrice_adjacence.parcours_en_profondeur_iteratif_ma(matrice[0][1].depart_arrivee[0]);
    // liste_adjacence.parcours_en_profondeur_iteratif_la(liste_adja[0].first);
    //liste_adjacence.parcours_en_largeur_la(0);
    //matrice_adjacence.parcours_en_largeur_ma(0);
    //matrice_adjacence.floyd_warshall();
    //liste_adjacence.djikstra(liste_adja[0].first, liste_adja[6].first);
}