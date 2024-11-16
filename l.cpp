#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string food;
    cin >> food;
    int total_l = 0, total_o = 0;
    for (auto c : food) {
        if (c == 'L') {
            total_l++;
        } else {
            total_o++;
        }
    }

    int cur_l = 0, cur_o = 0;
    for (unsigned int i = 0; i < food.length() - 1; i++) {
        if (food[i] == 'L') {
            cur_l++;
        } else {
            cur_o++;
        }
        if (cur_l != total_l - cur_l && cur_o != total_o - cur_o) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}