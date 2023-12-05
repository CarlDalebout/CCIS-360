# Makefile for mygllib
# Y. Liow
#------------------------------------------------------------------------------
# Macros
#------------------------------------------------------------------------------
CXX       = g++
CXXFLAGS  = -g -Wall
LINK      = g++
OBJS      = Register.o 	\
			Token.o		\
			Machine.o	\
			main.o
EXE 		= main.exe

$(EXE): 	$(OBJS)
	$(LINK) $(OBJS) -o $(EXE)
#------------------------------------------------------------------------------
# Object files
#------------------------------------------------------------------------------
#config.o: config.h config.cpp  
#	$(CXX) $(CXXFLAGS) config.cpp -c -o config.o
#
#View.o: View.h View.cpp
#	$(CXX) $(CXXFLAGS) View.cpp -c -o View.o
#
#SingletonView.o: SingletonView.h SingletonView.cpp
#	$(CXX) $(CXXFLAGS) SingletonView.cpp -c -o SingletonView.o
#
#Reshape.o: Reshape.h Reshape.cpp
#	$(CXX) $(CXXFLAGS) Reshape.cpp -c -o Reshape.o
#
#Keyboard.o: Keyboard.h Keyboard.cpp
#	$(CXX) $(CXXFLAGS) Keyboard.cpp -c -o Keyboard.o
# 
# Vec4f.o: Vec4f.h Vec4f.cpp
# 	$(CXX) $(CXXFLAGS) Vec4f.cpp -c -o Vec4f.o
#
# Body.o: Body.h Body.cpp
# 	$(CXX) $(CXXFLAGS) Body.cpp -c -o Body.o
#
# Conversion.o: Conversion.h Conversion.cpp
# 	$(CXX) Conversion.cpp -c -o Conversion.o
#
# Manipulation.o: Manipulation.h Manipulation.cpp
# 	$(CXX) Manipulation.cpp -c -o Manipulation.o

Register.o: Register.h Register.cpp
	$(CXX) Register.cpp -c -o Register.o

Token.o: Token.h Token.cpp
	$(CXX) Token.cpp -c -o Token.o

Machine.o: Machine.h Machine.cpp
	$(CXX) Machine.cpp -c -o Machine.o

#------------------------------------------------------------------------------
# Utilities
#------------------------------------------------------------------------------
r:
	./main.exe
clean:
	rm -f main.exe
c:
	rm -f $(OBJS) main.exe
