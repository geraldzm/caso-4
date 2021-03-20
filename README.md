# Caso 4, análisis de algoritmos
 
 **Este proyecto consiste en crear el siguiente patron**
 
 ![pattern](https://i.imgur.com/RYcV2Wm.png)
 
 Para crear esta ilusión óptica primero se calcula el alto y ancho de los cuadrados (es el mismo para todos) dependiendo del area dada. Luego se recorre la matriz de cuadros y se le asigna una coordenada (columna * ancho + offset,   fila * alto)  cada vez que se cambia de fila se calcula un offset con la función seno, este offset se le suma a su posición x.

# O(n)

Ya que el alto y ancho son variables totalmente separadas, tomamos N como
 

     n = amountRectsHeight*amountRectsWidth

La n representa la cantidad de elementos o cuadros en la matriz, solo se debe recorrer una vez, por ende O(n)

 

    for(int row = 0; row < amountRectsHeight; ++row) {
	 
	    for(int column = 0; column < amountRectsWidth; ++column) {  
	 
      }  
      
    }


# Opcional
**Para pintar el patron** 

 1.  Descomentar estas tres lineas de código  

    //string* json = generateStringForProcessing(pattern);  
    //cout << *json << endl;  
    //delete json;  
2. Copiar el output
3.  Pegar el output Dentro de la función setup en processing

```
void setup() {  
	    size(940, 800);  
	    squares = convertString("---PEGAR AQUÍ---");  
}
```
4.  Ejecutar  

