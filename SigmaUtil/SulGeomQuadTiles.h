// SulGeomQuadTiles.h

#ifndef __SULGEOMQUADTILES_H__
#define __SULGEOMQUADTILES_H__

#include "SulGeomBase.h"
#include "SulTypes.h"

class CSulGeomQuadTiles : public CSulGeomBase
{
public:
	enum EPLANE
	{
		PLANE_XY,
		PLANE_XZ
	};

public:
	CSulGeomQuadTiles( 
		const osg::Vec3& vCenter, 
		float w=1.0f, float h=1.0f, 
		Sigma::uint32 tileX=3, Sigma::uint32 tileY=3, 
		bool bFadeEdges=true,
		EPLANE ePlane=PLANE_XY );

	Sigma::uint32 getTileX();
	Sigma::uint32 getTileY();

	float getWidth();
	float getHeight();

protected:
	virtual void createDrawable();

	void createTiles();

private:
	osg::Vec2Array* m_texCoords;
	osg::Vec4Array* m_colors;

	osg::Vec3 m_vCenter;
	float	m_w;
	float	m_h;						// total width and height with all quads
	Sigma::uint32	m_tileX;
	Sigma::uint32	m_tileY;					// number of tiles x and y with in w and h
	bool	m_bFadeEdges;
	EPLANE	m_ePlane;
};

#endif // __SULGEOMQUADTILES_H__