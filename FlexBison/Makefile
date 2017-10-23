CXXFLAGS=-std=gnu++11 -Iinclude
all : dirs bin/cliser tests

dirs : tmp bin
	if [ ! -d tmp ] ; then mkdir tmp; fi
	if [ ! -d bin ] ; then mkdir bin; fi

tmp/cliser.lex.cpp : src/cliser.l
	flex -o tmp/cliser.lex.cpp src/cliser.l
	sed -i- -e 's/register //g' tmp/cliser.lex.cpp

tmp/cliser.tab.hpp tmp/cliser.tab.cpp : src/cliser.ypp
	bison -d -o tmp/cliser.tab.cpp src/cliser.ypp

tmp/cliser.lex.o : tmp/cliser.lex.cpp tmp/cliser.tab.hpp include/ast.hpp include/cliser.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/ast.o : src/ast.cpp include/ast.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/generator.o : src/generator.cpp include/generator.hpp include/ast.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/cliser.tab.o : tmp/cliser.tab.cpp  include/ast.hpp include/cliser.hpp include/generator.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

bin/cliser : tmp/cliser.tab.o tmp/cliser.lex.o tmp/ast.o tmp/generator.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean :
	/bin/rm -rf \#* *~ *.o cliser cliser.tab.cpp cliser.tab.hpp cliser.lex.cpp cliser.lex.cpp- tests/*.out

.PHONY: tests
tests: bin/cliser
	c=1; while [ -f tests/cliser.$$c.in  ]; do if [ tests/cliser.$$c.out -ot tests/cliser.$$c.in -o tests/cliser.$$c.out -ot bin/cliser ] ; then ./bin/cliser < tests/cliser.$$c.in > tests/cliser.$$c.out ; fi ; c=$$(($$c+1)); done
