#! /usr/bin/env python3
import sys
import unicodedata

print('')
print('-------------------------------------------------------------')
print("Unicodedata Decryption")
print('-------------------------------------------------------------')

chars = open('chars.txt', 'r')
w = chars.read()
w = w[:-1]
print('chars.txt: ', w)
chars.close()

print('-------------------------------------------------------------')

for i, c in enumerate(w):   #(chars.read()): #(u):
    print(i, '%04x' % ord(c), unicodedata.category(c), end = " ")
    print(unicodedata.name(c))

print('-------------------------------------------------------------')
print('')
