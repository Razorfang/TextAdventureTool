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
	ValuedVertex<int> v2(5);
	Edge<int> e(&v1, &v2);
	WeightedEdge<int> we(&v1, &v2, 100);

	cout << we.getWeight() << endl;
	we.setWeight(19);
	cout << we.getWeight() << endl;

	cout << v2.getValue() << endl;
	v2.setValue(36);
	cout << v2.getValue() << endl;
	return 0;
}
