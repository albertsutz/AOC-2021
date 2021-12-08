#include <bits/stdc++.h>
using namespace std;

//basically implementing a hash function between a series -> integer -> number it represents	

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<int, int> mapper = {{423, 0}, {282, 1}, {283, 2}, {403, 3}, {354, 4}, {299, 5}, {323, 6}, {325, 7}, {461, 8}, {437, 9}};
	string dummy;

	int final_answer = 0;
	while(cin >> dummy){
		vector<string> inputs;
		inputs.push_back(dummy);

		for(int i = 0; i < 9; i++){
			cin >> dummy;
			inputs.push_back(dummy);
		}
		cin >> dummy;
		for(int i = 0; i < 4; i++){
			cin >> dummy;
			inputs.push_back(dummy);
		}

		vector<int> check(7, 0);

		for(int i = 0; i < 10; i++){
			for(auto j : inputs[i]){
				check[j - 'a'] += inputs[i].size();
				if(inputs[i].size() == 2){
					check[j - 'a'] += 100;
				}
			}
		}

		int value = 0;
		int multiplier = 1000;
		for(int i = 10; i < 14; i++){
			int count = 0;
			for(auto j : inputs[i]){
				count += check[j - 'a'];
			}
			value += multiplier * mapper[count];
			multiplier /= 10;
		}
		final_answer += value;
	}
	cout << "Answer for part 2: " << final_answer << endl;	
}
