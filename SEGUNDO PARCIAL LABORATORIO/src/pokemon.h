#ifndef POKEMON_H_
#define POKEMON_H_

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVarioColor;
}Pokemon;

Pokemon* Gauna_Pokemon_new();
Pokemon* Gauna_Pokemon_newParametros();
void Gauna_Pokemon_Delete(Pokemon* this);

int Gauna_Pokemon_setID(Pokemon* this, int id);
int Gauna_Pokemon_getID(Pokemon* this, int* id);

int Gauna_Pokemon_setVarioColor(Pokemon* this, int esVarioColor);
int Gauna_Pokemon_getVarioColor(Pokemon* this, int* esVarioColor);

int Gauna_Pokemon_setValorAtaque(Pokemon* this, int valorAtaque);
int Gauna_Pokemon_getValorAtaque(Pokemon* this, int* valorAtaque);

int Gauna_Pokemon_setAtaqueCargado(Pokemon* this, char* ataqueCargado);
int Gauna_Pokemon_getAtaqueCargado(Pokemon* this, char* ataqueCargado);

int Gauna_Pokemon_setNombre(Pokemon* this, char* nombre);
int Gauna_Pokemon_getNombre(Pokemon* this, char* nombre);

int Gauna_Pokemon_setTamanio(Pokemon* this, char* tamanio);
int Gauna_Pokemon_getTamanio(Pokemon* this, char* tamanio);

int Gauna_Pokemon_setTipo(Pokemon* this, char* tipo);
int Gauna_Pokemon_getTipo(Pokemon* this, char* tipo);

int Gauna_Pokemon_Enlist(LinkedList* pArrayListPokemons, int index);

#endif
