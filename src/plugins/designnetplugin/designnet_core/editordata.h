#ifndef EDITORDATA_H
#define EDITORDATA_H

#include <QObject>

namespace DesignNet{
class DesignNetEditor;
class DesignView;
class EditorData : public QObject
{
    Q_OBJECT
public:
    explicit EditorData(QObject *parent = 0);
    DesignNetEditor *m_editor; //IEditor������
    DesignView      *m_view;    //�����ͼ
};
}

#endif // EDITORDATA_H
