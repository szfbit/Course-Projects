//*************************************************************************
//	Include headers
//*************************************************************************
#include "./headers/glui.h"
#include "./headers/container.h"
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cfloat>
#include <vector>
#include <algorithm>
using namespace std;
//*************************************************************************
//  Declarations
//*************************************************************************
int displayMesh;// control display of mesh
int displaySupport;// control display of support structure
int displaySampling;// control display of sampling points
int displayOverHang;// control display of overhang faces
int displayStructure;// control display of structure
int evaluationMode;// control of evaluation mode
int exportSupport;// control export of support structure
int nSamplingPts;// number of sampling points
int structureN;// control wrapping structure to be N
int structureX;// control wrapping structure to be X
const double PI = 3.141592653589793;// PI
double minCoordX;// min x coordinate of mesh
double minCoordY;// min y coordinate of mesh
double minCoordZ;// min z coordinate of mesh
double model_scale = 0.0;// fit the model to the screen
bool hasTrans;// whether the model has been translated
vector<Vert> vert_table;// vertex table for mesh
vector<Vert> vert_bkp;// backup vertex table for mesh
vector<Face> face_table;// face table for mesh
vector<Vert> sup_table;// vertex table for sampling points
vector<Vert> wall_table;// vertex table for cone-mesh intersection points
vector<int> c;// detect the end of tree building loop
vector<Vert> vstruct_table;// vertex table for N structure
vector<Vert> vtip_table;// vertex table for the tips
vector<Face> struct_table;// face table for N structure
vector<Face> tip_table;// face table for the tips
double criticalAngle;// critical printing angle of the 3D printer
double samplingDistance;// samepling distance in mm
double thickness;// thickness of the material
//*************************************************************************
//  Support Functions
//*************************************************************************
//-------------------------------------------------------------------------
//  File IO
//-------------------------------------------------------------------------
bool openfile(char *filepath);// open a mesh file, return false if fail
void saveFile();// save file with or without support
void UISetup();// reset the UI
//-------------------------------------------------------------------------
//  Read Mesh File
//-------------------------------------------------------------------------
int char2int(char*c);// customized function to change char into int
double *calFaceNormal(double*p1, double*p2, double*p3);// return face normal
double *normalize(double *n);// return normalized vector
//-------------------------------------------------------------------------
//  Model Translation
//-------------------------------------------------------------------------
void setTranslateDis();// find the boundary of the mesh for 3 dimensions 
void translateModel();// translate the model to the center of the screen
//-------------------------------------------------------------------------
//  Find Better Rotation
//-------------------------------------------------------------------------
vector<int*> getRandomOrient();// return k random rotation angles
double calNSupportPts(double *directionNorm);// return the sampling area after rotation
double *getRotated(double *m, double a, double b, double r);// return the result of rotation
void orient();// rotate the model to best orientation
void setFaceNormal(int type);// recalculate the face normal after rotation
void resumeVert();// resume the rotation
//-------------------------------------------------------------------------
//  Overhang Detection
//-------------------------------------------------------------------------
double calPlaneAngle(double *n1, double *n2);// calculate the angle between face and printing direction
bool isSameDirection(double *n1, double *n2);// return whether the face is the same with the printing direction
void findOverHang(double *directionNorm);// find the overhang faces, vertices and edges
//-------------------------------------------------------------------------
//  Sampling
//-------------------------------------------------------------------------
bool hasIntersection(int *vlist, double scanline, char t);// return whether the face has intersection with the scan plane
double *calCross(double*p1, double*p2, double*p3);// return the cross product of two vectors
double calDot(double *p1, double *p2);// return the dot product of two vectors
double calLength(double *v);// return the length of a vector
bool isInFace(double x, double y, double z, int *vlist);// return whether the point is in a face
void sampling();// get the sampling points
//-------------------------------------------------------------------------
//  Tree building
//  --detecting cone-to-cone intersection
//-------------------------------------------------------------------------
bool srtcmp(Vert v1, Vert v2);// comparator for vector sorting
void sortVector(vector<Vert> &v);//  sort the vector in point height ascending order
bool isDone(vector<int> v);// return whether the building tree loop is end
int getPair(int index, vector<Vert> v, vector<int> &c);// get the index of the point with minimum distance with ci
double *getTempPoints(double *p1, double *p2);// return temp points for cone-to-cone intersection
double *getNewPoint(double *p1, double *p2);// return the s point of overhang points(best intersection point of cones)
double calDistance(double *c1, double *c2);// return the distance between two points
double calHorzDis(double *p1, double *p2);// return the distance(ignoring Y) between two points
void buildTree();// build the tree 
//-------------------------------------------------------------------------
//  Tree building
//  --detecting cone-to-mesh intersection
//-------------------------------------------------------------------------
double *getConeMeshIntersection(double *p1, double *p2, int index);// get the best cone-to-mesh intersection point
bool findBoundary(int index, double *p);// return whether a cone has intersection with the mesh
void detectCollision();// detect cone-to-mesh intersection and modify the tree
//-------------------------------------------------------------------------
//  Apply Structure
//-------------------------------------------------------------------------
void applyStructureN();// apply N structure
void applyStructureX();// apply X structure
vector<double *> getAroundPtsN(bool isTip, double thickness, double weight, double *p);// used for N structure
vector<double *> getAroundPtsX(bool isTip, double thickness, double weight, double *p);// used for X structure
//-------------------------------------------------------------------------
//  Evaluate Support Cost
//-------------------------------------------------------------------------
void evaluate();// evaluate the result
//*************************************************************************
//  GLUT Declarations
//*************************************************************************
const float ANGFACT = { 1.0f };// rotation factor
const float SCLFACT = { 0.005f };// scaling factor
const float MINSCALE = { 0.05f };// minimum scale value
bool LmouseDown = false;// mouse left key down
bool MmouseDown = false;// mouse mid key down
bool RmouseDown = false;// mouse right key down
int	Xmouse, Ymouse;// mouse values
float Xrot, Yrot;// rotation angles in degrees
void init();// initialization
//-------------------------------------------------------------------------
//  CallBack Functions
//-------------------------------------------------------------------------
void display(void);// display the model
void mouse(int button, int state, int x, int y);// mouse click control
void motion(int x, int y);// mouse motion control
void reshape(int w, int h);// called when window size changed
void control_cb(int control);// glui control
//-------------------------------------------------------------------------
//  Define the window position on screen
//-------------------------------------------------------------------------
int window_x;
int window_y;
//-------------------------------------------------------------------------
//  Variables representing the window size
//-------------------------------------------------------------------------
int window_width = 1100;
int window_height = 860;
//-------------------------------------------------------------------------
//  Display mode 0:FLAT, 1:SMOOTH, 2:WIREFRAME, 3:SHADED WITH EDGES
//-------------------------------------------------------------------------
int mode = 0;
//-------------------------------------------------------------------------
//  GLUI control window
//-------------------------------------------------------------------------
GLuint main_window;//	The id of the main window
char *window_title = const_cast<char*>("GLUI");//	window title
//*************************************************************************
//  GLUI Declarations
//*************************************************************************
GLUI *glui_window;// pointer to the right GLUI window
GLUI_Checkbox *evaMode;// checkbox for evaluation mode
GLUI_Checkbox *exptSup;// check box for export support
GLUI_Checkbox *disMesh;// check box for display mesh
GLUI_Checkbox *disSup;// check box for display support
GLUI_Checkbox *disSamp;// check box for display sampling points
GLUI_Checkbox *disOverH;// check box for display overhang faces
GLUI_Checkbox *disStruct;// check box for display structure faces
GLUI_Checkbox *structN;// check box for display structure faces
GLUI_Checkbox *structX;// check box for display structure faces
GLUI_EditText *statustxt;// text shows the status
GLUI_EditText *loadtext;// file open path
GLUI_EditText *savetext;// file save path
GLUI_EditText *kvalue;// number of random rotations
GLUI_EditText *critAngle;// critical angle
GLUI_EditText *samplingDis;// sampling distance
GLUI_EditText *newCost;// new support cost
GLUI_EditText *origCost;// old support cost
GLUI_EditText *savePercent;// percentage saved
GLUI_EditText *thicknesstxt;// percentage saved
GLUI_Button *loadbtn;// open button
GLUI_Button *savebtn;// save button
GLUI_Button *orientbtn;// rotate button
GLUI_Button *resumeorientbtn;// reset rotation button
GLUI_Button *analysisbtn;// overhang button
GLUI_Button *samplebtn;// sampling button
GLUI_Button *buildbtn;// build tree button
GLUI_Button *collisionbtn;// detect cone-to-mesh intersection button
GLUI_Button *addStructurebtn;// add the support structure button
GLUI_Button *evabtn;// evaluation button
//-------------------------------------------------------------------------
//  Declare live variables (related to GLUI)
//-------------------------------------------------------------------------
char *string_list[] = { (char*)"Flat Shaded", (char*)"Smooth Shaded", (char*)"Wireframe", (char*)"shaded with Mesh Edges" };// String list to hold render options
int listbox_item_id = 1;// Id of the selected item in the list box
float rotation_matrix[16]// Rotation Matrix Live Variable Array
= { 1.0, 0.0, 0.0, 0.0,
0.0, 1.0, 0.0, 0.0,
0.0, 0.0, 1.0, 0.0,
0.0, 0.0, 0.0, 1.0 };
float translate_xy[2] = { 0.0, 0.0 };// Translation XY Live Variable
float translate_z = 1.0;// Translation Z Live Variable
float zoom = 1.0;// Spinner Zoom Live Variable
void setupGLUI();// Set up the GLUI window and its components
void idle();// Idle callack function
void glui_callback(int arg);// Declare callbacks related to GLUI
//-------------------------------------------------------------------------
//  Declare the IDs of controls generating callbacks
//-------------------------------------------------------------------------
enum
{
	ZOOM_SPINNER,
	QUIT_BUTTON
};
//-------------------------------------------------------------------------
//  Support Functions
//-------------------------------------------------------------------------
void centerOnScreen();// center the windows in the screen
void setuplight();// set up light
void drawObject();// prepare for the draw
void draw();// draw the model according to the mode
//*************************************************************************
//  GLUT Functions.rotation_matrix
//*************************************************************************
void init()
{
	int x, y, wq, hq;
	GLUI_Master.get_viewport_area(&x, &y, &wq, &hq);
	//glClearColor(1.0, 1.0, 1.0, 1.0);
	glClearColor(0.234, 0.322, 0.689, 1.0);
	glViewport(x, y, wq, hq);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (window_width <= window_height)
	{
		glOrtho(-0.7, 0.7, -0.7*hq / wq, 0.7*hq / wq, -10.0, 10.0);
	}
	else
	{
		glOrtho(-0.7*wq / hq, 0.7*wq / hq, -0.7, 0.7, -10.0, 10.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
//-------------------------------------------------------------------------
//  This function is passed to the glutReshapeFunc and is called
//  whenever the window is resized.
//-------------------------------------------------------------------------
void reshape(int w, int h)
{
	window_width = w;
	window_height = h;
	int x, y, wq, hq;
	GLUI_Master.get_viewport_area(&x, &y, &wq, &hq);
	//glClearColor(1.0, 1.0, 1.0, 1.0);
	glClearColor(0.234, 0.322, 0.689, 1.0);
	glViewport(x, y, wq, hq);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (window_width <= window_height)
	{
		glOrtho(-0.7, 0.7, -0.7*hq / wq, 0.7*hq / wq, -10.0, 10.0);
	}
	else
	{
		glOrtho(-0.7*wq / hq, 0.7*wq / hq, -0.7, 0.7, -10.0, 10.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutReshapeWindow(w, h);
	glui_window->refresh();
	glutPostRedisplay();
}
//-------------------------------------------------------------------------
//  This function is passed to the glutMouseFunc and is called
//  whenever the mouse is clicked.
//-------------------------------------------------------------------------
void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		switch (state)
		{
		case GLUT_DOWN:
			LmouseDown = true;
			Xmouse = x;
			Ymouse = y;
			break;
		case GLUT_UP:
			LmouseDown = false;
			break;
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		switch (state)
		{
		case GLUT_DOWN:
			MmouseDown = true;
			break;
		case GLUT_UP:
			MmouseDown = false;
			break;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		switch (state)
		{
		case GLUT_DOWN:
			RmouseDown = true;
			break;
		case GLUT_UP:
			RmouseDown = false;
			break;
		}
		break;
	}
}
//-------------------------------------------------------------------------
//  This function is passed to the glutMotionFunc and is called
//  whenever the mouse is dragged.
//-------------------------------------------------------------------------
void motion(int x, int y)
{
	int dx = x - Xmouse;
	int dy = y - Ymouse;
	if (LmouseDown && !MmouseDown&& !RmouseDown)
	{
		Xrot += (ANGFACT*dy);
		Yrot += (ANGFACT*dx);
	}
	if (!LmouseDown && MmouseDown&& !RmouseDown)
	{
		zoom += SCLFACT * (float)(dx - dy);
		if (zoom < MINSCALE)
		{
			zoom = MINSCALE;
		}
	}
	if (!LmouseDown && !MmouseDown&& RmouseDown)
	{
		translate_xy[0] += dx*0.001;
		translate_xy[1] -= dy*0.001;
	}
	Xmouse = x;
	Ymouse = y;
}
//	Set up light and material
void setuplight()
{
	//-------------------------------------------------------------------------
	//  Lighting set up
	//-------------------------------------------------------------------------
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	//-------------------------------------------------------------------------
	//  Set the light position
	//-------------------------------------------------------------------------
	GLfloat light_position[] = { 0.0, 0.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//-------------------------------------------------------------------------
	//  Set lighting intensity and color
	//-------------------------------------------------------------------------
	GLfloat light_ambient[] = { 0.19225f, 0.19225f, 0.19225f, 1.0f };
	GLfloat light_diffuse[] = { 0.50754f, 0.50754f, 0.50754f, 1.0f };
	GLfloat light_specular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat material_ambient[] = { 0.19225f, 0.19225f, 0.19225f, 1.0f };
	GLfloat material_diffuse[] = { 0.50754f, 0.50754f, 0.50754f, 1.0f };
	GLfloat material_specular[] = { 0.508273f, 0.508273f, 0.508273f, 1.0f };
	GLfloat material_shininess = { 10.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	//-------------------------------------------------------------------------
	//  Set material properties
	//-------------------------------------------------------------------------
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, material_shininess);
}
//-------------------------------------------------------------------------
//  This function sets the window x and y coordinates
//  such that the window becomes centered
//-------------------------------------------------------------------------
void centerOnScreen()
{
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
}
//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display
//	OpenGL contents on the window.
//-------------------------------------------------------------------------
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear the window
	glEnable(GL_DEPTH_TEST);
	setuplight();// Set up the lighting
	drawObject();// Draw object
	glutSwapBuffers();// Swap contents of backward and forward frame buffers
}
//-------------------------------------------------------------------------
//  Draws the object.
//-------------------------------------------------------------------------
void drawObject()
{
	// Draw the object only if the Draw check box is selected
	glPushMatrix();// Push the current matrix into the model view stack
	glTranslatef(translate_xy[0]-0.25, translate_xy[1]-0.3, -translate_z);// Apply the translation
	glRotatef((GLfloat)Yrot, 0.0, 1.0, 0.0);
	glRotatef((GLfloat)Xrot, 1.0, 0.0, 0.0);
	glMultMatrixf(rotation_matrix);// Apply the rotation matrix
	glScalef(zoom, zoom, zoom);// Apply the scaling
	//-------------------------------------------------------------------------
	//  Apply the mode
	//-------------------------------------------------------------------------
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	// Draw the meshes
	draw();
	// End of draw
	glPopMatrix();
	glFlush();
}
//-------------------------------------------------------------------------
//  This function will draw the meshed according to
//	the winged edge structure
//-------------------------------------------------------------------------
void draw()
{
	glLineWidth(1.0f);
	
	glBegin(GL_LINES);
	// draw line for x axis
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	// draw line for y axis
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	// draw line for Z axis
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 1.0);
	glEnd();

	glEnable(GL_FLAT);
	glShadeModel(GL_FLAT);
	double scale = (model_scale / (vert_table.size())) * 3;
	if (displayMesh)
	{
		for (size_t i = 0; i < face_table.size(); i++)
		{
			if (displayOverHang)
			{
				if (face_table[i].GetOverHange())
				{
					glColor3f(0.6, 0.0, 0.0);
				}
				else
				{
					glColor3f(0.6, 0.6, 0.6);
				}
			}
			else
			{
				glColor3f(0.6, 0.6, 0.6);
			}			
			int *vlist = face_table[i].GetAllVert();
			double *p1 = vert_table[vlist[0]].GetCoord();
			double *p2 = vert_table[vlist[1]].GetCoord();
			double *p3 = vert_table[vlist[2]].GetCoord();
			double *norm = face_table[i].GetNorm();
			glBegin(GL_TRIANGLES);
			glNormal3f(norm[0], norm[1], norm[2]);
			glVertex3f(p1[0] / scale, p1[1] / scale, p1[2] / scale);
			glVertex3f(p2[0] / scale, p2[1] / scale, p2[2] / scale);
			glVertex3f(p3[0] / scale, p3[1] / scale, p3[2] / scale);
			glEnd();
		}
	}
	for (size_t i = 0; i < wall_table.size(); i++)
	{
		glColor3f(0.0, 1.0, 0.0);
		glPointSize(3.0f);
		double *p = wall_table[i].GetCoord();
		glBegin(GL_POINTS);
		glVertex3f(p[0] / scale, p[1] / scale, p[2] / scale);
		glEnd();
	}
	for (size_t i = 0; i < sup_table.size(); i++)
	{
		glLineWidth(2.0f);
		int p = sup_table[i].GetPair();
		int ch = sup_table[i].GetChild();
		if (displaySampling)
		{
			glColor3f(0.0, 0.0, 1.0);
			glPointSize(5.0f) ;
			double *p = sup_table[i].GetCoord();
			glBegin(GL_POINTS);
			glVertex3f(p[0] / scale, p[1] / scale, p[2] / scale);
			glEnd();
		}
		if (displaySupport)
		{
			if (p==-1 || ch<0)
			{
				double *p1 = sup_table[i].GetCoord();
				double p2[] = { p1[0], 0.0, p1[2] };
				glColor3f(1.0, 1.0, 0.2);
				glBegin(GL_LINES);
				glVertex3f(p1[0] / scale, p1[1] / scale, p1[2] / scale);
				glVertex3f(p2[0] / scale, p2[1] / scale, p2[2] / scale);
				glEnd();
			}
			else if (ch >= 0)
			{
				double *p1 = sup_table[i].GetCoord();
				double *p2;

				if (sup_table[i].GetEnd())
				{
					glColor3f(1.0, 0.0, 0.0);
					p2 = wall_table[ch].GetCoord();
				}
				else
				{
					glColor3f(1.0, 1.0, 0.2);
					p2 = sup_table[ch].GetCoord();
				}
				glBegin(GL_LINES);
				glVertex3f(p1[0] / scale, p1[1] / scale, p1[2] / scale);
				glVertex3f(p2[0] / scale, p2[1] / scale, p2[2] / scale);
				glEnd();
			}
		}
	}

	if (displayStructure)
	{
		glColor3f(1.0, 1.0, 0.2);
		for (size_t i = 0; i < tip_table.size();i++)
		{
			int *vlist = tip_table[i].GetAllVert();
			double *p1 = vtip_table[vlist[0]].GetCoord();
			double *p2 = vtip_table[vlist[1]].GetCoord();
			double *p3 = vtip_table[vlist[2]].GetCoord();
			double *norm = tip_table[i].GetNorm();
			glBegin(GL_TRIANGLES);
			glNormal3f(norm[0], norm[1], norm[2]);
			glVertex3f(p1[0] / scale, p1[1] / scale, p1[2] / scale);
			glVertex3f(p2[0] / scale, p2[1] / scale, p2[2] / scale);
			glVertex3f(p3[0] / scale, p3[1] / scale, p3[2] / scale);
			glEnd();
		}
		
		for (size_t i = 0; i < struct_table.size(); i++)
		{
			int *vlist = struct_table[i].GetAllVert();
			double *p1 = vstruct_table[vlist[0]].GetCoord();
			double *p2 = vstruct_table[vlist[1]].GetCoord();
			double *p3 = vstruct_table[vlist[2]].GetCoord();
			double *norm = struct_table[i].GetNorm();
			glBegin(GL_TRIANGLES);
			glNormal3f(norm[0], norm[1], norm[2]);
			glVertex3f(p1[0] / scale, p1[1] / scale, p1[2] / scale);
			glVertex3f(p2[0] / scale, p2[1] / scale, p2[2] / scale);
			glVertex3f(p3[0] / scale, p3[1] / scale, p3[2] / scale);
			glEnd();
		}
	}
}

//-------------------------------------------------------------------------
//  Functions for GLUI controls
//-------------------------------------------------------------------------
void control_cb(int control) {
#define SAVEID 500
#define LOADID 501
#define OVERHANG 503
#define SAMPLE 504
#define BUILD 505
#define ORIENTATION 506
#define RESUME 507
#define COLLISION 508
#define STRUCT 509
#define EVALUATE 510
	if (control == LOADID)
	{
		char *filepath = (char*)loadtext->get_text();
		cout << "File Path: " << filepath << endl;
		openfile(filepath);
	}
	if (control == SAVEID)
	{
		statustxt->set_text("Saving file...");
		saveFile();
		savetext->set_text("../smf/");
	}
	if (control == OVERHANG)
	{
		statustxt->set_text("Detecting Overhang Parts");
		double directionNorm[] = { 0.0, 1.0, 0.0 };
		findOverHang(directionNorm);
		statustxt->set_text("Overhang Parts Detected");
	}
	if (control == SAMPLE)
	{
		statustxt->set_text("Sampling");
		sampling();
		statustxt->set_text("Sampling Done");
	}
	if (control == BUILD)
	{
		statustxt->set_text("Building Tree");
		buildTree();
		statustxt->set_text("Tree Built");
	}
	if (control == ORIENTATION)
	{
		statustxt->set_text("Finding Orientation");
		orient();
		statustxt->set_text("Oriented");
	}
	if (control == RESUME)
	{
		statustxt->set_text("Resuming...");
		resumeVert();
		statustxt->set_text("Resumed");
	}
	if (control == COLLISION)
	{
		statustxt->set_text("Detecting Intersection");
		detectCollision();
		statustxt->set_text("Intersection Detected");
	}
	if (control == STRUCT)
	{
		statustxt->set_text("Applying Structure");
		if (structureN == 1)
		{
			applyStructureN();
		}
		else
		{
			applyStructureX();
		}
		statustxt->set_text("Structure Applied");
	}
	if (control == EVALUATE)
	{
		statustxt->set_text("Evaluating");
		evaluate();
		statustxt->set_text("Evaluated");
	}
}
//*************************************************************************
//  GLUI Functions.
//*************************************************************************
void setupGLUI()
{
	GLUI_Master.set_glutIdleFunc(idle);// Set idle function
	//---------------------------------------------------------------------
	// Right GLUI window
	//---------------------------------------------------------------------
	glui_window = GLUI_Master.create_glui_subwindow(main_window, GLUI_SUBWINDOW_RIGHT);// Create GLUI window
	//---------------------------------------------------------------------
	// 'Status' Panel
	//---------------------------------------------------------------------
	// Add the 'File Property' Panel to the GLUI window
	GLUI_Panel *sts_panel = glui_window->add_panel("Status");
	statustxt = glui_window->add_edittext_to_panel(sts_panel, "Message: ");
	statustxt->set_text("Please open a file");
	statustxt->set_alignment(GLUI_ALIGN_CENTER);
	statustxt->set_w(200);
	statustxt->disable();
	//---------------------------------------------------------------------
	// 'File Property' Panel
	//---------------------------------------------------------------------
	// Add the 'File Property' Panel to the GLUI window
	GLUI_Panel *fp_panel = glui_window->add_panel("File Property");
	// Load file controls
	evaMode= glui_window->add_checkbox_to_panel(fp_panel, "Evaluation Mode", &evaluationMode);
	evaMode->set_int_val(0);
	loadtext = glui_window->add_edittext_to_panel(fp_panel, "Load Path: ", GLUI_EDITTEXT_TEXT);
	loadtext->set_text("D:\\models\\bird.obj");
	loadtext->set_w(200);
	loadtext->set_alignment(GLUI_ALIGN_LEFT);
	loadbtn = glui_window->add_button_to_panel(fp_panel, "Open", LOADID, control_cb);
	loadbtn->set_alignment(GLUI_ALIGN_LEFT);
	loadbtn->set_w(200);
	glui_window->add_separator_to_panel(fp_panel);
	// Save file controls
	exptSup = glui_window->add_checkbox_to_panel(fp_panel, "Export Support", &exportSupport);
	exptSup->set_int_val(1);
	savetext = glui_window->add_edittext_to_panel(fp_panel, "Save Path: ", GLUI_EDITTEXT_TEXT);
	savetext->set_text("D:\\result\\.obj");
	savetext->set_w(200);
	savetext->set_alignment(GLUI_ALIGN_LEFT);
	savebtn = glui_window->add_button_to_panel(fp_panel, "Save", SAVEID, control_cb);
	savebtn->set_alignment(GLUI_ALIGN_LEFT);
	savebtn->set_w(200);
	//---------------------------------------------------------------------
	// 'Analysis' Panel
	//---------------------------------------------------------------------
	// Rotation
	GLUI_Panel *analysis_panel = glui_window->add_panel("Analysis");
	kvalue = glui_window->add_edittext_to_panel(analysis_panel, "# Orientation: ", GLUI_EDITTEXT_TEXT);
	kvalue->set_text("50");
	kvalue->set_w(200);
	orientbtn= glui_window->add_button_to_panel(analysis_panel, "Orientation", ORIENTATION, control_cb);
	orientbtn->set_w(200);
	resumeorientbtn = glui_window->add_button_to_panel(analysis_panel, "Resume", RESUME, control_cb);
	resumeorientbtn->set_w(200);
	// Overhang
	glui_window->add_separator_to_panel(analysis_panel);
	critAngle = glui_window->add_edittext_to_panel(analysis_panel, "Critical Angle: ", GLUI_EDITTEXT_TEXT);
	critAngle->set_text("50");
	critAngle->set_w(200);
	analysisbtn = glui_window->add_button_to_panel(analysis_panel, "Overhange", OVERHANG, control_cb);
	analysisbtn->set_w(200);
	// Sampling
	glui_window->add_separator_to_panel(analysis_panel);
	samplingDis = glui_window->add_edittext_to_panel(analysis_panel, "Sampling Dist: ", GLUI_EDITTEXT_TEXT);
	samplingDis->set_text("0.25");
	samplingDis->set_w(200);
	samplebtn = glui_window->add_button_to_panel(analysis_panel, "Sampling", SAMPLE, control_cb);
	samplebtn->set_w(200);
	// Build Tree
	glui_window->add_separator_to_panel(analysis_panel);
	buildbtn = glui_window->add_button_to_panel(analysis_panel, "Build Support", BUILD, control_cb);
	buildbtn->set_w(200);
	collisionbtn = glui_window->add_button_to_panel(analysis_panel, "Detect Collision", COLLISION, control_cb);
	collisionbtn->set_w(200);
	glui_window->add_separator_to_panel(analysis_panel);
	// Apply structure
	//N
	GLUI_Panel *struct_panel = glui_window->add_panel_to_panel(analysis_panel, "");
	structN = glui_window->add_checkbox_to_panel(struct_panel, "'N' Struct", &structureN, 100, glui_callback);
	structN->set_int_val(1);
	glui_window->add_column_to_panel(struct_panel);
	//X
	structX = glui_window->add_checkbox_to_panel(struct_panel, "'X' Struct", &structureX, 101, glui_callback);
	structX->set_int_val(0);
	//button
	thicknesstxt = glui_window->add_edittext_to_panel(analysis_panel, "Thickness(mm)", GLUI_EDITTEXT_TEXT);
	thicknesstxt->set_text("0.1");
	thicknesstxt->set_w(200);
	addStructurebtn = glui_window->add_button_to_panel(analysis_panel, "Apply Structure", STRUCT, control_cb);
	addStructurebtn->set_w(200);
	// Evaluate
	glui_window->add_separator_to_panel(analysis_panel);
	origCost = glui_window->add_edittext_to_panel(analysis_panel, "Original Cost: ", GLUI_EDITTEXT_TEXT);
	origCost->set_text("0.0");
	origCost->set_w(200);
	origCost->disable();
	newCost = glui_window->add_edittext_to_panel(analysis_panel, "Clever Sup Cost: ", GLUI_EDITTEXT_TEXT);
	newCost->set_text("0.0");
	newCost->set_w(200);
	newCost->disable();
	savePercent = glui_window->add_edittext_to_panel(analysis_panel, "Saved Material(%): ", GLUI_EDITTEXT_TEXT);
	savePercent->set_text("0.0");
	savePercent->set_w(200);
	newCost->disable();
	evabtn = glui_window->add_button_to_panel(analysis_panel, "Evaluate", EVALUATE, control_cb);
	evabtn->set_w(200);
	//---------------------------------------------------------------------
	// 'Camera' Panel
	//---------------------------------------------------------------------
	// Add the 'Camera' Panel to the GLUI window
	GLUI_Panel *camera_panel = glui_window->add_panel("Camera Control");
	// Create Camera panel 1 that will contain the Display controls
	GLUI_Panel *camera_panel0 = glui_window->add_panel_to_panel(camera_panel, "");
	disMesh = glui_window->add_checkbox_to_panel(camera_panel0, "Display Mesh", &displayMesh);
	disOverH = glui_window->add_checkbox_to_panel(camera_panel0, "Display Overhang", &displayOverHang);
	disSamp = glui_window->add_checkbox_to_panel(camera_panel0, "Display Sampling", &displaySampling);
	disSup = glui_window->add_checkbox_to_panel(camera_panel0, "Display Support", &displaySupport);
	disStruct= glui_window->add_checkbox_to_panel(camera_panel0, "Display Structure", &displayStructure);
	disMesh->set_int_val(1);
	disSup->set_int_val(1);
	disSamp->set_int_val(1);
	disOverH->set_int_val(1);
	disStruct->set_int_val(1);
	// Add the zoom spinner
	GLUI_Spinner *spinner = glui_window->add_spinner_to_panel(camera_panel, "Zoom", GLUI_SPINNER_FLOAT, &zoom, ZOOM_SPINNER, glui_callback);
	// Set the limits for the spinner
	spinner->set_float_limits(0.0, 4.0);
	spinner->set_alignment(GLUI_ALIGN_LEFT);
	//---------------------------------------------------------------------
	// 'Quit' Button
	//---------------------------------------------------------------------
	// Add the Quit Button
	glui_window->add_button("Quit", QUIT_BUTTON, glui_callback);
	// Let the GLUI window know where its main graphics window is
	glui_window->set_main_gfx_window(main_window);
}
//-------------------------------------------------------------------------
//  GLUI callback function.
//-------------------------------------------------------------------------
void glui_callback(int control_id)
{
	// Behave based on control ID
	switch (control_id)
	{
	case 100:
		if (structureN == 1)
		{
			structX->set_int_val(0);
		}
		if (structureN == 0)
		{
			structX->set_int_val(1);
		}
		break;
	case 101:
		if (structureX == 1)
		{
			structN->set_int_val(0);
		}
		if (structureX == 0)
		{
			structN->set_int_val(1);
		}
		break;
	// Quit Button clicked
	case QUIT_BUTTON:
		exit(1);
		break;
	}
}
//-------------------------------------------------------------------------
//  Idle Callback function.
//
//  Set the main_window as the current window to avoid sending the
//  redisplay to the GLUI window rather than the GLUT window.
//  Call the Sleep function to stop the GLUI program from causing
//  starvation.
//-------------------------------------------------------------------------
void idle()
{
	glutSetWindow(main_window);
	glutPostRedisplay();
}
//*************************************************************************
//  Program Main method.
//*************************************************************************
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	// Window becomes centered
	centerOnScreen();
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(window_x, window_y);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	main_window = glutCreateWindow(window_title);
	// Set OpenGL context initial state.
	init();
	// Set the GLUT callback functions
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	// Setup all GLUI stuff
	setupGLUI();
	// Start GLUT event processing loop
	glutMainLoop();
	return 0;
}
//*************************************************************************
//  Support method.
//*************************************************************************
bool openfile(char *filepath)
{
	hasTrans = false;
	minCoordX = DBL_MAX;
	minCoordY = DBL_MAX;
	minCoordZ = DBL_MAX;
	model_scale = 0;
	sup_table.clear();
	vert_table.clear();
	face_table.clear();
	vert_bkp.clear();
	wall_table.clear();
	c.clear();
	tip_table.clear();
	vtip_table.clear();
	struct_table.clear();
	vstruct_table.clear();
	UISetup();
	int count = -1;
	//open file and read to memory
	FILE * file = fopen(filepath, "r");
	if (file == NULL)
	{
		printf("Impossible to open the file !\n");
		return false;
	}

	while (true)
	{
		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
		{
			break; // EOF = End Of File. Quit the loop.
		}
		if (strcmp(lineHeader, "o") == 0)
		{
			count++;
		}
		else if (strcmp(lineHeader, "v") == 0)
		{
			double x, y, z;
			fscanf(file, "%lf %lf %lf\n", &x, &y, &z);
			model_scale += sqrt(x*x + y*y + z*z);
			Vert *v = new Vert(x, y, z);
			vert_table.push_back(*v);
			Vert *vbkp = new Vert(x, y, z);
			vert_bkp.push_back(*vbkp);
		}
		else if (strcmp(lineHeader, "f") == 0)
		{
			char *temp1 = new char[15];
			char *temp2 = new char[15];
			char *temp3 = new char[15];
			
			int matches = fscanf(file, "%s %s %s\n", temp1, temp2, temp3);
			if (matches != 3)
			{
				printf("File can't be read by our simple parser : ( Try exporting with other options\n");
				return false;
			}
			int v1 = char2int(temp1) - 1;
			int v2 = char2int(temp2) - 1;
			int v3 = char2int(temp3) - 1;

			vert_table[v1].AddVert(v2);
			vert_table[v1].AddVert(v3);
			vert_table[v2].AddVert(v1);
			vert_table[v2].AddVert(v3);
			vert_table[v3].AddVert(v1);
			vert_table[v3].AddVert(v2);

			vert_bkp[v1].AddVert(v2);
			vert_bkp[v1].AddVert(v3);
			vert_bkp[v2].AddVert(v1);
			vert_bkp[v2].AddVert(v3);
			vert_bkp[v3].AddVert(v1);
			vert_bkp[v3].AddVert(v2);
			Face *f = new Face(v1, v2, v3);
			f->SetNorm(calFaceNormal(vert_table[v1].GetCoord(), vert_table[v2].GetCoord(), vert_table[v3].GetCoord()));
			if (count > 0)
			{
				f->SetSup();
			}
			face_table.push_back(*f);
		}
	}
	translateModel();
	return true;
}

void saveFile()
{
	string txt = savetext->get_text();
	if (!txt.compare(""))
	{
		statustxt->set_text("File save failed");
	}
	else
	{
		int vcount = 0;
		char *filepath = (char*)savetext->get_text();
		ofstream myfile;
		myfile.open(filepath);
		myfile << "# CMPT764 Course Project-Clever Project" << endl;
		myfile << "o mesh" << endl;
		for (size_t i = 0; i < vert_table.size(); i++)
		{
			double *p = vert_table[i].GetCoord();
			myfile << "v " << p[0] << " " << p[1] << " " << p[2] << endl;
		}
		for (size_t i = 0; i < face_table.size(); i++)
		{
			int *vlist = face_table[i].GetAllVert();
			myfile << "f " << vlist[0] + 1 << " " << vlist[1] + 1 << " " << vlist[2] + 1 << endl;
		}
		vcount += vert_table.size();
		myfile << endl;

		if (exportSupport)
		{
			myfile << "o support" << endl;
			for (size_t i = 0; i < vstruct_table.size(); i++)
			{
				double *p = vstruct_table[i].GetCoord();
				myfile << "v " << p[0] << " " << p[1] << " " << p[2] << endl;
			}
			for (size_t i = 0; i < struct_table.size(); i++)
			{
				int *vlist = struct_table[i].GetAllVert();
				myfile << "f " << vlist[0] + vcount + 1 << " " << vlist[1] + vcount + 1 << " " << vlist[2] + vcount + 1 << endl;
			}
			vcount += vstruct_table.size();
			myfile << endl;
			myfile << "o tip_support" << endl;
			for (size_t i = 0; i < vtip_table.size(); i++)
			{
				double *p = vtip_table[i].GetCoord();
				myfile << "v " << p[0] << " " << p[1] << " " << p[2] << endl;
			}
			for (size_t i = 0; i < tip_table.size(); i++)
			{
				int *vlist = tip_table[i].GetAllVert();
				myfile << "f " << vlist[0] + vcount + 1 << " " << vlist[1] + vcount + 1 << " " << vlist[2] + vcount + 1 << endl;
			}
		}
		statustxt->set_text("File Saved");
	}
}

int char2int(char*c)
{
	char *t = new char[15];
	for (int i = 0; i < 15; i++)
	{
		if (c[i] == '/')
		{
			break;
		}
		t[i] = c[i];
	}

	int result = atoi(t);
	return result;
}

double *normalize(double *n)
{
	double *result = new double[3];
	result[0] = n[0] / sqrtf(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
	result[1] = n[1] / sqrtf(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
	result[2] = n[2] / sqrtf(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
	return result;
}

void setTranslateDis()
{
	double newminx = DBL_MAX;
	double newminy = DBL_MAX;
	double newminz = DBL_MAX;
	for (size_t i = 0; i < vert_table.size(); i++)
	{
		if (vert_table[i].GetCoord()[0] < newminx)
		{
			newminx = vert_table[i].GetCoord()[0];
		}
		if (vert_table[i].GetCoord()[1] < newminy)
		{
			newminy = vert_table[i].GetCoord()[1];
		}
		if (vert_table[i].GetCoord()[2] < newminz)
		{
			newminz = vert_table[i].GetCoord()[2];
		}
	}
	minCoordX = newminx;
	minCoordY = newminy;
	minCoordZ = newminz;
}

void translateModel()
{
	setTranslateDis();
	if (!hasTrans)
	{
		for (size_t i = 0; i < vert_table.size(); i++)
		{
			vert_table[i].TransalteX(-minCoordX);
			vert_table[i].TransalteY(-minCoordY);	
			vert_table[i].TransalteZ(-minCoordZ);
		}
		hasTrans = true;
	}
}

double *calFaceNormal(double*p1, double*p2, double*p3)
{
	double*v1 = new double[3];
	double*v2 = new double[3];
	v1[0] = p2[0] - p1[0];
	v1[1] = p2[1] - p1[1];
	v1[2] = p2[2] - p1[2];
	v2[0] = p3[0] - p1[0];
	v2[1] = p3[1] - p1[1];
	v2[2] = p3[2] - p1[2];
	double x1 = v1[0];
	double y1 = v1[1];
	double z1 = v1[2];
	double x2 = v2[0];
	double y2 = v2[1];
	double z2 = v2[2];
	double *result = new double[3];
	result[0] = y1*z2 - z1*y2;
	result[1] = z1*x2 - x1*z2;
	result[2] = x1*y2 - y1*x2;
	return normalize(result);
}

void setFaceNormal(int type)
{
	if (type == 0)
	{
		for (size_t i = 0; i < face_table.size(); i++)
		{
			int*vlist = face_table[i].GetAllVert();
			double *v1 = vert_table[vlist[0]].GetCoord();
			double *v2 = vert_table[vlist[1]].GetCoord();
			double *v3 = vert_table[vlist[2]].GetCoord();
			double *norm = calFaceNormal(v1, v2, v3);
			face_table[i].SetNorm(norm);
		}
	}
	if (type == 1)
	{
		for (size_t i = 0; i < tip_table.size(); i++)
		{
			int*vlist = tip_table[i].GetAllVert();
			double *v1 = vtip_table[vlist[0]].GetCoord();
			double *v2 = vtip_table[vlist[1]].GetCoord();
			double *v3 = vtip_table[vlist[2]].GetCoord();
			double *norm = calFaceNormal(v1, v2, v3);
			tip_table[i].SetNorm(norm);
		}
		for (size_t i = 0; i < struct_table.size(); i++)
		{
			int*vlist = struct_table[i].GetAllVert();
			double *v1 = vstruct_table[vlist[0]].GetCoord();
			double *v2 = vstruct_table[vlist[1]].GetCoord();
			double *v3 = vstruct_table[vlist[2]].GetCoord();
			double *norm = calFaceNormal(v1, v2, v3);
			struct_table[i].SetNorm(norm);
		}
	}
}

double calPlaneAngle(double *n1, double *n2)
{
	double number = abs(n1[0] * n2[0] + n1[1] * n2[1] + n1[2] * n2[2]) / (sqrt(n1[0] * n1[0] + n1[1] * n1[1] + n1[2] * n1[2])*sqrt(n2[0] * n2[0] + n2[1] * n2[1] + n2[2] * n2[2]));
	return acos(number)*(180 / PI);
}

bool isSameDirection(double *n1, double *n2)
{
	return (n1[0] * n2[0] + n1[1] * n2[1] + n1[2] * n2[2]) > 0;
}

void findOverHang(double *directionNorm)
{
	for (size_t i = 0; i < face_table.size(); i++)
	{
		face_table[i].Reset();
	}
	for (size_t i = 0; i < vert_table.size(); i++)
	{
		vert_table[i].Reset();
	}
	criticalAngle = atoi(critAngle->get_text());
	//transalteModel();
	sup_table.clear();

	for (size_t i = 0; i < face_table.size(); i++)
	{
		double *facenorm = face_table[i].GetNorm();
		if (abs(calPlaneAngle(facenorm, directionNorm) - 90) > criticalAngle && !isSameDirection(facenorm, directionNorm))
		{
			face_table[i].SetAsOverHang();
		}
	}

	for (size_t i = 0; i < vert_table.size(); i++)
	{
		double y = vert_table[i].GetCoord()[1];
		vector<int> list = vert_table[i].GetVlist();
		bool IsLowest = true;
		for (size_t j = 0; j < list.size(); j++)
		{
			if (y > vert_table[list[j]].GetCoord()[1])
			{
				IsLowest = false;
			}
		}

		if (IsLowest)
		{
			vert_table[i].SetOverHang();
		}
	}
}

bool hasIntersection(int *vlist, double scanline, char t)
{
	double z1;
	double z2;
	double z3;
	if (t == 'z')
	{
		z1 = vert_table[vlist[0]].GetCoord()[2];
		z2 = vert_table[vlist[1]].GetCoord()[2];
		z3 = vert_table[vlist[2]].GetCoord()[2];
	}
	else if (t == 'x')
	{
		z1 = vert_table[vlist[0]].GetCoord()[0];
		z2 = vert_table[vlist[1]].GetCoord()[0];
		z3 = vert_table[vlist[2]].GetCoord()[0];
	}

	if (z1 > scanline && z2 > scanline && z3 > scanline) { return false; }
	if (z1 < scanline && z2 < scanline && z3 < scanline) { return false; }
	return true;;
}

double *calCross(double*p1, double*p2, double*p3)
{
	double*v1 = new double[3];
	double*v2 = new double[3];
	v1[0] = p2[0] - p1[0];
	v1[1] = p2[1] - p1[1];
	v1[2] = p2[2] - p1[2];
	v2[0] = p3[0] - p1[0];
	v2[1] = p3[1] - p1[1];
	v2[2] = p3[2] - p1[2];
	double x1 = v1[0];
	double y1 = v1[1];
	double z1 = v1[2];
	double x2 = v2[0];
	double y2 = v2[1];
	double z2 = v2[2];
	double *result = new double[3];
	result[0] = y1*z2 - z1*y2;
	result[1] = z1*x2 - x1*z2;
	result[2] = x1*y2 - y1*x2;
	return result;
}

double calDot(double *p1, double *p2)
{
	return p1[0] * p2[0] + p1[1] * p2[1] + p1[2] * p2[2];
}

double calLength(double *v)
{
	return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

bool isInFace(double x, double y, double z, int *vlist)
{
	double *A = vert_table[vlist[0]].GetCoord();
	double *B = vert_table[vlist[1]].GetCoord();
	double *C = vert_table[vlist[2]].GetCoord();
	double P[] = { x, y, z };
	
	double *vcrossw = calCross(A, C, P);
	double *vcrossu = calCross(A, C, B);

	if (calDot(vcrossw, vcrossu) < 0)
	{
		return false;
	}
	double *ucrossw = calCross(A, B, P);
	double *ucrossv = calCross(A, B, C);

	if (calDot(ucrossw, ucrossv) < 0)
	{
		return false;
	}

	double demon = calLength(ucrossv);
	double r = calLength(vcrossw) / demon;
	double t = calLength(ucrossw) / demon;

	return (r + t < 1);
}

void sampling()
{
	sup_table.clear();
	double scale = model_scale / vert_table.size() /3;
	cout << scale << endl;
	samplingDistance = atof(samplingDis->get_text())*scale;
	double minz = DBL_MAX;
	double maxz = -DBL_MAX;
	double minx = DBL_MAX;
	double maxx = -DBL_MAX;
	for (size_t i = 0; i < vert_table.size(); i++)
	{
		double x = vert_table[i].GetCoord()[0];
		double z = vert_table[i].GetCoord()[2];
		if (z < minz)
		{
			minz = z;
		}
		if (z > maxz)
		{
			maxz = z;
		}
		if (x < minx)
		{
			minx = x;
		}
		if (x > maxx)
		{
			maxx = x;
		}
	}
	for (size_t i = 0; i < face_table.size(); i++)
	{
		if (face_table[i].GetOverHange())
		{
			int *vlist = face_table[i].GetAllVert();
			for (double m = minz; m < maxz; m += samplingDistance)
			{
				if (hasIntersection(vlist, m, 'z'))
				{
					for (double n = minx; n < maxx; n += samplingDistance)
					{
						if (hasIntersection(vlist, n, 'x'))
						{
							double *v1 = vert_table[vlist[0]].GetCoord();
							double *norm = face_table[i].GetNorm();
							double d = -1.0*(norm[0] * v1[0] + norm[1] * v1[1] + norm[2] * v1[2]);
							double ycoord = -1.0*(norm[0] * n + norm[2] * m + d) / norm[1];
							if (isInFace(n, ycoord, m, vlist) &&ycoord > 0.0)
							{
								Vert *newV = new Vert(n, ycoord, m);
								newV->SetSampling();
								sup_table.push_back(*newV);
							}
						}
					}			
				}
			}
		}
	}
	nSamplingPts = sup_table.size();
}

double calDistance(double *c1, double *c2)
{
	return sqrt((c1[0] - c2[0])*(c1[0] - c2[0]) + (c1[1] - c2[1])*(c1[1] - c2[1]) + (c1[2] - c2[2])*(c1[2] - c2[2]));
}

double *getTempPoints(double *p1, double *p2)
{
	double *result = new double[6];
	double m1 = p1[1];
	double m2 = p2[1];
	double tp1[] = { p1[0], 0.0, p1[2] };
	double tp2[] = { p2[0], 0.0, p2[2] };
	double slope = abs((p2[2] - p1[2]) / (p2[0] - p1[0]));

	double n1x = m1 / (sqrt(1 + slope*slope));
	double n1z = m1*slope / (sqrt(1 + slope*slope));
	double n2x = m2 / (sqrt(1 + slope*slope));
	double n2z = m2*slope / (sqrt(1 + slope*slope));

	result[1] = result[4] = 0.0;
	if (p1[0] > p2[0])
	{
		result[0] = p1[0] - n1x;
		result[3] = p2[0] + n2x;
	}

	if (p1[0] < p2[0])
	{
		result[0] = p1[0] + n1x;
		result[3] = p2[0] - n2x;
	}

	if (p1[2] > p2[2])
	{
		result[2] = p1[2] - n1z;
		result[5] = p2[2] + n2z;
	}

	if (p1[2] < p2[2])
	{
		result[2] = p1[2] + n1z;
		result[5] = p2[2] - n2z;
	}
	return result;
}

double calHorzDis(double *p1, double *p2)
{
	return sqrt((p2[0] - p1[0])*(p2[0] - p1[0]) + (p2[2] - p1[2])*(p2[2] - p1[2]));
}

double *getNewPoint(double *p1, double *p2)
{
	double d = calHorzDis(p1, p2);
	criticalAngle = atoi(critAngle->get_text());
	double s1 = tan(criticalAngle*PI / 180);
	double s2 = tan((180 - criticalAngle)*PI / 180);

	if ((p1[1] / s1 + p2[1] / s1) < d)
	{
		//cout << "NO CONE INTERSECTION" << endl;
		return NULL;
	}
	if (p1[0] == p2[0] && p1[2] == p2[2])
	{
		//cout << "Wrong Pair!" << endl;
		return p1[1] > p2[1] ? p2 : p1;
	}
	else if (p1[2] == p2[2])
	{
		double k1, k2;
		if (p1[0] > p2[0])
		{
			k1 = p1[1] - s1*p1[0];
			k2 = p2[1] - s2*p2[0];
		}
		else
		{
			k1 = p2[1] - s1*p2[0];
			k2 = p1[1] - s2*p1[0];
		}
		double *result = new double[3];
		result[0] = (k2 - k1) / (s1 - s2);
		result[1] = (s1*k2 - s2*k1) / (s1 - s2);
		result[2] = p1[2];
		if (result[1] == 0.0)
		{
			return NULL;
		}
		return result;
	}
	else if (p1[0] == p2[0])
	{
		double k1, k2;
		if (p1[2] > p2[2])
		{
			k1 = p1[1] - s1*p1[2];
			k2 = p2[1] - s2*p2[2];
		}
		else
		{
			k1 = p2[1] - s1*p2[2];
			k2 = p1[1] - s2*p1[2];
		}
		double *result = new double[3];
		result[0] = p1[0];
		result[1] = (s1*k2 - s2*k1) / (s1 - s2);
		result[2] = (k2 - k1) / (s1 - s2);
		if (result[1] > p1[1] || result[1] > p2[1])
		{
			return NULL;
		}
		if (result[1] == 0.0)
		{
			return NULL;
		}
		return result;
	}
	else
	{
		double *tp = getTempPoints(p1, p2);
		double t = (p2[0] - p1[0]) / (tp[0] - tp[3] + p2[0] - p1[0]);
		double *result = new double[3];
		result[0] = p1[0] + t*(tp[0] - p1[0]);
		result[1] = p1[1] - p1[1] * t;
		result[2] = p1[2] + t*(tp[2] - p1[2]);

		if (result[1] > p1[1] || result[1] > p2[1])
		{
			//cout << "ERROR3" << endl;
			return p1[1] > p2[1] ? p2 : p1;
		}
		if (result[1] == 0.0)
		{
			return NULL;
		}
		return result;
	}
}

bool srtcmp(Vert v1, Vert v2)
{
	return v1.GetCoord()[1] > v2.GetCoord()[1];
}

void sortVector(vector<Vert> &v)
{
	sort(v.begin(), v.end(), srtcmp);
}

bool isDone(vector<int> v)
{
	int c = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] == -1)
		{
			c++;
		}
	}
	return c==1 || c==0;
}

int getPair(int index, vector<Vert> v, vector<int> &c)
{
	double min = DBL_MAX;
	int r = -1;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (c[i] == -1 && i!= index)
		{
			double dis = calDistance(v[index].GetCoord(), v[i].GetCoord());
			if (dis < min)
			{
				min = dis;
				r = i;
			}
		}
	}

	if (r != -1)
	{
		c[r] = 1;
		c[index] = 1;
		return r;
	}
	return -2;
}

double *getConeMeshIntersection(double *p1, double *p2, int index)
{
	int *vlist = face_table[index].GetAllVert();
	double *v1 = vert_table[vlist[0]].GetCoord();
	double *v2 = vert_table[vlist[1]].GetCoord();
	double *v3 = vert_table[vlist[2]].GetCoord();
	double *norm = face_table[index].GetNorm();
	
	double t[] = { p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2] };

	double denom = norm[0] * t[0] + norm[1] * t[1] + norm[2] * t[2];
	if (denom == 0.0)
	{
		return NULL;
	}
	else
	{
		double t2[] = { v1[0] - p1[0], v1[1] - p1[1], v1[2] - p1[2] };
		double numer = norm[0] * t2[0] + norm[1] * t2[1] + norm[2] * t2[2];
		double r = numer / denom;

		double *result = new double[3];
		result[0] = p1[0] + r*t[0];
		result[1] = p1[1] + r*t[1];
		result[2] = p1[2] + r*t[2];

		if (isInFace(result[0], result[1], result[2], vlist))
		{
			if (r >= 0 && r <= 1)
			{
				return result;
			}		
		}
		return NULL;
	}
}

void buildTree()
{
	sortVector(sup_table);
	c.clear();
	for (size_t i = 0; i < sup_table.size();i++)
	{
		c.push_back(-1);
	}

	for (size_t i = 0; i < sup_table.size(); i++)
	{
		if (isDone(c))
		{
			break;
		}
		else
		{
			int size = sup_table.size();
			if (c[i] == -1)
			{
				int p = getPair(i, sup_table, c);				
				//cout << i << " " << p << endl;
				if (p != -2)
				{
					double *newP =  getNewPoint(sup_table[i].GetCoord(), sup_table[p].GetCoord());
					sup_table[i].SetPair(p);
					sup_table[p].SetPair(-2);
					if (newP == NULL)
					{
						sup_table[i].SetChild(-10);
						sup_table[p].SetChild(-10);
					}
					else
					{
						Vert *v = new Vert(newP[0], newP[1], newP[2]);
						sup_table[i].SetChild(size);
						sup_table[p].SetChild(size);
						v->SetLevel(sup_table[i].GetLevel() +1);
						sup_table.push_back(*v);
						c.push_back(-1);
					}
				}
			}
		}
	}
}

void detectCollision()
{
	for (size_t  i = 0; i < sup_table.size(); i++)
	{
		int ch = sup_table[i].GetChild();
		if (ch >= 0)
		{
			double *cp = sup_table[ch].GetCoord();
			findBoundary(i, cp);
		}
	}
	cout << "WALL: "<< wall_table.size() << endl;
}

bool findBoundary(int index, double *p)
{
	double minD = DBL_MAX;
	double *meshInter = new double[3];
	bool hasIntersect = false;
	Vert *v = new Vert(p[0], p[1], p[2]);
	double *q = sup_table[index].GetCoord();
	if (p[0] == q[0] && p[1] == q[1] && p[2] == q[2])
	{
		return false;
	}
	if (index < nSamplingPts)
	{
		return false;
	}
	for (size_t  i = 0; i < face_table.size(); i++)
	{
		double *inter = getConeMeshIntersection(q, p, i);
		if (inter != NULL)
		{
			hasIntersect = true;
			//cout << inter[0] << " " << inter[1] << " " << inter[2] << endl;
			double cdis = calDistance(inter, sup_table[index].GetCoord());
			if (cdis < minD)
			{
				minD = cdis;
				meshInter[0] = inter[0];
				meshInter[1] = inter[1];
				meshInter[2] = inter[2];
			}	
			sup_table[index].SetEnd();
		}
	}
	
	if (sup_table[index].GetEnd())
	{
		sup_table[index].SetChild(wall_table.size());
		Vert *wv = new Vert(meshInter[0], meshInter[1], meshInter[2]);
		//cout << meshInter[0] << " " << meshInter[1] << " " << meshInter[2] << endl;
		wv->SetLevel(sup_table[index].GetLevel() + 1);
		wall_table.push_back(*wv);
	}
	return hasIntersect;
}

vector<int*> getRandomOrient()
{
	int k= atoi(kvalue->get_text());
	vector<int*> r;
	for (int i = 1; i <= k; i++)
	{
		srand(rand());
		int x = rand();
		int y = rand();
		int z = rand();
		while (x == 0)
		{
			x = rand();
		}
		while (y == 0)
		{
			y = rand();
		}
		while (z == 0)
		{
			z = rand();
		}
		int *result = new int[3];
		result[0] = x % 360;
		result[1] = y % 360;
		result[2] = z % 360;
		//cout << result[0] << " " << result[1] << " " << result[2] << endl;
		r.push_back(result);
	}
	return r;
}

double calNSupportPts(double *directionNorm)
{
	criticalAngle = atoi(critAngle->get_text());
	double totalArea = 0;
	for (size_t  i = 0; i < face_table.size(); i++)
	{
		double *facenorm = face_table[i].GetNorm();
		if (abs(calPlaneAngle(facenorm, directionNorm) - 90) > criticalAngle && !isSameDirection(facenorm, directionNorm))
		{
			int *vlist = face_table[i].GetAllVert();
			double *p1 = vert_table[vlist[0]].GetCoord();
			double *p2 = vert_table[vlist[1]].GetCoord();
			double *p3 = vert_table[vlist[2]].GetCoord();
			double area = calLength(calCross(p1, p2, p3));
			totalArea += area;
		}
	}
	return totalArea;
}

double *getRotated(double *m, double a, double b, double r)
{
	double *n = new double[3];
	n[0] = m[0] * cos(b)*cos(r) + m[1] * (cos(r)*sin(a)*sin(b) - cos(a)*sin(r)) + m[2] * (cos(a)*cos(r)*sin(b) + sin(a)*sin(r));
	n[1] = m[0] * cos(b)*sin(r) + m[1] * (cos(a)*cos(r) + sin(a)*sin(b)*sin(r)) + m[2] * (cos(a)*sin(b)*sin(r) - cos(r)*sin(a));
	n[2] = m[0] * (-sin(b)) + m[1] * cos(b)*sin(a) + m[2] * cos(a)*cos(b);
	return n;
}

void orient()
{
	UISetup();
	vector<int*> rt = getRandomOrient();
	double min = DBL_MAX;
	int index = -1;
	char *filepath = "Orientation Sampling Area.txt";
	ofstream myfile;
	myfile.open(filepath);
	for (size_t  i = 0; i < rt.size(); i++)
	{
		double m[] = { 0.0, 1.0, 0.0 };
		double a = rt[i][0] * PI / 180;
		double b = rt[i][1] * PI / 180;
		double r = rt[i][2] * PI / 180;
		double *n = getRotated(m, a, b, r);
		double cost = calNSupportPts(n);
		if (cost < min)
		{
			min = cost;
			index = i;
		}
		myfile << cost << endl;
	}
	myfile.close();
	cout << rt[index][0] << " " << rt[index][1] << " " << rt[index][2] << endl;
	for (size_t  i = 0; i < vert_table.size(); i++)
	{
		double*p = vert_table[i].GetCoord();
		double a = -1.0*rt[index][0] * PI / 180;
		double b = -1.0*rt[index][1] * PI / 180;
		double r = -1.0*rt[index][2] * PI / 180;
		double *newP = getRotated(p, a, b, r);
		vert_table[i].SetCoord(newP);
	}

	for (size_t  i = 0; i < face_table.size(); i++)
	{
		face_table[i].Reset();
	}
	hasTrans = false;
	translateModel();
	setFaceNormal(0);
}

void resumeVert()
{
	for (size_t  i = 0; i < face_table.size(); i++)
	{
		face_table[i].Reset();
	}
	vert_table.clear();
	vert_table=vert_bkp;
	sup_table.clear();
	wall_table.clear();
	hasTrans = false;
	translateModel();
	setFaceNormal(0);
}

vector<double *> getAroundPtsN(bool isTip, double thickness, double weight, double *p)
{
	double *start = new double[3];
	start[0] = p[0];
	start[1] = p[1];
	start[2] = p[2];
	if (isTip)
	{
		double scale = model_scale / vert_table.size();
		start[1] = p[1]-weight*2;
	}
	vector<double*> result;
	for (int i = 0; i < 10; i++)
	{
		double *r = new double[3];
		r[1] = start[1];
		switch (i)
		{
		case 0:
			r[0] = start[0] - weight;
			r[2] = start[2] + weight;
			break;
		case 1:
			r[0] = start[0] - weight + thickness;
			r[2] = start[2] + weight;
			break;
		case 2:
			r[0] = start[0] - weight;
			r[2] = start[2] - weight;
			break;
		case 3:
			r[0] = start[0] - weight + thickness;
			r[2] = start[2] - weight;
			break;
		case 4:
			r[0] = start[0] - weight + thickness;
			r[2] = start[2] - weight + thickness;
			break;
		case 5:
			r[0] = start[0] + weight;
			r[2] = start[2] + weight;
			break;
		case 6:
			r[0] = start[0] + weight - thickness;
			r[2] = start[2] + weight;
			break;
		case 7:
			r[0] = start[0] + weight - thickness;
			r[2] = start[2] + weight - thickness;
			break;
		case 8:
			r[0] = start[0] + weight;
			r[2] = start[2] - weight;
			break;
		case 9:
			r[0] = start[0] + weight - thickness;
			r[2] = start[2] - weight;
			break;
		}
		result.push_back(r);
	}
	return result;
}

void applyStructureN()
{
	struct_table.clear();
	vstruct_table.clear();
	tip_table.clear();
	vtip_table.clear();
	double scale = model_scale / vert_table.size() / 3;
	double weight1 = 0.0;
	double weight2 = 0.0;
	double thickness = atof(thicknesstxt->get_text());
	for (size_t i = 0; i < sup_table.size(); i++)
	{
		bool isTip = sup_table[i].IsSampling();
		double *p1 = sup_table[i].GetCoord();
		double *p2 = new double[3];
		int ch = sup_table[i].GetChild();
		weight1 = 0.017*sup_table[i].GetLevel()*scale;
		if (sup_table[i].GetEnd())
		{
			p2 = wall_table[ch].GetCoord();
			weight2 = 0.017*(sup_table[i].GetLevel()+1)*scale;
		}
		else if (ch >= 0)
		{
			p2 = sup_table[ch].GetCoord();
			weight2 = 0.017*sup_table[ch].GetLevel()*scale;
		}
		else if(sup_table[i].GetPair()==-1 || ch<0)
		{
			p2[0] = p1[0];
			p2[1] = 0.0;
			p2[2] = p1[2];
			weight2 = weight1 + 0.01;
		}
		if (calDistance(p1, p2) == 0.0)
		{
			continue;
		}
		vector<double*> newP1 = getAroundPtsN(isTip, thickness, weight1, p1);
		vector<double*> newP2 = getAroundPtsN(false, thickness, weight2, p2);
		
		if (isTip)
		{
			int s = vtip_table.size();
			Vert *v1 = new Vert(p1[0], p1[1], p1[2]);
			vtip_table.push_back(*v1);
			for (int i = 0; i < 10; i++)
			{
				double *tp = newP1[i];
				Vert *t = new Vert(tp[0], tp[1], tp[2]);
				vtip_table.push_back(*t);
			}
			Face *f0 = new Face(s, s + 2, s + 1);
			Face *f1 = new Face(s, s + 1, s + 3);
			Face *f2 = new Face(s, s + 4, s + 3);
			Face *f3 = new Face(s, s + 8, s + 4);
			Face *f4 = new Face(s, s + 10, s + 8);
			Face *f5 = new Face(s, s + 9, s + 10);
			Face *f6 = new Face(s, s + 9, s + 6);
			Face *f7 = new Face(s, s + 6, s + 7);
			Face *f8 = new Face(s, s + 7, s + 5);
			Face *f9 = new Face(s, s + 5, s + 2);
			tip_table.push_back(*f0);
			tip_table.push_back(*f1);
			tip_table.push_back(*f2);
			tip_table.push_back(*f3);
			tip_table.push_back(*f4);
			tip_table.push_back(*f5);
			tip_table.push_back(*f6);
			tip_table.push_back(*f7);
			tip_table.push_back(*f8);
			tip_table.push_back(*f9);
		}
		
		int s = vstruct_table.size();
		for (int i = 0; i < 10; i++)
		{
			double *tp = newP1[i];
			Vert *v = new Vert(tp[0], tp[1], tp[2]);
			vstruct_table.push_back(*v);
		}
		for (int i = 0; i < 10; i++)
		{
			double *tp = newP2[i];
			Vert *v = new Vert(tp[0], tp[1], tp[2]);
			vstruct_table.push_back(*v);
		}
		
		//N
		Face *f0 = new Face(s+1, s + 0, s + 2);
		Face *f1 = new Face(s + 1, s + 2, s + 4);
		Face *f2 = new Face(s + 4, s + 2, s + 3);
		Face *f3 = new Face(s + 6, s + 4, s + 3);
		Face *f4 = new Face(s + 7, s + 6, s + 3);
		Face *f5 = new Face(s + 5, s + 6, s + 7);
		Face *f6 = new Face(s + 5, s + 7, s + 9);
		Face *f7 = new Face(s + 5, s + 9, s + 8);

		Face *f8 = new Face(s + 11, s + 10, s + 12);
		Face *f9 = new Face(s + 11, s + 12, s + 14);
		Face *f10 = new Face(s + 14, s + 12, s + 13);
		Face *f11 = new Face(s + 16, s + 14, s + 13);
		Face *f12 = new Face(s + 17, s + 16, s + 13);
		Face *f13 = new Face(s + 15, s + 16, s + 17);
		Face *f14 = new Face(s + 15, s + 17, s + 19);
		Face *f15 = new Face(s + 15, s + 19, s + 18);
		//connection
		Face *f16 = new Face(s + 10, s+11, s);
		Face *f17 = new Face(s + 11, s+1, s);
		Face *f18 = new Face(s + 11, s+14, s + 1);
		Face *f19 = new Face(s + 14, s+4, s + 1);
		Face *f20 = new Face(s + 14, s+16, s + 4);
		Face *f21 = new Face(s + 16, s + 6, s + 4);
		Face *f22 = new Face(s + 16, s + 15, s + 6);
		Face *f23 = new Face(s + 15, s + 5, s + 6);
		Face *f24 = new Face(s + 15, s + 18, s + 5);
		Face *f25 = new Face(s + 18, s + 8, s + 5);
		Face *f26 = new Face(s + 18, s + 19, s + 8);
		Face *f27 = new Face(s + 19, s + 9, s + 8);
		Face *f28 = new Face(s + 19, s + 17, s + 9);
		Face *f29 = new Face(s + 17, s + 7, s + 9);
		Face *f30 = new Face(s + 17, s + 13, s + 7);
		Face *f31 = new Face(s + 13, s + 3, s + 7);
		Face *f32 = new Face(s + 13, s + 12, s + 3);
		Face *f33 = new Face(s + 12, s + 2, s + 3);
		Face *f34 = new Face(s + 12, s + 10, s + 2);
		Face *f35 = new Face(s + 10, s + 0, s + 2);
		struct_table.push_back(*f0);
		struct_table.push_back(*f1);
		struct_table.push_back(*f2);
		struct_table.push_back(*f3);
		struct_table.push_back(*f4);
		struct_table.push_back(*f5);
		struct_table.push_back(*f6);
		struct_table.push_back(*f7);
		struct_table.push_back(*f8);
		struct_table.push_back(*f9);
		struct_table.push_back(*f10);
		struct_table.push_back(*f11);
		struct_table.push_back(*f12);
		struct_table.push_back(*f13);
		struct_table.push_back(*f14);
		struct_table.push_back(*f15);
		struct_table.push_back(*f16);
		struct_table.push_back(*f17);
		struct_table.push_back(*f18);
		struct_table.push_back(*f19);
		struct_table.push_back(*f20);
		struct_table.push_back(*f21);
		struct_table.push_back(*f22);
		struct_table.push_back(*f23);
		struct_table.push_back(*f24);
		struct_table.push_back(*f25);
		struct_table.push_back(*f26);
		struct_table.push_back(*f27);
		struct_table.push_back(*f28);
		struct_table.push_back(*f29);
		struct_table.push_back(*f30);
		struct_table.push_back(*f31);
		struct_table.push_back(*f32);
		struct_table.push_back(*f33);
		struct_table.push_back(*f34);
		struct_table.push_back(*f35);
	}
	setFaceNormal(1);
}

vector<double *> getAroundPtsX(bool isTip, double thickness, double weight, double *p)
{
	double *start = new double[3];
	start[0] = p[0];
	start[1] = p[1];
	start[2] = p[2];
	if (isTip)
	{
		double scale = model_scale / vert_table.size();
		start[1] = p[1] - weight * 2;
	}
	vector<double*> result;
	for (int i = 0; i < 12; i++)
	{
		double *r = new double[3];
		r[1] = start[1];
		switch (i)
		{
		case 0:
			r[0] = start[0] - sqrt(2)*weight - thickness / 2.0;
			r[2] = start[2] - thickness / 2.0;
			break;
		case 1:
			r[0] = start[0] - sqrt(2)*weight - thickness / 2.0;
			r[2] = start[2] + thickness / 2.0;
			break;
		case 2:
			r[0] = start[0] - thickness / 2.0;
			r[2] = start[2] + thickness / 2.0;
			break;
		case 3:
			r[0] = start[0] - thickness / 2.0;
			r[2] = start[2] + sqrt(2)*weight + thickness / 2.0;
			break;
		case 4:
			r[0] = start[0] + thickness / 2.0;
			r[2] = start[2] + sqrt(2)*weight + thickness / 2.0;
			break;
		case 5:
			r[0] = start[0] + thickness / 2.0;
			r[2] = start[2] + thickness / 2.0;
			break;
		case 6:
			r[0] = start[0] + sqrt(2)*weight + thickness / 2.0;
			r[2] = start[2] + thickness / 2.0;
			break;
		case 7:
			r[0] = start[0] + sqrt(2)*weight + thickness / 2.0;
			r[2] = start[2] - thickness / 2.0;
			break;
		case 8:
			r[0] = start[0] + thickness / 2.0;
			r[2] = start[2] - thickness / 2.0;
			break;
		case 9:
			r[0] = start[0] + thickness / 2.0;
			r[2] = start[2] - sqrt(2)*weight - thickness / 2.0;
			break;
		case 10:
			r[0] = start[0] - thickness / 2.0;
			r[2] = start[2] - sqrt(2)*weight - thickness / 2.0;
			break;
		case 11:
			r[0] = start[0] + thickness / 2.0;
			r[2] = start[2] + thickness / 2.0;
			break;
		}
		result.push_back(r);
	}
	return result;
}

void applyStructureX()
{
	struct_table.clear();
	vstruct_table.clear();
	tip_table.clear();
	vtip_table.clear();
	double scale = model_scale / vert_table.size() / 3;
	double weight1 = 0.0;
	double weight2 = 0.0;
	double thickness = atof(thicknesstxt->get_text());
	for (size_t i = 0; i < sup_table.size(); i++)
	{
		bool isTip = sup_table[i].IsSampling();
		double *p1 = sup_table[i].GetCoord();
		double *p2 = new double[3];
		int ch = sup_table[i].GetChild();
		weight1 = 0.017*sup_table[i].GetLevel()*scale;
		if (sup_table[i].GetEnd())
		{
			p2 = wall_table[ch].GetCoord();
			weight2 = 0.017*(sup_table[i].GetLevel() + 1)*scale;
		}
		else if (ch >= 0)
		{
			p2 = sup_table[ch].GetCoord();
			weight2 = 0.017*sup_table[ch].GetLevel()*scale;
		}
		else if (sup_table[i].GetPair() == -1 || ch<0)
		{
			p2[0] = p1[0];
			p2[1] = 0.0;
			p2[2] = p1[2];
			weight2 = weight1 + 0.01;
		}
		if (calDistance(p1, p2) == 0.0)
		{
			continue;
		}
		vector<double*> newP1 = getAroundPtsX(isTip, thickness, weight1, p1);
		vector<double*> newP2 = getAroundPtsX(false, thickness, weight2, p2);

		if (isTip)
		{
			int s = vtip_table.size();
			Vert *v1 = new Vert(p1[0], p1[1], p1[2]);
			vtip_table.push_back(*v1);
			for (int i = 0; i < 12; i++)
			{
				double *tp = newP1[i];
				Vert *t = new Vert(tp[0], tp[1], tp[2]);
				vtip_table.push_back(*t);
			}

			Face *f0 = new Face(s, s+2, s + 1);
			Face *f1 = new Face(s, s+8, s + 7);
			Face *f2 = new Face(s, s+11, s + 10);
			Face *f3 = new Face(s, s+5, s + 4);
			Face *f4 = new Face(s, s+3, s + 2);
			Face *f5 = new Face(s, s+1, s + 12);
			Face *f6 = new Face(s, s + 4, s + 3);
			Face *f7 = new Face(s, s + 6, s + 5);
			Face *f8 = new Face(s, s + 7, s + 6);
			Face *f9 = new Face(s, s + 9, s + 8);
			Face *f10 = new Face(s, s + 10, s + 9);
			Face *f11 = new Face(s, s + 12, s + 10);
			tip_table.push_back(*f0);
			tip_table.push_back(*f1);
			tip_table.push_back(*f2);
			tip_table.push_back(*f3);
			tip_table.push_back(*f4);
			tip_table.push_back(*f5);
			tip_table.push_back(*f6);
			tip_table.push_back(*f7);
			tip_table.push_back(*f8);
			tip_table.push_back(*f9);
			tip_table.push_back(*f10);
			tip_table.push_back(*f11);
		}

		int s = vstruct_table.size();
		for (int i = 0; i < 12; i++)
		{
			double *tp = newP1[i];
			Vert *v = new Vert(tp[0], tp[1], tp[2]);
			vstruct_table.push_back(*v);
		}
		for (int i = 0; i < 12; i++)
		{
			double *tp = newP2[i];
			Vert *v = new Vert(tp[0], tp[1], tp[2]);
			vstruct_table.push_back(*v);
		}

		//X
		Face *f0 = new Face(s, s + 2, s + 1);
		Face *f1 = new Face(s + 11, s + 2, s);
		Face *f2 = new Face(s + 5, s + 3, s + 2);
		Face *f3 = new Face(s + 4, s + 3, s + 5);
		Face *f4 = new Face(s + 8, s + 6, s + 5);
		Face *f5 = new Face(s + 7, s + 6, s + 8);
		Face *f6 = new Face(s + 11, s + 9, s + 8);
		Face *f7 = new Face(s + 10, s + 9, s + 11);
		Face *f8 = new Face(s + 11, s + 5, s + 2);
		Face *f9 = new Face(s + 8, s + 5, s + 11);

		Face *f10 = new Face(s + 12, s + 14, s + 13);
		Face *f11 = new Face(s + 23, s + 14, s+12);
		Face *f12 = new Face(s + 17, s + 15, s + 14);
		Face *f13 = new Face(s + 16, s + 15, s + 17);
		Face *f14 = new Face(s + 20, s + 18, s + 17);
		Face *f15 = new Face(s + 19, s + 18, s + 20);
		Face *f16 = new Face(s + 23, s + 21, s + 20);
		Face *f17 = new Face(s + 22, s + 21, s + 23);
		Face *f18 = new Face(s + 23, s + 17, s + 14);
		Face *f19 = new Face(s + 20, s + 17, s + 23);
		//connection
		Face *f20 = new Face(s, s + 13, s + 12);
		Face *f21 = new Face(s + 1, s + 13, s);
		Face *f22 = new Face(s + 1, s + 14, s + 13);
		Face *f23 = new Face(s + 2, s + 14, s + 1);
		Face *f24 = new Face(s + 2, s + 15, s + 14);
		Face *f25 = new Face(s + 3, s + 15, s + 2);
		Face *f26 = new Face(s + 3, s + 16, s + 15);
		Face *f27 = new Face(s + 4, s + 16, s + 3);
		Face *f28 = new Face(s + 4, s + 17, s + 16);
		Face *f29 = new Face(s + 5, s + 17, s + 4);
		Face *f30 = new Face(s + 5, s + 18, s + 17);
		Face *f31 = new Face(s + 6, s + 18, s + 5);
		Face *f32 = new Face(s + 6, s + 19, s + 18);
		Face *f33 = new Face(s + 7, s + 19, s + 6);
		Face *f34 = new Face(s + 7, s + 20, s + 19);
		Face *f35 = new Face(s + 8, s + 20, s + 7);
		Face *f36 = new Face(s + 8, s + 21, s + 20);
		Face *f37 = new Face(s + 9, s + 21, s + 8);
		Face *f38 = new Face(s + 9, s + 22, s + 21);
		Face *f39 = new Face(s + 10, s + 22, s + 9);
		Face *f40 = new Face(s + 10, s + 23, s + 22);
		Face *f41 = new Face(s + 11, s + 23, s + 10);
		Face *f42 = new Face(s, s + 23, s + 12);
		Face *f43 = new Face(s + 11, s + 23, s);
		Face *f44 = new Face(s + 11, s + 14, s + 23);
		Face *f45 = new Face(s + 2, s + 14, s + 11);
		Face *f46 = new Face(s + 2, s + 17, s + 14);
		Face *f47 = new Face(s + 5, s + 17, s + 2);
		Face *f48 = new Face(s + 5, s + 20, s + 17);
		Face *f49 = new Face(s + 8, s + 20, s + 5);
		Face *f50 = new Face(s + 8, s + 23, s + 20);
		Face *f51 = new Face(s + 11, s + 23, s + 8);
		struct_table.push_back(*f0);
		struct_table.push_back(*f1);
		struct_table.push_back(*f2);
		struct_table.push_back(*f3);
		struct_table.push_back(*f4);
		struct_table.push_back(*f5);
		struct_table.push_back(*f6);
		struct_table.push_back(*f7);
		struct_table.push_back(*f8);
		struct_table.push_back(*f9);
		struct_table.push_back(*f10);
		struct_table.push_back(*f11);
		struct_table.push_back(*f12);
		struct_table.push_back(*f13);
		struct_table.push_back(*f14);
		struct_table.push_back(*f15);
		struct_table.push_back(*f16);
		struct_table.push_back(*f17);
		struct_table.push_back(*f18);
		struct_table.push_back(*f19);
		struct_table.push_back(*f20);
		struct_table.push_back(*f21);
		struct_table.push_back(*f22);
		struct_table.push_back(*f23);
		struct_table.push_back(*f24);
		struct_table.push_back(*f25);
		struct_table.push_back(*f26);
		struct_table.push_back(*f27);
		struct_table.push_back(*f28);
		struct_table.push_back(*f29);
		struct_table.push_back(*f30);
		struct_table.push_back(*f31);
		struct_table.push_back(*f32);
		struct_table.push_back(*f33);
		struct_table.push_back(*f34);
		struct_table.push_back(*f35);
		struct_table.push_back(*f36);
		struct_table.push_back(*f37);
		struct_table.push_back(*f38);
		struct_table.push_back(*f39);
		struct_table.push_back(*f40);
		struct_table.push_back(*f41);
		struct_table.push_back(*f42);
		struct_table.push_back(*f43);
		struct_table.push_back(*f44);
		struct_table.push_back(*f45);
		struct_table.push_back(*f46);
		struct_table.push_back(*f47);
		struct_table.push_back(*f48);
		struct_table.push_back(*f49);
		struct_table.push_back(*f50);
		struct_table.push_back(*f51);
	}
	setFaceNormal(1);
}

void evaluate()
{
	double m1[3] = { 0.5, 0.5, 0.5 };
	double m2[3] = { 0.5, 0.0, 0.5 };
	vector<double*> newP1 = getAroundPtsX(false , 0.1, 0.4, m1);
	vector<double*> newP2 = getAroundPtsX(false, 0.1, 0.5, m2);
	

	if (!evaluationMode)
	{
		double newcost = 0.0;
		double oldcost = 0.0;
		for (size_t i = 0; i < tip_table.size(); i++)
		{
			int *vlist = tip_table[i].GetAllVert();
			double *p1 = vtip_table[vlist[0]].GetCoord();
			double *p2 = vtip_table[vlist[1]].GetCoord();
			double *p3 = vtip_table[vlist[2]].GetCoord();
			double vol = calLength(calCross(p1, p2, p3)) / 2.0;
			newcost += vol;
		}
		for (size_t i = 0; i < struct_table.size(); i++)
		{
			int *vlist = struct_table[i].GetAllVert();
			double *p1 = vstruct_table[vlist[0]].GetCoord();
			double *p2 = vstruct_table[vlist[1]].GetCoord();
			double *p3 = vstruct_table[vlist[2]].GetCoord();
			double vol = calLength(calCross(p1, p2, p3)) / 2.0;
			newcost += vol;
		}
		for (int i = 0; i < nSamplingPts; i++)
		{
			double scale = model_scale / vert_table.size();
			double radius = 0.05 *scale;
			double vol = PI*radius*radius*sup_table[i].GetCoord()[1];
			oldcost += vol;
		}
		double percent = (oldcost - newcost) / oldcost * 100;
		newCost->set_text(to_string(newcost));
		origCost->set_text(to_string(oldcost));
		savePercent->set_text(to_string(percent));
	}	
	else
	{
		double cost = 0.0;
		for (size_t i = 0; i < face_table.size(); i++)
		{
			if (face_table[i].GetSup())
			{
				int *vlist = face_table[i].GetAllVert();
				double *p1 = vert_table[vlist[0]].GetCoord();
				double *p2 = vert_table[vlist[1]].GetCoord();
				double *p3 = vert_table[vlist[2]].GetCoord();
				double vol = calLength(calCross(p1, p2, p3)) / 2.0;
				cost += vol;
			}
		}

		newCost->set_text(to_string(cost));
		origCost->set_text("N/A");
		savePercent->set_text("N/A");
	}
	double scale = model_scale / vert_table.size();
	cout << scale << endl;
}

void UISetup()
{
	if (evaluationMode == 1)
	{
		exptSup->disable();
		disSup->disable();
		disSamp->disable();
		disOverH->disable();
		kvalue->disable();
		critAngle->disable();
		samplingDis->disable();
		savebtn->disable();
		orientbtn->disable();
		resumeorientbtn->disable();
		analysisbtn->disable();
		samplebtn->disable();
		buildbtn->disable();
		collisionbtn->disable();
		addStructurebtn->disable();
		newCost->set_text("0.0");
		origCost->set_text("0.0");
		savePercent->set_text("0.0");
		thicknesstxt->disable();
	}
	else
	{
		exptSup->enable();
		disSup->enable();
		disSamp->enable();
		disOverH->enable();
		kvalue->enable();
		critAngle->enable();
		samplingDis->enable();
		savebtn->enable();
		orientbtn->enable();
		resumeorientbtn->enable();
		analysisbtn->enable();
		samplebtn->enable();
		buildbtn->enable();
		collisionbtn->enable();
		addStructurebtn->enable();
		newCost->set_text("0.0");
		origCost->set_text("0.0");
		savePercent->set_text("0.0");
		thicknesstxt->enable();
	}
}