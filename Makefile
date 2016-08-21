condense: scc condense.cpp
	clang++ -std=c++0x -Wall -O3 condense.cpp scc.o -o condense

print_scc: scc print_scc.cpp
	clang++ -std=c++0x -Wall -O3 print_scc.cpp scc.o -o print_scc
scc: scc.cpp
	clang++ -std=c++0x -Wall -O3 -c scc.cpp -o scc.o
clean:
	rm -f *~ *.o print_scc scc condense
