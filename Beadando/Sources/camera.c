#include "camera.h"

#include <stdio.h>

#include <GL/glut.h>
#include <math.h>

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

void init_camera() {
    camera.x = 0.0;
    camera.y = 0.0;
    camera.z = 0.0;
    camera.rotationX = 0.0;
    camera.rotationY = 0.0;
    camera.rotationZ = 0.0;
    camera.speedX = 0.0;
    camera.speedY = 0.0;
    camera.speedZ = 0.0;
}

void update_camera() {

    glMatrixMode(GL_MODELVIEW);

    float Y = (M_PI * camera.rotationY) / 180.0;
    float angleY = (M_PI * Y) / 180.0;

    camera.z += cos(angleY) * camera.speedZ;
    camera.x -= sin(angleY) * camera.speedZ;

    camera.x += cos(angleY) * camera.speedX;
    camera.z += sin(angleY) * camera.speedX;

    glTranslatef(camera.x, camera.y, camera.z);
}

void rotate_camera() {
    glMatrixMode(GL_MODELVIEW);

    float radY = (M_PI * camera.rotationY) / 180.0;
    float radX = (M_PI * camera.rotationX) / 180.0;

    glRotatef(radX, 1, 0, 0);
    glRotatef(radY, 0, 1, 0);

}
