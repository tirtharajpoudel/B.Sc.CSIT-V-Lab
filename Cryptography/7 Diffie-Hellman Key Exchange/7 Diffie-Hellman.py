# Python program to implement Diffie-Hellman key exchange

import random

def is_prime(n):
    count = 0
    for i in range(1, int(n/2)+1):
        if (n % i == 0):
            count += 1
    if (count == 1):
        return True
    else:
        return False

while(True):
    p = int(input("Enter a prime number : "))
    if (is_prime(p)):
        break
g = int(input("Enter the primitive root of prime number : "))

Pr_A = random.randint(1,p)
print("\nPrivate key of A : {}".format(Pr_A))
Pr_B = random.randint(1,p)
print("Private key of B : {}".format(Pr_B))

Pu_A = (g**Pr_A) % p
print("\nPublic key of A : {}".format(Pu_A))
Pu_B = (g**Pr_B) % p
print("Public key of B : {}".format(Pu_B))

Se_A = (Pu_B**Pr_A) % p
Se_B = (Pu_A**Pr_B) % p
if(Se_A==Se_B):
    print("\nThe shared secret is : {}".format(Se_A))