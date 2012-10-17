#csv files shouldn't contain empty lines at the end
#if a csv file is empty it should be deleted as it could cause a problem with the script

maximumstudents = 29 #edit this to the number of students in class

import csv
import os

total = []
current = []
most = []
mostnum = []
least = []
leastnum = []
for i in xrange(maximumstudents):
	total.append(0)
	current.append(0)
	mostnum.append(-1)
	most.append(-1)
	least.append(1000) #impossible number
	leastnum.append(1000) #impossible number
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
                        if current[b] > most[b] and current[b]!=0:
                                most[b]=current[b]
                                mostnum[b]=filename
                        if current[b] < least[b] and current[b]!=0:
                                least[b]=current[b]
                                leastnum[b]=filename
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
print "=======Total========"
print "The most popular for the class is number",(maxnum+1),"with",maxi,"points." 
print "The least popular for the class is number",(minnum+1),"with",mini,"points."
print "===================="
for i in xrange(maximumstudents):
        if not most[i]<=0:
                print "Student",(i+1),"is most popular in",mostnum[i],"with",most[i],"points."
                print "Student",(i+1),"is least popular in",leastnum[i],"with",least[i],"points."
        else:
                print "Student", (i+1), "didn't participate."
