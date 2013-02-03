/*
 
 oF marching cubes implementation by andre sier
 Marching cubes implementation after Paul Bourke polygonize voxel.
 http://paulbourke.net/geometry/polygonise/
 
 201207 - of version
 201004 - processing version
 
 code released under http://www.gnu.org/licenses/lgpl-3.0.txt
 copyright 2012, Andr� Sier
 http://s373.net
 
 
 */


#pragma once

#include "ofMain.h"
#include "mTables.h"
#include "mTriangle.h"
#include "mGridCell.h"
#include <iostream>
#include <fstream>

using namespace std;

class ofxMarchingCubes;
class ofxMarchingCubes {
public:			
	ofxMarchingCubes();
	~ofxMarchingCubes();
		
	void setup(const float sx, const float sy, const float sz, const int x, const int y,const  int z);
	void setWorldDim(const float x,const  float y, const float z);
	void setWorldDim(const ofPoint &dim);
	void initResolution(const int x, const int y, const int z);
	string& getinfo();
	
	void clear();
	void addIsoPoint(const ofPoint &ptpos, const float ptval);
	void addIsoPoint(const int idx, const float ptval);
	void addCube(const ofPoint &pos, const ofPoint &dim, const float ptval);
	void addCube(const int centerx, const int centery, const int centerz,
				 const int dimx, const int dimy, const int dimz, const float ptval);
	void addBall(const ofPoint &pos, const ofPoint &dim, const float ptforce);
	void addBall(const int centerx, const int centery, const int centerz,
				 const int dimx, const int dimy, const int dimz, const float ptval);
	void zeroData();
	void setRndData(const float mn, const float mx);
	void setRndData(const float mx);
	
	void setData(const vector <float> &d);
	void addData(const vector <float> &d);
	void multData(const float d);
	void normalizeDataTo(const float val);
	void dataInvert();
	void dataSubs(const float v);
	vector <float> & getData();

	void setDataXY(const vector <float> &d);
	void addDataXY(const vector <float> &d);
	void setDataZSpeed(const float speed);
	void updateDataZspeed();
	
	void polygoniseData();
	bool isEmpty();
	void checkMinMax();
	
	void draw();
	void drawnormals(const float s);
	
	void readStl(const string &fn);
	void saveStl(const string &fn);
	void readBinaryStl(const string &fn);
	void saveBinaryStl(const string &fn);
//	void readAsciiStl(string fn);
//	void saveAsciiStl(string fn);
	
private:	
	 int Polygonize(const mGridCell grid, const  float isolevel, vector <mTriangle> &triangles);
	 int getIndex(const ofPoint &ptpos);
	ofVec3f VertexInterp(const float isolevel, const ofVec3f &p1, const ofVec3f &p2, const float valp1, const float valp2);	
	
public:		
	mGridCell grid;
	float isolevel;
	vector <mTriangle> triangles;
	vector <float> data;
	vector<mTriangle> trilist;
	int ntri;
	int gx, gy, gz, numxyz, gxgy;
	float themin, themax;
	bool invertnormals;
	bool closesides;
	
	ofPoint worlddim, worldstride, worldcenter, datastride;
	string info, header;
	
	int	mcZhead, mcZMax;
	float mcZheadf, mcZheadSpeed;
	

};