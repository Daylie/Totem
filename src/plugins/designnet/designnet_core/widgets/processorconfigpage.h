#ifndef PROCESSORCONFIGPAGE_H
#define PROCESSORCONFIGPAGE_H

#include <QWidget>
#include "customui/uicollapsiblewidget.h"
#include "../designnet_core_global.h"
QT_BEGIN_NAMESPACE
class QDialogButtonBox;
QT_END_NAMESPACE

namespace DesignNet{
class DESIGNNET_CORE_EXPORT ProcessorConfigPage : public CustomUI::uiCollapsibleWidget
{
	Q_OBJECT

public:
	enum PageType{
		PageType_Permanent,	//!< �����Բ���
		PageType_RealTime	//!< ʵʱ�Բ���
	};
	ProcessorConfigPage(PageType pt = PageType_RealTime, QWidget *parent = 0);
	virtual ~ProcessorConfigPage();
	PageType pageType();
signals:
	void configFinished();//!< �������
public slots:
	void setApplyButtonEnabled(bool bEnabled);
private:
	PageType m_pageType;//!< ҳ����
	QDialogButtonBox *m_buttonBox;
};

}

#endif // PROCESSORCONFIGPAGE_H
