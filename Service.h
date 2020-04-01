#pragma once
#include "Project.h"
#include "Repository.h"

class Service {
private:
	Repository r;
public:
	Service();
	void addProject(Project& p);
	void delProject(Project p);
	void updateProject(Project& p, const char*, int, int);
	int dim();
	Project getItemFromPos(int);
	Project* getAll();
	void delProjects(Service& ser);
	void filterProjects(Service& rep, Project projectFilter[], int& m, int k, int l);
	~Service();
};