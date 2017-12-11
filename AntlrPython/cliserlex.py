from sys import *
import re

tokens = []
token_types = []
numbers = []

def lex(filecontents):
    token = ""
    for line in filecontents:
        for word in line:
            token += word
            if re.match("-?[0-9]+\.?[0-9]+e?\+?\-?[0-9]+", token):
                token_types.append("NUMBER")
                tokens.append(token)
                numbers.append(token)
                token = ""
            else:
                token_types.append("WORD")
                tokens.append(token)
                token = ""
    return tokens
