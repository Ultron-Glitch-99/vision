
import numpy as np

# Q1. Create a 1D NumPy array with values from 10 to 49
arr = np.arange(10, 50)

print("Q1. Original 1D Array:")
print(arr)


# Q2. Reshape the array into a 3x5 matrix
matrix = arr[:15].reshape(3, 5)

print("\nQ2. Reshaped 3x5 Matrix:")
print(matrix)


# Q3. Extract elements divisible by 3 from the original array
result = arr[arr % 3 == 0]

print("\nQ3. Elements divisible by 3:")
print(result)


# Q4. Create two 3x3 NumPy arrays with random integers
A = np.random.randint(1, 100, size=(3, 3))
B = np.random.randint(1, 100, size=(3, 3))

print("\nQ4. First Random Array:")
print(A)

print("\nSecond Random Array:")
print(B)


# Q5. Perform element-wise arithmetic operations

print("\nQ5. Addition:")
print(A + B)

print("\nSubtraction:")
print(A - B)

print("\nMultiplication:")
print(A * B)

print("\nDivision:")
print(A / B)
