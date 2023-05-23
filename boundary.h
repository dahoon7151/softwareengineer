#ifndef boundary_h
#define boundary_h

#include <iostream>
#include "software.h"
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
    void createAccount(MemberList* , int type,string, int, string, string); //회사 회원
    void createAccount(MemberList* , int type,int, string, string); //일반 회원

    
};


//==== UI_LogIN class
class UI_LogIn
{
private:
public:
    UI_LogIn(){ cout << "로그인 할 거예요\n"; }
    
    
};




//==== UI_Apply class
class UI_Apply
{
private:
    
public:
    void selectDetail(string);
    void selectApply();
    
};



// ****************************************************************************************
// *************************** // CONTROL // **********************************************


// ================ Register Control ================
class Register
{
private:
    UI_Join* RegisterUI;
    
public:

    void startInterface();
    void addAccount(MemberList* mem, int type);
    
    
};

class Logging
{
private:
    UI_LogIn* LogInUI;
public:
    void startInterface();
    void logOut();
    
};






#endif /* boundary_h */
