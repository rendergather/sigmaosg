// SulClipLines.h

#ifndef __SULCLIPLINES_H__
#define __SULCLIPLINES_H__

#include "SulTypes.h"
#include <osg/plane>

class CSulClipLines
{
public:
	CSulClipLines( const Sigma::VEC_LINESEGMENT& lines, const osg::Plane& plane );

	const Sigma::VEC_LINESEGMENT& getLinesList();

	Sigma::uint32 getLineCount();

private:
	int		testVert( const osg::Vec3& v );
	void	process();

private:
	osg::Plane				m_plane;
	Sigma::VEC_LINESEGMENT	m_vecLinesIn;
	Sigma::VEC_LINESEGMENT	m_vecLines;
};

#endif // __SULCLIPLINES_H__