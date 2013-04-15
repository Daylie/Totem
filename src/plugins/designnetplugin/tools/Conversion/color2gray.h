#ifndef COLOR2GRAY_H
#define COLOR2GRAY_H

#include "designnetplugin/designnet_core/graphicsitem/processorgraphicsblock.h"
#include "designnetplugin/designnet_core/designnetbase/port.h"
#include "designnetplugin/designnet_core/data/imagedata.h"
#include <opencv2/core/core.hpp>
namespace Conversion{

class Color2Gray : public DesignNet::ProcessorGraphicsBlock
{
	Q_OBJECT

public:
	Color2Gray(DesignNet::DesignNetSpace *space, QGraphicsItem *parent = 0);
	~Color2Gray();
	virtual Processor* create(DesignNet::DesignNetSpace *space = 0) const;
	virtual QString title() const;
	virtual QString category() const;//!< ����
	virtual bool process(QFutureInterface<bool> &fi);     //!< ������
protected:
	virtual void dataArrived(DesignNet::Port* port);  //!< ���ݵ���
	virtual void propertyChanged(DesignNet::Property *prop);
private:
	DesignNet::Port m_outputPort;	//!< ����˿�
	DesignNet::Port m_inputPort;	//!< ����˿�
	DesignNet::ImageData m_colorData;				//!< ��ɫͼ
	DesignNet::ImageData m_grayData;				//!< �Ҷ�ͼ
};

}

#endif // COLOR2GRAY_H
