#ifndef INIT_H
#define INIT_H

#include "room.h"

typedef struct Config {
	double lightPosX;
	double lightPosY;
	double lightPosZ;
	double lightColorRed;
	double lightColorGreen;
	double lightColorBlue;
	double viewportRatioW;
	double viewportRatioH;
	double viewportAspect;
} Config;

/**
 * Initializes the configuration with the default values.
 */
void loadDefaultConfig(Config* config);

void initialize(Room* room, Config config);

/**
 * Initializes the room object with default values.
 */
void initRoom(Room* room, Config config);

/**
 * Loads the models into memory and scales them to the proper sizes.
 */
void initModels(Room* room);

/**
 * Loads and initializes the textures for use.
 */
void initTextures(Room* room);

#endif /* INIT_H */