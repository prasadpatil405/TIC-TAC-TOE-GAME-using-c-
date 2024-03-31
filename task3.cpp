#include <iostream>
using namespace std;

char board[3][3];
void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool isBoardFull() {
    bool isFull = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                isFull = false;
            }
        }
    }
    return isFull;
}

bool checkWin(char player) {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

int main() {
    int row, col;
    char currentPlayer = 'X';
    bool playAgain = true;

    while (playAgain) {
        initBoard();
        while (true) {
            system("clear");
            drawBoard();
            if (checkWin(currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }
            if (isBoardFull()) {
                cout << "It's a draw!" << endl;
                break;
            }
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
            if (row > 3 || row < 1 || col > 3 || col < 1) {
                cout << "Invalid input, try again." << endl;
            } else {
                row--;
                col--;
                if (board[row][col] == ' ') {
                    board[row][col] = currentPlayer;
                    currentPlayer = (currentPlayer == 'X' ? 'O' : 'X');
                } else {
                    cout << "Cell is already occupied, try again." << endl;
                }
            }
        }
        cout << "Do you want to play again? (yes/no) ";
        char response;
        cin >> response;
        if (response == 'n' || response == 'N') {
            playAgain = false;
        }
    }

    return 0;
}