#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fold(vector<vector<int>> grid, pair<char, int> instruction){
	vector<vector<int>> answer;
	if(instruction.first == 'y'){
		answer = vector<vector<int>>(instruction.second, vector<int>(grid[0].size(), 0));
		for(int i = 0; i < answer.size(); i++){
			for(int j = 0; j < answer[0].size(); j++){
				answer[i][j] = (grid[i][j] | grid[grid.size() -1 - i][j]);
			}
		}
	}
	else{
		answer = vector<vector<int>>(grid.size(), vector<int>(instruction.second, 0));
		for(int i = 0; i < answer.size(); i++){
			for(int j = 0; j < answer[0].size(); j++){
				answer[i][j] = (grid[i][j] | grid[i][grid[0].size() -1 - j]);
			}
		}
	}
	return answer;
}

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string dummy;
	vector<pair<int, int>> positions;
	vector<pair<char, int>> folds;
	int max_x = -1, max_y = -1;

	while(cin >> dummy){
		if(dummy == "fold") break;
		stringstream ss(dummy);
		int a, b; 
		ss >> a; ss.ignore(); ss >> b;

		if(a > max_x) max_x = a;
		if(b > max_y) max_y = b;
		positions.push_back({a, b});
	}

	while(cin >> dummy){
		if(dummy[0] != 'x' && dummy[0] != 'y') continue;
		stringstream ss(dummy);
		ss.ignore(); ss.ignore();
		char a; int b; a = dummy[0]; ss >> b;

		folds.push_back({a, b});
	}
	vector<vector<int>> grid(max_y + 1, vector<int>(max_x + 1, 0));
	for(auto pos : positions){
		grid[pos.second][pos.first] = 1;
	}

	for(auto i : folds){
		grid = fold(grid, i);
	}

	cout << "Answer for Part 2: " << endl;
	for(int i = 0; i < grid.size(); i++){
		for(int j = 0; j < grid[0].size(); j++){;
			if(grid[i][j]) cout << '#';
			else cout << '.';
		}
		cout << endl;
	}
}
