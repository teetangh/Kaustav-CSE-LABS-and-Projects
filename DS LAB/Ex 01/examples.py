import math
from math import *
counter = 100
miles = 1000
name = "John"
print(counter)
print(miles)
print(name)

a = b = c = 1

print(5 * a)
print(a/2)
print(a ** 2)

str = "Hello World"

print(str)
print(str[0])
print(str[2:5])
print(str[2:])
print(str * 2)
print(str + "TEST")


var1 = 'Hello World!'
print("Updated String :", var1[:6] + 'Python')

print("My name is %s and weight is %d kg!" % ('Anitha', 55))

str = "this is string example....wow!!!"
print(str.capitalize())

str = "this is string example....wow!!!"
print(str.count('s'))

print(str.find('example'))


str = "THIS IS STRING EXAMPLE....WOW!!!"
print(str.lower())

str = "this is string example....wow!!! this is really string"
print(str.replace("is", "was"))

str = "this is string example....wow!!!"
print(str.swapcase())


str = "this is string example....wow!!!"
print(str.title())


list = ['abcd', 786, 2.23, 'john', 70.2]
tinylist = [123, 'john']
print(list)  # Prints compe list
print(list[0])  # Prints first element of the list
print(list[1:3])  # Prints elements starting from 2nd till 3rd
print(list[2:])  # Prints elements starting from 3rd element
print(tinylist * 2)  # Prints list two times
print(list + tinylist)  # Prints concatenated lists

list = ['physics', 'chemistry', 1997, 2000]
list.append('maths')

del list[2]
print(list)

print(list.count('physics'))

list = ['physics', 'chemistry', 1997, 2000]
list.pop()
print(list)

list = ['physics', 'chemistry', 1997, 2000]
list.insert(2, 'maths')
print(list)

list = ['physics', 'chemistry', 1997, 2000]
list.remove('chemistry')
print(list)

list = ['physics', 'chemistry', 1997, 2000]
list.reverse()
print(list)

tuple = ('abcd', 786, 2.23, 'john', 70.2)
list = ['abcd', 786, 2.23, 'john', 70.2]
# tuple[2] = 1000  # Invalid syntax with tuple
list[2] = 1000  # Valid syntax with list

print(tuple)
print(list)

num = float(input('Enter a number: '))
if num > 0:
    print('pos number')
elif num == 0:
    print('zero')
else:
    print('Neg number')


x = float(input('Enter a number:'))
if x < 10:
    print('smaller')
if x > 20:
    print('bigger')
print('Finished')


x = 5
print('Before 5')
if x == 5:
    print('this is 5')
    print('still 5')
print('After 5')
print('Before 6')
if x == 6:
    print('this is 6')
print('After 6')


x = float(input('Enter a number: '))
if x < 20:
    print('Below 20')
elif x < 10:
    print('Below 10')
else:
    print('something else')

x = 42
if x > 1:
    print('above one')
if x < 100:
    print('less than 100')
print('All done')

age = 15
b = ('kid' if age < 18 else 'adult')
print(b)
# this will print 'kid'

for val in [5, 4, 3, 2, 1]:
    print(val)
print('Done')

stud = ['Ram', 'Vijay', 'Nithya', 'Anu', 'Ramesh', 'suja']
for k in stud:
    print('Hello: ', k)
print('done')


for i in range(5):
    print(i)
    if i > 2:
        print('Bigger than 2')
    print('Done with i', i)


x = int(input('Enter a number: '))
for i in range(1, x+1):
    if x % i == 0:
        print(i)
x = 10

x = [9, 41, 12, 3, 74, 15]
Largest = -math.inf
for i in x:
    if i > Largest:
        Largest = i
print(Largest)

x = [9, 41, 12, 3, 74, 15]
smallest = math.inf
for i in x:
    if i < smallest:
        smallest = i
print(smallest)

x = [9, 41, 12, 3, 74, 15]
count = sum = avg = 0
for i in x:
    count = count+1
    sum = sum+1
avg = sum/count
print(count)
print(sum)
print(avg)


x = [9, 41, 12, 3, 74, 15]
for i in x:
    if i > 20:
        print(i)

x = [9, 41, 12, 3, 74, 15]
res = []
for i in x:
    if i > 20:
        res.append(i)

y = np.zeros(len(x))
for i in range(len(x)):
    if x[i] > 20:
        y[i] = x[i]
print(y)
