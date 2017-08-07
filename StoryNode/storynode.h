/*
 * storynode.h
 *
 *  Created on: 7/06/2017
 *      Author: jamie
 */

#ifndef STORYNODE_STORYNODE_H_
#define STORYNODE_STORYNODE_H_

/*Story Nodes are self-contained units which contain what we are going to do at any given time*/
#include <algorithm>

class StoryNode {
private:
	static int ID; //Counter used to assign a unique ID to each node
	int nodeID; //Used to identify each part of the story. Used for comparison. Comes from ID
protected:
public:
	StoryNode();
	~StoryNode();
	int getNodeId() const;
};

//A way to hash a storynode. This is needed for the graphing library
//The hash is based on the ID of the node
namespace std {
	template<> struct hash<StoryNode> {
		size_t operator()(StoryNode const& sn) const {
			return hash<int>{}(sn.getNodeId());
		}
	};
}


#endif /* STORYNODE_STORYNODE_H_ */
