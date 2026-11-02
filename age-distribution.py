
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from scipy.stats import skew, kurtosis

# Load Adult dataset
df = pd.read_csv("adult.csv")

# Q1. Display basic information about the dataset
print("First 5 Records:")
print(df.head())

print("\nDataset Information:")
df.info()

print("\nDataset Shape:")
print(df.shape)


# Q2. Calculate measures of central tendency
print("\nMean Age:")
print(df["age"].mean())

print("\nMedian Age:")
print(df["age"].median())

print("\nMode Age:")
print(df["age"].mode())


# Q3. Calculate skewness and kurtosis
age_skewness = skew(df["age"].dropna())
age_kurtosis = kurtosis(df["age"].dropna())

print("\nSkewness of Age:", age_skewness)
print("Kurtosis of Age:", age_kurtosis)


# Q4. Detect outliers using IQR
Q1 = df["age"].quantile(0.25)
Q3 = df["age"].quantile(0.75)

IQR = Q3 - Q1

lower_limit = Q1 - 1.5 * IQR
upper_limit = Q3 + 1.5 * IQR

outliers = df[
    (df["age"] < lower_limit) |
    (df["age"] > upper_limit)
]

print("\nLower Limit:", lower_limit)
print("Upper Limit:", upper_limit)

print("\nAge Outliers:")
print(outliers["age"])


# Q5. Plot histogram of age distribution
plt.figure(figsize=(8, 5))
sns.histplot(df["age"].dropna(), bins=20, kde=False)

plt.title("Age Distribution Histogram")
plt.xlabel("Age")
plt.ylabel("Frequency")
plt.show()


# Q6. Plot box plot of age distribution
plt.figure(figsize=(8, 5))
sns.boxplot(x=df["age"])

plt.title("Age Distribution Box Plot")
plt.xlabel("Age")
plt.show()


# Q7. Plot density distribution of age
plt.figure(figsize=(8, 5))
sns.kdeplot(df["age"].dropna(), fill=True)

plt.title("Age Distribution Density Plot")
plt.xlabel("Age")
plt.ylabel("Density")
plt.show()


# Q8. Analyse age distribution by different groups
print("\nAverage Age by Workclass:")
print(df.groupby("workclass")["age"].mean())

print("\nAverage Age by Education:")
print(df.groupby("education")["age"].mean())

print("\nAverage Age by Sex:")
print(df.groupby("sex")["age"].mean())


# Q9. Display final age statistics
print("\nFinal Age Statistics:")
print(df["age"].describe())

print("\nAge Distribution Analysis Completed!")
