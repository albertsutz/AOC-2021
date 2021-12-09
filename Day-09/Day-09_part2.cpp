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

int dfs(vector<string> &inputs, vector<vector<bool>> &visited, int i, int j, int row, int column){
	visited[i][j] = true;
	int x[4] = {-1, 1, 0, 0};
	int y[4] = {0, 0, -1, 1};

	int answer = 1;
	for(int k = 0; k < 4; k++){
		int dummy_y = i + y[k];
		int dummy_x = j + x[k];
		if(dummy_y < 0 || dummy_y >= row || dummy_x < 0 || dummy_x >= column) continue;
		if(visited[dummy_y][dummy_x]) continue;
		if(inputs[i][j] < inputs[dummy_y][dummy_x] && inputs[dummy_y][dummy_x] != '9'){
			answer += dfs(inputs, visited, dummy_y, dummy_x, row, column);
		}
	}
	return answer;
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

	int answer = 1;
	int largest[3] = {-1, -1, -1};
	vector<vector<bool>> visited(row, vector<bool>(column, false));
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			if(local_low(inputs, i, j, row, column)){
				int dummy = dfs(inputs, visited, i, j, row, column);
				if(dummy > largest[2]){
					largest[0] = largest[1];
					largest[1] = largest[2];
					largest[2] = dummy;
				} else if (dummy > largest[1]){
					largest[0] = largest[1];
					largest[1] = dummy;
				} else if(dummy > largest[0]){
					largest[0] = dummy;
				}
			}
		}
	}
	for(int i = 0; i < 3; i++){
		answer *= largest[i];
	}
	cout << "Answer for part2: " answer << endl;
}
