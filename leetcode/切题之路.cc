#include <iostream>
#include <vector>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, a, b;
    i64 t;
    std::cin >> n >> t >> a >> b;

    std::vector<i64> time(n), diff(n);

    for (int i = 0; i < n; i++) {
        std::cin >> time[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> diff[i];
    }

    i64 restTime1 = t, restTime2 = t;
    int ans1 = 0, ans2 = 0;

    for (int i = 0; i < n; i++) {
        //circle
        if (diff[i] < a) {
            if (restTime1 >= time[i]) {
                restTime1 -= time[i];
                ans1++;
            }
        }

        //rqy
        if (diff[i] >= b) {
            if (restTime2 >= time[i] * 2) {
                restTime2 -= time[i] * 2;
                ans2++;
            }
        } else {
            if (restTime2 >= time[i]) {
                restTime2 -= time[i];
                ans2++;
            }
        }
    }

    std::cout << ans1 << " " << ans2 << "\n";
}
