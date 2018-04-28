#include "Entity.h"

Entity::Entity(){
    radius = 40;
    r = 1.0;
    g = 0.0;
    b = 0.0;
}


Entity::Entity(bool c){
    isCircle = c;
    r = 1.0;
    g = 0.0;
    b = 0.0;
    
    if(c){
    radius = 40;
    }
    else{
    length = .1;
    height = .1;        
    }
}

Entity::~Entity(){

}

void Entity::draw(){
    
	if(this->type == hero){
		glColor3d(0,1,1);
		glPointSize(radius);
		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();
		glColor3d(0,0,0);	
		
	}
	else if(isCircle){
		glColor3d(1,1,1);
		glPointSize(radius);
    // Draw something
		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();
		glColor3d(0,0,0);
	}else{
		glPointSize(length);
		glColor3d(1,1,1);	
		glBegin(GL_POLYGON);
		glVertex2f(x-length/2, y+height/2);
		glVertex2f(x+length/2, y+height/2);
		glVertex2f(x+length/2, y-height/2);
		glVertex2f(x-length/2, y-height/2);
		glEnd();	
		glColor3d(0,0,0);
	}

	



	
	
	

    //MAYBE A TEXTURE
    /*
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)*/
}
