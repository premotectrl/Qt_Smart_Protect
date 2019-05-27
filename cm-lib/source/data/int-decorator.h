#ifndef INTDECORATOR_H
#define INTDECORATOR_H

#include<QJsonObject>
#include<QJsonValue>
#include<QObject>
#include<QScopedPointer>
//#include<QString>

#include<cm-lib_global.h>
#include<data/data-decorator.h>

namespace cm {
namespace data {
class CMLIBSHARED_EXPORT IntDecorator : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(int ui_value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit IntDecorator(Entity *parentEntity = nullptr,
                          const QString& key = "SomeItemKey",
                          const QString& label ="", const int& value = 0);
    ~IntDecorator() override; //override added here by Peter!

    IntDecorator& setValue(int value);
    int value() const;

    QJsonValue jsonValue() const override;
    void update(const QJsonObject& jsonObject) override;
signals:
    void valueChanged();

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}}
#endif // INTDECORATOR_H
