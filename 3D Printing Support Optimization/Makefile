CC = gcc
CXX = g++ -std=c++0x
AR = ar
LD = g++ -std=c++0x
WINDRES = windres

CFLAGS = -Wall -w

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)-lglut -lGL -lglui
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/
OUT_DEBUG = clever_support/clever_support
OBJ_DEBUG = $(OBJDIR_DEBUG)/main.o

all: debug

clean: clean_debug

before_debug: 
	test -d clever_support/ || mkdir -p clever_support
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) 
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/main.o: main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.cpp -o $(OBJDIR_DEBUG)/main.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf $(OBJDIR_DEBUG)

.PHONY: before_debug after_debug clean_debug

