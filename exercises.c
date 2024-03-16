#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) {
int mayor = arr[0];
for (int i = 1; i < size; i++)
  {
    if (arr[i] > mayor){
      mayor = arr[i];
    }
  }
return mayor; 
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
int temp;
for (int i = 0; i < size / 2; i++) {
  temp = arr[i];
  arr[i] = arr[size - i - 1];
  arr[size - i - 1] = temp;
}  
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
newsize apunta a una dirección válida que no ha sido inicializada con nigún valor específico. 
*newsize debe almacenar el tamaño del nuevo arreglo que se retorna.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) { 
int contador = 0;
for (int i = 0; i < size; i++) {
  if (arr[i] % 2 == 0) {
    contador++;
  }
}
int *nuevoArreglo = (int *)malloc(contador * sizeof(int));
if (nuevoArreglo == NULL) {
  *newSize = 0;
  return NULL; }

int k = 0;
for (int i = 0; i < size; i++) {
  if (arr[i] % 2 == 0) {
    nuevoArreglo[k] = arr[i];
    k++;
  }
}
*newSize = contador;
return nuevoArreglo;
} 

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados de menor a mayor y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado de menor a mayor.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0;
    int k = 0;
    int z = 0;

    while (i < size1 && k < size2) {
        if (arr1[i] < arr2[k]) {
            result[z++] = arr1[i++];
        } else {
            result[z++] = arr2[k++];
        }
    }

    while (i < size1) {
        result[z++] = arr1[i++];
    }
    while (k < size2) {
        result[z++] = arr2[k++];
    }
}


/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) { 
int i;
int ascent = 1;
int descent = 1;
for (i = 1; i < size; i++) {
  if (arr[i - 1] > arr[i]) {
    ascent = 0;
  } else if (arr[i - 1] < arr[i]) {
    descent = 0;
  }
}
if (ascent == 1) {
  return 1;
} else if (descent == 1) {
  return -1;
} else {
  return 0;
}
  
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion) 
{
  strcpy(libro->titulo, titulo);
  libro->anioPublicacion = anioPublicacion;;
  strcpy(libro->autor.nombre, nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
Puedes guiarte con lo que vimos en las clases (diapos).
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) 
{
  Nodo *primero = NULL;
  Nodo *ultimo = NULL;

  for (int i = 0; i < size; i++)
    {
      Nodo *list = (Nodo *)malloc(sizeof(Nodo));
      if (list == NULL) exit(EXIT_FAILURE);

      list->numero = arr[i];
      list->siguiente = NULL;

      if (primero == NULL)
        primero = list;
      else
        ultimo->siguiente = list;
      ultimo = list;
    }
  
  
  return primero; 
}
