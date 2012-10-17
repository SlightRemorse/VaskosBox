#csv files shouldn't contain empty lines at the end
#if a csv file is empty it should be deleted so it doesn't cause a problem

maximumstudents = 29 #edit this to the number of students in class

import csv
import os

total = []
current = []
for i in xrange(maximumstudents):
	total.append(0)
	current.append(0)
for i in xrange(maximumstudents):
        i=i+1
        filename = str(i) + ".csv"
        if not os.path.exists(filename):
                print "File", filename, "doesn't exist."
        else:
                for a in xrange(maximumstudents):
                        current[a]=0
                read = open(filename, "r")
                for line in read:
                        array = line.split(",")
                        value=int(array[1])-1
                        current[value]=current[value]+1
                        total[value]=total[value]+1
                mini = 1000 # needs impossible number
                maxi = 0
                minnum = 0
                maxnum = 0
                for b in xrange(maximumstudents):
                        if current[b]>maxi:
                                maxnum=b
                                maxi=current[b]
                        if current[b]<mini and current[b]!=0:
                                minnum=b
                                mini=current[b]
                print "For", filename, "the most popular is number",(maxnum+1),"with",maxi,"points." 
                print "For", filename, "the least popular is number",(minnum+1),"with",mini,"points."
mini = 1000 # needs impossible number again
maxi = 0
minnum = 0
maxnum = 0
for b in xrange(maximumstudents):
        if total[b]>maxi:
                maxnum=b
                maxi=total[b]
        if total[b]<mini and total[b]!=0:
                minnum=b
                mini=total[b]
print "The most popular for the class is number",(maxnum+1),"with",maxi,"points." 
print "The least popular for the class is number",(minnum+1),"with",mini,"points."
