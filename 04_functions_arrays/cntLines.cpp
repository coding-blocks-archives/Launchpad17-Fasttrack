// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

bool isAlphabet(char c) {
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) return true;
	return false;
}

bool isDigit(char c) {
	if (c >= '0' && c <= '9') return true;
	return false;
}

bool isWhiteSpace(char c) {
	if (c == ' ' || c == '\t' || c == '\n') return true;
	return false;
}

bool isSpace(char c) {
	if (c == ' ') return true;
	return false;
}

void printCnt() {
	// printCnt reads the chars and prints the statistics
	// statistics are letters, digits, whitespaces, lines, words, spaces,
	// others like @, $, % etc....

	char c;
	int cntDigits = 0;
	int cntAlpha = 	0;
	int cntWords = 	0;
	int cntLines = 	0;
	int cntSpaces = 0;
	int whitespaces = 0;
	int others = 0;

	bool startWord = false;

	c = cin.get();
	while (c != '$') {
		// do some computation
		if (isAlphabet(c)) {
			++cntAlpha;
			startWord = true;
		}
		else if (isDigit(c)) {
			++cntDigits;
			startWord = true;
		}
		else if (isWhiteSpace(c)) {
			++whitespaces;
			if (c == '\n') ++cntLines;

			if (startWord == true) {
				++cntWords;
				startWord = false;
			}

			if (isSpace(c)) ++cntSpaces;

		}
		else {
			++others;
			startWord = true;
		}

		// read the other char
		c = cin.get();
	}

	cout << "Letters\t" << cntAlpha << endl;
	cout << "digits\t" << cntDigits << endl;
	cout << "spaces\t" << cntSpaces << endl;
	cout << "whitespaces\t" << whitespaces << endl;
	cout << "words\t" << cntWords << endl;
	cout << "lines\t" << cntLines << endl;
	cout << "others\t" << others << endl;
}

int main() {
	printCnt();
}