#include <iostream>
#include <string>
#include <list>

using namespace std;

class Pet {
public:
    string name;
    bool adopted;
    int hungerLevel;
    int happinessLevel;

    Pet() : Pet("") {}

    Pet(string petName) : name{petName}, adopted{false}, hungerLevel{50}, happinessLevel{50}  {}

    void adopt(string petName) {
        name = petName;
        adopted = true;
    }

    bool isAdopted(void) {
        return adopted;
    }

    void feed() {
        if (hungerLevel < 90) {
            hungerLevel += 10;
            cout << "You fed " << name << ". Its hunger level is now " << hungerLevel << "." << endl;
        } else {
            cout << name << " is full and doesn't want to eat anymore." << endl;
        }
    }

    void play() {
        if (happinessLevel < 90) {
            happinessLevel += 10;
            cout << "You played with " << name << ". Its happiness level is now " << happinessLevel << "." << endl;
        } else {
            cout << name << " is too happy and doesn't want to play anymore." << endl;
        }
    }

    void checkStatus() {
        cout << "Hunger level: " << hungerLevel << endl;
        cout << "Happiness level: " << happinessLevel << endl;
    }

    bool isGameOver() {
        return (hungerLevel >= 90 && happinessLevel >= 90);
    }
};

void display_list(void)
{
    cout << "\n1. Adopt Pet\n"
        << "2. Feed Pet\n"
        << "3. Play with Pet\n"
        << "4. Check Status\n"
        << "5. End game\n"
        << "Choose an option: ";
}


int main() {
    Pet myPet{};
    string name{};
    int choice;

    while (!myPet.isGameOver()) 
    {
        display_list();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nGive your pet a name: ";
                cin >> name;
                myPet.adopt(name);
                break;
            case 2:
                if (myPet.isAdopted())                
                    myPet.feed();
                else
                    cout << "No pet is adopted" << endl;
                break;
            case 3:
                if (myPet.isAdopted())                
                    myPet.play();
                else
                    cout << "No pet is adopted" << endl;
                break;
            case 4:
                if (myPet.isAdopted())                
                    myPet.checkStatus();
                else
                    cout << "No pet is adopted" << endl;
                
                break;
            case 5:
                cout << "Game over! Final status of " << myPet.name << ":" << endl;
                myPet.checkStatus();
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        if (myPet.isGameOver()) {
            cout << "Oh yeaa! " << myPet.name << " is happy and well-fed. The game is over." << endl;
            myPet.checkStatus();
        }
    }

    return 0;
}