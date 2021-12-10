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

	unordered_map<char, int> valuer;
	valuer[')'] = 3;
	valuer[']'] = 57;
	valuer['}'] = 1197;
	valuer['>'] = 25137;

	stack<char> s;
	int answer = 0;;

	string dummy;
	while(cin >> dummy){
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
				answer += valuer[i];
				break;
			}
		}
	}
	cout << "Answer for part 1: " << answer << endl;
}
