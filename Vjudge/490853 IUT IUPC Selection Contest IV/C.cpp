#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = n; i >= 1; i--)
            cout << i << " ";
        cout << "\n";
    }
}
