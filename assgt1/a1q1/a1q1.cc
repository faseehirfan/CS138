/*
 * CS138, W23, Assignment 1, Problem 1
 * Main Function
 *
 * main function is a special function,
 * which serves as the entry point for the program.
 *
 * Try to keep it as simple as possible
 * and implement the logic of your program
 * in a1q1.cpp, so that you can write unit tests
 * for them and make sure of their expected behavior.
 */

// no argc+argv because we aren't using them in A1

#include <string>
#include <iostream>
using namespace std;

void print(int N)
{
    cin.ignore(); // eat newline character after N

    string line;
    while (getline(cin, line))
    {
        if (line.length() > N)
        {
            cout << line.substr(0, N) << endl;
        }
        else
        {
            cout << line << endl;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    if (N <= 0)
    {
        cerr << "Error, line length must be positive." << endl;
        return 0;
    }
    print(N);
}
