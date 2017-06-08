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

template <typename T>
class Vertex {
	private:
		T *value; //Store by reference to avoid copying large classes
	public:
		Vertex(T *value);
		T *getValue() const;
		void setValue(T *value);

		//Equality check. This also requires an equality check to exist for T. If it does not (e.g. custom class), make sure you impemented one
		bool operator==(const Vertex<T>& v) const{
			return (this->value == v.value);
		}
};

template <typename T>
Vertex<T>::Vertex(T *value) {
	this->value = value;
}

template <typename T>
T *Vertex<T>::getValue() const{
	return this->value;
}

template <typename T>
void Vertex<T>::setValue(T *value) {
	this->value = value;
}

//If you want to hash a vertex, T needs a way of being hashed
namespace std {
	template<typename T> struct hash<Vertex<T>> {
		size_t operator()(Vertex<T> const& v) const {
			return hash<T>{}(*(v.getValue()));
		}
	};
}


template <typename T>
class Graph {
private:
	//Now I know what you're thinking. Graph theory taught me that a graph needs a set of nodes, and an adjacency list.
	//All you've given us is an adjacency list.
	//Well, since we need to use our nodes as keys, the set of keys is equivalent to the set of nodes. So there.

	unordered_map<Vertex<T>, std::vector<Vertex<T>>> adjacencyList;

public:
	Graph(); //Needs a hash function. For example, if your vertices are storing std::pairs, we need a hash to convert the pair into a key
			 //Since I don't know what you will be storing, you should provide a hash function
	~Graph();
	//Since we are initialising a new object, v must be whatever we are using to initialise our vertices
	void addVertex(T *value, std::vector<T *> adjacent);
	void removeVertex(T *value);
	void printGraph();
};

template <typename T>
Graph<T>::Graph() {
}

template <typename T>
Graph<T>::~Graph() {
}

//NOTE: Should we allow something to be its own neighbor? This might be good for repeating something in the vertex over and over....
//Also, should we allow a vertex to add a neighbor that does not currently exist
template <typename T>
void Graph<T>::addVertex(T *value, std::vector<T *> adjacent) {

	//Check that the value does not already exist
	Vertex<T> v = Vertex<T>(value);
	if (this->adjacencyList.find(v) == this->adjacencyList.end()) {
		std::vector<Vertex<T>> adj;
		for (unsigned int i = 0; i < adjacent.size(); i++) {
			Vertex<T> vAdj = Vertex<T>(adjacent[i]);
			adj.push_back(vAdj);
		}
		this->adjacencyList.insert(make_pair(v, adj));
	}
		//If the values does not exist, place it and the adjacency in there
		//Otherwise, do nothing


}

template <typename T>
void Graph<T>::removeVertex(T *value) {
	//Check that the value does not already exist
	//if (this->adjacencyList.find(Vertex<T>(value)) != this->adjacencyList.end()) {
		this->adjacencyList.erase(Vertex<T>(value));
	//}

		//If we remove a vertex, we also need to remove it from all the other vertices' list of neighbors
		//Otherwise, we will have a reference to a vertex that does not exist
}

template <typename T>
void Graph<T>::printGraph() {
	std::vector<Vertex<T>> keys;
	for(auto v: this->adjacencyList) {
		cout << "KEY: " << *(v.first.getValue()) << endl;
		for (auto vAdj: v.second) {
			cout << "VALUE: " << *(vAdj.getValue()) << endl;
		}
	}

}
#endif /* GRAPH_GRAPH_H_ */

/*template <typename T>
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
};*/
