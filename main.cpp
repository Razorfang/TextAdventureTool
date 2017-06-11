/*
 * main.cpp
 *
 *  Created on: 3/06/2017
 *      Author: jamie
 */

#include <iostream>
using namespace std;

#include "Graph/graph.h"
#include "StoryNode/storynode.h"

int main() {

	StoryNode s1 = StoryNode(1);
	StoryNode s2 = StoryNode(2);
	StoryNode s3 = StoryNode(3);

	vector<StoryNode *> a1 = {&s2, &s3};
	vector<StoryNode *> a2 = {&s1};
	vector<StoryNode *> a3 = {&s1};

	Graph<StoryNode> g;

	g.addVertex(&s1, a1);
	g.addVertex(&s2, a2);
	g.addVertex(&s3, a3);

	g.printGraph();
	cout << g.isNeighbor(&s1, &s3) << endl;

	g.removeVertex(&s1);

	cout << "********" << endl;
	g.printGraph();
	cout << g.isNeighbor(&s1, &s3) << endl;

	return 0;
}
