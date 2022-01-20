#include "read.h"

//lit le fichier passé en argument
// chaque ligne du fichier est une arrete et se presente de la forme "nom_du_sommet_depart nom_du_sommet_arrivée numero_de_l'arrete" 
//(attention les noms des sommets doivent être des caractères simples)

std :: vector <std :: pair <sommet, std :: vector <arrete>>> lecture_liste_adj(const char* filename){

  std :: vector <std :: pair <sommet, std :: vector <arrete>>> liste_adja;
  FILE* fichier = NULL; // on crée une variable du type FILE* initialisée à NULL
  char chaine[100] = ""; //on définit le format d'une ligne
  fichier = fopen(filename, "r"); //on ouvre le fichier

 // on cree les listes de sommets et d'arretes qu'on va extraire
  std :: vector <sommet> liste_sommets;
  std :: vector <arrete> liste_arretes;

  //on cree les variables de lecture
  std::vector<char> coords(2,'x');
  double arr;

  // on cree la variable servant a numeroter les sommets
  int i = 0;

  //tant qu'on a pas atteint la fin du fichier on continue
  while(fscanf(fichier, "%c %c %lf", &coords[0], &coords[1], &arr) != EOF){

    fseek(fichier, 1, SEEK_CUR); //déplace le curseur d'un cran pour passer à la ligne du dessous
    coords.shrink_to_fit(); //coords ne va plus grandir

    //maintenant on complète les listes de sommets et d'arretes à partir de ce qu'on a lu

    //on complète liste_sommets
    std :: vector <char> last_name;
    std :: vector <int> last_numero; //on récupère le nom et le numero du sommet tout en faisant attention au fait que le sommet lu est peut être déjà dans liste_sommets
    for (int k = 0;  k < 2; k++){
      bool deja_dans_liste = false;
      for (int j = 0;  j < liste_sommets.size(); j++){
        if (liste_sommets[j].nom == coords[k]){
          deja_dans_liste = true;
          last_name.push_back(liste_sommets[j].nom);
          last_numero.push_back(liste_sommets[j].numerotation);
        }
      }
      if (not deja_dans_liste){ //s'il n'etait pas dans la liste
        sommet nouv_som = sommet(coords[k], i); 
        liste_sommets.push_back(nouv_som);
        last_name.push_back(coords[k]);
        last_numero.push_back(i);
        i = i+1; //on incrémente la numerotation
      }
    }

    //on complete arretes
    std :: vector <sommet> depart_arrivee {sommet(last_name[0], last_numero[0]), sommet(last_name[1], last_numero[1])};
    liste_arretes.push_back(arrete(depart_arrivee, arr));
      
  }

  //on remplit la liste d'adjacence à partir des listes de sommet et d'arrete
  for (int i = 0; i < liste_sommets.size(); i++){
    std :: vector <arrete > liste_arrete_sortante;
    for (int j = 0; j < liste_arretes.size(); j++){
      if (liste_arretes[j].depart_arrivee[0].nom == liste_sommets[i].nom){
        liste_arrete_sortante.push_back(liste_arretes[j]);
      }
    }
    std :: pair <sommet, std :: vector <arrete>> nouvel_elt;
    nouvel_elt.first = liste_sommets[i];
    for (arrete so : liste_arrete_sortante){
      nouvel_elt.second.push_back(so);
    }
    liste_adja.push_back(nouvel_elt);
  }


  return liste_adja;
}