#ifndef __MYBOUNDINGOBJECTCLASS_H_
#define __MYBOUNDINGOBJECTCLASS_H_

#include "RE\ReEng.h"

class MyBoundingObjectClass
{
	matrix4 m_m4ToWorld = IDENTITY_M4; //Matrix that will take us from local to world coordinate
	vector3 m_v3Center = vector3(0.0f); //Will store the center point of the box Class
	vector3 m_v3Min = vector3(0.0f); //Will store the minimum vector of the box Class
	vector3 m_v3Max = vector3(0.0f); //Will store the maximum vector of the box Class

	vector3 m_v3CenterG = vector3(0.0f); //Will store the center point of the box Class
	vector3 m_v3MinG = vector3(0.0f); //Will store the minimum vector of the box Class
	vector3 m_v3MaxG = vector3(0.0f); //Will store the maximum vector of the box Class

	vector3 m_v3HalfWidth = vector3(0.0f);//Will store half the size of all sides
	vector3 m_v3HalfWidthG = vector3(0.0f);//Will store half the size of all sides

	MeshManagerSingleton* m_pMeshMngr = nullptr; //singleton pointer of the mesh manager

public:
	/*
	MyBoundingObjectClass
	USAGE: Constructor
	ARGUMENTS: ---
	OUTPUT: class object
	*/
	MyBoundingObjectClass(std::vector<vector3> a_lVectorList);
	/*
	MyBoundingObjectClass
	USAGE: Copy Constructor
	ARGUMENTS: class object to copy
	OUTPUT: class object instance
	*/
	MyBoundingObjectClass(MyBoundingObjectClass const& other);
	/*
	operator=
	USAGE: Copy Assignment Operator
	ARGUMENTS: class object to copy
	OUTPUT: ---
	*/
	MyBoundingObjectClass& operator=(MyBoundingObjectClass const& other);
	/*
	~MyBoundingObjectClass
	USAGE: Destructor
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	~MyBoundingObjectClass(void);

	/*
	Swap
	USAGE: Changes object contents for other object's
	ARGUMENTS:
	other -> object to swap content from
	OUTPUT: ---
	*/
	void Swap(MyBoundingObjectClass& other);

	/*
	SetToWorldMatrix
	USAGE: Sets the Bounding Box into world coordinates
	ARGUMENTS:
	matrix4 a_m4ToWorld -> Model to World matrix
	OUTPUT: ---
	*/
	void SetModelMatrix(matrix4 a_m4ToWorld);

	/*
	GetToWorldMatrix
	USAGE: Gets the Bounding Box into world coordinates
	ARGUMENTS:---
	OUTPUT: matrix4 -> Model to World matrix
	*/
	matrix4 GetModelMatrix(void);

	/*
	GetCenter
	USAGE: Gets the Bounding Box's center in local coordinates
	ARGUMENTS: ---
	OUTPUT: vector3 -> Center's of the box in local coordinates
	*/
	vector3 GetCenterLocal(void);

	/*
	GetCenterGlobal
	USAGE: Gets the Bounding Box's center in global coordinates
	ARGUMENTS: ---
	OUTPUT: vector3 -> Center's of the box in global coordinates
	*/
	vector3 GetCenterGlobal(void);

	/*
	GetHalfWidth
	USAGE: Gets the Bounding Box sizes for all sides (divided in half)
	ARGUMENTS: ---
	OUTPUT: vector3 -> HalfWidth Vector
	*/
	vector3 GetHalfWidth(void);

	/*
	GetHalfWidthG
	USAGE: Gets the Bounding Box sizes for all sides (divided in half) reoriented
	ARGUMENTS: ---
	OUTPUT: vector3 -> HalfWidth Vector
	*/
	vector3 GetHalfWidthG(void);

	/*
	USAGE: Asks if there is a collision with another Bounding Box Object
	ARGUMENTS:
	MyBoundingObjectClass* const a_pOther -> Other object to check collision with
	OUTPUT: bool -> check of the collision
	*/
	bool IsColliding(MyBoundingObjectClass* const a_pOther);

	/*
	USAGE: Adds the bounding box to the render list
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void AddToRenderList(void);

private:
	/*
	Release
	USAGE: Deallocates member fields
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void Release(void);
	/*
	Init
	USAGE: Allocates member fields
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void Init(void);
};

#endif

