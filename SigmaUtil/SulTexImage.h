// SulTexImage.h

#ifndef __SULTEXIMAGE_H__
#define __SULTEXIMAGE_H__

#include "SulArray2D.h"
#include <osg/Referenced>
#include <osg/Texture2D>

class CSulTexImage : public osg::Referenced
{
public:
						CSulTexImage( Sigma::uint32 w, Sigma::uint32 h );

	Sigma::uint32		GetWidth();
	Sigma::uint32		GetHeight();

	osg::Texture2D*		getTexture();

	void				Set( float x, float y, float v );

	void				Process();

private:
	osg::ref_ptr<CSulArray2D<Sigma::uint8>>	m_rData;
	osg::ref_ptr<osg::Texture2D>			m_rTex;
	Sigma::uint32							m_w;
	Sigma::uint32							m_h;
};

#endif // __SULTEXIMAGE_H__