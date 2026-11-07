# chessGame

A two-player chess game in C++ with a Qt graphical interface, played on the same computer.

## What it does
- Full board with the standard piece moves; clicking a piece highlights its legal moves.
- Moves that would leave your own king in check are filtered out by simulating them on a copy of the board.
- Castling (both sides) and pawn promotion (to a queen).
- Check and checkmate detection, with a status panel showing whose turn it is.
- A table listing every move played since the start of the game (for example `e2-e4`).
- A restart button.

## Tech stack
C++17, Qt 5 (Widgets, QGraphicsScene, a QAbstractTableModel for the move list), built with qmake.

## Run it locally
Requires Qt 5 (developed with Qt 5.15.2 / MinGW 64-bit). Open `chess/chess.pro` in Qt Creator and run it, or from the command line:
```
cd chess
qmake chess.pro
make
```

## Context
Personal project from March to May 2023, built to practice object-oriented programming in C++: each piece type is its own class deriving from a common `Piece` class.
