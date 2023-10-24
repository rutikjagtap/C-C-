#include <iostream>
#include <vector>

// Function to display the Tic-Tac-Toe board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            std::cout << board[row][col];
            if (col < 2) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (row < 2) {
            std::cout << "---------" << std::endl;
        }
    }
    std::cout << std::endl;
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;  // Check row
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;  // Check column
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;  // Check diagonal from top-left to bottom-right
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;  // Check diagonal from top-right to bottom-left
    }
    return false;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    bool gameWon = false;
    bool gameDraw = false;

    std::cout << "Tic-Tac-Toe Game" << std::endl;

    while (true) {
        displayBoard(board);

        int row, col;
        do {
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;
        } while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ');

        board[row - 1][col - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            gameWon = true;
        } else {
            // Check for a draw
            gameDraw = true;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        gameDraw = false;
                        break;
                    }
                }
                if (!gameDraw) {
                    break;
                }
            }
        }

        if (gameWon || gameDraw) {
            displayBoard(board);
            if (gameDraw) {
                std::cout << "It's a draw!" << std::endl;
            }

            char playAgain;
            std::cout << "Do you want to play again? (y/n): ";
            std::cin >> playAgain;
            if (playAgain != 'y' && playAgain != 'Y') {
                break;
            } else {
                // Reset the game for a new round
                board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
                currentPlayer = 'X';
                gameWon = false;
                gameDraw = false;
            }
        } else {
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
