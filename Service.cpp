#include "Service.h"
#include <iostream>
using namespace std;

/*constructor fara param*/
Service::Service() {
	this->r;
}



/*adauga un element de tip Project*/
void Service::addProject(Project& p) {
	r.addElem(p);
}

/*returneaza toate elementele de tip Project*/
Project* Service::getAll() {
	return r.getAll();
}

/*sterge un element*/
void Service::delProject(Project p) {
	r.delElem(p);
}

/*modifica un element de tip Project*/
void Service::updateProject(Project& p,const char* newGitPath, int newNoOfBranches, int newTotalNoOfCommits) {
	r.updateElem(p, newGitPath, newNoOfBranches, newTotalNoOfCommits);
}

/*returneaza elementul de tip Project de pe o anumita pozitie*/
Project Service::getItemFromPos(int i) {
	return r.getItemFromPos(i);
}

/*returneaza dimensiunea*/
int Service::dim() {
	return r.dim();
}

/*destructor*/
Service::~Service() {
}

/*Cerinta 1.*/
void Service::filterProjects(Service& ser, Project projectFilter[], int& m, int k, int l)
{
	Project* projects = ser.getAll();
	for (int i = 0; i < ser.dim(); i++)
	{

		if ((projects[i].getNoOfBranches() >= k) && (projects[i].getTotalNoOfCommits() >= l))
			projectFilter[m++] = projects[i];
	}
}
/*Cerinta 2.*/
void Service::delProjects(Service& ser)
{
	Project* projects = ser.getAll();
	for (int i = 0; i < ser.dim(); i++)
	{
		if ((projects[i].getNoOfBranches() * projects[i].getTotalNoOfCommits()) == 0)
		{
			ser.delProject(projects[i]);
			i--;
		}
	}
}
