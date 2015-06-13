SYSTEMC_PATH=../systemc/systemc-2.3.1
INCLUDE_PATH=$(SYSTEMC_PATH)/include
LIB_PATH=$(SYSTEMC_PATH)/lib-linux64
CFLAGS=
CPPFLAGS=-W -Wall 
LINKFLAG=-lsystemc -lpthread -static
EXENAME=main.out
OBJECT=timer.o receiver.o transmit.o channel.o display.o main.o 

all : $(EXENAME)

%.o : %.cc
	$(CXX) $(CPPFLAGS) -I./ -I$(INCLUDE_PATH) -c $< -o $@

$(EXENAME) : $(OBJECT)
	$(CXX) -L$(LIB_PATH) $(OBJECT) $(LINKFLAG) -o $@

clean :
	$(RM) $(EXENAME) $(OBJECT)

ctags :
	ctags -R .
