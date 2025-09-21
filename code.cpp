#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
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
    int checkCorrect(const Code &guess) const;
    int checkIncorrect(const Code &guess) const;
    
                    

private:
    int n;              // code length
    int m;              // digit range [0, m-1]
    vector<int> digits; // actual code digits
};
int Code::int checkCorrect(const Code &guess) const
    { // right digit, right spot
        if (n != guess.n)
        {
            throw invalid_argument("checkCorrect: n (length) mismatch");
        }
        if (m != guess.m)
        {
            throw invalid_argument("checkCorrect: m (range) mismatch");
        }
        if (digits.size() != guess.digits.size())
        {
            throw invalid_argument("checkCorrect: digits size mismatch");
        }
        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            if (digits[i] == guess.digits[i])
            {
                ++count;
            }
        }
        return count;
    }

int Code::checkIncorrect(const Code& guess) const{
    vector<bool> secretUsed(n, false);
    vector<bool> guessUsed(n, false);
    
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (this->digits[i] == guess.digits[i]) {
            secretUsed[i] = true;
            guessUsed[i] = true;
        }
    }
	
    for (int i = 0; i < n; ++i) {
        if (!guessUsed[i]) { 
            for (int j = 0; j < n; ++j) {
                if (!secretUsed[j] && guess.digits[i] == this->digits[j]) {
                    count++;
                    secretUsed[j] = true; 
                    guessUsed[i] = true; 
                    break;
                }
            }
        }
    }
	return count;
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

    for (vector<int> guess : testGuesses)
    {
        Code guess(n, m);

        cout << "Guess: ";
        for (int d : guess)
            cout << d << " ";
        cout << endl;

        cout << "Correct position: " << secret.checkCorrect(guess) << endl;
        cout << "Correct but wrong position: " << secret.checkIncorrect(guess) << endl;
        cout << "-----" << endl;
    }

    return 0;
}
