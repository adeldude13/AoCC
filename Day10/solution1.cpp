#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <inttypes.h>

using namespace std;

int check(char c) {
	if(c == '>') {
		return 4;
	}
	if(c == ')') {
		return 1;
	}
	if(c == ']') {
		return 2;
	}
	return 3;
}


int main(int argc, char **argv) {
	if(argc != 2) {
		return 1;
	}
 	ifstream file(argv[1]);
	string line;	
	vector<uint64_t> sums;	
A:
	while(getline(file, line)) {
		stack<char> st;
		for(int i=0; i<line.size();i++) {
			char c = line[i];
			switch(line[i]) {
				case '<':
				case '(':
				case '{': 
				case '[':
					st.push(c);
					break;
			}
			switch(line[i]) {
				case '>':
					if(st.empty() || st.top() != '<') { goto A;}
					else {st.pop();}
					break;
				case ')':
					if(st.empty() || st.top() != '(') { goto A;}
					else {st.pop();}
					break;
				case '}':
					if(st.empty() || st.top() != '{') { goto A;}
					else {st.pop();}
					break;
				case ']':
					if(st.empty() || st.top() != '[') { goto A;}
					else {st.pop();}
					break;
			}
			if(i + 1 == line.size()) {
				uint64_t sum = 0;	
				while(!st.empty()) {
					char val = st.top();
					st.pop();
					sum *= 5;
					if(val == '(') {
						val = ')';
					}
					if(val == '{') {
						val = '}';
					}

					if(val == '[') {
						val = ']';
					}
					if(val == '<') {
						val = '>';
					}
					sum += check(val);	
				}
				sums.push_back(sum);
			}
		}
	}
	for(int i=0; i<sums.size();i++) {
		int s = 0;
		int b = 0;
		for(int j=0; j<sums.size();j++) {
			if(j != i) {
				s += sums[i] > sums[j] ? 1 : 0;
				b += sums[i] < sums[j] ? 1 : 0;
			}
		}
		if(b == s) {
			cout << sums[i] << endl;
		}
	}
	return 0;
}
