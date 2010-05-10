// SulGuiXml.h

#ifndef __SULGUIXML_H__
#define __SULGUIXML_H__

#include "SulXmlParser.h"

class CSulGuiXml : public CSulXmlParser
{
private:
	typedef std::map< CSulString, osg::ref_ptr<CSulXmlAttr> >	MAP_ATTR;

public:
	void			ElementStart( const class CSulString& sName, class CSulXmlAttr* pAttr );

	CSulXmlAttr*	Get( const CSulString& sTag );

private:
	MAP_ATTR		m_mapAttr;
};

#endif // __SULGUIXML_H__