// SulFile.h

#ifndef __SULFILE_H__
#define __SULFILE_H__

#include "SulExport.h"
#include "SulString.h"
#include "SulTypes.h"
#include "SulPaths.h"
#include <osg/Referenced>
#include <osg/ref_ptr>
#include <vector>

class SUL_EXPORT CSulFile : public osg::Referenced
{
public:
	enum EMODE
	{
		MODE_WRITE,
		MODE_READ_BINARY
	};

	typedef std::vector< std::string >	VEC_STRING;

public:
					CSulFile();
					CSulFile( CSulPaths* sPaths );

	bool			Open( class CSulString sFile, EMODE eMode=MODE_READ_BINARY );
	bool			Close();
	bool			Print( const CSulString& s );
	
	bool 			Save( class CSulString& sFile, Sigma::int8* pBufData, Sigma::uint32 dwBufSize );
	Sigma::uint8* 	Load( const class CSulString& sFile );
	
	Sigma::uint32 	GetSize();
	Sigma::uint8*	GetDataPtr();
	
	VEC_STRING		getTextLines( Sigma::uint32 maxChars=1024 );

protected:
					~CSulFile();

private:
	Sigma::uint8*	m_pBuf;
	Sigma::uint32	m_dwBufSize;

//	FILE*			m_pFile;

	osg::ref_ptr<CSulPaths>	m_rPaths;

	// vs2003
#if !defined(WIN32) || (_MSC_VER>=1310 && _MSC_VER<1400)
	FILE*			m_pFile;
#else
	FILE*			m_pFile;
#endif



};

#endif // __SULFILE_H__
