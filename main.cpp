#include <unistd.h>
#include <string>

#include "version.h"

#include "cRender.h"
#include "cObject.h"
#include "cObjectHandler.h"
#include "cInput.h"
#include "cWiremesh.h"

//#include "testobject.h"

int main()
{
	cRender render(' ', _COL_DEFAULT, 30,30);
	cObjectHandler handler(&render);
	cObject ver(45,1);
	cWiremesh obj;

	cInput input;

	render.render();

	/*int iobj = handler.createObject((cObject*)&obj);
	handler.moveObject(iobj, {40,10}, _MOVE_ABSOLUTE);*/

	ver.drawPoint('v', {0,0}, true, _COL_WHITE);
	ver.drawPoint(VERSION + 48, {1,0}, true, _COL_WHITE);
	ver.drawPoint('.', {2,0}, true, _COL_WHITE);
	ver.drawPoint(PATCHLEVEL + 48, {3,0}, true, _COL_WHITE);
	ver.drawText(DATE, {32,0}, _COL_WHITE);
	ver.drawText(BRANCH, {5,0}, _COL_WHITE);
	int iver = handler.createObject(&ver);
	handler.moveObject(iver, {0,0}, _MOVE_ABSOLUTE);

	int x = 30;
	int y = 30;
	int z = 30;

	obj.addVector({0,0,z}, {x,0,0}, '+', _COL_RED);
	obj.addVector({0,0,z}, {0,y,0}, '+', _COL_RED);
	obj.addVector({0,y,z}, {x,0,0}, '+', _COL_RED);
	obj.addVector({x,0,z}, {0,y,0}, '+', _COL_RED);

	obj.addVector({0,0,0}, {0,0,z}, ':', _COL_RED);
	obj.addVector({x,0,0}, {0,0,z}, ':', _COL_RED);
	obj.addVector({0,y,0}, {0,0,z}, ':', _COL_RED);
	obj.addVector({x,y,0}, {0,0,z}, ':', _COL_RED);

	obj.addVector({0,0,0}, {x,0,0}, ',', _COL_RED);
	obj.addVector({0,0,0}, {0,y,0}, ',', _COL_RED);
	obj.addVector({0,y,0}, {x,0,0}, ',', _COL_RED);
	obj.addVector({x,0,0}, {0,y,0}, ',', _COL_RED);
	int imesh = handler.createWiremesh(&obj);

	while(1)
	{
		sInputEvent ie = input.poll();

		if(ie.type != _EVENT_NULL)
		{
			if(ie.type == _EVENT_KEY)
			{
				switch (ie.c)
				{
					case 'A'://up
						handler.moveWiremesh(imesh,{0,-1,0}, _MOVE_RELATIVE);
						break;
					case 'B'://down
						handler.moveWiremesh(imesh,{0,1,0}, _MOVE_RELATIVE);
						break;
					case 'C'://right
						handler.moveWiremesh(imesh,{1,0,0}, _MOVE_RELATIVE);
						break;
					case 'D'://left
						handler.moveWiremesh(imesh,{-1,0,0}, _MOVE_RELATIVE);
						break;
				};
			}
			else if (ie.type == _EVENT_MOUSE)
			{
				if(ie.b == 0)
					handler.clickEvent({ie.x, ie.y}, 0);
			}
			else if (ie.type == _EVENT_CHAR)
			{
				//handler.charEvent(ie.c);
				switch(ie.c)
				{
					case 'w':
						handler.rotateWiremesh(imesh,{-10,0,0});
						break;
					case 's':
						handler.rotateWiremesh(imesh,{10,0,0});
						break;
					case 'a':
						handler.rotateWiremesh(imesh,{0,-10,0});
						break;
					case 'd':
						handler.rotateWiremesh(imesh,{0,10,0});
						break;
					case 'q':
						handler.rotateWiremesh(imesh,{0,0,-10});
						break;
					case 'e':
						handler.rotateWiremesh(imesh,{0,0,10});
						break;
				};
			}
			else if (ie.type == _EVENT_TERM)
			{
				return 0;
			}

		}
		handler.write();
		render.render();

		usleep(10*1000);
	}


	/*cRender a(' ', _COL_DEFAULT, 20,20);
	cInput in;
	a.render();

	sPos size = a.getSize();
	sPos pos = {size.x / 2, size.y / 2};

	while(1)
	{
		sInputEvent ie = in.poll();
		if(ie.type != _EVENT_NULL)
		{
			if(ie.type == _EVENT_KEY)
			{
				switch (ie.c)
				{
					case 'A':
						pos.y--;
						break;
					case 'B':
						pos.y++;
						break;
					case 'C':
						pos.x++;
						break;
					case 'D':
						pos.x--;
						break;
				};
			}
			else if (ie.type == _EVENT_MOUSE)
			{
				pos.x = ie.x;
				pos.y = ie.y;
			}
			else if (ie.type == _EVENT_TERM)
			{
				return 0;
			}

			a.clear();
			a.drawPoint('X', pos, true, _COL_GREEN);
			a.render();

			usleep(10*1000);
		}
	}*/

	/*unsigned long int framecounter = 0;
	cRender a(' ', _COL_DEFAULT, 10,10);
	a.render();

	sPos pos = {0,10};
	int dirX = 1;
	int dirY = -1;

	while(1)
	{
		pos.x += 2 * dirX;
		pos.y += 1 * dirY;

		if(pos.x >= a.getSize().x) {
			pos.x = a.getSize().x;
			dirX *= -1;
		}
		if(pos.x <= 0) {
			pos.x = 0;
			dirX *= -1;
		}

		if(pos.y >= a.getSize().y) {
			pos.y = a.getSize().y;
			dirY *= -1;
		}
		if(pos.y <= 0) {
			pos.y = 0;
			dirY *= -1;
		}

		a.clear();
		a.drawPoint('X', pos, true, _COL_GREEN);
		a.drawText(to_string(framecounter), {0,0}, _COL_RED);
		a.render();

		framecounter++;
		//cin.get();
		//usleep(100*1000);
		if(framecounter >= 1000)
			break;
	}*/

	/*cObjectHandler b(&a);
	cObject x(1,1);

	int i = b.createObject(&x);
	int dir1 = 1;
	int dir2 = -1;
	int cntr = 0;

	a.clear(true);
	b.moveObject(i, {0,30}, _MOVE_ABSOULUTE);
	x.drawPoint('X', {0,0}, true,_COL_GREEN);

	while(1)
	{
		b.moveObject(i, {2 * dir1, 1 * dir2}, _MOVE_RELATIVE);

		b.write();
		a.drawText(to_string(framecounter), {0,0}, _COL_RED);
		a.render();

		if(x.getPosition().x <= 0)
			dir1 *= -1;
		else if(x.getPosition().x >= a.getSize().x)
		{
			dir1 *= -1;
			x.setPosition({a.getSize().x, x.getPosition().y});
		}

		if(x.getPosition().y <= 0)
			dir2 *= -1;
		else if(x.getPosition().y >= a.getSize().y)
		{
			dir2 *= -1;
			x.setPosition({x.getPosition().x, a.getSize().y});
		}

		framecounter++;
		//cin.get();
		usleep(100*1000);
	}*/
	return 0;
}
