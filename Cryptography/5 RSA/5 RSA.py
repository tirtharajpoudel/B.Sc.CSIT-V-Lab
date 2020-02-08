# Python program to implement RSA algorithm.

import pyinputplus as pyip
import math, random

def is_prime(n):
    count = 0
    for i in range(1, n + 1):
        if n % i == 0:
            count += 1
    if count == 2:
        return True
    else:
        return False

def calculate_d(totient_n, e):
    for i in range(2, totient_n):
        if (e * i) % totient_n == 1:
            return i
    
while True:
    print("Enter two prime numbers : ")
    p = pyip.inputNum()
    q = pyip.inputNum()
    if is_prime(p) and is_prime(q) and p != q:
        break

n  = p * q
print("n : ", n)

totient_n = (p - 1) * (q - 1)
print("totient(n) : ", totient_n)

e_list = []
for i in range(2, totient_n):
    if math.gcd(totient_n, i) == 1:
        e_list.append(i)
# print("e_list: ", e_list)

while True:
    #e = pyip.inputInt("Select an integer from e_list: ")
    e = random.choice(e_list)
    if e in e_list:
        break
print("e : ", e)

d = calculate_d(totient_n, e)
print("d : ", d)

PU = [e, n]
print("Public key : ", PU)

PR = [d, n]
print("Private key : ", PR)

m = pyip.inputInt("Enter message : ", lessThan = n)

c = m ** e % n
print("Cipher text : ", c)

m = c ** d % n
print("Decrypted text : ", m)



