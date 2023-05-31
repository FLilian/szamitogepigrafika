#include <GL/glut.h>
#include <math.h>

#include "init.h"
#include "callbacks.h"
#include "room.h"
#include "utils.h"
#include "texture.h"

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

void loadDefaultConfig(Config* config) {
	config->lightPosX = 100.0;
	config->lightPosY = 100.0;
	config->lightPosZ = 100.0;
	config->lightColorRed = 1.0;
	config->lightColorGreen = 1.0;
	config->lightColorBlue = 1.0;
	config->viewportRatioW = 4.0;
	config->viewportRatioH = 3.0;
	config->viewportAspect = 50.0;
}

void initialize(Room* room, Config config) {
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);
    glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
	
	initRoom(room, config);
	
	display();
}

void initRoom(Room* room, Config config) {
	room->shownMessage = NONE;
	room->viewportRatioW = config.viewportRatioW;
	room->viewportRatioH = config.viewportRatioH;
	room->viewportAspect = config.viewportAspect;
	
	initTextures(room);
	initModels(room);
	
	initSkysphere(&room->skysphere, &room->models[0], room->textures[0]);
	initChair(&room->chair, &room->models[1], room->textures[1]);
	initFloor(&room->floor, &room->models[2], room->textures[2]);
	initDesk(&room->desk, &room->models[3], room->textures[3]);
	initTv_cupboard(&room->tv_cupboard, &room->models[4], room->textures[4]);
	initSupercomputer(&room->supercomputer, &room->models[5], room->textures[9]);
	initSpeaker(&room->speaker, &room->models[6], room->textures[5]);
	initCeiling(&room->ceiling, &room->models[2], room->textures[14]);
	initBook(&room->book, &room->models[7], room->textures[6]);
	initWall(&room->wall, &room->models[8], room->textures[7]);
	initWall2(&room->wall2, &room->models[8], room->textures[18]);
	initWall3(&room->wall3, &room->models[8], room->textures[15]);
	initWall4(&room->wall4, &room->models[8], room->textures[19]);
	initFish(&room->fish, &room->models[9], room->textures[8]);
	initTv(&room->tv, &room->models[10], room->textures[11]);
	initCrate(&room->crate, &room->models[11], room->textures[12]);
	initBread(&room->bread, &room->models[12], room->textures[13]);
	initNotebook(&room->notebook, &room->models[13], room->textures[16]);
	initClock(&room->clock, &room->models[14], room->textures[17]);
	
	
	ColorRGB lightColor;
	initColorRGB(&lightColor, config.lightColorRed, config.lightColorGreen, config.lightColorBlue);
	Position3D lightPosition;
	initPosition3D(&lightPosition, config.lightPosX, config.lightPosY, config.lightPosZ);
	
}


void initModels(Room* room) {
	load_model("Models/Skysphere/Skysphere.obj", &room->models[0]);
	scale_model(&room->models[0], 140, 140, 140);
	
	load_model("Models/Chair/Chair.obj", &room->models[1]);
	scale_model(&room->models[1], 1, 1, 1);
	
	load_model("Models/Floor/Floor.obj", &room->models[2]);
	scale_model(&room->models[2], 3, 3, 3);
	
	load_model("Models/Desk/Desk.obj", &room->models[3]);
	scale_model(&room->models[3], 4, 4, 4);
	
	load_model("Models/Tv_cupboard/tv_cupboard.obj", &room->models[4]);
	scale_model(&room->models[4], 4, 4, 4);
	
	load_model("Models/Supercomputer/Supercomputer.obj", &room->models[5]);
	scale_model(&room->models[5], 0.04, 0.04, 0.04);
	
	load_model("Models/Speaker/Speaker.obj", &room->models[6]); 
	scale_model(&room->models[6], 0.5, 0.5, 0.5);
	
	load_model("Models/Book/Book.obj", &room->models[7]);
	scale_model(&room->models[7], 0.3, 0.3, 0.3);
	
	load_model("Models/Wall/Wall.obj", &room->models[8]);
	scale_model(&room->models[8], 1.45, 5.25, 4);
	
	load_model("Models/Fish/fish.obj", &room->models[9]);
	scale_model(&room->models[9], 0.5, 0.5, 0.5);
	
	load_model("Models/Tv/tv.obj", &room->models[10]);
	scale_model(&room->models[10], 1.8, 1.8, 1.8);
	
	load_model("Models/Crate/crate.obj", &room->models[11]);
	scale_model(&room->models[11], 1, 1, 1);
	
	load_model("Models/Bread/bread.obj", &room->models[12]);
	scale_model(&room->models[12], 0.1, 0.1, 0.1);
	
	load_model("Models/Notebook/notebook.obj", &room->models[13]);
	scale_model(&room->models[13], 0.5, 0.5, 0.5);
	
	load_model("Models/Clock/Clock.obj", &room->models[14]);
	scale_model(&room->models[14], 3, 3, 3);

}

void initTextures(Room* room) {
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	loadTexture(&room->textures[0], "Textures/Skysphere/skysphere.jpg");
	loadTexture(&room->textures[1], "Textures/Chair/chair.jpg");
	loadTexture(&room->textures[2], "Textures/Floor/floor.png");
	loadTexture(&room->textures[3], "Textures/Desk/desk.png");
	loadTexture(&room->textures[4], "Textures/Tv_cupboard/tv_cupboard.png");
	loadTexture(&room->textures[5], "Textures/Speaker/speaker.jpg");
	loadTexture(&room->textures[6], "Textures/Book/book.png");
	loadTexture(&room->textures[7], "Textures/Wall/wall3.jpg");
	loadTexture(&room->textures[8], "Textures/Fish/fish.png");
	loadTexture(&room->textures[9], "Textures/Supercomputer/Supercomputer.png");
	loadTexture(&room->textures[10], "Textures/Help/help.png");
	loadTexture(&room->textures[11], "Textures/Tv/tv.jpg");
	loadTexture(&room->textures[12], "Textures/Crate/crate.jpg");
	loadTexture(&room->textures[13], "Textures/Bread/bread.jpg");
	loadTexture(&room->textures[14], "Textures/Ceiling/ceiling.jpg");
	loadTexture(&room->textures[15], "Textures/Wall/wall.jpg");
	loadTexture(&room->textures[16], "Textures/Notebook/notebook.jpg");
	loadTexture(&room->textures[17], "Textures/Clock/Clock.jpg");
	loadTexture(&room->textures[18], "Textures/Wall/wall2.jpg");
	loadTexture(&room->textures[19], "Textures/Wall/wall4.jpg");
	
	
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}