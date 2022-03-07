#include <bitset>
#include <iostream>
#include <vector>
#include <cmath>

const int ASCII_MAX = 90;
const int ASCII_MIN = 65;
const int ASCII_RANGE = ASCII_MAX - ASCII_MIN;

std::string clave_random() {
    std::string key;
    int tam = 3 + (rand() % 5);
    key.resize(tam);
    for(int i = 0; i < tam; i++)
        key[i] = char((rand() % ASCII_RANGE) + ASCII_MIN);
    return key;
}

std::vector<char> set_clave(std::string pal) {
    std::vector<char> resultado;

    if(pal.length() > 256){
        std::cout << "\nLa clave introducida supera los 256 Bytes. Prueba una más corta.\n";
        return resultado;
    }

    for(int i = 0, j = 0; i < 256; i++, j++){
        if(pal[j%pal.length()] != ','){
            resultado[i] = char(pal[j%pal.length()] - ASCII_MIN);
        } else { 
            j++;
            resultado[i] = char(pal[j%pal.length()] - ASCII_MIN);
        }
    }
    return resultado;
}

std::vector<int> ksa(std::vector<char> t){
    std::vector<int> s;
    for(int i = 0; i < 256; i++){
        s[i] = i;
    }

}

int main(){
    int opcion = 0;
    bool clave_asignada = false;
    std::string clave = "";
    std::string palabra = "";

    // vector s y t
    std::vector<int> s(256);
    std::vector<char> t(256);

    do{
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Clave: " << clave << std::endl;
        std::cout << "Última palabra usada: " << palabra << std::endl;
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
                    t = set_clave(clave);
                    clave_asignada = true;
                    break;
            case 2:
                    clave = clave_random();
                    t = set_clave(clave);
                    clave_asignada = true;
                    break;
            case 3: if(clave_asignada){
                        std::cout << "Introduce la palabra que deseas codificar: ";
                        std::cin >> palabra;
                        std::cout << "Palabra cod.:  " << palabra << std::endl << std::endl;
                    }break;
            case 4: break;
            default: std::cout << "Introduce un número del 1 al 4.\n";
        }
        std::cout << std::endl;
    }while(opcion != 4);

    return 0;
}