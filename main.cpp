#include <iostream>
#include <string>
#include <cstdlib> 
#include <thread>  
#include <chrono>

using namespace std;


void clearScreen() {
   
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


void drawBar(string label, int value) {
    cout << label << ": [";
    int bars = value / 10; 
    
    for (int i = 0; i < 10; i++) {
        if (i < bars) cout << "#";
        else cout << "-";
    }
    cout << "] " << value << "%" << endl;
}


void drawPet(int mood) {
    cout << "\n";
    if (mood == 1) { // HAPPY
        cout << "      /\\_/\\  " << endl;
        cout << "     ( ^.^ )  < Meow!" << endl;
        cout << "      > ^ <  " << endl;
    } else if (mood == 2) { // SAD / HUNGRY
        cout << "      /\\_/\\  " << endl;
        cout << "     ( T_T )  < Feed me..." << endl;
        cout << "      > ^ <  " << endl;
    } else { // SLEEPY
        cout << "      /\\_/\\  " << endl;
        cout << "     ( -_- ) zZZ" << endl;
        cout << "      > ^ <  " << endl;
    }
    cout << "\n";
}

int main() {
    int hunger = 50;
    int happiness = 50;
    int energy = 50;
    int choice;
    bool running = true;

    while (running) {
        clearScreen(); 

        cout << "===========================" << endl;
        cout << "         VIRTUAL PET       " << endl;
        cout << "===========================" << endl;

        int currentMood = 1;
        if (energy < 30) currentMood = 3;
        else if (hunger < 30 || happiness < 30) currentMood = 2;

        drawPet(currentMood);

     
        drawBar("Hunger   ", hunger);
        drawBar("Happiness", happiness);
        drawBar("Energy   ", energy);

        cout << "===========================" << endl;
        
 
        if (hunger <= 0 || happiness <= 0 || energy <= 0) {
            cout << "\nYOUR PET RAN AWAY!" << endl;
            break;
        }

 
        cout << "1. Feed  2. Play  3. Sleep  4. Exit" << endl;
        cout << "Select: ";
        cin >> choice;

        if (choice == 1) { 
            hunger += 20; energy -= 5; 
            cout << "Eating..." << endl;
        }
        else if (choice == 2) { 
            happiness += 20; hunger -= 10; energy -= 10; 
            cout << "Playing..." << endl;
        }
        else if (choice == 3) { 
            energy += 20; hunger -= 10; 
            cout << "Sleeping..." << endl;
        }
        else if (choice == 4) { 
            running = false; 
        }

  
        std::this_thread::sleep_for(std::chrono::seconds(1));

       
        hunger -= 5;
        happiness -= 5;
        energy -= 5;

       
        if(hunger > 100) hunger = 100;
        if(happiness > 100) happiness = 100;
        if(energy > 100) energy = 100;
    }

    return 0;
}
