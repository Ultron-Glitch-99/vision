
import pandas as pd
import sqlite3

# A. Import data from CSV file
csv_data = pd.read_csv("data.csv")

print("\n========== CSV DATA ==========")

print("\nFirst 5 Records:")
print(csv_data.head())

print("\nLast 5 Records:")
print(csv_data.tail())

print("\nDataset Information:")
csv_data.info()

print("\nStatistical Description:")
print(csv_data.describe())

print("\nData Types:")
print(csv_data.dtypes)

print("\nDataset Shape:")
print(csv_data.shape)


# B. Import data from JSON file
json_data = pd.read_json("data.json")

print("\n========== JSON DATA ==========")

print("\nFirst 5 Records:")
print(json_data.head())

print("\nLast 5 Records:")
print(json_data.tail())

print("\nDataset Information:")
json_data.info()

print("\nStatistical Description:")
print(json_data.describe())

print("\nData Types:")
print(json_data.dtypes)

print("\nDataset Shape:")
print(json_data.shape)


# C. Import data from SQL database
connection = sqlite3.connect("database.db")

query = "SELECT * FROM students"

sql_data = pd.read_sql_query(query, connection)

print("\n========== SQL DATA ==========")

print("\nFirst 5 Records:")
print(sql_data.head())

print("\nLast 5 Records:")
print(sql_data.tail())

print("\nDataset Information:")
sql_data.info()

print("\nStatistical Description:")
print(sql_data.describe())

print("\nData Types:")
print(sql_data.dtypes)

print("\nDataset Shape:")
print(sql_data.shape)

# Close database connection
connection.close()
