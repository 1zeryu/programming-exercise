#include <iostream>
#include <fstream>
using namespace std;
int main(void)
{
    ifstream fin("data.in");
    streambuf *in;
    in = cin.rdbuf(fin.rdbuf());
    string word;
    string guess;
    int game;
    while (true)
    {
        cin >> game;
        if (game == -1)
        {
            cout << "game over" << endl;
            break;
        }
        else
        {
            cin >> guess;
            cin >> word;
            int wrong = 0;
            for (int i = 0; i < word.size(); i++)
            {
                int right = 1;
                for (int j = 0; j < guess.size(); j++)
                {
                    if (word[i] == guess[j])
                    {
                        right = 0;
                        break;
                    }
                }
                if (right)
                {
                    wrong += 1;
                }
            }
            cout << "Game" << game << " " << endl;
            if (wrong == 0)
            {
                cout << "You win" << endl;
            }
            else if (wrong >= 7)
            {
                cout << "You lost" << endl;
            }
            else
            {
                cout << "You chickened out" << endl;
            }
        }
    }
    cin.rdbuf(in);
    fin.close();
    return 0;
}