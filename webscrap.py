
import pandas as pd

# Wikipedia World Population webpage URL
url = "https://en.wikipedia.org/wiki/World_population"

# Extract all tables from the webpage
tables = pd.read_html(url)

# Display the total number of tables
print("Total number of tables extracted:", len(tables))

# Display all extracted tables
for i, table in enumerate(tables):
    print("\nTable", i + 1)
    print(table)
