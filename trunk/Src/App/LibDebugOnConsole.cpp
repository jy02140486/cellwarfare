#include "app.h"
#include "../Libs/NatrualNum.h"
#include "../Libs/RandomVal.h"

void T_App::LibDebugOnConsole()
{
// 	NatrualNum tn1(20,50);
// 	CL_Console::write_line("NatrualNum curVal %1,maxVal %2",tn1.val,tn1.maximun);
// 	tn1-10;
// 	CL_Console::write_line("tn1-10=%1",tn1.val);
// 	CL_Console::write_line("NatrualNum curVal %1,maxVal %2",tn1.val,tn1.maximun);
// 	tn1-30;
// 	CL_Console::write_line("tn1-30=%1",tn1.val);
// 	CL_Console::write_line("NatrualNum curVal %1,maxVal %2",tn1.val,tn1.maximun);
// 	tn1+40;
// 	CL_Console::write_line("tn1+40=%1",tn1.val);
// 
// 	NatrualNum tn2(40);
// 	CL_Console::write_line("NatrualNum curVal %1,maxVal %2",tn2.val,tn2.maximun);
// 
// 	int temp;
// 	
// 	CL_Console::write_line("");
// 	CL_Console::write_line("output 10 ints from 20 to 35for testing");
// 	for (int i=0;i<10;i++)
// 	{
// 		temp=RandomVal::int_from_to(20,35);
// 		CL_Console::write_line("the first %1 is %2",i,temp);
// 	}
// 
// 	CL_Point temP;
// 	CL_Console::write_line("");
// 	CL_Console::write_line("output 10 points from (0,0) to (800,600) for testing");
// 	for (int i=0;i<10;i++)
// 	{
// 		temP=*RandomVal::randomPointi(0,0,800,600);
// 		CL_Console::write_line("the first point %1,(%2,%3)",i,temP.x,temP.y);
// 	}

// 	ScrObj*temp=entites->SOselected;
// 
// 	CL_Console::write_line("%1",temp->datas->celldeployed)
// 	;

// 	for (b2Body* bbbb=entites->curBF->world->GetBodyList();bbbb!=NULL;bbbb=bbbb->GetNext())
// 	{
// 			CL_Console::write_line("%1",bbbb->GetPosition().x);
// 	}
// 
// 	if (entites->curBF->world->GetBodyList()==NULL)
// 	{
// 		CL_Console::write_line("crap");
// 	}

	CL_Console::write_line("%1",entites->curBF->world->GetBodyCount());
	for(b2Body*tb=entites->curBF->world->GetBodyList();tb!=NULL;tb=tb->GetNext())
	{
		CL_Console::write_line("dir x= %1 y= %2",tb->GetPosition().x,tb->GetPosition().y);
	}
}