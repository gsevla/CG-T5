CFLAGS = -lm -lGL -lGLU -lglut
default:build
build: L5
run: L5.o
	g++ L5.cpp -lm -lGL -lGLU -lglut -o L5
	./L5

clean:
	rm *.o
	rm ${OUT_FILES}