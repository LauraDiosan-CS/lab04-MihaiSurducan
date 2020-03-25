#include "Repository.h"

Repository::Repository() { size = 0; }

/*Adaugare element*/
void Repository::addElem(Project p) {
	elem[size++] = p;
}

/*Gasire element*/
int Repository::findElem(Project p) {
	int i = 0;

	while (i < size) {
		if (elem[i] == p) return i;
		i++;
	}
	return -1;
}

/*Stergere element*/
void Repository::delElem(Project p) {
	int i = findElem(p);
	if (i != -1)
		elem[i] = elem[size - 1];
	size--;
}


/*Modificare element*/
void Repository::updateElem(Project p, const char* newGitPath, int newNoOfBranches, int newTotalNoOfCommits) {
	int i = findElem(p);
	elem[i].setGitPath(newGitPath);
	elem[i].setNoOfBranches(newNoOfBranches);
	elem[i].setTotalNoOfCommits(newTotalNoOfCommits);
}

/*Returnarea tuturor elementelor*/
Project* Repository::getAll() {
	return elem;
}

/*Returneaza cate elemente de tip Project avem*/
int Repository::dim() {
	return size;
}

/*Destructor*/
Repository::~Repository() {
}

/*Returnarea unui element de pe o anumita pozitie*/
Project Repository::getItemFromPos(int i) {
	return elem[i];
}
