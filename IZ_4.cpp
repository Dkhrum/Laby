#include <iostream>
#include <string.h>
#include <cstring>
#include <cctype>

using namespace std;


int StrLen(char* c_str){
	int count = 0;
	while (*c_str++) ++count;
	return count;
}

int StrCSpn(char* s1, char* s2){
	int len1 = StrLen(s1);
	int len2 = StrLen(s2);
	int i;
	for (i = 0; i < len1; i++)
		for (int j = 0; j < len2; j++)
			if (s1[i] == s2[j]) return i;
	return i;
}

int main() {
	char s1[100];
	char s2[100];
	cout << "Enter the first line\n";
	cin.get(s1, 100);
	cin.get();
	cout << "Enter the second line\n";
	cin.get(s2, 100);
	cin.get();
	cout << "\n\nYou entered:\n" << s1 << endl << s2 << endl << endl;
	cout << "The result of StrCSpn work:\n";
	cout << StrCSpn(s1, s2) << endl << endl;



	char ch, str[300];
	cin.get(str, 300);
	int i = 0;
	while (i < StrLen(str)) {
		ch = str[i];
		if (islower((unsigned char)ch) && i == 0) {
			ch = toupper(ch);
		}
		else if ((unsigned char)ch == ' ') {
			cout << ch;
			i++;
			ch = str[i];
			if (islower(ch)) {
				ch = toupper(ch);
			}
			else if ((unsigned char)ch == ' ') 
				continue;
		}
		cout << ch;              
		i++;                                   
	}

	return 0;
}