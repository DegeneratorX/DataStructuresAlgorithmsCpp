#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

class Graph{
private:
    std::unordered_map<string, std::unordered_set<string>> adjList;
    
public:
    void printGraph(){
        for(auto [vertex, edges] : adjList){
            cout << vertex << ": [";
            for(auto edge: edges){
                cout << edge << " ";
            }
            cout << "]" << endl;
        }
    }

    bool addVertex(string vertex){
        if (adjList.count(vertex) == 0){
            adjList[vertex];
            return true;
        }
        return false;
    }
};