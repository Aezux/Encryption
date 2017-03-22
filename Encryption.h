#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "KeyMap.cpp"
#include "FriendFunctions.cpp"
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

class Encryption {
    private:
        std::string Message;
        friend char wrap(int type, char value, int number);
        friend double power(double base, int exponent);
        friend std::string B10_TO_B21(char character);
        friend char B21_TO_B10(std::string Base21);
    public:
        Encryption();
        std::string encrypt(std::string msg = "");
        std::string decrypt(std::string msg = "");
};

Encryption :: Encryption(): Message("") { // Constructor
    ImplementMaps();
    srand(time(0));
}

std::string Encryption :: encrypt(std::string msg) {
    Message = msg;
    std::string Temp = "";
    std::vector<std::string> Space;
    int Split = 0;
    for (size_t i=0; i<Message.size(); i++) {
        for(int j=0; j<11; j++) {
            Temp += B10_TO_B21(random[rand() % 62]);
        }
        Temp += B10_TO_B21(Message[i]);
    }
    Message.clear();
    for (size_t i=0; i<Temp.size(); i++) {
        int TYPE = (Temp[i] >= '0' && Temp[i] <= '9') ? 1 : 2;
        switch(TYPE) {
            case 1: Temp[i] = wrap(1, Temp[i], KEY[i % 128]); break;
            case 2: Temp[i] = wrap(2, Temp[i], KEY[i % 128]); break;
            default: break;
        }
    }
    for (size_t i=0; i<Temp.size(); i++) {
        Message += Encrypt[Temp[i]];
    }
    Temp.clear();
    while (Split < Message.size()) {
        Space.push_back(Message.substr(Split,13));
        Split += 13;
    }
    for (size_t i=0; i<Space.size(); i++) {
        if (i != 0 && i%7 == 0) {
            Temp += "\n";
        }
        Temp += Space[i] + "   ";
    }
    return Message = Temp;
}

std::string Encryption :: decrypt(std::string msg) {
    Message = msg;
    size_t counter = 0;
    std::string Temp = "";
    for (size_t i=0; i<Message.size(); i++) {
        if(Message[i] == ' ') {
            Message.erase(i,3);
        }
        if(Message[i] == '\n') {
            Message.erase(i,1);
        }
    }
    for (size_t i=0; i<Message.size(); i+=5) {
        Temp += Decrypt[Message.substr(i,5)];
    }
    Message.clear();
    for (size_t i=0; i<Temp.size(); i++) {
        int TYPE = (Temp[i] >= '0' && Temp[i] <= '9') ? 1 : 2;
        switch(TYPE) {
            case 1: Message += wrap(1, Temp[i], -KEY[i % 128]); break;
            case 2: Message += wrap(2, Temp[i], -KEY[i % 128]); break;
            default: break;
        }
    }
    Temp.clear();
    while(Message.size() != 0) {
        Temp += Message.substr(0,24).erase(0,22);
        Message.erase(0,24);
    }
    while(counter < Temp.size()) {
        Message += B21_TO_B10(Temp.substr(counter,2));
        counter += 2;
    }
    return Message;
}

#endif
