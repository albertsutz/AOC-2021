#include <bits/stdc++.h>

using namespace std;

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map<char, char> validator;
    validator['{'] = '}';
    validator['['] = ']';
    validator['<'] = '>';
    validator['('] = ')';

	unordered_map<char, long long> valuer;
	valuer[')'] = 3;
	valuer[']'] = 57;
	valuer['}'] = 1197;
	valuer['>'] = 25137;

	unordered_map<char, long long> solver;
	solver['{'] = 3;
    solver['['] = 2;
    solver['<'] = 4;
    solver['('] = 1;

	stack<char> s;
	vector<long long> answer;

	string dummy;

	while(cin >> dummy){
		bool incomplete = true;
		for(auto i : dummy){
			if(i == '(' || i == '[' || i == '<' || i == '{'){
				s.push(i);
			}
			else if(s.empty()){
				break;
			}
			else{
				char j = s.top();
				s.pop();
				if(validator[j] == i) continue;
				//answer += valuer[i];
				incomplete = false;
				while(!s.empty()){
					s.pop();
				}
				break;
			}
		}

		if(!incomplete) continue;
		long long temp = 0;
		//cout << dummy << endl;
		while(!s.empty()){
			temp *= 5;
			char j = s.top();
			s.pop();
			//cout << j;
			temp += solver[j];
		}
		//cout << endl;
		answer.push_back(temp);
	}
	sort(answer.begin(), answer.end());

	cout << "Answer for part 2: " << answer[answer.size() / 2] << endl;
}
