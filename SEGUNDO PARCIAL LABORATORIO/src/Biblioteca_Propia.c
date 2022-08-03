#include "Biblioteca_Propia.h"

int Gauna_Propia_PedirOpcion()
{
	int opcionElegida;
	int valido;
	char pidoOpcion[50];

	valido = getStringNumeros("< MENU DE OPCIONES >\n1.Cargar archivos pokemones\n2.Eliminar pokemon\n3.Imprimir pokemones\n4.Filtrar de tipo agua variocolor\n"
							  "5.Mapear ataque cargado\n6.Salir\nElija una opcion: ", pidoOpcion);
	opcionElegida = atoi(pidoOpcion);

	while(valido != 1 || (opcionElegida != 1 && opcionElegida != 2 && opcionElegida != 3 && opcionElegida != 4 && opcionElegida != 5 && opcionElegida != 6))
	{
		valido = getStringNumeros("\n|ERROR|\n< MENU DE OPCIONES >\n1.Cargar archivos pokemones\n2.Eliminar pokemon\n3.Imprimir pokemones\n4.Filtrar de tipo agua variocolor\n"
								  "5.Mapear ataque cargado\n6.Salir\nElija una opcion correcta: ", pidoOpcion);
		opcionElegida = atoi(pidoOpcion);
	}

	return opcionElegida;
}

int Gauna_Propia_PedirId()
{
	int valido;
	int id;
	char pedirId[50];

	valido = getStringNumeros("\nIngrese el ID del pokemon: ", pedirId);
	id = atoi(pedirId);

	while(valido != 1)
	{
		valido = getStringNumeros("\nIngrese el ID del pokemon: ", pedirId);
		id = atoi(pedirId);
	}

	return id;
}

int Gauna_Propia_BuscarId(LinkedList* pArrayListPokemons, int id)
{
	int index = -1;
	int len;
	int idAux;
	Pokemon* unPokemon = NULL;

	if(pArrayListPokemons != NULL)
	{
		len = ll_len(pArrayListPokemons);

		if(len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				unPokemon = (Pokemon*) ll_get(pArrayListPokemons, i);

				if(Gauna_Pokemon_getID(unPokemon, &idAux))
				{
					if(idAux == id)
					{
						index = i;
						break;
					}
				}
			}
		}
	}

	return index;
}

int Gauna_Propia_EliminarPokemon(LinkedList* pArrayListPokemons, int id)
{
	int valido = 0;
	char pidoOpcion[50];
	int opcionElegida;
	int compruebo;
	int index = -1;

	if(pArrayListPokemons != NULL)
	{
		index = Gauna_Propia_BuscarId(pArrayListPokemons, id);

		if(index != -1)
		{
			Gauna_Pokemon_Enlist(pArrayListPokemons, index);

			compruebo = getStringNumeros("\nEl pokemon mostrado en pantalla esta por ser eliminado. Desea continuar?\n1.Si\n2.No\nElija una opcion: ", pidoOpcion);
			opcionElegida = atoi(pidoOpcion);

			while(compruebo != 1 || (opcionElegida != 1 && opcionElegida != 2))
			{
				compruebo = getStringNumeros("\n|ERROR|\nEl pokemon mostrado en pantalla esta por ser eliminado. Desea continuar?\n1.Si\n2.No\nElija una opcion correcta: ", pidoOpcion);
				opcionElegida = atoi(pidoOpcion);
			}

			switch(opcionElegida)
			{
				case 1:
					ll_remove(pArrayListPokemons, index);
					printf("\nSe ha realizado la baja con exito\n");
					valido = 1;
				break;

				case 2:
					printf("\nSe ha cancelado la baja\n");
				break;
			}
		}
		else
		{
			printf("\nEl ID no ha sido encontrado\n");
		}
	}

	return valido;
}

int Gauna_Propia_FilterWaterShiny(void* pElement)
{
	int valido = 0;
	int comparo;
	char tipo[50];
	int esVarioColor;
	Pokemon* aux = NULL;

	aux = (Pokemon*) pElement;

	if(Gauna_Pokemon_getTipo(aux, tipo) && Gauna_Pokemon_getVarioColor(aux, &esVarioColor))
	{
		comparo = strcmp(tipo, "Water");

		if(!comparo && esVarioColor > 0)
		{
			valido = 1;
		}
	}

	return valido;
}

int Gauna_Propia_MapFilterFGG(void* pElement)
{
	int valido = 1;
	char tipo[50];
	int valorAtaque;
	int nuevoValorAtaque;
	Pokemon* aux = NULL;

	aux = (Pokemon*) pElement;

	if(Gauna_Pokemon_getTipo(aux, tipo))
	{
		if(strcmp(tipo, "Fire") == 0 || strcmp(tipo, "Grass") == 0 || strcmp(tipo, "Ground") == 0)
		{
			if(Gauna_Pokemon_getValorAtaque(aux, &valorAtaque))
			{
				nuevoValorAtaque = Gauna_Propia_CalcularValorAtaque(valorAtaque, 10);

				if(Gauna_Pokemon_setValorAtaque(aux, nuevoValorAtaque))
				{
					valido = 0;
				}
			}
		}
	}

	return valido;
}

int Gauna_Propia_CalcularValorAtaque(int valorActual, int porcentaje)
{
	int valorFinal;
	int calculo;

	calculo = (valorActual * porcentaje) / 100;

	if(calculo > 0)
	{
		valorFinal = valorActual + calculo;
	}

	return valorFinal;
}
