#include "entity.h"
#include "boundary.h"



using namespace std;

void doTask(){
    
    MemberList members;
    RecruitInfoList recruits;
    Member* pNewMember = NULL;
    string currentID  = "";
    string currentPW = "";
    
    int menu_level_1 = 0, menu_level_2=0;
    int is_program_exit = 0;
    
    while(!is_program_exit){
        
        cout << "1.1 회원 가입\n";
        cout << "1.2 회원 탈퇴\n";
        cout << "2.1 로그인\n";
        cout << "2.2 로그아웃\n";
        cout << "3.1 채용정보 등록\n";
        cout << "3.2 등록된 채용정보 좋회\n";
        cout << "4.1 채용 정보 검색\n";
        cout << "4.2 채용 지원\n";
        cout << "4.3 지원 정보 조회\n";
        cout << "5.1 지원 정보 통계\n";
        cout << "6.1 종료\n";
        
        cin >> menu_level_1;
        cin.ignore();
        cin >> menu_level_2;
        switch(menu_level_1){
            case 1:
            {
                Control_Register* control_Reg = new Control_Register();
                switch(menu_level_2){
                    case 1: //1.1 회원가입, 1 hankook 3456 hk pwd1 /OR/ 2 98765 hn pwd2
                    {
                        
                        control_Reg->call_startInterface(&members);
                        members.showAll(); //왜 안 되냐??
                        break;
                    }
                    case 2://1.2 회원 탈퇴
                    {
                        Control_DeleteAccount* control_deleteAccount = new Control_DeleteAccount();
                        control_deleteAccount->call_startInterface(&members, &currentID, &currentPW);
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                Control_Login* control_log = new Control_Login();
                switch(menu_level_2){
                    case 1: //2.1 로그인, hk pwd1
                    {
                        control_log->call_startInterface(&members, 1, &currentID, &currentPW);
                        break;
                    }
                    case 2: //2.2 로그아웃, hk
                    {
                        control_log->call_startInterface(&members, 0, &currentID, &currentPW);
                    }
                }
                break;
            }
            case 3:
            {
                Control_ApplyRecruit* control_applyrec = new Control_ApplyRecruit();
                switch(menu_level_2){
                    case 1: //3.1 채용 정보 등록
                    {
                        control_applyrec->call_startInterface(&members, &recruits, &currentID, &currentPW);
                    }
                    case 2: //3.2 등록된 채용 정보 조회
                    {
                        
                    }
                    
                }
                break;
            }
            case 4:
            {
                switch(menu_level_2){
                    case 1: //4.1 채용 정보 검색
                    {
                        
                    }
                    case 2: //4.2 채용 지원
                    {
                        
                    }
                    case 3: //4.3 지원 정보 조회
                    {
                        
                    }
                    case 4: //4.4 지원 취소
                    {
                        
                    }

                }
                break;
            }
            case 5:
            {
                switch(menu_level_2){
                    case 1: // 5.1 지원 정보 통계
                    {
                        
                    }
                }
                break;
            }
            case 6:
            {
                switch(menu_level_2){
                    case 1: // 6.1 종료
                    {
                        program_exit();
                        is_program_exit = 1;
                        break;
                        
                    }
                }
                break;
            }
        }
    }
}




// join()
void join(){
    
}


void program_exit(){
    cout << "sibal";
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************



//============================ Member Entity 관련 함수 ============================
// Member :: setType()
void Member::setType(int type)
{
    if(type == 1) type = 1; //회사 회원
    else type = 0; //일반 회원
}



// Member :: setState
void Member::setState(int _state){
    if(_state == 1){
        state = 1;
    }
    else if(_state == 0){
        state = 0;
    }
    else {}
}


// <<<<<<<<<<<<<<<<<<<<< FOR DEBUGGING >>>>>>>>>>>>>>>>>>>>>>>>
// Member :: show()
void Member::show(){
    cout << "\nID: " << ID << "\n" << "PW: " << PW << "\n\n" << endl;
}




//============================ RecruitInfoList 관련 함수 ============================
void RecruitInfoList::addRecruitInfo(RecruitInfo* recInfo){

    //RecruitInfo(string _compname, int _Bn, string _task, int _applynum, int _deadline):taskApplied(0){

    recruitlist[numRecruitInfo++] = recInfo;
}


//============================ MemberList 관련 함수 ============================

//MemberList :: addMember
void MemberList::addMember(Member* member){ //이거 포인터로 전달하기 실수!!
    memberList[numMembers++] = member;
}


//MemberList :: deleteMember
void MemberList::deleteMember(string _name){
    for(int i= 0; i < numMembers; i++){
        if(memberList[i]->Names()){
            memberList[i]->Names();
        }
    }
}


//MemberList :: checkIDlist
int MemberList::checkIDlist(string id, string pw){
    for(int i = 0; i < this->getnumber(); i++){
        if(memberList[i]->getID() == id){
            if(memberList[i]->getPW() == pw){
                //cout << "로그인 성공";
                return i; //인덱스를 반환
            }
        }
    }
    return -1;
}


//MemberList :: setState
void MemberList::setState(int _state, int index){
    memberList[index]->setState(_state);
}


//MemberList :: getState
int MemberList::getState(int index){
    return memberList[index]->getState(); // 로그인 상태 반환
}

Member* MemberList::getMember(int index){
    return memberList[index];
}


void MemberList::setNumMembers(int num){
    numMembers = num;
}



// <<<<<<<<<<<<<<<<<<<<< FOR DEBUGGING >>>>>>>>>>>>>>>>>>>>>>>>
//MemberList :: showAll()
void MemberList::showAll(){
    for (int i = 0; i < numMembers; i++){
        memberList[i]->show();
    }
}






















