/*
The Main Algorithm (Pseudo Code)

v3 -> a vector with 3 floats {x,y,z}

LineSegment -> {v3 point0, point1}

Plane -> {v3 normal, float distance}

Triangle -> {v3 vertices[3], normal}

TriangleMesh -> {vector of Triangle}

read-stl-file -> generate a TriangleMesh ‘TM’

nSlices -> compute-number-of-slices using slice-size and 3D Model aabb

for each slice

– fix-a-cutting-plane using the slice-index

– for each Triangle in TriangleMesh

– – intersect(Triangle, Plane) -> find zero or two intersection points

– – take only the second case and generate a Line Segment from two points

– – Gather all Line Segment for this slice in a vector

output all line segments to an Ascii or Binary file for viewing or manipulating
*/
