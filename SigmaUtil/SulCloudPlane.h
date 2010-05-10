// SulCloudPlane2.h

#ifndef __SULCLOUDPLANE2_H__
#define __SULCLOUDPLANE2_H__

#include "SulGeomQuad.h"
#include "SulCloudScrollTexture.h"

class CSulCloudPlane : public CSulGeomQuad
{
public:
					CSulCloudPlane( float size, float height );

	void			setSize( float s );

	void			setWind( float x, float y );

protected:
	virtual void	createDrawable();

private:
	osg::ref_ptr<CCloudScrollTexture>	m_rCloudScrollTexture;
	float m_size;
	float m_height;
};

#endif // __SULCLOUDPLANE2_H__