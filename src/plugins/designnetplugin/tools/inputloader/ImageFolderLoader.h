#pragma once
#include "designnetplugin\designnet_core\graphicsitem\processorgraphicsblock.h"
#include "designnetplugin\designnet_core\designnetbase\port.h"
namespace DesignNet{
class PathDialogProperty;
}
namespace InputLoader{

class ImageFolderLoader :
	public DesignNet::ProcessorGraphicsBlock
{
	Q_OBJECT
public:
	ImageFolderLoader(DesignNet::DesignNetSpace *space, QGraphicsItem *parent = 0);
	virtual ~ImageFolderLoader(void);
	virtual Processor* create(DesignNet::DesignNetSpace *space = 0) const;
	virtual QString title() const;
	virtual QString category() const;//!< ����
	virtual bool process();     //!< ������
signals:
protected:
	virtual void dataArrived(DesignNet::Port* port);  //!< ���ݵ���
	DesignNet::Port m_outPort;
	DesignNet::PathDialogProperty *m_pathProperty;
};

}

