#include <bits/stdc++.h>
//Imports library that allows to reverse a string
using namespace std;

string isPalindrome(string str)
{
	string palindrome = str;

	reverse(palindrome.begin(), palindrome.end());
	// Reverses the string

	if (str == palindrome) {
		return "It is a palindrome";
	}else {
		return "It is not a palindrome";
	}
}

int main()
{
	string str = "ABCDCBA";
    //String that is checked to be a palindrome
	cout << isPalindrome(str);

	return 0;
}
