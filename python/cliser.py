from sys import *
import re
import ast
import cliserparse
import cliserast
import cliserlex
import clisergenerator

tokens = cliserlex.tokens
token_types = cliserlex.token_types
numbers = cliserlex.numbers
dec_numbers = clisergenerator.dec_numbers

def open_file(filename):
    f = open(filename, "r")
    STL_DESCRIPTION = f.readline()
    nodes = f.readlines()
    nodes = [x.strip(' ') for x in nodes]
    nodes = [x.strip('\n') for x in nodes]
    nodes = [x.split() for x in nodes]
    return nodes

def run():
    nodes = open_file(argv[1])
    toks = cliserlex.lex(nodes)
    cliserparse.parse(toks)
    clisergenerator.generate_slices()

run()
