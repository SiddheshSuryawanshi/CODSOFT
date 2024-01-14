#include <iostream>
#include <cstdlib>
using namespace std;

const int boardSize = 3;  // Customize the board size here

char board[boardSize][boardSize] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
char player1 = 'X', player2 = 'O';
char currentPlayer = player1;

void displayBoard() {
    // Display the current state of the board
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cout << board[i][j];
            if (j < boardSize - 1) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < boardSize - 1) {
            for (int k = 0; k < 4 * boardSize - 1; k++) {
                cout << "-";
            }
            cout << endl;
        }
    }
    cout << endl;
}

bool checkWin() {
    // Check for a win in rows and columns
    for (int i = 0; i < boardSize; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;  // Win in a row
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;  // Win in a column
        }
    }
    // Check for a win in diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;  // Win in the main diagonal
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;  // Win in the other diagonal
    }
    return false;
}

bool checkDraw() {
    // Check if the board is full, indicating a draw
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == ' ') {
                return false;  // There is an empty space, the game is not a draw yet
            }
        }
    }
    return true;  // The board is full, indicating a draw
}

void switchPlayer() {
    // Alternate turns between players
    currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

void updateBoard(int row, int col) {
    // Update the board with the player's move
    board[row][col] = currentPlayer;
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    
    while (true) {
        cout << "New Game!" << endl;
        displayBoard();
        
        while (true) {
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row, col): ";
            cin >> row >> col;
            
            if (row < 1 || row > boardSize || col < 1 || col > boardSize || board[row - 1][col - 1] != ' ') {
                cout << "Invalid move. Try again." << endl;
            } else {
                updateBoard(row - 1, col - 1);
                displayBoard();
                
                if (checkWin()) {
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break;
                }
                if (checkDraw()) {
                    cout << "It's a draw!" << endl;
                    break;
                }
                
                switchPlayer();
            }
        }
        
        char playAgain;
        cout << "Play again? (y/n): ";
        cin >> playAgain;
        
        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    }
    
    cout << "Thanks for playing! Goodbye." << endl;
    return 0;
}
