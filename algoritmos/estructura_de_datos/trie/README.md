
# TRIE
El trie es una estructura de datos, mas conocido como arbol de busqueda. Su funcion es al macenar un array en que se utilizan strings. 
Este tiene las siguientes caracteristicas:
 - es un arbol ordenado.
 - cada nodo es etiquetado con un caracter.
 - se etiqueta al nodo como fin de palabra.
 - el primer nodo vacio, porque vamos a tener un conjunto de letras que van a empezar de diferente forma. 
 La ventaja en el tiempo de complejidad n (tamano de la palabra) x m (cantidad de palabras).
Aplicaciones del trie:
 - autocompletado
 - busqueda diccionario
 - opciones de palabras
 - hallar el maximo prefijo comun. 

Para empezar tenemos al trie como un nodo vacio con un array de 27 (el tamano del abecedario), el cual siempre debe estar vacio ya que si lo llenamos con alguna letra, este ya no podra tener otras letras. Se crea un nuevo nodo que tambien tendra un array de 27 y se llenara el caracter correspondiente en el lugar de la letra y si sigue habiendo nueva letras, se crean nuevos nodos de forma recursiva, hasta llegar al final de la palabra donde se la marcara con un operador booleanos si es el final de la palabra o no. 
El codigo explicado mas detalladamente sera:

struct node {// creamos un nodo del tamano sdel abecedario
    char currentCharacter;  //caracter actual      
    bool isWord;//variable que diga si es una palabra o no es una palabra
   //  int priority = 0;  //cuantas palabras empiezan con ese prefijo          
    struct node *children[27];  // [null,null,null,......,null] primer nodo donde todo va a estar nulo array de nodos
    node() {
        isWord = false;
    }//hasta ahi creamos una estructura
}*trie; // referencia es el asterisgo, estamos apuntando al nodo de referencia
// lo que estamos haciendo es crear una variable
// Inicializar 

void init() {
    trie = new node();  // Instanciar el objeto trie inicializamos el arbol y crea todo eso
}

void insertWord(string word) {   // alba 
    node *currentNode =  trie;  //jalamos el puntero y lo colocamos en el nodo trie*(nodo cero)
    for (int i = 0; i< word.length(); i++) { // alba// se pregunta que si existe la palabra 
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0 posicion de la palabra a que da 0
        if(currentNode->children[character] == NULL ) {//en trie andate a los hijos y en la posicion 0 dime si hay un nodo o es nulo
            currentNode->children[character] = new node();// si es nulo en esa posicion crea un nodo
           // currentNode->isWord = false;
        }
      //   currentNode = max(currentNode->priority,priority);
        currentNode = currentNode->children[character];//cambiamos el puntero y ahora el puntero sera el que hemos creado
        currentNode->currentCharacter = word[i];// le estamos poniendo el caracter, que es, le ponemos el nodo, le decimos esto es a
    }
    currentNode->isWord = true;//una vez que termina con todo eso  pone que la ultima letra es final de palabra
}

bool searchWord(string word) {   // alto 
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
           return false;
        }
        currentNode = currentNode->children[character];
         cout<<currentNode->currentCharacter<<endl;
    }
    return currentNode->isWord;
}
 
bool deleteWord(string word) {   // colocamos la palabra a eliminar
    node *currentNode =  trie;  // colocamos el puntero en la cabeza, el nodo vacio del trie
for (int i = 0; i< word.length(); i++) {//creamos un for para recorrer la palabra
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0 creamos una variable que sera la posicion que estara en el array
        if(currentNode->children[character] == NULL ) {//vemos si los hijos del nodo que estamos estan nulos
           return false;// si es asi retornamos falso
        }
        currentNode = currentNode->children[character];//creamos un nodo en el hijo de la posicion indicada
         cout<<currentNode->currentCharacter<<endl;//imprimimos el caracter que esta
    }
    return currentNode->isWord=false;//colocamos que el final de la palabra estara en falso
    }   
  
 


void isThereWord(string word) {
    if(searchWord(word)) {
        cout<<"si existe : "<<word<<" en el trie"<<endl;
    } else {
        cout<<"No Existe :P"<<endl;
    }
}

void removeWord(string word){
if(searchWord(word)){
if(!deleteWord(word)){
cout<<"Se elimino la palabra con exito"<<endl;
}else {
   cout<<"No se elimino la palabra con exito"<<endl; 
}
}
}
