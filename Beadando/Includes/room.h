#ifndef ROOM_H
#define ROOM_H

#include "texture.h"
#include "model.h"
#include "objects.h"
#include "utils.h"
#include "screen_message.h"

typedef struct Room
{
	double viewportRatioW;
	double viewportRatioH;
	double viewportAspect;
	Texture textures[20];
	Model models[20];
	Skysphere skysphere;
	Chair chair;
	Floor floor;
	Desk desk;
	Tv_cupboard tv_cupboard;
	Supercomputer supercomputer;
	Speaker speaker;
	Ceiling ceiling;
	Book book;
	Wall wall;
	Wall2 wall2;
	Wall3 wall3;
	Wall4 wall4;
	Fish fish;
	Tv tv;
	Crate crate;
	Bread bread;
	ShownScreenMessage shownMessage;
	Notebook notebook;
	Clock clock;
} Room;

#endif /* ROOM_H */
