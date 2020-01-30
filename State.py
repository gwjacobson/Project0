import gzip
import numpy
import pylab
import matplotlib.pyplot as plt

#getting the lattice files
lattice_file = open("lattice", "r")

#arrays of data points to be used in the graph
file_size = []
sweeps = []
count = 0

#taking each sweep each conpressing the data
temp = ""

for line in lattice_file.readlines():
    #add line to temp
    #if line blank, process and set temp blank
    
    if line != "\n":
        temp += line
   
    else:
        
        compression = gzip.compress(bytes(temp, "utf-8"))
        file_size.append(len(compression))
        sweeps.append(count)
        count += 1
        temp = ""


plt.plot(sweeps, file_size)
plt.title("Entropy of Lattice Gas Automata")
plt.xlabel("Sweeps")
plt.ylabel("Number of compressed bits")
plt.show()