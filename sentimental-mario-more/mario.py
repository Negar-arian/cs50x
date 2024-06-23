import cs50

while True:
    h = cs50.get_int("Height:")
    if h > 0 and h < 9:
        break
for i in range(h):
    for j in range(i, h - 1):
        print(" ", end="")
    for k in range(i + 1):
        print("#", end="")
    print("  ", end="")
    for j in range(i + 1):
        print("#", end="")
    print()
