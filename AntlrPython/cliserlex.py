from sys import *
import re

tokens = []
token_types = []
numbers = []
dec_numbers = []

def lex(filecontents):
    token = ""
    for line in filecontents:
        #print("LINE: ", line)
        for word in line:
            #print("WORD: ", word)
            token += word
            if "facet" == token.lower():
                token += " "
            elif "facet normal" == token.lower():
                token_types.append("FACET NORMAL")
                tokens.append(token)
                token = ""
            elif "outer" == token.lower():
                token += " "
            elif "outer loop" == token.lower():
                token_types.append("OUTER LOOP")
                tokens.append(token)
                token = ""
            elif "vertex" == token.lower():
                token_types.append("VERTEX")
                tokens.append(token)
                token = ""
            elif re.match("-?[0-9]+", token):
                token_types.append("NUMBER")
                tokens.append(token)
                numbers.append(token)
                token = ""
            elif "endloop" == token.lower():
                token_types.append("END LOOP")
                tokens.append(token)
                token = ""
            elif "endfacet" == token.lower():
                token_types.append("END FACET")
                tokens.append(token)
                token = ""
    #print("TOKENS = ", tokens,'\n')
    #print("TOKEN_TYPES = ", token_types, '\n')
    #print("NUMBERS = ", numbers, '\n')
    return tokens
