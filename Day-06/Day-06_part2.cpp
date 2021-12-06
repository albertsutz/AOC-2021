#include <bits/stdc++.h>

using namespace std;

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<long long> lanternfish(9, 0);

	long long dummy;
	while(cin >> dummy){
		cin.ignore();
		lanternfish[dummy]++;
	}

	long long days = 257;
	while(--days){
		vector<long long> new_lanternfish(9);
		for(long long i = 0; i < 8; i++){
			new_lanternfish[i] = lanternfish[i + 1];
		}
		new_lanternfish[6] += lanternfish[0];
		new_lanternfish[8] = lanternfish[0];
		lanternfish = new_lanternfish;
	}

	long long answer = 0;
	for(auto i : lanternfish){
		answer += i;
	}
	cout << "Answer for part 2: " << answer << endl;
}
