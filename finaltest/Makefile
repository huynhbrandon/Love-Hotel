CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -g

OBJS = inputVal.o menu.o main.o Game.o Space.o Alex.o Jess.o Morgan.o Pat.o Robin.o lobby.o Player.o

SRCS = inputVal.cpp menu.cpp main.cpp Game.cpp Alex.cpp Jess.cpp Morgan.cpp Pat.cpp Robin.cpp lobby.cpp Player.cpp

HEADERS = menu.hpp inputVal.hpp Game.hpp Alex.hpp Jess.hpp Morgan.hpp Pat.hpp Robin.hpp lobby.hpp Player.hpp

main: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

#menu: Board.cpp Ant.cpp menu.cpp inputVal.cpp directionConvert.cpp main.cpp
#	g++ -g -std=c++11 inputVal.cpp Board.cpp Ant.cpp menu.cpp directionConvert.cpp main.cpp -o main

clean:
	rm menu.o inputVal.o main.o Game.o Space.o Alex.o Jess.o Morgan.o Pat.o Robin.o lobby.o Player.o main
