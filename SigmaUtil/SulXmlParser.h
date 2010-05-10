// SulXmlParser.h

#ifndef __SULXMLPARSER_H__
#define __SULXMLPARSER_H__

#include "SulExport.h"
#include "SulString.h"
#include <osg/Referenced>

class CSulParser;
class CSulXmlAttr;

class SUL_EXPORT CSulXmlParser : public osg::Referenced
{
public:
					CSulXmlParser();
	virtual			~CSulXmlParser();

	virtual bool	Load( const class CSulString& sXmlFile );

	virtual void	ElementStart( const CSulString& sName, CSulXmlAttr* pAttr ) {}
	virtual void	ElementEnd( const CSulString& sName, CSulXmlAttr* pAttr  ) {}
	virtual void	ElementEnd( const CSulString& sName ) {}

	virtual void	LoadFinished() {}	

private:
	bool			ParseElement( CSulParser* pSulParser );

private:
	// because ParseElement is called a lot these variables are only created one instance of for faster usage
	CSulString		strNameAttr;
	CSulString		strValueAttr;
	CSulString		strName;
	CSulString		strElementName;
};

#endif // __SULXMLPARSER_H__
