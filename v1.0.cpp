#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <GL/freeglut.h>
#include <cstdio>
#include <iostream>
#include <SOIL/SOIL.h>

using namespace std;

void idle(void);
void Sistema_Solar(void);
void Sol_Info(void);
void Mercurio_Info(void);
void Venus_Info(void);
void Tierra_Info(void);
void Marte_Info(void);
void Jupiter_Info(void);
void Saturno_Info(void);
void Urano_Info(void);
void Neptuno_Info(void);
void pauseAnimation(void);
void startAnimation(void);

void si(void);

//Inicializacion para las variables de rotacion al rededor del sol.
GLfloat rotA=0,
        rot1=0,
        rot2=0,
        rot3=2017,
        rot4=0,
        rot5=0,
        rot6=0,
        rot7=0,
        rot8=0,
        rotL=0;
//Inicializacion para la variable de rotacion de la luna al rededor de la Tierra.
GLfloat rotLT=0;

//Variable para rotacion en su propio Eje.
GLfloat rotateEjeY = 0;

//Inicializacion para los radios de los planetas.
GLfloat rdS=20,
        rd1=6,
        rd2=12,
        rd3=9,
        rd4=6,
        rd5=18,
        rd6=15,
        rd7=12,
        rd8=12,
        rdL=3;

GLfloat pos1=40,
        pos2=60,
        pos3=80,
        pos4=100,
        pos5=120,
        pos6=140,
        pos7=160,
        pos8=180,
        posl=95;

GLfloat posx=0,posz=0;

//Variable para la cadena de texto.
char text[500];

//Inicializacion para las variables de traslado y escalado.
GLfloat rotate_y=0.0f;
GLfloat rotate_x=0.0f;
GLfloat scale = 1.5f;

//Variables para la orbita.
GLfloat calx, caly;

// venctor donde almacenaremos el id de la imagen a imprimir
int vf[5]={2};
int opc;

//Variables pata la textura.
GLfloat texSun,
		texMercurio,
		texVenus,
		texTierra,
		texMarte,
		texJupiter,
		texSaturno,
		texUrano,
		texNeptuno,
		texLuna;

//Convirtiendo cuadrados a esferas.
GLUquadricObj *pSphere = NULL;

//Variable para animacion.
int animating = 0;

//Variable para aumentar y disminuir distancia.
int count=0;

//Variable para la orbita.
int countorb=0;
//CREACION DE LOS PLANETAS. --------------------

//Sol.
void Sol(){

    glPushMatrix();  
    sprintf(text, "Sol");
    glColor3f(1, 1, 1);
    glRasterPos3f( (rdS/rdS) , 22 , 0);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texSun);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,rdS,60,60);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

//Mercurio.
void Mercurio(){

    //Rotacion y traslacion para Mercurio.
    glPushMatrix();
    glRotatef(rot1,0,1,0);
    glTranslatef(pos1,0,0);

    //Nombre del planeta
    sprintf(text, "Mercurio");
    glColor3f(1, 1, 1);
    glRasterPos3f( -3 , 22 , 0);
        for(int i = 0; text[i] != '\0'; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    //Rotacion en su eje.
    glRotatef(rotateEjeY,0,1,0);
    
    //Dibujando Planeta.
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texMercurio);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,rd1,60,60);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}

//Venus.
void Venus(){

    //Rotacion y traslacion para Venus.
     glPushMatrix();
     glRotatef(rot2,0,1,0);
     glTranslatef(pos2,0,0);

     sprintf(text, "Venus");
     glColor3f(1, 1, 1);
     glRasterPos3f( -3 , 22 , 0);
     for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    //Rotacion en su eje.
    glRotatef(rotateEjeY,0,1,0);

    //Dibujando Planeta.
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texVenus);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,rd2,60,60);

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}

//Tierra.
void Tierra(){

    //Rotacion y tralacion para Tierra.
     glPushMatrix();
     glRotatef(rot3,0,1,0);
     glTranslatef(pos3,0,0);

     sprintf(text, "Tierra");
     glColor3f(1, 1, 1);
     glRasterPos3f( -3 , 22 , 0);
     for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    //Rotacion en su eje.
    glRotatef(rotateEjeY,0,1,0);
    //Dibujando Planeta.
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texTierra);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,rd3,60,60);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}

//Luna
void Luna(){

//Rotacion y tralacion para Luna.
     glPushMatrix();
     glRotatef(rotL,0,1,0);
     glTranslatef(posl,0,0);

     sprintf(text, "Luna");
     glColor3f(1, 1, 1);
     glRasterPos3f( -3 , 22 , 0);
     for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);

    //Rotacion en su eje.
    glRotatef(rotateEjeY,0,1,0);
    //Dibujando Planeta.
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texLuna);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,rdL,60,60);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glPopMatrix();

}

//Marte.
void Marte(){
//SDL
    //Rotacion y traslacion para Marte.
     glPushMatrix();
     glRotatef(rot4,0,1,0);
     glTranslatef(pos4,0,0);

     sprintf(text, "Marte");
     glColor3f(1, 1, 1);
     glRasterPos3f( -3 , 22 , 0);
     for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    //Rotacion en su eje.
    glRotatef(rotateEjeY,0,1,0);
    //Dibujando Planeta.
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texMarte);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,rd4,60,60);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}

//Jupiter.
void Jupiter(){

    //Rotacion y traslacion para Jupiter.
     glPushMatrix();
     glRotatef(rot5,0,1,0);
     glTranslatef(0,0,-pos5);

     sprintf(text, "Jupiter");
     glColor3f(1, 1, 1);
     glRasterPos3f( -3 , 22 , 0);
     for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    //Rotacion en su eje.
    glRotatef(rotateEjeY,0,1,0);
    //Dibujando Planeta.
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texJupiter);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,rd5,60,60);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}

//Saturno y su Anillo.
void Saturno(){


    //Rotacion y traslacion para Saturno.
    glPushMatrix();
    glRotatef(rot6,0,1,0);
    glTranslatef(pos6,0,0);

    sprintf(text, "Saturno");
    glColor3f(1, 1, 1);
    glRasterPos3f( -3 , 22 , 0);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    
    //Rotacion en su eje.
    glRotatef(rotateEjeY,0,1,0);
    //Dibujando Planeta.
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texSaturno);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,rd6,60,60);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glPopMatrix();

}

void Anillos(){

//Rotacion y Traslacion para los Anillos.
    glPushMatrix();
    glRotatef(rot6,0,1,0);
    glTranslatef(pos6,0,0);
    glColor3f(0.75f,0.75f,0.75f);
    //Dibujando Planeta.
    glEnable(GL_LIGHTING);  
    glRotatef(-65,1,0,1);
    glutSolidTorus(3, 20, 10,50);
    glDisable(GL_LIGHTING);
    glPopMatrix();

}

//Urano.
void Urano(){

    //Rotacion y traslacion para Urano.
     glPushMatrix();
     glRotatef(rot7,0,1,0);
     glTranslatef(0,0,pos7);

     sprintf(text, "Urano");
     glColor3f(1, 1, 1);
     glRasterPos3f( -3 , 22 , 0);
     for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    //Rotacion en su eje.
    glRotatef(rotateEjeY,0,1,0);
    //Dibujando Planeta.
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texUrano);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,rd7,60,60);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}


//Neptuno.
void Neptuno(){

    //Rotacion y traslacion para Neptuno.
    glPushMatrix();
    glRotatef(rot8,0,1,0);
    glTranslatef(-pos8,0,0);

    sprintf(text, "Neptuno");
    glColor3f(1, 1, 1);
    glRasterPos3f( -3 , 22 , 0);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    //Rotacion en su eje.
    glRotatef(rotateEjeY,0,1,0);
    //Dibujando Planeta.
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texNeptuno);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,rd8,60,60);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}

//FIN DE LA CREACION DE LOS PLANETAS. -------------------


GLuint loadTex(const char* filename){
	   
    GLuint tex_ID = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,(SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT));
        glEnable( GL_TEXTURE_2D );
        glBindTexture( GL_TEXTURE_2D, tex_ID );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        return tex_ID;
}

void OpenGLInit(void){

    glShadeModel( GL_FLAT );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glClearDepth( 1.0 );
    glEnable( GL_DEPTH_TEST);
    pSphere = gluNewQuadric();
    gluQuadricDrawStyle(pSphere, GLU_FILL);
    gluQuadricNormals(pSphere, GLU_SMOOTH);
    gluQuadricTexture(pSphere, GLU_TRUE);
}


//Plano Carteciano.
void ejes(){

   	glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex3f(-200,0,0);
        glVertex3f(200,0,0);
        glVertex3f(0,-200,0);
        glVertex3f(0,200,0);
        glVertex3f(0,0,-200);
        glVertex3f(0,0,200);
    glEnd();
}


void estrellas(){

    int i,j,k; 
    srand (time(NULL)); 
    glBegin(GL_POINTS);
    glPointSize(0.1);
    

    for(int s=-100; s<100; s++){

        i=(rand()%300);
        j=(rand()%300);
        k=(rand()%300);

        glColor3f(1,1,1);
        glVertex3f( i, j, k);
        glVertex3f( i, j,-k);
        glVertex3f( i,-j, k);
        glVertex3f( i,-j,-k);
        glVertex3f(-i, j, k);
        glVertex3f(-i, j,-k);
        glVertex3f(-i,-j, k);
        glVertex3f(-i,-j,-k);
      
     }
    glEnd();
}

void Orbita(){

//Orbita para Mercurio.
    glPushMatrix();

    glRotatef(90,1.0,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POINTS);

    for (double i=0.0; i<10; i+=0.001){
       calx=(pos1+1)*cos(i)+0;
       caly=(pos1+1)*sin(i)+0;
       glVertex2f(calx,caly);
    }
    glEnd();

    glPopMatrix();

//Orbita para Venus.
    glPushMatrix();

    glRotatef(90,1.0,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POINTS);
    for (double i=0.0; i<10; i+=0.001){
       calx=(pos2+1)*cos(i)+0;
       caly=(pos2+1)*sin(i)+0;
       glVertex2f(calx,caly);
    }
    glEnd();

    glPopMatrix();

//Orbita para Tierra.
    glPushMatrix();

    glRotatef(90,1.0,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POINTS);
    for (double i=0.0; i<10; i+=0.001){
       calx=(pos3+1)*cos(i)+0;
       caly=(pos3+1)*sin(i)+0;
       glVertex2f(calx,caly);
    }
    glEnd();

    glPopMatrix();

//Orbita para Martes.
    glPushMatrix();

    glRotatef(90,1.0,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POINTS);
    for (double i=0.0; i<10; i+=0.001){
       calx=(pos4+1)*cos(i)+0;
       caly=(pos4+1)*sin(i)+0;
       glVertex2f(calx,caly);
    }
    glEnd();

    glPopMatrix();

//Orbita para Jupiter.
    glPushMatrix();

    glRotatef(90,1.0,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POINTS);
    for (double i=0.0; i<10; i+=0.001){
       calx=(pos5+1)*cos(i)+0;
       caly=(pos5+1)*sin(i)+0;
       glVertex2f(calx,caly);
    }
    glEnd();

    glPopMatrix();

//Orbita para Saturno.
    glPushMatrix();

    glRotatef(90,1.0,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POINTS);
    for (double i=0.0; i<10; i+=0.001){
       calx=(pos6+1)*cos(i)+0;
       caly=(pos6+1)*sin(i)+0;
       glVertex2f(calx,caly);
    }
    glEnd();

    glPopMatrix();

//Orbita para Urano.
    glPushMatrix();

    glRotatef(90,1.0,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POINTS);
    for (double i=0.0; i<10; i+=0.001){
       calx=(pos7+1)*cos(i)+0;
       caly=(pos7+1)*sin(i)+0;
       glVertex2f(calx,caly);
    }
    glEnd();

    glPopMatrix();

//Orbita para Neptuno.
    glPushMatrix();

    glRotatef(90,1.0,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POINTS);
    for (double i=0.0; i<10; i+=0.001){
       calx=(pos8+1)*cos(i)+0;
       caly=(pos8+1)*sin(i)+0;
       glVertex2f(calx,caly);
    }
    glEnd();

    glPopMatrix();

}

void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glLoadIdentity();
    
    GLfloat lightPosition[] = { 0.0, 0.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    startAnimation();

    Sistema_Solar();
  
    glutSwapBuffers();

}

void Sistema_Solar(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glLoadIdentity();

    //Rotacion de 45 grados en torno al Eje X.
    glRotated(45.0, 1.0, 0.0, 0.0);
    glRotatef( rotate_x, 1.0f, 0.0f, 0.0f );
    glRotatef( rotate_y, 0.0f, 1.0f, 0.0f );
    glScalef(scale, scale, scale);

    //ejes();
    estrellas();

    if(countorb==0){
    Orbita();
    }

    Sol();
    Mercurio();
    Venus();
    Tierra();
    Luna();
    Marte();
    Jupiter();
    Saturno();
    Anillos();
    Urano();
    Neptuno();
      
    rotL=rot3*1;
    rot1=rot3*4.3;
    rot2=rot3*1.63;
    rot3=rot3+0.1;
    rot4=rot3/1.88;
    rot5=rot3/11.9;
    rot6=rot3/29;
    rot7=rot3/84;
    rot8=rot3/165;
    rotateEjeY=rotateEjeY+2;

    glutSwapBuffers();
}

void Sol_Info(){

	pauseAnimation();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();    
    estrellas();
     
    glTranslatef(-160.0f, 0.0f, 0.0f);
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texSun);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,100, 60, 60);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

	glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f( 250 , 250 , 0);
    sprintf(text, "El Sol.");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 230 , 0);
    sprintf(text, "El sol es la estrella situada en el centro de nuestro Sistema Solar.");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 210 , 0);
    sprintf(text, "Su masa representa el 96.8 de la masa total del sistema.");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 180 , 0);
    sprintf(text, "Aproximadamente tres cuartos de su masa estan compuestos de"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 160 , 0);
    sprintf(text, "Hidrogeno, siendo el resto de Helio en su mayor parte. Solo un"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 140 , 0);
    sprintf(text, "1.69 esta formado por elementos mas pesados como Carbono,"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 120 , 0);
    sprintf(text, "Hierro, Neon y Oxigeno"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 90 , 0);
    sprintf(text, "La distancia media entre el Sol y la Tierra es de 146.6 millones"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 70 , 0);
    sprintf(text, "de Kilometros. Su luz tarda en llegar a nuestro planeta unos 8"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 50 , 0);
    sprintf(text, "minutos y 19 segundos."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 20 , 0);
    sprintf(text, "En comparacion con la tierra: "); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 0 , 0);
    sprintf(text, "Diametro Ecuatorial: 109 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -20 , 0);
    sprintf(text, "Gravedad en superficie: 28xTierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -40 , 0);
    sprintf(text, "Temperatura en superficie: 5 505 C."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -60 , 0);
    sprintf(text, "Periodo de rotacion: 23 dias."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -80 , 0);
    sprintf(text, "Periodo de orbitacion galactico: 23 M anos."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -100 , 0);
    sprintf(text, "Distancia media al planeta: 30 900 000 M km."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    
    glRasterPos3f( 120 , -130 , 0);
    sprintf(text, "Anta\244o se creia que el Sol era una estrella relativamente"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -150 , 0);
    sprintf(text, "insignificante pero hoy en dia sabemos que su brillo es superior"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -170 , 0);
    sprintf(text, "al 85 de las estrellas de la Via Lactea. Se encuentra dos veces"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -190 , 0);
    sprintf(text, "mas lejos que el centro de la galaxia que del borde exterior,"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    
    glRasterPos3f( 120 , -210 , 0);
    sprintf(text, "es decir que esta situado a unos dos tercios del radio galactico "); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -230 , 0);
    sprintf(text, "partiendo desde el centro de la Via Lactea."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glutSwapBuffers();
}

void Mercurio_Info(){

    estrellas();
     
    glTranslatef(-160.0f, 0.0f, 0.0f);
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texMercurio);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,100, 60, 60);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
 
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f( 250 , 250 , 0);
    sprintf(text, "Mercurio.");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 230 , 0);
    sprintf(text, "Mercurio es de entre todos los planetas del Sistema Solar, el");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 210 , 0);
    sprintf(text, "mas proximo y a la vez el mas pequeno. La falta de una atmosfera");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 190 , 0);
    sprintf(text, "significativa que retenga calor, hace que su superficie experimente"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 170 , 0);
    sprintf(text, "la mayor variacion de temperatura entre todos los planetas."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 130 , 0);
    sprintf(text, "Mercurio suele aparecer como una estrella de la manana o una"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 110 , 0);
    sprintf(text, "estrella vespertina al Sol es muy dificil de ver la causa de su"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 90 , 0);
    sprintf(text, "su resplandor. Aun asi, Mercurio puede observarse al menos dos"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 70 , 0);
    sprintf(text, "veces a lo largo del ano: al anochecer en primavera y antes"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 50 , 0);
    sprintf(text, "del amanecer del otono."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    
    glRasterPos3f( 120 , 20 , 0);
    sprintf(text, "En comparacion con la tierra: "); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 0 , 0);
    sprintf(text, "Diametro Ecuatorial: 0.38 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -20 , 0);
    sprintf(text, "Gravedad en superficie: 0.38 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -40 , 0);
    sprintf(text, "Temperatura en superficie: Dia: 437 C, Noche: -138 C."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -60 , 0);
    sprintf(text, "Periodo de rotacion: 59 x mas lento."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -80 , 0);
    sprintf(text, "Periodo de orbita al rededor del Sol: 4.2 x mas rapido."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -100 , 0);
    sprintf(text, "Distancia media al Sol: 0.39 x Tirra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void Venus_Info(){

    estrellas();
     
    glTranslatef(-160.0f, 0.0f, 0.0f);
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texVenus);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,100, 60, 60);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos3f( 250 , 250 , 0);
    sprintf(text, "Venus.");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 230 , 0);
    sprintf(text, "Pase a que el tamano y a la estructura interna de Venus son");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 210 , 0);
    sprintf(text, "similares a los de la Tierra, su superficie volcanica y su");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 190 , 0);
    sprintf(text, "atmosfera extremadamente caliente y densa, hacen de este planeta"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 170 , 0);
    sprintf(text, "uno de los más inhospitos de todo el Sistema Solar."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 130 , 0);
    sprintf(text, "Las espesas nubes de acido sulfurico reflejan al espacio la"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 110 , 0);
    sprintf(text, "la mayor parte de luz proveniente del Sol mientras que el"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 90 , 0);
    sprintf(text, "dioxido de carbono conserva el calor dentro de la atmosfera"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 70 , 0);
    sprintf(text, "provocando un devastador efecto invernadero. La presion atmosforica"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 50 , 0);
    sprintf(text, "en la superficie de Venus es 92 veces superior a la de la Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    
    glRasterPos3f( 120 , 30 , 0);
    sprintf(text, "Venus es uno de los objetos mas brillantes del cielo nocturno."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 10 , 0);
    sprintf(text, "superado solo por la Luna. Llegando incluso a proyectar sombras."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -10 , 0);
    sprintf(text, "Suele aparecer como una estrella vespertina o estrella de la manana."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -40 , 0);
    sprintf(text, "En comparacion con la Tierra: "); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -60 , 0);
    sprintf(text, "Diametro Ecuatorial: 0.95 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -80 , 0);
    sprintf(text, "Gravedad en la superficie: 0.9 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -100 , 0);
    sprintf(text, "Temperatura en superficie: 462 C."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -120 , 0);
    sprintf(text, "Periodo de rotacion: 0.004 x mas rapido."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -140 , 0);
    sprintf(text, "Periodo de orbita alrededor del Sol: 1.63 x mas rapido."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -160 , 0);
    sprintf(text, "Distancia media al Sol: 0.72 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void Tierra_Info(){

    estrellas();
     
    glTranslatef(-160.0f, 0.0f, 0.0f);
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texTierra);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,100, 60, 60);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f( 250 , 250 , 0);
    sprintf(text, "Tierra.");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 230 , 0);
    sprintf(text, "Nuestro planeta natal es el mas denso de los ocho planetas");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 210 , 0);
    sprintf(text, "del Sistema Solar. Es tambien el mas grande de los cuatro");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 190 , 0);
    sprintf(text, "planetas teluricos. Al rededor del 70 de la superficie"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 170 , 0);
    sprintf(text, "de la Tierra esta cubierta por oceanos de agua salada y el 30"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 150 , 0);
    sprintf(text, "restante esta ocupado por los 7 continentes. La superficie exterior"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 130 , 0);
    sprintf(text, "placas tectonicas, que se deslizan atraves de la superficie en"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 110 , 0);
    sprintf(text, "periodos que abarcan millones de anos."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 70 , 0);
    sprintf(text, "Al dia de hoy, el eje de la Tierra esta inclinado sobre el plano"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 50 , 0);
    sprintf(text, "de la ecliptica 23.4, siendo esto la causa de las distintas estaciones."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    
    glRasterPos3f( 120 , 30 , 0);
    sprintf(text, "que se manifiestan en todo el planeta a lo largo de un ano."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 0 , 0);
    sprintf(text, "En comparación con el Sol:"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -20 , 0);
    sprintf(text, "Diametro Ecuatorial: 0.009 x Sol."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -40 , 0);
    sprintf(text, "Gravedad en la superficie: 0.04 x Sol."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -60 , 0);
    sprintf(text, "Temperatura en superficie: 15 C"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -80 , 0);
    sprintf(text, "Periodo de rotacion: 23.56m."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -100 , 0);
    sprintf(text, "Periodo de orbita alrededor del Sol: 1 ano."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -120 , 0);
    sprintf(text, "Distancia media al Sol: 150 M km."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -150 , 0);
    sprintf(text, "El campo magnetico de la Tierra se genera en el interior de la region"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -170 , 0);
    sprintf(text, "formada por el nucleo extremo fundido y se extiende hacia el exterior"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -190 , 0);
    sprintf(text, "formando la magnetosdera: barrera que rodea el planeta y lo preotege"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -210 , 0);
    sprintf(text, "de la radiacion del Sol asi como de las particulas del viento solar."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void Marte_Info(){

    estrellas();
     
    glTranslatef(-160.0f, 0.0f, 0.0f);
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texMarte);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,100, 60, 60);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f( 250 , 250 , 0);
    sprintf(text, "Marte.");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 230 , 0);
    sprintf(text, "A continuacion de la Tierra encontramos a Marte, el segundo");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 210 , 0);
    sprintf(text, "planeta mas pequeno del Sistema Solar. Su apariencia rojiza");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 190 , 0);
    sprintf(text, "es causada por la abundancia del Oxido del Hierro (Oxidacion)."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 170 , 0);
    sprintf(text, "Aunque Marte tenga la mitad del tamano de la Tierra existen"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 150 , 0);
    sprintf(text, "varias similitudes entre estos dos planetas: Martes tiene una"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 130 , 0);
    sprintf(text, "superficie rocosa y hielo en los casquetes polares, los dias"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 110 , 0);
    sprintf(text, "en el planeta rojo son solo unos 40 minutos más largos que en"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 90 , 0);
    sprintf(text, "la tierra y la inclinacion de su eje hace que se produzcan"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 70 , 0);
    sprintf(text, "estaciones similares a la nuestra (Aunque duran el doble de tiempo)."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    
    glRasterPos3f( 120 , 40 , 0);
    sprintf(text, "Marte posee uno de los paisajes espectaculares, imponentes"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 20 , 0);
    sprintf(text, "volcanes y un gran sistema de canones. De todos los planetas del,"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 0 , 0);
    sprintf(text, "Sistema Solar Marte tienen la montana mas alta, el Monte Olimpo,"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -20 , 0);
    sprintf(text, "y el canón mas largo, el Valles Marineris."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -50 , 0);
    sprintf(text, "En comparacion con la Tierra:"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -70 , 0);
    sprintf(text, "Diametro Ecuatorial: 0.53 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -90 , 0);
    sprintf(text, "Gravedad en la superficie: 0.38 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -110 , 0);
    sprintf(text, "Temperatura:  Verano: 17 C,  Invierno: -140 C."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -130 , 0);
    sprintf(text, "Periodo de rotacion:  1.03 x mas lento."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -150 , 0);
    sprintf(text, "Periodo de orbita alrededor del Sol: 1.88 x mas rapido."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -170 , 0);
    sprintf(text, "Distancia media al Sol: 1.52 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void Jupiter_Info(){

    estrellas();
     
    glTranslatef(-160.0f, 0.0f, 0.0f);
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texJupiter);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,100, 60, 60);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f( 250 , 250 , 0);
    sprintf(text, "Jupiter.");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 230 , 0);
    sprintf(text, "Jupiter es el planeta más grande del Sistema Solar con una");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 210 , 0);
    sprintf(text, "masa 2.5 veces mayor que el resto de los otros planetas juntos");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 190 , 0);
    sprintf(text, "y aun asi unas mil veces mas pequena que la masa del Sol."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 160 , 0);
    sprintf(text, "Jupiter rota sobre su eje mas rapido que cualquiera de los otros"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 140 , 0);
    sprintf(text, "planetas. Debido a esta gran velocidad de rotacion, su atmosfera"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 120 , 0);
    sprintf(text, "esta sometida a fuertes vientos que provocan la formacion de"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 100 , 0);
    sprintf(text, "distintas bandas de calor, grandes remolinos y poderosas tormentas."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 70 , 0);
    sprintf(text, "En comparacion con la Tierra: "); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 50 , 0);
    sprintf(text, "Diametro Ecuatorial: 11.2 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    
    glRasterPos3f( 120 , 30 , 0);
    sprintf(text, "Gravedad en la superficie: 2.5 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 10 , 0);
    sprintf(text, "Temperatura  en la superficie:  -120 C."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -10 , 0);
    sprintf(text, "Periodo de rotacion: 2.4 x mas rapido."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -30 , 0);
    sprintf(text, "Periodo de orbita alrededor del Sol: 11.9 x mas lento."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -50 , 0);
    sprintf(text, "Distancia media al Sol: 5.2 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void Saturno_Info(){

    estrellas();
    
    glTranslatef(-160.0f, 0.0f, 0.0f);
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texSaturno);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,80, 60, 60);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(-65,1,0,0);
    glColor3f(0.75,0.75,0.75);
    glutSolidTorus(10, 100, 10,50);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f( 250 , 250 , 0);
    sprintf(text, "Saturno.");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 230 , 0);
    sprintf(text, "Saturno es el sexto planeta del Sistema Solar y el segundo");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 210 , 0);
    sprintf(text, "de mayor tamano. Hasta la invención del telescopio moderno,");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 190 , 0);
    sprintf(text, "se creia que Saturno era el ultimo de los planetas."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 160 , 0);
    sprintf(text, "Pese a ser el segundo planeta mas grande, Saturno es el menos"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 140 , 0);
    sprintf(text, "denso de todo el Sistema Solar con solo un octavo de la densidad"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 120 , 0);
    sprintf(text, "a la del agua, si lo soltaramos dentro del mar flotaria."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 90 , 0);
    sprintf(text, "Los otros gigantes gaseosos tambien poseen sistemas de anillos"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 70 , 0);
    sprintf(text, "pero los anillos de Saturno son los mayores y mas visibles del"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 50 , 0);
    sprintf(text, "Sistema Solar. Estos anillos estan formados por cristales de hielo"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    
    glRasterPos3f( 120 , 30 , 0);
    sprintf(text, "y trozos de rocas cuyo tamano puede varias desde simples motas de"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 10 , 0);
    sprintf(text, "polvo a algunos metros."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -20 , 0);
    sprintf(text, "En comparacion con la Tierra: "); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -40 , 0);
    sprintf(text, "Diametro Ecuatorial: 9.5 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -60 , 0);
    sprintf(text, "Gravedad en la superficie: 1.06 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -80 , 0);
    sprintf(text, "Temperatura en la superficie: -125 C."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -100 , 0);
    sprintf(text, "Periodo de rotación: 2.2x mas rápido."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -120 , 0);
    sprintf(text, "Periodo de orbita alrededor del Sol: 29 x mas lento."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -140 , 0);
    sprintf(text, "Distancia media al Sol: 9.5 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void Urano_Info(){

    estrellas();
     
    glTranslatef(-160.0f, 0.0f, 0.0f);
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texUrano);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,100, 60, 60);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f( 250 , 250 , 0);
    sprintf(text, "Urano.");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 230 , 0);
    sprintf(text, "Urano es el séptimo planeta del Sistema Solar y el tercero");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 210 , 0);
    sprintf(text, "de tamano de los cuatro gigantes gaseosos. Es tambien el mas");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 190 , 0);
    sprintf(text, "gelido de todo el Sistema Solar. Fue el primer planeta"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 170 , 0);
    sprintf(text, "descubierto gracias al uso del telescopio moderno, por el"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 150 , 0);
    sprintf(text, "astronomo ingles William Herschel en 1781."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 120 , 0);
    sprintf(text, "Urano tiene una oblicuidad de 97.77, lo que significa que"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 100 , 0);
    sprintf(text, "gira alrededor del sol completamente “Tumbado” en relación a los"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 80 , 0);
    sprintf(text, "otros planetas del Sistema Solar. Mientras esta en oposicion, Urano"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 60 , 0);
    sprintf(text, "se puede observar a simple vista. Puede parecer una estrella debil"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    
    glRasterPos3f( 120 , 40 , 0);
    sprintf(text, "en condiciones de cielo oscuro."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 10 , 0);
    sprintf(text, "En comparacion con la Tierra: "); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -10 , 0);
    sprintf(text, "Diametro Ecuatorial: 4.1 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -30 , 0);
    sprintf(text, "Gravedad en la superficie: 0.89 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -50 , 0);
    sprintf(text, "Temperatura en la superficie: -210 C."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -70 , 0);
    sprintf(text, "Periodo de rotacion: 1.39 x mas rapido."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -90 , 0);
    sprintf(text, "Periodo de orbita alrededor del Sol: 84 x mas lento."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -110 , 0);
    sprintf(text, "Distancia media al Sol: 19.2 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void Neptuno_Info(){
    estrellas();
     
    glTranslatef(-160.0f, 0.0f, 0.0f);
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texNeptuno);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluSphere(pSphere,100, 60, 60);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f( 250 , 250 , 0);
    sprintf(text, "Neptuno.");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 230 , 0);
    sprintf(text, "Neptuno es el octavo planeta y oficialmente, el mas alejado");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 210 , 0);
    sprintf(text, "el sol. Es el mas pequeno pero tambien el mas denso de los");
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 190 , 0);
    sprintf(text, "gigantes gaseosos. Su gravedad en la superficie es solo superada"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 170 , 0);
    sprintf(text, "por Jupiter. Neptuno fue el primer planeta en ser descubierto"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 150 , 0);
    sprintf(text, "unicamente por tacticas de predicción matematica en vez de observacion"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  

    glRasterPos3f( 120 , 130 , 0);
    sprintf(text, "directa. Desde su descubrimiento en 1846, Neptuno ha completado"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 110 , 0);
    sprintf(text, "solo una orbita alrededor del Sol."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 80 , 0);
    sprintf(text, "En comparacion con la Tierra: "); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 60 , 0);
    sprintf(text, "Diametro Ecuatorial: 3.9 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    
    glRasterPos3f( 120 , 40 , 0);
    sprintf(text, "Gravedad en la superficie: 1.14 x Tierra."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 20 , 0);
    sprintf(text, "Temperatura en la superficie: -200 C."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , 0 , 0);
    sprintf(text, "Periodo de rotacion: 1.49 x mas rapido."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -20 , 0);
    sprintf(text, "Periodo de orbita alrededor del Sol: 165 x mas lento."); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glRasterPos3f( 120 , -40 , 0);
    sprintf(text, "Distancia media al Sol: 30 x Tierra:"); 
    for(int i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void menu (int opc)
{

  vf[1]=opc; // En el vector VF, en su campo 1, se almacenara el id de la imagen
  glPushMatrix();

  switch (opc)
    {
    case 1:
    
    Sol_Info();

    break;

    case 2:
    
    pauseAnimation();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    Mercurio_Info();
    
    glutSwapBuffers();

    break;
    
    case 3:

    pauseAnimation();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    Venus_Info();
    
    glutSwapBuffers();
 
    break;

    case 4:

    pauseAnimation();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    Tierra_Info();
    
    glutSwapBuffers();
 
    break;

    case 5:

    pauseAnimation();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    Marte_Info();
    
    glutSwapBuffers();
 
    break;

    case 6:

    pauseAnimation();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    Jupiter_Info();
    
    glutSwapBuffers();
 
    break;

    case 7:

    pauseAnimation();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    Saturno_Info();
    
    glutSwapBuffers();
 
    break;

    case 8:

    pauseAnimation(); 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    Urano_Info();
    
    glutSwapBuffers();

    break;

    case 9:

    pauseAnimation();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    Neptuno_Info();
    
    glutSwapBuffers();
 
    break;

    case 10:
      exit(0);

    }
}

void initTex(){
    texSun = loadTex("Texturas/Sol.jpg");  
    texMercurio = loadTex("Texturas/Mercurio.jpg");
    texVenus = loadTex("Texturas/Venus.jpg");
    texTierra = loadTex("Texturas/Tierra.jpg");
    texMarte = loadTex("Texturas/Marte.jpg");
    texJupiter = loadTex("Texturas/Jupiter.jpg");
    texSaturno = loadTex("Texturas/Saturno.jpg");
    texUrano = loadTex("Texturas/Urano.jpg");
    texNeptuno = loadTex("Texturas/Neptuno.jpg");
    texLuna = loadTex("Texturas/Luna.jpg");
}

void reshape(int width, int height){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);//Matriz de proyeccion.
    glLoadIdentity();//Cargamos la matriz identidad.
    glOrtho(-300,300,-300,300,-300,300);
    glMatrixMode(GL_MODELVIEW);//Matriz de modelado.
    glLoadIdentity();//Matriz identidad.
    glEnable(GL_DEPTH_TEST);//Activamos el Test de profundidad.
    glDepthFunc(GL_LEQUAL);//Funcion de borrrado buffer depth.
}

// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{
    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;

    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;

    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)

     if(rotate_x >=45){
            rotate_x = 45;
        }
        else{
            rotate_x +=5;
        }
            
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)

        rotate_x -=5;

        if(rotate_x <=-135){
            rotate_x = -135;
        }
    //Solicitar actualización de visualización.
    glutPostRedisplay();
}

// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.

    switch (key)
    {
    case 'q':

        if(scale >=3){
            scale = 3;
        }
        else{
            scale +=0.02;
        }

    break;

    case 'w':

        scale -=0.02;

        if(scale <=1.0){
            scale = 1.0;
        }

    break;

    case '1':
         
         rot3+=25;

    break;

    case '2':
         
         rot3-=25;

    break;

    case '3':

     if(count == 0){ 
        pos3+=10;
        pos4+=15;
        pos5+=25;
        pos6+=55;
        pos7+=80;
        pos8+=100;
        posl+=10;

        count=1;
    }else{
        pos3+=0;
        pos4+=0;
        pos5+=0;
        pos6+=0;
        pos7+=0;
        pos8+=0;
        posl+=0;
    }

    break;

    case '4':
    
    if(count == 1){
        pos3-=10;
        pos4-=15;
        pos5-=25;
        pos6-=55;
        pos7-=80;
        pos8-=100;
        posl-=10;

        count=0;
    }else{
    	pos3+=0;
        pos4+=0;
        pos5+=0;
        pos6+=0;
        pos7+=0;
        pos8+=0;
        posl+=0;
    }

    break;

    case '5':
    	countorb=1;
    break;

    case '6':
    	if(countorb==1){
    		countorb=0;
    	}
    break;

    case 27:
        exit(0);
    }
    //Solicitar actualización de visualización
    glutPostRedisplay();
}

void pauseAnimation() {
       // Llamamo a la función para detener la animación 
    animating = 0;
}

void timerFunction(int timerID) {
      // Invocamos la funcion para controlar el tiempo de la ejecucion de funciones 
    if (animating) {
        //updateFrame();
        glutTimerFunc(30, timerFunction, 0);
        glutPostRedisplay();
    }
}

void startAnimation() {
      // llamamos la función para iniciar la animación 
   if ( ! animating ) {
       animating = 1;
       glutTimerFunc(30, timerFunction, 1);
   }
}

void init (void){

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	
	// set up lighting
	glEnable(GL_LIGHTING);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GLfloat matSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat matAmbience[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat matShininess[] = { 20.0 };
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbience);

	GLfloat lightAmbient[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat lightDiffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
}

int main(int argc, char* argv[]){

    glutInit(&argc, argv);//Inicializacion del glut.
    glutInitWindowSize(1000,800);//Tamaño de la ventana.
    glutInitWindowPosition(180,0);//Posicion de la ventana en el monitor.
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);//Modo de visualizacion inicial.
    glutCreateWindow("SISTEMA SOLAR");//Nombre de la ventana.
    OpenGLInit();
    init();
    initTex();
    glClearColor(0,0,0,0);//Especificar valores claros para el color del buffer.
    glutDisplayFunc(display);//Establece la devolución de llamada de visualización de la ventana actual.
    glutReshapeFunc(reshape);//Control de ventanas.

    glutCreateMenu(menu);
    glutAddMenuEntry("Sol",1);
    glutAddMenuEntry("Mercurio",2);
    glutAddMenuEntry("Venus",3);
    glutAddMenuEntry("Tierra",4);
    glutAddMenuEntry("Marte",5);
    glutAddMenuEntry("Jupiter",6);
    glutAddMenuEntry("Saturno",7);
    glutAddMenuEntry("Urano",8);
    glutAddMenuEntry("Neptuno",9);
    glutAddMenuEntry("Salir",10);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutKeyboardFunc(keyboard);//Funcion para teclas normales.
    glutSpecialFunc(specialKeys);//Funcion para teclas especiales.
    //glutMouseFunc(mouse);
    //glutMouseWheelFunc(MouseWheel);
    //glutFullScreen();//Funcion para mostrar pantalla completa.
    startAnimation();//Funcion de animacion.
    glutMainLoop();//Bucle de procesamiento de eventos de GLUT.
    return 0;
}
