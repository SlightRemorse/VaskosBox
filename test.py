import csv
a = 0
b = 0
array = []
read = open("Test.csv", "r")
for line in read:
    array = line.split(",")
    if array[3] != "program\n": #has to match the .csv's first line, 3rd element
        if array[3] == "Python\n":
            a = a + int(array[2])
        if array[3] == "Ruby\n":
            b = b + int(array[2])
print "Sum of Python's numbers: ", a
print "Sum of Ruby's numbers: ", b
raw_input("Press Enter to Exit")


#Example Test.csv is included in the repository
#If desired the columns can be changed by tweaking the array[] index
#Remove "\n" in case array[3] isn't the last element
