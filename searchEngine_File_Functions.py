#!/usr/bin/python

import sys
import glob
from os import listdir
from os import path

#Code made by Luis Ariel Valbuena Reyes
#write the name of a function or variable as input and the program will
#list all the instances in the project where the variable or function is present

def fixpath(listFiles,route):
    sizeList = len(listFiles)
    iterator = 0
    returnList = []
    #print 'On fixpath'
    while(iterator < sizeList):
        pos = listFiles[iterator].find(route+'/')
        if(pos == -1):
            returnList.append(route+'/'+listFiles[iterator])
        else:
            returnList.append(listFiles[iterator])
        #print returnList[iterator]
        iterator = iterator + 1
    return returnList

def listFiles(strLocation):
    lFiles = listdir(strLocation)
    sizelFiles = len(lFiles)
    iterator = 0
    while(iterator < sizelFiles):
        if (path.isdir(strLocation + '/' + lFiles[iterator])):
            newFolder = lFiles.pop(iterator)
            newPath = strLocation + '/' + newFolder
            newlistFiles = listFiles(newPath)
            listFilesCompletePath =  fixpath(newlistFiles,newPath) 
            lFiles.extend(listFilesCompletePath)
            #lFiles.extend(newlistFiles)
            sizelFiles = len(lFiles)
        else:
            pos = lFiles[iterator].find(strLocation) 
            if(pos==-1):
                lFiles[iterator] = strLocation+'/' + lFiles[iterator]
            iterator = iterator + 1
    return lFiles

def getFileContent(nameFile):
    f = open(nameFile,'r')
    stringForReturn = f.read()
    f.close()
    return stringForReturn

def returnFilescontainingGoal(listContent,goal):
    listContainingGoal = []
    for fileFolder in listContent:
        stringContent = getFileContent(fileFolder)
        pos = stringContent.find(goal)
        if (pos > -1) and (fileFolder[-1]!='~'):
            listContainingGoal.append(fileFolder)
    return listContainingGoal



if __name__ == "__main__":
    #print 'Number of arguments:', len(sys.argv), 'arguments.'
    #print 'Argument List:', str(sys.argv)
    #Usage: searchEngine_File_Function PATH (function or variable)

    print '\nHello...\n'
    goalFolder = str(sys.argv[1])
    goalVarFunct = str(sys.argv[2])
    extension = str(sys.argv[3])
    print 'Accessing folder ' + goalFolder + '/...\n'
    print 'looking for function or variable ' + goalVarFunct + '.\n'

    laLista = listFiles(goalFolder)
    
    for line in laLista:
        print line

    #filteredLista = returnFilescontainingGoal(laLista,goalVarFunct)

    filteredLista = returnFilescontainingGoal(laLista,goalVarFunct)

    print "\nThe filtered files are: \n"
    for line in filteredLista:
        print line
    print '\n'
