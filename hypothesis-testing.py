
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from scipy import stats

# Z-Test
sample = np.array([52, 55, 53, 54, 56, 51, 55, 54, 53, 52])

population_mean = 50
population_std = 5
n = len(sample)

sample_mean = np.mean(sample)

z_score = (sample_mean - population_mean) / (population_std / np.sqrt(n))
p_value = 2 * (1 - stats.norm.cdf(abs(z_score)))

print("Z Score:", z_score)
print("P Value:", p_value)

if p_value < 0.05:
    print("Reject Null Hypothesis")
else:
    print("Fail to Reject Null Hypothesis")


# T-Test
data = np.array([45, 50, 48, 52, 47, 49, 51, 46, 53, 50])

t_statistic, p_value = stats.ttest_1samp(data, popmean=50)

print("\nT Statistic:", t_statistic)
print("P Value:", p_value)

if p_value < 0.05:
    print("Reject Null Hypothesis")
else:
    print("Fail to Reject Null Hypothesis")


# Chi-Square Test
observed = np.array([
    [30, 20],
    [20, 30]
])

chi2, p_value, dof, expected = stats.chi2_contingency(observed)

print("\nChi-Square Statistic:", chi2)
print("P Value:", p_value)
print("Degrees of Freedom:", dof)
print("Expected Frequencies:")
print(expected)

if p_value < 0.05:
    print("Reject Null Hypothesis")
else:
    print("Fail to Reject Null Hypothesis")


# ANOVA Test
group1 = [75, 80, 85, 70, 90]
group2 = [60, 65, 70, 68, 72]
group3 = [85, 88, 90, 92, 87]

f_statistic, p_value = stats.f_oneway(group1, group2, group3)

print("\nF Statistic:", f_statistic)
print("P Value:", p_value)

if p_value < 0.05:
    print("Reject Null Hypothesis")
else:
    print("Fail to Reject Null Hypothesis")


# Normal Distribution
normal_data = np.random.normal(loc=50, scale=10, size=1000)

mean, std = stats.norm.fit(normal_data)

print("\nNormal Distribution Mean:", mean)
print("Standard Deviation:", std)

sns.histplot(normal_data, kde=True, stat="density")
plt.title("Normal Distribution")
plt.show()


# Binomial Distribution
n = 10
p = 0.5

x = np.arange(0, n + 1)
binomial_data = stats.binom.pmf(x, n, p)

print("\nBinomial Probabilities:")
print(binomial_data)

plt.bar(x, binomial_data)
plt.title("Binomial Distribution")
plt.show()


# Poisson Distribution
lam = 4

x = np.arange(0, 15)
poisson_data = stats.poisson.pmf(x, lam)

print("\nPoisson Probabilities:")
print(poisson_data)

plt.bar(x, poisson_data)
plt.title("Poisson Distribution")
plt.show()

print("\nAll Statistical Tests and Distributions Completed!")
