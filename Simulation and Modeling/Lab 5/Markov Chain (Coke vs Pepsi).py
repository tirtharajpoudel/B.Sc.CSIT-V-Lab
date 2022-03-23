# Python program to implement Markov Chain (Coke vs Pepsi)

n = int(input("Enter no of purchase after which the probability needs to be calculated : "))

#    Coke   Pepsi
P = [[0.9,  0.1], #Coke
     [0.2,  0.8]] #Pepsi

#    Coke Pepsi
Pi = [ 0,    1] #Current Purchase

for i in range(n):
    Pi = [Pi[0]*P[0][0] + Pi[1]*P[1][0],
          Pi[0]*P[0][1] + Pi[1]*P[1][1]]

print(f"Probability of purchasing coke after {n} purchases : {round(Pi[0],5)}")
print(f"Probability of purchasing pepsi after {n} purchases : {round(Pi[1],5)}")