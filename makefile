#Builds LoadedDice, Stats, Dice, Main into Lab B 
#Tyler Forrester
#7/2/2016
CXX = g++
OBJSSUM = LoadedDice.o
SRCSSUM = LoadedDice.cpp
OBJSAVG = Dice.o
SRCSAVG = Dice.cpp
OBJSL1 = Stats.o
SRCSL1 = Stats.cpp
OBJSL2 = main.o
SRCSL2 = main.cpp
HEADERS = LoadedDice.h
HEADERA = Dice.h
HEADERI = Stats.h
PROG = roll
all: $(PROG)

$(PROG): $(OBJSL2) $(OBJSSUM) $(OBJSAVG) $(OBJSL1)
	$(CXX) $(OBJSAVG) $(OBJSL2) $(OBJSSUM) $(OBJSL1) -o $(PROG)
$(OBJSL2): $(SRCSL2) $(HEADERS) $(HEADERA) $(HEADERI)
	$(CXX) -c $(SRCSL2)
$(OBJAVG): $(SCRSAVG) $(HEADERA) 
	$(CXX) -c $(SRCSAVG)
$(OBJSL1): $(SRCSL1) $(HEADERI)
	$(CXX) -c $(SRCSL1)
$(OBJSSUM): $(SRCSSUM) $(HEADERS)
	$(CXX) -c $(SRCSSUM)
clean:
	rm -rf *.o $(PROG)
