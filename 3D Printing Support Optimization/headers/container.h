#ifndef CONTAINER_INCLUDED
#define CONTAINER_INCLUDED
#include <vector>
using namespace std;

class Vert
{
private:
	double *coord;
	bool overhang;
	int pair;
	int child;
	vector<int> vlist;
	bool end;
	bool splpt;
	int level;
	
public:
	Vert() {}
	Vert(double x, double y, double z)
	{
		coord = new double[3];
		coord[0] = x;
		coord[1] = y;
		coord[2] = z;
		overhang = false;
		pair = -1;
		child = -1;
		end = false;
		splpt = false;
		level = 1;
	}
	//Set
	void SetLevel(int l) { level = l; }
	void SetEnd() { end = true; }
	bool GetEnd() { return end; }
	void SetSampling() { splpt = true; }
	void SetCoord(double *n) { coord[0] = n[0]; coord[1] = n[1]; coord[2] = n[2]; }
	void AddVert(int n) { vlist.push_back(n); }
	void SetPair(int p) 
	{
		pair = p;
	}
	void SetChild(int n) { child = n; }
	void Reset() { overhang = false; }
	void SetOverHang() { overhang = true; }
	void TransalteX(double d) { coord[0] += d; }
	void TransalteY(double d) { coord[1] += d; }
	void TransalteZ(double d) { coord[2] += d; }
	//Get
	vector<int> GetVlist() { return vlist; }
	bool GetOverHang(){return overhang;}
    double *GetCoord(){return coord;}
	int GetPair() { return pair; }
	int GetChild() { return child; }
	bool IsSampling() { return splpt; }
	int GetLevel() { return level; }
};

class Face
{
private:
    int *vlist;
    double *norm;
	bool overhang;
	bool sup;

public:
    Face(){}
    Face(int v1, int v2, int v3)
    {
        vlist=new int[3];
        vlist[0]=v1;
        vlist[1]=v2;
        vlist[2]=v3;
		overhang = false;
		sup = false;
    }
	//Set
	void SetSup() { sup = true; }
	void Reset() { overhang = false; }
	void SetAsOverHang() { overhang = true; }
	void SetNorm(double *n_norm){norm =n_norm;}
	//Get
    int *GetAllVert(){return vlist;}
    double *GetNorm(){return norm;}
	bool GetOverHange() { return overhang; }
	bool GetSup() { return sup; }
};


#endif // CONTAINER_INCLUDED
