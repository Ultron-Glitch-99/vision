
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Load student performance dataset
df = pd.read_csv("student_performance.csv")

# Q1. Display basic information about the dataset
print("First 5 Records:")
print(df.head())

print("\nDataset Information:")
df.info()

print("\nStatistical Description:")
print(df.describe())

print("\nDataset Shape:")
print(df.shape)


# Q2. Analyse grades in different subjects
subjects = ["Math", "Science", "English"]

print("\nAverage Marks in Each Subject:")
print(df[subjects].mean())

print("\nMinimum Marks:")
print(df[subjects].min())

print("\nMaximum Marks:")
print(df[subjects].max())


# Q3. Visualize grade distributions
df[subjects].hist(figsize=(10, 6), bins=10)

plt.suptitle("Grade Distribution in Different Subjects")
plt.tight_layout()
plt.show()


# Q4. Analyse correlation between subjects
correlation = df[subjects].corr()

print("\nCorrelation Between Subjects:")
print(correlation)

# Visualize correlation using heatmap
plt.figure(figsize=(7, 5))
sns.heatmap(correlation, annot=True, cmap="coolwarm")
plt.title("Correlation Between Subjects")
plt.show()


# Q5. Analyse impact of attendance on grades
df["Average_Marks"] = df[subjects].mean(axis=1)

print("\nCorrelation Between Attendance and Average Marks:")
print(df["Attendance"].corr(df["Average_Marks"]))

# Visualize attendance vs average marks
plt.figure(figsize=(8, 5))
sns.scatterplot(
    data=df,
    x="Attendance",
    y="Average_Marks"
)

plt.title("Attendance vs Average Marks")
plt.xlabel("Attendance")
plt.ylabel("Average Marks")
plt.show()


# Q6. Visualize grade distribution using boxplot
plt.figure(figsize=(8, 5))
sns.boxplot(data=df[subjects])

plt.title("Subject-wise Grade Distribution")
plt.show()


# Q7. Display correlation and performance trends
print("\nSubject-wise Correlation:")
print(correlation)

print("\nAverage Student Performance:")
print(df["Average_Marks"].mean())

print("\nEDA Completed Successfully!")
