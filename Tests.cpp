#include <iostream>
#include <string>
#include "assert.h"
#include "Repository.h"
#include "Project.h"
#include "Service.h"

using namespace std;

/*Teste la Project*/
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

	assert(strcmp(P1.getGitPath(), "New") == 0);
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

	Project P6(P4);
	assert(P6 == P4);

	Project p;
	assert(p.getGitPath() == NULL);
	assert(p.getNoOfBranches() == 0);
	assert(p.getTotalNoOfCommits() == 0);
}

/*Teste la Repository*/
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
	assert(strcmp(rep.getItemFromPos(1).getGitPath(), "New") == 0);
	assert(rep.getItemFromPos(1).getNoOfBranches() == 1);

	rep.delElem(P3);
	assert(rep.dim() == 3);

	assert(rep.getAll()[0] == P1);
	assert(rep.getAll()[2] == P4);
}

/*Teste la Service*/
void TestService()
{
	Project P1("New", 15, 25);
	Project P2("Old", 25, 35);
	Project P3("Medium", 14, 27);
	Project P4("High", 17, 36);
	Service ser;
	ser.addProject(P1);
	ser.addProject(P2);
	ser.addProject(P3);
	ser.addProject(P4);
	assert(ser.dim() == 4);
	ser.delProject(P2);
	assert(ser.dim() == 3);
	ser.updateProject(P1, "Outrageous", 4, 34);
	assert(ser.getItemFromPos(0).getNoOfBranches() == 4);
	assert(ser.getItemFromPos(0).getTotalNoOfCommits() == 34);
	assert(ser.getAll()[1] == P4);
}

/*Teste la cerinta 1.*/
void TestFilterProject()
{
	Project P1("New", 15, 25);
	Project P2("Old", 25, 35);
	Project P3("Medium", 14, 27);
	Project P4("High", 17, 36);
	Service ser;
	ser.addProject(P1);
	ser.addProject(P2);
	ser.addProject(P3);
	ser.addProject(P4);
	assert(ser.dim() == 4);
	Project results[10];
	int m = 0;
	ser.filterProject(ser, results, m, 15, 25);
	assert((m == 3) && (results[0] == P1) && (results[1] == P2) && (results[2] == P4));
}

/*Teste la cerinta 2.*/
void TestDeleteProjects()
{
	Service s;
	Project P1("New", 1, 25);
	Project P2("Old", 0, 1);
	Project P3("Medium", 0, 0);
	Project P4("High", 14, 1);
	s.addProject(P1);
	s.addProject(P2);
	s.addProject(P3);
	s.addProject(P4);
	assert(s.dim() == 4);
	s.delProjects(s);
	assert(s.dim() == 2);
}

/*Aici apelez toate testele de mai sus*/
void MainTests()
{
	cout << "First Tests" << endl;
	TestProject();
	TestRepository();
	TestService();
	TestDeleteProjects();
	TestFilterProject();
	cout << "Succesful";
}