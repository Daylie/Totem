#ifndef BUFFERPROCESSOR_H
#define BUFFERPROCESSOR_H

#include <QObject>
#include "designnetplugin\designnet_core\graphicsitem\processorgraphicsblock.h"
#include "designnetplugin\designnet_core\designnetbase\port.h"
class BufferProcessorPrivate;
class BufferProcessor : public DesignNet::ProcessorGraphicsBlock
{
	Q_OBJECT

public:
	BufferProcessor(DesignNet::DesignNetSpace *space, QGraphicsItem *parent = 0);
	~BufferProcessor();
	virtual DesignNet::Processor* create(DesignNet::DesignNetSpace *space = 0) const;
	virtual QString title() const;
	virtual QString category() const;//!< ����
	virtual bool process();     //!< ������
signals:
protected:
	virtual void dataArrived(DesignNet::Port* port);  //!< ���ݵ���
	virtual void createContextMenu(QMenu *parentMenu);
	virtual void propertyChanged(DesignNet::Property *prop);
	BufferProcessorPrivate *d;
};

#endif // BUFFERPROCESSOR_H
