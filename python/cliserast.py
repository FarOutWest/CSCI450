from sys import *
import ast

class FuncVisit(ast.NodeVisitor):
    def __init__(self):
        self.calls = []
        self.names = []
    def generic_visit(self, node):
        #print(type(node).__name__)
        ast.NodeVisitor.generic_visit(self, node)
    def visit_Name(self, node):
        self.names.append(node.id)
    def visit_Call(self, node):
        self.names = []
        ast.NodeVisitor.generic_visit(self, node)
        self.calls.append(self.names)
        self.names = []
    def visit_keyword(self, node):
        self.names.append(node.arg)
