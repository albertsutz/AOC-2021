#include <bits/stdc++.h>

using namespace std;

void print_board(vector<vector<vector<int>>> &boards){
	for(int i = 0; i < boards.size(); i++){
		for(int j = 0; j < 6; j++){
			for(int k = 0; k < 6; k++){
				cout << boards[i][j][k] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
}

vector<int> play_game(int num, vector<vector<vector<int>>> &boards){
	vector<int> winner_board;
	for(int j = 0; j < boards.size(); j++){
		for(int k = 0; k < 5; k++){
			for(int l = 0; l < 5; l++){
				if(boards[j][k][l] == num){
					boards[j][k][l] = -1;
					boards[j][k][5] += 1;
					boards[j][5][l] += 1;

					if(boards[j][k][5] == 5 || boards[j][5][l] == 5){
						winner_board.push_back(boards[j][5][5]);
					}
				}
			}
		}
	}
	return winner_board;
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
	int counter = 0;
	while(cin >> dummy){
		vector<vector<int>> board(6, vector<int>(6, 0));
		board[5][5] = counter;
		counter++;
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
	vector<int> last_winner;
	int last_number;
	for(int i = 0; i < sequence.size(); i++){
		last_winner = play_game(sequence[i], boards);
		last_number = sequence[i];
		if(last_winner.size() == 0) continue;
		if(boards.size() == 1){
			break;
		}

		for(int k = 0; k < last_winner.size(); k++){
			for(int j = 0; j < boards.size(); j++){
				if(boards[j][5][5] == last_winner[k]){
					boards.erase(boards.begin() + j);
					break;
				}
			}
		}
	}
	int answer = 0;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(boards[0][i][j] != -1){
				answer += boards[0][i][j];
			}
		}
	}
	cout << "answer for part2: " << answer * last_number << endl;
}
