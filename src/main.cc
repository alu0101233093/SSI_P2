#include <bitset>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

const int ASCII_MAX = 57;
const int ASCII_MIN = 48;
const int ASCII_RANGE = ASCII_MAX - ASCII_MIN;

std::string clave_random() {
    std::string key;
    int tam = 1 + (rand() % 3);
    key.resize(tam);
    for(int i = 0; i < tam; i++)
        key[i] = char((rand() % ASCII_RANGE) + ASCII_MIN);
    return key;
}

std::vector<int> set_clave(std::string pal) {
    std::vector<int> resultado;
    std::vector<int> pal_int_array;
    std::stringstream stream(pal);
    std::string aux_string;

    if(pal.length() > 256){
        std::cout << "\nLa clave introducida supera los 256 Bytes. Prueba una más corta.\n";
        return resultado;
    }

    while (std::getline(stream, aux_string, ',')){
        pal_int_array.push_back(std::stoi(aux_string));
    }
    

    for(int i = 0, exponente = 0; i < 256; i++, exponente++){
        resultado.push_back(pal_int_array[i%pal_int_array.size()]);
    }
    return resultado;
}

std::vector<int> ksa(std::vector<int> t){
    std::vector<int> s(256);
    int aux = 0;
    int j = 0;
    
    for(int i = 0; i < 256; i++){
        s[i] = i;
    }

    for(int i = 0; i < 256; i++){
        j = (j + s[i] + int(t[i])) % 256;
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }

    return s;
}

std::vector<std::bitset<8>> prga(std::vector<int> s, int L){
    std::vector<std::bitset<8>> key_stream(L);
    int i = 0, j = 0, k = 0, aux = 0;

    while(k<L){
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
        key_stream[k] = s[(s[i] + s[j]) % 256];
        k++;
    }

    return key_stream;
}

int main(){
    int opcion = 0;
    bool clave_asignada = false;
    std::string clave = "";
    std::string palabra = "";

    // vector s y t
    std::vector<int> s(256);
    std::vector<int> t(256);
    std::vector<std::bitset<8>> key_stream;
    std::vector<std::bitset<8>> palabra_bits;

    do{
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Clave: " << clave << std::endl;
        std::cout << "Última palabra usada: " << palabra << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Introduce el número de la opción deseada: \n";
        std::cout << "1. Asignar clave \n";
        std::cout << "2. Asignar clave aleatoria \n";
        std::cout << "3. Codificar \n";
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
                    for(int i = 0; i < ((rand() % 5) + 1); i++)
                        clave += "," + clave_random();
                    t = set_clave(clave);
                    clave_asignada = true;
                    break;
            case 3: if(clave_asignada){
                        s = ksa(t);
                        std::cout << "Introduce la palabra que deseas codificar: ";
                        std::cin >> palabra;
                        
                        // Pasar de caracteres a bit
                        std::stringstream stream(palabra);
                        std::string aux_string;
                        while (std::getline(stream, aux_string, ',')){
                            palabra_bits.push_back(std::stoi(aux_string));
                        }
                        key_stream = prga(s,palabra_bits.size());
                        std::cout << std::endl;
                        
                        // Imprimir cadena cifrante
                        std::cout << "Cadena cifrante:    ";
                        for(int i = 0; i < int(key_stream.size()); i++)
                            std::cout << key_stream[i] << " ";
                        std::cout << std::endl;

                        // Imprimir palabra
                        std::cout << "Palabra original:   ";
                        for(int i = 0; i < int(palabra_bits.size()); i++)
                            std::cout << palabra_bits[i] << " ";
                        std::cout << std::endl;

                        // Imprimir palabra codificada
                        std::cout << "Palabra codificada: ";
                        for(int i = 0; i < int(key_stream.size()); i++)
                            std::cout << (key_stream[i] ^ palabra_bits[i]) << " ";
                        std::cout << std::endl;
                    }break;
            case 4: break;
            default: std::cout << "Introduce un número del 1 al 4.\n";
        }
        std::cout << std::endl;
    }while(opcion != 4);

    return 0;
}