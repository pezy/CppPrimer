from sys import argv
from os import listdir
from os.path import isfile, join

if len(argv) > 1:
    mypath = argv[1]
else:
    mypath = '.'

print 'clang-format -i',

onlyfiles = [ f for f in listdir(mypath) if isfile(join(mypath, f)) ]
for file in onlyfiles:
    if (file.endswith(('.cpp', '.cc', '.h'))):
        print mypath + '\\' + file,
