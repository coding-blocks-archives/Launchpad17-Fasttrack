// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
	int n;
	int r;
	cin >> n >> r;

	//n!
	int nFact = 1;
	for(int x = 1; x <= n; ++x){
		nFact = nFact * x;
	}

	//r!
	int rFact = 1;
	for(int x = 1; x <= r; ++x){
		rFact = rFact * x;
	}

	//n - r
	int nrFact = 1;
	for(int x = 1; x <= n - r; ++x){
		nrFact = nrFact * x;
	}

	//n!, r!, n-r!
	int ans = nFact / (rFact * nrFact);
	cout << ans;
}