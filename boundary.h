#ifndef boundary_h
#define boundary_h

#include <iostream>
#include "software.h"
#include "controls.h"
#include <fstream>
#include <sstream>


using namespace std;


// **************************************************************************
// **************************************************************************
// 클래스 선언


//==== UI_Join class
class UI_Join{
private:
    
public:
    
    UI_Join(){
        cout << "생성 축하\n";
    }
    void createAccount(MemberList, string, int, string, string); //회사 회원
    void createAccount(MemberList, int, string, string); //일반 회원

    
};



//==== UI_Apply class
class UI_Apply
{
private:
    
public:
    void selectDetail(string);
    void selectApply();
    
};


class Register
{
private:
    UI_Join* RegisterUI;
    
public:

    void startInterface();
    void addAccount(MemberList mem, int type);
    
    
};






#endif /* boundary_h */
