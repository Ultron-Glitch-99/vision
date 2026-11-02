
print("LIST OPERATIONS")

marks = [45, 67, 45, 89, 67, 90]

marks.append(95)
print("Append:", marks)

marks.extend([80, 85])
print("Extend:", marks)

marks.insert(1, 75)
print("Insert:", marks)

marks.remove(45)
print("Remove:", marks)

marks.pop()
print("Pop:", marks)

marks.sort()
print("Sort:", marks)

marks.reverse()
print("Reverse:", marks)

print("Count:", marks.count(67))

print("Index:", marks.index(89))

new_marks = marks.copy()
print("Copy:", new_marks)


print("\nTUPLE OPERATIONS")

subjects = ("Python", "Java", "C++", "Python", "C")

print("Count:", subjects.count("Python"))

print("Index:", subjects.index("Java"))

print("Length:", len(subjects))

numbers = (10, 20, 30, 40, 50)

print("Maximum:", max(numbers))

print("Minimum:", min(numbers))

print("Sum:", sum(numbers))

print("Sorted:", sorted(numbers, reverse=True))

print("Reversed:", tuple(reversed(numbers)))

print("Slicing:", subjects[1:4])

new_subjects = subjects + ("HTML", "CSS")
print("Concatenation:", new_subjects)


print("\nDICTIONARY OPERATIONS")

student = {
    "Name": "Rahul",
    "Age": 20,
    "Marks": 85
}

print("Keys:", student.keys())

print("Values:", student.values())

print("Items:", student.items())

print("Get:", student.get("Name"))

student.update({"Marks": 95})
print("Update:", student)

student.pop("Age")
print("Pop:", student)

student.popitem()
print("Popitem:", student)

student.setdefault("City", "Pune")
print("Setdefault:", student)

new_student = student.copy()
print("Copy:", new_student)

keys = ["Name", "Age", "City"]
new_dict = dict.fromkeys(keys, "Unknown")
print("Fromkeys:", new_dict)


print("\nSET OPERATIONS")

A = {10, 20, 30, 40, 50}
B = {30, 40, 50, 60, 70}

A.add(80)
print("Add:", A)

A.update([90, 100])
print("Update:", A)

A.remove(10)
print("Remove:", A)

A.discard(200)
print("Discard:", A)

print("Pop:", A.pop())

print("Union:", A.union(B))

print("Intersection:", A.intersection(B))

print("Difference:", A.difference(B))

print("Symmetric Difference:", A.symmetric_difference(B))

print("Is Subset:", {30, 40}.issubset(B))
