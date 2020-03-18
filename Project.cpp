#include <string.h>
#include "Project.h"

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

int Project::getNoOfBranches() {
	return noOfBranches;
}

void Project::setNoOfBranches(int newNoOfBranches) {
	noOfBranches = newNoOfBranches;
}

int Project::getTotalNoOfCommits() {
	return totalNoOfCommits;
}

void Project::setTotalNoOfCommits(int newTotalNoOfCommits) {
	totalNoOfCommits = newTotalNoOfCommits;
}


char* Project::getGitPath() {
	return gitPath;
}


void Project::setGitPath(const char* n) {
	if (gitPath) delete[]gitPath;
	gitPath = new char[strlen(n) + 1];
	strcpy_s(gitPath, strlen(n) + 1, n);
}

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