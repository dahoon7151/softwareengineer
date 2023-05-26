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
void UI_Register::startInterface(MemberList* memberlist){
    
    cout << "type 1 to register as a company member\ntype 2 to register as a user\n";
    int input = -1;
    cin >> input;
    this->addAccount(memberlist, input);
    
}

//RegisteraUI :: addAccount
void UI_Register::addAccount(MemberList* memberlist, int type){
    control_register->createAccount(memberlist, type); // UI에서 컨트롤 함수 실행
}


//=====================// LoginUI //====================
//=====================// LoginUI //====================
void UI_Login::startInterface(MemberList* memberlist, int type, string* curID, string* curPW){ //type ==1 : 로그인, type == 0 로그아웃
    cout << "Log-in UI\n";
    
    if(type == 1) this->LogIn(memberlist, curID, curPW);
    else this->LogOut(memberlist, curID, curPW);
}

void UI_Login::LogIn(MemberList* memberlist, string* curID, string* curPW){
    control_login->Login(memberlist, curID, curPW); //UI의 control 함수 호출 // (UI startInterface() -> UI LogIn() -> control Login())
}

void UI_Login::LogOut(MemberList* memberlist, string* curID, string* curPW){
    control_login->Logout(memberlist, curID, curPW);
    
}



//=====================// DeleteAccountUI //====================
//=====================// DeleteAccountUI //====================

void UI_DeleteAccount::startInterface(MemberList* memberlist, string* curID, string* curPW){
    cout << "DEL UI\n";
    this->DeleteAccount(memberlist, curID, curPW);
}

void UI_DeleteAccount::DeleteAccount(MemberList* memberlist,  string* curID, string* curPW){
    control_deleteAccount->deleteAccount(memberlist, curID, curPW);
}


//=====================// ApplyRecruitUI //====================
//=====================// ApplyRecruitUI //====================
void UI_ApplyRecruit::startInterface(MemberList* memberlist, RecruitInfoList* rec, string* curID, string* curPW){
    this->addRecruit(memberlist, rec, curID, curPW);
}

void UI_ApplyRecruit::addRecruit(MemberList* memberlist, RecruitInfoList* rec, string* curID, string* curPW){
    control_applyrecruit->addRecruit(memberlist, rec, curID, curPW);
}



//=====================// UserInfo //====================
//=====================// UserInfo //====================
void UI_UserInfo::startInterface(MemberList* memberlist, RecruitInfoList* rec, string* curID, string* curPW){
    cout << "USER INFO\n";
    this->printInfo(memberlist,rec,curID,curPW);
}
void UI_UserInfo::printInfo(MemberList* memberlist,RecruitInfoList* rec, string* curID, string* curPW){
    int index = memberlist->checkIDlist(*(curID), *(curPW));
    control_userinfo->printInfo(memberlist, index);
}



//=====================// DeleteApply //====================
//=====================// DeleteApply //====================
void UI_DeleteApply::startInterface(MemberList* memberlist, RecruitInfoList* rec, string* curID, string* curPW){
    cout << "DEL APPLY UI\n";
    UserMember* user = memberlist->getMember(memberlist->checkIDlist(*(curID), *(curPW)));
    user->showAllApplied();
    
    int input;
    cin >> input;
    
    this->DeleteApply(user, input);
}

void UI_DeleteApply::DeleteApply(UserMember* mem, int index){
    //드동안 등록한 어플라이 목록을 뽑아주는 과정이 필요함
    control_deleteapply->deleteApply(mem, index);
}


//=====================// Apply //====================
//=====================// Apply //====================

void UI_Apply::startInterface(MemberList* memberlist, RecruitInfoList* rec, string* curID, string* curPW){
    cout << "APPLY UI\n";
    this->Apply();
}

void UI_Apply::Apply(){
    control_apply->Apply();
}

//=====================// Search //====================
//=====================// Search //====================
void UI_Search::startInterface(MemberList* memberlist, RecruitInfoList* rec, string* curID, string* curPW){
    cout << "SEARCH UI\n";
    this->Search(rec);
}

void UI_Search::Search(RecruitInfoList* info){
    control_search->Search(info);
}


/*
 ############################################### // CONTROL // ########################################################################
 ############################################### // CONTROL // ########################################################################
 ############################################### // CONTROL // ########################################################################
 */


//=====================// RegisterControl //====================
//=====================// RegisterControl //====================


//RegisterControl :: call_startInterface()
void Control_Register::call_startInterface(MemberList* memberlist){
    ui_register = new UI_Register(this, memberlist); // Control에서 UI 생성자 호출
}


//RegisterControl :: createAccount
void Control_Register::createAccount(MemberList* memberlist, int type){
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
void Control_Login::call_startInterface(MemberList* memberlist, int type, string* curID, string* curPW){
    ui_login = new UI_Login(this, type, memberlist, curID, curPW);

}

//LoginControl :: Login
void Control_Login::Login(MemberList* memberlist, string* curID, string* curPW){
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
void Control_Login::Logout(MemberList* memberlist, string* curID, string* curPW){
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

void Control_DeleteAccount::call_startInterface(MemberList* memberlist, string* curID, string* curPW){
    //int index = memberlist->checkIDlist(*(curID), *(curPW));
    
    ui_deleteaccount = new UI_DeleteAccount(this, memberlist, curID, curPW);
    
}

void Control_DeleteAccount::deleteAccount(MemberList* memberlist, string* curID, string* curPW){
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



//=====================// ApplyRecruit Controll //====================
//=====================// ApplyRecruit Controll //====================
void Control_ApplyRecruit::call_startInterface(MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW){
    ui_applyrecruit = new UI_ApplyRecruit(this, memberlist, recruitlist, curID, curPW);
}

void Control_ApplyRecruit::addRecruit(MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW){
    //RecruitInfo(string _compname, int _Bn, string _task, int _applynum, int _deadline):taskApplied(0){
    cout << "\n업무 인원 기한\n";
    string ID = *(curID);
    string PW = *(curPW);
    
    int index = memberlist->checkIDlist(ID, PW);
    //Member* mem = memberlist->getCompMember(index);
    
    string _name ;
    int bn ;
    string _task;
    int an;
    int dl;
    
    cin >> _task >> an >> dl;
    RecruitInfo* rec = new RecruitInfo(_name, bn, _task, an, dl);
    cout <<"\n여기까진 성공\n";
     
    recruitlist->addRecruitInfo(rec);
}


void Control_Apply::call_startInterface(MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW){
    ui_apply = new UI_Apply(this, memberlist, recruitlist, curID, curPW);
}








//=====================// User Info Controll //====================
//=====================// User Info Controll //====================

void Control_UserInfo::call_startInterface(MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW){
    ui_userinfo = new UI_UserInfo(this, memberlist, recruitlist, curID, curPW);
}

void Control_UserInfo::printInfo(MemberList* memberlist, int index){
    UserMember* mem = memberlist->getMember(index);
    mem->sortList();
    cout << mem->getCompname(index) << "\n";
    cout << mem->getTask(index) << "\n";
    cout << mem->getHeads(index) << "\n";
    cout << mem->getDeadline(index) << "\n";
    
}



//=====================// Delete Apply Controll //====================
//=====================// Delete Apply Controll //====================
void Control_DeleteApply::call_startInterface(MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW){
    UI_deleteapply = new UI_DeleteApply(this, memberlist, recruitlist, curID, curPW);
}

void Control_DeleteApply::deleteApply(UserMember* mem, int index){
    int oldnum = mem->getAppliedNum();
    mem->setAppliedNum(index);
    for(int i = index + 1; i < oldnum; i++){
        mem->Apply(mem->getAppliedList(i));
    }
    cout << "삭제완료\n\n";
}


void Control_Apply::Apply(){
    
}


void Control_Search::call_startInterface(MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW){
    ui_search = new UI_Search(this, memberlist, recruitlist, curID, curPW);
}

void Control_Search::Search(RecruitInfoList* info){
    string name;
    cout << "검색하고자 하는 회사 이름:\n";
    cin >> name;
    info->show(name);
}







