// SulPlasma.h

#ifndef __SULPLASMA_H__
#define __SULPLASMA_H__

#include "SulTypes.h"
#include "SulExport.h"
#include <osg/Referenced>

class SUL_EXPORT CSulPlasma : public osg::Referenced
{
public:
								CSulPlasma();
								~CSulPlasma();

	void						Create( Sigma::uint32 w, Sigma::uint32 h );
	Sigma::uint8				GetValue( Sigma::uint32 dwPosX, Sigma::uint32 dwPosY );
	Sigma::uint8*				GetDataPtr();

private:
	int							NewColor( Sigma::int32 mc, Sigma::int32 n, Sigma::int32 dvd );
	void						Plasma( Sigma::int32 x1, Sigma::int32 y1, Sigma::int32 x2, Sigma::int32 y2, Sigma::uint8* pData );

private:
	Sigma::uint32				m_maxX;
	Sigma::uint32				m_maxY;
	Sigma::uint8*				m_pData;
};

#endif // __SULPLASMA_H__
