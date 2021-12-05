#include <bits/stdc++.h>

using namespace std;

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//process each line, put it inside a, b, c, d
	vector<vector<int>> storage;
	string dummy;
	int a, b, c, d;
	int max_x = 0, max_y = 0;

	while(cin >> dummy){
		stringstream ss1(dummy);
		ss1 >> a; ss1.ignore(); ss1 >> b;
		cin >> dummy >> dummy;
		stringstream ss2(dummy);
		ss2 >> c; ss2.ignore(); ss2 >> d;

		if(a == c || b == d){
			storage.push_back({a, b, c, d});
		}
		if(a > max_x) max_x = a;
		if(c > max_x) max_x = c;
		if(b > max_y) max_y = b;
		if(d > max_y) max_y = d;
	}

	//make grid and draw the map
	vector<vector<int>> grid(max_y + 1, vector<int>(max_x + 1, 0));
	int answer = 0;

	for(auto edge : storage){
		a = edge[0];
		b = edge[1];
		c = edge[2];
		d = edge[3];
		if(a == c){
			for(int i = b; i <= d; i++){
				grid[i][a]++;
			}
			for(int i = d; i <= b; i++){
				grid[i][a]++;
			}
		}
		else{
			for(int i = a; i <= c; i++){
				grid[b][i]++;
			}
			for(int i = c; i <= a; i++){
				grid[b][i]++;
			}
		}
	}


	//get the overlapping hydrothermal vents
	for(auto i : grid){
		for(auto j : i){
			if(j > 1) answer++;
		}
	}
	cout << "Answer for part 1: " << answer << endl;
}
