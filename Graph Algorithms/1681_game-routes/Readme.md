Same as the longest flight route :
Here too we are using same Topological sort for ordering purpose .
but here the route can be different at every state if a single edge is different .
so at the end of topological sort we apply a dp over topo vector for checking how much route reach n .
directly by taking 1 as 1 and adding the route comming from previous every route will come and update again and again the value of final node .