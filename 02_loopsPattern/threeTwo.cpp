#include <iostream>
using namespace std;
int main (){
	int N;
	cin >> N;

	for (int x = 0; x < N; ++x){
		if ((x % 2 == 0) || (x % 3 == 0)){
			cout << x << " ";
		}
	}
}




/*{
	int n, i;
	cin >> n;
	for (i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			cout << i << endl;
		}
		else if (i % 3 == 0)
		{
			cout << i << endl;
		}
	}
}*/
