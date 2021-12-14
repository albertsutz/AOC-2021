#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> addition;
unordered_map<char, long long> counter;
unordered_map<string, long long> pairs;

void step(){
	unordered_map<string, long long> new_pairs;
	for(auto i : addition){
		if(pairs.find(i.first) == pairs.end()) continue;
		counter[i.second[0]] += pairs[i.first];

		string dummy = "";
		dummy += i.first[0]; dummy += i.second;
		new_pairs[dummy]+= pairs[i.first];
		dummy = ""; dummy += i.second; dummy += i.first[1];
		new_pairs[dummy]+= pairs[i.first];
		new_pairs[i.first]-= pairs[i.first];
	}	
	for(auto i : new_pairs){
		pairs[i.first] += i.second;
	}
}

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string dummy;
	cin >> dummy;
	//cout << dummy << endl;
	for(auto i : dummy){
		counter[i]++;
	}

	for(long long i = 0; i < dummy.size() - 1; i++){
		string s1 = "";
		s1 += dummy[i]; s1 += dummy[i + 1];
		pairs[s1]++;
	}

	while(cin >> dummy){
		string value;
		cin >> value >> value;
		addition[dummy] = value;
	}

	for(long long i = 0; i < 40; i++){
		step();
	}

	long long min = LLONG_MAX;
	long long max = -1;
	for(auto i : counter){
		if (i.second < min) min = i.second;
		if (i.second > max) max = i.second;
	}

	cout << min << ' ' << max << endl;
	cout << "Answer for Part 2 : " << max - min << endl;
}