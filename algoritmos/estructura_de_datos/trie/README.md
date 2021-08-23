
# TRIE
El trie es una estructura de datos, mas conocido como arbol de busqueda. Su funcion es al macenar un array en que se utilizan strings.

![TRIE](https://upload.wikimedia.org/wikipedia/commons/b/be/Trie_example.svg)

Este tiene las siguientes caracteristicas:
 - es un arbol ordenado.
 - cada nodo es etiquetado con un caracter.
 - se etiqueta al nodo como fin de palabra.
 - el primer nodo vacio, porque vamos a tener un conjunto de letras que van a empezar de diferente forma. 
 
![TRIE](https://static.javatpoint.com/ds/images/trie-data-structure.png)

 La ventaja en el tiempo de complejidad n (tamano de la palabra) x m (cantidad de palabras).
Aplicaciones del trie:
 - autocompletado
 - busqueda diccionario
 - opciones de palabras
 - hallar el maximo prefijo comun. 

![TRIE](https://datastructures.maximal.io/img/tries/trie-0.svg)
Para empezar tenemos al trie como un nodo vacio con un array de 27 (el tamano del abecedario), el cual siempre debe estar vacio ya que si lo llenamos con alguna letra, este ya no podra tener otras letras. Se crea un nuevo nodo que tambien tendra un array de 27 y se llenara el caracter correspondiente en el lugar de la letra y si sigue habiendo nueva letras, se crean nuevos nodos de forma recursiva, hasta llegar al final de la palabra donde se la marcara con un operador booleanos si es el final de la palabra o no. 

