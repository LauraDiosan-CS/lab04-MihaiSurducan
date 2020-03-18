#include "Repository.h"

Repository::Repository() { size = 0; }

void Repository::addElem(Project p) {
	elem[size++] = p;
}

int Repository::findElem(Project p) {
	int i = 0;

	while (i < size) {
		if (elem[i] == p) return i;
		i++;
	}
	return -1;
}

void Repository::delElem(Project p) {
	int i = findElem(p);
	if (i != -1)
		elem[i] = elem[size - 1];
	size--;
}

void Repository::updateElem(Project p,const char* newGitPath, int newNoOfBranches, int newTotalNoOfCommits) {
	int i = findElem(p);
	elem[i].setGitPath(newGitPath);
	elem[i].setNoOfBranches(newNoOfBranches);
	elem[i].setTotalNoOfCommits(newTotalNoOfCommits);
}

Project* Repository::getAll() {
	return elem;
}
int Repository::dim() {
	return size;
}
Repository::~Repository() {
}

Project Repository::getItemFromPos(int i) {
	return elem[i];
}
