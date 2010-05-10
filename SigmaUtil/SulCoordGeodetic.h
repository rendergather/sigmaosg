// SulCoordGeodetic.h

#ifndef __SULCOORDGEODETIC_H__
#define __SULCOORDGEODETIC_H__

#include "SulTypes.h"
#include "SulCoordLatLon.h"

////////////////////////////////////////////////////////////////////////////////////////////////
//
//	geodetic with height parameter at 0.0 is at the earth surface
//	geodetic defines a spherical coordinate system
//	longitude describes the upwards and downwards direction on the earth
//	latitude describes the left and right directions on the earth
//
////////////////////////////////////////////////////////////////////////////////////////////////

class CSulCoordGeodetic : public osg::Referenced
{
public:
	CSulCoordGeodetic( const CSulCoordLatLon& latlon /*, Sigma::uint8 meridian, Sigma::uint8 hemisphere*/ );

	const CSulCoordLatLon& getLatLon() const;

private:
	CSulCoordLatLon		m_latlon;
	double				m_height;
/*
	Sigma::uint8		m_meridian;		// 'E' : eastern, 'W' : western
	Sigma::uint8		m_hemisphere;	// 'N' : nortern, 'S' : southern
*/
};


#endif // __SULCOORDGEODETIC_H__