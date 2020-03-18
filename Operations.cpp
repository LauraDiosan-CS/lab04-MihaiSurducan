#include "Repository.h"
#include <string.h>

void filterProject(Repository& rep, Project projectFilter[], int& m, int k, int l) {
	for (int i = 0; i < rep.dim(); i++) 
	{
		Project crtProject = rep.getItemFromPos(i);

		if((crtProject.getNoOfBranches() >= k) && (crtProject.getTotalNoOfCommits() >= l))
			projectFilter[m++] = crtProject;
	}
}

void delProject(Repository& rep) {
	for (int i = 0; i < rep.dim(); i++)
	{
		if ((rep.getItemFromPos(i).getNoOfBranches() * rep.getItemFromPos(i).getTotalNoOfCommits()) == 0)
		{
			rep.delElem(rep.getItemFromPos(i));
			i--;
		}
	}
}