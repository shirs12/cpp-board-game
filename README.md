# cpp-board-game

### A 2 player board console game using c++

<br />

First, Initialize players and game board

```console
Welcome!

Menu:
1. start the game
2. Exit

Enter your choice: 1

You chose to play!

The game board is empty, you need to fill it up

# # # # # # # # # # #
#                   #
#                   #
#                   #
#                   #
#                   #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # #

First player starting point
enter row: 2
enter colomn: 2

player placed on board successfully.

# # # # # # # # # # #
#                   #
#   1               #
#                   #
#                   #
#                   #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # #


Second player starting point
enter row: 2
enter colomn: 3

player placed on board successfully.

# # # # # # # # # # #
#                   #
#   1 2             #
#                   #
#                   #
#                   #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # #

Enter Victory-Island's top-left corner point
enter row: 4
enter colomn: 4

Enter Victory-Island's dimentions
enter height: 2
enter width: 3

Victory-Island placed on board successfully.

# # # # # # # # # # #
#                   #
#   1 2             #
#                   #
#       * * *       #
#       * * *       #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # #
```

Each player can move one step, in turns.

```console
Player 1
Please enter your step:
1 - Up
2 - Down
3 - Right
4 - Left

2


# # # # # # # # # # #
#                   #
#     2             #
#   1               #
#       * * *       #
#       * * *       #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # #

Player 2
Please enter your step:
1 - Up
2 - Down
3 - Right
4 - Left

2


# # # # # # # # # # #
#                   #
#                   #
#   1 2             #
#       * * *       #
#       * * *       #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # #
```

If one player try to move where another player is already is, an appropriate message will appear, and the player will need to choose to move to another direction.

```console
Player 1
Please enter your step:
1 - Up
2 - Down
3 - Right
4 - Left

3

# # # # # # # # # # #
#                   #
#                   #
#   1 2             #
#       * * *       #
#       * * *       #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # #

Other player is already at that point.
Try a different direction (1-up, 2-down, 3-right, 4-left):
2

```

```console
# # # # # # # # # # #
#                   #
#                   #
#     2             #
#   1   * * *       #
#       * * *       #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # #

Player 2
Please enter your step:
1 - Up
2 - Down
3 - Right
4 - Left

2


# # # # # # # # # # #
#                   #
#                   #
#                   #
#   1 2 * * *       #
#       * * *       #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # #

Player 1
Please enter your step:
1 - Up
2 - Down
3 - Right
4 - Left

2


# # # # # # # # # # #
#                   #
#                   #
#                   #
#     2 * * *       #
#   1   * * *       #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # #
```

The first player who got to the victory-island - wins the game.

```console
Player 2
Please enter your step:
1 - Up
2 - Down
3 - Right
4 - Left

3

# # # # # # # # # # #
#                   #
#                   #
#                   #
#       2 * *       #
#   1   * * *       #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # #


Player 2 found the victory-island and won the game!
game over
```

If the game is over - the game menu will shown again until the players choose to exit the game.

```console
Menu:
1. start the game
2. Exit

Enter your choice: 1

You chose to play!

The game board is empty, you need to fill it up

# # # # # # # # # # #
#                   #
#                   #
#                   #
#                   #
#                   #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # #

First player starting point
enter row: 8
enter colomn: 8

player placed on board successfully.

# # # # # # # # # # #
#                   #
#                   #
#                   #
#                   #
#                   #
#                   #
#                   #
#               1   #
#                   #
# # # # # # # # # # #


Second player starting point
enter row: 6
enter colomn: 5

player placed on board successfully.

# # # # # # # # # # #
#                   #
#                   #
#                   #
#                   #
#                   #
#         2         #
#                   #
#               1   #
#                   #
# # # # # # # # # # #

Victory-Island's top-left corner point
enter row: 1
enter colomn: 1

Victory-Island's dimentions
enter height: 2
enter width: 2

Victory-Island placed on board successfully.

# # # # # # # # # # #
# * *               #
# * *               #
#                   #
#                   #
#                   #
#         2         #
#                   #
#               1   #
#                   #
# # # # # # # # # # #

Player 1
Please enter your step:
1 - Up
2 - Down
3 - Right
4 - Left

1


# # # # # # # # # # #
# * *               #
# * *               #
#                   #
#                   #
#                   #
#         2         #
#               1   #
#                   #
#                   #
# # # # # # # # # # #

Player 2
Please enter your step:
1 - Up
2 - Down
3 - Right
4 - Left

1


# # # # # # # # # # #
# * *               #
# * *               #
#                   #
#                   #
#         2         #
#                   #
#               1   #
#                   #
#                   #
# # # # # # # # # # #

```

. . .

```console
Player 1
Please enter your step:
1 - Up
2 - Down
3 - Right
4 - Left

1


# # # # # # # # # # #
# * *               #
# * *               #
#     2             #
#                   #
#         1         #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # # 

Player 2
Please enter your step:
1 - Up
2 - Down
3 - Right
4 - Left

1


# # # # # # # # # # #
# * *               #
# * * 2             #
#                   #
#                   #
#         1         #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # #

Player 1
Please enter your step:
1 - Up
2 - Down
3 - Right
4 - Left

1


# # # # # # # # # # #
# * *               #
# * * 2             #
#                   #
#         1         #
#                   #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # #

Player 2
Please enter your step:
1 - Up
2 - Down
3 - Right
4 - Left

4

# # # # # # # # # # #
# * *               #
# * 2               #
#                   #
#         1         #
#                   #
#                   #
#                   #
#                   #
#                   #
# # # # # # # # # # #


Player 2 found the victory-island and won the game!
game over
```

If the players choose to exit the game, an appropriate message will appear, and the program will stop running.

```console
Menu:
1. start the game
2. Exit

Enter your choice: 2

You chose to exit the game...
```

enjoy!
