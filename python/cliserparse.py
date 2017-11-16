from sys import *
import re

def parse(toks):
    i = 0
    passed = True
    while i < len(toks):
        if toks[i] == "FACET NORMAL":
            if toks[i+1] and toks[i+2] and toks[i+3] != "NUMBER":
                    print("ERROR INVALID ARGUMENTS FOR FACET")
                    passed = False
        if toks[i] == "END FACET":
            if toks[i+1] != "FACET NORMAL":
                    print("ERROR INVALID START OF NEW FACET")
                    passed = False
        if toks[i] == "OUTER LOOP":
            if toks[i+1] != "VERTEX":
                    print("ERROR LOOP DOES NOT CONTAIN PROPER VERTEXES")
                    passed = False
        if toks[i] == "VERTEX":
            if toks[i+1] and toks[i+2] and toks[i+3] != "NUMBER":
                    print("ERROR INVALID ARGUMENTS FOR VERTEX")
                    passed = False
        if toks[i] == "END LOOP":
            if toks[i+1] != "END FACET":
                    print("ERROR INVALID ENDING OF LOOP/FACET")
                    passed = False
        if toks[len(toks) - 1] == "endsolid ?[a-zA-z]*":
            print("ERROR INVALID EOF")
            passed = False
        i += 1
    if passed == True:
        print("LEXING AND PARSING FINISHED. \nNO ERRORS IN INPUT.")
