#include <GL/glut.h>
#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include<stdio.h>
#include <ostream>
#include <iostream>
#include <GL/glext.h>
#include <GLES2/gl2.h>

void drawFridge();
void drawDrawers();
void drawCabinets();

void drawCupboard();
void drawHandles();
void drawStove();
void drawMicrowave();
void drawUpperCabinets();
void drawLeftCabinet();

void drawWallsAndCeiling();

GLuint floorTexture;
GLuint wallTexture;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Setup camera
    gluLookAt(0, 10, 25,  // Camera position (eye)
              10, 8, 0,   // Look at this point
              0, 1, 0);  // Up vector


    drawFridge();
    drawDrawers();
    drawCabinets();

    drawCupboard();
    drawHandles();
    drawStove();
    drawMicrowave();
    drawUpperCabinets();
    drawLeftCabinet();

    drawWallsAndCeiling();

    glutSwapBuffers();
}

void drawWallsAndCeiling() {
    // Enable texturing
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, wallTexture);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);  // White color to avoid tinting the texture

    // Back Wall (moved back by 2)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10, 0, -2);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(30, 0, -2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(30, 20, -2);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-10, 20, -2);

    // Left Wall
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10, 0, -2);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-10, 20, -2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-10, 20, 10);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-10, 0, 10);

    // Right Wall
    glTexCoord2f(0.0f, 0.0f); glVertex3f(20, 0, -2);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(20, 20, -2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(20, 20, 10);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(20, 0, 10);

    glEnd();

    // Disable texturing for the ceiling
    glDisable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
    glColor3f(9.0f, 0.96f, 0.96f);  // Cream color

    // Ceiling
    glVertex3f(-10, 19, -2);
    glVertex3f(20, 19, -2);
    glVertex3f(20, 19, 10);
    glVertex3f(-10, 19, 10);

    glEnd();

    // Enable texturing for the floor
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, floorTexture);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);  // White color to avoid tinting the texture

    // Floor (extended forward by 3)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10, 0, -2);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(20, 0, -2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(20, 0, 13);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-10, 0, 13);

    glEnd();

    // Disable texturing
    glDisable(GL_TEXTURE_2D);
}

void drawFridge() {
    glPushMatrix();
        // Transformations
        glTranslatef(15.25, 6.0, 0.0);
        glScalef(3.0, 3.0, 3.0);

        // Draw the fridge body
        glPushMatrix();
            glColor3f(0.15, 0.15, 0.15);  
            glScalef(1.0, 2.0, 1.0);   
            glutSolidCube(2);
        glPopMatrix();

        // Draw door separation (horizontal line)
        glPushMatrix();
            glColor3f(0.1, 0.1, 0.1); 
            glBegin(GL_QUADS);
                glVertex3f(-1.0, 0.80, 1.01);  // Top left
                glVertex3f( 1.0, 0.80, 1.01);  // Top right
                glVertex3f( 1.0, 0.70, 1.01); // Bottom right
                glVertex3f(-1.0, 0.70, 1.01); // Bottom left
            glEnd();
        glPopMatrix();

        // Draw cube edges for better definition (wireframe)
        glPushMatrix();
            glColor3f(0, 0, 0); 
            glScalef(1.01, 2.01, 1.01); 
            glutWireCube(2);
        glPopMatrix();
    glPopMatrix();
}

void drawDrawers() {
    glPushMatrix();
        // Transformations
        glTranslatef(10.5, 4.0, -0.8);
        glScalef(5.0, 5.0, 5.0);

        // Draw drawer 1
        glPushMatrix();
            glColor3f(0.4f, 0.2f, 0.1f); 
            glTranslatef(0.0, 0.6, 0.0);
            glScalef(0.3, 0.2, 0.6);
            glutSolidCube(2);  
        glPopMatrix();
        glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            glTranslatef(0.0, 0.6, 0.6);
            glScalef(0.1, 0.03, 0.1);
            glutSolidCube(2);
        glPopMatrix();
        glPushMatrix();
            glColor3f(0, 0, 0);  
            glTranslatef(0.0, 0.6, 0.0);
            glScalef(0.301, 0.201, 0.601);
            glutWireCube(2);
        glPopMatrix();

        // Draw drawer 2
        glPushMatrix();
            glColor3f(0.4f, 0.2f, 0.1f); 
            glTranslatef(0.0, 0.2, 0.0);
            glScalef(0.3, 0.2, 0.6);
            glutSolidCube(2);  
        glPopMatrix();
        glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            glTranslatef(0.0, 0.2, 0.6);
            glScalef(0.1, 0.03, 0.1);
            glutSolidCube(2);
        glPopMatrix();
        glPushMatrix();
            glColor3f(0, 0, 0); 
            glTranslatef(0.0, 0.2, 0.0); 
            glScalef(0.301, 0.201, 0.601);
            glutWireCube(2);
        glPopMatrix();

        // Draw drawer 3
        glPushMatrix();
            glColor3f(0.4f, 0.2f, 0.1f); 
            glTranslatef(0.0, -0.2, 0.0);
            glScalef(0.3, 0.2, 0.6);
            glutSolidCube(2);  
        glPopMatrix();
        glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            glTranslatef(0.0, -0.2, 0.6);
            glScalef(0.1, 0.03, 0.1);
            glutSolidCube(2);
        glPopMatrix();
        glPushMatrix();
            glColor3f(0, 0, 0); 
            glTranslatef(0.0, -0.2, 0.0); 
            glScalef(0.301, 0.201, 0.601);
            glutWireCube(2);
        glPopMatrix();
        
        // Draw drawer 4
        glPushMatrix();
            glColor3f(0.4f, 0.2f, 0.1f); 
            glTranslatef(0.0, -0.6, 0.0);
            glScalef(0.3, 0.2, 0.6);
            glutSolidCube(2);  
        glPopMatrix();
        glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            glTranslatef(0.0, -0.6, 0.6);
            glScalef(0.1, 0.03, 0.1);
            glutSolidCube(2);
        glPopMatrix();
        glPushMatrix();
            glColor3f(0, 0, 0); 
            glTranslatef(0.0, -0.6, 0.0); 
            glScalef(0.301, 0.201, 0.601);
            glutWireCube(2);
        glPopMatrix();

    glPopMatrix();
}

void drawCabinets() {
    glPushMatrix();
        // Transformations
        glTranslatef(15.0, 14.5, 2.0);
        glScalef(3.0, 3.0, 1.0);

        // Draw cabinet above fridge
        // base
        glPushMatrix();
            glColor3f(0.5f, 0.3f, 0.1f);
            glTranslatef(0.0, 0.0, 0.0);
            glScalef(2.0, 1.0, 1.0);
            glBegin(GL_QUADS);
                glVertex3f(-0.5, -0.5, 0.0); // Bottom left
                glVertex3f(0.5, -0.5, 0.0); // Bottom right
                glVertex3f(0.5, 0.5, 0.0); // Top right
                glVertex3f(-0.5, 0.5, 0.0); // Top left
            glEnd();
        glPopMatrix();
        // center line
        glPushMatrix();
            glColor3f(0, 0, 0);
            glBegin(GL_LINES);
                glVertex3f(0.0, -0.5, 0.01);  // Bottom center
                glVertex3f(0.0,  0.5, 0.01);  // Top center
            glEnd();
        glPopMatrix();
        // left handle
        glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            glBegin(GL_QUADS);
                glVertex3f(-0.15,  0.1, 0.02); // Top left
                glVertex3f(-0.1,  0.1, 0.02); // Top right
                glVertex3f(-0.1, -0.4, 0.02); // Bottom right
                glVertex3f(-0.15, -0.4, 0.02); // Bottom left
            glEnd();
        glPopMatrix();
        // right handle
        glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            glBegin(GL_QUADS);
                glVertex3f(0.1,  0.1, 0.02); // Top left
                glVertex3f(0.15,  0.1, 0.02); // Top right
                glVertex3f(0.15, -0.4, 0.02); // Bottom right
                glVertex3f(0.1, -0.4, 0.02); // Bottom left
            glEnd();
        glPopMatrix();  

        // Draw right cabinet
        // base
        glPushMatrix();
            glColor3f(0.5f, 0.3f, 0.1f);
            glTranslatef(-1.5, -0.5, 0.0);
            glScalef(1.0, 2.0, 1.0);
            glBegin(GL_QUADS);
                glVertex3f(-0.5, -0.5, 0.0); // Bottom left
                glVertex3f(0.5, -0.5, 0.0); // Bottom right
                glVertex3f(0.5, 0.5, 0.0); // Top right
                glVertex3f(-0.5, 0.5, 0.0); // Top left
            glEnd();
        glPopMatrix();
        // handle
        glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            glTranslatef(-2.0, -1.0, 0.0);
            glBegin(GL_QUADS);
                glVertex3f(0.1,  0.1, 0.02); // Top left
                glVertex3f(0.15,  0.1, 0.02); // Top right
                glVertex3f(0.15, -0.4, 0.02); // Bottom right
                glVertex3f(0.1, -0.4, 0.02); // Bottom left
            glEnd();
        glPopMatrix();
        // right border line
        glPushMatrix();
            glColor3f(0, 0, 0);
            glBegin(GL_LINES);
                glVertex3f(-1.0, -0.5, 0.01);  // Bottom center
                glVertex3f(-1.0,  0.5, 0.01);  // Top center
            glEnd();
        glPopMatrix();
        // left border line
        glPushMatrix();
            glColor3f(0, 0, 0);
            glBegin(GL_LINES);
                glVertex3f(-2.0, -1.49, 0.01);  // Bottom center
                glVertex3f(-2.0,  0.5, 0.01);  // Top center
            glEnd();
        glPopMatrix();


    glPopMatrix();
}


// #####################################################################################################################################


void drawCupboard(){
    glBegin(GL_QUADS);

// Bottom Face
glColor3f(0.4f, 0.2f, 0.1f); // A deeper brown shade

glVertex3f(0, 0, -4);
glVertex3f(3, 0, -4);
glVertex3f(3, 0, 2);
glVertex3f(0, 0, 2);

// Top Face
glColor3f(0.4f, 0.2f, 0.1f); // A deeper brown shade

glVertex3f(0, 8, -4);
glVertex3f(3, 8, -4);
glVertex3f(3, 8, 2);
glVertex3f(0, 8, 2);

// Front Face
glColor3f(0.4f, 0.2f, 0.1f); // A deeper brown shade

glVertex3f(0, 0, 2);
glVertex3f(3, 0, 2);
glVertex3f(3, 8, 2);
glVertex3f(0, 8, 2);

// Back Face
glColor3f(0.4f, 0.2f, 0.1f); // A deeper brown shade

glVertex3f(0, 0, -4);
glVertex3f(3, 0, -4);
glVertex3f(3, 8, -4);
glVertex3f(0, 8, -4);

// Left Face
glColor3f(0.82f, 0.71f, 0.55f); // A lighter brown, more like tan

glVertex3f(0, 0, -4);
glVertex3f(0, 0, 2);
glVertex3f(0, 8, 2);
glVertex3f(0, 8, -4);

// Right Face
glColor3f(0.82f, 0.71f, 0.55f); // A lighter brown, more like tan
glVertex3f(3, 0, -4);
glVertex3f(3, 0, 2);
glVertex3f(3, 8, 2);
glVertex3f(3, 8, -4);

glEnd();


}
void drawHandles(){
    glBegin(GL_QUADS);

// Front Face (Z = 2.3) (Neutral Gray)
glColor3f(0.5f, 0.5f, 0.5f);
glVertex3f(0.3, 4.0, 2.3);
glVertex3f(0.6, 4.0, 2.3);
glVertex3f(0.6, 5.2, 2.3);
glVertex3f(0.3, 5.2, 2.3);

// Back Face (Z = 2.01) (Neutral Gray)
glColor3f(0.5f, 0.5f, 0.5f);
glVertex3f(0.3, 4.0, 2.01);
glVertex3f(0.3, 5.2, 2.01);
glVertex3f(0.6, 5.2, 2.01);
glVertex3f(0.6, 4.0, 2.01);

// Left Face (X = 0.3) (Soft White)
glColor3f(0.8f, 0.8f, 0.8f);
glVertex3f(0.3, 4.0, 2.01);
glVertex3f(0.3, 5.2, 2.01);
glVertex3f(0.3, 5.2, 2.3);
glVertex3f(0.3, 4.0, 2.3);

// Right Face (X = 0.6) (Soft White)
glColor3f(0.8f, 0.8f, 0.8f);
glVertex3f(0.6, 4.0, 2.01);
glVertex3f(0.6, 4.0, 2.3);
glVertex3f(0.6, 5.2, 2.3);
glVertex3f(0.6, 5.2, 2.01);

// Top Face (Y = 5.2) (Dark Gray)
glColor3f(0.15f, 0.15f, 0.15f);
glVertex3f(0.3, 5.2, 2.01);
glVertex3f(0.6, 5.2, 2.01);
glVertex3f(0.6, 5.2, 2.3);
glVertex3f(0.3, 5.2, 2.3);

// Bottom Face (Y = 4.0) (Dark Gray)
glColor3f(0.15f, 0.15f, 0.15f);
glVertex3f(0.3, 4.0, 2.01);
glVertex3f(0.3, 4.0, 2.3);
glVertex3f(0.6, 4.0, 2.3);
glVertex3f(0.6, 4.0, 2.01);

glEnd();
glColor3f(0, 0, 0);  // Set line color to black
glLineWidth(3.0f);   // Set line thickness

glBegin(GL_LINES);
    glVertex3f(0,6,2.01);  // Start point of the line (X, Y, Z)
    glVertex3f(3,6, 2.01);  // End point of the line
glEnd();

glBegin(GL_QUADS);

// Front Face (Z = 2.3) (Neutral Gray)
glColor3f(0.5f, 0.5f, 0.5f);
glVertex3f(1.0, 7.2, 2.3);
glVertex3f(2.0, 7.2, 2.3);
glVertex3f(2.0, 7.5, 2.3);
glVertex3f(1.0, 7.5, 2.3);

// Back Face (Z = 2.01) (Neutral Gray)
glColor3f(0.5f, 0.5f, 0.5f);
glVertex3f(1.0, 7.2, 2.01);
glVertex3f(1.0, 7.5, 2.01);
glVertex3f(2.0, 7.5, 2.01);
glVertex3f(2.0, 7.2, 2.01);

// Left Face (X = 1.0) (Soft White)
glColor3f(0.8f, 0.8f, 0.8f);
glVertex3f(1.0, 7.2, 2.01);
glVertex3f(1.0, 7.2, 2.3);
glVertex3f(1.0, 7.5, 2.3);
glVertex3f(1.0, 7.5, 2.01);

// Right Face (X = 2.0) (Soft White)
glColor3f(0.8f, 0.8f, 0.8f);
glVertex3f(2.0, 7.2, 2.01);
glVertex3f(2.0, 7.5, 2.01);
glVertex3f(2.0, 7.5, 2.3);
glVertex3f(2.0, 7.2, 2.3);

// Top Face (Y = 6.5) (Dark Gray)
glColor3f(0.15f, 0.15f, 0.15f);
glVertex3f(1.0, 7.5, 2.01);
glVertex3f(2.0, 7.5, 2.01);
glVertex3f(2.0, 7.5, 2.3);
glVertex3f(1.0, 7.5, 2.3);

// Bottom Face (Y = 6.2) (Dark Gray)
glColor3f(0.15f, 0.15f, 0.15f);
glVertex3f(1.0, 7.2, 2.01);
glVertex3f(1.0, 7.2, 2.3);
glVertex3f(2.0, 7.2, 2.3);
glVertex3f(2.0, 7.2, 2.01);

glEnd();
}

void drawStove(){
    glBegin(GL_QUADS);
        // Front Face (Z = 2)
        glVertex3f(3, 0, 2);
        glVertex3f(9, 0, 2);
        glVertex3f(9, 8, 2);
        glVertex3f(3, 8, 2);

        // Back Face (Z = 0)
        glVertex3f(3, 0, -4);
        glVertex3f(3, 8, -4);
        glVertex3f(9, 8, -4);
        glVertex3f(9, 0, -4);

        // Left Face (X = 3)
        glVertex3f(3, 0, -4);
        glVertex3f(3, 0, 2);
        glVertex3f(3, 8, 2);
        glVertex3f(3, 8, -4);

        // Right Face (X = 9)
        glVertex3f(9, 0, -4);
        glVertex3f(9, 8, -4);
        glVertex3f(9, 8, 2);
        glVertex3f(9, 0, 2);

        // Top Face (Y = 8)
        glVertex3f(3, 8, -4);
        glVertex3f(3, 8, 2);
        glVertex3f(9, 8, 2);
        glVertex3f(9, 8, -4);

        // Bottom Face (Y = 0)
        glVertex3f(3, 0, -4);
        glVertex3f(9, 0, -4);
        glVertex3f(9, 0, 2);
        glVertex3f(3, 0, 2);
    glEnd();

   glBegin(GL_QUADS);
glColor4f(0.0f, 0.1f, 0.2f, 0.6f);  // Dark blue-tinted glass

// Adjust X position to be centered within the stove
glVertex3f(4.5, 4, 2.01); // Left
glVertex3f(7.5, 4, 2.01); // Right
glVertex3f(7.5, 7, 2.01); // Top Right
glVertex3f(4.5, 7, 2.01); // Top Left
glEnd();
glBegin(GL_QUADS);
glColor3f(0, 0, 0);  // Black handle

// Front Face (Z = 2.1)
glVertex3f(3.2, 7.3, 2.1);
glVertex3f(8.8, 7.3, 2.1);
glVertex3f(8.8, 7.6, 2.1);
glVertex3f(3.2, 7.6, 2.1);

// Back Face (Z = 2.01)
glVertex3f(3.2, 7.3, 2.01);
glVertex3f(3.2, 7.6, 2.01);
glVertex3f(8.8, 7.6, 2.01);
glVertex3f(8.8, 7.3, 2.01);

// Left Face (X = 3.2)
glVertex3f(3.2, 7.3, 2.01);
glVertex3f(3.2, 7.3, 2.1);
glVertex3f(3.2, 7.6, 2.1);
glVertex3f(3.2, 7.6, 2.01);

// Right Face (X = 8.8)
glVertex3f(8.8, 7.3, 2.01);
glVertex3f(8.8, 7.6, 2.01);
glVertex3f(8.8, 7.6, 2.1);
glVertex3f(8.8, 7.3, 2.1);

// Top Face (Y = 7.6)
glVertex3f(3.2, 7.6, 2.01);
glVertex3f(8.8, 7.6, 2.01);
glVertex3f(8.8, 7.6, 2.1);
glVertex3f(3.2, 7.6, 2.1);

// Bottom Face (Y = 7.3)
glVertex3f(3.2, 7.3, 2.01);
glVertex3f(3.2, 7.3, 2.1);
glVertex3f(8.8, 7.3, 2.1);
glVertex3f(8.8, 7.3, 2.01);

glEnd();

// Add four black circles as burners on the top surface of the stove
glColor3f(0.6, 0.6, 0.6);  // Black color for burners
int num_segments = 32;
float radius = 0.5f;  // Burner radius
// Burner center positions on the top surface (Y = 8.001 to avoid z-fighting)
float burners[4][2] = {
    {4.5f, -3.0f},
    {7.5f, -3.0f},
    {4.5f, -1.0f},
    {7.5f, -1.0f}
};
for (int b = 0; b < 4; b++){
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++){
        float theta = 2.0f * 3.14159f * float(i) / float(num_segments);
        float x = radius * cos(theta);
        float z = radius * sin(theta);
        glVertex3f(burners[b][0] + x, 8.001f, burners[b][1] + z);
    }
    glEnd();
}

}

void drawUpperCabinets() {
    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.3f, 0.1f);  // Brown cabinets

    // **Left Cabinet**
    // Front Face
    glVertex3f(3, 13, 2);
    glVertex3f(6, 13, 2);
    glVertex3f(6, 16, 2);
    glVertex3f(3, 16, 2);

    // Back Face
    glVertex3f(3, 13, -4);
    glVertex3f(3, 16, -4);
    glVertex3f(6, 16, -4);
    glVertex3f(6, 13, -4);

    // Left Face
    glVertex3f(3, 13, -4);
    glVertex3f(3, 13, 2);
    glVertex3f(3, 16, 2);
    glVertex3f(3, 16, -4);

    // Right Face
    glVertex3f(6, 13, -4);
    glVertex3f(6, 16, -4);
    glVertex3f(6, 16, 2);
    glVertex3f(6, 13, 2);

    // Top Face
    glVertex3f(3, 16, -4);
    glVertex3f(3, 16, 2);
    glVertex3f(6, 16, 2);
    glVertex3f(6, 16, -4);

    // Bottom Face
    glVertex3f(3, 13, -4);
    glVertex3f(6, 13, -4);
    glVertex3f(6, 13, 2);
    glVertex3f(3, 13, 2);

    // **Right Cabinet**
    // Front Face
    glVertex3f(6, 13, 2);
    glVertex3f(9, 13, 2);
    glVertex3f(9, 16, 2);
    glVertex3f(6, 16, 2);

    // Back Face
    glVertex3f(6, 13, -4);
    glVertex3f(6, 16, -4);
    glVertex3f(9, 16, -4);
    glVertex3f(9, 13, -4);

    // Left Face
    glVertex3f(6, 13, -4);
    glVertex3f(6, 13, 2);
    glVertex3f(6, 16, 2);
    glVertex3f(6, 16, -4);

    // Right Face
    glVertex3f(9, 13, -4);
    glVertex3f(9, 16, -4);
    glVertex3f(9, 16, 2);
    glVertex3f(9, 13, 2);

    // Top Face
    glVertex3f(6, 16, -4);
    glVertex3f(6, 16, 2);
    glVertex3f(9, 16, 2);
    glVertex3f(9, 16, -4);

    // Bottom Face
    glVertex3f(6, 13, -4);
    glVertex3f(9, 13, -4);
    glVertex3f(9, 13, 2);
    glVertex3f(6, 13, 2);

    glEnd();
    // **Draw Line to Split the Two Cabinets**
glColor3f(0, 0, 0);  // Black color
glLineWidth(3.0f);   // Set line thickness

glBegin(GL_LINES);
// Draw the vertical split at X = 6 (Front)
glVertex3f(6, 13, 2);
glVertex3f(6, 16, 2);

// Draw the vertical split at X = 6 (Back)
glVertex3f(6, 13, -4);
glVertex3f(6, 16, -4);
glEnd();
    // **Draw Handles**
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);  // Silver handle color

    // **Left Cabinet Handle (on the right side of the left cabinet)**
    glVertex3f(5.4, 14, 2.1);
    glVertex3f(5.7, 14, 2.1);
    glVertex3f(5.7, 15.2, 2.1);
    glVertex3f(5.4, 15.2, 2.1);

    // **Right Cabinet Handle (on the left side of the right cabinet)**
    glVertex3f(6.3, 14, 2.1);
    glVertex3f(6.6, 14, 2.1);
    glVertex3f(6.6, 15.2, 2.1);
    glVertex3f(6.3, 15.2, 2.1);

    glEnd();

}


void drawMicrowave() {
    glBegin(GL_QUADS);

    // **Front Face**
    glColor3f(0.2f, 0.2f, 0.2f);  // Dark gray
    glVertex3f(3, 10, 2);
    glVertex3f(9, 10, 2);
    glVertex3f(9, 13, 2);
    glVertex3f(3, 13, 2);

    // **Back Face**
    glVertex3f(3, 10, -4);
    glVertex3f(3, 13, -4);
    glVertex3f(9, 13, -4);
    glVertex3f(9, 10, -4);

    // **Left Face**
    glColor3f(0.3f, 0.3f, 0.3f);  // Slightly lighter gray
    glVertex3f(3, 10, -4);
    glVertex3f(3, 10, 2);
    glVertex3f(3, 13, 2);
    glVertex3f(3, 13, -4);

    // **Right Face**
    glVertex3f(9, 10, -4);
    glVertex3f(9, 13, -4);
    glVertex3f(9, 13, 2);
    glVertex3f(9, 10, 2);

    // **Top Face**
    glColor3f(0.4f, 0.4f, 0.4f);  // Even lighter gray
    glVertex3f(3, 13, -4);
    glVertex3f(3, 13, 2);
    glVertex3f(9, 13, 2);
    glVertex3f(9, 13, -4);

    // **Bottom Face**
    glVertex3f(3, 10, -4);
    glVertex3f(9, 10, -4);
    glVertex3f(9, 10, 2);
    glVertex3f(3, 10, 2);

    glEnd();

    // Microwave window
    glBegin(GL_QUADS);
    glColor4f(0.1f, 0.1f, 0.1f, 0.7f);  // Dark tinted glass
    glVertex3f(3.5, 10.5, 2.01);
    glVertex3f(6, 10.5, 2.01);
    glVertex3f(6, 12, 2.01);
    glVertex3f(3.5, 12, 2.01);
    glEnd();

    // Microwave handle
    glBegin(GL_QUADS);
    glColor3f(0.15f, 0.15f, 0.15f);  // Dark tinted glass
    glVertex3f(6.5, 10.5, 2.01);
    glVertex3f(7, 10.5, 2.01);
    glVertex3f(7, 12.5, 2.01);
    glVertex3f(6.5, 12.5, 2.01);
    glEnd();

    // Microwave input panel
    glBegin(GL_QUADS);
    glColor3f(0.125f, 0.125f, 0.15f);  // Darker gray for control panel
    glVertex3f(7.5, 10.5, 2.01);
    glVertex3f(8.5, 10.5, 2.01);
    glVertex3f(8.5, 12.5, 2.01);
    glVertex3f(7.5, 12.5, 2.01);
    glEnd();
}

void drawLeftCabinet() {
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.3f, 0.1f);  // Brown cabinet

    // **Front Face**
    glVertex3f(0, 10, 2);
    glVertex3f(3, 10, 2);
    glVertex3f(3, 16, 2);
    glVertex3f(0, 16, 2);

    // **Back Face**
    glVertex3f(0, 10, -4);
    glVertex3f(0, 16, -4);
    glVertex3f(3, 16, -4);
    glVertex3f(3, 10, -4);

    // **Left Face**
    glVertex3f(0, 10, -4);
    glVertex3f(0, 10, 2);
    glVertex3f(0, 16, 2);
    glVertex3f(0, 16, -4);

    // **Right Face**
    glVertex3f(3, 10, -4);
    glVertex3f(3, 16, -4);
    glVertex3f(3, 16, 2);
    glVertex3f(3, 10, 2);

    // **Top Face**
    glVertex3f(0, 16, -4);
    glVertex3f(0, 16, 2);
    glVertex3f(3, 16, 2);
    glVertex3f(3, 16, -4);

    // **Bottom Face**
    glVertex3f(0, 10, -4);
    glVertex3f(3, 10, -4);
    glVertex3f(3, 10, 2);
    glVertex3f(0, 10, 2);

    glEnd();

    // **Handle for Left Cabinet**
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);  // Silver handle

    // **Front Face**
    glVertex3f(2.4, 12.8, 2.4);
    glVertex3f(2.7, 12.8, 2.4);
    glVertex3f(2.7, 14, 2.4);
    glVertex3f(2.4, 14, 2.4);

    // **Back Face**
    glVertex3f(2.4, 12.8, 2.2);
    glVertex3f(2.7, 12.8, 2.2);
    glVertex3f(2.7, 14, 2.2);
    glVertex3f(2.4, 14, 2.2);

    // **Left Side**
    glVertex3f(2.4, 12.8, 2.2);
    glVertex3f(2.4, 12.8, 2.4);
    glVertex3f(2.4, 14, 2.4);
    glVertex3f(2.4, 14, 2.2);

    // **Right Side**
    glVertex3f(2.7, 12.8, 2.2);
    glVertex3f(2.7, 12.8, 2.4);
    glVertex3f(2.7, 14, 2.4);
    glVertex3f(2.7, 14, 2.2);

    glEnd();

    // Right border line
    glColor3f(0, 0, 0);  // Black color
    glLineWidth(1.0f);   // Set line thickness
    glBegin(GL_LINES);
    glVertex3f(3, 10, 2.01);  // Start point
    glVertex3f(3, 16, 2.01);  // End point
    glEnd();
}

// ########################################################################################################################################################################

void init() {
    glEnable(GL_DEPTH_TEST);  // Enable depth testing

    // Set Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 800.0 / 600.0, 0.1, 100);  // FOV, Aspect, Near, Far

    glMatrixMode(GL_MODELVIEW); // Switch back to ModelView

    int width, height, nrChannels;
    unsigned char* data = stbi_load("Floor-tex.jpg", &width, &height, &nrChannels, 0);
    if (data) {
        glGenTextures(1, &floorTexture);
        glBindTexture(GL_TEXTURE_2D, floorTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        // Set the texture wrapping/filtering options (on the currently bound texture object)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else {
        std::cout << "Failed to load floor texture" << std::endl;
    }

    // Load the wall texture
    data = stbi_load("Wall-tex.jpg", &width, &height, &nrChannels, 0);
    if (data) {
        glGenTextures(1, &wallTexture);
        glBindTexture(GL_TEXTURE_2D, wallTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        // Set the texture wrapping/filtering options (on the currently bound texture object)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else {
        std::cout << "Failed to load wall texture" << std::endl;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Kitchen");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
