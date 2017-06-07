/*
 * storynode.h
 *
 *  Created on: 7/06/2017
 *      Author: jamie
 */

#ifndef STORYNODE_STORYNODE_H_
#define STORYNODE_STORYNODE_H_


class StoryNode {
private:
	int id; //Used to identify each part of the story. Used for comparison
protected:
public:
	StoryNode();
	~StoryNode();
	bool operator==(const StoryNode& sn) const{
		return (this->id == sn.id);
	}
	int getId() const;
	void setId(int id);
};

int StoryNode::getId() const{
	return this->id;
}

void StoryNode::setId(int id) {
	this->id = id;
}

//A way to hash a storynode. This is needed for the graphing library
namespace std {
	template<> struct hash<StoryNode> {
		size_t operator()(StoryNode const& sn) const {
			return hash<int>{}(sn.getId());
		}
	};
}


#endif /* STORYNODE_STORYNODE_H_ */
