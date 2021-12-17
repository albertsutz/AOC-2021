#include <bits/stdc++.h>

using namespace std;

int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string dummy;
	int x[2];
	int y[2];

	cin >> dummy >> dummy;
	cin.ignore(); cin.ignore();cin.ignore();
	cin >> x[0]; cin.ignore(); cin.ignore();
	cin >> x[1]; cin.ignore(); cin.ignore(); cin.ignore(); cin.ignore();
	cin >> y[0]; cin.ignore(); cin.ignore();
	cin >> y[1];

	int biggest_vy = -y[0];
	int biggest_vx = x[1];

	int answer = 0;
	for(int i = -biggest_vy; i <= biggest_vy; i++){
		for(int j = 0; j <= biggest_vx; j++){
			int v_x = j;
			int v_y = i;
			int d_x = 0;
			int d_y = 0;

			while(d_x <= x[1] && y[0] <= d_y){
				if(x[0] <= d_x && d_x <= x[1] && y[0] <= d_y && d_y <= y[1]){
					answer++;
					//cout << j << ' ' << i << endl;
					break;
				}
				d_x += v_x;
				d_y += v_y;
				v_y--;
				if(v_x > 0) v_x--;
			}
		}
	}
	cout << "Answer for part 2 : " << answer << endl;
}
