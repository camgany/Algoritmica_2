# BIT
Un árbol de Fenwick o un BIT (Binary indexed tree) es una estructura de datos que puede realizar actualizaciones de los elementos y calcular la suma de los prefijos en un arreglo de números de manera eficiente.

Esta estructura fue propuesta por Boris Ryabko en 1989 [1] con una modificación adicional publicada en 1992. [2] Posteriormente se conoció con el nombre de árbol de Fenwick en honor a Peter Fenwick , quien describió esta estructura en su artículo de 1994. 
![BIT](https://he-s3.s3.amazonaws.com/media/uploads/68f2369.jpg)
La imagen de arriba muestra el árbol indexado binario, cada cuadro adjunto del cual denota el valor BIT [índice] y cada BIT [índice] almacena la suma parcial de algunos números.

Algunas ventajas sobre el Segment tree son el espacio, ya que utiliza mucho menos y además es una estructura de datos más fácil de implementar. Sin embargo, es algo complejo de entender.
Los árboles de Fenwick están especialmente diseñados para implementar el algoritmo de codificación aritmética , que mantiene los recuentos de cada símbolo producido y necesita convertirlos a la probabilidad acumulativa de un símbolo menor que un símbolo dado. En ese caso, el desarrollo de las operaciones que soporta fue motivado principalmente por el uso.

El uso de un árbol de Fenwick solo requiere {\ Displaystyle O (\ log n)}O (\ log n) operaciones para calcular cualquier suma acumulativa deseada, o más generalmente la suma de cualquier rango de valores (no necesariamente comenzando en cero).

Los árboles de Fenwick se pueden ampliar para actualizar y consultar submatrices de matrices multidimensionales. Estas operaciones se pueden realizar con complejidad{\ Displaystyle O (4 ^ {d} \ log ^ {d} n)}{\ Displaystyle O (4 ^ {d} \ log ^ {d} n)}, dónde {\ Displaystyle d}D es el número de dimensiones y {\ Displaystyle n}nortees el número de elementos a lo largo de cada dimensión.
![BIT](https://community.topcoder.com/i/education/binaryIndexedTrees/bitval.gif)

El árbol indexado binario se representa como una matriz. Deje que la matriz sea BITree []. Cada nodo del árbol indexado binario almacena la suma de algunos elementos de la matriz de entrada. El tamaño del árbol indexado binario es igual al tamaño de la matriz de entrada, denotado como n. En el siguiente código, usamos un tamaño de n + 1 para facilitar la implementación.

![BIT](https://www.codingninjas.com/blog/wp-content/uploads/2020/09/image-140.png)

##Operaciones

- getSum (x): Devuelve la suma de la submatriz arr [0,…, x] 
// Devuelve la suma de la submatriz arr [0,…, x] usando BITree [0..n], que es construido a partir de arr [0..n-1] 

- update (x, val): actualiza el árbol indexado binario (BIT) realizando arr [index] + = val 

![BIT](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR5stmJrtxIw7u4w3ttRxBT0kE-nJZJKiFhOUQl-pKRwnMw6EpQCsyFKtTEH_ykf53sOGQ&usqp=CAU)

## La idea detrás del BIT

La idea se basa en el hecho de que todos los enteros positivos se pueden representar como la suma de potencias de 2. Por ejemplo, 19 se puede representar como 16 + 2 + 1. Cada nodo del BITree almacena la suma de n elementos donde n es un potencia de 2. Por ejemplo, en el primer diagrama anterior (el diagrama para getSum ()), la suma de los primeros 12 elementos se puede obtener mediante la suma de los últimos 4 elementos (de 9 a 12) más la suma de 8 elementos (de 1 a 8). El número de bits establecidos en la representación binaria de un número n es O (Logn). Por lo tanto, atravesamos como máximo los nodos O (Logn) en las operaciones getSum () y update (). La complejidad temporal de la construcción es O (nLogn), ya que llama a update () para todos los n elementos. 

## Código base
-  [BIT](bit.cpp) - _C++_
<<<<<<< HEAD

=======
>>>>>>> ba8efbbcf5f69a29a021939529b8833f0f5b9a62
