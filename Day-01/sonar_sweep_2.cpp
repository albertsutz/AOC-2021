#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	int current;
	int counter = 0;

	cout << a << " " << b << " " << c << endl;
	while (cin >> current) {
		if (current > a) {
			counter++;
		}
		a = b; b = c; c = current;
		//uncomment line 19 if you want to know all the triplets
		//cout << a << " " << b << " " << c << endl;
	}
	cout << "Answer for Part 2: " << counter << endl;
}