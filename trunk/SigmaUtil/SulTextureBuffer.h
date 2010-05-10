// SulTextureBuffer.h

#ifndef __SULTEXTUREBUFFER_H__
#define __SULTEXTUREBUFFER_H__

#include "SulTypes.h"
#include <osg/referenced>
#include <osg/texture2d>

class CSulTextureBuffer : public osg::Referenced
{
private:
	typedef std::vector< osg::ref_ptr<osg::Texture2D> >	VEC_TEXTURE;

public:
					CSulTextureBuffer( Sigma::uint32 texWidth, Sigma::uint32 texHeight, Sigma::uint32 numBuffers=2 );

	void			setIn( CSulTextureBuffer* texBuf );
	void			setIn( osg::Texture2D* texIn );
	void			setOut( CSulTextureBuffer* texOut );
	void			setOut( osg::Texture2D* texOut );

	osg::Texture2D*	getIn();
	osg::Texture2D*	getOut();

	void			swap();

private:
	osg::Texture2D* createTexture( unsigned short w, unsigned short h );

private:
	VEC_TEXTURE						m_vecTex;
	osg::ref_ptr<osg::Texture2D>	m_texIn;
	osg::ref_ptr<osg::Texture2D>	m_texOut;
	Sigma::uint32					m_numBuf;
	Sigma::uint32					m_curBuf;
	GLint							m_texFormatInternal;
	GLint							m_texFormatSource;
	GLenum							m_texSourceType;
};

#endif // __SULTEXTUREBUFFER_H__