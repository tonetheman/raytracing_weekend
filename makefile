
all : mainline chap3

chap3 : chap3.cpp ray.h vec3.h vec3.cpp
	g++ -o chap3 chap3.cpp vec3.cpp

mainline : mainline.cpp vec3.cpp vec3.h
	g++ -o mainline mainline.cpp vec3.cpp

clean :
	rm -rf mainline
	rm -rf chap3


