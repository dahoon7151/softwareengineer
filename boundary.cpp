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
void LoginUI::startInterface(MemberList* memberlist, int type, string* curID, string* curPW){ //type ==1 : 로그인, type == 0 로그아웃
    cout << "Log-in UI\n";
    
    if(type == 1) this->LogIn(memberlist, curID, curPW);
    else this->LogOut(memberlist, curID, curPW);
}

void LoginUI::LogIn(MemberList* memberlist, string* curID, string* curPW){
    control_login->Login(memberlist, curID, curPW); //UI의 control 함수 호출 // (UI startInterface() -> UI LogIn() -> control Login())
}

void LoginUI::LogOut(MemberList* memberlist, string* curID, string* curPW){
    control_login->Logout(memberlist, curID, curPW);
    
}



//=====================// DeleteAccountUI //====================
//=====================// DeleteAccountUI //====================

void DeleteAccountUI::startInterface(MemberList* memberlist, string* curID, string* curPW){
    this->DeleteAccount(memberlist, curID, curPW);
}

void DeleteAccountUI::DeleteAccount(MemberList* memberlist, string* curID, string* curPW){
    control_deleteAccount->deleteAccount(memberlist, curID, curPW);
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
    else if(type == 2){ //일반회원
        string id, pw;
        int serial_number;
        cout << "주민번호 아이디 비번\n";
        cin >> serial_number >> id >> pw;
        
        mem = new UserMember(0, serial_number, id, pw);
        memberlist->addMember(mem); // Control 에서 entity 함수 실행
    }
}



//=====================// LoginControl //====================
//=====================// LoginControl //====================


//LoginControl :: startInterface
void LoginControl::call_startInterface(MemberList* memberlist, int type, string* curID, string* curPW){
    ui_login = new LoginUI(this, type, memberlist, curID, curPW);

}

//LoginControl :: Login
void LoginControl::Login(MemberList* memberlist, string* curID, string* curPW){
    cout << "id pw 입력\n";
    string id, pw;
    
    cin.ignore();
    cin >> id >> pw;
    cout << "내가 입력한 거 : " << id  <<" " <<pw << endl;
    
    if(memberlist->checkIDlist(id, pw) >= 0){
        cout <<"로그인 성공\n\n";
        memberlist->setState(1, memberlist->checkIDlist(id, pw)); //type = 1이면 로그인 상태
        *(curID) = id;
        *(curPW) = pw;
        
    }
    else if(memberlist->checkIDlist(id, pw) == -1){
        cout <<"그런 거 없다\n";
    }
    
}

//LoginControl :: Logout
void LoginControl::Logout(MemberList* memberlist, string* curID, string* curPW){
    int index = memberlist->checkIDlist(*(curID), *(curPW));
    
    if(index < 0){
        cout << "이미 로그아웃 됨\n\n";
    }
    else{
        if(memberlist->getState(index)){
            memberlist->setState(0, index);
            cout <<"\n로그아웃 완료\n\n";
            *(curID) = "";
            *(curPW) = "";
        }
    }
}

/*

//=====================// LogoutControl //====================
//=====================// LogoutControl //====================

void LoginControl::Logout(MemberList* memberlist, string* curID, string* curPW){
    int index = memberlist->checkIDlist(*(curID), *(curPW));
    
    if(index < 0){
        cout << "그런 아이디 없다\n\n";
    }
    else{
        if(memberlist->getState(index)){
            memberlist->setState(-1, index);
            cout <<"\n로그아웃 완료\n\n";
        }
    }
}
 
 */

//=====================// DeleteAccountControl //====================
//=====================// DeleteAccountControl //====================

void DeleteAccountControl::call_startInterface(MemberList* memberlist, string* curID, string* curPW){
    //int index = memberlist->checkIDlist(*(curID), *(curPW));
    
    ui_deleteaccount = new DeleteAccountUI(this, memberlist, curID, curPW);
    
}

void DeleteAccountControl::deleteAccount(MemberList* memberlist, string* curID, string* curPW){
    int index = memberlist->checkIDlist(*(curID), *(curPW));
    
    if(index >= 0){
        //int newnumber = memberlist->getnumber() - 1;
        int oldnumber = memberlist->getnumber();
        memberlist->setNumMembers(0);
        for(int i = 0; i < index; i++){
            memberlist->addMember(memberlist->getMember(i));
        }
        for(int i = index + 1; i <= oldnumber; i++){
            memberlist->addMember(memberlist->getMember(i));
        }
    }
    else{
        cout << "\n<< WARNING : 로그인부터 하세요 >>\n\n";
    }
}
















