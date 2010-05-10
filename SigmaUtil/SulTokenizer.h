// SulTokenizer.h

#ifndef __SULTOKENIZER_H__
#define __SULTOKENIZER_H__

#include "SulTypes.h"
#include "SulString.h"

class CSulTokenizer : public osg::Referenced
{
private:
	typedef std::vector<CSulString>	VECTOR_STRING;

public:
						CSulTokenizer();

	bool				Parse( Sigma::uint8* pData, Sigma::uint32 iSize );

	const CSulString&	GetToken( Sigma::uint32 iIndex );

	// character tokens
	void				AddCharAsToken( Sigma::uint8 c );
	void				RemoveCharAsToken( Sigma::uint8 c );
	bool				IsCharToken( Sigma::uint8 c ) { return m_cToken[c]?true:false; }

	// character delimiters
	void				AddCharAsDelimiter( Sigma::uint8 c );
	void				RemoveCharAsDelimiter( Sigma::uint8 c );
	bool				IsCharDelimiter( Sigma::uint8 c ) { return m_cDelimiter[c]?true:false; }

	// character sentence start
	void				AddCharAsSentenceStart( Sigma::uint8 c );
	void				RemoveCharAsSentenceStart( Sigma::uint8 c );
	bool				IsCharSentenceStart( Sigma::uint8 c ) { return m_cSentenceStart[c]?true:false; }

	// character sentence end
	void				AddCharAsSentenceEnd( Sigma::uint8 c );
	void				RemoveCharAsSentenceEnd( Sigma::uint8 c );
	bool				IsCharSentenceEnd( Sigma::uint8 c ) { return m_cSentenceEnd[c]?true:false; }

private:
	VECTOR_STRING	m_vecToken;
	Sigma::int8		m_cToken[256];
	Sigma::int8		m_cDelimiter[256];
	Sigma::int8		m_cSentenceStart[256];
	Sigma::int8		m_cSentenceEnd[256];
};

#endif // __SULTOKENIZER_H__