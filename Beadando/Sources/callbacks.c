#include <GL/glut.h>
#include <stdbool.h>
#include <math.h>

#include "callbacks.h"
#include "camera.h"
#include "objects.h"
#include "screen_message.h"
#include "model.h"
#include "texture.h"
#include "draw.h"
#include "room.h"

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

extern Room room;

float lightIntensity = 0.5f;

void setCallbacks() {
	glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutKeyboardUpFunc(keyRelease);
	glutSpecialFunc(keyboardSpecialButtonHandler);
    glutPassiveMotionFunc(mouse);
    glutIdleFunc(idle);
}

void display() {
	glClearStencil(0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    const GLfloat light_position[] = { 100, 100, 100, 0 };

    float R = 1.0f;
    float G = 1.0f;
    float B = 1.0f;

    float intensity = 0.1f;

    GLfloat color[] =
	{
		R * lightIntensity,
		G * lightIntensity,
		B * lightIntensity,
		1.0
	};

    glLightfv(GL_LIGHT0, GL_AMBIENT,  color);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  color);
    glLightfv(GL_LIGHT0, GL_SPECULAR, color);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glScalef(10, 10, 10);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	rotate_camera();
    update_camera();
	
	glPushMatrix();
	renderSkysphere(&room.skysphere);
	renderChair(&room.chair);
	renderFloor(&room.floor);
	renderDesk(&room.desk);
	renderTv_cupboard(&room.tv_cupboard);
	renderSupercomputer(&room.supercomputer);
	renderSpeaker(&room.speaker);
	renderCeiling(&room.ceiling);
	renderBook(&room.book);
	renderWall(&room.wall);
	renderWall2(&room.wall2);
	renderWall3(&room.wall3);
	renderWall4(&room.wall4);
	renderFish(&room.fish);
	renderTv(&room.tv);
	renderCrate(&room.crate);
	renderBread(&room.bread);
	renderNotebook(&room.notebook);
	renderClock(&room.clock);
	
	
	if(room.shownMessage != NONE) {
		renderScreenMessage(room.textures[room.shownMessage]);
	}
	
	glPopMatrix();
	
	glutSwapBuffers();
}


void reshape(GLsizei width, GLsizei height) {
	int x, y, w, h;
    double ratio = (double)width / height;
	double viewportRatio =  room.viewportRatioW /  room.viewportRatioH;
	
    if (ratio > viewportRatio) {
        w = (int)((double)height * viewportRatio);
        h = height;
        x = (width - w) / 2;
        y = 0;
    }
    else {
        w = width;
        h = (int)((double)width / viewportRatio);
        x = 0;
        y = (height - h) / 2;
    }

    glViewport(x, y, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(room.viewportAspect, viewportRatio, 0.01, 10000.0);
}


void keyboardSpecialButtonHandler (int key, int x, int y) {
	HelpMenu(key, &room.shownMessage);
	
	glutPostRedisplay();
}

void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case 'w':
            camera.speedZ = 0.07;
            break;
        case 's':
            camera.speedZ = -0.07;
            break;
        case 'd':
            camera.speedX = -0.07;
            break;
        case 'a':
            camera.speedX = 0.07;
            break;
		case '+':
            if(lightIntensity < 1.5f) {
                lightIntensity += .05;
            }
            break;
        case '-':
            if(lightIntensity > 0.0f) {
                lightIntensity -= .05;
            }
            break;
	}

    glutPostRedisplay();
}

void keyRelease(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'w':
        case 's':
            camera.speedZ = 0;
            break;
        case 'd':
        case 'a':
            camera.speedX = 0;
            break;
    }

    glutPostRedisplay();
}

void mouse(int x, int y) {
    float centerX = glutGet(GLUT_WINDOW_WIDTH) / 2;
    float centerY = glutGet(GLUT_WINDOW_HEIGHT) / 2;

    float ratio = 90.0 / (glutGet(GLUT_WINDOW_WIDTH) / 2);

    float deltaX = - (centerX - x);
    float deltaY = - (centerY - y);

    camera.rotationY += deltaX;
    camera.rotationX += ratio * deltaY;

    if(camera.rotationY > ((180 * 360) / M_PI)) {
        camera.rotationY -= (180 * 360) / M_PI;
    }

    if(camera.rotationY < - ((180 * 360) / M_PI)) {
        camera.rotationY += (180 * 360) / M_PI;
    }

    glutWarpPointer(centerX, centerY);
}

void idle() {
	glutPostRedisplay();
}