#include "datetime-decorator.h"
#include <QVariant>
#include <QDateTime>
namespace cm {
namespace data {

    class DateTimeDecorator::Implementation {
    public:
        Implementation(DateTimeDecorator* _dateTimeDecorator, QDateTime _value)
            : dateTimeDecorator(_dateTimeDecorator), value(_value){}

        DateTimeDecorator* dateTimeDecorator{nullptr};
        QDateTime value;
    };

    DateTimeDecorator::DateTimeDecorator(Entity *parentEntity, const QString& key, const QString& label, const QDateTime& value) : DataDecorator (parentEntity, key, label)
    {
        implementation.reset(new Implementation(this, value));
    }

    DateTimeDecorator:: ~DateTimeDecorator(){}

    QDateTime DateTimeDecorator::value() const{
        return implementation->value;
    }

    DateTimeDecorator& DateTimeDecorator::setValue(const QDateTime &value){
        if(value != implementation->value){
            //...validation here if required..
           // implementation->value = value;
            emit valueChanged();
        }
        return *this;
    }

    QJsonValue DateTimeDecorator:: jsonValue() const{
        return  QJsonValue::fromVariant(QVariant(implementation->value));
    }

    void DateTimeDecorator::update(const QJsonObject& _jsonObject){
        if(_jsonObject.contains(key())){
            setValue(QDateTime::currentDateTime());
        }else{
            setValue(QDateTime::currentDateTime());
            // this should be an empty or some default date value
        }
    }

    QString DateTimeDecorator::toISO8601String() const{
        if(implementation->value.isNull()){
            return "";
        }else{
            return implementation->value.toString(Qt::ISODate);
        }
    }

    QString DateTimeDecorator::toPrettyDateString() const{
        if(implementation->value.isNull()){
            return "Not Set";
        }else{
            return implementation->value.toString("D MM YYYY");
        }
    }

    QString DateTimeDecorator::toPrettyTimeString() const{
        if(implementation->value.isNull()){
            return "Not Set";
        }else
            return implementation->value.toString("hh mm: ap");
    }

    QString DateTimeDecorator::toPrettyString() const{
        if(implementation->value.isNull()){
            return "Not Set";
        }else{
            return implementation->value.toString("ddd d MM YYYY @ HH:mm:ss");
        }
    }

}}
