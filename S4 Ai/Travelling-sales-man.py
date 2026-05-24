import random


# create distance matrix
def create_matrix(n):

    matrix = [[0] * n for _ in range(n)]

    for i in range(n):
        for j in range(i + 1, n):

            distance = random.randint(1, 10)

            matrix[i][j] = distance
            matrix[j][i] = distance

    return matrix


# calculate path cost
def find_cost(path, matrix):

    cost = 0

    for i in range(len(path) - 1):

        city1 = path[i]
        city2 = path[i + 1]

        cost += matrix[city1][city2]

    # return to starting city
    cost += matrix[path[-1]][path[0]]

    return cost


# hill climbing algorithm
def hill_climbing(n, matrix):

    # create random path
    path = list(range(n))
    random.shuffle(path)

    best_cost = find_cost(path, matrix)

    while True:

        found_better = False

        for i in range(n):
            for j in range(i + 1, n):

                # copy current path
                new_path = path[:]

                # swap cities
                new_path[i], new_path[j] = (
                    new_path[j],
                    new_path[i]
                )

                new_cost = find_cost(new_path, matrix)

                # better solution found
                if new_cost < best_cost:

                    path = new_path
                    best_cost = new_cost

                    found_better = True

        # stop if no improvement
        if not found_better:
            break

    return path, best_cost


# main program

n = int(input("Enter number of cities: "))

matrix = create_matrix(n)

print("Distance Matrix:\n")

for row in matrix:
    print(row)

best_path, minimum_cost = hill_climbing(n, matrix)

print("\nBest Path:", best_path)
print("Minimum Cost:", minimum_cost)