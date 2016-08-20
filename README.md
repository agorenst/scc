# scc
Strongly connected components

# Motivation
I had always thought that this algorithm seemed exotic and difficult for the simplicity of the concept.
Essentially, I imagined it was very finicky and pointer-manipulating-y, and all it would do is break a graph into its SCCs, which are intuitively very easily understood.
I suppose I like how algorithms can also provide a very good definition of what a certain concept is (e.g., the dynamic programming algorithm for optimizing matrix multiplication, ultimately, does very well in explaining what it's actually trying to do).

For a variety of reasons I buckled down and finally implemented it. It works on a grand total of two cases, so it must be correct.
The code is pretty much emulating what the Wikipedia page <https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm> describes, but it actually makes it work.

I'm very curious about the "distance" between the description of an algorithm, and a halfway-usable implementation. I found that this was a really good exercise on that topic.
