d = set()

for i in range(2,101):
    for j in range(2, 101):
        d.add(i**j)

print(len(d))
