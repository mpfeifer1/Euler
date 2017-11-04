def pal(n):
    s = str(n)
    t = s[::-1]
    if s == t:
        return True
    return False

def pal2(n):
    s = bin(n)[2:]
    t = s[::-1]
    if s == t:
        return True
    return False

total = 0
for i in range(1,1000001):
    if pal(i) and pal2(i):
        total += i

print(total)
