#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>

#include <cm-lib_global.h>
#include <data/enumerator-decorator.h>
#include <data/string-decorator.h>
#include <data/entity.h>

namespace cm{
namespace models{

class CMLIBSHARED_EXPORT Contact : public data::Entity
{
    Q_OBJECT
    Q_PROPERTY(cm::data::EnumeratorDecorator *ui_type MEMBER contactType CONSTANT)
    Q_PROPERTY(cm::data::StringDecorator *ui_address MEMBER contactAddress CONSTANT)

    Q_PROPERTY(QString ui_fullContact READ fullContact CONSTANT)

    //std::map<int, QString> contactTypeMapper;

    public:
        explicit Contact(QObject *parent = nullptr);
        Contact(QObject *parent, const QJsonObject &json);

        data::EnumeratorDecorator *contactType{nullptr};
        data::StringDecorator *contactAddress{nullptr};

        QString fullContact() const;

        static std::map<int, QString> contactTypeMapper; //static qualifier is added by Peter

        enum eContactType{
            Unknown = 0,
            Telephone,
            Email,
            Fax
        };

};
}}

#endif // CONTACT_H
