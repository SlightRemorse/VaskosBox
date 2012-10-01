import csv
a = 0
read = csv.reader(open("Test.csv", "rb"))
for row in read:
    if row[1] != "size":
          a = int(row[1])+a
print "Result is: ", a
raw_input("Press Enter to Exit")
