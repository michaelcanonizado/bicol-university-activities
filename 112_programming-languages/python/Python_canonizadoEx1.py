import math

# Get user input
a = float(input("Enter a: "))
b = float(input("Enter b: "))
c = float(input("Enter c: "))

# Calculate discriminant
d = b**2 - 4*a*c

# Output the determinant
print(f"descriminant = {d}")

# Determine root characteristics
if d > 0:
    print("two real and distinct roots")
    root1 = (-b + math.sqrt(d)) / (2 * a)
    root2 = (-b - math.sqrt(d)) / (2 * a)
    print(f"Roots are: {root1:.2f} and {root2:.2f}")
elif d == 0:
    print("one real root")
    root = -b / (2 * a)
    print(f"Root are: {root:.2f}")
else:
    print("no real roots")
    real_part = -b / (2 * a)
    imaginary_part = math.sqrt(-d) / (2 * a)
    print(f"Roots are: {real_part:.2f} + {imaginary_part:.2f}i and {real_part:.2f} - {imaginary_part:.2f}i")
