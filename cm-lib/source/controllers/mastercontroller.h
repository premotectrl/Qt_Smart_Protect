#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <cm-lib_global.h>

#include <QObject>
#include <QScopedPointer>
#include <QString>

#include <controllers/navigation-controller.h>
#include <controllers/commandcontroller.h>

namespace cm {
namespace controllers {


class CMLIBSHARED_EXPORT MasterController : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString ui_welcomeMessage READ welcomeMessage CONSTANT)
    Q_PROPERTY( cm::controllers::NavigationController* ui_navigationController READ navigationController CONSTANT )
    Q_PROPERTY(cm::controllers::CommandController* ui_commandController READ commandController CONSTANT)

public:
    explicit MasterController(QObject *parent = nullptr);
    ~MasterController();

    NavigationController* navigationController();
    const QString& welcomeMessage() const;
    CommandController* commandController();
private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};
}}

#endif // MASTERCONTROLLER_H
