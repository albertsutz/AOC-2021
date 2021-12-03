#include <bits/stdc++.h>

using namespace std;

int binary_to_int(string binary){
	int size = binary.size();
	int answer = 0;
	int counter = 0;
	for(int i = size - 1; i >= 0; i--){
		answer += ((binary[i] - '0') * pow(2, counter));
		counter++;
	}
	return answer;
}

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<string> input;
	vector<string> input2;
	string dummy;

	while(cin >> dummy){
		input.push_back(dummy);	
		input2.push_back(dummy);	
	}

	int counter = 0;
	int max = 0;

	while(input.size() > 1){
		max = 0;
		for(int i = 0; i < input.size(); i++){
			if(input[i][counter] == '1'){
				max += 1;
			}
			else{
				max -= 1;
			}
		}
		//for(auto i : input){
		//	cout << i << endl;
		//}
		//cout << max << endl << endl;
		if (max < 0) max = 0;
		else max = 1;
		for(int i = 0; i < input.size(); i++){
			if(input[i][counter] - '0' != max){
				input.erase(input.begin() + i);
				i -= 1;
			}
		}
		counter++;
	}
	counter = 0;
	while(input2.size() > 1){
		max = 0;
		for(int i = 0; i < input2.size(); i++){
			if(input2[i][counter] == '1'){
				max += 1;
			}
			else{
				max -= 1;
			}
		}
		if (max < 0) max = 1;
		else max = 0;
		for(int i = 0; i < input2.size(); i++){
			if(input2[i][counter] - '0' != max){
				input2.erase(input2.begin() + i);
				i -= 1;
			}
		}
		counter++;
	}
	cout << input.front() << endl;
	cout << input2.front() << endl;
	cout << binary_to_int(input.front()) * binary_to_int(input2.front()) << endl;
}
