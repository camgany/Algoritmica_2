#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 

struct node {// creamos un nodo del tamano sdel abecedario
    char currentCharacter;  //caracter actual      
    bool isWord;//variable que diga si es una palabra o no es una palabra
   //  int priority = 0;  //cuantas palabras empiezan con ese prefijo          
    struct node *children[10];  // [null,null,null,......,null] primer nodo donde todo va a estar nulo array de nodos
    //node() {
    //    isWord = false;
    //}//hasta ahi creamos una estructura
}*trie; // referencia es el asterisgo, estamos apuntando al nodo de referencia
// lo que estamos haciendo es crear una variable
// Inicializar 

void init() {
    trie = new node();  // Instanciar el objeto trie inicializamos el arbol y crea todo eso
    for(int i=0;i<10;i++){
        cout<<trie->children[i]<<endl;
    }
}

void insertWord(string word) {   // alba 
cout<<"by"<<endl;
    node *currentNode =  trie;  //jalamos el puntero y lo colocamos en el nodo trie*(nodo cero)
    for (int i = 0; i< word.length(); i++) { // alba// se pregunta que si existe la palabra 
        int character = word[i] - '0';       // i = 0 'a'-'a' = 0 posicion de la palabra a que da 0
        cout<<(currentNode->children[character]==NULL)<<endl;
        if(currentNode->children[character] == NULL ) {//en trie andate a los hijos y en la posicion 0 dime si hay un nodo o es nulo
            cout<<"hi"<<endl;
            currentNode->children[character] = new node();// si es nulo en esa posicion crea un nodo
            currentNode->isWord = false;
        }
      //   currentNode = max(currentNode->priority,priority);
        currentNode = currentNode->children[character];//cambiamos el puntero y ahora el puntero sera el que hemos creado
        currentNode->currentCharacter = word[i];// le estamos poniendo el caracter, que es, le ponemos el nodo, le decimos esto es a
    }
    currentNode->isWord = true;//una vez que termina con todo eso  pone que la ultima letra es final de palabra
cout<<"bye"<<endl;
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
     //cout<<currentNode->currentCharacter<<endl;
    for (int i = 0; i<=sizeof(currentNode->children);i++){
        if(currentNode->children[i]==NULL){   
            currentNode->isWord = true;
        }else{
            currentNode->isWord = false;

        }
        
    }
     
    return currentNode->isWord;
}
 
 void isThereWord(string word) {
     cout<<"dfsd"<<endl;
    if(searchWord(word)) {
        cout<<"si existe : "<<word<<" en el trie"<<endl;
    } else {
        cout<<"No Existe :P"<<endl;
    }
}


int main() {
    input;
    output;
    init();
    cout<<"hola"<<endl;  
    insertWord("911");
    insertWord("91178");
    isThereWord("911");
    string palabra;
    cin>>palabra;
    cout<<palabra<<endl;
    /*int cases;
    cin >> cases;  
    while(cases>0){
         init(); 
        int problems;
        cin >> problems;
        int a = problems;
        int numberCases=0;
         string palabras[problems]; 
        while(a > 0){ 
            string word;
            cin>> word;
             insertWord(word);
             palabras[numberCases]=word;
             numberCases++; 
          a--;
         }
         int contador = 0;
         for(int i = 0; i<problems;i++){
             if(searchWord(palabras[i])){
                 contador++;
             }
         }
         if (contador==problems){
          cout<<"YES"<<endl; 
         }else{
             cout<<"NO"<<endl;  
         }
     
     cases--;
     }*/
    return 0;
    
    }

