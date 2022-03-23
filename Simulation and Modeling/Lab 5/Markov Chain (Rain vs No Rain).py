# Python program to implement Markov Chain (Rain vs No Rain)

n = int(input("Enter the day for which weather need to be predicted (1,2,3,..) : "))

#    Rain   No rain
P = [[0.8,  0.2], #Rain
     [0.4,  0.6]] #No rain

#    Rain  No rain
Pi = [ 1,     0] #Current weather

for i in range(n):
    Pi = [Pi[0]*P[0][0] + Pi[1]*P[1][0],
          Pi[0]*P[0][1] + Pi[1]*P[1][1]]

print(f"Probability of rain at day {n} : {round(Pi[0],5)}")
print(f"Probability of no rain at day {n} : {round(Pi[1],5)}")