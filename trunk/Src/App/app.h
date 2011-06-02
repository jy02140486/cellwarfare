#ifndef APP_H
#define APP_H 

#include "precomp.h"
#include "event.h"
#include "../Entities/cells.h"
#include "../Entities/levels.h"
#include "../Libs/timer.h"
#include "EM.h"
#include "globals.h"

#include <list>
#include<stdio.h>


class T_App : public T_Event	
{


public:
	T_App ();
	int  start();
	bool running;

	EM *entites;
	
	
	CL_Font *words;
	CL_Point offset;
	
	CL_Image* body;

	CL_LineEdit* mx,*my;
	CL_PushButton* cirfirm;
	CL_PushButton* SendingCirfirm;
	CL_PushButton* PainKiller;


	CL_Label* infoBF;
	CL_Spin* cellsdeployed;
	CL_Spin* intruders;

	CL_Label*TaticalBoard;
	CL_Label*lbTintruders,*lbTcellsdeployed;
	CL_Label*Tintruders,*Tcellsdeployed;

	CL_ProgressBar* timeleft;
	CL_Label* lbcellsdeployed,*lbintruders,*lbtimeleft;

	time_t Atime;
	DWORD mrk;

	//initial game enviroment
	bool init();

	//processing game logics
	void loop();

	//render the game
	void render();
	inline void renderdes();
	
	inline	void renderScrObj();

	//initial all
	int eventInit(void);

	void onMouseMove(const CL_InputEvent &, const CL_InputState &);
	void onMouseDown(const CL_InputEvent &, const CL_InputState &);
	void onMouseUp(const CL_InputEvent &, const CL_InputState &);
	void onKeyboardUp(const CL_InputEvent &key,
		const CL_InputState &state);

	//temp funcs
	void LibDebugOnConsole();
	void StateSwitching(GLOBAL_STATE newstate);
	void ButtonClick();

	void ScrObjSelect();
	void invading_LogicLayer_Failure();
	void updateBoard();
	void OnSendingCirfirmClick();
	void Ttimesup();
	void takePill();
};

#endif
