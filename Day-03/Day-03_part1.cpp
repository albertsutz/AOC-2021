#include <bits/stdc++.h>

using namespace std;

int binary_to_int(vector<int> binary){
	int size = binary.size();
	int answer = 0;
	int counter = 0;
	for(int i = size - 1; i >= 0; i--){
		answer += ((binary[i]) * pow(2, counter));
		counter++;
	}
	return answer;
}

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string current;
	cin >> current;
	int size = current.size();
	vector<int> gamma(size, 0);
	vector<int> epsilon(size, 0);

	for(int i = 0; i < size; i++){
		if(current[i] == '1'){
			gamma[i]++;
		}
		else{
			gamma[i]--;
		}
	}
	while(cin >> current){
		for(int i = 0; i < size; i++){
			if(current[i] == '1'){
				gamma[i]++;
			}
			else{
				gamma[i]--;
			}
		}
	}

	for(int i = 0; i < size; i++){
		if(gamma[i] > 0){
			gamma[i] = 1;
			epsilon[i] = 0;
		}
		else{
			gamma[i] = 0;
			epsilon[i] = 1;
		}
	}
	cout << binary_to_int(gamma) * binary_to_int(epsilon) << endl;

}
