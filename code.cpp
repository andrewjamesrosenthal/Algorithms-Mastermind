#include <iostream>
#include <vector>
#include <cstdlib> // for rand(), srand()
#include <ctime>   // for time()
using namespace std;

class Code
{
public:
    // Constructor
    Code(int n, int m);

    // Random initialization of the code
    void initializeRandom();

    // Getters (for debugging/printing)
    void printCode() const;

    // Compare functions
    int checkCorrect(const Code &guess) const;   // right digit, right spot
    int checkIncorrect(const Code &guess) const; // right digit, wrong spot

private:
    int n;              // code length
    int m;              // digit range [0, m-1]
    vector<int> digits; // actual code digits
};

int main()
{
    srand(time(0)); // seed RNG

    int n = 5, m = 6; // example test setup
    Code secret(n, m);
    secret.initializeRandom();

    cout << "Secret code: ";
    secret.printCode();

    // Sample test guesses
    vector<vector<int>> testGuesses = {
        {5, 0, 3, 2, 6},
        {2, 1, 2, 2, 2},
        {1, 3, 3, 4, 5}};

    for (auto g : testGuesses)
    {
        Code guess(n, m);
        // Manually set guess digits (you’ll implement a setter or modify constructor)
        // guess.setDigits(g);

        cout << "Guess: ";
        for (int d : g)
            cout << d << " ";
        cout << endl;

        cout << "Correct position: " << secret.checkCorrect(guess) << endl;
        cout << "Correct but wrong position: " << secret.checkIncorrect(guess) << endl;
        cout << "-----" << endl;
    }

    return 0;
}
