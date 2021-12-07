#include <bits/stdc++.h>

using namespace std;

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> inputs;
	int a;
	while(cin >> a){
		cin.ignore();
		inputs.push_back(a);
	}

	sort(inputs.begin(), inputs.end());
	int middle = inputs.size() / 2;
	int answer = 0;

	for(int i = 0; i < inputs.size(); i++){
		answer += abs(inputs[middle] - inputs[i]);
	}
	cout << "The answer for part 1: " answer << endl;
}
