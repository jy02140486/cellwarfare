#include "app.h"

void T_App::initScrObjs()
{
	head=new ScrObj();
	itr=head;
	itr->pos=new CL_Point(423,229);
	
	head->next=new ScrObj();
	itr=itr->next;
	itr->pos=new CL_Point(564,174);
}