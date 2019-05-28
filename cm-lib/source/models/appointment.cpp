#include "appointment.h"

using namespace cm::data;

namespace cm{
namespace models {

Appointment::Appointment(QObject *parent) : Entity(parent, "Appointment")
{
    endAt = static_cast<DateTimeDecorator*>(addDataItem(new DateTimeDecorator(this, "endAt", "EndAt")));
    startAt = static_cast<DateTimeDecorator*>(addDataItem(new DateTimeDecorator(this, "startAt", "StartAt")));
    notes = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this, "notes", "Notes")));
}

Appointment::Appointment(QObject *parent, const QJsonObject &json) : Appointment(parent)
{
    update(json);
}

QString Appointment::appointmentDetails() const
{   //.toString  is added to endAt and startAt->value() by Peter
    return endAt->value().toString() + "" + endAt->value().toString() + "\n" + notes->value();
}

}}
