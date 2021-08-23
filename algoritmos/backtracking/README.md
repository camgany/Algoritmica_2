# Backtracking
Backtricking es una tecnica que se utiliza para resolver problemas de manera recursiva intentando construir una solución de forma incrementeal, una pieza a la vez, quitando las soluciones que fallan en en satisfacer las condiciones del problema en cualquier momento del tiempo. 

![Backtracking](https://miro.medium.com/max/875/1*Q-DyKa25eozOeMdN5YQONA.png)

La técnica de backtracking esta muy asociada a la recursividad, o mas propiamente, a la estructura recursiva de la mayoría de tipos de datos: listas, árboles, etc.

![Backtracking](https://www.apascualco.com/wp-content/uploads/2020/01/backtrakcing.png)

Esta técnica consiste básicamente en :

- Enumerar sistemáticamente las alternativas que existen en cada momento para dar con la solución a un problema.

- Se prueba una alternativa, guardando memoria del resto de alternativas.

- Si no damos con la solución, podemos dar marcha atrás (backtracking) y probar otra alternativa.

## Código base
### 8 queens
-  [8queens](8queen.cpp) - _C++_
### Sudoku
-  [Sudoku](sudoku.cpp) - _C++_
