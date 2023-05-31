#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <GL/glut.h>


/**
 * Sets GLUT callbacks to the corresponding functions.
 */
void setCallbacks();

/**
 * Call when need to display the graphical content.
 */
void display();

/**
 * Call after windows resizing.
 */
void reshape(GLsizei width, GLsizei height);

/**
 * Call after keyboard function button event.
 */
void keyboardSpecialButtonHandler (int key, int x, int y);

/**
 * Call after keyboard event.
 */
void key(unsigned char key, int x, int y);

void keyRelease(unsigned char key, int x, int y);

/**
 * Call after mouse event.
 */
void mouse(int x, int y);


/**
 * Call when there is no other event.
 */
void idle();


#endif /* CALLBACKS_H */
