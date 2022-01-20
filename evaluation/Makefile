CPP = g++
RM=rm -f
graph_eval : graphe.o floyd_warshall.o algorithme_de_djikstra.o display_functions.o liste_adjacence.o matrice_adjacence.o read.o main.o parcours_liste_adjacence.o parcours_matrice_adjacence.o
	$(CPP) $^ -o $@


graphe.o : graphe.h graphe.cpp
floyd_warshall.o : graphe.h floyd_warshall.cpp
algorithme_de_djikstra.o : graphe.h algorithme_de_djikstra.cpp
display_functions.o : display_functions.cpp
liste_adjacence.o : graphe.h liste_adjacence.cpp
matrice_adjacence.o : graphe.h matrice_adjacence.cpp
read.o : graphe.h read.cpp
parcours_liste_adjacence.o : graphe.h parcours_liste_adjacence.cpp liste_adjacence.cpp
parcours_matrice_adjacence.o : graphe.h parcours_matrice_adjacence.cpp matrice_adjacence.cpp
main.o : graphe.h

%.o:%.cpp
	$(CPP) -o $@ -c $<

clean:
	$(RM) *.o graph_eval

.PHONY: clean