#include <iostream>
using namespace std;
int main(void)
{
    int year, month, day;
    cin >> year >> month >> day;
    int century = year / 100;
    year = year % 100;
    int week=5-century+year+(year/4)+(13*(month+1)/5)+day;
    week=week%7;
    switch (week)
    {
    case 1: cout << "Monday";
        break;
    case 2: cout << "Tuesday"; break;
    case 4: cout << "Thursday"; break;
    case 3: cout << "Wednesday"; break;
    case 5: cout << "Friday"; break;
    case 6: cout << "Saturday"; break;
    case 0: cout << "Sunday"; break;
    default:
        break;
    }
    return 0;
}