#include <iostream>
#include <fstream>
#include "Encryption.h"

std::string Readfile() {
    /*This function reads in a file*/
    std::ifstream infile; // ifstream variable
    std::string File_Name, Message, STRING; // String variables
    std::cout << "Enter the name of the file: "; // Lets the user know to enter the name of the file
    std::cin.ignore(); // Ignores the last cin call
    getline(std::cin, File_Name); // User enters the name of the file
    infile.open(File_Name.c_str()); // Opens the file
    while (!infile) { // If the file does not exist
        infile.close(); // Close the file
        infile.clear(); // Clear the file
        std::cout << "\nThat file you entered does not exist, please enter another one: "; // Tells the user to re-enter the file name
        getline(std::cin, File_Name); // User re-enters the file name
        infile.open(File_Name.c_str()); // Tries to open the new file
    }
    infile >> std::ws; // Checks for whitespace
    while (!infile.eof()) { // Makes sure the file has not reached the end
        getline(infile, STRING); // Gets a line from the file
        Message += STRING; // Adds that line to a new string variable
        if (!infile.eof()) { // Makes sure the file has not reached the end of the file
            Message.push_back('\n'); // Enter a newline after each string line except for the last one
        }
    }
    infile.close(); // Closes the file
    return Message; // Returns all the contants of the file in string form
}
void insertfile(std::string Message) {
    /*This function returns a string into a file*/
    std::ofstream outfile; // ofstream variable
    std::string File_Name; // string variable
    std::cout << "Enter the file name you want to export this to: "; // Asks the user to enter the name of the file
    getline(std::cin, File_Name); // Gets name of the file from the user
    outfile.open(File_Name.c_str()); // Creates that file
    outfile << Message; // Puts the string into that file
    outfile.close(); // Closes the file
}

int main() {
    Encryption Cipher;
    std::string Encrypted, Decrypted; // String variables
    bool loop = true; // Boolian variable
    int option; // int variable
    while (loop == true) { // Runs the loop only when it is true
        std::cout << "1. Encrypt\n2. Decrypt\n3. Exit\nWhat do you want to do?: "; // Displays a menu for the user
        std::cin >> option; // User enters what they want to do
        switch (option) { // decides what to do based on what the user entered
            case 1:
            /*Encrypts the file*/
                Encrypted = Readfile();
                insertfile(Cipher.encrypt(Encrypted));
            break;
            case 2:
            /*Decrypts the file*/
                Decrypted = Readfile();
                insertfile(Cipher.decrypt(Decrypted));
            break;
            default:
            /*Exits out if user enters 3 or anything else besides 1 or 2*/
                loop = false;
            break;
        }
    }
    return 0; // Return 0 for main()
}
