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

#include <unordered_set>
#include <unordered_map>
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

//Useful for if you want to make data storage, such as a tree
//T should be a single object or class that contains everything you need to know, such as a StoryNode
template <typename T>
class ValuedVertex: public Vertex<T> {
	private:
		T value;
	public:
		ValuedVertex(T value);
		T getValue();
		void setValue(T value);
};

template <typename T>
ValuedVertex<T>::ValuedVertex(T value): Vertex<T>::Vertex() {
	this->value = value;
}

template <typename T>
T ValuedVertex<T>::getValue() {
	return this->value;
}

template <typename T>
void ValuedVertex<T>::setValue(T value) {
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
class DirectedEdge: public Edge<T> {
};


template <typename T>
class Graph {
private:
	//All the vertexes. Kept in an unordered set because adding/removing vertexes won't happen often, but accessing them will
	//Will need a hash function to get the correct index of a graph node. Also need to watch out for hash collisions
	unordered_set<Vertex<T>> vertices;
	//Adjacency list. Like the vertices, this will not change often. The same indexes will be used as the vertices
	unordered_map<Vertex<T>, unordered_set<Vertex<T>>> adjacencyList;

public:
	Graph();
	~Graph();
	void addVertex(Vertex<T> v, unordered_set<Vertex<T>> adjacent);
	void removeVertex(Vertex<T> v);
	void printGraph();
};

template <typename T>
Graph<T>::Graph() {
}

template <typename T>
Graph<T>::~Graph() {
}

template <typename T>
void Graph<T>::addVertex(Vertex<T> v, unordered_set<Vertex<T>> adjacent) {
	this->vertices.insert(v);
	this->adjacencyList.insert(make_pair(v, adjacent));
}

template <typename T>
void Graph<T>::removeVertex(Vertex<T> v) {
	this->vertices.erase(v);
	this->adjacencyList.erase(v);
}

template <typename T>
void Graph<T>::printGraph() {
}
#endif /* GRAPH_GRAPH_H_ */
