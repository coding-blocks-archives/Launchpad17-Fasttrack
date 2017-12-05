#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;

	int cur_num = 0;
	int lar_num = -1000000000;		// -infinity as sentinel

	int cnt = 0;	//No of nos read so far
	while(cnt < N){
		cin >> cur_num;
		if (cur_num > lar_num){
			lar_num = cur_num;
		}
		// cnt = cnt + 1;
		++cnt;
	}	

	cout << lar_num << endl;
}