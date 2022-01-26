from scipy.stats import binom
#pip install scipy

criticalPercent = .7
#binom -> binom.pmf(trials, p, success)
trials = 50
prob = 1/2
numSuccess = int(trials * criticalPercent)

def binomSum(trials, prob, numSuccess):
    return sum([binom.pmf(n=trials, p=prob, k=s) for s in range(numSuccess, trials+1)])

S = binomSum(trials, prob, numSuccess)
print(round(S, 4))