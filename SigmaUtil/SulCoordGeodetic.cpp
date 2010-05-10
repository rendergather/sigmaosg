// SulCoordGeodetic.cpp

#include "stdafx.h"
#include "SulCoordGeodetic.h"

CSulCoordGeodetic::CSulCoordGeodetic( const CSulCoordLatLon& latlon/*, Sigma::uint8 meridian, Sigma::uint8 hemisphere*/ ) :
m_latlon(latlon),
m_height(0.0)
/*m_meridian(meridian),
m_hemisphere(hemisphere)
*/
{
}

const CSulCoordLatLon& CSulCoordGeodetic::getLatLon() const
{
	return m_latlon;
}