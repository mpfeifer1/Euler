fact = [1]

for i in range(1, 101):
    fact.append(fact[i-1] * i)

def c(n, r):
    return fact[n] // (fact[r] * fact[n-r])

total = 0
for i in range(1,101):
    for j in range(0,100):
        if c(i,j) > 1000000:
            total += 1

print(total)
