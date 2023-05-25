#include "entity.h"




using namespace std;






// <<<<<<<<<<<  S T A R T I N T E R F A C E >>>>>>>>>>>>

void UI_Register::startInterface(){
    control_register->addAccount();
}
void UI_DeleteAccount::startInterface(){
    control_deleteaccount->deleteAccount();
}
void UI_Login::startInterface(){
    control_login->logIn();
}
void UI_Logout::startInterface(){
    control_logout->logOut();
}

/*
 =======================================================================================================================
 class ControlList{
 private:
 Control* controls[10];
 public:
 void generateControl(int num);
 };
 
 */

void ControlList::generateControl(int num){
    switch(num){
        case 0: controls[0] = new Control_Register(this);
        case 1: controls[1] = new Control_DeleteAccount(this);
        case 2: controls[2] = new Control_Login(this);
        case 3: controls[3] = new Control_Logout(this);
        default: break;
    }
}



/*
 =======================================================================================================================
 class Control_Register : public Control
 {
 private:
 UI_Register* ui_register;
 public:
 Control_Register(){
 ui_register = new UI_Register();
 }
 
 void addAccount();
 };
 
 */
void Control_Register::addAccount(){
    
}



/*
 =======================================================================================================================
 class Control_DeleteAccount : public Control
 {
 private:
 UI_DeleteAccount* ui_delaccount;
 public:
 Control_DeleteAccount(){
 ui_delaccount = new UI_DeleteAccount();
 }
 
 void deleteAccount();
 };
 
 */

void Control_DeleteAccount::deleteAccount(){
    
}



/*
 =======================================================================================================================
 
 class Control_Login : public Control
 {
 private:
 UI_Login* ui_login;
 public:
 Control_Login(){
 ui_login = new UI_Login();
 }
 
 void logIn();
 };
 
 */
void Control_Login::logIn(){
    
}


/*
 =======================================================================================================================
 
 class Control_Logout : public Control
 {
 private:
 UI_Logout* ui_logout;
 public:
 Control_Logout(){
 ui_logout = new UI_Logout();
 }
 
 void logOut();
 };
 
 */
void Control_Logout::logOut(){
    
}





/*
 =======================================================================================================================
 
 class Control_ApplyRecruit : public Control
 {
 private:
 UI_ApplyRecruit* ui_applyrec;
 public:
 Control_ApplyRecruit(){
 ui_applyrec = new UI_ApplyRecruit();
 }
 
 void applyRecruit();
 };
 
 */
void Control_ApplyRecruit::applyRecruit(){
    
}

























