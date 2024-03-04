#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int s1, s2;
    if (d >= b)
    {
        s1 = c - a;
        s2 = d - b;
    }
    else
    {
        d = d + 60;
        c = c - 1;
        s1 = c - a;
        s2 = d - b;
    }
    cout << s1 << " " << s2 << endl;
    system("pause");
    return 0;
}