#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Biblioteca_Propia.h"
#include "parser.h"

int Gauna_Controller_loadFromText(char* path , LinkedList* pArrayListPokemons);
int Gauna_Controller_ListPassenger(LinkedList* pArrayListPokemons);
int Gauna_Controller_removePokemon(LinkedList* pArrayListPokemons);
int Gauna_Controller_FilterWater(LinkedList* pArrayListPokemons);
int Gauna_Controller_MapFGG(LinkedList* pArrayListPokemons);
int Gauna_Controller_MapBFG(LinkedList* pArrayListPokemons);
int Gauna_Controller_Batallar(LinkedList* pArrayListPokemons);

#endif
