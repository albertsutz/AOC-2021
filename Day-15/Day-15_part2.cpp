#include <bits/stdc++.h>

using namespace std;

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> dummy_grid;

	string dummy;
	while(cin >> dummy){
		vector<int> test;
		for(auto i : dummy){
			test.push_back(i - '0');
		}
		dummy_grid.push_back(test);
	}
	int size = dummy_grid.size() * 5;

	vector<vector<int>> grid(size, vector<int>(size));

	for(int i = 0; i < dummy_grid.size(); i++){
		for(int j = 0; j < dummy_grid.size(); j++){
			grid[i][j] = dummy_grid[i][j];
		}
	}
	for(int i = 0 ; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(i == 0 && j == 0) continue;
			for(int k = 0; k < size / 5; k++){
				for(int l = 0; l < size / 5; l++){
					int value = (grid[k][l] + i + j);
					if(value > 9) value -= 9;
					grid[i * size / 5 + k][j * size / 5 + l] = value;
				}
			}
		}
	}

	vector<vector<bool>> visited(size, vector<bool>(size, false));
	vector<vector<int>> distance(size, vector<int>(size, -1));

	typedef pair<int, pair<int, int>> pi;
	priority_queue<pi, vector<pi>, greater<pi>> pq;

	pq.push({0, {0, 0}});


	int counter = 0;
	while(!pq.empty()){
		pi current = pq.top();
		pq.pop();

		if(visited[current.second.first][current.second.second]) continue;
		visited[current.second.first][current.second.second] = true;
		distance[current.second.first][current.second.second] = current.first;


		if(current.second.first == size - 1 && current.second.second == size - 1){
			break;
		}


		int dir_x[4] = {-1, 1, 0, 0};
		int dir_y[4] = {0, 0, -1, 1};

		for(int i = 0; i < 4; i++){
			int next_y = current.second.first + dir_y[i];
			int next_x = current.second.second + dir_x[i];

			if(next_x < 0 || next_y < 0 || next_x >= size || next_y >= size) continue;
			if(visited[next_y][next_x]) continue;
			pq.push({current.first + grid[next_y][next_x], {next_y, next_x}});
		}
	}

	cout << "Answer for Part 2: " << distance[size - 1][size - 1] << endl;
}
