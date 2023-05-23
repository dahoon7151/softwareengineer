#include "software.h"
#include "boundary.h"



using namespace std;

void doTask(){
    
    MemberList members;
    Member* pNewMember = NULL;
    
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
                Register* control_Reg = new Register();
                switch(menu_level_2){
                    case 1: //1.1 회원가입, 1 hankook 3456 hk pwd1 /OR/ 2 98765 hn pwd2
                    {
                        
                        control_Reg->startInterface();
                        cout << "type 1 to register as a company member\ntype 2 to register as a User";
                        int input = -1;
                        cin >> input;
                        if(input == 1){

                            control_Reg->addAccount(&members, input);
                            cin.ignore();
                        
                        }
                        else{
                            control_Reg->addAccount(&members, input);
                            cin.ignore();
                        }
                        members.showAll(); //왜 안 되냐??
                        break;
                    }
                    case 2://1.2 회원 탈퇴
                    {
                        
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                switch(menu_level_2){
                    case 1: //2.1 로그인, hk pwd1
                    {
                        
                    }
                    case 2: //2.2 로그아웃, hk
                    {
                        
                    }
                }
                break;
            }
            case 3:
            {
                switch(menu_level_2){
                    case 1: //3.1 채용 정보 등록
                    {
                        
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


void Member::show(){
    cout << "ID: " << ID << "\n" << "PW: " << PW << "\n" << endl;
}


void MemberList::addMember(Member* member){
    memberList[numMembers++] = member;
}

void MemberList::deleteMember(string _name){
    for(int i= 0; i < numMembers; i++){
        if(memberList[i]->Names()){
            memberList[i]->Names();
        }
    }
}

void MemberList::showAll(){
    for (int i = 0; i < numMembers; i++){
        memberList[i]->show();
    }
}






















