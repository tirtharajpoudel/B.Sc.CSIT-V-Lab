# Python program to implement Elgamal Encryption
import random

print("Side A")
q = int(input("Enter a prime number (q) : "))
α = int(input("Enter its primitive root (α) : "))

XA = random.randint(2,q-2)
print(f"A's private Key (XA) = {XA}")
YA = α**XA % q
print(f"A's public Key (q, α, YA) = ({q}, {α}, {YA})")

# Encryption
print("\nSide B")
M = int(input("Enter the message to be sent (between 1 and q) : "))

k = random.randint(1,q-1)
K = YA**k % q
print(f"One time key (K) = {K}")

C1 = α**k % q
C2 = K*M %q
print(f"Cipher Text (C1, C2) = ({C1}, {C2})")

# Inverse of K
for i in range(q+1):
    if K*i % q == 1:
        K_iv = i
        break

# Decryption
print("\nSide A")
K = C1**XA % q
print(f"Decrypted one time key (K) = {K}")
M = C2*K_iv % q
print(f"Decrypted message (M) = {M}")

