#include <cmath> // Para elevar numeros
#include <iostream>
#include "calc.hpp"


float datacalc::converter(const float &pre_input, int &pre_option, int &post_option) {
    /* Para Trabajar con Bits y Bytes debes saber lo siguiente 
    1. para pasar de bit a byte se divide entre 8, en caso contrario se multiplica
    2. Si vas a trabajar con valores como Kilobyte o Kilobit (es decir, comerciales), se usa 10^3 (1.000).
    3. Si por otro lado vas a usar valores binarios como Kibibit o Kibibyte, se usa 2^10 (1.024).*/
    // 11 (Minuendo) - 3 (sustraendo) = 8 (diferencia)
    static int diferencia;

    if(pre_input == 0.0f) {
        return 0;
    }

    if (pre_option == post_option) {
        return pre_input;
    }

    else if (pre_option == 0 && post_option == 9 || pre_option == 9 && post_option == 0) {
        if (pre_option > post_option) {
            return pre_input * 8.0f;
        }
        else if (pre_option < post_option) {
            return pre_input / 8.0f;
        }
    }

    else if (pre_option < 9 && post_option < 9) {
        if (pre_option < post_option) {
            diferencia = post_option - pre_option;
            return (pre_input / pow(pow(2, 10), diferencia));
        }
        else if (pre_option > post_option) {
            diferencia = pre_option - post_option;
            return (pre_input * pow(pow(2, 10), diferencia));
        }
        return diferencia;
    }

    else if (pre_option > 8 && post_option > 8) {
        if (pre_option < post_option) {
            diferencia = post_option - pre_option;
            return pre_input / (pow(pow(2, 10), diferencia));
        }
        else if (pre_option > post_option) {
            diferencia = pre_option - post_option;
            return pre_input * (pow(pow(2, 10), diferencia));
        }
        return diferencia;
    }

    else if (pre_option > 8 && post_option < 9 || pre_option < 9 && post_option > 8) {
        float aux;
        if (pre_option < post_option) {
            aux = (pre_input * (pow(pow(2, 10), pre_option))) / 8;
            diferencia = post_option - 9;
            if (diferencia >= 1) {
                return aux / (pow(pow(2, 10), diferencia));
            }
            else if (diferencia == 0) {
                return aux;
            }
        }
        else if (pre_option > post_option) { // Not Working correctly
            std::cout << pre_option << "-" << post_option;
            diferencia = pre_option - 9;
            aux = (pre_input * (pow(pow(2, 10), diferencia)) * 8);
            std::cout << "Pre_Diferencia" << diferencia << std::endl;
            diferencia = post_option;
            std::cout << "Post_Diferencia" << diferencia << std::endl;
            if (diferencia >= 1) {
                std::cout << "Toy hecho un fucker" << std::endl;
                return aux / (pow(pow(2, 10), diferencia));
            }
            else if (diferencia == 0.0f || diferencia >= 0.9f) {
                std::cout << "Pitorrillo laser" << std::endl;
                return aux;
            }
        }
    }

    else if (pre_option > 17 | post_option > 17) {return -8.0f;} // Easter Egg inalcanzable

    return -1.0f; // No deberias poder llegar aqui
}
