def prime(n):
    for i in range(2, int(n**.5)+2):
        if n % i == 0:
            return False
    return True

def dig(n):
    chars = []
    while n > 0:
        chars.append(n%10)
        n //= 10
    chars = sorted(chars)
    ret = ''.join(str(e) for e in chars)
    return ret

m = {}

for i in range(1000, 9999):
    if prime(i):
        if dig(i) not in m:
            m[dig(i)] = []
        m[dig(i)].append(i)

for i in m:
    if len(m[i]) >= 3:
        m[i] = sorted(m[i])

        for j in range(0, len(m[i])-2):
            for k in range(j+1, len(m[i])-1):
                for l in range(k+1, len(m[i])):
                    if m[i][l]-m[i][k] == m[i][k]-m[i][j]:
                        print(m[i][j], m[i][k], m[i][l])
