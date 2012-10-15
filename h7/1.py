import array
from random import randint
import time

spot = []
found = 0

for line in xrange(27):
    spot.append([])
    for row in xrange(6):
        spot[line].append(0)

def display():
    for line in xrange(27):
        for row in xrange(6):
            if row == 3:
                print " ",
            print spot[line][row],
        print ""

def addnew(num):
    print ""
    print ""
    print "Looking for ", num, " seats."
    free = 0
    found = 0
    for line in xrange(27):
        for row in xrange(6):
            if spot[line][row] == 0:
                if row <=2 and (row+num) <= 3:
                    free = 1
                    for count in xrange(num):
                        if spot[line][row+count] == 1:
                            free = 0
                    if free == 1:
                        for count in xrange(num):
                            spot[line][row+count] = 1
                if row >= 3 and row+num <= 6:
                    free = 1
                    for count in xrange(num):
                        if spot[line][row+count] == 1:
                            free = 0
                    if free == 1:
                        for count in xrange(num):
                            spot[line][row+count] = 1
            if free == 1:
                break
        if free == 1:
            break
    if free == 1:
        global found
        found = 1

counter = 0
while counter < 162:
    time.sleep(0.6)
    size=randint(1,3)
    addnew(size)
    if found == 1:
        counter=counter+size
        display()
        print "Filled spots: ", counter
    if found == 0:
        print "Couldn't find a spot."
        

