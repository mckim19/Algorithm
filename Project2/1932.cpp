#include <iostream>
#include <algorithm>
using namespace std;

int Arr[501][501];
int N, ans = 0;

void triangle(int N)
{
   
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
            {
                Arr[i][j] += Arr[i - 1][j];
            }
            else if (i == j)
            {
                Arr[i][j] += Arr[i - 1][j - 1];
            }
            else
            {
                Arr[i][j] = max(Arr[i - 1][j], Arr[i - 1][j - 1]) + Arr[i][j];
            }
            if (ans < Arr[i][j])
                ans = Arr[i][j];
        }
    }

}
int main()
{

    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            cin >> Arr[i][j];

    triangle(N);

    cout << ans;
}