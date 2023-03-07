#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void printer(char c2, vector<string> lines)
{
    if (c2 == 'f')
    {
        for (auto j : lines)
        {
            if (j.size() != 0)
                cout << j << endl;
        }
    }
    else if (c2 == 'r')
    {
        while (lines.size() > 0)
        {
            string singleline = lines.back();
            if (singleline.size() != 0)
            {
                cout << singleline << endl;
            }
            lines.pop_back();
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
        return 1;
    }
    string textFileName;
    cin >> textFileName;
    ifstream textFile(textFileName);
    if (!textFile.is_open())
    {
        cerr << "Error, cannot open specified text file." << endl;
        return 1;
    }
    textFile.close();

    vector<string> lines;
    string line;
    string token;
    int flag = 0;

    string command;
    char printDirection = 'f'; // f for forward, r for reverse
    while (cin >> command)
    {
        if (flag == 0 && command != "rr" && command != "rl" && command != "c" && command != "j")
        {
            flag = 1;
            ifstream textFile(textFileName);
            lines.clear();
            line = "";
            token = "";

            while (textFile >> token)
            {
                if (line.length() + token.length() + 1 > N)
                {
                    lines.push_back(line);
                    line = "";
                }

                else if (token.length() > N)
                {
                    token = token.substr(0, N);
                    lines.push_back(token);
                }

                line += (line.length() == 0 ? "" : " ") + token;

                if (line.size() > N)
                {
                    line = line.substr(0, N);
                }
            }

            if (line.size() != 0)
            {
                lines.push_back(line);
            }
            for (int i = 0; i < lines.size(); i++)
            {
                if (lines[i].size() != 0)
                {
                    int spaces = N - lines[i].length();
                    string newline = lines[i];
                    for (int j = 0; j < spaces; j++)
                    {
                        newline.insert(newline.length(), " ");
                    }
                    lines[i] = newline;
                }
            }
            textFile.close();
        }

        if (command == "rr") // done
        {
            flag = 1;
            ifstream textFile(textFileName);
            lines.clear();
            line = "";
            token = "";

            while (textFile >> token)
            {
                if (line.length() + token.length() + 1 > N)
                {
                    lines.push_back(line);
                    line = "";
                }

                else if (token.length() > N)
                {
                    token = token.substr(0, N);
                    lines.push_back(token);
                }

                line += (line.length() == 0 ? "" : " ") + token;

                if (line.size() > N)
                {
                    line = line.substr(0, N);
                }
            }

            if (line.size() != 0)
            {
                lines.push_back(line);
            }
            for (int i = 0; i < lines.size(); i++)
            {
                if (lines[i].size() != 0)
                {
                    int spaces = N - lines[i].length();
                    string newline = lines[i];
                    for (int j = 0; j < spaces; j++)
                    {
                        newline.insert(newline.length(), " ");
                    }
                    lines[i] = newline;
                }
            }
            textFile.close();
        }
        else if (command == "rl") // done
        {
            flag = 1;
            ifstream textFile(textFileName);
            lines.clear();
            line = "";
            token = "";

            while (textFile >> token)
            {
                if (line.length() + token.length() + 1 > N)
                {
                    lines.push_back(line);
                    line = "";
                }

                else if (token.length() > N)
                {
                    token = token.substr(0, N);
                    lines.push_back(token);
                }

                line += (line.length() == 0 ? "" : " ") + token;

                if (line.size() > N)
                {
                    line = line.substr(0, N);
                }
            }

            if (line.size() != 0)
            {
                lines.push_back(line);
            }
            for (int i = 0; i < lines.size(); i++)
            {
                if (lines[i].size() != 0)
                {
                    int spaces = N - lines[i].length();
                    string newline = lines[i];
                    for (int j = 0; j < spaces; j++)
                    {
                        newline.insert(0, " ");
                    }
                    lines[i] = newline;
                }
            }
            textFile.close();
        }
        else if (command == "c") // done
        {
            flag = 1;
            ifstream textFile(textFileName);
            lines.clear();
            line = "";
            token = "";

            while (textFile >> token)
            {
                if (line.length() + token.length() + 1 > N)
                {
                    lines.push_back(line);
                    line = "";
                }

                else if (token.length() > N)
                {
                    token = token.substr(0, N);
                    lines.push_back(token);
                }

                line += (line.length() == 0 ? "" : " ") + token;

                if (line.size() > N)
                {
                    line = line.substr(0, N);
                }
            }

            if (line.size() != 0)
            {
                lines.push_back(line);
            }
            for (int i = 0; i < lines.size(); i++)
            {
                int spaces = (N - lines[i].size()) / 2;
                int remaining = (N - lines[i].size()) % 2;
                string newline = "";

                for (int i = spaces; i > 0; i--)
                {
                    newline.insert(0, " ");
                }

                newline.insert(0, lines[i]);

                for (int i = spaces; i > 0; i--)
                {
                    newline.insert(0, " ");
                }
                for (int i = remaining; i > 0; i--)
                {
                    newline.insert(0, " ");
                }
                lines[i] = newline;
            }
            textFile.close();
        }
        else if (command == "j") // done
        {
            flag = 1;
            ifstream textFile(textFileName);
            lines.clear();
            line = "";
            token = "";

            while (textFile >> token)
            {
                if (line.length() + token.length() + 1 > N)
                {
                    lines.push_back(line);
                    line = "";
                }

                else if (token.length() > N)
                {
                    token = token.substr(0, N);
                    lines.push_back(token);
                }

                line += (line.length() == 0 ? "" : " ") + token;

                if (line.size() > N)
                {
                    line = line.substr(0, N);
                }
            }

            if (line.size() != 0)
            {
                lines.push_back(line);
            }

            for (int j = lines.size() - 1; j >= 0; j--)
            {
                if (lines[j].size() != 0)
                {
                    int spaces = N - lines[j].size();
                    int gaps = 0;
                    for (int i = 0; i < lines[j].size(); i++)
                    {
                        if (lines[j][i] == ' ')
                            gaps++;
                    }

                    if (gaps == 0)
                    {
                        string newline = lines[j];
                        for (int i = 0; i < spaces; i++)
                        {
                            newline.insert(newline.length(), " ");
                        }
                        lines[j] = newline;
                    }
                    else
                    {
                        string newLine = "";
                        int spacesPerGap = spaces / gaps;
                        int extraSpaces = spaces % gaps;
                        for (int i = 0; i < lines[j].size(); i++)
                        {
                            newLine += lines[j][i];
                            if (lines[j][i] == ' ')
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
                        lines[j] = newLine;
                    }
                }
            }
            textFile.close();
        } 


        else if (command == "f")
        {
            printDirection = 'f';
        }
        else if (command == "r")
        {
            printDirection = 'r';
        }
        else if (command == "p")
        {
            printer(printDirection, lines);
        }
        else if (command == "k")
        {
            for (int i = 0; i < lines.size(); i++){
                if (lines[i].length() == 0){
                    lines.erase(lines.begin() + i);
                }
            }
            int k;
            cin >> k;
            if (k > -1 && k < lines.size())
            {
                cout << lines[k] << endl;
            }
        }
        else if (command == "s")
        {
            string s;
            cin >> s;
            for (auto i : lines)
            {
                if (i.find(s) != -1)
                {
                    cout << i << endl;
                }
            }
        }
        else if (command == "q")
        {
            break;
        }
        else
        {
            cerr << "Error, command is illegal." << endl;
            break;
        }
    }
    return 0;
}