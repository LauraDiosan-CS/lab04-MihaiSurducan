#include "UI.h"

#include <iostream>
using namespace std;

//constructor
UI::UI()
{
	this->s; 
}

//afisare meniu 
void UI::printMenu()
{
	cout << "1. Adaugare " << endl;
	cout << "2. Afisare " << endl;
	cout << "3. Update " << endl;
	cout << "4. Stergere " << endl;
	cout << "5. Afisarea proiectelor care cel putin k branch-uri si l commit-uri " << endl;
	cout << "6. Eliminare proiectelor care numarul branch-urilor * numarul de total de commit-uri egal cu 0 " << endl;
	cout << "7. Exit " << endl;
}

//adaugare element
void UI::addProject(Service& s)
{
	char gitPath[100];
	int noOfBranches, totalNoOfCommits; 
	cout << "Git Path: ";
	cin >> gitPath;
	cout << "Number of Branches: ";
	cin >> noOfBranches;
	cout << "Total number of commits: ";
	cin >> totalNoOfCommits;
	Project p(gitPath, noOfBranches, totalNoOfCommits);
	s.addProject(p);
	cout << endl;
}

//afisare tututror elementelor
void UI::getAll(Service& s)
{
	for (int i = 0; i < s.dim(); i++) 
	{
		cout << s.getAll()[i] << " ";
		cout << endl;
	}

	cout << endl;
}

//stergere element
void UI::delProject(Service& s)
{
	int i;
	cout << "Care Poriect doriti sa il stergeti: ";
	cin >> i; 
	int n = s.dim();
	s.delProject(s.getItemFromPos(i - 1));
}

//modificare element
void UI::updateProject(Service& s)
{
	int i;
	cout << "Care proiect doriti sa il modificati: ";
	cin >> i;
	Project p = s.getItemFromPos(i - 1);
	char  newGitPath[10];
	int newNoOfBranches, newTotalNoOfCommits;
	cout << "New GitPath: ";  
	cin >> newGitPath;
	cout << "New NoOfBranches: ";   
	cin >> newNoOfBranches;
	cout << "New TotalNoOfCommits: ";  
	cin >> newTotalNoOfCommits;
	s.updateProject(p, newGitPath, newNoOfBranches, newTotalNoOfCommits);
}

//afisare elemente dupa filtrare(cerinta 1)
void UI::filterProjects(Service& s)
{
	int k, l, m = 0; 
	Project results[10];
	cout << "Dati numarul de branch-rui: ";
	cin >> k;
	cout << endl << "Dati numarul de commit-uri: ";
	cin >> l ;
	cout << endl;
	int n = s.dim();
	s.filterProjects(s, results, m, k, l);
	cout << endl << "Proiectele sunt: " << endl;
	for (int i = 0; i < m; i++) 
	{
		cout << results[i] << " ";
		cout << endl;
	}
	cout << endl;
}

//stergere elemente dupa cerinta 1
void UI::delProjects(Service& s)
{
	int n = s.dim();
	s.delProjects(s);
}

//destructor
UI::~UI()
{

}