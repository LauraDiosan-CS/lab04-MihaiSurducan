#pragma once
#include "Project.h"
#include "Repository.h"
#include "Service.h"

class UI {
private:
	Service s;
public:
	UI();
	void printMenu();
	void addProject(Service& s);
	void getAll(Service& s);
	void delProject(Service& s);
	void updateProject(Service& s);
	void filterProjects(Service& s);
	void delProjects(Service& s);
	~UI();
};