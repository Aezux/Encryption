#ifndef KEY_CPP
#define KEY_CPP

#include <map>
std::map<char, std::string> Encrypt;
std::map<std::string, char> Decrypt;
std::map<char, int> Numbers;
std::map<char, int> Letters;

const int KEY[127] = {
    4229, 4050, 3790, 3624, 3365,
    3048, 3137, 4982, 3629, 3647,
    3657, 4545, 4258, 4457, 4108,
    4897, 4168, 3747, 3326, 3009,
    3469, 3912, 4946, 4312, 3462,
    3761, 4266, 3218, 4194, 3267,
    4903, 3084, 3049, 3626, 4749,
    4600, 3890, 4001, 3033, 4569,
    3913, 3342, 4747, 3697, 3105,
    3402, 4132, 3118, 3528, 3599,
    4114, 3461, 4132, 4643, 3514,
    3516, 3644, 4295, 3603, 4560,
    3602, 3238, 3564, 3033, 3098,
    3435, 4533, 4175, 3915, 4810,
    3577, 4346, 4586, 4628, 4443,
    3762, 3022, 4252, 4080, 4931,
    4531, 3756, 4789, 4560, 3772,
    4825, 3648, 4607, 4048, 3448,
    3736, 4692, 3885, 4304, 3854,
    3908, 4495, 3238, 4488, 3724,
    3858, 3992, 3495, 4258, 4019,
    3375, 3331, 4315, 3205, 4123,
    3662, 4536, 4781, 3176, 4669,
    4198, 3697, 3156, 3459, 3022,
    4489, 3895, 4481, 4445, 4233,
    3799, 3692
};

char CharNumbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
char CharLetters[52] = {'A','B','C','D','E','F','G','H','I','J',
                        'K','L','M','N','O','P','Q','R','S','T',
                        'U','V','W','X','Y','Z','a','b','c','d',
                        'e','f','g','h','i','j','k','l','m','n',
                        'o','p','q','r','s','t','u','v','w','x',
                        'y','z'};
char random[62] =      {'0','1','2','3','4','5','6','7','8','9',
                        'A','B','C','D','E','F','G','H','I','J',
                        'K','L','M','N','O','P','Q','R','S','T',
                        'U','V','W','X','Y','Z','a','b','c','d',
                        'e','f','g','h','i','j','k','l','m','n',
                        'o','p','q','r','s','t','u','v','w','x',
                        'y','z'};
void EnMap() {
    Encrypt['0'] = ".:;,`"; Encrypt['1'] = ".,`:;"; Encrypt['2'] = ":;`.,"; Encrypt['3'] = ":`;.,";
    Encrypt['4'] = ".:;`,"; Encrypt['5'] = ".,`;:"; Encrypt['6'] = ":;.,`"; Encrypt['7'] = ":`;,.";
    Encrypt['8'] = ".:,;`"; Encrypt['9'] = ".`:,;"; Encrypt['A'] = ":;.`,"; Encrypt['B'] = ";.,`:";
    Encrypt['C'] = ".:,`;"; Encrypt['D'] = ".`:;,"; Encrypt['E'] = ":;,.`"; Encrypt['F'] = ";.,:`";
    Encrypt['G'] = ".:`;,"; Encrypt['H'] = ".`;,:"; Encrypt['I'] = ":;,`."; Encrypt['J'] = ";.`,:";
    Encrypt['K'] = ".:`,;"; Encrypt['L'] = ".`;:,"; Encrypt['M'] = ":,`.;"; Encrypt['N'] = ";.`:,";
    Encrypt['O'] = ".;:`,"; Encrypt['P'] = ".`,;:"; Encrypt['Q'] = ":,`;."; Encrypt['R'] = ";.:,`";
    Encrypt['S'] = ".;:,`"; Encrypt['T'] = ".`,:;"; Encrypt['U'] = ":,.`;"; Encrypt['V'] = ";.:`,";
    Encrypt['W'] = ".;,`:"; Encrypt['X'] = ":.`;,"; Encrypt['Y'] = ":,.;`"; Encrypt['Z'] = ";:,.`";
    Encrypt['a'] = ".;,:`"; Encrypt['b'] = ":.`,;"; Encrypt['c'] = ":,;`."; Encrypt['d'] = ";:,`.";
    Encrypt['e'] = ".;`,:"; Encrypt['f'] = ":.;`,"; Encrypt['g'] = ":,;.`"; Encrypt['h'] = ";:`.,";
    Encrypt['i'] = ".;`:,"; Encrypt['j'] = ":.;,`"; Encrypt['k'] = ":`,;."; Encrypt['l'] = ";:`,.";
    Encrypt['m'] = ".,:;`"; Encrypt['n'] = ":.,`;"; Encrypt['o'] = ":`,.;"; Encrypt['p'] = ";:.`,";
    Encrypt['q'] = ".,:`;"; Encrypt['r'] = ":.,`;"; Encrypt['s'] = ":`.;,"; Encrypt['t'] = ";:.,`";
    Encrypt['u'] = ".,;:`"; Encrypt['v'] = ":.,;`"; Encrypt['w'] = ":`.,;"; Encrypt['x'] = ";,:`.";
    Encrypt['y'] = ".,;`:"; Encrypt['z'] = ":;`,.";
}

void DeMap() {
    Decrypt[".:;,`"] = '0'; Decrypt[".,`:;"] = '1'; Decrypt[":;`.,"] = '2'; Decrypt[":`;.,"] = '3';
    Decrypt[".:;`,"] = '4'; Decrypt[".,`;:"] = '5'; Decrypt[":;.,`"] = '6'; Decrypt[":`;,."] = '7';
    Decrypt[".:,;`"] = '8'; Decrypt[".`:,;"] = '9'; Decrypt[":;.`,"] = 'A'; Decrypt[";.,`:"] = 'B';
    Decrypt[".:,`;"] = 'C'; Decrypt[".`:;,"] = 'D'; Decrypt[":;,.`"] = 'E'; Decrypt[";.,:`"] = 'F';
    Decrypt[".:`;,"] = 'G'; Decrypt[".`;,:"] = 'H'; Decrypt[":;,`."] = 'I'; Decrypt[";.`,:"] = 'J';
    Decrypt[".:`,;"] = 'K'; Decrypt[".`;:,"] = 'L'; Decrypt[":,`.;"] = 'M'; Decrypt[";.`:,"] = 'N';
    Decrypt[".;:`,"] = 'O'; Decrypt[".`,;:"] = 'P'; Decrypt[":,`;."] = 'Q'; Decrypt[";.:,`"] = 'R';
    Decrypt[".;:,`"] = 'S'; Decrypt[".`,:;"] = 'T'; Decrypt[":,.`;"] = 'U'; Decrypt[";.:`,"] = 'V';
    Decrypt[".;,`:"] = 'W'; Decrypt[":.`;,"] = 'X'; Decrypt[":,.;`"] = 'Y'; Decrypt[";:,.`"] = 'Z';
    Decrypt[".;,:`"] = 'a'; Decrypt[":.`,;"] = 'b'; Decrypt[":,;`."] = 'c'; Decrypt[";:,`."] = 'd';
    Decrypt[".;`,:"] = 'e'; Decrypt[":.;`,"] = 'f'; Decrypt[":,;.`"] = 'g'; Decrypt[";:`.,"] = 'h';
    Decrypt[".;`:,"] = 'i'; Decrypt[":.;,`"] = 'j'; Decrypt[":`,;."] = 'k'; Decrypt[";:`,."] = 'l';
    Decrypt[".,:;`"] = 'm'; Decrypt[":.,`;"] = 'n'; Decrypt[":`,.;"] = 'o'; Decrypt[";:.`,"] = 'p';
    Decrypt[".,:`;"] = 'q'; Decrypt[":.,`;"] = 'r'; Decrypt[":`.;,"] = 's'; Decrypt[";:.,`"] = 't';
    Decrypt[".,;:`"] = 'u'; Decrypt[":.,;`"] = 'v'; Decrypt[":`.,;"] = 'w'; Decrypt[";,:`."] = 'x';
    Decrypt[".,;`:"] = 'y'; Decrypt[":;`,."] = 'z';
}

void NumCheck() {
    Numbers['0'] = 0; Numbers['1'] = 1; Numbers['2'] = 2;
    Numbers['3'] = 3; Numbers['4'] = 4; Numbers['5'] = 5;
    Numbers['6'] = 6; Numbers['7'] = 7; Numbers['8'] = 8;
    Numbers['9'] = 9;
}

void CharCheck() {
    Letters['A'] = 0;  Letters['B'] = 1;  Letters['C'] = 2;
    Letters['D'] = 3;  Letters['E'] = 4;  Letters['F'] = 5;
    Letters['G'] = 6;  Letters['H'] = 7;  Letters['I'] = 8;
    Letters['J'] = 9;  Letters['K'] = 10; Letters['L'] = 11;
    Letters['M'] = 12; Letters['N'] = 13; Letters['O'] = 14;
    Letters['P'] = 15; Letters['Q'] = 16; Letters['R'] = 17;
    Letters['S'] = 18; Letters['T'] = 19; Letters['U'] = 20;
    Letters['V'] = 21; Letters['W'] = 22; Letters['X'] = 23;
    Letters['Y'] = 24; Letters['Z'] = 25; Letters['a'] = 26;
    Letters['b'] = 27; Letters['c'] = 28; Letters['d'] = 29;
    Letters['e'] = 30; Letters['f'] = 31; Letters['g'] = 32;
    Letters['h'] = 33; Letters['i'] = 34; Letters['j'] = 35;
    Letters['k'] = 36; Letters['l'] = 37; Letters['m'] = 38;
    Letters['n'] = 39; Letters['o'] = 40; Letters['p'] = 41;
    Letters['q'] = 42; Letters['r'] = 43; Letters['s'] = 44;
    Letters['t'] = 45; Letters['u'] = 46; Letters['v'] = 47;
    Letters['w'] = 48; Letters['x'] = 49; Letters['y'] = 50;
    Letters['z'] = 51;
}

void ImplementMaps(){
    EnMap();
    DeMap();
    NumCheck();
    CharCheck();
}

#endif
