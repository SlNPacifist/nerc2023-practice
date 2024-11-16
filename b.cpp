#include <iostream>
using namespace std;

typedef long long int lli;

const lli mod = 998244353;

const unsigned int MAX = 1e5 + 1;
lli facts[MAX] = {};

lli pow(lli x, lli p) {
    lli res = 1;
    lli cur = x;
    for (; p; p = p >> 1) {
        if (p & 1) {
            res = res * cur % mod;
        }
        cur = cur * cur % mod;
    }
    return res;
}

lli inv(lli x) {
    return pow(x, mod - 2);
}

lli c(lli n, lli m) {
    return (facts[n] * inv(facts[m]) % mod) * inv(facts[n - m]) % mod;
}

lli dist(lli n, lli k) {
    lli size = n / k; // 2
    lli plus = n % k; // 1

    lli res;
    if (size % 2) {
        lli lower_size = size - 1;
        res = (lower_size / 2) * lower_size / 2;
    } else {
        res = (size / 2 - 1) * size / 2;
    }
    res *= k;
    res += size / 2 * plus;
    return res;
}

int main() {
    facts[0] = 1;
    for (lli i = 1; i <= MAX; i++) {
        facts[i] = facts[i - 1] * i % mod;
    }

    lli t;
    cin >> t;
    while (t--) {
        lli n, k;
        cin >> n >> k;
        
        lli combinations = 0;
        lli plus = n % k;

        lli size = n / k;
        if (size % 2) {
            if (plus == 0) {
                combinations = 2;
            } else {
                combinations = c(k - 1, plus - 1) + 2 * c(k - 1, plus);
            }
        } else {
            if (plus == 0) {
                combinations = 1;
            } else {
                combinations = 2 * c(k - 1, plus - 1) + c(k - 1, plus);
            }
        }
        cout << dist(n, k) << " " << combinations % mod << "\n";
    }
    return 0;
}