#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, x, ans;
    string s;

    cin >> s;

    x = 0;
    ans = 0;
    for(i = 0; i < s.size(); i++)
    {
        x += s[i] == 'S';
        x -= s[i] == 'T';

        if(x < 0)
        {
            ans++;
            x = 0;
        }
    }

    cout << ans + x << "\n";
}