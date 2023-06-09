#include "boundary.h"
#include "entity.h"

/*
 ############################################### // UI // ########################################################################
 ############################################### // UI // ########################################################################
 ############################################### // UI // ########################################################################
 */

//=====================// RegisterUI //====================
//=====================// RegisterUI //====================

//RegisterUI :: startInterface
void RegisterUI::startInterface(MemberList* memberlist){
    cout << "type 1 to register as a company member\ntype 2 to register as a user\n";
    int input = -1;
    cin >> input;
    
    this->addAccount(memberlist, input);
    
}

//RegisteraUI :: addAccount
void RegisterUI::addAccount(MemberList* memberlist, int type){
    control_register->createAccount(memberlist, type); // UI에서 컨트롤 함수 실행
}


//=====================// LoginUI //====================
//=====================// LoginUI //====================
void LoginUI::startInterface(MemberList* memberlist){
    cout << "Log-in UI\n";
    
    this->LogIn(memberlist);
}

void LoginUI::LogIn(MemberList* memberlist){
    control_login->Login(memberlist); //UI의 control 함수 호출 // (UI startInterface() -> UI LogIn() -> control Login())
}


/*
 ############################################### // CONTROL // ########################################################################
 ############################################### // CONTROL // ########################################################################
 ############################################### // CONTROL // ########################################################################
 */


//=====================// RegisterControl //====================
//=====================// RegisterControl //====================


//RegisterControl :: call_startInterface()
void RegisterControl::call_startInterface(MemberList* memberlist){
    ui_register = new RegisterUI(this, memberlist); // Control에서 UI 생성자 호출
}


//RegisterControl :: createAccount
void RegisterControl::createAccount(MemberList* memberlist, int type){
    Member* mem;
    if(type == 1){  //회사회원
        string name, id, pw;
        int serial_number;
        
        cout << "회사명 사번 아이디 비번\n";
        cin >> name >> serial_number >> id >> pw;
        mem = new CompanyMember(type, name, serial_number,  id, pw);
        memberlist->addMember(mem); // Control 에서 entity 함수 실행
        
    }
    else if(type == 0){ //일반회원
        string id, pw;
        int serial_number;
        cout << "주민번호 아이디 비번\n";
        cin >> serial_number >> id >> pw;
        
        mem = new UserMember(type, serial_number, id, pw);
        memberlist->addMember(mem); // Control 에서 entity 함수 실행
    }
}



//=====================// LoginControl //====================
//=====================// LoginControl //====================


//LoginControl :: startInterface
void LoginControl::call_startInterface(MemberList* memberlist){
    ui_login = new LoginUI(this, memberlist);
}

//LoginControl :: Login
void LoginControl::Login(MemberList* memberlist){
    cout << "id pw 입력\n";
    string id, pw;
    
    cin.ignore();
    cin >> id >> pw;
    cout << "내가 입력한 거 : " << id  <<" " <<pw << endl;
    
    if(memberlist->checkIDlist(id, pw) >= 0){
        cout <<"로그인 성공\n\n";
        memberlist->setState(1, memberlist->checkIDlist(id, pw)); //type = 1이면 로그인 상태
        
    }
    else if(memberlist->checkIDlist(id, pw) == -1){
        cout <<"그런 거 없다\n";
    }
    
    
    
}

