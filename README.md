# Práctica 2. Seguridad en Sistemas Informáticos
<u>Nombre:</u> Leonardo Alfonso Cruz Rodríguez  
<u>Correo:</u> alu0101233093@ull.edu.es  

Este programa hecho en C++ permite codificar y decodificar palabras utilizando el cifrado RC4.

## Aspectos relevantes del cifrado
Para que las palabras codificadas se puedan representar por consola, he decidido restarle 65 unidades al código ASCII de todas las letras.
De tal manera que el primer caracter (el caracter número 0) será la A mayúscula. La constante `ASCII_MAX` en la línea 6 del fichero
`palabra.h` en el directorio `include` almacena el valor ASCII de la letra Z y la constante `ASCII_MIN` almacena el valor ASCII de la letra A.
Estos valores no solo sirven para reducir los valores del código ASCII, también permiten generar claves aleatorias que estén en el rango
entre `ASCII_MAX` y `ASCII_MIN`.

## Directorio
### /build
Este directorio contiene los archivos generados por el make.
### /src
Este directorio contiene el fichero `main.cc` (con el código del menú y las impresiones por consola).
### Makefile
Permite compilar todos los archivos con el comando `make`.
### RC4
Archivo ejecutable para iniciar el programa. Para usarlo se debe teclear en consola `./RC4`