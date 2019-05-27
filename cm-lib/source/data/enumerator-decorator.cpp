#include "enumerator-decorator.h"
#include <QVariant>
namespace cm {
namespace data {

class EnumeratorDecorator::Implementation {
public:
    Implementation(EnumeratorDecorator* _EnumeratorDecorator, const std::map<int, QString>& _descriptionMapper, int _value)
        : EnumeratorDecorator(_EnumeratorDecorator), descriptionMapper(_descriptionMapper), value(_value){}

    EnumeratorDecorator* EnumeratorDecorator{nullptr};

    const  std::map<int, QString>& descriptionMapper;
    int value = 0;
};

EnumeratorDecorator::EnumeratorDecorator(Entity *parentEntity, const QString& key, const QString& label, int value, const std::map<int, QString>& descriptionMapper) : DataDecorator (parentEntity, key, label)
{
    implementation.reset(new Implementation(this, descriptionMapper, value));
}

EnumeratorDecorator:: ~EnumeratorDecorator(){}

int EnumeratorDecorator::value() const{
    return implementation->value;
}

EnumeratorDecorator& EnumeratorDecorator::setValue( int value){
    if(value != implementation->value){
        //...validation here if required..
        implementation->value = value;
        emit valueChanged();
    }
    return *this;
}

QJsonValue EnumeratorDecorator:: jsonValue() const{
    return  QJsonValue:: fromVariant(QVariant(implementation->value));
}

void EnumeratorDecorator::update(const QJsonObject& _jsonObject){
    if(_jsonObject.contains(key())){
        setValue(_jsonObject.value(key()).toInt());
    }else{
        setValue(0);
    }
}

QString EnumeratorDecorator::valueDescription() const{
    if(implementation->descriptionMapper.find(implementation->value) != implementation->descriptionMapper.end()){
        return implementation->descriptionMapper.at(implementation->value);
    }else{
        return{};
    }
}
}}
