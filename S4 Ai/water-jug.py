def dfs_water_jug(cap1, cap2, goal):
    stack = [(0, 0, [])]
    visited = set()
    visited.add((0, 0))
    while stack:
        amt1, amt2, path = stack.pop()
        if amt1 == goal or amt2 == goal:
            return path + [(amt1, amt2)]
        moves = []
        if amt1 < cap1:
            moves.append((cap1, amt2))
        if amt2 < cap2:
            moves.append((amt1, cap2))
        if amt1 > 0:
            moves.append((0, amt2))
        if amt2 > 0:
            moves.append((amt1, 0))
        if amt1 > 0 and amt2 < cap2:
            pour = min(amt1, cap2 - amt2)
            moves.append((amt1 - pour, amt2 + pour))
        if amt2 > 0 and amt1 < cap1:
            pour = min(amt2, cap1 - amt1)
            moves.append((amt1 + pour, amt2 - pour))
        for state in moves:
            if state not in visited:
                visited.add(state)
                stack.append((state[0], state[1], path + [(amt1, amt2)]))
    return None
def main():
    cap1 = 6
    cap2 = 4
    goal = 2
    path = dfs_water_jug(cap1, cap2, goal)
    if path:
        print(f"Water Jug Problem: {cap1}L and {cap2}L jugs, goal {goal}L")
        print(f"Solution found with {len(path)} states:")
        for i, state in enumerate(path, 1):
            print(f"{i}. {state}")
    else:
        print("No solution found.")
if __name__ == "__main__":
    main()