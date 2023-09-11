#include <iostream>
using namespace std;

void abs(int *a, int *b)
{
    int num1 = (*a + *b);
    int num2;
    if (*a > *b)
    {
        num2 = (*a - *b);
    }
    else
    {
        num2 = (*b - *a);
    }
    cout << num1 << endl
         << num2;
}

int main()
{
    int a, b;
    int *pa = &a, *pb = &b;
    cin >> a >> b;
    abs(pa, pb);

    return 0;
}