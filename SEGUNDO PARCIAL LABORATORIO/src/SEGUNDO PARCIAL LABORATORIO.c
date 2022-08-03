#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"
#include "utn.h"
#include "controller.h"

int main(void)
{
	setbuf(stdout, NULL);
	int opcionElegida;
	int flagIn = 0;
	LinkedList* listaPokemones = ll_newLinkedList();

	do
	{
		opcionElegida = Gauna_Propia_PedirOpcion();

		switch(opcionElegida)
		{
			case 1:
				if(!flagIn)
				{
					if(Gauna_Controller_loadFromText("Data_Pokemones.csv", listaPokemones))
					{
						printf("\nLista cargada con exito...\n");
						flagIn = 1;
					}
					else
					{
						printf("\nHubo un error...\n");
					}
				}
				else
				{
					printf("\nLa lista ya ha sido cargada\n");
				}
			break;

			case 2:
				if(flagIn)
				{
					Gauna_Controller_removePokemon(listaPokemones);
				}
				else
				{
					printf("\n|ERROR|\nSe debe cargar la lista de pokemones primero\n");
				}
			break;

			case 3:
				if(flagIn)
				{
					if(Gauna_Controller_ListPassenger(listaPokemones))
	            	{
	            		printf("\nLista cargada con exito\n");
	            	}
	            	else
	            	{
	            		printf("\nNo se han podido mostrar los pasajeros\n");
	            	}
				}
				else
				{
					printf("\n|ERROR|\nSe debe cargar la lista de pokemones primero\n");
				}
			break;

			case 4:
				if(flagIn)
				{
					if(Gauna_Controller_FilterWater(listaPokemones))
					{
						printf("\nFiltro cargado con exito\n");
					}
					else
					{
						printf("\nERROR...\n");
					}
				}
				else
				{
					printf("\n|ERROR|\nSe debe cargar la lista de pokemones primero\n");
				}
			break;

			case 5:
				if(flagIn)
				{
					if(Gauna_Controller_MapFGG(listaPokemones))
					{
						printf("\nMapeado exitoso\n");
					}
					else
					{
						printf("\nERROR...\n");
					}
				}
				else
				{
					printf("\n|ERROR|\nSe debe cargar la lista de pokemones primero\n");
				}
			break;
		}
	}while(opcionElegida != 6);

	return EXIT_SUCCESS;
}
