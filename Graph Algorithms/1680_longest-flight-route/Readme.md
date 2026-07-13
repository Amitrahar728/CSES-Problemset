Simple thought which can come or can say intution is that given problem is having a DAG only , means we can apply topo sort 
but actually we want to traverse complete tree therefore too we need toposort only via going through there parents only 

So whenever there is a sense of order topological sort is used 
& as it asks more maximum cities anything realted to max , longest we use dp to compute via bottom up approach .

**This is the flow**

Compute a topological order
Run dynamic programming over that order
Store a parent array as we need to reconstruct the path from last node 