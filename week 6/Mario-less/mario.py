from cs50 import get_int


while True:
    pyramidHeight = get_int("How height is the Pyramid?")
    if pyramidHeight > 0 and pyramidHeight < 9:
        break
for row in range(pyramidHeight):
    for space in range(pyramidHeight - row - 1, 0, -1):
        print(" ", end="")
    for hash in range(row + 1):
        print("#", end="")
    print("\n", end="")
