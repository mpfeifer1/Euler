def sumdigits(n):
    s = 0
    while n > 0:
        s += n % 10
        n //= 10
    return s


best = 0

for i in range(1,100):
    for j in range(1,100):
        num = sumdigits(i**j)
        if num > best:
            best = num

print(best)
