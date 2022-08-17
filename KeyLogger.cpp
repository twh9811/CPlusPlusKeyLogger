#include <windows.h>
#include <iostream>
#include <fstream>

#define FILE_NAME "logged.txt"

void fileData(std::string data) {
    std::fstream log_file;
    //Create the file. If the file exists, append to it instead of erasing.
    log_file.open(FILE_NAME, std::ios::app);
    //put keystrokes into text file
    log_file << data;
    //Close the file
    log_file.close()
}

std::string specialKey(int keyPressed) {
    //Space
    //Enter
    //Tab
    //Caps Lock
    //Back Space
    //Shift
    //Control
    //Alt
    return "ah";
}

int main() {
    //Loop through each key using ASCII values.
    //Check if the key is pressed
    //If its a special key, translate it
    return 1;
}