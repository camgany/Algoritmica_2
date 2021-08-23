# Segment Tree
Un árbol de segmentos es una estructura de datos que permite responder consultas de rango sobre una matriz de manera efectiva, sin dejar de ser lo suficientemente flexible como para permitir modificar la matriz. Esto incluye encontrar la suma de elementos de matriz consecutivosa [ l ... r ], o encontrar el elemento mínimo en tal rango en  O(logn) tiempo. Entre responder a tales consultas, el árbol de segmentos permite modificar la matriz reemplazando un elemento, o incluso cambiar los elementos de un subsegmento completo (por ejemplo, asignando todos los elementosa [ l ... r ] a cualquier valor, o agregando un valor a todos los elementos del subsegmento).

![Segment Tree](https://he-s3.s3.amazonaws.com/media/uploads/a0c7f90.jpg)

En general, un árbol de segmentos es una estructura de datos muy flexible y con él se pueden resolver una gran cantidad de problemas. Además, también es posible aplicar operaciones más complejas y responder consultas más complejas (consulte Versiones avanzadas de árboles de segmentos ). En particular, el árbol de segmentos se puede generalizar fácilmente a dimensiones más grandes. Por ejemplo, con un árbol de segmentos bidimensional, puede responder consultas de suma o mínimo sobre algún subrectángulo de una matriz determinada. Sin embargo, solo en  O(log2n).

El árbol de segmentos se utiliza en los casos en que existen múltiples consultas de rango en la matriz y modificaciones de elementos de la misma matriz. Por ejemplo, encontrar la suma de todos los elementos de una matriz a partir de índices para , o encontrar el mínimo (conocido como problema de consulta de rango mínimo) de todos los elementos en una matriz a partir de índices  para . Estos problemas se pueden resolver fácilmente con una de las estructuras de datos más versátiles, Segment Tree .
![Segment Tree](https://media.geeksforgeeks.org/wp-content/cdn-uploads/segment-tree1.png)
## Implementación:

Dado que un árbol de segmentos es un árbol binario , se puede utilizar una matriz lineal simple para representar el árbol de segmentos. Antes de construir el árbol de segmentos, uno debe averiguar qué se debe almacenar en el nodo del árbol de segmentos. .
Por ejemplo, si la pregunta es encontrar la suma de todos los elementos en una matriz a partir de índices para , luego en cada nodo (excepto los nodos hoja) se almacena la suma de sus nodos secundarios.

Se puede construir un árbol de segmentos usando recursividad (enfoque de abajo hacia arriba) . Empiece por las hojas y suba a la raíz y actualice los cambios correspondientes en los nodos que están en el camino de las hojas a la raíz. Las hojas representan un solo elemento. En cada paso, los datos de dos nodos secundarios se utilizan para formar un nodo principal interno. Cada nodo interno representará una unión de los intervalos de sus hijos. La combinación puede ser diferente para diferentes preguntas. Entonces, la recursividad terminará en el nodo raíz que representará la matriz completa.

![Segment Tree](https://gblobscdn.gitbook.com/assets%2F-M7JACxIEuMBezDCzfss%2F-MC-o-2M4xnP2IgI7C3x%2F-MC-oCLNM561SSEuEMgy%2Fimage.png?alt=media&token=bdfa9ed1-f425-41f0-bb8a-622af03424bd)

Para update(), busque la hoja que contiene el elemento a actualizar. Esto se puede hacer yendo al hijo de la izquierda o al hijo de la derecha, según el intervalo que contiene el elemento. Una vez que se encuentra la hoja, se actualiza y nuevamente usa el enfoque de abajo hacia arriba para actualizar el cambio correspondiente en la ruta de esa hoja a la raíz.

Hacer un query() en el árbol de segmentos, seleccione un rango de  para (que generalmente se da en la pregunta). Recurra en el árbol comenzando desde la raíz y verifique si el intervalo representado por el nodo está completamente en el rango de para . Si el intervalo representado por un nodo está completamente en el rango de para , devuelve el valor de ese nodo.
## Código base
-  [Segment Tree](segmentTree.cpp) - _C++_
