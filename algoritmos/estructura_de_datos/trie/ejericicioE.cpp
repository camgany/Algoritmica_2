#include <bits/stdc++.h> 

using namespace std; 

struct node {// creamos un nodo del tamano sdel abecedario
    char currentCharacter;  //caracter actual      
    bool isWord;//variable que diga si es una palabra o no es una palabra
   //  int priority = 0;  //cuantas palabras empiezan con ese prefijo          
    struct node *children[10];  // [null,null,null,......,null] primer nodo donde todo va a estar nulo array de nodos
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
        int character = word[i] - '0';       // i = 0 'a'-'a' = 0 posicion de la palabra a que da 0
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
        int character = word[i] - '0';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL) {
           return false;
        } 
      
        currentNode = currentNode->children[character];
        
         cout<<currentNode->currentCharacter<<endl;
    }
      for(int i=0;i<10;i++ ){
            if(currentNode->children[i]!=NULL){
                return false;
            }
        } 
    return currentNode->isWord;
}
 
 


void isThereWord(string word) {
    if(searchWord(word)) {
        cout<<"si existe : "<<word<<" en el trie"<<endl;
    } else {
        cout<<"No Existe :P"<<endl;
    }
}


int main() {

    // Inicializar Trie
    init();  
    insertWord("911");
    insertWord("91178");
    isThereWord("911");
    return 0;
}