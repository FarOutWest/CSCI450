from sys import *
import re
from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
import cliserlex

numbers = cliserlex.numbers
dec_numbers = []

def plot(V1,V2,V3):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    # Plot a basic wireframe.
    ax.plot_wireframe(V1, V2, V3, rstride=10, cstride=10)
    return plt

def generate_slices():
    decs = []
    powers = []
    for j in numbers:
        val = ""
        pos = 0
        for char in j:
            if char == "-":
                val += char
            if re.match("[0-9]", char):
                val += char
            if char == ".":
                val += char
            elif char == "e":
                decs.append(val)
                val = ""
            elif char == "+":
                val = ""
            if pos == len(j)-1:
                powers.append(val)
            pos += 1
    iterator = 0
    for iterator in range(len(decs)):
        if float(decs[iterator]) == 0.0:
            dec_numbers.append(0.0)
        else:
            tempa = (float(decs[iterator]))
            tempb = (float(powers[iterator]))
            if tempa < 0:
                dec_value = tempa**tempb
                dec_value = dec_value * -1
            else:
                dec_value = tempa**tempb
            #print("Calculation = ",float(decs[iterator]),"^",float(powers[iterator])," = ",dec_value)
            dec_numbers.append(dec_value)

    splits = [dec_numbers[x:x+3] for x in range(0, len(dec_numbers),3)]
    normal_count = 0
    vertex_count = 0
    normals = []
    vertexes = []
    i = 1
    for i in range(len(splits)):
        if i%4 == 0:
            normals.append(splits[i])
            normal_count += 1
            continue
        else:
            vertexes.append(splits[i])
            vertex_count += 1
    #print("\nDEC_NUMBERS: ", dec_numbers)
    #print("\nSPLITS: ", splits)
    print("\nNORMALS: ", normals)
    print("\nVERTEXES: ", vertexes,'\n')

    print(vertex_count,"Vertecies Found")
    print(normal_count,"Normals Found")

    V1 = vertexes[::3]
    V2 = vertexes[1::3]
    V3 = vertexes[2::3]

    vert = 0
    for vert in range(len(V1)):
        tmp_plt1 = V1[vert]
        tmp_plt2 = V2[vert]
        tmp_plt3 = V3[vert]
        plt = plot(tmp_plt1, tmp_plt2, tmp_plt3)
    plt.show()
