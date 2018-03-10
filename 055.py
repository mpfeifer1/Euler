
def rev(n):
    n = str(n)
    n = n[::-1]
    return int(n)

def pal(n):
    m = rev(n)
    return n == m

def lychrel(n):
    for i in range(0,50):
        n += rev(n)
        if pal(n):
            return False
    return True

count = 0
for i in range(0,10000):
    if lychrel(i):
        count += 1
        print(i)

print(count)
