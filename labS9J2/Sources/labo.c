#include "labo.h"

/*
* Creer une matrice d'adjacence. Mettre len a 0. Mettre max_size a max_nodes.
* Allouer de la memoire pour le max de noeud specifier i.e. pour graph->nodes.
* Pour chaque noeud de graph->nodes mettre le cost et path_from a UINT8_MAX et visited a 0.
* 
* Pour adjGraph, allouer une quantiter de int* relatif a la valeur de max_nodes.
* Dans chaque int* allouer un tableau de int relatif a la valeur max_nodes.
* A chaque index de adjGraph mettez son cout a 0.
* 
* 
* Retourner le graph creer.
*/
AdjMatrix* create_graph(size_t max_nodes){
	AdjMatrix* newMatrix;
	newMatrix = (AdjMatrix*)allocate(sizeof(AdjMatrix));
	newMatrix->len = 0;
	newMatrix->max_size = max_nodes;
	newMatrix->nodes = (Node*)allocate(sizeof(Node)*max_nodes);
	newMatrix->nodes->cost = UINT8_MAX;
	newMatrix->nodes->path_from = UINT8_MAX;
	newMatrix->nodes->visited = 0;

	newMatrix->adjGraph = (int**)allocate(sizeof(int*)*max_nodes);

	for (int i = 0; i < max_nodes;i++) {
		newMatrix->adjGraph[i] = (int*)allocate(sizeof(int));
		for (int j = 0; j < max_nodes;j++) {
			newMatrix->adjGraph[i][j] = 0; // Censer etre le cost, mais je ne comprends pas comment l'atteindre....
		}
	}
	
	return newMatrix;
}

/*
* Creer un node, lui attribuer le data et l'ajouter dans la matrice d'adjacence.
*/
void add_node(AdjMatrix* graph, void* data){
	graph->nodes[graph->len++].data = data;

	return;
}

/*
* Ajouter un lien dans la matrice d'adjacence, d'un noeud a l'autre noeud, en specifiant le cout y etant relier.
*/
void add_edge(AdjMatrix* graph, int fromNode, int toNode, uint8_t cost){
	graph->adjGraph[fromNode][toNode] = cost;

	return;
}

/*
* Implementer l'algorithme de dijkstra.
*/
void dijkstra(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath){
	Queue* q = allocate(sizeof(Queue));
	queue_init(q);
	Node* currNode = startNodeIndex;
	Node* temp = endNodeIndex;

	/*currNode->visited = 1;
	currNode->cost = 0;

	while (currNode != temp) {

		for (int i = 0; i < graph->len;i++) {
			Node* adj = graph->adjGraph[i];
			if (adj != NULL && adj->visited != 1) {
				if (currNode->cost > temp->cost) {
					currNode->cost = temp->cost;
					currNode->path_from = temp;
				}
				queue_push(q, adj);
				adj->visited = 1;
				adj->data = temp;
			}
		}
	}*/
	

}
