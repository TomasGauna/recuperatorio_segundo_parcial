#include "parser.h"

int Gauna_Parser_PokemonFromText(FILE* pFile , LinkedList* pArrayListPokemons)
{
	int valido = 0;
	Pokemon* unPokemon = NULL;
	int cantidad;
	char nombreStr[50];
	char idStr[50];
	char esVarioStr[50];
	char valorAtaqueStr[50];
	char ataqueCargadoStr[50];
	char tamanioStr[50];
	char tipoStr[50];

	if(pFile != NULL && pArrayListPokemons != NULL)
	{
		do
		{
			cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, tipoStr, tamanioStr, ataqueCargadoStr, valorAtaqueStr, esVarioStr);

			if(cantidad == 7)
			{
				unPokemon = Gauna_Pokemon_newParametros(idStr, esVarioStr, valorAtaqueStr, ataqueCargadoStr, nombreStr, tamanioStr, tipoStr);

				if(unPokemon != NULL)
				{
					ll_add(pArrayListPokemons, unPokemon);
					valido = 1;
				}
				else
				{
					Gauna_Pokemon_Delete(unPokemon);
				}
			}
			else
			{
				printf("\nError...\n");
			}
		}while(!feof(pFile));
	}

	return valido;
}

