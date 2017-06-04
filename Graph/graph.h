/*
 * tree.h
 *
 *	A graph library
 *
 *  Created on: 3/06/2017
 *      Author: jamie
 */

#ifndef GRAPH_GRAPH_H_
#define GRAPH_GRAPH_H_

#include <vector>
using namespace std;

template <typename T>
class Vertex {
	private:
	public:
		Vertex();
};

template <typename T>
Vertex<T>::Vertex () {

}


template <typename T>
class Edge {
	private:
		pair<Vertex<T> *, Vertex<T> *> edge; //Edge connects two vertexes
	public:
		Edge(Vertex<T> *first, Vertex<T> *second);
};

template <typename T>
Edge<T>::Edge (Vertex<T> *first, Vertex<T> *second) {
	this->edge = make_pair(first, second);
}


template <typename T>
class WeightedEdge: public Edge<T> {
	private:
		int weight;
	public:
		WeightedEdge(Vertex<T> *first, Vertex<T> *second, int weight);
		int getWeight();
		void setWeight(int weight);
};

template <typename T>
WeightedEdge<T>::WeightedEdge (Vertex<T> *first, Vertex<T> *second, int weight): Edge<T>::Edge (first, second) {

	this->weight = weight;
}

template <typename T>
int WeightedEdge<T>::getWeight() {
	return this->weight;
}

template <typename T>
void WeightedEdge<T>::setWeight(int weight) {
	this->weight = weight;
}


template <typename T>
class Graph {
	//adjacency list
};
#endif /* GRAPH_GRAPH_H_ */
