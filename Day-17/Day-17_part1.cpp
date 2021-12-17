#include <bits/stdc++.h>

using namespace std;

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string dummy;
	int x[2];
	int y[2];

	cin >> dummy >> dummy;
	cin.ignore(); cin.ignore();cin.ignore();
	cin >> x[0]; cin.ignore(); cin.ignore();
	cin >> x[1]; cin.ignore(); cin.ignore(); cin.ignore(); cin.ignore();
	cin >> y[0]; cin.ignore(); cin.ignore();
	cin >> y[1];

	int vx = 0;
	while(!(x[0] <= vx * (vx + 1) / 2 && vx * (vx + 1) / 2 <= x[1])){
		++vx;
	}

	if (-y[0] < vx){
		cout << "NO ANSWER YET" << endl;
		return 1;
	}

	cout << "Answer for Part 1 : " << (-y[0] - 1) * (-y[0] - 1 + 1) / 2 << endl;
}
