#include <iostream>
using namespace std;
int main(void)
{
    const string p = "QWERTYUIOP[ASDFGHJKL;'ZXCVBNM,./";
    string wrong;
    getline(cin, wrong);
    for (int i = 0; i < wrong.size(); i++)
    {
        for (int j = 0; j < p.size(); j++)
        {
            if (wrong[i] == p[j])
            {
                wrong[i] = p[j - 1];
            }
        }
    }
    cout << wrong;
    return 0;
}