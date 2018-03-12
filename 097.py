def fastpow(base, exp, mod):
    base %= mod
    res = 1
    while exp > 0:
        if exp % 2 == 1:
            res = (res * base) % mod
        base = (base * base) % mod
        exp //= 2
    return res % mod


big = 10000000000
print((28433 * fastpow(2, 7830457, big) + 1) % big)
