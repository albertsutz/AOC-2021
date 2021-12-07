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

	// sort(inputs.begin(), inputs.end());
	// for(auto i : inputs){
	// 	cout << i << endl;
	// }

	// int middle = inputs.size() / 2;
	float sum = 0.0;
	for(int i = 0; i < inputs.size(); i++){
		sum += inputs[i];
	}
	int rounded = round(sum / inputs.size());
	
	int answer = 0;
	int answer1 = 0;
	int answer2 = 0;
	//cout << rounded << endl;
	for(int i = 0; i < inputs.size(); i++){
		//cout << answer << endl;
		int difference = abs(rounded - inputs[i]);
		answer += ((difference * (difference + 1)) / 2);
	}
	for(int i = 0; i < inputs.size(); i++){
		//cout << answer << endl;
		int difference = abs(rounded - 1 - inputs[i]);
		answer1 += ((difference * (difference + 1)) / 2);
	}
	for(int i = 0; i < inputs.size(); i++){
		//cout << answer << endl;
		int difference = abs(rounded + 1 - inputs[i]);
		answer2 += ((difference * (difference + 1)) / 2);
	}
	cout << answer << endl; 
	cout << answer1 << endl;
	cout << answer2 << endl;
}
