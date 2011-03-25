#ifndef APP_H
#define APP_H 

#include "precomp.h"
#include "event.h"
#include "../Entities/cells.h"
#include "../Entities/levels.h"
#include "../Libs/timer.h"
#include "EM.h"
#include <list>
#include<stdio.h>

//Sub Wnds
class T_App : public T_Event	
{
public:
	T_App ();
	int  start();

	//PhyObj Manager
	bool running;

	CL_Signal_v2<int, int> signal;


	EM *entites;
	CL_Font *infos;

	time_t Atime;
	DWORD mrk;

	//initial game enviroment
	bool init();

	//processing game logics
	void loop();

	//render the game
	void render();

	//initial all
	int eventInit(void);

	void onMouseMove(const CL_InputEvent &, const CL_InputState &);
	void onMouseDown(const CL_InputEvent &, const CL_InputState &);
	void onMouseUp(const CL_InputEvent &, const CL_InputState &);
	void onKeyboardUp(const CL_InputEvent &key,
		const CL_InputState &state);


};

#endif
