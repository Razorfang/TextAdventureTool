/*
 * main.cpp
 *
 *  Created on: 3/06/2017
 *      Author: jamie
 */

#include <iostream>
using namespace std;

#include "Graph/graph.h"

int main() {

	Vertex<int> v1;
	Vertex<int> v2;
	Edge<int> e(&v1, &v2);
	WeightedEdge<int> we(&v1, &v2, 100);

	cout << we.getWeight() << endl;
	we.setWeight(19);
	cout << we.getWeight() << endl;
	return 0;
}
