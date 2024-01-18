import random
import os

# Generate 3 random floats
float1 = random.uniform(0, 1)
float2 = random.uniform(0, 1)
float3 = random.uniform(0, 1)

# Convert them to strings
str1 = str(float1)
str2 = str(float2)
str3 = str(float3)

# Concatenate them into a single string
final_string = str1 + ", " + str2 + ", " + str3

# Write the string to a file
with open('output.txt', 'w') as f:
    f.write(final_string)