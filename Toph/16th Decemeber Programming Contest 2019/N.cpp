#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second
ll a[1000009];
int main()
{
    ll t, n, i, mod = 1000000007;

    a[0] = 0;
    a[1] = 1;

    for(i = 2; i < 1000009; i++)
        a[i] = (a[i-1] + a[i-2])%mod;

    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << a[n] << endl;
    }
}
