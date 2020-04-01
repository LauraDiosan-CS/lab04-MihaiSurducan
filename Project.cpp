#include <string.h>
#include <ostream>
#include "Project.h"

/*Constructorul*/
Project::Project()
{
	gitPath = NULL;
	noOfBranches = 0;
	totalNoOfCommits = 0;
}

Project::Project(const char* gitPath, int noOfBranches, int totalNoOfCommits) {
	this->gitPath = new char[strlen(gitPath) + 1];
	strcpy_s(this->gitPath, strlen(gitPath) + 1, gitPath);
	this->noOfBranches = noOfBranches;
	this->totalNoOfCommits = totalNoOfCommits;
}

Project::Project(const Project& p) {
	this->gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(this->gitPath, strlen(p.gitPath) + 1, p.gitPath);
	this->totalNoOfCommits = p.totalNoOfCommits;
	this->noOfBranches = p.noOfBranches;
}

/*Returnarea valorii lui noOfBranches*/
int Project::getNoOfBranches() {
	return noOfBranches;
}

/*Schimbarea valorii lui totalNoOfCommits*/
void Project::setNoOfBranches(int newNoOfBranches) {
	noOfBranches = newNoOfBranches;
}

/*Returnarea valorii lui totalnoOfCommits*/
int Project::getTotalNoOfCommits() {
	return totalNoOfCommits;
}

/*Schimabarea valorii lui totalNoOfCommits*/
void Project::setTotalNoOfCommits(int newTotalNoOfCommits) {
	totalNoOfCommits = newTotalNoOfCommits;
}

/*Returnarea valorii lui GitPath*/
char* Project::getGitPath() {
	return gitPath;
}

/*Schimbarea valorii la GitPath*/
void Project::setGitPath(const char* n) {
	if (gitPath) delete[]gitPath;
	gitPath = new char[strlen(n) + 1];
	strcpy_s(gitPath, strlen(n) + 1, n);
}

/*Destructorul*/
Project::~Project() {
	if (gitPath) delete[]gitPath;
	gitPath = NULL;
	totalNoOfCommits = -1;
	noOfBranches = -1;
}

Project& Project::operator=(const Project& p) {
	if (this == &p) return *this; //self-assignment
	if (gitPath) delete[] gitPath;
	gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(gitPath, strlen(p.gitPath) + 1, p.gitPath);
	totalNoOfCommits = p.totalNoOfCommits;
	noOfBranches = p.noOfBranches;
	return *this;
}

bool Project::operator==(const Project& p) {
	return (strcmp(gitPath, p.gitPath) == 0) and (totalNoOfCommits == p.totalNoOfCommits) and (noOfBranches == p.noOfBranches);
}

ostream& operator<<(ostream& os, const Project& p)
{
	os << "GitPath - " << p.gitPath << ", NoOBranches - " << p.noOfBranches << ",TotalNoOfCommits - " << p.totalNoOfCommits;
	return os;
}