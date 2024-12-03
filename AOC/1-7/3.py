import re

good = True

def eval(x):
    global good
    if x == 'do()':
        good = True
        return 0
    if x == 'don\'t()':
        good = False
        return 0
    print(x)
    t = re.findall(r'[0-9][0-9]*', x)
    if good == False:
        return 0
    return int(t[0]) * int(t[1])

# open 3.in into a string s
s = open('AOC/1-7/3.in').read()
t = re.findall(r'mul\([0-9]*,[0-9]*\)|do\(\)|don\'t\(\)', s)

print(t)

sum = 0
for x in t:
    sum += eval(x)

print(sum)