import cs50

number = cs50.get_int("Number: ")
strnum = str(number)


def sumdigit(num):
    sum = 0
    for i in str(num):
        sum += int(i)
    return sum


def check(number):
    sum = 0
    strnumber = str(number)
    n = int(len(strnumber))
    for i in range(n - 2, -1, -2):
        intsnum = int(strnumber[i])
        if len(str(intsnum * 2)) != 1:
            sum += sumdigit(intsnum * 2)
        else:
            sum += intsnum * 2
    for j in range(n - 1, -1, -2):
        sum += int(strnumber[j])
    return sum


strsum = str(check(number))
if strsum[-1] == "0":
    if int(strnum[0]) == 3 and (
        int(strnum[1]) == 4 or int(strnum[1]) == 7 and len(strnum) == 15
    ):
        print("AMEX")
    elif (
        int(strnum[0]) == 5
        and int(strnum[1]) > 0
        and int(strnum[1]) < 6
        and len(strnum) == 16
    ):
        print("MASTERCARD")
    elif int(strnum[0]) == 4 and (len(strnum) == 13 or len(strnum) == 16):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
