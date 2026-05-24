import heapq


# check if state is valid
def valid_state(m, c):

    # cannot exceed limits
    if m < 0 or c < 0 or m > 3 or c > 3:
        return False

    # missionaries cannot be outnumbered
    if m > 0 and m < c:
        return False

    if (3 - m) > 0 and (3 - m) < (3 - c):
        return False

    return True


def a_star():

    start = (3, 3, 1)   # missionaries, cannibals, boat
    goal = (0, 0, 0)

    pq = []   # priority queue

    heapq.heappush(pq, (0, start, []))

    visited_cost = {start: 0}

    while pq:

        cost, state, path = heapq.heappop(pq)

        m, c, boat = state

        if state == goal:
            return path

        moves = [(1,0), (2,0), (0,1), (0,2), (1,1)]

        for move_m, move_c in moves:

            if boat == 1:   # boat left → right
                new_m = m - move_m
                new_c = c - move_c
                new_boat = 0
            else:           # boat right → left
                new_m = m + move_m
                new_c = c + move_c
                new_boat = 1

            if valid_state(new_m, new_c):

                new_state = (new_m, new_c, new_boat)

                new_cost = len(path) + 1

                if new_state not in visited_cost or new_cost < visited_cost[new_state]:

                    visited_cost[new_state] = new_cost

                    heuristic = new_m + new_c

                    total_cost = new_cost + heuristic

                    new_path = path + [(move_m, move_c, boat)]

                    heapq.heappush(pq, (total_cost, new_state, new_path))


    return None


# main program
print("Missionaries and Cannibals using A*")

solution = a_star()

if solution:

    print("Solution found in", len(solution), "moves\n")

    for i, step in enumerate(solution, 1):

        m, c, direction = step

        if direction == 1:
            d = "Left → Right"
        else:
            d = "Right → Left"

        print(i, ": Move", m, "Missionaries and", c, "Cannibals", d)

else:
    print("No solution found")