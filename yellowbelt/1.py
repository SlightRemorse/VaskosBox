import csv
import optparse
parser = optparse.OptionParser()

parser.add_option('-s','--s',
                  action="store", dest="query",
                  help="query string", default="spam")
options, args = parser.parse_args()
filename=options.query
print filename
i = []
x = []
y = []
options, args = parser.parse_args()
read = open("belt1_1.csv", "r")
for line in read:
    array = line.split(",")
    i.append(int(array[0]))
    x.append(int(array[1]))
    value=(int(array[1])+int(array[0]))/7
    y.append(value)
write1 = open(filename, "w")
for a in xrange(5): #edit to size of csv list
    string = str(i[a]) + "," + str(x[a]) + "," + str(y[a])
    write1.write(string)
    write1.write("\n")
write1.close()
