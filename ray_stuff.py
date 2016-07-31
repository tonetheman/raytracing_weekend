
class vec3:
	def __init__(self,x,y,z):
		self.e = [float(x),float(y),float(z)]
	def __repr__(self):
		return str(self.e[0]) + " " + str(self.e[1]) + " " + str(self.e[2])
	def length(self):
		import math
		return math.sqrt(self.e[0]*self.e[0] +
			self.e[1]*self.e[1] +
			self.e[2]*self.e[2])
	def scalar_mult(self, val):
		return vec3(self.e[0]*val, self.e[1]*val, self.e[2]*val)
	def add(self, other):
		return vec3(self.e[0]+other.e[0],
			self.e[1]+other.e[1],
			self.e[2]+other.e[2])


def point_at_param(t,a,b):
	return a.add( b.scalar_mult(t) )

origin = vec3(0,0,0)
head = vec3(1,1,0)

print "t is time"
print "if t is 0"
t = 0
print "point at param", point_at_param(t,origin,head)
print "if t is 1"
t = 1
print "point at param", point_at_param(t,origin,head)
print "if t is 0.5"
t = 0.5
print "point at param", point_at_param(t,origin,head)







