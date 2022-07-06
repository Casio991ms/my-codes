#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(ll caseno)
{
    ll n, x, i;
    ordered_set<pll> OS;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x;
        OS.insert({i, x});
    }

    for(i = 0; i < n; i++)
    {
        cin >> x;

        cout << (*OS.find_by_order(x-1)).ss << " ";
        OS.erase(*OS.find_by_order(x-1));
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}