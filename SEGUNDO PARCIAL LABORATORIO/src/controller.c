#include "controller.h"

int Gauna_Controller_loadFromText(char* path , LinkedList* pArrayListPokemons)
{
	int valido;
	FILE* pArchivo;

	pArchivo = fopen(path, "r");

	valido = Gauna_Parser_PokemonFromText(pArchivo, pArrayListPokemons);

	fclose(pArchivo);

	return valido;
}

int Gauna_Controller_ListPassenger(LinkedList* pArrayListPokemons)
{
	int valido = 0;
	int cantidad;

	if(pArrayListPokemons != NULL)
	{
		cantidad = ll_len(pArrayListPokemons);

		if(cantidad > 0)
		{
			printf("\n< LISTADO DE POKEMONES >");
			printf("\n ID	 Nombre		      Tipo  	           Tamaño               Ataque cargado       Valor ataque       Vario color\n");
			for(int i = 0; i < cantidad; i++)
			{
				valido = Gauna_Pokemon_Enlist(pArrayListPokemons, i);
			}
		}
	}

	return valido;
}

int Gauna_Controller_removePokemon(LinkedList* pArrayListPokemons)
{
	int valido;
	int id;

	if(Gauna_Controller_ListPassenger(pArrayListPokemons))
	{
		id = Gauna_Propia_PedirId();
		valido = Gauna_Propia_EliminarPokemon(pArrayListPokemons, id);
	}

	return valido;
}

int Gauna_Controller_FilterWater(LinkedList* pArrayListPokemons)
{
	int valido;
	LinkedList* lista = NULL;

	lista = ll_filter(pArrayListPokemons, Gauna_Propia_FilterWaterShiny);

	if(lista != NULL)
	{
		valido = Gauna_Controller_ListPassenger(lista);
		ll_deleteLinkedList(lista);
	}

	return valido;
}

int Gauna_Controller_MapFGG(LinkedList* pArrayListPokemons)
{
	int valido;

	if(pArrayListPokemons != NULL)
	{
		if(ll_map(pArrayListPokemons, Gauna_Propia_MapFilterFGG))
		{
			valido = Gauna_Controller_ListPassenger(pArrayListPokemons);
		}
	}

	return valido;
}
