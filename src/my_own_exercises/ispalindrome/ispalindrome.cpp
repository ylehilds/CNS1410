#include <iostream>
using namespace std;


bool substringIsPalindrome(string s, int start, int end)
{
     // the simplest cases - substring length 1 or zero
     if (start >= end) return true;

     if (s[start] == s[end])
		return substringIsPalindrome(s, start+1, end-1);
     else
          return false;
}
bool isPalindrome(string s)
{
     return substringIsPalindrome(s, 0, s.length( ) - 1);
}
int main()

{
	string answer;
	
	do
	{
	system("cls");
	system("title Lehi's Palindrome proram test");
	system("color e");
	cout << "Please input a phrase and I will check if it s a Palindrome or not: " <<endl;
	string input;
	getline(cin, input);
	isPalindrome(input);
	if (isPalindrome(input)==1)
	{
		cout << "the phrase, " << input <<", it is a Palindrome" << endl;
	}
	else
	{
		cout << "the phrase," << input << ", it is not a palindrome" << endl;
	}
	
	cout <<"would you you linke to try again? " << endl;
	getline(cin, answer);
	}while (answer =="yes" || answer == "YES" || answer == "y" || answer == "Y" ||answer =="Yes");
	return 0;
	
}	