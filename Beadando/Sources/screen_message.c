#include <GL/glut.h>
#include <stdbool.h>

#include "utils.h"
#include "texture.h"
#include "screen_message.h"


void HelpMenu(int key, ShownScreenMessage* shownMessage) {
	if(key == GLUT_KEY_F1) {
		if(*shownMessage == NONE) {
			*shownMessage = HELP;
		} else if (*shownMessage == HELP) {
			*shownMessage = NONE;
		}
	}
}

void renderScreenMessage(Texture shownScreenMessageTexture) {
	glPushMatrix();
		GLint viewport[4];
		GLdouble modelview[16];
		GLdouble projection[16];
		double w = glutGet(GLUT_WINDOW_WIDTH);
		double h = glutGet(GLUT_WINDOW_HEIGHT);
		glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
		glGetDoublev( GL_PROJECTION_MATRIX, projection );
		glGetIntegerv( GL_VIEWPORT, viewport );
		double depth=0.01;
		
		Position3D upRight;
		Position3D upLeft;
		Position3D downRight;
		Position3D downLeft;

		gluUnProject( w, h, depth, modelview, projection, viewport, &upRight.x, &upRight.y, &upRight.z);
		gluUnProject( 0, h, depth, modelview, projection, viewport, &upLeft.x, &upLeft.y, &upLeft.z);
		gluUnProject( w, 0, depth, modelview, projection, viewport, &downRight.x, &downRight.y, &downRight.z);
		gluUnProject( 0, 0, depth, modelview, projection, viewport, &downLeft.x, &downLeft.y, &downLeft.z);
			
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDisable(GL_LIGHTING);
		glBindTexture(GL_TEXTURE_2D, shownScreenMessageTexture.id);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0,1.0);
			glVertex3f(downLeft.x, downLeft.y, downLeft.z);
			glTexCoord2f(1.0,1.0);
			glVertex3f(downRight.x, downRight.y, downRight.z);
			glTexCoord2f(1.0,0.0);
			glVertex3f(upRight.x, upRight.y, upRight.z);
			glTexCoord2f(0.0,0.0);
			glVertex3f(upLeft.x, upLeft.y, upLeft.z);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_BLEND);
				
	glPopMatrix();
}
