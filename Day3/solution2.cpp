
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
	vector<string> o = arr;
	for(int j=0; j<BYTE_SIZE;j++) {
		string bit = "0";	
		vector<string> one;
		vector<string> bytes;	
		for(int i=0; i<o.size(); i++) {
			string s(1, o[i][j]);
			bytes.push_back(s);
		}
		if(count(bytes.begin(), bytes.end(), "1") >= count(bytes.begin(), bytes.end(), "0")) {
			bit = "1";
		}
		for(int l=0; l<o.size();l++) {
			string c(1, o[l][j]);	
			if(c == bit) {
					one.push_back(o[l]);
			}	
		}
		o = one;
	}
	cout << stoi(o[0], 0, 2) << endl;
	// CO2
	vector<string> n = arr;
	for(int j=0; j<BYTE_SIZE;j++) {
		string bit = "0";	
		vector<string> one;
		vector<string> bytes;	
		for(int i=0; i<n.size(); i++) {
			string s(1, n[i][j]);
			bytes.push_back(s);
		}
		if(count(bytes.begin(), bytes.end(), "1") < count(bytes.begin(), bytes.end(), "0")) {
			bit = "1";
		}
		for(int l=0; l<n.size();l++) {
			string c(1, n[l][j]);	
			if(c == bit) {
					one.push_back(n[l]);
			}	
		}
		n = one;
	}
	cout << stoi(n[0], 0, 2) << endl;
	cout << "RESULT: " << stoi(n[0], 0, 2) * stoi(o[0], 0, 2) << endl;
	return 0;
}
