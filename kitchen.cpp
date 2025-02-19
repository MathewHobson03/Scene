#include <GL/glut.h>

void drawFridge();
void drawDrawers();
void drawCabinets();

void drawCupboard();
void drawHandles();
void drawStove();
void drawMicrowave();
void drawUpperCabinets();
void drawLeftCabinet();

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

    glutSwapBuffers();
}

void drawFridge() {
    glPushMatrix();
        // Transformations
        glTranslatef(15.25, 6.0, 0.0);
        glScalef(3.0, 3.0, 3.0);

        // Draw the fridge body
        glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);  
            glScalef(1.0, 2.0, 1.0);   
            glutSolidCube(2);
        glPopMatrix();

        // Draw door separation (horizontal line)
        glPushMatrix();
            glColor3f(0.4, 0.4, 0.4); 
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
            glColor3f(0.8, 0.8, 0.8); 
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
            glColor3f(0.8, 0.8, 0.8); 
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
            glColor3f(0.8, 0.8, 0.8); 
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
            glColor3f(0.8, 0.8, 0.8); 
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
            glColor3f(0.8, 0.8, 0.8);
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
            glColor3f(0.8, 0.8, 0.8);
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
}

// ########################################################################################################################################################################

void init() {
    glEnable(GL_DEPTH_TEST);  // Enable depth testing

    // Set Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 800.0 / 600.0, 0.1, 100);  // FOV, Aspect, Near, Far

    glMatrixMode(GL_MODELVIEW); // Switch back to ModelView
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
