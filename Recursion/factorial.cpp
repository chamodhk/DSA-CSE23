#include <iostream>
using namespace std;

int factorial(int);

int main()
{
    int n = 0;
    cout << "Enter a non-negative number: ";
    cin >> n;
    cout << "Factorial of " <<  n << " is " << factorial(n) << endl;
}


int factorial(int n) 
{
    if (n == 1) 
        return 1;
    else
        return n * factorial( n - 1 );
}
