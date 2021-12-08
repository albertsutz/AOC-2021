#include <bits/stdc++.h>

using namespace std;

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string dummy;

	int answer = 0;
	while(cin >> dummy){
		for(int i = 0; i < 10; i++){
			cin >> dummy;
		}
		for(int i = 0; i < 4; i++){
			cin >> dummy;
			switch(dummy.size()){
				case 2:
				case 4:
				case 3:
				case 7:
					answer++;
					break;
			}
		}
	}
	cout << "Answer for part 1: " << answer << endl;

}
