

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

// graph representation : adjacency list

class agraph{
// by default private members
int nV;
std::list<int> *adj_list;
bool * visitor_box;



public : //from here on all members are public untill  another access specifier is used

//constructor
agraph(int nv){

this->nV = nv;  // to be used inside the graph class
adj_list = new std::list<int>[nv];  // array of lists

// for dfs_recursive
visitor_box = new bool[nV];
// making all false at first
for (int i = 0; i<nV; i++){visitor_box[i] = false;}

}

//destructor
~agraph(){
delete [] adj_list;
delete [] visitor_box;
}


// adding an edge
void add_edge(int a,int b, int k){ // add edge between vertices a and b
adj_list[a].push_back(b); 
if (k == 0){ // for undirected graph
adj_list[b].push_back(a);
}

}


// bfs
void bfs(int a){

std::queue<int> q;
bool *visitor_box = new bool[nV];
// making all false at first
for (int i = 0; i<nV; i++){visitor_box[i] = false;}
//std::cout<<visitor_box[0]<<"\n";

// for the first vertex push it to the queue
// and mark it visited in visitor box
visitor_box[a] = true;
q.push(a);

while(!q.empty()){ // while queue q is not empty
//save front of queue to some variable
int front = q.front();
q.pop(); // remove front from queue
std::cout<<front<<" ";

// using iterator to see elements in list
for(auto itr = adj_list[front].begin() ; itr != adj_list[front].end(); itr++){ // iterating from start to end of adj_list
if(!visitor_box[*itr]){ // if not visited that vertex
q.push(*itr);
visitor_box[*itr] = true;
}

}

} // bfs 1st while end

delete [] visitor_box ;
}//bfs end

// dfs
void dfs(int a){
std::stack<int> stack1;
bool *visitor_box = new bool[nV];
// making all false at first
for (int i = 0; i<nV; i++){visitor_box[i] = false;}
//std::cout<<visitor_box[0]<<"\n";

// for the first vertex push it to the  stack
// and mark it visited in visitor box
visitor_box[a] = true;
stack1.push(a);

while(!stack1.empty()){ // while queue q is not empty
//save front of queue to some variable
int top = stack1.top();
stack1.pop(); // remove front from queue
std::cout<<top<<" ";

// using iterator to see elements in vector
for(auto itr = adj_list[top].begin() ; itr != adj_list[top].end(); itr++){ // iterating from start to end of adj_list
if(!visitor_box[*itr]){ // if not visited that vertex
stack1.push(*itr);
visitor_box[*itr] = true;
}

}

} // dfs 1st while end

delete[]  visitor_box ;
}//dfs end




// dfs_recursive
void dfsr(int a){
//std::stack<int> stack1;
//std::cout<<visitor_box[0]<<"\n";

// for the first vertex push it to the  stack
// and mark it visited in visitor box
visitor_box[a] = true;
//stack1.push(a);

//while(!stack1.empty()){ // while queue q is not empty
//save front of queue to some variable
//int top = stack1.top();
//stack1.pop(); // remove front from queue
std::cout<<a<<" ";

// using iterator to see elements in vector
for(auto itr = adj_list[a].begin() ; itr != adj_list[a].end(); itr++){ // iterating from start to end of adj_list
if(!visitor_box[*itr]){ // if not visited that vertex
//stack1.push(*itr);
//visitor_box[*itr] = true;
dfsr(*itr);
}

}

//} // dfs 1st while end

//delete[]  visitor_box ;
}//dfsr end


};


int main(){
int nV, a , nE, v1,v2;
std::cout<<"specify the no of vertices of a graph to be constructed : ";
std::cin >>nV;
std::cout<<"Enter the vertex number  from which bfs and dfs is needed : ";
std::cin>>a;

std::cout<< "No of edges to add to the graph : ";
std::cin>>nE;


agraph bgraph(nV);

for(int i = 1; i<=nE; i++){
std::cout<<"Enter the vertex pair that form the edge : ";
std::cin>>v1>>v2; 
bgraph.add_edge(v1,v2,0); // last argument to indicate directed or undirected grapH
}


std::cout<<"BFS : "; 
bgraph.bfs(a);
std::cout<<"\n";

std::cout<<"DFS : "; 
bgraph.dfs(a);
std::cout<<"\n";


std::cout<<"DFS_r : "; 
bgraph.dfsr(a);
std::cout<<"\n";

}
