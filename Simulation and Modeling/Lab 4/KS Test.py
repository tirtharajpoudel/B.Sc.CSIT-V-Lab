# Python program to implement Kolmogorov-Smirnov Test

data=[0.44,0.81,0.14,0.05,0.93]
N = len(data)
α = 0.05
D_critical = 0.565
print("Data = {}".format(data))
print("N = {}".format(N))
print("Level of significance (α) = {}".format(α))
print("Critical value of D for α = {} and N = {} is {} .".format(α,N,D_critical))

Ri = data.copy()
Ri.sort()
print("\nAfter sorting :")
print("Ri = {}".format(Ri))

i = list(range(1, len(data)+1))
print("i = {}".format(i))

i_N = []
for index in i:
    i_N.append(index/N)
print("i/N = {}".format(i_N))

i_N_Ri = []
for index in i:
    i_N_Ri.append(round(i_N[index-1] - Ri[index-1],2))
print("i/N - Ri = {}".format(i_N_Ri))

Ri_i_1_N = []
for index in i:
    Ri_i_1_N.append(round(Ri[index-1] - (index-1)/N,2))
print("Ri - (i-1)/N = {}".format(Ri_i_1_N))

D_p = max(i_N_Ri)
print("D+ = {}".format(D_p))
D_n = max(Ri_i_1_N)
print("D- = {}".format(D_n))
D_calc = max(D_p,D_n)
print("D = {}".format(D_calc))

if (D_calc < D_critical):
    print("\nCalculated value of D < Tabulated value of D.")
    print("Therefore, Null Hypothesis is accepted.")
else:
    print("\nCalculated value of D > Tabulated value of D.")
    print("THerefore, Null Hypothesis is rejected.")
