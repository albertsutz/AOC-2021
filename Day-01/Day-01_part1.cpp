#include <bits/stdc++.h>

using namespace std;

int main() {
	int prev = INT_MAX;
	int counter = 0;
	int current = 0;

	while(cin >> current) {
		if (current > prev) {
			counter++;
		}
		prev = current;
	}
	cout << "Answer for Part 1: " counter << endl;
}