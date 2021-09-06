# Edmonds Karp 

En ciencias de la computación y teoría de grafos, el Algoritmo de Edmonds-Karp es una implementación del método de Ford-Fulkerson para calcular el flujo maximal en una red de flujo(i.e. computer network) con complejidad O(V E2). Es asintóticamente más lento que el algoritmo de Push-relabel, que tiene complejidad O(V3), pero es habitualmente más rápido en la práctica para grafos ralos. El algoritmo fue publicado por primera vez por un científico soviético, Yefim (Chaim) Dinic, en 1970,1​ e independientemente por Jack Edmonds y Richard Karp en 1972.2​ El Algoritmo de Dinic incluye técnicas adicionales para reducir la complejidad a O(V2E).

![EDMONDS](https://es.wikipedia.org/wiki/Algoritmo_de_Edmonds-Karp#/media/Archivo:Edmonds-Karp_flow_example_0.svg)<br/><br/>
### _Primera Ruta:    **Min(100,50)=50**_<br/>

El algoritmo es idéntico al algoritmo de Ford-Fulkerson, excepto porque el orden para ir buscando los caminos aumentantes está definido. El camino encontrado debe ser el camino más corto que tiene capacidad disponible. Esto se puede encontrar mediante una búsqueda en anchura, ya que dejamos que los bordes tengan unidad de longitud. La complejidad O(V E2)3​ se fundamenta mostrando que cada camino aumentante puede ser encontrado con O(E), cada vez que al menos uno de los lados E se satura, la distancia desde el lado saturado hasta el origen a través del camino aumentante deberá ser más largo que la última vez que este estuvo saturado, y ese largo es a lo sumo V.
<br/>

### Esquema inicial<br/>
![Unsolved Problem](https://github.com/AleS900/prueba/blob/master/assets/EK1.png)<br/><br/>
### _Primera Ruta:    **Min(100,50)=50**_<br/>
![Problem Solution Step 1](https://github.com/AleS900/prueba/blob/master/assets/EK2.png)<br/><br/>
### _Segunda Ruta:    **Min(50,50,75)=50**_<br/>
![Problem Solution Step 1](https://github.com/AleS900/prueba/blob/master/assets/EK3%20(1).png)<br/><br/>
### _Tercera Ruta:    **Min(50,100,25)=25**_<br/>
![Problem Solution Step 1](https://github.com/AleS900/prueba/blob/master/assets/EK4.png)<br/><br/>
### _**NO EXISTEN RUTAS DISPONIBLES**_<br/>
![Problem Solution Step 1](https://github.com/AleS900/prueba/blob/master/assets/EKF.png)
### _**FlujoMAX= 50 + 50 + 25 = 125**_<br/><br/>

## Algoritmos Base
### Código
-  [Edmonds Karp](https://github.com/camgany/Algoritmica_2/blob/main/algoritmos/Teoria_Grafos/EdmodsKarp/edmonds_karp.cpp) - _C++_
