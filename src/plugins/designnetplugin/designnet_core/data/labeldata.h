#ifndef LABELDATA_H
#define LABELDATA_H

#include "idata.h"
#include "opencv2/core/core.hpp"
#include <QHash>
namespace DesignNet {
/*!
 *	\brief ��������ǩ
 *
 * 
 */
class DESIGNNET_CORE_EXPORT LabelData : public IData
{
	Q_OBJECT

public:
	LabelData(QObject *parent);
	~LabelData();
	virtual Core::Id id();
	QHash<int, int> &labels();//!< ���ر�ǩ��
private:
	QHash<int, int> m_labels;//!< ʹ��Hash����ű�ǩ�� <����xi--���y>
};
}//!< namespace DesignNet

#endif // LABELDATA_H
