# BIT
Un árbol de Fenwick o un BIT (Binary indexed tree) es una estructura de datos que puede realizar actualizaciones de los elementos y calcular la suma de los prefijos en un arreglo de números de manera eficiente.
Algunas ventajas sobre el Segment tree son el espacio, ya que utiliza mucho menos y además es una estructura de datos más fácil de implementar. Sin embargo, es algo complejo de entender. 
![BIT](https://community.topcoder.com/i/education/binaryIndexedTrees/bitval.gif)

El árbol indexado binario se representa como una matriz. Deje que la matriz sea BITree []. Cada nodo del árbol indexado binario almacena la suma de algunos elementos de la matriz de entrada. El tamaño del árbol indexado binario es igual al tamaño de la matriz de entrada, denotado como n. En el siguiente código, usamos un tamaño de n + 1 para facilitar la implementación.

![BIT](https://media.geeksforgeeks.org/wp-content/cdn-uploads/BITSum.pngs/bitval.gif)

##Operaciones

- getSum (x): Devuelve la suma de la submatriz arr [0,…, x] 
// Devuelve la suma de la submatriz arr [0,…, x] usando BITree [0..n], que es construido a partir de arr [0..n-1] 

- update (x, val): actualiza el árbol indexado binario (BIT) realizando arr [index] + = val 

![BIT](![image](https://user-images.githubusercontent.com/84194948/130463408-1d80e795-27eb-4ea1-a018-ba7129584d5f.png))

## La idea detrás del BIT

La idea se basa en el hecho de que todos los enteros positivos se pueden representar como la suma de potencias de 2. Por ejemplo, 19 se puede representar como 16 + 2 + 1. Cada nodo del BITree almacena la suma de n elementos donde n es un potencia de 2. Por ejemplo, en el primer diagrama anterior (el diagrama para getSum ()), la suma de los primeros 12 elementos se puede obtener mediante la suma de los últimos 4 elementos (de 9 a 12) más la suma de 8 elementos (de 1 a 8). El número de bits establecidos en la representación binaria de un número n es O (Logn). Por lo tanto, atravesamos como máximo los nodos O (Logn) en las operaciones getSum () y update (). La complejidad temporal de la construcción es O (nLogn), ya que llama a update () para todos los n elementos. 

## Código base
-  [BIT](BIT.java) - _Java/T_
-  [BIT](bit.cpp) - _C++_
