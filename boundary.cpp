#include "boundary.h"
#include "software.h"

//************************************** // UI // **************************************
//************************************** // UI // **************************************


//================================== UI_Apply =======================
//================================== UI_Apply =======================
void UI_Apply::selectDetail(string compName){

}



//================================== UI_Join =======================
//================================== UI_Join =======================

void UI_Join::createAccount(MemberList* mem, int type, string _name, int _serialnumber, string _id, string _pw){
    Member* _mem = new CompanyMember(type, _name, _serialnumber, _id, _pw);
    mem->addMember(_mem);
    cout << "회사회원 생성 완료\n\n";
}

void UI_Join::createAccount(MemberList* mem, int type, int _serial, string _id, string _pw){
    Member* _mem = new UserMember(type, _serial, _id, _pw);
    mem->addMember(_mem);
    cout << "일반 완료\n\n";
}





//************************************** // CONTROL // **************************************
//************************************** // CONTROL // **************************************



//================================== Register =======================
//================================== Register =======================
void Register::startInterface(){
    RegisterUI = new UI_Join();
}

void Register::addAccount(MemberList* mem, int type){
    if(type == 1){ //회사
        cout << "회사이름, 사원번호, 아이디, 비번 입력하세요\n";
        string name, id, pw;
        int serial;
        cin >> name >> serial >> id >> pw;
        RegisterUI->createAccount(mem, type, name, serial, id, pw);
    }
    else if(type == 0){//일반
        int serial;
        string id, pw;
        
        cout << "주민번호, 아이디, 비번 입력하세요\n";
        cin >> serial >> id >> pw;
        RegisterUI->createAccount(mem, type, serial, id, pw);
    }
}
