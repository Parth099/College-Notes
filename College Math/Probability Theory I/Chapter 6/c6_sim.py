import random as r

#dice is 6 sided
SIDES = 6

def simDice(trials):
    rollingSum = 0
    for _ in range(trials):
        rolled = r.randint(1, SIDES)
        if rolled % 2:
            rollingSum += rolled
        else:
            rollingSum -= rolled

    return rollingSum / trials 

def runSimdice():
    trials = [100, 1_000, 10_000, 100_000, 1_000_000]
    print("%12s%12s"%("Trials", "Gain"))
    for t in trials:
        print("%12d%12.4f"%(t, simDice(t)))

runSimdice()