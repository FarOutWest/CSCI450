from sys import *
import cliserlex

nums = cliserlex.numbers

def parse(toks):
    if(len(nums)%3 == 0):
        print("LEXING AND PARSING FINISHED. \nNO ERRORS IN INPUT.")
    else:
        print("PARSE FAILED. \nINVALID NUMBER OF VERTICIES AND/OR NORMALS")
