#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct man {
	int _gender;
	int _height;
	int _weight;
};

string girl(man baby) {
	string advice;
	
	if (baby._height > 129) {
		advice += "ni li hai!";
	} else if (baby._height == 129) {
		advice += "wan mei!";
	} else {
		advice += "duo chi yu!";
	}
	advice += " ";
	if (baby._weight > 25) {
		advice += "shao chi rou!";
	} else if (baby._weight == 25) {
		advice += "wan mei!";
	} else {
		advice += "duo chi rou!";
	}
	
	return advice;
}

string boy(man baby) {
	string advice;
	
	if (baby._height > 130) {
		advice += "ni li hai!";
	} else if (baby._height == 130) {
		advice += "wan mei!";
	} else {
		advice += "duo chi yu!";
	}
	advice += " ";
	if (baby._weight > 27) {
		advice += "shao chi rou!";
	} else if (baby._weight == 27) {
		advice += "wan mei!";
	} else {
		advice += "duo chi rou!";
	}
	
	return advice;
}

int main() {
	int n;
	man baby;
	vector<man> arr;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> baby._gender;
		cin >> baby._height;
		cin >> baby._weight;
		
		arr.push_back(baby);
	}
	
	int MAX = arr.size();
	
	for (int i = 0; i < MAX; i++) {
		if (arr[i]._gender == 1) {
			cout << boy(arr[i]) << endl; 
		} else {
			cout << girl(arr[i]) << endl;
		}
	} 
	
	
	return 0;
} 