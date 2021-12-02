#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    string direction;
    long dummy;
    long horizontal = 0;
    long vertical = 0;
    long aim = 0;

    while (cin >> direction) {
    	cin >> dummy;

    	//using switch case so i can know the syntax better
    	switch(direction[0]) {
    		case 'f':
    			horizontal += dummy;
    			vertical += dummy * aim;
    			break;
    		case 'd':
    			aim += dummy;
    			break;
    		case 'u':
    			aim -= dummy;
    			break;
    	}
    }

    cout << "Answer for part 1: " << horizontal * vertical << endl;


}
