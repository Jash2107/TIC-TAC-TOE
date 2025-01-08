Tic Tac Toe Game in C

This repository contains a simple **Tic Tac Toe** game written in **C**. The game is designed for two players and runs in the terminal.

# Features

- A 3x3 game board that updates dynamically.
- Players take turns marking their cells using `X` and `O`.
- Color-coded display for `X` (Yellow) and `O` (Magenta) for better visual differentiation.
- Detects win conditions across rows, columns, and diagonals.
- Handles invalid moves and informs players of errors.
- Supports restarting the game or exiting mid-play.
- Graceful handling of a draw game when all cells are filled.

## Instructions

1. **Start the Game**:
   - Run the program and follow the on-screen instructions.
   - Player 1 uses the sign `X`, and Player 2 uses the sign `O`.

2. **Gameplay**:
   - Players will be prompted to select a cell (1–9) on their turn.
   - The cells are numbered as shown below:
     ```
      1 | 2 | 3
     -----------
      4 | 5 | 6
     -----------
      7 | 8 | 9
     ```
   - Enter the corresponding number for the desired cell to make your move.

3. **Game End**:
   - The game ends when a player wins or the board is full (resulting in a draw).
   - To terminate the game mid-play, enter `-1`.

4. **Restart or Exit**:
   - After the game ends, you can choose to restart or exit.

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/your_username/tic-tac-toe.git
   cd tic-tac-toe
   ```

2. Compile the program:
   ```bash
   gcc -o TicTacToe TIC_TAC_TOE.c
   ```

3. Run the executable:
   ```bash
   ./TicTacToe
   ```

## Code Structure

- **Game Board Initialization**: The board is cleared and displayed with cell numbers.
- **Game Logic**: Handles player turns, move validation, and winner detection.
- **Display Functions**: Color-coded output for better visuals.
- **Restart and Exit**: Flexible options to replay or end the game.

## Requirements

- GCC Compiler
- Terminal with ANSI escape code support for colored output.

## Contribution

Feel free to fork this repository and submit pull requests to improve the game or add new features.


Let me know if you'd like to modify or add anything!
