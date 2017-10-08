for i in range(11, 99):
    if i % 10 == 0:
        continue
    for j in range(11, 99):
        if j % 10 == 0:
            continue

        if i == j:
            continue

        if i > j:
            continue

        tempi = str(i).zfill(2);
        tempj = str(j).zfill(2);

        checkmore = True

        if tempi[0] == tempj[0]:
            tempi = int(tempi[1])
            tempj = int(tempj[1])
            checkmore = False

        if checkmore and tempi[1] == tempj[0]:
            tempi = int(tempi[0])
            tempj = int(tempj[1])
            checkmore = False

        if checkmore and tempi[0] == tempj[1]:
            tempi = int(tempi[1])
            tempj = int(tempj[0])
            checkmore = False

        if checkmore and tempi[1] == tempj[1]:
            tempi = int(tempi[0])
            tempj = int(tempj[0])
            checkmore = False

        if checkmore:
            continue

        if tempj == '0':
            continue
        if tempi == '0':
            continue

        if (tempi / tempj) == (i / j):
            print(i, j)
