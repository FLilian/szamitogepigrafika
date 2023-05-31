#ifndef OBJECTS_H
#define OBJECTS_H

#include "model.h"
#include "texture.h"


typedef struct Skysphere { 
	Model* model;
	int textureId;
} Skysphere;

typedef struct Chair { 
	Model* model;
	int textureId;
} Chair;

typedef struct Floor { 
	Model* model;
	int textureId;
} Floor;

typedef struct Desk { 
	Model* model;
	int textureId;
} Desk;

typedef struct Tv_cupboard { 
	Model* model;
	int textureId;
} Tv_cupboard;

typedef struct Supercomputer { 
	Model* model;
	int textureId;
} Supercomputer;

typedef struct Speaker { 
	Model* model;
	int textureId;
} Speaker;

typedef struct Ceiling { 
	Model* model;
	int textureId;
} Ceiling;

typedef struct Book { 
	Model* model;
	int textureId;
} Book;

typedef struct Wall { 
	Model* model;
	int textureId;
} Wall;

typedef struct Wall2 { 
	Model* model;
	int textureId;
} Wall2;

typedef struct Wall3 { 
	Model* model;
	int textureId;
} Wall3;

typedef struct Wall4 { 
	Model* model;
	int textureId;
} Wall4;

typedef struct Fish { 
	Model* model;
	int textureId;
} Fish;

typedef struct Tv { 
	Model* model;
	int textureId;
} Tv;

typedef struct Crate { 
	Model* model;
	int textureId;
} Crate;

typedef struct Bread { 
	Model* model;
	int textureId;
} Bread;
typedef struct Notebook {
	Model* model;
	int textureId;
} Notebook;

typedef struct Clock {
	Model* model;
	int textureId;
} Clock;

void renderSkysphere(Skysphere* skysphere);
void initSkysphere(Skysphere* skysphere, Model* model, Texture texture);

void renderChair(Chair* chair);
void initChair(Chair* chair, Model* model, Texture texture);

void renderFloor(Floor* floor);
void initFloor(Floor* floor, Model* model, Texture texture);

void renderDesk(Desk* desk);
void initDesk(Desk* desk, Model* model, Texture texture);

void renderTv_cupboard(Tv_cupboard* tv_cupboard);
void initTv_cupboard(Tv_cupboard* tv_cupboard, Model* model, Texture texture);

void renderSupercomputer(Supercomputer* supercomputer);
void initSupercomputer(Supercomputer* supercomputer, Model* model, Texture texture);

void renderSpeaker(Speaker* speaker);
void initSpeaker(Speaker* speaker, Model* model, Texture texture);

void renderCeiling(Ceiling* ceiling);
void initCeiling(Ceiling* ceiling, Model* model, Texture texture);

void renderBook(Book* book);
void initBook(Book* book, Model* model, Texture texture);

void renderWall(Wall* wall);
void initWall(Wall* wall, Model* model, Texture texture);

void renderWall2(Wall2* wall2);
void initWall2(Wall2* wall2, Model* model, Texture texture);

void renderWall3(Wall3* wall3);
void initWall3(Wall3* wall3, Model* model, Texture texture);

void renderWall4(Wall4* wall4);
void initWall4(Wall4* wall4, Model* model, Texture texture);

void renderFish(Fish* fish);
void initFish(Fish* fish, Model* model, Texture texture);

void renderTv(Tv* tv);
void initTv(Tv* tv, Model* model, Texture texture);

void renderCrate(Crate* crate);
void initCrate(Crate* crate, Model* model, Texture texture);

void renderBread(Bread* bread);
void initBread(Bread* bread, Model* model, Texture texture);

void renderNotebook(Notebook* notebook);
void initNotebook(Notebook* notebook, Model* model, Texture texture);

void renderClock(Clock* clock);
void initClock(Clock* clock, Model* model, Texture texture);

#endif /* OBJECTS_H */
