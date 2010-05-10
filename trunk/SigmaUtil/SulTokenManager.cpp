// SulTokenManager.cpp

#include "stdafx.h"
#include "SulTokenManager.h"

CSulTokenManager::CSulTokenManager()
{
	m_iIndex = 0;
	m_rTokenizer = new CSulTokenizer;
}

bool CSulTokenManager::Parse( Sigma::uint8* pData, Sigma::uint32 iSize )
{
	return m_rTokenizer->Parse( pData, iSize );
}

const char* CSulTokenManager::GetToken()
{
	// check if we are at the end
	if ( m_iIndex>=(Sigma::int32)m_vecToken.size() )
	{
		return 0;
	}

	// increase index
	++m_iIndex;

	return m_vecToken[m_iIndex-1].c_str();
}