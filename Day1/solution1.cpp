#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
	if(argc != 2) {
		return 1;
	}
	ifstream file(argv[1]);	
	string line, prev;
	getline(file, prev);
	int count = 0;
	while(getline(file, line)) {
		if(stoi(line) > stoi(prev)) count++;
		prev = line;
	}
	cout << count << endl;
	return 0;
}
