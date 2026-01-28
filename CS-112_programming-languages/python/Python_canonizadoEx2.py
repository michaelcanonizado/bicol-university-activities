# Get user input for half height
n = int(input("Enter the half height of the diamond (n): "))

# Upper half of the diamond (including the middle line)
for i in range(1, n + 1):
    spaces = ' ' * (n - i)
    stars = '*' * (2 * i - 1)
    print(spaces + stars)

# Lower half of the diamond
for i in range(n - 1, 0, -1):
    spaces = ' ' * (n - i)
    stars = '*' * (2 * i - 1)
    print(spaces + stars)
