count = {}

for i in range(1,1000):
    for j in range(1,1000):
        num = (i**2+j**2)**.5
        if num == int(num):
            num = int(num+i+j)
            if num not in count:
                count[num] = 1
            else:
                count[num] += 1

best = 0
idx = 0
for i in count:
    if i > 1000:
        continue
    if count[i] > best:
        best = count[i]
        idx = i

print(idx)
