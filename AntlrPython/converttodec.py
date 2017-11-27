def plot(normals,vertexes):
    V1 = vertexes[::3]
    V2 = vertexes[1::3]
    V3 = vertexes[2::3]

    vert = 0
    for vert in range(len(V1)):
        tmp_plt1 = V1[vert]
        tmp_plt2 = V2[vert]
        tmp_plt3 = V3[vert]
        fig = plt.figure()
        ax = fig.add_subplot(111, projection='3d')
        ax.plot_wireframe(tmp_plt1,tmp_plt2,tmp_plt3, rstride=10, cstride=10)
        ax.set_xlabel('X')
        ax.set_ylabel('Y')
        ax.set_zlabel('Z')
    return plt


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
