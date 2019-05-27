#include "mastercontroller.h"
//#include <QObject>
//namespace cm {
//namespace controllers {

using namespace cm::controllers;

class MasterController::Implementation
{
    public:
        Implementation(MasterController* _masterController)
            : masterController(_masterController)
        {
            navigationController = new NavigationController(masterController);
            commandController = new CommandController(masterController);
        }

        MasterController* masterController{nullptr};
        NavigationController* navigationController{nullptr};
        QString WelcomeMessage = "This is the MasterController to Tom";
        CommandController* commandController{nullptr};
};

MasterController::MasterController(QObject* parent)
    : QObject (parent)
{
    implementation.reset(new Implementation(this));
}

MasterController::  ~MasterController(){}

NavigationController* MasterController:: navigationController(){
    return implementation -> navigationController;
}

const QString& MasterController::welcomeMessage() const{
    return implementation->WelcomeMessage;
}

CommandController* MasterController::commandController(){
    return implementation -> commandController;
}


//}}
