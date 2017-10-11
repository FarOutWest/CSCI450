CXXFLAGS=-std=gnu++11
all : cliser

cliser.lex.cpp : cliser.l
	flex -o cliser.lex.cpp cliser.l
	sed -i- -e 's/register //g' cliser.lex.cpp

cliser.tab.hpp cliser.tab.cpp : cliser.ypp
	bison -d -o cliser.tab.cpp cliser.ypp

#cliser.lex.o : cliser.lex.cpp cliser.tab.hpp ast.hpp cliser.hpp
#	$(CXX) $(CXXFLAGS) -c -o $@ $<

#ast.o : ast.cpp ast.hpp
#	$(CXX) $(CXXFLAGS) -c -o $@ $<

#generator.o : generator.cpp generator.hpp ast.hpp
#	$(CXX) $(CXXFLAGS) -c -o $@ $<

#cliser.tab.o : cliser.tab.cpp  ast.hpp cliser.hpp generator.hpp
#	$(CXX) $(CXXFLAGS) -c -o $@ $<

#cliser : cliser.tab.o cliser.lex.o ast.o generator.o
#	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

#clean :
#	/bin/rm -rf \#* *~ *.o cliser cliser.tab.cpp cliser.tab.hpp cliser.lex.cpp
