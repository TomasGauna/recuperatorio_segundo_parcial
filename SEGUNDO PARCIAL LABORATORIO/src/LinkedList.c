#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../inc/LinkedList.h"
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int len;

	len = ll_len(this);

	if(this != NULL && nodeIndex > - 1 && nodeIndex < len && len != -1)
	{
		pNode = this->pFirstNode;

		for(int i = 0; i < nodeIndex; i++)
		{
			pNode = pNode->pNextNode;
		}
	}

	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	int len;

	Node* pNodeAnterior = NULL;
	Node* pNode = NULL;

	len = ll_len(this);

	if(this != NULL && nodeIndex > -1 && nodeIndex <= len)
	{
		pNode = (Node*) malloc(sizeof(Node));

		if(pNode != NULL)
		{
			pNode->pElement = pElement;

			if(nodeIndex > 0)
			{
				pNodeAnterior = getNode(this, nodeIndex - 1);

				if(pNodeAnterior != NULL)
				{
					pNode->pNextNode = pNodeAnterior->pNextNode;
					pNodeAnterior->pNextNode = pNode;
				}
			}
			else
			{
				pNode->pNextNode = this->pFirstNode;
				this->pFirstNode = pNode;
			}

			this->size++;
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int returnAux = -1;
	int len;

	len = ll_len(this);

	if(this != NULL)
	{
		returnAux = addNode(this, len, pElement);
	}

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
	Node* pNode = NULL;
	int len;

	len = ll_len(this);

	if(this != NULL && index > -1 && index <= len)//compruebo
	{
		pNode = getNode(this, index);//obtengo el Nodo segun el index que me pasan

		if(pNode != NULL)
		{
			returnAux = pNode->pElement;//retorno el elemento del nodo que encontre, si es que lo encontre
		}
	}

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
	int returnAux = -1;
	Node* pNode = NULL;
	int len;

	len = ll_len(this);

    if(this != NULL && index > -1 && index <= len)//compruebo
    {
    	pNode = getNode(this, index);//obtengo el Nodo segun el index que me pasan

    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;//seteo el elemento que me pasan al elemento del nodo
    		returnAux = 0;
    	}
    }

	return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int returnAux = -1;

	Node* pNodeAnterior = NULL;
	Node* pNode = NULL;
	int len;

	len = ll_len(this);

	if(this != NULL && index > -1 && index <= len)//compruebo
	{
		pNode = getNode(this, index);

		if(pNode != NULL)
		{
			if(index == 0)//primero
			{
				this->pFirstNode = pNode->pNextNode;//le asigno al primer nodo, la direccion del nodo que estoy por remover

				free(pNode);//borro memoria dinamica
				pNode = NULL;
			}
			else
			{
				pNodeAnterior = getNode(this, index - 1);//obtengo uno antes del index que me pasan

				if(pNodeAnterior != NULL)
				{
					pNodeAnterior->pNextNode = pNode->pNextNode;//asigno al nodo que obtuve, la direccion del que estoy por borrar
					free(pNode);// borro
					pNode = NULL;
				}
			}

			this->size = len - 1;
			returnAux = 0;
		}
	}

	return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
	int len;

	len = ll_len(this);

    if(this != NULL)
    {
    	for(int i = 0; i < len; i++)//recorro lista
    	{
    		ll_remove(this, 0);//remuevo toda la lista
    	}
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int returnAux = -1;

	if(this != NULL)
	{
	   	ll_clear(this);
	   	free(this);
	   	returnAux = 0;
	}

	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* auxElement = NULL;
	int len;

	len = ll_len(this);

    if(this != NULL)
    {
    	for(int i = 0; i < len; i++)//recorro lista
    	{
    		auxElement = ll_get(this, i);//obtengo el elemento en el index de i

    		if(pElement == auxElement)//si el elemento auxiliar coincide con el que me pasaron, lo encontre//comparo direcc
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
	int len;

	len = ll_len(this);

    if(this != NULL)
    {
    	returnAux = 1;

    	if(len > 0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	int returnAux = -1;
	int len;

	len = ll_len(this);

	if(this != NULL && index > -1 && index <= len)
	{
		returnAux = addNode(this, index, pElement);//0 falso
	}

	return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	void* returnAux = NULL;
	void* aux = NULL;
	int len;

	len = ll_len(this);

	if(this != NULL && index > -1 && index <= len)
	{
		aux = ll_get(this, index);

		if(!ll_remove(this, index))
		{
			returnAux = aux;
		}
	 }

	return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	int returnAux = -1;

	if(this != NULL)
	{
	    returnAux = 0;

	    if(ll_indexOf(this, pElement) != -1)
	    {
	    	returnAux = 1;
	    }
	}

	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux = -1;
	void* pNode;

	if(this != NULL && this2 != NULL)
	{
		returnAux = 1;
		pNode = NULL;

		for(int i = 0; i < ll_len(this2); i++)//recorro la segunda lista
		{
			pNode = ll_get(this2, i);
			returnAux = ll_contains(this, pNode);//pregunto si el elemto obtenido esta en la lista 1
			break;
		}
	}

	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
	LinkedList* cloneArray = NULL;
	void* elementAux;
	int len;

	len = ll_len(this);

	if(this != NULL && from > -1 && from < to && to <= len)
	{
		elementAux = NULL;
	    cloneArray = ll_newLinkedList();

	    if(cloneArray != NULL)
	    {
	        for(int i = from; i < to; i++)//recorro la distancia que se quiera clonar
	        {
	        	elementAux = ll_get(this, i);//obtengo
	            ll_add(cloneArray, elementAux);//lo agrego a la clonacion//ll_add
	        }
	    }
	}

	return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
	LinkedList* cloneArray = NULL;
	int len;

	len = ll_len(this);

	if(this != NULL)
	{
		cloneArray = ll_subList(this, 0, len);
	}

	return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	 int returnAux = -1;
	 void* pElement1 = NULL;
	 void* pElement2 = NULL;
	 int len;

	 len = ll_len(this);

	 if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
	 {
		for(int i = 0; i < len - 1; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				pElement1 = ll_get(this, i);
				pElement2 = ll_get(this, j);

				if((pFunc(pElement1, pElement2) > 0 && order == 1) || (pFunc(pElement1, pElement2) < 0 && order == 0))
				{
					ll_set(this, i, pElement2);
					ll_set(this, j, pElement1);

				}
			}
		}

		returnAux = 0;
	 }

	 return returnAux;
}

/*La función “ll_filter” recibirá una lista y una función criterio “fn”. Se deberá iterar todos los elementos
de la lista y pasarlos a la función “fn”. La función “fn” devolverá 1 si ese ítem se debe agregar a la
lista resultado o 0 si no debe agregarse. La función “ll_filter” generará la nueva lista resultado,
agregará a la misma los ítems correspondientes y la devolverá.*/
LinkedList* ll_filter(LinkedList* this,int (*pFunc)(void*))
{
	LinkedList* nuevaLista = NULL;
	void* pElement;
	int len;
	int valido;

	nuevaLista = ll_newLinkedList();

	if(this != NULL && nuevaLista != NULL)
	{
		len = ll_len(this);

		for(int i = 0; i < len; i++)
		{
			pElement = ll_get(this, i);

			valido = pFunc(pElement);

			if(valido)
			{
				ll_add(nuevaLista, pElement);
			}
		}
	}

	return nuevaLista;
}

/*La funcion “ll_map” recibirá la lista y una función criterio “fn”. La función “fn” podrá realizar un cálculo
con el elemento recibido y modificar alguno de sus campos si es necesario. Al finalizar la iteración,
los elementos de la lista quedarán modificados.*/

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
	int valido = 0;
	int len;
	void* pElement;

	if(this != NULL)
	{
		len = ll_len(this);

		for(int i = 0; i < len; i++)
		{
			pElement = ll_get(this, i);

			valido = pFunc(pElement);
		}
	}

	return valido;
}

/*La funcion “ll_count” recibirá la lista y una función criterio “fn”. La función “fn” deberá devolver 1 en
caso de que el elemento recibido cumpla con el/los criterios especificados. Al finalizar la iteración, la
función count retornará la cantidad de elementos que pasaron el criterio.*/

int ll_count(LinkedList* this, int (*pFunc)(void*))
{
	int contador = 0;
	int len;
	void* pElement;

	if(this != NULL)
	{
		len = ll_len(this);

		for(int i = 0; i < len; i++)
		{
			pElement = ll_get(this, i);

			if(pFunc(pElement))
			{
				contador++;
			}
		}
	}

	return contador;
}
