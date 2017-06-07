/*
 * main.cpp
 *
 *  Created on: 3/06/2017
 *      Author: jamie
 */

#include <iostream>
using namespace std;

#include "Graph/graph.h"

template <typename T>
size_t vertexHash (const Vertex<T> & v) {
	T value = v.getValue;
	return value;
}

int main() {

	/*Vertex<int> v1;
	ValuedVertex<int> v2(5);
	Edge<int> e(&v1, &v2);
	WeightedEdge<int> we(&v1, &v2, 100);

	cout << we.getWeight() << endl;
	we.setWeight(19);
	cout << we.getWeight() << endl;

	cout << v2.getValue() << endl;
	v2.setValue(36);
	cout << v2.getValue() << endl;*/

	//Because we are using an unordered set, we need to define a hash function for
	//Vertex<int>. We need to make a hash function for each of our types


	/*

	vector<Vertex<int>> va = {w, x};
	vector<Vertex<int>> wa = {v};
	vector<Vertex<int>> xa = {v};

	Graph<int> g;
	g.addVertex(v, va);
	g.addVertex(w, wa);
	g.addVertex(x, xa);*/

	/*Vertex<int> *v = new Vertex<int>(5);
	Vertex<int> *w = new Vertex<int>(7);
	Vertex<int> *x = new Vertex<int>(9);
	delete v;
	delete w;
	delete x;*/

	int v = 5;
	int w = 7;
	int x = 9;

	vector<int> av = {w, x};
	vector<int> aw = {v};
	vector<int> ax = {v};

	Graph<int> g;
	g.addVertex(v, av);
	g.addVertex(w, aw);
	g.addVertex(x, ax);

	g.printGraph();

	return 0;
}
