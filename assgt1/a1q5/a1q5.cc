/*
* CS138, W23, Assignment 1, Problem 5
* Main Function
*
* main function is a special function,
* which serves as the entry point for the program.
* 
* Try to keep it as simple as possible
* and implement the logic of your program
* in a1q5.cpp, so that you can write unit tests
* for them and make sure of their expected behavior.
*/

// no argc+argv because we aren't using them in A1
#include<string>
#include<vector>
#include<iostream>
using namespace std;

void printer(char c2, vector<string> para){
    if (c2 == 'f'){
        for (auto j : para)
        {
            if (j.size() != 0)
                cout << j << endl;
        }
    } 
    else if (c2 == 'r'){
        while (para.size() > 0)
        {
            string singleline = para.back();
            if (singleline.size() != 0){
                cout << singleline << endl;
            }
            para.pop_back();
        }
    }
    else if (c2 == 'g'){
        const string fnord = "fnord";
        for (auto i : para)
        {
            if (i.find(fnord) != -1){
                cout << i << endl;
            }
        }
    }
}

int main() {
    // TODO: Solve the problem!
    int N;
    string token;
    string line;
    string c1;
    char c2;
    vector<string> para;
    cin >> N;

    if (N <= 0)
    {
        cerr << "Error, line length must be positive." << endl;
        return 1;
    }

    cin >> c1;
    cin >> c2;
    if (c1 != "rr" && c1 != "j" && c1 != "rl" && c1 != "c"){
        cerr << "Error, command is illegal." << endl;
        return 1;
    }
    if (c2 != 'f' && c2 != 'r' && c2 != 'g')
    {
        cerr << "Error, command is illegal." << endl;
        return 1;
    }


    if (c1 == "rr")
    {
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
        for (int i = 0; i < para.size(); i++)
        {   
            if (para[i].size() != 0){
                int spaces = N - para[i].length();
                string newline = para[i];
                for (int j = 0; j < spaces; j++)
                {
                    newline.insert(newline.length(), " ");
                }
                para[i] = newline;
            }
        }
    }
    else if (c1 == "j"){
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

        for (int j = para.size() - 1; j >= 0; j--)
        {
            if (para[j].size() != 0)
            {
                int spaces = N - para[j].size();
                int gaps = 0;
                for (int i = 0; i < para[j].size(); i++)
                {
                    if (para[j][i] == ' ')
                        gaps++;
                }

                if (gaps == 0)
                {
                    string newline = para[j];
                    for (int i = 0; i < spaces; i++)
                    {
                        newline.insert(newline.length(), " ");
                    }
                    para[j] = newline;
                }
                else
                {
                    string newLine = "";
                    int spacesPerGap = spaces / gaps;
                    int extraSpaces = spaces % gaps;
                    for (int i = 0; i < para[j].size(); i++)
                    {
                        newLine += para[j][i];
                        if (para[j][i] == ' ')
                        {
                            for (int k = 0; k < spacesPerGap; k++)
                            {
                                newLine.insert(newLine.length(), " ");
                            }
                            if (extraSpaces > 0)
                            {
                                newLine.insert(newLine.length(), " ");
                                extraSpaces--;
                            }
                        }
                    }
                    para[j] = newLine;
                }
            }
        }
    }

    else if (c1 == "rl"){
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

        for (int i = 0; i < para.size(); i++)
        {
            if (para[i].size() != 0)
            {
                int spaces = N - para[i].length();
                string newline = para[i];
                for (int j = 0; j < spaces; j++)
                {
                    newline.insert(0, " ");
                }
                para[i] = newline;
            }
        }
    }

    else if (c1 == "c"){
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

        for (int i = 0; i < para.size(); i++)
        {
            int spaces = (N - para[i].size()) / 2;
            int remaining = (N - para[i].size()) % 2;
            string newline = "";

            for (int i = spaces; i > 0; i--)
            {
                newline.insert(0, " ");
            }

            newline.insert(0, para[i]);

            for (int i = spaces; i > 0; i--)
            {
                newline.insert(0 , " ");
            }
            for (int i = remaining; i > 0; i--)
            {
                newline.insert(0, " ");
            }
            para[i] = newline;
        }
    }

    printer(c2, para);
    return 0;
}
