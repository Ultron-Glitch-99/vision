
import pandas as pd

# Load the NCAA basketball dataset
df = pd.read_csv("RegularSeasonCompactResults.csv")

# Q1. Display sample records using head() and tail()
print("\nQ1. First five records:")
print(df.head())

print("\nLast five records:")
print(df.tail())

# Q2. Display the number of records in the dataset
print("\nQ2. Number of records:")
print(len(df))

# Q3. Display the number of missing values in each column
print("\nQ3. Missing values in each column:")
print(df.isnull().sum())

# Q4. Display the maximum value present in each column
print("\nQ4. Maximum value in each column:")
print(df.max())

# Q5. Display unique values present in each column
print("\nQ5. Unique values in each column:")

for column in df.columns:
    print("\nColumn:", column)
    print(df[column].unique())

# Q6. Display the number of unique values present in each column
print("\nQ6. Number of unique values in each column:")
print(df.nunique())

# Q7. Display the number of times unique values appeared in each column
print("\nQ7. Frequency of unique values in each column:")

for column in df.columns:
    print("\nColumn:", column)
    print(df[column].value_counts(dropna=False))
