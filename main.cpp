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

	//Test cast that works perfectly
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;
	int g = 7;
	int h = 8;
	int i = 9;
	int j = 10;
	int k = 11;
	int l = 12;

	vector<int *> aa = {&b, &c};
	vector<int *> ab = {&a, &d, &e};
	vector<int *> ac = {&a, &e, &f};
	vector<int *> ad = {&a, &b};
	vector<int *> ae = {&b, &c};
	vector<int *> af = {&c, &h, &i};
	vector<int *> ag = {&i};
	vector<int *> ah = {&e, &f, &j, &k};
	vector<int *> ai = {&f, &g, &j};
	vector<int *> aj = {&h, &i, &l};
	vector<int *> ak = {&h, &l};
	vector<int *> al = {&j, &k};

	Graph<int> gr;
	gr.addVertex(&a, aa);
	gr.addVertex(&b, ab);
	gr.addVertex(&c, ac);
	gr.addVertex(&d, ad);
	gr.addVertex(&e, ae);
	gr.addVertex(&f, af);
	gr.addVertex(&g, ag);
	gr.addVertex(&h, ah);
	gr.addVertex(&i, ai);
	gr.addVertex(&j, aj);
	gr.addVertex(&k, ak);
	gr.addVertex(&l, al);

	gr.printGraph();


	return 0;
}
