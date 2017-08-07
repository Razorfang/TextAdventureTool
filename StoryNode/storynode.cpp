/*
 * storynode.cpp
 *
 *  Created on: 12/06/2017
 *      Author: jamie
 */

#include "storynode.h"

#include <iostream>
using namespace std;

int StoryNode::ID = 0;

StoryNode::StoryNode() {
	this->nodeID = ++ID;
}

StoryNode::~StoryNode() {

}

int StoryNode::getNodeId() const{
	return this->nodeID;
}
