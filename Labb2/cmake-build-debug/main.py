import matplotlib.pyplot as p 
import numpy as np 

mean_values = []
std_devs = []
ids = []

with open("cmake-build-debug\data.txt") as file:
    current_id = None
    current_mean = None
    current_std_dev = None

    for line in file:
        line = line.strip()
        if line.startswith("ID:"):
            current_id = int(line.split(":")[1].strip())
        elif line.startswith("Mean Value:"):
            current_mean = float(line.split(":")[1].strip())
        elif line.startswith("Standard Deviation:"):
            current_std_dev = float(line.split(":")[1].strip())

        if current_id is not None and current_mean is not None and current_std_dev is not None:
            ids.append(current_id)
            mean_values.append(current_mean)
            std_devs.append(current_std_dev)

            # Reset current values for the next set of data
            current_id = None
            current_mean = None
            current_std_dev = None

# Print the extracted data
#for i in range(len(ids)):
    #print(f"ID: {ids[i]}, Mean Value: {mean_values[i]}, Standard Deviation: {std_devs[i]}")

p.yscale('linear')
p.xlabel('N')
p.ylabel('time/s')
p.errorbar(ids,mean_values,yerr=std_devs, linestyle='None', marker='.', label="std_dev")
p.title("QuickMOT -- Inc")

p.plot(ids,mean_values,label="O(Nlog(N))")

p.legend()

p.show()

