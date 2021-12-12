#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph(100);
vector<bool> only_once(100, false);
unordered_map<string, int> map1;
unordered_map<int, string> map2;


bool is_lower(string s){
	for(auto a : s){
		if(!islower(a)){
			return false;
		}
	}
	return true;
}

int dfs(int src, vector<bool> visited, int twice){
	visited[src] = true;
	//path.push_back(src);
	int answer = 0;

	if(src == map1["end"]){
		return 1;
	}
	for(auto node : graph[src]){
		if(visited[node] && only_once[node]){
			if(twice == 1 || node == map1["start"]) continue;
			answer += dfs(node, visited, twice + 1);
		}
		else{
			answer += dfs(node, visited, twice);
		}
	}
	return answer;
}


int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	string input;
	int counter = 0;
	while(cin >> input){
		stringstream ss(input);
		string dummy1;
		string dummy2;

		getline(ss, dummy1, '-');
	    if(map1.find(dummy1) == map1.end()){
	    	map1[dummy1] = counter;
	    	map2[counter] = dummy1;
	    	if(is_lower(dummy1)) only_once[counter] = true;
	    	counter++;
	    }
		getline(ss, dummy2, '-');
	    if(map1.find(dummy2) == map1.end()){
	    	map1[dummy2] = counter;
	    	map2[counter] = dummy2;
	    	if(is_lower(dummy2)) only_once[counter] = true;
	    	counter++;
	    }

	    graph[map1[dummy1]].push_back(map1[dummy2]);
	    graph[map1[dummy2]].push_back(map1[dummy1]);
	}

	vector<bool> visited(100, false);
	//vector<int> path;
	int answer = dfs(map1["start"], visited, 0);
	cout << "Answer for part 2 : " << answer << endl;
}
