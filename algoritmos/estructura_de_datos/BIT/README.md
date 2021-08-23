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
## Código base
-  [BIT](bit.cpp) - _C++_

