#ifndef LABELLOADER_H
#define LABELLOADER_H

#include "designnetplugin/designnet_core/graphicsitem/processorgraphicsblock.h"
#include "designnetplugin/designnet_core/designnetbase/port.h"
#include "designnetplugin/designnet_core/data/imagedata.h"

namespace DesignNet{
class Processor;
class PathDialogProperty;
class Property;
}
namespace InputLoader{
class LabelLoader : public DesignNet::ProcessorGraphicsBlock
{
	Q_OBJECT
public:
	LabelLoader(QObject *parent);
	~LabelLoader();
	virtual Processor* create(DesignNet::DesignNetSpace *space = 0) const;
	virtual QString title() const;
	virtual QString category() const;//!< ����
	virtual bool process();     //!< ������

protected:
	virtual void dataArrived(DesignNet::Port* port);  //!< ���ݵ���
	virtual void propertyChanged(DesignNet::Property *prop);
private:
};

}

#endif // LABELLOADER_H
