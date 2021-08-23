# Union find
La estructura Union-Find, también llamada Disjoint-set Union (abreviado DSU), es una estructura que nos permite manejar conjuntos disjuntos de elementos. Un ejemplo de esto en grafos son las componentes conexas, que son conjuntos disjuntos de nodos.

Union Find es una estructura de datos de conjuntos disjuntos es una estructura de datos que realiza un seguimiento de un conjunto de elementos divididos en varios subconjuntos disjuntos (no superpuestos). Un algoritmo de búsqueda de unión es un algoritmo que realiza dos operaciones útiles en dicha estructura de datos:

Buscar: determina en qué subconjunto se encuentra un elemento en particular. Esto se puede usar para determinar si dos elementos están en el mismo subconjunto.

Unión: une dos subconjuntos en un solo subconjunto.

![Union find](https://helloacm.com/wp-images/acm/2012/data-structure/disjoint2.jpg)

El algoritmo Union-Find se puede usar para verificar si un gráfico no dirigido contiene ciclo o no. Tenga en cuenta que hemos discutido un algoritmo para detectar ciclos . Este es otro método basado en Union-Find . Este método asume que el gráfico no contiene bucles propios. 

![Union find](https://cgi.luddy.indiana.edu/~yye/c343-2019/images/Figure6.5.png)

## Código base
-  [Union find](unionFind.cpp) - _C++_
