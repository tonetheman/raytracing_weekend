

W = 640
H = 480

W = float(W)
H = float(H)

invWidth = 1/W
invHeight = 1/H

print "width",W,"height",H
print "invWidth and invHeight", invWidth, invHeight

fov = float(30)
aspectratio = W/H

print "fov", fov, "aspectratio", aspectratio

import math
PI=3.14159

angle = math.tan(PI * 0.5 * fov/180.0)

print "angle",angle

for y in range(int(H)):
	for x in range(int(W)):
		xx = (2 * ((x+0.5) * invWidth) - 1) * angle * aspectratio
		yy = (1 - 2 * ((y+0.5) * invHeight)) * angle
		print "xx yy",xx,yy
		

