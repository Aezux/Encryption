#ifndef FRIENDFUNCTIONS_CPP
#define FRIENDFUNCTIONS_CPP

char wrap(int type, char value, int number) {
    int Starting_Position, New_Position;
    int size = 0;
    bool negative = false;
    switch (type) {
        case 1: Starting_Position = Numbers[value]; size = 10; break;
        case 2: Starting_Position = Letters[value]; size = 52; break;
        default:break;
    }
    number += Starting_Position;
    if (number < 0) {
        negative = true;
        number = -number;
    }
    int index = number % size;
    New_Position = (negative) ? size - index : index;
    return (type == 1) ? CharNumbers[New_Position] : CharLetters[New_Position];
}

double power(double base, int exponent) {
    double answer = 1;
    if (exponent == 0) return answer;
    else{
        int absExponent = (exponent > 0) ? exponent : (-1) * exponent;
        for (short i = 0; i<absExponent; i++) {
            answer *= base;
        }
        if (exponent < 0) answer = 1.0 / answer;
    }
    return answer;
}

std::string B10_TO_B21(char character) {
    signed short ascii = int(character), position = 0;
    int container[2];
    std::string Base21 = "";
    if (ascii < 21) {
        switch (ascii) {
            case  0: Base21 += "00"; break;
            case  1: Base21 += "01"; break;
            case  2: Base21 += "02"; break;
            case  3: Base21 += "03"; break;
            case  4: Base21 += "04"; break;
            case  5: Base21 += "05"; break;
            case  6: Base21 += "06"; break;
            case  7: Base21 += "07"; break;
            case  8: Base21 += "08"; break;
            case  9: Base21 += "09"; break;
            case 10: Base21 += "0A"; break;
            case 11: Base21 += "0B"; break;
            case 12: Base21 += "0C"; break;
            case 13: Base21 += "0D"; break;
            case 14: Base21 += "0E"; break;
            case 15: Base21 += "0F"; break;
            case 16: Base21 += "0G"; break;
            case 17: Base21 += "0H"; break;
            case 18: Base21 += "0I"; break;
            case 19: Base21 += "0J"; break;
            case 20: Base21 += "0K"; break;
        }
    }
    else {
        while (ascii != 0) {
            container[position] = ascii % 21;
            position++;
            ascii /= 21;
        }
        for (int i=position-1; i>=0; i--) {
            switch (container[i]) {
                case  0: Base21 += "0"; break;
                case  1: Base21 += "1"; break;
                case  2: Base21 += "2"; break;
                case  3: Base21 += "3"; break;
                case  4: Base21 += "4"; break;
                case  5: Base21 += "5"; break;
                case  6: Base21 += "6"; break;
                case  7: Base21 += "7"; break;
                case  8: Base21 += "8"; break;
                case  9: Base21 += "9"; break;
                case 10: Base21 += "A"; break;
                case 11: Base21 += "B"; break;
                case 12: Base21 += "C"; break;
                case 13: Base21 += "D"; break;
                case 14: Base21 += "E"; break;
                case 15: Base21 += "F"; break;
                case 16: Base21 += "G"; break;
                case 17: Base21 += "H"; break;
                case 18: Base21 += "I"; break;
                case 19: Base21 += "J"; break;
                case 20: Base21 += "K"; break;
            }
        }
    }
    return Base21;
}

char B21_TO_B10(std::string Base21) {
    signed short container[2], ascii = 0, count = 0, count2 = 0;
    for(size_t i=0; i<Base21.size(); i++) {
        char temp = Base21[i];
        switch(temp) {
            case '0': container[count] =  0; break;
            case '1': container[count] =  1; break;
            case '2': container[count] =  2; break;
            case '3': container[count] =  3; break;
            case '4': container[count] =  4; break;
            case '5': container[count] =  5; break;
            case '6': container[count] =  6; break;
            case '7': container[count] =  7; break;
            case '8': container[count] =  8; break;
            case '9': container[count] =  9; break;
            case 'A': container[count] = 10; break;
            case 'B': container[count] = 11; break;
            case 'C': container[count] = 12; break;
            case 'D': container[count] = 13; break;
            case 'E': container[count] = 14; break;
            case 'F': container[count] = 15; break;
            case 'G': container[count] = 16; break;
            case 'H': container[count] = 17; break;
            case 'I': container[count] = 18; break;
            case 'J': container[count] = 19; break;
            case 'K': container[count] = 20; break;
        }
        count++;
    }
    for (int i=Base21.size()-1; i>=0; i--) {
        ascii += container[count2] * (power(21,i));
        count2++;
    }
    return char(ascii);
}

#endif
