# Python program to implement different hashing algorithms

import hashlib

message = "Tirtha Raj Poudel"

# MD-5
md5 = hashlib.md5(message.encode())
print(f"MD-5 hash message digest: \n{md5.hexdigest()}")

# SHA-1
sha1 = hashlib.sha1(message.encode())
print(f"\nSHA-1 hash message digest: \n{sha1.hexdigest()}")

# SHA-224
sha224 = hashlib.sha224(message.encode())
print(f"\nSHA-224 hash message digest: \n{sha224.hexdigest()}")

# SHA-256
sha256 = hashlib.sha256(message.encode())
print(f"\nSHA-256 hash message digest: \n{sha256.hexdigest()}")

# SHA-384
sha384 = hashlib.sha384(message.encode())
print(f"\nSHA-384 hash message digest: \n{sha384.hexdigest()}")

# SHA-512
sha512 = hashlib.sha512(message.encode())
print(f"\nSHA-512 hash message digest: \n{sha512.hexdigest()}")