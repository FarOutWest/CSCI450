from sys import *
import re
import cliserparse
import cliserlex
import clisergenerator

tokens = cliserlex.tokens
token_types = cliserlex.token_types
numbers = cliserlex.numbers
dec_numbers = clisergenerator.dec_numbers

def open_file(filename):
    f = open(filename, "r")
    STL_DESCRIPTION = f.readline()
    data = f.readlines()
    data = [x.strip(' ') for x in data]
    data = [x.strip('\n') for x in data]
    data = [x.split() for x in data]
    return data

def run():
    data = open_file(argv[1])
    toks = cliserlex.lex(data)
    cliserparse.parse(toks)
    clisergenerator.generate_slices()

run()
