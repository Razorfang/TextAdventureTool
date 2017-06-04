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
#include <unordered_map>
using namespace std;

template <typename T>
class Vertex {
	private:
		T value;
	public:
		Vertex(T value);
		T getValue();
		void setValue(T value);
};

template <typename T>
Vertex<T>::Vertex(T value) {
	this->value = value;
}

template <typename T>
T Vertex<T>::getValue() {
	return this->value;
}

template <typename T>
void Vertex<T>::setValue(T value) {
	this->value = value;
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
		long double weight;
	public:
		WeightedEdge(Vertex<T> *first, Vertex<T> *second, long double weight);
		int getWeight();
		void setWeight(long double weight);
};

template <typename T>
WeightedEdge<T>::WeightedEdge (Vertex<T> *first, Vertex<T> *second, long double weight): Edge<T>::Edge(first, second) {
	this->weight = weight;
}

template <typename T>
int WeightedEdge<T>::getWeight() {
	return this->weight;
}

template <typename T>
void WeightedEdge<T>::setWeight(long double weight) {
	this->weight = weight;
}

template <typename T>
class DirectedEdge: public Edge<T> {
};


template <typename T>
class Graph {
private:
	//Now I know what you're thinking. Graph theory taught me that a graph needs a set of nodes, and an adjacency list.
	//All you've given us is an adjacency list.
	//Well, since we need to use our nodes as keys, the set of keys is equivalent to the set of nodes. So there.
	unordered_map<Vertex<T>, vector<Vertex<T>>> adjacencyList;

public:
	Graph();
	~Graph();
	void addVertex(Vertex<T> v, vector<Vertex<T>> adjacent);
	void removeVertex(Vertex<T> v);
};

template <typename T>
Graph<T>::Graph() {
}

template <typename T>
Graph<T>::~Graph() {
}

template <typename T>
void Graph<T>::addVertex(Vertex<T> v, vector<Vertex<T>> adjacent) {
	this->adjacencyList.emplace(v, adjacent);
}

template <typename T>
void Graph<T>::removeVertex(Vertex<T> v) {
	this->adjacencyList.erase(v);
}

#endif /* GRAPH_GRAPH_H_ */
