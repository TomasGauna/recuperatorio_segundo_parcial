#ifndef BIBLIOTECA_PROPIA_H_
#define BIBLIOTECA_PROPIA_H_

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "utn.h"
#include "pokemon.h"

/// @brief pide al usuario una opcion de las que muestra por pantalla
/// y verifica que este dentro del rango proporcionado
///
/// @return la opcion elegida
int Gauna_Propia_PedirOpcion();

/// @brief pide al usuario que ingrese un id
///
/// @return el id ingresado
int Gauna_Propia_PedirId();

/// @brief busca en la lista el id recibido por parametro
///
/// @param pArrayListPokemons lista de pokemones
/// @param id numero entero
/// @return [-1] si no encontro el id/ la posicion del id en el array
int Gauna_Propia_BuscarId(LinkedList* pArrayListPokemons, int id);

/// @brief Elimina un pokemon seleccionado por el usuario de la lista
///
/// @param pArrayListPokemons lista de pokemones
/// @param id numero entero
/// @return [0] si la baja no se realizo/ [1] si esta ok
int Gauna_Propia_EliminarPokemon(LinkedList* pArrayListPokemons, int id);

/// @brief filtra los pokemones del tipo agua y que sean vario color
///
/// @param pElement elemento recibido de la lista de pokemones
/// @return [1] si el elemento entra en el criterio/ [0] si no lo esta
int Gauna_Propia_FilterWaterShiny(void* pElement);

/// @brief filtra y mapea a los pokemones de tipo Fire, Grass y Ground
///
/// @param pElement elemento recibido de la lista de pokemones
/// @return [0] si entra en el criterio y se pudo setear el nuevo valor de ataque/
/// [1] si no pertenece al criterio o no se puso setear el valor
int Gauna_Propia_MapFilterFGG(void* pElement);

/// @brief calcula el nuevo valor de ataque con un valor inicial y un porcentaje
///
/// @param valorActual valor al cual se le va a hacer el calculo
/// @param porcentaje entero con el cual se va a hacer el calculo
/// @return nuevo valor despues del calculo
int Gauna_Propia_CalcularValorAtaque(int valorActual, int porcentaje);

/// @brief filtra y mapea pokemones del tipo Bug, Fire y Grass
///
/// @param pElement elemento recibido de la lista de pokemones
/// @return [1] si entra en el criterio y se pudo setear el nuevo valor de ataque/
/// [0] si no pertenece al criterio o no se puso setear el valor
int Gauna_Propia_MapFilterBFG(void* pElement);

/// @brief Filtra un equipo segun el criterio
///
/// @param pElement elemento recibido de la lista de pokemones
/// @return [1] si entra en el criterio [0] si no pertenece al criterio
int Gauna_Propia_FormarEquipo(void* pElement);
#endif
