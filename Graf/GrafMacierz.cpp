#include "Graf.h"

Graf::Graf(){
    clear();
}

void Graf::createVertices(int ile){
    numberOfVertices = ile;
    clear();
}

void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
    matrix[i_Vertex_Index_1][i_Vertex_Index_2] = 1;
    matrix[i_Vertex_Index_2][i_Vertex_Index_1] = 1;
}

void Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
    matrix[i_Vertex_Index_1][i_Vertex_Index_2] = 0;
    matrix[i_Vertex_Index_2][i_Vertex_Index_1] = 0;
}

bool Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
    return matrix[i_Vertex_Index_1][i_Vertex_Index_2] == true;
}

int Graf::vertexDegree(int idx){
    int degree = 0;
    for(int i = 0; i < numberOfVertices; i++ ){
        degree += matrix[idx][i];
    }
    return degree;
}

std::vector<int> Graf::getNeighbourIndices(int idx){
    std::vector<int> neighbours;
    for(int i = 0; i < numberOfVertices; i++){
        if (matrix[idx][i] == 1){
            neighbours.push_back(i);
        }
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
    for(int i = 0; i < numberOfVertices; i++){
        for(int j = 0; j < numberOfVertices; j++){
            if(matrix[i][j] == 1){
                count++;
            }
        }
    }
    return count;
}

void Graf::readFromFile(std::string path){
    std::ifstream file(path);
    if (file.is_open()){
        int vertex1, vertex2;
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

void Graf::clear(){
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            matrix[i][j] = 0;
        }
    }
}


void test1()
{
    Graf* G = new Graf();    
    G->createVertices(10);
    G->addEdge(1, 2);
    G->addEdge(2, 3);
    G->addEdge(1, 5);
    std::cout << G->vertexDegree(1)<<"\n";
    std::cout << G->vertexDegree(8) << "\n";
    G->printNeighbourIndices(1);
    G->printNeighbourIndices(1);
    std::cout << G->checkEdge(1, 2)<<"\n";
    G->removeEdge(1, 2);
    G->printNeighbourIndices(1);
    std::cout << G->checkEdge(1, 2) << "\n\n\n\n\n";  
}

void test2()
{
    Graf* G = new Graf();
    G->readFromFile("C:\\Users\\benio\\OneDrive\\Pulpit\\AiSD\\GrafL.txt");
    G->printNeighbourIndices(1);
    std::cout << G->getNumberOfEdges();
}

int main()
{
    test1();
    test2();  
}




