#ifndef JOIN_H
#define JOIN_H

#include <QObject>
#include "designnetplugin\designnet_core\graphicsitem\processorgraphicsblock.h"
#include "designnetplugin\designnet_core\designnetbase\port.h"
QT_BEGIN_NAMESPACE
class QMenu;
QT_END_NAMESPACE
namespace DesignNet{
class DesignNetSpace;
}
class JoinProcessorPrivate;
/**
 * \class	Join
 *
 * \brief	Join.
 * 
 * ���ڽ�������������һ��m������Ϊ1*n������������Щ����������һ��
 * \author	Michael_BJFU
 * \date	2013/5/22
 */

class JoinProcessor : public DesignNet::ProcessorGraphicsBlock
{
	Q_OBJECT

public:
	JoinProcessor(DesignNet::DesignNetSpace *space, QGraphicsItem *parent = 0);
	virtual ~JoinProcessor();
	virtual DesignNet::Processor* create(DesignNet::DesignNetSpace *space = 0) const;
	virtual QString title() const;
	virtual QString category() const;//!< ����
	virtual bool process();     //!< ������
signals:
protected:
	virtual void dataArrived(DesignNet::Port* port);  //!< ���ݵ���
	virtual void createContextMenu(QMenu *parentMenu);
	virtual void propertyChanged(DesignNet::Property *prop);
private:
	JoinProcessorPrivate *d;
};

#endif // JOIN_H
