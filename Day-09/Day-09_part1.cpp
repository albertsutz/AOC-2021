#include <bits/stdc++.h>

using namespace std;

bool local_low(vector<string> &inputs, int i, int j, int row, int column){
	int x[4] = {-1, 1, 0, 0};
	int y[4] = {0, 0, -1, 1};

	for(int k = 0; k < 4; k++){
		int dummy_y = i + y[k];
		int dummy_x = j + x[k];
		if(dummy_y < 0 || dummy_y >= row || dummy_x < 0 || dummy_x >= column) continue;
		if(inputs[i][j] >= inputs[dummy_y][dummy_x]){
			return false;
		}
	}
	return true;
}

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int row, column;

	vector<string> inputs;
	string dummy;
	while(cin >> dummy){
		inputs.push_back(dummy);
	}
	row = inputs.size();
	column = inputs[0].size();

	int answer = 0;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			if(local_low(inputs, i, j, row, column)){
				answer += (inputs[i][j] - '0' + 1);
			} 
		}
	}

	cout << "Answer for part1: " answer << endl;
}
