#Makefile
FLAGS = -pedantic-errors -std=c++11
#FLAGS for c++11
mergenameandscore.o: mergenameandscore.cpp mergenameandscore.h
	g++ $(FLAGS) -c mergenameandscore.cpp
highscores.o: highscores.cpp highscores.h
	g++ $(FLAGS) -c highscores.cpp
bank_heist.o: bank_heist.cpp mergenameandscore.h highscores.h
	g++ $(FLAGS) -c bank_heist.cpp
bank_heist: mergenameandscore.o highscores.o bank_heist.o
	g++ $(FLAGS) mergenameandscore.o highscores.o bank_heist.o -o bank_heist
clean:
	rm -f mergenameandscore.o highscores.o bank_heist.o bank_heist
.PHONY: clean
