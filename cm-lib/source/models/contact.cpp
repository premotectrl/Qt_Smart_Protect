#include "contact.h"

using namespace cm::data;

namespace cm{
namespace models {

Contact::Contact(QObject *parent) : Entity(parent, "Contact")
{
    contactType = static_cast<EnumeratorDecorator*>(addDataItem(new EnumeratorDecorator(this, "contactType", "Contact Type", 0, contactTypeMapper)));
    contactAddress = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this, "contactAddress", "ContactAddress")));
}

Contact::Contact(QObject *parent, const QJsonObject &json) : Contact(parent)
{
    update(json);
}

std::map<int, QString> Contact::contactTypeMapper = std::map<int, QString>
{
    {Contact:: eContactType::Unknown, ""},
    {Contact::eContactType::Telephone, "Telephone"},
    {Contact:: eContactType::Email, "Email"},
    {Contact::eContactType::Fax, "Fax"}
};

QString Contact::fullContact() const
{
    return static_cast<QString>(contactType->value()) + "\n" + contactAddress->value() ;
}

}}
