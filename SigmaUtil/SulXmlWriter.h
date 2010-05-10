// SulXmlWriter.h

#ifndef __SULXMLWRITER_H__
#define __SULXMLWRITER_H__

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	BASIC USAGE: example from an old project
//
// 	CSulXmlWriter* pSaveState;
//
//	pSaveState = new CSulXmlWriter( "AxiomEngineState" );
//
//	CSulXmlAttr* pAttr;
//
//	pAttr = pSaveState->ElementStart( "DEBUG_MENU" );
//	pAttr->Add( "Information",	MF->GetMainWindow()->IsVisibleInformation()?"true":"false" );
//	pAttr->Add( "Profiler",		MF->GetMainWindow()->IsVisibleProfiler()?"true":"false" );
//	pAttr->Add( "TreeView",		MF->GetMainWindow()->IsVisibleTreeView()?"true":"false" );
//	pAttr->Add( "Messages",		MF->GetMainWindow()->IsVisibleMessageInfo()?"true":"false" );
//	pSaveState->ElementEnd();
//
//	pSaveState->Save( pszFile );
//
//	delete pSaveState;
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "SulExport.h"
#include "SulString.h"
#include "SulXmlDataInfo.h"
#include <osg/ref_ptr>

class CSulXmlAttr;

class SUL_EXPORT CSulXmlWriter
{
	typedef std::vector< osg::ref_ptr<CSulXmlDataInfo> >	VECTOR_DATAINFO_PTR;
	typedef std::vector<CSulString>							VECTOR_TAG_REF;

public:
							CSulXmlWriter( const char* pszRootName );
							~CSulXmlWriter();

	CSulXmlAttr*			GetRootAttr();

	bool					Save( const char* pszXmlFile );

	CSulXmlAttr*			ElementStart( const char* pszName );
	void					ElementEnd();

private:
	VECTOR_DATAINFO_PTR		m_rVectorDataInfoPtr;
	CSulString				m_strRootName;
	CSulXmlAttr*			m_pAttrRoot;
};

#endif // __SULXMLWRITER_H__


