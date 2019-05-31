#include "mastercontroller.h"

//#include <QObject>
//namespace cm {
//namespace controllers {

using namespace cm::controllers;
using namespace cm::models;

class MasterController::Implementation
{
    public:
        Implementation(MasterController* _masterController)
            : masterController(_masterController)
        {
            navigationController = new NavigationController(masterController);
            commandController = new CommandController(masterController);
            newClient = new Client(masterController);
        }

        MasterController* masterController{nullptr};
        NavigationController* navigationController{nullptr};
        QString WelcomeMessage = "This is the MasterController to Tom";
        CommandController* commandController{nullptr};
        // added 28/05/2019
       Client* newClient{nullptr};
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

Client* MasterController::newClient(){
    return implementation->newClient;
}


//}}
