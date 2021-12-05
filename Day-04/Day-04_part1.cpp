#include <bits/stdc++.h>

using namespace std;

int play_game(int num, vector<vector<vector<int>>> &boards){
	int winner_board = -1;
	for(int j = 0; j < boards.size(); j++){
		for(int k = 0; k < 5; k++){
			for(int l = 0; l < 5; l++){
				if(boards[j][k][l] == num){
					//cout << j << ' ' << k << ' ' << l << endl;
					boards[j][k][l] = -1;
					boards[j][k][5] += 1;
					boards[j][5][l] += 1;

					if(boards[j][k][5] == 5 || boards[j][5][l] == 5){
						winner_board = j;
						return winner_board;
					}
				}
			}
		}
	}
	return -1;
}


int main(){
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//get sequences of bingo numbers
	string first;
	cin >> first;
	vector<vector<vector<int>>> boards;

	//get the boards
	int dummy;
	while(cin >> dummy){
		vector<vector<int>> board(6, vector<int>(6, 0));
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				if(dummy != -1){
					board[i][j] = dummy;
					dummy = -1;
				} else{
					cin >> board[i][j];
				}
			}
		}
		boards.push_back(board);
	}

	//turn bingo inputs to vector
	vector<int> sequence;
	stringstream ss(first);
	while(ss >> dummy){
		sequence.push_back(dummy);
		if(ss.peek() == ','){
			ss.ignore();
		}
	}

	//play game
	int winner;
	int last_number;
	for(int i = 0; i < sequence.size(); i++){
		winner = play_game(sequence[i], boards);
		if(winner == -1) continue;
		last_number = sequence[i];
		break;
	}

	int answer = 0;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(boards[winner][i][j] != -1){
				answer += boards[winner][i][j];
			}
		}
	}
	cout << answer * last_number << endl;
}
