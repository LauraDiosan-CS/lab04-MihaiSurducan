#include "assert.h"
#include "Operations.h"
#include "Repository.h"
#include "Project.h"
#include <iostream>
#include <string>

using namespace std;

void TestProject()
{
	Project P1("New", 1, 25);
	Project P2("Old", 25, 3);
	Project P3("Medium", 0, 0);
	Project P4("High", 14, 1);
	Repository rep;
	rep.addElem(P1);
	rep.addElem(P2);
	rep.addElem(P3);
	rep.addElem(P4);
	assert(rep.dim() == 4);
	
	assert(strcmp(P1.getGitPath(),"New") == 0);
	P1.setGitPath("Beautiful");
	assert(strcmp(P1.getGitPath(), "Beautiful") == 0);
	
	assert(P2.getNoOfBranches() == 25);
	P2.setNoOfBranches(10);
	assert(P2.getNoOfBranches() == 10);

	assert(P3.getTotalNoOfCommits() == 0);
	P3.setTotalNoOfCommits(97);
	assert(P3.getTotalNoOfCommits() == 97);

	Project P5("High", 14, 1);
	assert(P5 == P4);

	Project p;
	assert(p.getGitPath() == NULL);
	assert(p.getNoOfBranches() == 0);
	assert(p.getTotalNoOfCommits() == 0);
}

void TestRepository() 
{
	Project P1("Fancy", 43, 15);
	Project P2("Glorious", 53, 0);
	Project P3("Few", 2, 29);
	Project P4("Business", 52, 97);

	Repository rep;
	rep.addElem(P1);
	rep.addElem(P2);
	rep.addElem(P3);
	rep.addElem(P4);
	 
	assert(rep.dim() == 4);
	rep.updateElem(P2, "New", 1, 97);
	assert(strcmp(rep.getItemFromPos(1).getGitPath(),"New") == 0);
	assert(rep.getItemFromPos(1).getNoOfBranches() == 1);

	rep.delElem(P3);
	assert(rep.dim() == 3);

	assert(rep.getAll()[0] == P1);
	assert(rep.getAll()[2] == P4);
}

void TestFilterProjectWithRepo()
{
	Project P1("New", 15, 25);
	Project P2("Old", 25, 35);
	Project P3("Medium", 14, 27);
	Project P4("High", 17, 36);
	Repository rep;
	rep.addElem(P1);
	rep.addElem(P2);
	rep.addElem(P3);
	rep.addElem(P4);
	assert(rep.dim() == 4);
	Project results[10];
	int m = 0;
	filterProject(rep, results, m, 15, 25);
	assert((m == 3) && (results[0] == P1) && (results[1] == P2) && (results[2] == P4));
}

void TestDeleteProjectWithRepo()
{
	Project P1("New", 1, 25);
	Project P2("Old", 0, 1);
	Project P3("Medium", 0, 0);
	Project P4("High", 14, 1);
	Repository rep;
	rep.addElem(P1);
	rep.addElem(P2);
	rep.addElem(P3);
	rep.addElem(P4);
	assert(rep.dim() == 4);
	delProject(rep);
	assert(rep.dim() == 2);
}

void MainTests()
{
	cout << "First Tests" << endl;
	TestFilterProjectWithRepo();
	TestDeleteProjectWithRepo();
	TestProject();
	TestRepository();
	cout << "Succesful";
}
