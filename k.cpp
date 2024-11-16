#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

long long int mod =  998244353;

typedef long long int lli;
const int MAXN = 200000;
lli amount[MAXN + 10][4][8];

lli dumb(vector<int> &nums) {
    int res = 0;
    for (int i = 0; i < (1 << nums.size()); i++) {
        vector<int> left;
        for (int j = 0; j < nums.size(); j++) {
            if (i & (1 << j)) {
                left.push_back(nums[j]);
            }
        }
        if (left.size() < 3) {
            continue;
        }

        bool is_good = true;
        for (int j = 0; is_good && j < left.size() - 2; j++) {
            is_good = is_good &&((left[j] + left[j + 1] + left[j + 2]) % 2 == 0);
        }
        res += is_good;
    }
    return res;
}

lli solve(vector<int> &nums) {
    memset(amount, 0, sizeof(amount));
    auto n = nums.size();

    amount[0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        int a = nums[i - 1];
        a %= 2;
        for (int len = 1; len <= 4; len++) {
            for (int mask = 0; mask < 8; mask++) {
                if (len > 3 && __popcount(mask) % 2) {
                    continue;
                }
                int newmask = ((mask & 3) << 1) + a;
                amount[i][min(len, 3)][newmask] += amount[i - 1][len - 1][mask];
                amount[i][min(len, 3)][newmask] %= mod;
            }
            for (int mask = 0; mask < 8; mask++) {
                amount[i][len - 1][mask] += amount[i - 1][len - 1][mask];
                amount[i][len - 1][mask] %= mod;
            }
        }
        // cout << "i = " << i << ", a = " << a << "\n";
        // for (int len = 0; len < 4; len++) {
        //     cout << "Len " << len << "\n";
        //     for (int mask = 0; mask < 8; mask++) {
        //         cout << amount[i][len][mask] << ' ';
        //     }
        //     cout << "\n";
        // }
    }
    // for (int len = 0; len < 4; len++) {
    //     cout << "Len " << len << "\n";
    //     for (int mask = 0; mask < 8; mask++) {
    //         cout << amount[n][len][mask] << ' ';
    //     }
    //     cout << "\n";
    // }
    return (amount[n][3][0] + amount[n][3][3] + amount[n][3][5] + amount[n][3][6]) % mod;
}

void printVector(const std::vector<int>& vec) {
    for (int x : vec) { // Range-based for loop
        std::cout << x << " ";
    }
    std::cout << std::endl; // Newline at the end
}

void check() {
    for (int i = 3; i < 6; i++) {
        for (int j = 0; j < (1 << i); j++) {
            vector<int> v;
            for (int k = 0; k < i; k++) {
                v.push_back((j >> k) & 1);
            }
            auto d = dumb(v);
            auto s = solve(v);
            if (d != s) {
                printVector(v);
                cout << "dumb:" << dumb(v) << "\n";
                cout << "solv:" << solve(v) << "\n";
            }
        }
    }
}

int main() {
    unsigned int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }


    // vector<int> v = {1, 3, 4};

    cout << solve(v) << "\n";

    return 0;
}