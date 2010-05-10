// SulPerlinNoiseBase.cpp

#include "stdafx.h"
#include "SulPerlinNoiseBase.h"

CSulPerlinNoiseBase::CSulPerlinNoiseBase()
{
	m_iSeed			= 1;
	m_iOctaves		= 1;
	m_fPersistence	= 1;
}

void CSulPerlinNoiseBase::SetRandomSeed( Sigma::uint32 iSeed )
{
	m_iSeed = iSeed;
}

void CSulPerlinNoiseBase::SetOctave( Sigma::uint32 iOctaves )
{
	m_iOctaves = iOctaves;
}

Sigma::uint32 CSulPerlinNoiseBase::GetOctave()
{
	return m_iOctaves;
}


void CSulPerlinNoiseBase::SetPersistence( float fPersistence )
{
	m_fPersistence = fPersistence;
}

float CSulPerlinNoiseBase::GetPersistence()
{
	return m_fPersistence;
}
