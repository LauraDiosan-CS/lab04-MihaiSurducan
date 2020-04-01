#include <iostream>
#include "Tests.h"
#include "UI.h"
#include "Service.h"
using namespace std;

int main()
{
	int ok = 0;
	MainTests();
	Service s; 
	UI ui;
	while (!ok)
	{
		ui.printMenu();
		int option = 0;
		cout << "Optiunea: ";
		cin >> option;
		if (option == 1)
			ui.addProject(s);
		if (option == 2)
			ui.getAll(s);
		if (option == 3)
		{
			ui.updateProject(s);
			ui.getAll(s);
		}
		if (option == 4)
		{
			ui.delProject(s);
			ui.getAll(s);
		}
		if (option == 5)
			ui.filterProjects(s);
		if (option == 6)
		{
			ui.delProjects(s);
			ui.getAll(s);
		}
		if (option == 7)
			ok = 1;
	}
	return 0;
}