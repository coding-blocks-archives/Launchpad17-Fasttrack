// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

// recursive
int minSteps(int n) {
    if (n == 0) {
        return 1e6;
    }

    if (n == 1) {
        return 0;
    }

    // check ur memopad

    // compute and register
    int ans = minSteps(n - 1);

    if (n % 2 == 0) {
        int tmp = minSteps(n / 2);
        ans = min(ans, tmp);
    }

    if (n % 3 == 0) {
        int tmp = minSteps(n / 3);
        ans = min(ans, tmp);
    }

    ans  = ans + 1; // 1 operation has to be performed
    return ans;
}

int  minStepsDP(int n) {
    int* dp = new int[n + 1];
    dp[0] = 1e6;
    dp[1] = 0;

    for (int i = 2; i <= n; ++i) {
        dp[i] = 1 + dp[i - 1]; // n  - 1

        if (i % 2 == 0) {
            int tmp = 1 + dp[i / 2];
            dp[i] = min (tmp, dp[i]);
        }

        if (i % 3 == 0) {
            int tmp = 1 + dp[i / 3];
            dp[i] = min(tmp, dp[i]);
        }
    }

    int ans = dp[n];
    delete [] dp;
    return ans;
}



int main() {
    int n;
    cin >> n;
    int ans = minStepsDP(n);
    cout << ans;
}