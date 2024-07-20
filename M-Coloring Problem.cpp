class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int node, bool graph[101][101],int color[],int n , int col){
        for(int k = 0 ; k < n;k++){
            //if its not same node and has same color 
            if(k != node && graph[k][node]  && color[k] == col)return false;
        }
        return true;
    }
    bool solve(int node,bool graph[101][101],int m , int n, int color[]){
        if(node == n) return true;
        
        for(int i = 1; i <= m ; i++){
          //if its safe to put color --> then we can put colors
            if(isSafe(node,graph,color,n,i)){
              //put color
                color[node] = i;
                if(solve(node+1,graph,m,n,color)) return true;
              //remove color 
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        
        int color[101] = {0};
        if(solve(0,graph,m,n,color)) return true;
        return false;
    }
};
