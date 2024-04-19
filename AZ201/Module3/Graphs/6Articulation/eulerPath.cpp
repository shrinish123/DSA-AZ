// procedure FindEulerPath(V)
//   1. iterate through all the edges outgoing from vertex V;
//        remove this edge from the graph,
//        and call FindEulerPath from the second end of this edge;
//   2. add vertex V to the answer.


///  
// eulerPath(node) : 
//   
//  for(edges : node)
//     remove the edge 
//     eulerPath(node on the other edge)
// 
//   push node to answer
// 
