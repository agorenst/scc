scc: scc.cpp
	clang++ -std=c++0x -Wall -O3 scc.cpp -o scc
clean:
	rm -f *~ scc
