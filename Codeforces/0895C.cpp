#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll arr[MAXN];

ll convert(ll x)
{
    
}

void solve(ll caseno)
{
    ll n, i;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] = convert(arr[i]);
    }
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