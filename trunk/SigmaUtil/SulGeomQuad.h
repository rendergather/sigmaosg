// SulGeomQuad.h

#ifndef __SULGEOMQUAD_H__
#define __SULGEOMQUAD_H__

#include "SulExport.h"
#include "SulGeomBase.h"
#include "SulTypes.h"
#include <osg/ref_ptr>
#include <osg/Vec3>
#include <osg/texture2d>

// FIXME: should be able to choose between vertice colors or all_over_colors

class SUL_EXPORT CSulGeomQuad : public CSulGeomBase
{
public:
	enum EPLANE
	{
		PLANE_XY,
		PLANE_XZ
	};

public:
									CSulGeomQuad( float w=1.0f, float h=1.0f, EPLANE ePlane=PLANE_XY );
									CSulGeomQuad( const osg::Vec3& vCenter, float w=1.0f, float h=1.0f, EPLANE ePlane=PLANE_XY );

	// these 2 methods should be private/protected										
	void							create();
	void							Create( const osg::Vec3& vCenter, float w=1.0f, float h=1.0f, EPLANE ePlane=PLANE_XY );

	void							setColor( float r, float g, float b, float a );
	const osg::Vec4&				getColor( Sigma::uint32 index );

	void							setTexture( osg::Image* pImage, GLint internalFormat=GL_RGB );
	void							setTexture( osg::Texture2D* pTex );

	osg::Texture2D*					getTexture();

	void							setUV( float uv );
	void							setUV( float u, float v );

	void							setWidth( float w );
	void							setHeight( float h );

	float							getWidth();
	float							getHeight();

protected:
	void							createDrawable();

private:
	void							calcVertPositions();

private:
	osg::ref_ptr<osg::Texture2D>	m_rTex;
	osg::ref_ptr<osg::Vec4Array>	m_rColors;
	osg::ref_ptr<osg::Vec3Array>	m_rVerts;
	osg::ref_ptr<osg::Vec2Array>	m_rUV;
	osg::Vec3						m_vCenter;
	float							m_w;
	float							m_h;
	EPLANE							m_ePlane;
};

#endif // __SULGEOMQUAD_H__