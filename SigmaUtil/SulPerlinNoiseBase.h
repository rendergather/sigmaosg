// SulPerlinNoiseBase.h

#ifndef __SULPERLINNOISEBASE_H__
#define __SULPERLINNOISEBASE_H__

#include "SulTypes.h"
#include <osg/Referenced>

class CSulPerlinNoiseBase : public osg::Referenced
{
public:
						CSulPerlinNoiseBase();

	void				SetRandomSeed( Sigma::uint32 iSeed );

	void				SetOctave( Sigma::uint32 iOctaves );
	Sigma::uint32		GetOctave();

	void				SetPersistence( float fPersistence );
	float				GetPersistence();

protected:
	Sigma::uint32		m_iOctaves;
	float				m_fPersistence;
	Sigma::uint32		m_iSeed;
};

#endif // __SULPERLINNOISEBASE_H__