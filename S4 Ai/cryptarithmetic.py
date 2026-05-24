import itertools

def solve_crypt(words, result):

    # collect all letters
    letters = set("".join(words) + result)

    if len(letters) > 10:
        print("Too many letters")
        return None

    letters = list(letters)

    first = set(word[0] for word in words + [result])
    # try all digit arrangements
    for perm in itertools.permutations(range(10), len(letters)):

        
        mapping = dict(zip(letters, perm))

        # leading digit cannot be zero
        if any(mapping[ch] == 0 for ch in first):
            continue

        word_values = []

        for word in words:
            num = int("".join(str(mapping[ch]) for ch in word))
            word_values.append(num)

        result_value = int("".join(str(mapping[ch]) for ch in result))


        # check equation
        if sum(word_values) == result_value:

            print("Solution Found\n")

            for i in sorted(mapping):
                print(i, "=", mapping[i])

            print("\nVerification:")

            print(" + ".join(map(str, word_values)),"=",result_value)

            return

    print("No solution found")


# Main Program

def main():
    words = ["EAT", "THAT"]
    result = "APPLE"

    print("EAT + THAT = APPLE\n")

    solve_crypt(words, result)

if __name__ == "__main__":
    main()