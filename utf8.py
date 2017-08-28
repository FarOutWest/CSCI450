#! /usr/bin/env python3
import sys
import unicodedata

for i in range(0,55):
    print('-', end='')
print('')
print("Unicodedata Decryption using Python3")
for i in range(0,55):
    print('-', end='')
print('')

chars = open('chars.txt', 'r')
w = chars.read()
w = w[:-1]
print('chars.txt: ', w)
chars.close()

for i in range(0,55):
    print('-', end='')
print('')

for i, c in enumerate(w):   #(chars.read()): #(u):
    print(i, '%04x' % ord(c), unicodedata.category(c), end = " ")
    print(unicodedata.name(c))

for i in range(0,55):
    print('-', end='')
print('')
