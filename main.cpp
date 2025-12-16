#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string petName;
    int hunger = 50;   
    int happiness = 50; 
    int energy = 50;    
    int choice;
    bool gameRunning = true;

    cout << "-----------------------------" << endl;
    cout << "   VIRTUAL PET ADOPTION      " << endl;
    cout << "-----------------------------" << endl;
    cout << "Please name your new pet: ";
    cin >> petName;

   
    while (gameRunning) {
        
       
        cout << "\n-----------------------------" << endl;
        
        
        if (hunger < 20 || happiness < 20) {
            cout << "   ( T_T )  <-- " << petName << " is sad/hungry!" << endl;
        } else if (energy < 20) {
            cout << "   ( -_- )  <-- " << petName << " is sleepy..." << endl;
        } else {
            cout << "   ( ^_^ )  <-- " << petName << " is happy!" << endl;
        }

        cout << "Stats:" << endl;
        cout << "Hunger:    " << hunger << "/100" << endl;
        cout << "Happiness: " << happiness << "/100" << endl;
        cout << "Energy:    " << energy << "/100" << endl;

       
        if (hunger <= 0 || happiness <= 0 || energy <= 0) {
            cout << "\nOH NO! " << petName << " has run away due to neglect!" << endl;
            cout << "GAME OVER." << endl;
            break; 
        }

        
        cout << "\nWhat do you want to do?" << endl;
        cout << "1. Feed " << petName << " (Increases Hunger)" << endl;
        cout << "2. Play with " << petName << " (Increases Happiness, Tiring)" << endl;
        cout << "3. Put " << petName << " to bed (Restores Energy)" << endl;
        cout << "4. Quit Game" << endl;
        cout << "Choice: ";
        cin >> choice;

        
        if (choice == 1) { 
            cout << "You fed " << petName << ". Yummy!" << endl;
            hunger += 20;
            energy -= 5; 
        } 
        else if (choice == 2) { 
            cout << "You played fetch with " << petName << "!" << endl;
            happiness += 20;
            hunger -= 10; 
            energy -= 10; 
        } 
        else if (choice == 3) { 
            cout << "Shhh... " << petName << " is sleeping." << endl;
            energy += 20;
            hunger -= 10; 
            happiness -= 5; 
        } 
        else if (choice == 4) { 
            cout << "Goodbye! " << petName << " will miss you." << endl;
            gameRunning = false;
        } 
        else {
            cout << "Invalid choice." << endl;
        }

 
        hunger -= 5;
        happiness -= 5;
        energy -= 5;

        if (hunger > 100) hunger = 100;
        if (happiness > 100) happiness = 100;
        if (energy > 100) energy = 100;
    }

    return 0;
}
