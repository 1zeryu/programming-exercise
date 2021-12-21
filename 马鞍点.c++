#include <iostream>
#include <fstream>
using namespace std;
int main(void)
{
    ifstream fin("data.in");
    streambuf *in;
    in = cin.rdbuf(fin.rdbuf());
    int a[4][5];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int max_index = 0;
        int max = a[i][0];
        for (int j = 0; j < 5; j++)
        {
            if (max < a[i][j])
            {
                max = a[i][j];
                max_index = j;
            }
        }
        int right = 1;
        for (int j = 0; j < 4; j++)
        {
            if (max > a[j][max_index])
            {
                right = 0;
            }
        }
        if (right)
        {
            cout << max << " " << i + 1 << " " << max_index + 1;
            return 0;
        }
    }
    cout << "°°µã²»´æÔÚ" << endl;
    cin.rdbuf(in);
    fin.close();
    return 0;
}