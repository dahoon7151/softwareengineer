//
//  main.cpp
//  씨이발
//
//  Created by joo on 2023. 5. 26..
//  Copyright © 2023년 project1. All rights reserved.
//

#include <iostream>
#include "entity.h"
#include "boundary.h"

#define INPUT_FILE "example.txt"
#define OUTPUT_FILE "output.txt"

using namespace std;

// join()
void join(){
    
}


void program_exit(){
    cout << "sibal";
}



//==================================================================================================================
void doTask(){
    
    ControlList controls = ControlList();
    
    
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
                switch(menu_level_2){
                    case 1: //1.1 회원가입, 1 hankook 3456 hk pwd1 /OR/ 2 98765 hn pwd2
                    {
                        controls.generateControl(0);
                        break;
                    }
                    case 2://1.2 회원 탈퇴
                    {
            
                        controls.generateControl(1);
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
                        controls.generateControl(2);
                        break;
                    }
                    case 2: //2.2 로그아웃, hk
                    {
                        controls.generateControl(3);
                        break;
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





//==================================================================================================================


// 변수 선언

int main(){

    doTask();
    

    return 0;
}
