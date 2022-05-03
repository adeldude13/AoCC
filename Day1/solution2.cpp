#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#define LETTERS 26
#define SIZE 2000

using namespace std;

int main(int argc, char **argv) {
	if(argc != 2) {
		return 1;
	}
	ifstream file(argv[1]);	
	string line;	
	vector<int> arr;	
	int count = 0;
	while(getline(file, line)) {
		arr.push_back(stoi(line));	
	}
	int prev = 10000;
	for(int i=0; i<3; i++) {
		prev += arr[i];
	}
	int curr = 0;
	int j=0;
	while(j<arr.size()) {	
		for(int l=0; l<LETTERS;l++) {
			curr = 0;	
			for(int i=j; i<j+3; i++) {
				curr += arr[i];	
			}
			if(j >= arr.size()) {
				break;
			}
			if(curr > prev) {
				count++;
			}
			j++;
			prev = curr;		
		}
	}
	cout << count << endl;
	return 0;
}
