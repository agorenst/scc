# scc
Strongly connected components

# Motivation
The strongly connected components of a graph always seemed easy to understand, but the algorithms--even Tarjan's--seemed too complicated for such a simple concept.
Two thoughts from this:
1. I like how algorithm implementations can sometimes be the clearest explanation of what they do. Geometric algorithms and Dynamic Programming algorithms are two classes that come to mind.
2. There's a sort of "ratio" between the conceptual difficulty of the problem, and the conceptual difficulty of an efficient algorithm that solves the problem. I thought SCC fell on the wrong side of that ratio.

Motivated by 2-sat, I buckled down and finally implemented it. It works on a grand total of two cases, so it must be correct.
The code is pretty much emulating what the Wikipedia page <https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm> describes, but it actually makes it work.

I'm very curious about the "distance" between the description of an algorithm, and a halfway-usable implementation. I found that this was a really good exercise on that topic, and made a blog post.

# Files
1. scc.cpp is the file that contains the real "meat" of the algorithm, and is quite similar to the psuedocode on Wikipedia. It is not executable.
2. scc.h is the interface for scc.cpp.
3. print\_scc.cpp is the main demonstration of using scc, and printing it out.
4. condense.cpp implements a dead-stupid algorithm that collapses a graph into its strongly connected components.
