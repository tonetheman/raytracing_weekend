
class vec3:
	def __init__(self,x,y,z):
		self.e = [float(x),float(y),float(z)]
	def length(self):
		import math
		return math.sqrt(self.e[0]*self.e[0] +
			self.e[1]*self.e[1] +
			self.e[2]*self.e[2])




