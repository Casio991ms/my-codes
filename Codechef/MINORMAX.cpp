#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 100005

void solve(ll caseno)
{
    ll i, n, b, mx, mn;
    bool flag;

    cin >> n;

    mx = -1;
    mn = INT_MAX;
    flag = 1;
    for(i = 0; i < n; i++)
    {
        cin >> b;
        if(b < mx && b > mn)
            flag = 0;
        mx = max(mx, b);
        mn = min(mn, b);
    }

    cout << (flag? "YES\n" : "NO\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}