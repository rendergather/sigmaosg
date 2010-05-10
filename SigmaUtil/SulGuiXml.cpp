// SulGuiXml.cpp

#include "stdafx.h"
#include "SulGuiXml.h"
#include "SulXmlAttr.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//	NOTE:
//
//		basic format for the xml file is:
//			<ELEMENTS image="elements.tga" >
//				<XXXXX a="0" b="1" .../>
//				<XXXXX a="0" b="1" .../>
//				<XXXXX a="0" b="1" .../>
//			</ELEMETNS>
//
//		the xml is formed in a way so there are only one line for each definition of an element
//		I have decided to do this so I can make a simple database that can use strings to map
//		attributes.
//
//		I might change this at a later date if the elements need more advance information.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

void CSulGuiXml::ElementStart( const CSulString& sName, CSulXmlAttr* pAttr )
{
	// we assume only element tags from now on (there is no smart error checking here yet!)
	m_mapAttr[sName] = pAttr;
}

CSulXmlAttr* CSulGuiXml::Get( const CSulString& sTag ) 
{
	MAP_ATTR::const_iterator i;

	i = m_mapAttr.find( sTag );
	if ( i!=m_mapAttr.end() )
	{
		return m_mapAttr[sTag].get();
	}

	return 0;
}

