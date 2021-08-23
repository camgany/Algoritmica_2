# Rod Cutting
Dado que la programación dinámica es principalmente una recursividad de optimización sobre simple, podemos usarla para optimizar el algoritmo de tiempo exponencial.

El corte de varillas es otro tipo de problema que se puede resolver sin utilizar un enfoque de programación dinámica , pero podemos optimizarlo en gran medida usándolo. Según el problema, contamos con una varilla larga de longitud r norte unidades. Podemos cortar la varilla en diferentes tamaños y cada tamaño tiene un costo diferente asociado, es decir, una varilla de I unidades de longitud tendrá un costo de C 1$ . Veamos la tabla que se muestra a continuación que muestra el costo en función de la longitud de la varilla.

![Rod Cutting](https://www.codesdope.com/staticroot/images/algorithm/rod1.png)

En la tabla anterior, puede ver que la varilla de longitud 1 unidad tiene un precio de 10 $ y una varilla de longitud 2 tiene un precio de 24 $ , etc. Ahora, nuestra tarea es generar las piezas de la varilla en tal una forma en que los ingresos generados por la venta de todas las piezas sean máximos (digamos que estos ingresos máximos son r norte para una varilla de longitud n unidades).

Tomemos un caso en el que nuestra varilla tiene 4 unidades de largo, entonces tenemos las siguientes formas diferentes de cortarla:

![Rod Cutting](https://www.codesdope.com/staticroot/images/algorithm/rod2.png)
Así, puedes ver que para una caña de 4 unidades de largo, cortarla en dos piezas de 2 unidades de largo genera el máximo beneficio para nosotros.

Nuestra tarea es encontrar el valor de rnorte (ingreso máximo que se puede generar a partir de una barra de longitud n unidades).
## Código base
-  [Segment Tree](https://github.com/camgany/Algoritmica_2/blob/main/algoritmos/programacion_dinamica/RodCutting/rod_cutting.cpp) - _C++_

