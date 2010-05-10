// SulGeomHeightField.h

#ifndef __SULGEOMHEIGHTFIELD_H__
#define __SULGEOMHEIGHTFIELD_H__

#include "SulGeomBase.h"
#include "SulTypes.h"
#include "SulArray2D.h"

class CSulGeomHeightField : public CSulGeomBase
{
public:
	void			Create( CSulArray2D<float>* pArray2D, float fScaleX=1.0f, float fScaleY=1.0f, float fScaleH=1.0f );

	osg::Vec3		GetNormal( Sigma::int32 x, Sigma::int32 y ) const;
	float			GetHeight( Sigma::int32 x, Sigma::int32 y ) const;

private:
	osg::ref_ptr<osg::Vec3Array>	m_rVerts;
	Sigma::uint32					m_w;
	Sigma::uint32					m_h;
	float							m_fScaleX;
	float							m_fScaleY;
	float							m_fScaleH;
};

#endif // __SULGEOMHEIGHTFIELD_H__
