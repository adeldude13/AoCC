#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char **argv) {
	if(argc != 2) {
		return 1;
	}
	ifstream file(argv[1]);
	string line;
	int depth = 0;
	int horz = 0;
	while(getline(file, line)) {
		string s(1, line[line.size()-1]);
		switch(line[0]) {
			case 'd':
				depth += stoi(s);
				break;
			case 'u':
				depth -= stoi(s);
				break;
			case 'f':
				horz += stoi(s);
				break;
		}
	}
	cout << "Horz: " << horz << " Depth: " << depth << endl; 
	cout << horz * depth << endl;
}
