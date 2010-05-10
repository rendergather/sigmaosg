// SulGeomLine.h

#ifndef __SULGEOMLINE_H__
#define __SULGEOMLINE_H__

#include "SulGeomBase.h"
#include <osg/linesegment>

class CSulGeomLine : public CSulGeomBase
{
public:
				CSulGeomLine( const osg::LineSegment& line );

				CSulGeomLine( const osg::Vec3& v0, const osg::Vec3& v1 );

protected:
	void		createDrawable();

private:
	osg::Vec3	m_v0;
	osg::Vec3	m_v1;
};

#endif // __SULGEOMLINE_H__