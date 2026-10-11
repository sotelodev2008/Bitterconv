#include <cmath>     // Para elevar numeros (pow)
#include "calc.hpp"


float datacalc::converter(const float &pre_input, int &pre_option, int &post_option) {
    /* Para Trabajar con Bits y Bytes debes saber lo siguiente
    1. para pasar de bit a byte se divide entre 8, en caso contrario se multiplica
    2. Si vas a trabajar con valores como Kilobyte o Kilobit (es decir, comerciales), se usa 10^3 (1.000).
    3. Si por otro lado vas a usar valores binarios como Kibibit o Kibibyte, se usa 2^10 (1.024).*/
    // 11 (Minuendo) - 3 (sustraendo) = 8 (diferencia)
    static int diferencia;

    if (pre_input == 0.0f) {
        return 0;
    }

    if (pre_option == post_option) {
        return pre_input;
    }

    // Bit <-> Byte (misma magnitud)
    else if (pre_option == 0 && post_option == 9 || pre_option == 9 && post_option == 0) {
        if (pre_option > post_option) {
            return pre_input * 8.0f;
        }
        else {
            return pre_input / 8.0f;
        }
    }

    // FAMILIA BINARIA (indices 0..17)
    // Bit binario <-> Bit binario
    else if (pre_option < 9 && post_option < 9) {
        if (pre_option < post_option) {
            diferencia = post_option - pre_option;
            return (pre_input / pow(pow(2, 10), diferencia));
        }
        else {
            diferencia = pre_option - post_option;
            return (pre_input * pow(pow(2, 10), diferencia));
        }
    }

    // Byte binario <-> Byte binario
    else if (pre_option > 8 && pre_option < 18 && post_option > 8 && post_option < 18) {
        if (pre_option < post_option) {
            diferencia = post_option - pre_option;
            return (pre_input / pow(pow(2, 10), diferencia));
        }
        else {
            diferencia = pre_option - post_option;
            return (pre_input * pow(pow(2, 10), diferencia));
        }
    }

    // Bit binario <-> Byte binario
    else if (pre_option < 9 && post_option > 8 && post_option < 18
          || pre_option > 8 && pre_option < 18 && post_option < 9) {
        float aux;
        if (pre_option < post_option) {          // bit -> byte
            aux = (pre_input * pow(pow(2, 10), pre_option)) / 8.0f;
            diferencia = post_option - 9;
            if (diferencia >= 1) {
                return aux / pow(pow(2, 10), diferencia);
            }
            else {
                return aux;
            }
        }
        else { // byte -> bit
            diferencia = pre_option - 9;
            aux = (pre_input * pow(pow(2, 10), diferencia)) * 8.0f;
            diferencia = post_option;
            if (diferencia >= 1) {
                return aux / pow(pow(2, 10), diferencia);
            }
            else {
                return aux;
            }
        }
    }

    // FAMILIA COMERCIAL (indices 18..33)
    // Cualquier caso con al menos una unidad comercial: normalizo a bits y desnormalizo.
    // OJO: la familia comercial no tiene Bit/Byte base, arranca en Kilo,
    // por eso el exponente es (opcion - 17) para bits y (opcion - 25) para bytes.
    else if (pre_option > 17 || post_option > 17) {
        float en_bits;
        if (pre_option < 9) {                                   // bit binario
            en_bits = pre_input * pow(pow(2, 10), pre_option);
        }
        else if (pre_option < 18) {                             // byte binario
            en_bits = pre_input * pow(pow(2, 10), pre_option - 9) * 8.0f;
        }
        else if (pre_option < 26) {                             // bit comercial
            en_bits = pre_input * pow(pow(10, 3), pre_option - 17);
        }
        else {                                                  // byte comercial
            en_bits = pre_input * pow(pow(10, 3), pre_option - 25) * 8.0f;
        }

        if (post_option < 9) {                                  // bit binario
            return en_bits / pow(pow(2, 10), post_option);
        }
        else if (post_option < 18) {                            // byte binario
            return en_bits / (pow(pow(2, 10), post_option - 9) * 8.0f);
        }
        else if (post_option < 26) {                            // bit comercial
            return en_bits / pow(pow(10, 3), post_option - 17);
        }
        else {                                                  // byte comercial
            return en_bits / (pow(pow(10, 3), post_option - 25) * 8.0f);
        }
    }

    return -1.0f; // No deberias poder llegar aqui
}
