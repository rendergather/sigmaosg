// SulCloudPlane2.cpp

#include "stdafx.h"
#include "SulCloudPlane.h"
#include <osgDB/FileUtils>
#include <iostream>

CSulCloudPlane::CSulCloudPlane( float size, float height ) :
CSulGeomQuad( size, size )
{

}

void CSulCloudPlane::createDrawable()
{
	// create geom with has a osg::TexMat
	osg::ref_ptr<osg::TexMat> rTexMat = new osg::TexMat;
	m_rCloudScrollTexture= new CCloudScrollTexture( rTexMat, getWidth() );
	m_rCloudScrollTexture->setUseDisplayList( false );
	setDrawable( m_rCloudScrollTexture );
	create();

	bool bRet;

	osg::ref_ptr< osg::Shader > vertexShader = new osg::Shader();
    vertexShader->setType( osg::Shader::VERTEX );
    bRet = vertexShader->loadShaderSourceFromFile( osgDB::findDataFile("shaders/clouds.vert") );
	assert( bRet );

	osg::ref_ptr< osg::Shader > fragShader = new osg::Shader();
    fragShader->setType( osg::Shader::FRAGMENT );
    bRet = fragShader->loadShaderSourceFromFile( osgDB::findDataFile("shaders/clouds.frag") );
	assert( bRet );

	osg::ref_ptr< osg::Program > program = new osg::Program();
    program->addShader( vertexShader.get() );
	program->addShader( fragShader.get() );

	osg::ref_ptr<osg::StateSet> ss = getDrawable()->getOrCreateStateSet();
	ss->setAttribute( program.get(), osg::StateAttribute::ON );
}

void CSulCloudPlane::setSize( float s )
{
	setWidth( s );
	setHeight( s );
	m_rCloudScrollTexture->setPlaneSize( s );
}

void CSulCloudPlane::setWind( float x, float y )
{
	m_rCloudScrollTexture->setWind( x, y );
}