#include <vector>
#include <iostream>
#include <fstream>
#include <inttypes.h>
#include <string>
#include <bits/stdc++.h>

#define BYTE_SIZE 12 

using namespace std;


int main(int argc, char **argv) {	
	if(argc != 2) {
		return 1;
	}
	vector<string> arr;
	ifstream file(argv[1]);
	string line;
	while(getline(file, line)) {
		arr.push_back(line);
	}
	uint16_t ep = 0;
	uint16_t gamma = 0;
	for(int j=0; j<BYTE_SIZE; j++) {	
		string common = "0";
		vector<string> bytes;	
		for(int i=0; i<arr.size(); i++) {
			string s(1, arr[i][j]);
			bytes.push_back(s);
		}
		if(count(bytes.begin(), bytes.end(), "1") > count(bytes.begin(), bytes.end(), "0")) {
			common = "1";
		}
		gamma |= (stoi(common) << (BYTE_SIZE - j - 1));
		ep |= ((!stoi(common)) << (BYTE_SIZE - j - 1));
	}
	cout << gamma << " " << ep << endl;
	cout << "Answer : " << ep * gamma << endl;
	return 0;
}
