// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int StringLen(char arr[]){
	int i = 0;
	while(arr[i] != '\0'){
		++i;
	}
	return i;
}

void StringRotate(char arr[]){
	int len = StringLen(arr);
	
	int j = len - 1;
	char last_char = arr[j];

	while(j >= 1){
		arr[j] = arr[j - 1];
		--j;
	}
	arr[0] = last_char;	
}

void KStringRotate(char arr[], int k){
	for(int i = 0; i < k; ++i){
		StringRotate(arr);
	}
}

int main(){
	char arr[100];

	cin >> arr;	// null is automatically appended
	int k;
	cin >> k;

	KStringRotate(arr,k);

	cout << arr;	
}