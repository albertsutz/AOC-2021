#include <bits/stdc++.h>

using namespace std;

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> grid;

	string dummy;
	while(cin >> dummy){
		vector<int> test;
		for(auto i : dummy){
			test.push_back(i - '0');
		}
		grid.push_back(test);
	}
	int size = grid.size();

	vector<vector<bool>> visited(size, vector<bool>(size, false));
	vector<vector<int>> distance(size, vector<int>(size, -1));

	typedef pair<int, pair<int, int>> pi;
	priority_queue<pi, vector<pi>, greater<pi>> pq;

	pq.push({0, {0, 0}});


	//int counter = 0;
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

	cout << "Answer for Part 1: " << distance[size - 1][size - 1] << endl;
}
