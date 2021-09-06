# Busqueda Binaria
La búsqueda binaria es un algoritmo eficiente para encontrar un elemento en una lista ordenada de elementos. Funciona al dividir repetidamente a la mitad la porción de la lista que podría contener al elemento, hasta reducir las ubicaciones posibles a solo una. Usamos la búsqueda binaria en el juego de adivinar en la lección introductoria.

![Busqueda Binaria](https://s3-us-west-2.amazonaws.com/devcodepro/media/tutorials/img3.png)

Una de las maneras más comunes de usar la búsqueda binaria es para encontrar un elemento en un arreglo. Por ejemplo, el catálogo estelar Tycho-2 contiene información acerca de las 2,539,913 estrellas más brillantes en nuestra galaxia. Supón que quieres buscar en el catálogo una estrella en particular, con base en el nombre de la estrella. Si el programa examinara cada estrella en el catálogo estelar en orden empezando con la primera, un algoritmo llamado búsqueda lineal, la computadora podría, en el peor de los casos, tener que examinar todas las 2,539,913 de estrellas para encontrar la estrella que estás buscando. Si el catálogo estuviera ordenado alfabéticamente por nombres de estrellas, la búsqueda binaria no tendría que examinar más de 22 estrellas, incluso en el peor de los casos.

![Busqueda Binaria 2](https://slideplayer.es/slide/4909881/16/images/4/Pseudoc%C3%B3digo+para+B%C3%BAsqueda+Binaria.jpg)

La búsqueda binaria es computada en el peor de los casos en un tiempo logarítmico, realizando {\displaystyle O{\bigl (}\log n{\bigr )}}{\displaystyle O{\bigl (}\log n{\bigr )}} comparaciones, donde n es el número de elementos del arreglo y log es el logaritmo. La búsqueda binaria requiere solamente O(1) en espacio, es decir, que el espacio requerido por el algoritmo es el mismo para cualquier cantidad de elementos en el array.5​ Aunque estructuras de datos especializadas en la búsqueda rápidas como las tablas hash pueden ser más eficientes, la búsqueda binaria se aplica a un amplio rango de problemas de búsqueda.

Aunque la idea es simple, implementar la búsqueda binaria correctamente requiere atención a algunos detalles como su condición de parada y el cálculo del punto medio de un intervalo.
-  [Busqueda Binaria](https://github.com/camgany/Algoritmica_2/blob/main/algoritmos/busqueda_binaria/mayor.cpp)

