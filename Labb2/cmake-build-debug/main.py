import matplotlib.pyplot as plt
import re

# Open the file in read mode ('r')
with open('results.txt', 'r') as file:
    content = file.read()

# Split the content into blocks based on empty lines
blocks = content.split('\n\n')

# List to store extracted values as tuples (ID, Mean Value, Sum, Standard Deviation)
values_list = []

# Iterate through blocks and extract information
for block in blocks:
    # Use regular expressions to extract ID, Mean Value, Sum, and Standard Deviation values
    id_match = re.search(r'ID:\s*(\d+)', block)
    mean_match = re.search(r'Mean Value:\s*([\d.]+)', block)
    sum_match = re.search(r'Sum:\s*([\d.]+)', block)
    std_dev_match = re.search(r'Standard Deviation:\s*([\d.]+)', block)

    # Check if matches are found and extract values
    if id_match and mean_match and sum_match and std_dev_match:
        id_value = int(id_match.group(1))
        mean_value = float(mean_match.group(1))
        sum_value = float(sum_match.group(1))
        std_dev_value = float(std_dev_match.group(1))

        # Append values as a tuple to the list
        values_list.append((id_value, mean_value, sum_value, std_dev_value))

# Unpack the values for plotting
ids, means, sums, std_devs = zip(*values_list)

# Plot the values
plt.figure(figsize=(10, 6))

plt.subplot(2, 1, 1)
plt.plot(ids, means, marker='o', linestyle='-', label='Mean Value')
plt.plot(ids, sums, marker='o', linestyle='-', label='Sum')
plt.xlabel('ID')
plt.ylabel('Mean Value / Sum')
plt.title('ID vs. Mean Value and Sum')
plt.legend()
plt.grid(True)

plt.subplot(2, 1, 2)
plt.plot(ids, std_devs, marker='o', linestyle='-', color='orange', label='Standard Deviation')
plt.xlabel('ID')
plt.ylabel('Standard Deviation')
plt.title('ID vs. Standard Deviation')
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()