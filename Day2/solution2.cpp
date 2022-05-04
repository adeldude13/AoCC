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
	int aim = 0;	
	while(getline(file, line)) {
		string s(1, line[line.size()-1]);
		switch(line[0]) {
			case 'd':
				aim += stoi(s);
				break;
			case 'u':
				aim -= stoi(s);
				break;
			case 'f':
				horz += stoi(s);
				depth += aim * stoi(s);
				break;
		}
	}
	cout << "Horz: " << horz << " Depth: " << depth << endl; 
	cout << horz * depth << endl;
}
