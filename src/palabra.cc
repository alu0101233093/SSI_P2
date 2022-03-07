#include "../include/palabra.h"

palabra::palabra(std::string p){
     set_palabra(p);
}

int 
palabra::get_longitud(){
     return longitud_;
}

std::string 
palabra::get_palabra(){
     return p_;
}

std::vector<int> 
palabra::get_ascii(){
     return palabra_int_;
}

std::bitset<8> 
palabra::get_binario(int i){
     return palabra_bin_[i];
}

void 
palabra::set_binario(std::vector<std::bitset<8>> bits) {
     p_.resize(bits.size());
     palabra_bin_.resize(bits.size());
     palabra_int_.resize(bits.size());

     for(int i = 0; i < int(bits.size()); i++){
          palabra_bin_[i] = bits[i];
          palabra_int_[i] = 0;
          for(int j = 0; j < 8; j++)
               palabra_int_[i] += (bits[i][j]*pow(2,j));
          p_[i] = char(palabra_int_[i] + ASCII_MIN);
     }
}

void 
palabra::set_palabra(std::string p) {
     p_ = p;
     longitud_ = p.length();

     palabra_int_.resize(longitud_);
     palabra_bin_.resize(longitud_);
     for(int i = 0; i < longitud_; i++){
          palabra_int_[i] = char(p[i] - ASCII_MIN);
          palabra_bin_[i] = palabra_int_[i];
     }
}

palabra 
palabra::suma(palabra p){
     std::vector<std::bitset<8>> b;

     for(int i = 0, j = 0; i < int(p.get_longitud()); i++, j++){
          if(j >= longitud_) j = 0;
          b.push_back(p.get_binario(i) ^ palabra_bin_[j]);
     }

     p.set_binario(b);
     return p;
}
