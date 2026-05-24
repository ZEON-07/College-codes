import queue

# print board
def print_board(board):

    for row in board:
        print(row[0], "|", row[1], "|", row[2])
        print("----------")
    print()

# check winner
def check_winner(board, player):

    # rows
    for i in range(3):
        if board[i][0] == player and board[i][1] == player and board[i][2] == player:
            return True

    # columns
    for i in range(3):
        if board[0][i] == player and board[1][i] == player and board[2][i] == player:
            return True

    # diagonals
    if board[0][0] == player and board[1][1] == player and board[2][2] == player:
        return True

    if board[0][2] == player and board[1][1] == player and board[2][0] == player:
        return True

    return False


# check draw
def check_draw(board):

    for row in board:
        if " " in row:
            return False

    return True


# BFS AI move
def bfs_ai(board, player):

    q = queue.Queue()
    q.put(board)

    while not q.empty():

        current = q.get()

        for r in range(3):
            for c in range(3):

                if current[r][c] == " ":

                    # copy board
                    new_board = [row[:] for row in current]

                    # place move
                    new_board[r][c] = player

                    # winning move
                    if check_winner(new_board, player):
                        return r, c

                    q.put(new_board)

    # fallback move
    for r in range(3):
        for c in range(3):

            if board[r][c] == " ":
                return r, c


# main game
def play_game():

    board = [
        [" "," "," "],
        [" "," "," "],
        [" "," "," "]
    ]

    current = "X"

    while True:

        print_board(board)

        # player move
        if current == "X":

            r = int(input("Row: "))
            c = int(input("Column: "))

        # AI move
        else:

            print("AI move...")
            r, c = bfs_ai(board, "O")

        # valid move
        if (
            0 <= r <= 2 and
            0 <= c <= 2 and
            board[r][c] == " "
        ):

            board[r][c] = current

            # winner
            if check_winner(board, current):

                print_board(board)
                print(current, "wins!")
                break

            # draw
            if check_draw(board):

                print_board(board)
                print("Draw!")
                break

            # switch player
            current = "O" if current == "X" else "X"

        else:
            print("Invalid move")


play_game()