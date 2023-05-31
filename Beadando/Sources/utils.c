#include "utils.h"


void initPosition3D(Position3D* pos, double x, double y, double z) {
	pos->x = x;
	pos->y = y;
	pos->z = z;
}

void initSize3D(Size3D* sizes, double sizeX, double sizeY, double sizeZ) {
	sizes->sizeX = sizeX;
	sizes->sizeY = sizeY;
	sizes->sizeZ = sizeZ;
}

void initColorRGB(ColorRGB* color, double R, double G, double B) {
	color->R = R;
	color->G = G;
	color->B = B;
}
