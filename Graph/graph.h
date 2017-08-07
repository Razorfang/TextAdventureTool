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
#include <algorithm>
#include <unordered_map>

template <typename T>
class Vertex {
	private:
		T *value; //Store by const reference to avoid copying large classes
				  //Should this be const? There are situations where people might want to modify their graph data
					//If we make the pointer const, this is the same as making the thing it points to read-only
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
	bool isNeighbor(T *home, T *check);
	bool isComplete();
	std::vector<T *> getNeighbors(T *value);
	void printGraph();
};

template <typename T>
Graph<T>::Graph() {
}

template <typename T>
Graph<T>::~Graph() {
}

//NOTE: Should we allow something to be its own neighbor? This might be good for repeating something in the vertex over and over....
	//Try it out for now. If it causes problems in testing, then it'll be removed. It's not a bug, it's a feature.
//Also, should we allow a vertex to add a neighbor that does not currently exist
	//Yes, otherwise we could never add the first vertex. It wouldn't be allowed to have any neighbors!
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
}

//Note that this will not free any memory. This only removes the reference from the graph
//Any memory allocated outside the graph will need to be freed by you (yes, you)
template <typename T>
void Graph<T>::removeVertex(T *value) {

	//Not a problem, since value is just an address. It's not like we're copying an entire object. Vertex is a small class, too
	Vertex<T> outcast = Vertex<T>(value);

	//If we remove a vertex, we also need to remove it from all the other vertices' list of neighbors
	//Otherwise, we will have a reference to a vertex that does not exist
	std::vector<Vertex<T>> neighbors = this->adjacencyList[outcast];

	this->adjacencyList.erase(outcast);

	for (auto n: neighbors) {
		auto it = std::find(this->adjacencyList[n].begin(), this->adjacencyList[n].end(), outcast);
		if (it != this->adjacencyList[n].end()) {
			//I've read that if you don't care for order (like us), you can avoid overhead of moving items by
			//swapping the outcast with the item at the end of the container, then calling pop_back.
			std::swap(*it, this->adjacencyList[n].back());
			this->adjacencyList[n].pop_back();
		}
		else {
			cout << "Error, data entered incorrectly. Neighbors hate each other" << endl;
		}
	}
}

//We need to check that 'home' and 'check' actually exist first
template <typename T>
bool Graph<T>::isNeighbor(T *home, T *check) {
	Vertex<T> v1(home);
	Vertex<T> v2(check);
	auto it = std::find(this->adjacencyList[v1].begin(), this->adjacencyList[v1].end(), v2);
	if (it != this->adjacencyList[v1].end()) {
		return true;
	}
	else {
		return false;
	}
}

//This may be a long process, since we have to check everything is adjacent to everything else,
//And we can have thousands or millions of nodes
template <typename T>
bool Graph<T>::isComplete() {
	cout << "Not yet implemented" << endl;
	return false;
}

template <typename T>
std::vector<T *> Graph<T>::getNeighbors(T *value) {

	std::vector<T *> neighbors;
	for (auto n: this->adjacencyList[Vertex<T>(value)]) {
		neighbors.push_back(n.getValue());
	}
	return neighbors;
}

template <typename T>
void Graph<T>::printGraph() {
	std::vector<Vertex<T>> keys;
	for(auto v: this->adjacencyList) {
		cout << "KEY: " << (v.first.getValue())->getNodeId() << endl;
		for (auto vAdj: v.second) {
			cout << "VALUE: " << (vAdj.getValue())->getNodeId() << endl;
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
