#include <GL/glut.h>
#include <cstdio>


void render() {
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex2f(-0.33, -0.33);

        glColor3f(0, 1, 0);
        glVertex2f(0.33, -0.33);

        glColor3f(0, 0, 1);
        glVertex2f(0, 0.33);
    glEnd();
    glutSwapBuffers();
}

void mouse(int buttom, int state, int x, int y) {
    if (buttom == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        printf("Left click!\n");
    }
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27) {
        exit(0);
    }
}


int main(int argc, char** argv) {

    // Initialization
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(1000, 400); 
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("Window 00"); 

    // Definition of callbacks
    glutDisplayFunc(render);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    
    // Start main loop
    glutMainLoop();
}