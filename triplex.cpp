#include <iostream>
#include <ctime>

void PrintIntroduction( int Difficulty ) {
    // Print welcome messages to the terminal
    std::cout << "---------------------------------------------------------------------------------------------------------------------" << "\n";
    std::cout << "You are a hacker in the FBI, infiltrating FIREWALL #" << Difficulty << ", of the enemy's top secret server..." << "\n";
    std::cout << "You need to enter the correct code to bypass this FIREWALL..." << "\n\n";
}

bool PlayGame( int Difficulty, int GameDifficulty ) {

    PrintIntroduction( Difficulty );

    // Declare 3 number code
    const int CodeA = (rand() % Difficulty) + (Difficulty * GameDifficulty );
    const int CodeB = (rand() % Difficulty) + (Difficulty * GameDifficulty );
    const int CodeC = (rand() % Difficulty) + (Difficulty * GameDifficulty );

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print Sum and Product to the terminal
    std::cout << "+ There are 3 numbers in the code" << "\n";
    std::cout << "+ The codes add-up to: " << CodeSum << "\n";
    std::cout << "+ The codes multiply to give: " << CodeProduct << "\n\n";

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if( GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "Your code worked! You bypassed FIREWALL #" << Difficulty << "!" << "\n";
        return true;
    } else {
        std::cout << "Your code failed! The enemy found you messing with their servers and booted you out of their system!" << "\n";
        return false;
    }
}

int main() {

    srand(time(NULL));

    int GameDifficulty = 0;

    std::cout << "Enter a Game difficulty between 1 & 3: ";
    std::cin >> GameDifficulty;

    while( GameDifficulty < 1 || GameDifficulty > 3 ) {
        std::cout << "\n" << "That is not a valid game difficulty, enter a difficulty between 1 & 3: ";
        std::cin >> GameDifficulty;
    }

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5 * GameDifficulty;

    while( LevelDifficulty <= MaxDifficulty ){ // Loop game untill all levels are completed

        bool bLevelComplete = PlayGame(LevelDifficulty, GameDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if( bLevelComplete ) {
            if( LevelDifficulty == MaxDifficulty ) 
                std::cout << "You breached the enemy's top secret, maximum security server!" << "\n";
            LevelDifficulty++;
        } else
            break;
    }

    return 0;
}