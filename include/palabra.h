#include <bitset>
#include <iostream>
#include <vector>
#include <cmath>

const int ASCII_MAX = 90;
const int ASCII_MIN = 65;
const int ASCII_RANGE = ASCII_MAX - ASCII_MIN;

class palabra {
    private:
        std::string p_;
        int longitud_;
        std::vector<int> palabra_int_;
        std::vector<std::bitset<8>> palabra_bin_;
    public:
        palabra(std::string);
        int get_longitud();
        std::string get_palabra();
        std::vector<int> get_ascii();
        std::bitset<8> get_binario(int);

        void set_binario(std::vector<std::bitset<8>>);
        void set_palabra(std::string);

        palabra suma(palabra);
};