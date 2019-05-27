#ifndef DATETIMEDECORATOR_H
#define DATETIMEDECORATOR_H

#include<QJsonObject>
#include<QJsonValue>
#include<QObject>
#include<QScopedPointer>
#include<QDateTime>


#include<cm-lib_global.h>
#include<data/data-decorator.h>

namespace cm {
namespace data {
class CMLIBSHARED_EXPORT DateTimeDecorator : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(int ui_value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString ui_iso8601String READ toISO8601String NOTIFY valueChanged)
    Q_PROPERTY(QString ui_prettyDateString READ toPrettyDateString NOTIFY valueChanged)
    Q_PROPERTY(QString ui_prettyTimeString READ toPrettyTimeString NOTIFY valueChanged)
    Q_PROPERTY(QString ui_prettyString READ toPrettyString NOTIFY valueChanged)

public:
    explicit DateTimeDecorator(Entity *parentEntity = nullptr,
                          const QString& key = "SomeItemKey",
                          const QString& label ="", const QDateTime &value = QDateTime::currentDateTime());
    ~DateTimeDecorator() override; //override added here by Peter!

    DateTimeDecorator& setValue(const QDateTime& valueT);
    QDateTime value() const;
    QString toISO8601String()const;
    QString toPrettyTimeString()const;
    QString toPrettyDateString()const;
    QString toPrettyString()const;


    QJsonValue jsonValue() const override;
    void update(const QJsonObject& jsonObject) override;
signals:
    void valueChanged();

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}}

#endif // DATETIMEDECORATOR_H
