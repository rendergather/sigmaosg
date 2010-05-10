// SulExtractGeometry.h

#ifndef __SULEXTRACTGEOMETRY_H__
#define __SULEXTRACTGEOMETRY_H__

#include "SulTypes.h"
#include "SulFuncExtractor.h"
#include <osg/geode>
#include <osg/TemplatePrimitiveFunctor>

class CSulExtractGeometry : public osg::NodeVisitor
{
public:
 	CSulExtractGeometry() : 
		NodeVisitor( NodeVisitor::TRAVERSE_ALL_CHILDREN ) 
	{
	}

    virtual void apply( osg::Geode &geode ) 
	{
		int drawCount = geode.getNumDrawables();

		for ( int i=0; i<drawCount; i++ )
		{	
			osg::Drawable* p = geode.getDrawable(i);
			osg::TemplatePrimitiveFunctor<CSulFuncExtractor> functor;
			p->accept(functor);

			const Sigma::VEC_LINESEGMENT& src = functor.getLineSegmentList();

			Sigma::VEC_LINESEGMENT::const_iterator iS;
			Sigma::VEC_LINESEGMENT::const_iterator iE;
			iS = src.begin();
			iE = src.end();
			std::copy( iS, iE, std::back_inserter(m_vecLineSegment) );

			const Sigma::VEC_TRI& srcTri = functor.getTriList();
			Sigma::VEC_TRI::const_iterator iTriS;
			Sigma::VEC_TRI::const_iterator iTriE;
			iTriS = srcTri.begin();
			iTriE = srcTri.end();
			std::copy( iTriS, iTriE, std::back_inserter(m_vecTri) );
		}

		// continue traversing through the graph
        traverse( geode );
	}

	const Sigma::VEC_LINESEGMENT& getLineSegmentList() const
	{
		return m_vecLineSegment;
	}

	const Sigma::VEC_TRI& getTriList() const
	{
		return m_vecTri;
	}

private:
	Sigma::VEC_LINESEGMENT	m_vecLineSegment;
	Sigma::VEC_TRI m_vecTri;
};

#endif // __SULEXTRACTGEOMETRY_H__