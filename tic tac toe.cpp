

#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); 

    const int ROCK = 1;
    const int PAPER = 2;
    const int SCISSORS = 3;

    int playerChoice;
    int computerChoice;

    cout << "Choose rock (1), paper (2), or scissors (3): ";
    cin >> playerChoice;

    computerChoice = rand() % 3 + 1;

    switch (computerChoice) {
        case ROCK:
            cout << "The computer chose: Rock" << endl;
            break;
        case PAPER:
            cout << "The computer chose: Paper" << endl;
            break;
        case SCISSORS:
            cout << "The computer chose: Scissors" << endl;
            break;
    }

    if (playerChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((playerChoice == ROCK && computerChoice == SCISSORS) ||
               (playerChoice == PAPER && computerChoice == ROCK) ||
               (playerChoice == SCISSORS && computerChoice == PAPER)) {
        cout << "You win!" << endl;
    } else {
        cout << "You lose!" << endl;
    }

    return 0;
}
