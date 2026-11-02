
import pandas as pd
import matplotlib.pyplot as plt

# Load Titanic dataset
df = pd.read_csv("Titanic-Dataset.csv")

# Q1. Inspect the dataset
print("First 5 Records:")
print(df.head())

print("\nLast 5 Records:")
print(df.tail())

print("\nDataset Shape:")
print(df.shape)

print("\nColumn Names:")
print(df.columns)


# Q2. Display statistical description
print("\nStatistical Description:")
print(df.describe())


# Q3. Count missing values in each column
print("\nMissing Values:")
print(df.isnull().sum())


# Q4. Fill missing Age values with mean
age_mean = df["Age"].mean()
df["Age"] = df["Age"].fillna(age_mean)

print("\nMissing Age Values After Filling:")
print(df["Age"].isnull().sum())


# Q5. Fill missing Cabin values with Unknown
df["Cabin"] = df["Cabin"].fillna("Unknown")

print("\nMissing Cabin Values After Filling:")
print(df["Cabin"].isnull().sum())


# Q6. Detect Fare outliers using a boxplot
plt.figure(figsize=(8, 5))
plt.boxplot(df["Fare"].dropna())
plt.title("Fare Outlier Detection")
plt.ylabel("Fare")
plt.show()


# Q7. Calculate IQR and detect Fare outliers
Q1 = df["Fare"].quantile(0.25)
Q3 = df["Fare"].quantile(0.75)

IQR = Q3 - Q1

lower_limit = Q1 - 1.5 * IQR
upper_limit = Q3 + 1.5 * IQR

print("\nLower Limit:", lower_limit)
print("Upper Limit:", upper_limit)

outliers = df[(df["Fare"] < lower_limit) |
              (df["Fare"] > upper_limit)]

print("\nFare Outliers:")
print(outliers["Fare"])


# Q8. Replace Fare outliers with values within the range
df["Fare"] = df["Fare"].clip(
    lower=lower_limit,
    upper=upper_limit
)

print("\nFare Outliers After Replacement:")
print(df[(df["Fare"] < lower_limit) |
         (df["Fare"] > upper_limit)]["Fare"])


# Q9. Display cleaned dataset
print("\nCleaned Dataset:")
print(df.head())

print("\nMissing Values After Cleaning:")
print(df.isnull().sum())


# Q10. Display boxplot after outlier treatment
plt.figure(figsize=(8, 5))
plt.boxplot(df["Fare"])
plt.title("Fare After Outlier Treatment")
plt.ylabel("Fare")
plt.show()
