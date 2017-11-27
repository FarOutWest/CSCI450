from sys import *
import re
import numpy as np
from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
from matplotlib import cm
import cliserlex

numbers = cliserlex.numbers
dec_numbers = []

def generate_slices():
    splits = [numbers[x:x+3] for x in range(0, len(numbers),3)]
    normal_count = 0
    vertex_count = 0
    normals = []
    vertecies = []
    triangles = []
    _vertecies = []
    _triangles = []
    i = 1

    for i in range(len(splits)):
        if i%4 == 0:
            normals.append(splits[i])
            normal_count += 1
            continue
        else:
            vertecies.append(splits[i])
            vertex_count += 1

    #print("\nNUMBERS: ", numbers)
    #print("\nSPLITS: ", splits)
    #print("\nNORMALS: ", normals)
    #print("\nVERTECIES: ", vertecies,'\n')

    for verts in vertecies:
        counter = 0
        for values in verts:
            if counter == 0:
                _vertecies.append('[')
                _vertecies.append(values)
                _vertecies.append(',')
            if counter == 0:
                _vertecies.append(values)
                _vertecies.append(',')
            if counter == 2:
                _vertecies.append(values)
                _vertecies.append('],')
            counter += 1

    number = 0
    num = 0
    for verts in range(len(vertecies)):
        if num > 2:
            num = 0
        if num == 0:
            _triangles.append('[')
            _triangles.append(str(number))
            _triangles.append(',')
        if num == 1:
            _triangles.append(str(number))
            _triangles.append(',')
        if num == 2:
            _triangles.append(str(number))
            _triangles.append('],')
        num += 1
        number += 1


    #print("\nVERTECIES: ", _vertecies,'\n')
    #print("\nTriangles: ", _triangles)

    print(vertex_count,"Vertecies Found")
    print(normal_count,"Normals Found")

    poly = "polyhedron(\r\npoints=["
    for vert in _vertecies:
        poly += vert
    poly += "],\r\n  faces=["
    for trig in _triangles:
        poly += trig
    poly += "]);"
    module = "module object(scale) {"
    module = module + poly + "}\r\n\r\n"
    module = module + "object(1);"
    scad_object = open("object.scad", 'w')
    scad_object.write(module)
    scad_object.close()
