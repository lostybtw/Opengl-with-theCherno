debug:
	g++ -c ./src/main.cpp -std=c++14 -m64 -g -Wall -I include && g++ *.o -o ./build/debug/main -lGL -lglfw -lGLEW  && ./build/debug/main
clean:
	rm -rf ./build/*.o
