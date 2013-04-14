#ifndef DESIGNNETDOCUMENT_H
#define DESIGNNETDOCUMENT_H
#include "coreplugin/idocument.h"
namespace DesignNet{

class DesignNetEditor;

class DesignNetDocumentPrivate;
/**
 * @brief The DesignNetDocument class
 * 实现*.designnet文件的操作
 */
class DesignNetDocument : public Core::IDocument
{
    Q_OBJECT
public:
    DesignNetDocument(DesignNetEditor *parent = 0);
    ~DesignNetDocument();

    QString defaultPath() const;
    QString suggestedFileName() const;
    QString suffixType() const;

    bool shouldAutoSave() const;

    bool isModified() const;
    bool isSaveAsAllowed() const;

    void rename(const QString &newName);
    void setModified(const bool &bModified = true);

    bool reload(QString *errorString, ReloadFlag flag, ChangeType type);
    bool save(QString *errorString, const QString &fileName = QString(), bool autoSave = false);

private:
    DesignNetDocumentPrivate *d;
};
}//namespace DesignNet

#endif // DESIGNNETDOCUMENT_H
