
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> removeSpaces(vector<string> arr) {
	vector<string> ret;
	for(int i=0; i<arr.size();i++) {
		if(arr[i] != "") ret.push_back(arr[i]);
	}
	return ret;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

typedef struct {
	int x1;
	int y1;
	int x2;
	int y2;
} Point;


int main(int argc, char **argv) {
	if(argc != 2) {
		return 1;
	}
	unordered_map<string, int> umap;
	string line;
	ifstream file(argv[1]);
	vector<Point> arr;	
	while(getline(file, line)) {
		vector<string> temp;
  	boost::split(temp, line, boost::is_any_of(" -> "));
		temp = removeSpaces(temp);
		vector<int> points;
		for(int i=0; i<temp.size();i++) {
			vector<string> temp2;
  		boost::split(temp2, temp[i], boost::is_any_of(","));
			for(int j=0; j<temp2.size(); j++) {
				points.push_back(stoi(temp2[j]));
			}
		}
		Point p;
		p.x1 = points[0];
		p.y1 = points[1];
		p.x2 = points[2];
		p.y2 = points[3];
		arr.push_back(p);
	}
	

	for(int i=0; i<arr.size();i++) {
			Point p = arr[i];
			int maxp;
			int minp;
			string val;


			if(p.x1 == p.x2) {
				// handle y1 or y2
				maxp = max(p.y1, p.y2);
				minp = min(p.y1, p.y2);
				int x = p.x1; 
				while(minp <= maxp) { 
					// y first then x
					val = to_string(minp) + "-" + to_string(x);
					if(umap.find(val) == umap.end()) {
						umap[val] = 1;	
					} else {
						umap[val] += 1;
					}
					minp++;
				}

			} else if(p.y1 == p.y2) {
					// handle x1 or x2
					maxp = max(p.x1, p.x2);
					minp = min(p.x1, p.x2);
					while(minp <= maxp) {
						val = to_string(p.y1) + "-" + to_string(minp);
						if(umap.find(val) == umap.end()) {
							umap[val] = 1;	
						} else {
							umap[val] += 1;
						}
						minp++;
			}
		}
	}
	int count = 0;
  for (auto it = umap.cbegin(); it != umap.cend(); ++it) {
      std::cout << "{" << (*it).first << ": " << (*it).second << "}\n";
			if((*it).second > 1) {
				count++;
			}
  }
	std::cout << count << endl;
	return 0;
}
