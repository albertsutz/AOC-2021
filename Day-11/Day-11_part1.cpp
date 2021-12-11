#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;

int dfs(int i, int j, vector<vector<bool>> &exploded){
	exploded[i][j] = true;
	grid[i][j] = 0;

	int dir_x[3] = {-1, 0, 1};
	int dir_y[3] = {-1, 0, 1};

	int flashes = 1;

	for(int a = 0; a < 3; a++){
		for(int b = 0; b < 3; b++){
			int dummy_y = i + dir_y[a];
			int dummy_x = j + dir_x[b];
			if(dummy_y < 0 || dummy_x < 0 || dummy_y >= grid.size() || dummy_x >= grid.size()) continue;
			if(exploded[dummy_y][dummy_x]) continue;
			grid[dummy_y][dummy_x]++;
			if(grid[dummy_y][dummy_x] > 9){
				flashes += dfs(dummy_y, dummy_x, exploded);
			}
		}
	}
	return flashes;	
}

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string dummy;
	while(cin >> dummy){
		vector<int> row;
		for(auto i : dummy){
			row.push_back(i - '0');
		}
		grid.push_back(row);
	}

	int step = 100;
	int answer = 0;
	while(step--){
		int flashes = 0;
		vector<vector<bool>> exploded(grid.size(), vector<bool>(grid.size(), false));
		for(int i = 0; i < grid.size(); i++){
			for(int j = 0; j < grid.size(); j++){
				grid[i][j]++;
			}
		}

		for(int i = 0; i < grid.size(); i++){
			for(int j = 0; j < grid.size(); j++){
				if(exploded[i][j]) continue;
				if(grid[i][j] <= 9) continue;
				flashes += dfs(i, j, exploded);
			}
		}
		cout << "flashes: " << flashes << endl;
		answer += flashes;
	}	
	cout << "Answer for part 1: " << answer << endl;
}
