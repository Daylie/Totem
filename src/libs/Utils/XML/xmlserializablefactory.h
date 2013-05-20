#ifndef XMLSERIALIZABLEFACTORY_H
#define XMLSERIALIZABLEFACTORY_H
#include "../utils_global.h"
#include <QObject>
namespace Utils{

/**
 * \class	XmlSerializableFactory
 *
 * \brief	XML ���л��������������ɸ��ָ�����Serializable����
 * 			
 *	XML������һ������ģʽ��\note ʹ�øù��������һ��Ҫ����Release()
 *
 * \author	Michael_BJFU
 * \date	2013/5/15
 */

class XmlSerializableFactoryPrivate;
class XmlSerializable;

class TOTEM_UTILS_EXPORT XmlSerializableFactory : public QObject
{
	Q_OBJECT

public:
	XmlSerializableFactory(QObject *parent = 0);
	~XmlSerializableFactory();
	static XmlSerializableFactory *instance();
	static void Release();
	void registerSerializable(const XmlSerializable* serializable);
	XmlSerializable* createSerialzable(const QString &serialzableType) ;
private:
	XmlSerializableFactoryPrivate *d;
	static XmlSerializableFactory *m_instance;
};

}

#endif // XMLSERIALIZABLEFACTORY_H
