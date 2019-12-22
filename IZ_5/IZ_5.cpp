#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	ifstream in("input.txt");
	if (in.is_open()) {
		vector <string> strings;
		string line;
		int k = 0;
		while (!getline(in, line).eof()) {
			strings.push_back(line);
			k++;
		}
		strings.push_back("nullstring");
		k++;
	

		ofstream output;
		output.open("output.txt");

		for (int i = 0; i < (k - 1); i++) {
			if (strings[i] == strings[i + 1]) {
				int m = 1;
				//output << endl << i << " " << k << endl;
				output << "repeated string: " << strings[i]
				   	<< "; number of the first string of the group: " << i + 1;
				do {
					m++;
					i++;
					//output << endl << i << " " << k << endl;
				} while ((strings[i] == strings[i + 1]) && (i < k - 1));
				output << "; number of strings: " << m << "\n\n";
			}
		}
	}
	else {
		cout << "File doesn't exist";
	}

	system("pause");
	return 0;
}
