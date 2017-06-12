/*
 * storynode.cpp
 *
 *  Created on: 12/06/2017
 *      Author: jamie
 */

#include "storynode.h"

#include <iostream>
using namespace std;

StoryNode::StoryNode(int id) {
	this->id = id;
}

StoryNode::~StoryNode() {

}

bool StoryNode::operator==(const StoryNode& sn) const {
	return (this->id == sn.id);
}

int StoryNode::getId() const{
	return this->id;
}

void StoryNode::setId(int id) {
	this->id = id;
}
