// Project 1a - Mastermind
// EECE2560 Fundamentals of Engineering Algorithms
// Team: 13-roscraeni-1a
// Date: Sept 21, 2025
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
using namespace std;

class Code {
public:
    // Constructor
    Code(int n, int m);

    // Random initialization of the code
    void randomCode();

    // Set digits manually
    void setDigits(const vector<int>& d);

    // For printing
    void printCode() const;
    int checkCorrect(const Code &guess) const;
    int checkIncorrect(const Code &guess) const;

private:
    int n;              // code length
    int m;              // digit range [0, m-1]
    vector<int> digits; // actual code digits
};

// constructor
Code::Code(int n, int m) : n(n), m(m), digits(n, 0) {}

// random initialization
void Code::randomCode() {
    for (int i = 0; i < n; ++i) {
        digits[i] = rand() % m;
    }
}

// set digits manually
void Code::setDigits(const vector<int>& d) {
    if (d.size() != n) {
        throw invalid_argument("setDigits: size mismatch");
    }
    digits = d;
}

// print code
void Code::printCode() const {
    for (int d : digits) cout << d << " ";
    cout << endl;
}

// check correct (right digit, right spot)
int Code::checkCorrect(const Code& guess) const {
    if (n != guess.n || m != guess.m || digits.size() != guess.digits.size()) {
        throw invalid_argument("checkCorrect: mismatch in n, m, or size");
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (digits[i] == guess.digits[i]) {
            ++count;
        }
    }
    return count;
}

// check incorrect (right digit, wrong spot)
int Code::checkIncorrect(const Code& guess) const {
    vector<bool> secretUsed(n, false);
    vector<bool> guessUsed(n, false);

    int count = 0;
    // mark exact matches first
    for (int i = 0; i < n; ++i) {
        if (digits[i] == guess.digits[i]) {
            secretUsed[i] = true;
            guessUsed[i] = true;
        }
    }

    // check for misplaced matches
    for (int i = 0; i < n; ++i) {
        if (!guessUsed[i]) {
            for (int j = 0; j < n; ++j) {
                if (!secretUsed[j] && guess.digits[i] == digits[j]) {
                    count++;
                    secretUsed[j] = true;
                    guessUsed[i] = true;
                    break;
                }
            }
        }
    }
    return count;
}

int main() {
    srand(time(0));

    int n = 5, m = 6; // example test setup
    Code secret(n, m);
    secret.randomCode();

    cout << "Secret code: ";
    secret.printCode();

    // Sample test guesses
    vector<vector<int>> testGuesses = {
        {5, 0, 3, 2, 6},
        {2, 1, 2, 2, 2},
        {1, 3, 3, 4, 5}
    };

    for (vector<int> g : testGuesses) {
        Code guess(n, m);
        guess.setDigits(g);

        cout << "Guess: ";
        for (int d : g) cout << d << " ";
        cout << endl;

        cout << "Correct position: " << secret.checkCorrect(guess) << endl;
        cout << "Correct but wrong position: " << secret.checkIncorrect(guess) << endl;
        cout << "-----" << endl;
    }

    return 0;
}
