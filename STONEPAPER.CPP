#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Choice { ROCK = 1, PAPER, SCISSORS };

void printChoice(Choice choice) {
    switch (choice) {
        case ROCK: cout << "Rock"; break;
        case PAPER: cout << "Paper"; break;
        case SCISSORS: cout << "Scissors"; break;
    }
}

Choice getUserChoice() {
    int choice;
    cout << "Enter your choice (1 = Rock, 2 = Paper, 3 = Scissors): ";
    cin >> choice;

    // Ensure choice is valid
    while (choice < 1 || choice > 3) {
        cout << "Invalid choice. Please enter 1, 2, or 3: ";
        cin >> choice;
    }

    return static_cast<Choice>(choice);
}

Choice getComputerChoice() {
    // Seed random number generator
    srand(time(0));
    return static_cast<Choice>(rand() % 3 + 1);
}

void determineWinner(Choice user, Choice computer) {
    if (user == computer) {
        cout << "It's a tie!" << endl;
    } else if ((user == ROCK && computer == SCISSORS) ||
               (user == PAPER && computer == ROCK) ||
               (user == SCISSORS && computer == PAPER)) {
        cout << "You win!" << endl;
    } else {
        cout << "You lose!" << endl;
    }
}

int main() {
    cout << "Welcome to Rock, Paper, Scissors!" << endl;

    Choice userChoice = getUserChoice();
    Choice computerChoice = getComputerChoice();

    cout << "You chose: ";
    printChoice(userChoice);
    cout << endl;

    cout << "Computer chose: ";
    printChoice(computerChoice);    
    cout << endl;

    determineWinner(userChoice, computerChoice);

    return 0;
}
