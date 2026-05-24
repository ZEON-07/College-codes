def alpha_beta(values, depth, is_max, alpha, beta):

    # leaf node
    if depth == 0 or len(values) == 1:
        return values[0], [values[0]]

    mid = len(values) // 2
    left = values[:mid]
    right = values[mid:]

    if is_max:

        best_val = float('-inf')
        best_path = []

        # explore left child
        val, path = alpha_beta(left, depth-1, False, alpha, beta)

        if val > best_val:
            best_val = val
            best_path = ["MAX"] + path

        alpha = max(alpha, best_val)

        # pruning check
        if beta <= alpha:
            return best_val, best_path

        # explore right child
        val, path = alpha_beta(right, depth-1, False, alpha, beta)

        if val > best_val:
            best_val = val
            best_path = ["MAX"] + path

        alpha = max(alpha, best_val)

        return best_val, best_path


    else:

        best_val = float('inf')
        best_path = []

        # explore left child
        val, path = alpha_beta(left, depth-1, True, alpha, beta)

        if val < best_val:
            best_val = val
            best_path = ["MIN"] + path

        beta = min(beta, best_val)

        # pruning check
        if beta <= alpha:
            return best_val, best_path

        # explore right child
        val, path = alpha_beta(right, depth-1, True, alpha, beta)

        if val < best_val:
            best_val = val
            best_path = ["MIN"] + path

        beta = min(beta, best_val)

        return best_val, best_path


# Main program
values = [5,3,2,4,1,3,6,2,8,7,5,1,3,4]

print("Alpha Beta Pruning Example")

result, path = alpha_beta(values, 4, False, float('-inf'), float('inf'))

print("Root value:", result)
print("Pruned Tree Path:", path)