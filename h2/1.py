import csv
a = 0
array = []
read = open("Test.csv", "r")
for line in read:
    array = line.split(",")
    if array[2] != "points": #has to match the .csv's first line, 3rd element
        a = a + int(array[2])
        print array[2]
    
print "=", a
raw_input("Press Enter to Exit")


#Example Test.csv is included in the repository
#If desired the columns can be changed by tweaking the array[] index
