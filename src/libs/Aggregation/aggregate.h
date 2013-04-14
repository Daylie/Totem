/*!
 * \file aggregate.h
 * \author Michael_BJFU
 * \ref ���뼸��û�н����޸ģ�����QtCreatorԴ���룬����ض�����
 * \brief
 *
 */
#ifndef QAGGREGATION_H
#define QAGGREGATION_H

#include "aggregation_global.h"

#include <QObject>
#include <QList>
#include <QHash>
#include <QReadWriteLock>
#include <QReadLocker>

namespace Aggregation {
/*!
 * \class Aggregate
 * \brief Aggregate ���󼯺��൱��Union����
 */
class AGGREGATION_EXPORT Aggregate : public QObject
{
    Q_OBJECT

public:
    Aggregate(bool autoDelete = true, QObject *parent = 0);
    virtual ~Aggregate();

    void add(QObject *component);   //!< ���QObject��m_components����
    void remove(QObject *component);//!< ��m_components���Ƴ��ƶ�QObject

    ///
    /// �õ��б��е�һ��ָ�����͵�component�����������qobject_cast����m_components��QList)�б�
    /// �л������
    template <typename T> T *component() {
        QReadLocker(&lock());
        foreach (QObject *component, m_components) {
            if (T *result = qobject_cast<T *>(component))
                return result;
        }
        return (T *)0;
    }

    ///
    /// �����б�������ָ�����͵�component��
    /// �л������
    template <typename T> QList<T *> components() {
        QReadLocker(&lock());
        QList<T *> results;
        foreach (QObject *component, m_components) {
            if (T *result = qobject_cast<T *>(component)) {
                results << result;
            }
        }
        return results;
    }

    ///
    /// ����obj���ڵ�Aggregate�����ϣ�
    static Aggregate *parentAggregate(QObject *obj);

    /// ������
    static QReadWriteLock &lock();

signals:
    void changed();

private slots:
    void deleteSelf(QObject *obj);

private:
    static QHash<QObject *, Aggregate *> &aggregateMap();

    QList<QObject *> m_components;
    bool m_autoDelete;  //!< ��ĳһ��componentɾ��ʱ���Ƿ��Զ�ɾ�����Ըü����е����ж���
};

/*!
 * \fn query(Aggregate *obj)
 * ��ȫ��ģ�庯���в�ѯ<em> Aggregate obj </em> ������Ϊ\a T ��component
 */
template <typename T> T *query(Aggregate *obj)
{
    if (!obj)
        return (T *)0;
    return obj->component<T>();
}

/*!
 * \fn T *query(QObject *obj)
 * ��\a obj ���ڵļ����в��ҵ�һ��ΪT���͵�component
 */
template <typename T> T *query(QObject *obj)
{
    if (!obj)
        return (T *)0;
    T *result = qobject_cast<T *>(obj);
    if (!result) {
        QReadLocker(&lock());
        Aggregate *parentAggregation = Aggregate::parentAggregate(obj);
        result = (parentAggregation ? query<T>(parentAggregation) : 0);
    }
    return result;
}

/*!
 * ������\a obj ���ڵļ����в�������ΪT���͵�component
 */
template <typename T> QList<T *> query_all(Aggregate *obj)
{
    if (!obj)
        return QList<T *>();
    return obj->template components<T>();
}

/*!
 *  ����\a obj ���ڼ��������е�T���͵�component
 *  \sa query_all(Aggregate *obj)
 */
template <typename T> QList<T *> query_all(QObject *obj)
{
    if (!obj)
        return QList<T *>();
    QReadLocker(&lock());
    Aggregate *parentAggregation = Aggregate::parentAggregate(obj);
    QList<T *> results;
    if (parentAggregation)
        results = query_all<T>(parentAggregation);
    else if (T *result = qobject_cast<T *>(obj))
        results.append(result);
    return results;
}

} // namespace Aggregation

#endif // QAGGREGATION_H
