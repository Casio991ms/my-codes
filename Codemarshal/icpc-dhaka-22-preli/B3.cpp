#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 500005

LL a[MAXN], b[MAXN];

LL mul(LL a, LL b, LL mod) {
    return (__int128)a * b % mod;
    // LL ans = a * b - mod * (LL) (1.L / mod * a * b);
    // return ans + mod * (ans < 0) - mod * (ans >= (LL) mod);
}
LL bigmod(LL num, LL pow, LL mod) {
    LL ans = 1;
    for (; pow > 0; pow >>= 1, num = mul(num, num, mod))
        if (pow & 1) ans = mul(ans, num, mod);
    return ans;
}
bool is_prime(LL n) {
    if (n < 2 or n % 6 % 4 != 1) return (n | 1) == 3;
    LL a[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    LL s = __builtin_ctzll(n - 1), d = n >> s;
    for (LL x : a) {
        LL p = bigmod(x % n, d, n), i = s;
        for (; p != 1 and p != n - 1 and x % n and i--; p = mul(p, p, n))
        ;
        if (p != n - 1 and i != s) return false;
    }
    return true;
}
LL get_factor(LL n) {
    auto f = [&](LL x) { return mul(x, x, n) + 1; };
    LL x = 0, y = 0, t = 0, prod = 2, i = 2, q;
    for (; t++ % 40 or gcd(prod, n) == 1; x = f(x), y = f(f(y))) {
        (x == y) ? x = i++, y = f(x) : 0;
        prod = (q = mul(prod, max(x, y) - min(x, y), n)) ? q : prod;
    }
    return gcd(prod, n);
}
map<LL, int> factorize(LL n) {
    map<LL, int> res;
    if (n < 2) return res;
    LL small_primes[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                        43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for (LL p : small_primes)
        for (; n % p == 0; n /= p, res[p]++)
        ;

    auto _factor = [&](LL n, auto &_factor) {
        if (n == 1) return;
        if (is_prime(n))
        res[n]++;
        else {
        LL x = get_factor(n);
        _factor(x, _factor);
        _factor(n / x, _factor);
        }
    };
    _factor(n, _factor);
    return res;
}


void solve(int caseno)
{
    LL n, i, j, gcdA;
    map<LL, int> factA, factB, factGcdA;
    bool canAlice, canBob;

    cin >> n;

    gcdA = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];

        map<LL, int> temp = factorize(a[i]);

        if(factA.size() < temp.size())
            swap(factA, temp);

        for(auto &[p, cnt] : temp)
            factA[p] += cnt;

        gcdA = gcd(gcdA, a[i]);
    }

    factGcdA = factorize(gcdA);

    for(i = 0; i < n; i++)
    {
        cin >> b[i];

        map<LL, int> temp = factorize(b[i]);

        if(factB.size() < temp.size())
            swap(factB, temp);

        for(auto &[p, cnt] : temp)
            factB[p] += cnt;
    }

    cout << "Case " << caseno << ": ";

    canAlice = true;
    for(auto &[p, cnt] : factB)
    {
        if(factA.find(p) == factA.end())
        {
            canAlice = false;
            break;
        }
    }

    if(canAlice == false)
    {
        cout << "No No\n";
        return;
    }

    canBob = true;
    for(i = 0; i < n; i++)
    {
        a[i] /= gcdA;
        
        for(auto &[p, cnt] : factGcdA)
        {
            while(b[i] % p == 0)
                b[i] /= p;
        }

        if(a[i] != b[i])
        {
            canBob = false;
            break;
        }
    }

    cout << "Yes " << (canBob? "Yes\n" : "No\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}