#include <iostream>
using namespace std;
int main(void)
{
    int num[50];
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < m * n; i++)
    {
        cin >> num[i];
    }
    int size = m * n;
    for (int x = 0; x < size; x++)
    {
        for (int y = x + 1; y < size; y++)
        {
            if (num[x] > num[y])
            {
                swap(num[x], num[y]);
            }
        }
    }
    int i = 0;
    int a[7][7];
    int j = n - 1;
    int k = 0;
    while (true)
    {
        while (true)
        {
            a[i][j] = num[k];
            k++, j--;
            if (j < 0)
            {
                break;
            }
        }
        i++;
        j++;
        if (i >= m)
        {
            break;
        }
        while (true)
        {
            a[i][j] = num[k];
            j++, k++;
            if (j >= n)
            {
                break;
            }
        }
        i++, j--;
        if (i >= m)
        {
            break;
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}