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

bool IsPalindrome(char arr[]){
	int len = StringLen(arr);
	int start_idx = 0;
	int end_idx = len - 1;

	while(start_idx < end_idx){
		if (arr[start_idx] != arr[end_idx]) return false;
		++start_idx;
		--end_idx;
	}
	return true;
}

int main(){
	char arr[100];

	cin >> arr;	// null is automatically appended

	bool ans = IsPalindrome(arr);

	cout << ans;	
}