//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdlib.h>
#include <stdio.h>
#pragma hdrstop
#include "U10616001.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLCtrl"
#pragma resource "*.dfm"
TForm1 *Form1;
double Rx,Ry,Rz,Tx,Ty,Tz,Sx,Sy,Sz,Ix,Iy,Iz,Nx,Ny,Nz;
double L = 1.0;
bool BlueLight=true; bool RedLight=true; bool GreenLight=true; int material=3; int shading = 2; int view=0; bool NOTFREE = true; int type = 1;
int count = 0; int *front; int *back;
float *vx; float *vy; float *vz;
float *nx; float *ny; float *nz;
GLfloat global_ambient[] = {0.2,0.2,0.2,1.0};
GLfloat bronzea[]={0.212500, 0.127500, 0.054000, 1.000000};
GLfloat bronzed[]={0.714000, 0.428400, 0.181440, 1.000000};
GLfloat bronzes[]={0.393548, 0.271906, 0.166721, 1.000000};
GLfloat golda[]={0.247250, 0.199500, 0.074500, 1.000000};
GLfloat goldd[]={0.751640, 0.606480, 0.226480, 1.000000};
GLfloat golds[]={0.628281, 0.555802, 0.366065, 1.000000};
GLfloat pewtera[]={0.105882, 0.058824, 0.113725, 1.000000};
GLfloat pewterd[]={0.427451, 0.470588, 0.541176, 1.000000};
GLfloat pewters[]={0.333333, 0.333333, 0.521569, 1.000000};
GLfloat da[]={0.2,0.2,0.2,1.0};
GLfloat dd[]={0.8,0.8,0.8,1.0};
GLfloat ds[]={0.0,0.0,0.0,1.0};
GLfloat emission[]={0.0,0.0,0.0,1.0};
GLfloat vertices[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
        {1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},
	{1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0}};
GLfloat normals[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
        {1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},
        {1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}};
GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},
	{1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},
	{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};
GLfloat pn[][3] = {{0.0,0.0,-0.1},{0.0,1.0,0.0},{-1.0,0.0,0.0},
        {1.0,0.0,0.0},{0.0,0.0,1.0},{0.0,-1.0,0.0}};

void polygon(int type, int a, int b, int c , int d){
        if (type == 1){
                glBegin(GL_POLYGON);
		glColor3fv(colors[a]);
                glNormal3fv(normals[a]);
		glVertex3fv(vertices[a]);
		glColor3fv(colors[b]);
                glNormal3fv(normals[b]);
		glVertex3fv(vertices[b]);
		glColor3fv(colors[c]);
                glNormal3fv(normals[c]);
		glVertex3fv(vertices[c]);
		glColor3fv(colors[d]);
                glNormal3fv(normals[d]);
		glVertex3fv(vertices[d]); 
                glEnd();
        }/*else if(type==0){
                int t = 0;
                glBegin(GL_TRIANGLES);
                while(t<count){
                        glColor3ub(front[t*3],front[t*3+1],front[t*3+2]);
                        glNormal3f(ny[t*3+2],nz[t*3+2],nx[t*3+2]);
                        glVertex3f(vy[t*3+2],vz[t*3+2],vx[t*3+2]);
                        glNormal3f(ny[t*3+1],nz[t*3+1],nx[t*3+1]);
                        glVertex3f(vy[t*3+1],vz[t*3+1],vx[t*3+1]);
                        glNormal3f(ny[t*3],nz[t*3],nx[t*3]);
                        glVertex3f(vy[t*3],vz[t*3],vx[t*3]);
                        t++;
                }
                glEnd();
        }*/else{
                glBegin(GL_POLYGON);
                glColor3fv(colors[a]);
                glNormal3fv(normals[a]);
		glVertex3fv(vertices[a]);
                glVertex3fv(vertices[b]);
                glVertex3fv(vertices[c]);
                glVertex3fv(vertices[d]);
                glEnd();
        }

}
/* map vertices to faces */
void colorcube(){
	polygon(1,0,3,2,1);
	polygon(1,2,3,7,6);
	polygon(1,0,4,7,3);
	polygon(1,1,2,6,5);
	polygon(1,4,5,6,7);
	polygon(1,0,1,5,4);
}
void flatcube(){
        polygon(2,1,0,3,2);
	polygon(2,2,3,7,6);
	polygon(2,0,4,7,3);
	polygon(2,1,2,6,5);
	polygon(2,4,5,6,7);
	polygon(2,0,1,5,4);
}

void input(){
        int t = 0;
        glBegin(GL_TRIANGLES);
                while(t<count){
                        glColor3ub(front[t*3],front[t*3+1],front[t*3+2]);
                        glNormal3f(ny[t*3+2],nz[t*3+2],nx[t*3+2]);
                        glVertex3f(vy[t*3+2],vz[t*3+2],vx[t*3+2]);
                        glNormal3f(ny[t*3+1],nz[t*3+1],nx[t*3+1]);
                        glVertex3f(vy[t*3+1],vz[t*3+1],vx[t*3+1]);
                        glNormal3f(ny[t*3],nz[t*3],nx[t*3]);
                        glVertex3f(vy[t*3],vz[t*3],vx[t*3]);
                        t++;
                }
                glEnd();
}

void drawline(){
        glBegin(GL_LINES);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(L*20.0,0.0,0.0);

        glColor3f(0.0,1.0,0.0);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(0.0,L*20.0,0.0);

        glColor3f(0.0,0.0,1.0);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(0.0,0.0,L*20.0);

        glEnd();
}
void drawline2(){
        glBegin(GL_LINES);
        glColor3f(0.7,0.0,0.0);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(L*3.0,0.0,0.0);

        glColor3f(0.0,0.7,0.0);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(0.0,L*3.0,0.0);

        glColor3f(0.0,0.0,0.7);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(0.0,0.0,L*3.0);

        glEnd();
}
void light(){
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
        GLfloat light0_ambient[] = {0.7,0.0,0.0,0.0};
        GLfloat light0_diffuse[] = {1.0,1.0,1.0,0.0};
        GLfloat light0_specular[] = {1.0,1.0,1.0,0.0};
        GLfloat light0_position[] = {0.2,0.0,0.0,1.0};
        glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
        glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
        if(RedLight == true){
                glEnable(GL_LIGHT0);
        }else{
                glDisable(GL_LIGHT0);
        }

        GLfloat light1_ambient[] = {0.0,0.7,0.0,0.0};
        GLfloat light1_diffuse[] = {1.0,1.0,1.0,0.0};
        GLfloat light1_specular[] = {1.0,1.0,1.0,0.0};
        GLfloat light1_position[] = {0.0,0.2,0.0,1.0};
        glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
        glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
        if(GreenLight == true){
                glEnable(GL_LIGHT1);
        }else{
                glDisable(GL_LIGHT1);
        }

        GLfloat light2_ambient[] = {0.0,0.0,0.7,0.0};
        GLfloat light2_diffuse[] = {1.0,1.0,1.0,0.0};
        GLfloat light2_specular[] = {1.0,1.0,1.0,0.0};
        GLfloat light2_position[] = {0.0,0.0,0.2,1.0};
        glLightfv(GL_LIGHT2, GL_AMBIENT, light2_ambient);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
        glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular);
        glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
        if(BlueLight == true){
                glEnable(GL_LIGHT2);
        }else{
                glDisable(GL_LIGHT2);
        }
}

void materials(){
        if(material==0){
                glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,emission);
                glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,27.8974);
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,bronzea);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bronzed);
                glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,bronzes);
        }else if(material==1){
                glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,emission);
                glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,51.2);
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,golda);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,goldd);
                glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,golds);
        }else if(material==2){
                glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,emission);
                glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,9.84615);
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,pewtera);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,pewterd);
                glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,pewters);
        }else if(material==3){
                glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,emission);
                glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,0.0);
                glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,ds);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,dd);
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,da);
        }
}

void shadings(){
       if (shading==0){
                glPolygonMode(GL_FRONT ,GL_LINE);
                //glDisable(GL_LIGHTING);
                //glDisable(GL_COLOR_MATERIAL);
                glShadeModel(GL_FLAT);
                glLineWidth(1.0f);
       }else if(shading==1){
                glPolygonMode(GL_FRONT, GL_FILL);
                glPolygonMode(GL_BACK, GL_LINE);
                glEnable(GL_LIGHTING);
                glEnable(GL_COLOR_MATERIAL);
                glShadeModel(GL_FLAT);
       }else if(shading==2){
                glPolygonMode(GL_FRONT, GL_FILL);
                glPolygonMode(GL_BACK, GL_FILL);
                glEnable(GL_LIGHTING);
                glEnable(GL_COLOR_MATERIAL);
                glShadeModel(GL_SMOOTH);
       }
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::init(TObject *Sender)
{
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_NORMALIZE);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glEnable(GL_LIGHT2);
        glClearColor(0.3 ,0.3 ,0.3 ,0.0);
        Rx=Ry=Rz=0;
        Tx=Ty=Tz=0;
        Sx=Sy=Sz=100;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Draw(TObject *Sender)
{
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if (type==0){
                glOrtho(-5.0*L,5.0*L,-5.0*L,5.0*L,-5.0*L,5.0*L);
        }else{
                glOrtho(-5.0,5.0,-5.0,5.0,-5.0,5.0);
        }
        glMatrixMode(GL_MODELVIEW);

        if(view==0){
                glLoadIdentity();
                glViewport(0,0,GLBox1->Width,GLBox1->Height);
                gluLookAt(0,0,1,0,0,0,0,1,0);
                light();
                materials();
                shadings();
                glRotatef(35.26,1.0,0.0,0.0);
                glRotatef(-45,0.0,1.0,0.0);
                glRotatef(Ix,1.0,0.0,0.0);
                glRotatef(Iy,0.0,1.0,0.0);
                glRotatef(Iz,0.0,0.0,1.0);
                drawline();
                glTranslatef(L*Tx/10,L*Ty/10,L*Tz/10);
                glRotatef(Rx,1.0,0.0,0.0);
                glRotatef(Ry,0.0,1.0,0.0);
                glRotatef(Rz,0.0,0.0,1.0);
                glScalef (Sx/100, Sy/100, Sz/100);
                drawline2();
                if (type == 0){
                        input();
                }else if (type == 1){
                        colorcube();
                }else if (type == 2){
                        flatcube();
                }
        }else if(view==1){
                glLoadIdentity();
                glViewport(0,0,GLBox1->Width/2, GLBox1->Height/2);
                gluLookAt(0,0,1,0,0,0,0,1,0);
                light();
                materials();
                shadings();
                glRotatef(35.26,1.0,0.0,0.0);
                glRotatef(-45,0.0,1.0,0.0);
                glRotatef(Ix,1.0,0.0,0.0);
                glRotatef(Iy,0.0,1.0,0.0);
                glRotatef(Iz,0.0,0.0,1.0);
                drawline();
                glTranslatef(L*Tx/10,L*Ty/10,L*Tz/10);
                glRotatef(Rx,1.0,0.0,0.0);
                glRotatef(Ry,0.0,1.0,0.0);
                glRotatef(Rz,0.0,0.0,1.0);
                glScalef (Sx/100, Sy/100, Sz/100);
                if (type == 0){
                        input();
                }else if (type == 1){
                        colorcube();
                }else if (type == 2){
                        flatcube();
                }

                glLoadIdentity();
                glViewport(0,GLBox1->Height/2,GLBox1->Width/2, GLBox1->Height/2);
                gluLookAt(0,1,0,0,0,0,0,0,-1);
                light();
                materials();
                shadings();
                glRotatef(35.26,1.0,0.0,0.0);
                glRotatef(-45,0.0,1.0,0.0);
                glRotatef(Ix,1.0,0.0,0.0);
                glRotatef(Iy,0.0,1.0,0.0);
                glRotatef(Iz,0.0,0.0,1.0);
                drawline();
                glTranslatef(L*Tx/10,L*Ty/10,L*Tz/10);
                glRotatef(Rx,1.0,0.0,0.0);
                glRotatef(Ry,0.0,1.0,0.0);
                glRotatef(Rz,0.0,0.0,1.0);
                glScalef (Sx/100, Sy/100, Sz/100);
                if (type == 0){
                        input();
                }else if (type == 1){
                        colorcube();
                }else if (type == 2){
                        flatcube();
                }

                glLoadIdentity();
                glViewport(GLBox1->Width/2,0,GLBox1->Width/2, GLBox1->Height/2);
                gluLookAt(1,0,0,0,0,0,0,1,0);
                light();
                materials();
                shadings();
                glRotatef(35.26,1.0,0.0,0.0);
                glRotatef(-45,0.0,1.0,0.0);
                glRotatef(Ix,1.0,0.0,0.0);
                glRotatef(Iy,0.0,1.0,0.0);
                glRotatef(Iz,0.0,0.0,1.0);
                drawline();
                glTranslatef(L*Tx/10,L*Ty/10,L*Tz/10);
                glRotatef(Rx,1.0,0.0,0.0);
                glRotatef(Ry,0.0,1.0,0.0);
                glRotatef(Rz,0.0,0.0,1.0);
                glScalef (Sx/100, Sy/100, Sz/100);
                if (type == 0){
                        input();
                }else if (type == 1){
                        colorcube();
                }else if (type == 2){
                        flatcube();
                }

                glLoadIdentity();
                glViewport(GLBox1->Width/2,GLBox1->Height/2,GLBox1->Width/2, GLBox1->Height/2);
                gluLookAt(L*sqrt(3)/3,L*sqrt(3)/3,L*sqrt(3)/3,0,0,0,0,1,0);
                light();
                materials();
                shadings();
                glRotatef(35.26,1.0,0.0,0.0);
                glRotatef(-45,0.0,1.0,0.0);
                glRotatef(Ix,1.0,0.0,0.0);
                glRotatef(Iy,0.0,1.0,0.0);
                glRotatef(Iz,0.0,0.0,1.0);
                drawline();
                glTranslatef(L*Tx/10,L*Ty/10,L*Tz/10);
                glRotatef(Rx,1.0,0.0,0.0);
                glRotatef(Ry,0.0,1.0,0.0);
                glRotatef(Rz,0.0,0.0,1.0);
                glScalef (Sx/100, Sy/100, Sz/100);
                if (type == 0){
                        input();
                }else if (type == 1){
                        colorcube();
                }else if (type == 2){
                        flatcube();
                }
        }
        glFlush();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


void __fastcall TForm1::Scrollrx(TObject *Sender, TScrollCode ScrollCode,
      int &ScrollPos)
{
        Labelrx->Caption = ScrollBarrx->Position;
        Rx=ScrollBarrx->Position;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Scrollry(TObject *Sender, TScrollCode ScrollCode,
      int &ScrollPos)
{
        Labelry->Caption = ScrollBarry->Position;
        Ry=ScrollBarry->Position;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Scrollrz(TObject *Sender, TScrollCode ScrollCode,
      int &ScrollPos)
{
        Labelrz->Caption = ScrollBarrz->Position;
        Rz=ScrollBarrz->Position;
        GLBox1->Invalidate();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Btnr(TObject *Sender)
{
      ScrollBarrx->Position = 0;
      Labelrx->Caption = ScrollBarrx->Position;
      Rx=ScrollBarrx->Position;
      ScrollBarry->Position = 0;
      Labelry->Caption = ScrollBarry->Position;
      Ry=ScrollBarry->Position;
      ScrollBarrz->Position = 0;
      Labelrz->Caption = ScrollBarrz->Position;
      Rz=ScrollBarrz->Position;
      GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Scrolltx(TObject *Sender, TScrollCode ScrollCode,
      int &ScrollPos)
{

        Labeltx->Caption = ScrollBartx->Position;
        Tx=ScrollBartx->Position;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Scrollty(TObject *Sender, TScrollCode ScrollCode,
      int &ScrollPos)
{
        Labelty->Caption = ScrollBarty->Position;
        Ty=ScrollBarty->Position;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Scrolltz(TObject *Sender, TScrollCode ScrollCode,
      int &ScrollPos)
{
        Labeltz->Caption = ScrollBartz->Position;
        Tz=ScrollBartz->Position;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btnt(TObject *Sender)
{
        ScrollBartx->Position = 0;
        Labeltx->Caption = ScrollBartx->Position;
        Tx=ScrollBartx->Position;
        ScrollBarty->Position = 0;
        Labelty->Caption = ScrollBarty->Position;
        Ty=ScrollBarty->Position;
        ScrollBartz->Position = 0;
        Labeltz->Caption = ScrollBartz->Position;
        Tz=ScrollBartz->Position;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Scrollsx(TObject *Sender, TScrollCode ScrollCode,
      int &ScrollPos)
{
        if (CheckBoxs->Checked == true){
        Labelsx->Caption = ScrollBarsx->Position;
        Sx=ScrollBarsx->Position;
        Sy=Sx;
        Sz=Sx;
        GLBox1->Invalidate();
       }else{
        ScrollBarsy->Enabled = true;
        ScrollBarsz->Enabled = true;
        Labelsx->Caption = ScrollBarsx->Position;
        Sx=ScrollBarsx->Position;
        GLBox1->Invalidate();
       }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Scrollsy(TObject *Sender, TScrollCode ScrollCode,
      int &ScrollPos)
{
        Labelsy->Caption = ScrollBarsy->Position;
        Sy=ScrollBarsy->Position;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Scrollsz(TObject *Sender, TScrollCode ScrollCode,
      int &ScrollPos)
{
        Labelsz->Caption = ScrollBarsz->Position;
        Sz=ScrollBarsz->Position;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btns(TObject *Sender)
{
        ScrollBarsx->Position = 100;
        Labelsx->Caption = ScrollBarsx->Position;
        Sx=ScrollBarsx->Position;
        ScrollBarsy->Position = 100;
        Labelsy->Caption = ScrollBarsy->Position;
        Sy=ScrollBarsy->Position;
        ScrollBarsz->Position = 100;
        Labelsz->Caption = ScrollBarsz->Position;
        Sz=ScrollBarsz->Position;
        CheckBoxs->Checked = false;
        ScrollBarsy->Enabled = true;
        ScrollBarsz->Enabled = true;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Checks(TObject *Sender)
{
       if (CheckBoxs->Checked == true){
        Labelsy->Caption = 0;
        Labelsz->Caption = 0;
        ScrollBarsy->Enabled = false;
        ScrollBarsz->Enabled = false;
        GLBox1->Invalidate();
       }else{
        ScrollBarsy->Enabled = true;
        ScrollBarsz->Enabled = true;
       }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::Buttoni1Click(TObject *Sender)
{
        Rx=0;
        Ry=0;
        Rz=0;
        Ix=0;
        Iy=0;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Buttoni2Click(TObject *Sender)
{
        Rx=0;
        Ry=0;
        Rz=0;
        Ix=0;
        Iy=90;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Buttoni3Click(TObject *Sender)
{
        Rx=0;
        Ry=0;
        Rz=0;
        Ix=0;
        Iy=180;
        GLBox1->Invalidate();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Buttoni4Click(TObject *Sender)
{
        Rx=0;
        Ry=0;
        Rz=0;
        Ix=0;
        Iy=270;
        GLBox1->Invalidate();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Buttoni5Click(TObject *Sender)
{
        Rx=0;
        Ry=0;
        Rz=0;
        Ix=180;
        Iy=0;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Buttoni6Click(TObject *Sender)
{
        Rx=0;
        Ry=0;
        Rz=0;
        Ix=180;
        Iy=90;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Buttoni7Click(TObject *Sender)
{
        Rx=0;
        Ry=0;
        Rz=0;
        Ix=180;
        Iy=180;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Buttoni8Click(TObject *Sender)
{
        Rx=0;
        Ry=0;
        Rz=0;
        Ix=180;
        Iy=270;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBoxlbClick(TObject *Sender)
{
        if(CheckBoxlb->Checked == true){
                BlueLight = true;
        }else{
                BlueLight = false;
        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBoxlgClick(TObject *Sender)
{
        if(CheckBoxlg->Checked == true){
                GreenLight = true;
        }else{
                GreenLight = false;
        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBoxlrClick(TObject *Sender)
{
        if(CheckBoxlr->Checked == true){
                RedLight = true;
        }else{
                RedLight = false;
        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::RadioBrassClick(TObject *Sender)
{
        if(RadioBrass->Checked == true){
                material = 0;
        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RadioGoldClick(TObject *Sender)
{
        if(RadioGold->Checked == true){
                material = 1;
        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioPewterClick(TObject *Sender)
{
        if(RadioPewter->Checked == true){
                material = 2;
        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadiodefaultClick(TObject *Sender)
{
        if(Radiodefault->Checked == true){
                material = 3;
        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioLineClick(TObject *Sender)
{
        if(RadioLine->Checked == true){
                shading = 0;
        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioFlatClick(TObject *Sender)
{
        if(RadioFlat->Checked == true){
                shading = 1;
        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioSmoothClick(TObject *Sender)
{
        if(RadioSmooth->Checked == true){
                shading = 2;
        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadiovsClick(TObject *Sender)
{
        if(Radiovs->Checked == true){
                view = 0;
        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadiovmClick(TObject *Sender)
{
        if(Radiovm->Checked == true){
                view = 1;
        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtoninputClick(TObject *Sender)
{
        ScrollBarrx->Position = 0;
        Labelrx->Caption = ScrollBarrx->Position;
        Rx=ScrollBarrx->Position;
        ScrollBarry->Position = 0;
        Labelry->Caption = ScrollBarry->Position;
        Ry=ScrollBarry->Position;
        ScrollBarrz->Position = 0;
        Labelrz->Caption = ScrollBarrz->Position;
        Rz=ScrollBarrz->Position;
        ScrollBartx->Position = 0;
        Labeltx->Caption = ScrollBartx->Position;
        Tx=ScrollBartx->Position;
        ScrollBarty->Position = 0;
        Labelty->Caption = ScrollBarty->Position;
        Ty=ScrollBarty->Position;
        ScrollBartz->Position = 0;
        Labeltz->Caption = ScrollBartz->Position;
        Tz=ScrollBartz->Position;
        ScrollBarsx->Position = 100;
        Labelsx->Caption = ScrollBarsx->Position;
        Sx=ScrollBarsx->Position;
        ScrollBarsy->Position = 100;
        Labelsy->Caption = ScrollBarsy->Position;
        Sy=ScrollBarsy->Position;
        ScrollBarsz->Position = 100;
        Labelsz->Caption = ScrollBarsz->Position;
        Sz=ScrollBarsz->Position;
        CheckBoxs->Checked = false;
        ScrollBarsy->Enabled = true;
        ScrollBarsz->Enabled = true;
        Ix=0;
        Iy=0;
        CheckBoxlr->Checked = true;
        CheckBoxlg->Checked = true;
        CheckBoxlb->Checked = true;
        RedLight = true;
        GreenLight = true;
        BlueLight = true;
        RadioSmooth->Checked = true;
        shading = 2;
        Radiovs->Checked = true;
        view = 0;
        Radiodefault->Checked = true;
        material = 3;
        int otype = type;
        type = 0;
        AnsiString Dir,Name,Path;
        if (OD->Execute()){
                Dir = ExtractFileDir(OD->FileName);
                Name = ExtractFileName(OD->FileName);
                Path = Dir+"\\"+Name;
                FILE* infile = fopen(Path.c_str(),"r");
                if(infile!=NULL){
                        char ch[50];
                        count=0;
                        while((fscanf(infile,"%s",ch))!=EOF){
                                if(strstr(ch,"Triangle")!=NULL)
                                        count++;
                        }
                        fclose(infile);
                        infile = fopen(Path.c_str(),"r");
                        int t = 0;
                        vx = (float *)malloc(3*count*sizeof(float));
                        vy = (float *)malloc(3*count*sizeof(float));
                        vz = (float *)malloc(3*count*sizeof(float));
                        nx = (float *)malloc(3*count*sizeof(float));
                        ny = (float *)malloc(3*count*sizeof(float));
                        nz = (float *)malloc(3*count*sizeof(float));
                        front = (int *)malloc(3*count*sizeof(int));
                        back = (int *)malloc(3*count*sizeof(int));
                        while((fscanf(infile,"%s",ch))!=EOF){
                                if(strstr(ch,"Triangle")!=NULL){
                                        fscanf(infile,"%d%d%d%d%d%d",&front[t*3],&front[t*3+1],&front[t*3+2],&back[t*3],&back[t*3+1],&back[t*3+2]);
                                        fscanf(infile,"%f%f%f%f%f%f",&vx[t*3],&vy[t*3],&vz[t*3],&nx[t*3],&ny[t*3],&nz[t*3]);
                                        fscanf(infile,"%f%f%f%f%f%f",&vx[t*3+1],&vy[t*3+1],&vz[t*3+1],&nx[t*3+1],&ny[t*3+1],&nz[t*3+1]);
                                        fscanf(infile,"%f%f%f%f%f%f",&vx[t*3+2],&vy[t*3+2],&vz[t*3+2],&nx[t*3+2],&ny[t*3+2],&nz[t*3+2]);
                                        t++;
                                }
                        }
                        float posA = vx[0];
                        float posB = vy[0];
                        float posC = vz[0];
                        float negA = vx[0];
                        float negB = vy[0];
                        float negC = vz[0];

                        for(t=1;t<count*3;t++){
                                float a = vx[t];
                                float b = vy[t];
                                float c = vz[t];
                                if(posA<a){
                                        posA=a;
                                }else if(posA>a){
                                        negA=a;
                                }
                                if(posB<b){
                                        posB=b;
                                }else if(posB>b){
                                        negB=b;
                                }
                                if(posC<c){
                                        posC=c;
                                }else if(posC>c){
                                        negC=c;
                                }
                        }
                        float tA=(posA+negA)/2;
                        float tB=(posB+negB)/2;
                        float tC=(posC+negC)/2;

                        float mA=posA-tA;
                        float mB=posB-tB;
                        float mC=posC-tC;
                        if(mA>mB){
                                if(mA>mC){
                                        L=mA;
                                }else{
                                        L=mC;
                                }
                        }else{
                                if(mB>mC){
                                        L=mB;
                                }else{
                                        L=mC;
                                }
                        }

                        for(t=0;t<3*count;t++){
                                vx[t]=vx[t]-tA;
                                vy[t]=vy[t]-tB;
                                vz[t]=vz[t]-tC;
                        }
                        fclose(infile);
                        Sx=90;
                        Sy=90;
                        Sz=90;
                        GLBox1->Invalidate();
                }
                NOTFREE=false;
        }else{
                type = otype;
        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Buttonobj1Click(TObject *Sender)
{
        type = 1;
        if (NOTFREE==false){
                free(vx);
                free(vy);
                free(vz);
                free(nx);
                free(ny);
                free(nz);
                free(front);
                free(back);
                NOTFREE=true;
        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Buttonobj2Click(TObject *Sender)
{
        type =2;
        if (NOTFREE==false){
                free(vx);
                free(vy);
                free(vz);
                free(nx);
                free(ny);
                free(nz);
                free(front);
                free(back);
                NOTFREE=true;
        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

