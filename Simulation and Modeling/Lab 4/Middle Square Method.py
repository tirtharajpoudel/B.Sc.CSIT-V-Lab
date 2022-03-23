# Python program to generate pseudo-random numbers using the middle square method

seed = int(input("Enter a 4 digit number : "))
number = seed
print(f"The seed is {seed}.")

print("The random numbers are : ")
already_generated = set()

while(True):

    already_generated.add(number)

    Xi = str(int(number)**2)
    # print(f"Square : {Xi}")

    # Builtin function to fill zeros / prepend 0s.
    # Xi.zfill(8)
    
    zeros_to_be_added = 8 - len(Xi)
    for i in range(zeros_to_be_added):
        Xi = '0' + Xi
    # print(f"After padding : {Xi}")

    number = str(Xi)[2:6]

    if(number in already_generated):
        break

    if (int(number)==0):
        break

    print(int(number))