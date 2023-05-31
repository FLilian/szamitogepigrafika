#include <GL/glut.h>

#include "objects.h"
#include "model.h"
#include "texture.h"
#include "draw.h"

float fishX = -25.0f;
float fishSpeed = 0.1;

float breadY = 4.2f;
float breadSpeed = -0.03;

void renderSkysphere(Skysphere* skysphere) {
	glDisable(GL_LIGHTING);
	GLfloat col[] = {1.0, 1.0, 1.0};
	GLfloat col2[] = {0.0, 0.0, 0.0};
	glMaterialfv(GL_FRONT, GL_EMISSION, col);
		
	glPushMatrix();
		glEnable(GL_STENCIL_TEST);
		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
		glStencilFunc(GL_ALWAYS, 0, -1);
		glBindTexture(GL_TEXTURE_2D, skysphere->textureId);
		draw_model(skysphere->model);
		glDisable(GL_STENCIL_TEST);
	glPopMatrix();	
	
	glMaterialfv(GL_FRONT, GL_EMISSION, col2);
	glEnable(GL_LIGHTING);
}

void initSkysphere(Skysphere* skysphere, Model* model, Texture texture) {
	skysphere->textureId = texture.id;
	skysphere->model = model;
}

void renderChair(Chair* chair) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, chair->textureId);
		glTranslatef(7.2,-2.6,-0.2);
		glRotated(90,0,1,0);
		draw_model(chair->model);
	glPopMatrix();	

}

void initChair(Chair* chair, Model* model, Texture texture) {
	chair->textureId = texture.id;
	chair->model = model;
}

void renderFloor(Floor* floor) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, floor->textureId);
		glTranslatef(0,-2.6,-3);
		draw_model(floor->model);
	glPopMatrix();	
	
}

void initFloor(Floor* floor, Model* model, Texture texture) {
	floor->textureId = texture.id;
	floor->model = model;
}

void renderDesk(Desk* desk) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, desk->textureId);
		glTranslatef(9,-2,-0.2);
        glRotated(90,0,1,0);
		draw_model(desk->model);
	glPopMatrix();	
	
}

void initDesk(Desk* desk, Model* model, Texture texture) {
	desk->textureId = texture.id;
	desk->model = model;
}

void renderTv_cupboard(Tv_cupboard* tv_cupboard) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, tv_cupboard->textureId);
		glTranslatef(-5.5,-2.6,-7.5);
        glRotated(90,0,1,0);
		draw_model(tv_cupboard->model);
	glPopMatrix();	
}

void initTv_cupboard(Tv_cupboard* tv_cupboard, Model* model, Texture texture) {
	tv_cupboard->textureId = texture.id;
	tv_cupboard->model = model;
}

void renderSupercomputer(Supercomputer* supercomputer) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, supercomputer->textureId);
		glTranslatef(-7.3,-2.6,9);
        glRotated(90,0,1,0);
		draw_model(supercomputer->model);
	glPopMatrix();	
}

void initSupercomputer(Supercomputer* supercomputer, Model* model, Texture texture) {
	supercomputer->textureId = texture.id;
	supercomputer->model = model;
}

void renderSpeaker(Speaker* speaker) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, speaker->textureId);
		glTranslatef(8,-2.6,8);
        glRotated(90,0,1,0);
        glRotated(90,0,1,0);
     
		draw_model(speaker->model);
	glPopMatrix();	
}

void initSpeaker(Speaker* speaker, Model* model, Texture texture) {
	speaker->textureId = texture.id;
	speaker->model = model;
}

void renderCeiling(Ceiling* ceiling) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, ceiling->textureId);
		glTranslatef(0,3.15,-3);
		draw_model(ceiling->model);
	glPopMatrix();	
	
}

void initCeiling(Ceiling* ceiling, Model* model, Texture texture) {
	ceiling->textureId = texture.id;
	ceiling->model = model;
}

void renderBook(Book* book) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, book->textureId);
		glTranslatef(9,-0.5,1);
        glRotated(90,0,1,0);
		glRotated(90,0,1,0);
		glRotated(90,0,1,0);
		draw_model(book->model);
	glPopMatrix();	
	
}

void initBook(Book* book, Model* model, Texture texture) {
	book->textureId = texture.id;
	book->model = model;
}

void renderNotebook(Notebook* notebook) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, notebook->textureId);
		glTranslatef(9,-0.6,-1);

        
		
		draw_model(notebook->model);
	glPopMatrix();	
	
}

void initNotebook(Notebook* notebook, Model* model, Texture texture) {
	notebook->textureId = texture.id;
	notebook->model = model;
}

void renderClock(Clock* clock) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, clock->textureId);
		glTranslatef(-3,5,11.9);
		glRotated(90,0,1,0);
		
		glRotated(133,1,0,0);
        
		
		draw_model(clock->model);
	glPopMatrix();	
	
}

void initClock(Clock* clock, Model* model, Texture texture) {
	clock->textureId = texture.id;
	clock->model = model;
}

void renderWall(Wall* wall) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, wall->textureId);
		glTranslatef(0,-1.1,12);
        glRotated(90,0,1,0);
		glRotated(90,0,1,0);
		glRotated(90,0,0,1);
		draw_model(wall->model);
	glPopMatrix();	
}

void initWall(Wall* wall, Model* model, Texture texture) {
	wall->textureId = texture.id;
	wall->model = model;
}

void renderWall2(Wall2* wall2) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, wall2->textureId);
		glTranslatef(0,1.65,-18);
        glRotated(180,0,1,0);
		glRotated(180,1,0,0);
		glRotated(90,0,0,1);
		
		draw_model(wall2->model);
	glPopMatrix();	
}

void initWall2(Wall2* wall2, Model* model, Texture texture) {
	wall2->textureId = texture.id;
	wall2->model = model;
}

void renderWall3(Wall3* wall3) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, wall3->textureId);
		glTranslatef(-10.5,-1.1,-3);
		glScalef(1,1,1.43);
        glRotated(90,0,1,0);
		glRotated(90,0,0,1);
		draw_model(wall3->model);
	glPopMatrix();	
}

void initWall3(Wall3* wall3, Model* model, Texture texture) {
	wall3->textureId = texture.id;
	wall3->model = model;
}

void renderWall4(Wall4* wall4) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, wall4->textureId);
		glTranslatef(10.5,1.65,3.62);
		glScalef(1,1,0.8);
        glRotated(270,0,1,0);
		glRotated(180,1,0,0);
		glRotated(90,0,0,1);
		draw_model(wall4->model);
	glPopMatrix();	
}

void initWall4(Wall4* wall4, Model* model, Texture texture) {
	wall4->textureId = texture.id;
	wall4->model = model;
}

void renderFish(Fish* fish) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, fish->textureId);
		glRotated(90,0,1,0);
		glRotated(90,0,1,0);
		glRotated(90,0,1,0);
		glRotated(90,0,1,0);
		if(fishX > 25.0 && fishSpeed > 0) {
            fishSpeed = -0.1;
		}
        else if(fishX < -25.0 && fishSpeed < 0) {
            fishSpeed = 0.1;
        }
        fishX += fishSpeed;

        glTranslatef(fishX, -1, -6.6);

        if(fishSpeed > 0) {
            glRotatef(90,0,1,0);
        } else {
            glRotatef(-90,0,1,0);
        }
		draw_model(fish->model);
	glPopMatrix();	
	
}

void initFish(Fish* fish, Model* model, Texture texture) {
	fish->textureId = texture.id;
	fish->model = model;
}

void renderTv(Tv* tv) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, tv->textureId);
		glTranslatef(-7,0.7,-12.5);
        glRotated(90,0,1,0);
		draw_model(tv->model);
	glPopMatrix();	
}

void initTv(Tv* tv, Model* model, Texture texture) {
	tv->textureId = texture.id;
	tv->model = model;
}

void renderCrate(Crate* crate) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, crate->textureId);
		glTranslatef(-1,-1.6,-16);
        glRotated(90,0,1,0);
		draw_model(crate->model);
	glPopMatrix();	
}

void initCrate(Crate* crate, Model* model, Texture texture) {
	crate->textureId = texture.id;
	crate->model = model;
}

void renderBread(Bread* bread) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, bread->textureId);
		glTranslatef(4,-1.6,-17);
        glRotated(90,0,1,0);
		
		if(breadY > 2.6 && breadSpeed > 0) {
            breadSpeed = -0.03;
		}
        else if(breadY < -0.8 && breadSpeed < 0) {
            breadSpeed = 0.03;
        }
        breadY += breadSpeed;

        glTranslatef(-3, breadY, 2);
		
		draw_model(bread->model);
	glPopMatrix();	
}

void initBread(Bread* bread, Model* model, Texture texture) {
	bread->textureId = texture.id;
	bread->model = model;
}