#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double pi = 3.1415926;

int main()
{
    int N;
    double R;
    int n, scenario=1;
    cin >> N;
    while(N--)
    {
        cin >> R >> n;
        double m = sin(pi / (double) n);
        printf("Scenario #%d:\n%.3f\n",scenario++, m * R / (m + 1));
        if(N) cout << endl;
    }
    return 0;
}