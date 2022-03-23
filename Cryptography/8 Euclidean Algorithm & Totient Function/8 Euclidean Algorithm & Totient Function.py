# Python program to calculate GCD using Euclidean algorithm and calculate the totient function

a = int(input("Enter first number : "))
b = int(input("Enter second number : "))


def gcd(a, b):
    if a < b:
        return gcd(b, a)
    if b != 0:
        return gcd(b, a % b)
    else:
        return a


print(f"GCD of {a} and {b} : {gcd(a,b)}")


def Φ(n):
    count = 0
    print(f"The numbers smaller than {n} and relatively prime to {n} are : ")
    for i in range(1, n):
        if gcd(i, n) == 1:
            count = count + 1
            print(i)
    print(f"∴ Φ({n}) = {count}")


Φ(21)
