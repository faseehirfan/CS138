/*
* CS138, W23, Assignment 1, Problem 4
* Main Function
*
* main function is a special function,
* which serves as the entry point for the program.
* 
* Try to keep it as simple as possible
* and implement the logic of your program
* in a1q4.cpp, so that you can write unit tests
* for them and make sure of their expected behavior.
*/

// no argc+argv because we aren't using them in A1
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// no argc+argv because we aren't using them in A1

int main()
{
    // TODO: Solve the problem!

    int N;
    string token;
    string line;
    vector<string> para;
    cin >> N;
    if (N <= 0)
    {
        cerr << "Error, line length must be positive." << endl;
        return 1;
    }

    while (cin >> token)
    {

        if (line.length() + token.length() + 1 > N)
        {
            para.push_back(line);
            line = "";
        }

        else if (token.length() > N)
        {
            token = token.substr(0, N);
            para.push_back(token);
        }

        line += (line.length() == 0 ? "" : " ") + token;

        if (line.size() > N)
        {
            line = line.substr(0, N);
        }
    }

    if (line.size() != 0)
    {
        para.push_back(line);
    }

    for (auto j : para)
    {
        if (j.size() != 0)
        {
            int spaces = N - j.size();
            int gaps = 0;

            for (int i = 0; i < j.size(); i++)
            {
                if (j[i] == ' ')
                    gaps++;
            }

            if (gaps == 0)
            {
                cout << j;
                for (int i = 0; i < spaces; i++)
                {
                    cout << " ";
                }
                cout << endl;
            }
            else
            {
                string newLine = "";
                int spacesPerGap = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int i = 0; i < j.size(); i++)
                {
                    newLine += j[i];
                    if (j[i] == ' ')
                    {
                        for (int k = 0; k < spacesPerGap; k++)
                        {
                            newLine += " ";
                        }
                        if (extraSpaces > 0)
                        {
                            newLine += " ";
                            extraSpaces--;
                        }
                    }
                }
                cout << newLine << endl;
            }
        }
    }
    return 0;
}