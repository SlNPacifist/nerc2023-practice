#include <iostream>
using namespace std;

int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int b, n;
        cin >> b >> n;

        long long int cur_pow = b;
        long long int k = 1;
        int type = 0;

        for (; type == 0 && k <= n; k++) {
            if (cur_pow % n == 0) {
                type = 1;
                break;
            }
            if (cur_pow % n == 1) {
                type = 2;
                break;
            }
            if (cur_pow % n == n - 1) {
                type = 3;
                break;
            }
            cur_pow = (cur_pow * b) % n;
        }
        if (type > 0) {
            cout << type << " " << k << "\n";
        } else {
            cout << "0\n";
        }
    }
    return 0;
}