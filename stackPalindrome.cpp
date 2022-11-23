#include<iostream>
using namespace std;

// Maximum length of string.
#define MAX 1000

class Stack{

// Using typedef for char

		typedef char ch;// Private members

	private:

		ch arr[MAX];
		int pointerSize=0;

// Public members and functions

	public:
		
// Functions

// Pushing into stack
	void push(ch c){
		if(pointerSize>=MAX){
			cout<<"Overflow!!";
			return;
		}	
		else
		arr[pointerSize++]=c;
	}	

// pop() 
	ch pop(){
		if(pointerSize==0){
			cout<<"Underflow!!";
			return ' ';
		}
	
		ch a = arr[pointerSize-1];
		pointerSize--;
		return a;
	}
	
// size() returns size
	int size(){
		return pointerSize;
	}
	
};

bool TruePalindrome(string str){
		Stack stc1,stc2;

		for(int i=0;i<str.length();i++){
			
			if((str[i]>=97 && str[i]<=122) || (str[i]>=48 && str[i]<=57))
				stc1.push(str[i]);
			else if(str[i]>=65 && str[i]<=90)
				stc1.push(str[i]+32);
		}
// Pop the characters of the first stack and
// push it to the second stack till the size
// of first stack beccomes half of the original size.
		int stc1_size=stc1.size(),stc2_size;
		for(int i=1;i<=stc1_size/2;i++){
			stc2.push(stc1.pop());
		}
		
		stc1_size=stc1.size();
		stc2_size=stc2.size();
// If one more element is present in first stack
// than the second stack then pop it.
		if(stc1_size>stc2_size)
		stc1.pop();
// If any character in the stacks mismatches then return false.
		for(int i=1;i<stc1_size;i++){
			if(stc1.pop()!=stc2.pop())
				return false;
		}
	return true;
}

int main(){
 
// Running code

	string str;
	cout<<"Enter a string -> ";
	getline(cin,str);
	
	if(TruePalindrome(str))
	cout<<"The string is a palindrome.";
		else
	cout<<"The string is NOT a palindrome.";
		return 0;
}

