#ifndef UTILS_H
#define UTILS_H


typedef struct Position3D { 
    double x;
	double y;
	double z;
} Position3D;

typedef struct Size3D { 
    double sizeX;
	double sizeY;
	double sizeZ;
} Size3D;

typedef struct ColorRGB { 
    double R;
	double G;
	double B;
} ColorRGB;

/**
 * Initializes the Position3D
 */
void initPosition3D(Position3D* pos, double x, double y, double z);

/**
 * Initializes the initSize3D
 */
void initSize3D(Size3D* sizes, double sizeX, double sizeY, double sizeZ);

/**
 * Initializes the initColorRGB
 */
void initColorRGB(ColorRGB* color, double R, double G, double B);

#endif /* UTILS_H */
