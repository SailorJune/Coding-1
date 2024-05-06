#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0));
    
    string name = "June";
    std::cout << "Hello World!\n";

    int counter = 0;
    while(counter++ < 10) {
        cout << "counter = " << counter << ".\n";
    }
    
    string input = "";

    
    do {
        cout << "Do you want to keep adventuring? (yes/no)\n";
        getline(cin, input);
    } while(input != "no");

    while(true) {
        string response = "";
        cout << "Are we there yet??\n";
        getline(cin, response);
        
        if (response == "yes") {
            break;
        }

       
    } 
        for(int i = 0; i < 10; i += 1) {
            cout << i << "\n";
    }

    string names[10];

    names[0] = "Jinx";
    names[1] = "Vi";
    names[2] = "Caitlyn";
    names[3] = "Jayce";
    names[4] = "Echo";
    names[5] = "Viktor";
    names[6] = "Silco";

    cout << "One of my favorite characters in Arcane is " << names[rand () % 6] << ".\n";

    // Lets go on a "platonic" date with one of the characters?

    cout << "today we get to hang out with " << names[rand () % 6] << "!!!!\n";

    // create an array of strings named favGames
    // start a while true loop
    // ask play what do? They can..
        // add game
        // show all games
        // quit

    string favGames[10];
    int index = 0;
    while (true){
        cout << "what do you want to do?\n";
        string input;
        getline(cin, input);
    

        if (input == "add") {
            cout << "what game would you like to add?\n";
            getline(cin, input);
            favGames[index++] = input;
        }
        else if(input == "show") {
            for(int i = 0; i < 10; i += 1) {
                cout << favGames[i] << "\n";
            }
        }
        else if (input == "quit") {
            cout << "thanks for playing!\n";
            break;
        }
    }
   
}