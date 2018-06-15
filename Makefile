project4.exe:inputValidation.o menu.o main.o queue.o barbarian.o blueMen.o character.o harryPotter.o medusa.o vampire.o
	g++ -std=c++11 *.o -o project4.exe

barbarian.o:barbarian.cpp barbarian.hpp
	$(makeObj) barbarian.cpp

blueMen.o:blueMen.cpp blueMen.hpp
	$(makeObj) blueMen.cpp

character.o:character.cpp character.hpp
	$(makeObj) character.cpp

harryPotter.o:harryPotter.cpp harryPotter.hpp
	$(makeObj) harryPotter.cpp

medusa.o:medusa.cpp medusa.hpp
	$(makeObj) medusa.cpp

vampire.o:vampire.cpp vampire.hpp
	$(makeObj) vampire.cpp

queue.o:queue.cpp queue.hpp
	$(makeObj) queue.cpp

menu.o:menu.cpp menu.hpp
	$(makeObj) menu.cpp

main.o:main.cpp
	$(makeObj) main.cpp

inputValidation.o:inputValidation.cpp inputValidation.hpp
	$(makeObj) inputValidation.cpp

clean:
	rm *.o project4.exe

zip:
	zip -D Hall_Kenneth_Project4.zip *.cpp *.hpp *.pdf Makefile

makeObj = g++ -std=c++11 -c
