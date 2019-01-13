import math

def is_armstrong(number):
    strNb = str(number)
    l = len(strNb)
    S = 0
    for i in strNb:
        S += math.pow(int(i), l)

    if S == number:
        return True
    else:
        return False
