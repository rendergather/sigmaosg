// SulParser.h

#ifndef __SULPARSER_H__
#define __SULPARSER_H__
/*
#ifdef TARGET_WINDOWS
// stl uses long names which which is not supported by Visual C/C++ debugger ( only a warning  )
#pragma warning( disable:4786 )
#endif // TARGET_WINDOWS
*/

#include "SulExport.h"
#include "SulTypes.h"
#include <osg/Referenced>
#include <string>
#include <vector>

using std::vector;
using std::string;

class SUL_EXPORT CSulParser : public osg::Referenced
{
public:
	class CMyString
	{
	public:
		CMyString( string str ) { m_str = str; };
		string	m_str;
	};

	typedef vector<char>		VECTOR_CHAR_REF;
	typedef vector<CMyString>	VECTOR_STRING_REF;

public:
	CSulParser();
	
	// load data into memory and preprocess it
	bool Init( const class CSulString& sFileName );

	bool InitStringParse( const CSulString& s );

	// NOTE: Init must not be called if calling ParseData directly
	bool ParseData( const Sigma::uint8* pData, Sigma::uint32 iSize );

	// reset parser pointer
	void Reset();

	void IncIndex( Sigma::uint32 i );
	void DecIndex( Sigma::uint32 i );

	void Goto( const CSulString& sText );

	// gets the token and advances the pointer to the next token
	Sigma::int8*	GetToken();
	CSulString		GetStringToken();

	// gets the token but does not advance the pointer
	char* PeekToken();

	// gets the token before the current token,.. but does not advance the pointer
	char* OldToken();

	void AddCharDelimiter( char cChar );
	void AddCharToken( char cChar );
	void AddCommentStart( char* lpszCommentStart );
	void AddCommentEnd( char* lpszCommentEnd );
	void AddCommentEOL( char* lpszCommentEOL );
	void AddSentenceStart( char* lpszText );
	void AddSentenceEnd( char* lpszText );
	void AddSentenceCharStart( char cChar );
	void AddSentenceCharEnd( char cChar );

	void RemoveCharToken( Sigma::int8 cChar );

	bool IsCommentStart( char* lpszText );
	bool IsCommentEnd( char* lpszText );
	bool IsCommentEOL( char* lpszText );
	long IsSentenceStart( char* lpszText );
	long IsSentenceEnd( char* lpszText );

	void PreProcessData();

protected:
	~CSulParser();

private:
	Sigma::uint32		m_dwSize;		// size of data
	Sigma::uint8*		m_pBuf;			// data loaded
	Sigma::uint32		m_dwIndex;

	Sigma::uint8			m_cDelimiters[256];
	Sigma::uint8			m_cTokens[256];
	Sigma::uint8			m_cSentenceStart[256];
	Sigma::uint8			m_cSentenceEnd[256];

	VECTOR_STRING_REF	m_vecTokens;
	VECTOR_STRING_REF	m_vecCommentStart;
	VECTOR_STRING_REF	m_vecCommentEnd;
	VECTOR_STRING_REF	m_vecCommentEOL;
	VECTOR_STRING_REF	m_vecSentenceStart;
	VECTOR_STRING_REF	m_vecSentenceEnd;
};

#endif // __SULPARSER_H__


