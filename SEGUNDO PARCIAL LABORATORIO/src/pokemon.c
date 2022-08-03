#include "pokemon.h"

Pokemon* Gauna_Pokemon_new()
{
	Pokemon* unPokemon = NULL;

	unPokemon = (Pokemon*) malloc(sizeof(Pokemon));

	if(unPokemon != NULL)
	{
		unPokemon->id = 0;
		unPokemon->esVarioColor = 0;
		unPokemon->valorAtaque = 0;
		strcpy(unPokemon->ataqueCargado, " ");
		strcpy(unPokemon->nombre, " ");
		strcpy(unPokemon->tamanio, " ");
		strcpy(unPokemon->tipo, " ");
	}

	return unPokemon;
}

Pokemon* Gauna_Pokemon_newParametros(char* idStr, char* esVarioStr, char* valorAtaqueStr, char* ataqueCargadoStr, char* nombreStr, char* tamanioStr, char* tipoStr)
{
	Pokemon* unPokemon = NULL;
	int id;
	int esVarioColor;
	int valorAtaque;

	if(idStr != NULL && valorAtaqueStr != NULL && valorAtaqueStr != NULL && ataqueCargadoStr != NULL && nombreStr != NULL && tamanioStr != NULL && tipoStr != NULL)
	{
		unPokemon = Gauna_Pokemon_new();
		id = atoi(idStr);
		esVarioColor = atoi(esVarioStr);
		valorAtaque = atoi(valorAtaqueStr);

		if(!Gauna_Pokemon_setID(unPokemon, id) || !Gauna_Pokemon_setNombre(unPokemon, nombreStr) || !Gauna_Pokemon_setAtaqueCargado(unPokemon, ataqueCargadoStr) || !Gauna_Pokemon_setTamanio(unPokemon, tamanioStr)
		   || !Gauna_Pokemon_setTipo(unPokemon, tipoStr) || !Gauna_Pokemon_setValorAtaque(unPokemon, valorAtaque) || !Gauna_Pokemon_setVarioColor(unPokemon, esVarioColor))
		{
			Gauna_Pokemon_Delete(unPokemon);
		}
	}

	return unPokemon;
}

void Gauna_Pokemon_Delete(Pokemon* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

int Gauna_Pokemon_setID(Pokemon* this, int id)
{
	int valido = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		valido = 1;
	}

	return valido;
}

int Gauna_Pokemon_getID(Pokemon* this, int* id)
{
	int valido = 0;

	if(this != NULL)
	{
		*id = this->id;
		valido = 1;
	}

	return valido;
}

int Gauna_Pokemon_setVarioColor(Pokemon* this, int esVarioColor)
{
	int valido = 0;

	if(this != NULL && esVarioColor > -1)
	{
		this->esVarioColor = esVarioColor;
		valido = 1;
	}

	return valido;
}

int Gauna_Pokemon_getVarioColor(Pokemon* this, int* esVarioColor)
{
	int valido = 0;

	if(this != NULL)
	{
		*esVarioColor = this->esVarioColor;
		valido = 1;
	}

	return valido;
}

int Gauna_Pokemon_setValorAtaque(Pokemon* this, int valorAtaque)
{
	int valido = 0;

	if(this != NULL && valorAtaque > -1)
	{
		this->valorAtaque = valorAtaque;
		valido = 1;
	}

	return valido;
}

int Gauna_Pokemon_getValorAtaque(Pokemon* this, int* valorAtaque)
{
	int valido = 0;

	if(this != NULL)
	{
		*valorAtaque = this->valorAtaque;
		valido = 1;
	}

	return valido;
}

int Gauna_Pokemon_setAtaqueCargado(Pokemon* this, char* ataqueCargado)
{
	int valido = 0;

	if(this != NULL && ataqueCargado != NULL)
	{
		strcpy(this->ataqueCargado, ataqueCargado);
		valido = 1;
	}

	return valido;
}

int Gauna_Pokemon_getAtaqueCargado(Pokemon* this, char* ataqueCargado)
{
	int valido = 0;

	if(this != NULL)
	{
		strcpy(ataqueCargado, this->ataqueCargado);
		valido = 1;
	}

	return valido;
}

int Gauna_Pokemon_setNombre(Pokemon* this, char* nombre)
{
	int valido = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		valido = 1;
	}

	return valido;
}

int Gauna_Pokemon_getNombre(Pokemon* this, char* nombre)
{
	int valido = 0;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		valido = 1;
	}

	return valido;
}

int Gauna_Pokemon_setTamanio(Pokemon* this, char* tamanio)
{
	int valido = 0;

	if(this != NULL && tamanio != NULL)
	{
		strcpy(this->tamanio, tamanio);
		valido = 1;
	}

	return valido;
}

int Gauna_Pokemon_getTamanio(Pokemon* this, char* tamanio)
{
	int valido = 0;

	if(this != NULL)
	{
		strcpy(tamanio, this->tamanio);
		valido = 1;
	}

	return valido;
}

int Gauna_Pokemon_setTipo(Pokemon* this, char* tipo)
{
	int valido = 0;

	if(this != NULL && tipo != NULL)
	{
		strcpy(this->tipo, tipo);
		valido = 1;
	}

	return valido;
}

int Gauna_Pokemon_getTipo(Pokemon* this, char* tipo)
{
	int valido = 0;

	if(this != NULL)
	{
		strcpy(tipo, this->tipo);
		valido = 1;
	}

	return valido;
}

int Gauna_Pokemon_Enlist(LinkedList* pArrayListPokemons, int index)
{
	int valido = 0;
	Pokemon* unPokemon = NULL;
	int id;
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVarioColor;

	unPokemon = ll_get(pArrayListPokemons, index);
	if(unPokemon != NULL)
	{
		if(Gauna_Pokemon_getID(unPokemon, &id) && Gauna_Pokemon_getNombre(unPokemon, nombre) && Gauna_Pokemon_getTipo(unPokemon, tipo) && Gauna_Pokemon_getTamanio(unPokemon, tamanio) &&
		   Gauna_Pokemon_getAtaqueCargado(unPokemon, ataqueCargado) && Gauna_Pokemon_getValorAtaque(unPokemon, &valorAtaque) && Gauna_Pokemon_getVarioColor(unPokemon, &esVarioColor))
		{
			printf("|%-5d | %-18s | %-18s | %-18s | %-18s | %-18d | %-8d|\n", id, nombre, tipo, tamanio, ataqueCargado, valorAtaque, esVarioColor);
			valido = 1;
		}
	}

	return valido;
}
