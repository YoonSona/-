#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

bool startGame()
{
    char choice;

    do
    {
        cout << "Whould you like to play a game(y/n)?";
        cin >> choice;
        if(choice == 'y')
            cout << "Let's paly a game. I'm thiking of a number. You have 7 tries to guess what it is.\n";
    } while (choice != 'y' && choice != 'n');
    return (choice == 'y');
}

bool play(int tries, int answer)
{
    for (int i = 1; i <= tries; ++i)
    {
        cout << "Guess # " << i << ": ";
        string numImput;
        int num;
        cin >> numImput;
        try
        {
            num = stoi(numImput);
        }
        catch (invalid_argument)
        {
            cout << "Only numbers are allowed!\n";
            break;
        }
            if (num < answer)
                cout << "Your guess is too low.\n";
            else if (num > answer)
                cout << "Your guess is too high.\n";
            else
                return true;
    }
    return false;
}

bool playAgain()
{
    char choice;

    do
    {
        cout << "Whould you like to play again (y/n)?";
        cin >> choice;
    }     while (choice != 'y' && choice != 'n');
    return (choice == 'y');
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();

    int tries = 7;

    bool game = startGame();
    
    do
    {
        int answer = getRandomNumber(1, 100);

        bool result = play(tries, answer);
        if (result)
            cout << "Correct! You win!\n";
        else
            cout << "Sorry, you lose. The correct number was " << answer << "." << endl;
    }
    while (playAgain());

    cout << "Thank you for playing.";
    return system("pause");
}
