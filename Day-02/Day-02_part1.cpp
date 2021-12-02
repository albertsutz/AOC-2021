#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    string direction;
    int dummy;
    int horizontal = 0;
    int vertical = 0;

    while (cin >> direction) {
    	cin >> dummy;

    	//using switch case so i can know the syntax better
    	switch(direction[0]) {
    		case 'f':
    			horizontal += dummy;
    			break;
    		case 'd':
    			vertical -= dummy;
    			break;
    		case 'u':
    			vertical += dummy;
    			break;
    	}
    }

    cout << "Answer for part 1: " << horizontal * -vertical << endl;


}
