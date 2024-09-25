#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
#include <string>
#include <vector>
#include <algorithm> // For std::max

// Function prototypes
void displayMenu();
void startGame();
void showHelp();
void showHighScore();
void exitGame();
int generateQuestion(int difficulty);

int highScore = 0;  // Global variable to track the high score

int main() {
    std::srand(std::time(0));  // Seed random number generator with current time
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                startGame();
                break;
            case 2:
                showHelp();
                break;
            case 3:
                showHighScore();
                break;
            case 4:
                exitGame();
                break;
            default:
                std::cout << "Invalid option. Please select a valid choice.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    std::cout << "\n==== Multiplication Learning Game ====\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. Help\n";
    std::cout << "3. Show High Score\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void startGame() {
    std::string playerName;
    std::cout << "\nEnter your name: ";
    std::cin >> playerName;

    int score = 0;
    int difficulty = 1;
    int correctStreak = 0;
    int wrongStreak = 0;

    for (int i = 0; i < 20; ++i) {
        int answer = generateQuestion(difficulty);
        int userAnswer;
        std::cin >> userAnswer;

        if (userAnswer == answer) {
            std::cout << "Correct!\n";
            score += difficulty * 10;
            correctStreak++;
            wrongStreak = 0;

            if (correctStreak == 3) {
                difficulty++;
                correctStreak = 0;
                std::cout << "Difficulty increased to level " << difficulty << "!\n";
            }
        } else {
            std::cout << "Incorrect. The correct answer was " << answer << ".\n";
            wrongStreak++;
            correctStreak = 0;

            if (wrongStreak == 3) {
                std::cout << "Game Over! You answered 3 questions incorrectly in a row.\n";
                break;
            }
        }
    }

    highScore = std::max(highScore, score);  // Update high score if the current score is higher
    std::cout << "Your final score is: " << score << "\n";
    std::cout << "The highest score so far is: " << highScore << "\n";
}

void showHelp() {
    std::cout << "\n=== Help ===\n";
    std::cout << "1. Start Game: Answer multiplication questions to earn points.\n";
    std::cout << "2. Difficulty increases after 3 consecutive correct answers.\n";
    std::cout << "3. The game ends if you answer 3 questions incorrectly in a row.\n";
    std::cout << "4. Try to achieve the highest score!\n";
}

void showHighScore() {
    std::cout << "\nThe current high score is: " << highScore << "\n";
}

void exitGame() {
    std::cout << "Thank you for playing! Goodbye!\n";
}

int generateQuestion(int difficulty) {
    int num1 = std::rand() % (10 * difficulty) + 1;
    int num2 = std::rand() % (10 * difficulty) + 1;

    std::cout << "What is " << num1 << " x " << num2 << "? ";
    return num1 * num2;  // Return the correct answer
}