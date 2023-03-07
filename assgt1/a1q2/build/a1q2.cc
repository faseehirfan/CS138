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
#include <vector>
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

void printReverse(int N)
{
    vector<string> lines{};
    string line;

    cin.ignore(); // eat newline character after N
    while (getline(cin, line))
    {
        if (line.length() > N)
        {
            lines.push_back(line.substr(0, N));
        }
        else
        {
            lines.push_back(line);
        }
    }
    while (lines.size() > 0)
    {
        string printer = lines.back();
        cout << printer << endl;
        lines.pop_back();
    }
}

void printfnord(int N)
{
    vector<string> lines;
    string line;
    const string fnord = "fnord";

    cin.ignore(); // eat newline character after N
    while (getline(cin, line))
    {
        if (line.length() > N)
        {
            if (line.find(fnord) != -1)
                lines.push_back(line.substr(0, N));
        }
        else
        {
            if (line.find(fnord) != -1)
            {
                lines.push_back(line);
            }
        }
    }
    
    for (auto i : lines){
        cout << i << endl;
    }
}

int main()
{

    int N;
    char comd;

    cin >> N;
    if (N <= 0)
    {
        cerr << "Error, line length must be positive." << endl;
        return 0;
    }

    cin >> comd;
    if (comd == 'f')
    {
        print(N);
    }
    else if (comd == 'r')
    {
        printReverse(N);
    }
    else if (comd == 'g')
    {
        printfnord(N);
    }
    else
    {
        cerr << "Error, command is illegal." << endl;
    }
}
