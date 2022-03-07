#include "../include/palabra.h"

std::string clave_random() {
    std::string key;
    int tam = 3 + (rand() % 5);
    key.resize(tam);
    for(int i = 0; i < tam; i++)
        key[i] = char((rand() % ASCII_RANGE) + ASCII_MIN);
    return key;
}

int main(){
    std::string aux;
    int opcion = 0;
    bool clave_asignada = false;
    std::string clave = "";
    std::palabra pal = "";

    do{
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Clave: " << clave.get_palabra() << std::endl;
        std::cout << "Última palabra usada: " << pal.get_palabra() << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Introduce el número de la opción deseada: \n";
        std::cout << "1. Asignar clave \n";
        std::cout << "2. Asignar clave aleatoria \n";
        std::cout << "3. Decodificar \n";
        std::cout << "4. Salir \n";
        std::cin >> opcion;

        switch(opcion){
            case 1:
                    std::cout << "Introduce la nueva clave: ";
                    std::cin >> clave;
                    clave_asignada = true;
                    break;
            case 2:
                    clave = clave_random();
                    clave_asignada = true;
                    break;
            case 3: if(clave_asignada){
                        std::cout << "Introduce la palabra que deseas codificar: ";
                        std::cin >> aux;
                        pal.set_palabra(aux);

                        // Imprimir en decimal
                        std::cout << "Decimal:       ";
                        for(int i = 0; i < int(aux.length());i++){
                            std::cout << pal.get_ascii()[i] << " ";
                        }
                        std::cout << std::endl;

                        // Imprimir palabra en binario
                        std::cout << "Binario:       ";
                        for(int i = 0; i < int(aux.length());i++){
                            std::cout << pal.get_binario(i) << " ";
                        } std::cout << std::endl;

                        // Imprimir clave en binario
                        std::cout << "Clave binaria: ";
                        for(int i = 0, j = 0; i < int(aux.length());i++, j++){
                            if(j >= clave.get_longitud()) j = 0;
                            std::cout << clave.get_binario(j) << " ";
                        } std::cout << std::endl;

                        pal = clave.suma(pal);
                        // Imprimir resultado en binario
                        std::cout << "Codificación:  ";
                        for(int i = 0; i < int(aux.length());i++){
                            std::cout << pal.get_binario(i) << " ";
                        } std::cout << std::endl;

                        // Imprimir resultado en ascii
                        std::cout << "Decimal cod.:  ";
                        for(int i = 0; i < int(aux.length());i++){
                            std::cout << pal.get_ascii()[i] << " ";
                        } std::cout << std::endl;

                        // Imprimir palabra
                        std::cout << "Palabra cod.:  " << pal.get_palabra() << std::endl << std::endl;
                    }break;
            case 4: break;
            default: std::cout << "Introduce un número del 1 al 4.\n";
        }
        std::cout << std::endl;
    }while(opcion != 4);

    return 0;
}