// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int memo[100][100];

int maxProfit(int bottles[], int be, int en, int yr){
    if (be > en){
        return 0;
    }

    if (memo[be][en] != -1) return memo[be][en];

    int ans1 = yr * bottles[be] + maxProfit(bottles, be + 1, en, yr + 1);
    int ans2 = yr * bottles[en] + maxProfit(bottles, be, en - 1, yr + 1);
    return memo[be][en] = max(ans1, ans2);
}

int main(){
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            memo[i][j] = -1;
        }
    }
    int bottles[] = {2,3,5,1,4};
    int n = 5;
    cout << maxProfit(bottles, 0, 4, 1);   
}