// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int memo[1000];

int minCoins(int denominations[], int n, int change){
    if (change == 0){
        return 0;
    }

    if (change < 0){
        const int inf = 1e6;
        return inf;
    }

    if (memo[change] != -1){
        return memo[change];
    }

    int ans = 1e6;

    for(int i = 0; i < n; ++i){
        if (denominations[i] <= change){
            int remVal = change - denominations[i];
            int coinsReqForRemVal = minCoins(denominations, n, remVal);
            ans = min(ans, coinsReqForRemVal + 1); 
        }
    }

    memo[change] = ans; // REGISter
    
    return ans;
}



int minCoinsDP(int denominations[], int n, int change){
    int dp[100] = {};

    dp[0] = 0;
    dp[1] = 1;  // we have been provided that Re 1 always exist
    
    for(int val = 2; val <= change; ++val){
        // try picking each demonination
        int coins = 1e6;
        for(int i = 0; i < n; ++i){
            int remVal = val - denominations[i];
            if (remVal < 0) continue;

            coins = min(coins, 1 + dp[remVal]);
        }
        dp[val] = coins;
    }
    return dp[change];
}


int main(){
    int denominations[100];
    int n;
    cin >> n;
    
    for(int i = 0; i < n; ++i) cin >> denominations[i];

    int change; cin >> change;
    
    //set to -1.. clear memopad
    for(int i = 0; i <= change; ++i) memo[i] = -1;

    int ans = minCoinsDP(denominations, n, change);
    cout << ans;
}