reciprocal: main.o reciprocal.o
	g++ $(CFLAGS) -o reciprocal main.o reciprocal.o
	
main.o: main.c reciprocal.hpp		
	gcc $(CFLAGS) -c -I ../headers main.c
	 
reciprocal.o: reciprocal.cpp reciprocal.hpp
	g++ $(CFLAGS) -c -I ../headers reciprocal.cpp
	 
clean:
	rm -f *.o reciprocal
