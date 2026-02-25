#include "GrafLista.h"
#include "edge.h"
#include <deque>

Graf::Graf(){}

void Graf::createVertices(int ile){
    vertexList.resize(ile);
}

void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
    vertexList[i_Vertex_Index_1].push_back(edge(i_Vertex_Index_1, i_Vertex_Index_2));
}

bool Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
    for(auto it = vertexList[i_Vertex_Index_1].begin(); it != vertexList[i_Vertex_Index_1].end(); it++){
        if(it->vertex_Index2 == i_Vertex_Index_2){
            vertexList[i_Vertex_Index_1].erase(it);
            return true;
        }
    }
    return false;
}

bool Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
    for(const auto& e : vertexList[i_Vertex_Index_1]){
        if (e.vertex_Index2 == i_Vertex_Index_2){
            return true;
        } 
    }
    return false;
}

int Graf::vertexDegree(int idx){
    return vertexList[idx].size();
}

std::vector<int> Graf::getNeighbourIndices(int idx){
    std::vector<int> neighbours;
    for(const auto& e : vertexList[idx]){
        neighbours.push_back(e.vertex_Index2);
    }
    return neighbours;
}

void Graf::printNeighbourIndices(int idx){
    std::vector<int> neighbours = getNeighbourIndices(idx);
    for(int neighbour : neighbours){
        std::cout << neighbour << " ";
    }
    std::cout << std::endl;
}

int Graf::getNumberOfEdges(){
    int count = 0;
    for(const auto& vertex : vertexList){
        count += vertex.size();
    }
    return count;
}

void Graf::readFromFile(std::string path){
    std::ifstream file(path);
    if (file.is_open()){
        int vertex1, vertex2, numberOfVertices;
        file >> numberOfVertices;
        createVertices(numberOfVertices);
        while(file >> vertex1 >> vertex2){
            addEdge(vertex1, vertex2);
        }
        file.close();
    } else {
        std::cerr << "Blad w ladowaniu pliku" << std::endl;
    }
}

int main(){

    return 0;
}





