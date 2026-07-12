As the Given problem is taking about dependencies of one course over other .
-> its a  sign of topological sort

**(The Given Problem should be DAG)**
Otherwise return "IMPOSSIBLE"

Process of Topo Sort :
1.) calculate all indegrees start from any node having indegree 0 means having no prerequistes .


2.) reduce indegree of nodes connected to it 
whenever a new node indegree becomes 0 push it to the queue and do traverse continuosly 

3.) At any point if there is no node in queue with indegree 0 and still somecourses are left means "IMPOSSIBLE" 

4.) at the end return the order 

