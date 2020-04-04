# All Targets
all: reviiot

# Tool invocations
# Executable "reviiot" depends on the files:
# Card.o, FigureCard.o,  NumericCard.o, Deck.o Hand.o.

reviiot: bin/Card.o bin/NumericCard.o bin/FigureCard.o bin/Deck.o bin/Hand.o bin/Player.o bin/PlayerType1.o bin/PlayerType2.o bin/PlayerType3.o bin/PlayerType4.o bin/Game.o bin/reviiyot.o

	@echo 'Building target: reviiot'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/reviiot bin/Card.o bin/NumericCard.o bin/FigureCard.o bin/Deck.o bin/Hand.o bin/Player.o bin/PlayerType1.o bin/PlayerType2.o bin/PlayerType3.o bin/PlayerType4.o bin/Game.o bin/reviiyot.o
	@echo 'Finished building target: reviiot'
	@echo ' '

# Depends on the source and header files
bin/Card.o: src/Card.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Card.o src/Card.cpp
	
# Depends on the source and header files
bin/NumericCard.o: src/NumericCard.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/NumericCard.o src/NumericCard.cpp

# Depends on the source and header files 
bin/FigureCard.o: src/FigureCard.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/FigureCard.o src/FigureCard.cpp
	
# Depends on the source and header files 
bin/Deck.o: src/Deck.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Deck.o src/Deck.cpp
	
# Depends on the source and header files 
bin/Hand.o: src/Hand.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Hand.o src/Hand.cpp

# Depends on the source and header files 
bin/Player.o: src/Player.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Player.o src/Player.cpp

# Depends on the source and header files 
bin/PlayerType1.o: src/PlayerType1.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PlayerType1.o src/PlayerType1.cpp	
	
# Depends on the source and header files 
bin/PlayerType2.o: src/PlayerType2.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PlayerType2.o src/PlayerType2.cpp	
	
# Depends on the source and header files 
bin/PlayerType3.o: src/PlayerType3.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PlayerType3.o src/PlayerType3.cpp		

# Depends on the source and header files 
bin/PlayerType4.o: src/PlayerType4.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PlayerType4.o src/PlayerType4.cpp		
	
# Depends on the source and header files 
bin/Game.o: src/Game.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Game.o src/Game.cpp			
		
# Depends on the source and header files 
bin/reviiyot.o: src/reviiyot.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/reviiyot.o src/reviiyot.cpp
		
	
#Clean the build directory
clean: 
	rm -f bin/* 
