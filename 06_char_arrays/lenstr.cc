// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void InputStr(char arr[]){
	int i = 0;
	while (i < 100){
		char x;
		// cin >> x;
		x = cin.get();

		if (x != '\n') {
			arr[i] = x;
		}
		else {
			break;
		}
		++i;
	}
	arr[i] = '\0';
}

int StringLen(char arr[]){
	int i = 0;
	while(arr[i] != '\0'){
		++i;
	}
	return i;
}


int main(){
	char arr[100];

	InputStr(arr);

	int len = StringLen(arr);

	cout << len;
	
}