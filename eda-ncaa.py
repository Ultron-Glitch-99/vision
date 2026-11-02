
import pandas as pd

# Load NCAA basketball dataset
df = pd.read_csv("RegularSeasonCompactResults.csv")


# Q1. Display all object columns
print("Q1. Object Columns:")

object_columns = df.select_dtypes(include="object")

print(object_columns)


# Q2. Find games where winning team scored more than 150
print("\nQ2. Games where winning score is greater than 150:")

high_scoring_games = df[df["WScore"] > 150]

print(high_scoring_games)


# Q3. Find games where winning score is greater than 150
# and losing score is less than 100
print("\nQ3. Games where winning score > 150 and losing score < 100:")

selected_games = df[
    (df["WScore"] > 150) &
    (df["LScore"] < 100)
]

print(selected_games)


# Q4. Count the number of games played per season
print("\nQ4. Number of games per season:")

games_per_season = df.groupby("Season").size()

print(games_per_season)


# Q5. Calculate average winning score for each team
print("\nQ5. Average winning score for each team:")

average_winning_score = df.groupby("WTeamID")["WScore"].mean()

print(average_winning_score)


# Q6. Count games won at home, away and neutral locations
print("\nQ6. Games won at different locations:")

location_wins = df["WLoc"].value_counts()

print(location_wins)

print("\nLocation Details:")
print("Home Wins:", location_wins.get("H", 0))
print("Away Wins:", location_wins.get("A", 0))
print("Neutral Wins:", location_wins.get("N", 0))
