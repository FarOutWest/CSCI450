#! /usr/bin/env python3
import sys
import unicodedata

print('-------------------------------------------------------------')
print("Unicodedata Decryption")
print('-------------------------------------------------------------')
print('')

chars = open('chars.txt', 'r')
w = chars.read()
print('chars.txt: ', w)
chars.close()

#u = chr(233) + chr(0x0bf2) + chr(3972) + chr(6000) + chr(13231)
#print('u: ', u)

print('-------------------------------------------------------------')
print('')

for i, c in enumerate(w):   #(chars.read()): #(u):
    print(i, '%04x' % ord(c), unicodedata.category(c), end = " ")
    print(unicodedata.name(c))

print('')
print('-------------------------------------------------------------')
