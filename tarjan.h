#ifndef SCC_H
#define SCC_H


#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
#include <limits.h>
#include <stdbool.h>

//Inizializza le strutture dati ed esegue l'algoritmo di Tarjan per il calcolo delle componenti fortemente connesse
//Restituisce un puntatore a puntatori: ogni puntatore "puntato" ha in posizione 0 il numero di elementi della SCC, e nelle posizioni successive gli indici dei nodi
int **scc(int **grafo, int n_nodi);

//True se x appartiene ad array
bool is_in_array_0_len(int x, int *array);

//Rovescia l'array di lunghezza len
void reverse_array(int *arr, int len);

//Stampa le compenenti fortemente connesse
void print_scc(int **scc_s);

#endif
