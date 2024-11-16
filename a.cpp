// -1 -1 4
// - - - - +
// 
//
//

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef vector<long long int> vlli;
long long int calc(const vlli &nums) {
    long long int sum = 0;
    long long int dip = 0;
    int i = (int)nums.size() - 1;

    for (; i >= 0; i--) {
        sum += nums[i];
        dip = min(dip, sum);

        if (sum > 0) {
            return dip;
        }
    }

    return -1e18;
}

int main() {
    long long int x;
    unsigned k;
    cin >> x >> k;
    vector<vlli> l;

    priority_queue<pair<long long int, unsigned int>> chunks;
    for (unsigned int i = 0; i < k; i++) {
        unsigned int len;
        cin >> len;
        vlli l_i;
        while (len--) {
            long long int cur_l;
            cin >> cur_l;
            l_i.push_back(cur_l);
        }
        reverse(l_i.begin(), l_i.end());
        l.push_back(l_i);
        chunks.push({calc(l_i), i});
    }

    while (!chunks.empty()) {
        auto [dip, index] = chunks.top();
        // cout << "Dip " << dip << " for list " << index << "\n";
        if (dip + x < 0) {
            break;
        }
        chunks.pop();
        long long int sum = 0;
        while (sum <= 0) {
            sum += l[index].back();
            l[index].pop_back();
        }
        x += sum;
        chunks.push({calc(l[index]), index});
        // cout << "Sum is " << sum << ", x is " << x << "\n";
    }

    cout << x;
    return 0;
}