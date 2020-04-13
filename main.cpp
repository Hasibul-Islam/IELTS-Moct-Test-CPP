#include <bits/stdc++.h>
#include<string>
using namespace std;
ofstream input;
ifstream output;
string CheckEmail="Default@gmail.com";
string CheckPassword;
string CurrentName="Default";
class Admin{

    string AdminName;
    string AdminEmail;
    string AdminPh;
    string AdminPass;
    string StudentName;
    string StudentEmail;
    string StudentPh;
    string StudentPass;
public:
    int AdminId;
    int StudentId;
    bool is_empty(ifstream& pFile){
        return pFile.peek() == ifstream::traits_type::eof();
    }
    //Add Test
    void AddTest(){
        if(AdminId==1){
            output.open("Tests.txt");
            int Checktest;
            int TestId;
            if(is_empty(output)){
                TestId=1;
            }
            else{
                while(!output.eof()){
                output>>Checktest;
                }
                TestId=Checktest+1;
            }
            output.close();
            input.open("Tests.txt",ios::app);
            input<<TestId<<endl;
            input.close();
            string TestLine;
            string TestAns;
            stringstream ss;
            ss<<TestId;
            string s;
            ss>>s;
            string TestName="Test-"+s+".txt";
            input.open(TestName.c_str());
            cout<<"ENTER PARAGRAPHS"<<endl;
            int font=65;
            for(int i=0;i<4;i++){
                getchar();
                cout<<"ENTER "<<i+1<<"th PARGRAPH"<<endl;
                getline(cin,TestLine);
                cout<<"ENTER AGAIN TO SAVE THIS PARAGRAPH"<<endl;
                input<<char(font)<<endl<<TestLine<<endl<<"#"<<endl;
                font++;
            }
            input<<"***"<<endl;
            input.close();
            font=65;
            input.open(TestName.c_str(),ios::app);
            for(int i=0;i<4;i++){
                getchar();
                cout<<"ENTER SHUFFLED PARGRAPH SUMMARY"<<endl;
                getline(cin,TestAns);
                cout<<"ENTER AGAIN TO SAVE THIS SUMMARY"<<endl;
                input<<"["<<char(font)<<"]"<<TestAns<<endl;
                font++;
            }
            input<<"---"<<endl;
            input.close();
            font=65;
            input.open(TestName.c_str(),ios::app);
            for(int i=0;i<4;i++){
                getchar();
                cout<<"ENTER "<<char(font)<<"th PARGRAPH ANSWER[I,E:A,B,C,D]"<<endl;
                getline(cin,TestAns);
                font++;
                cout<<"ENTER AGAIN TO SAVE THIS ANSWER"<<endl;
                input<<TestAns<<endl;
            }
            input.close();
            cout<<"TEST ADDED SUCCESSFULLY"<<endl;
        }
        else{
            cout<<"LOGIN TO ADD TEST"<<endl;
        }
    }



    //Add Admin

    void AddAdmin(){
        output.open("Admin.txt");
        if(AdminId==1||is_empty(output)){
            output.close();
            cout<<"FILL UP THE ADMIN FORM"<<endl;
            cout<<"ADMIN NAME: ";
            cin>>AdminName;
            cout<<endl;
            cout<<"ADMIN EMAIL: ";
            bool check=true;
            while(check){
                string s;
                cin>>AdminEmail;
                bool check1=true;
                output.open("Admin.txt");
                    if(!is_empty(output)){
                        while(!output.eof()){
                        output>>s;
                        if(s==AdminEmail){
                            cout<<"THIS EMAIL IS ALREADY IN USE"<<endl;
                        }
                        else{
                            check1=false;
                        }
                    }
                    }
                    else{
                        check1=false;
                    }
                    if(!check1){
                        check=false;

                    }
                    else{
                        cout<<"ADMIN EMAIL: ";
                    }
                }
            output.close();
            cout<<endl;
            cout<<"ADMIN PHONE: ";
            cin>>AdminPh;
            cout<<endl;
            cout<<"ADMIN PASSWORD: ";
            cin>>AdminPass;
            cout<<endl;
            input.open("Admin.Txt",ios::app);
            input<<AdminEmail<<"\n"<<AdminName<<"\n"<<AdminPh<<"\n"<<AdminPass<<endl;
            input.close();
        }
        else{
            cout<<"PLEASE LOG IN TO ADD ADMIN"<<endl;
        }
    }

    //Admin Login

    void IsAdminLoggedIn(){
        output.open("Admin.Txt");
        if(!is_empty(output)){
        string Email;
        string Pass;
        cout<<"ENTER EMAIL AND PASSWORD TO LOGIN"<<endl;
        cout<<"EMAIL: ";
        cin>>Email;
        cout<<"PASSWORD: ";
        cin>>Pass;
        bool IsCheckedEmail=false;
        bool IsCheckedPassword=false;
        while(!output.eof()){
            if(!IsCheckedEmail){
                output>>CheckEmail;
            }
            if(CheckEmail==Email){
                IsCheckedEmail=true;
            }
            if(!IsCheckedPassword){
                output>>CheckPassword;
            }
            if(CheckPassword==Pass){
                IsCheckedPassword=true;
                break;
            }
        }
        if(IsCheckedEmail&&IsCheckedPassword){
            cout<<"WELCOME ";;
            AdminId=1;
            int cnt=0;
            string Emailcheck;
            while(!output.eof()){
                output>>CurrentName;
                output>>Emailcheck;
                if(cnt==1){
                    break;
                }
                if(Emailcheck==CheckEmail){
                    cnt++;
                }
            }
            cout<<CurrentName<<endl;
        }
        else{
            cout<<"ENTER VALIED EMAIL AND PASSWORD"<<endl;
            AdminId=2;
            IsAdminLoggedIn();
        }
        output.close();
    }
    else{
        cout<<"NO ADMIN AVAILABLE\nCREATE A NEW ADMIN?\nY/N"<<endl;
        char c;
        cin>>c;
        if(c=='Y'){
            AddAdmin();
        }
        else{
            StudentId=2;
        }
    }
    }

    //Edit Admin

    void EditAdmin(){
        if(AdminId==1){
            cout<<"ENTER ADMIN EMAIL TO EDIT: ";
            string Email;
            cin>>Email;
            bool checkfind=false;
            int cnt=0;
            int cnt2=0;
            string line;
            output.open("Admin.txt");
            input.open("temp.txt");
            while(!output.eof()){
                output>>line;
                if(line==Email){
                    checkfind=true;
                    cnt2++;
                    cnt++;
                }
                else{

                    checkfind=false;
                    if(cnt>0&&cnt<5){
                        cnt++;
                    }
                    else if(cnt==5){
                        cnt=0;
                    }
                    else if(cnt==0){
                        input<<line<<endl;
                    }
                }
                if(checkfind){
                    cout<<"Yes"<<endl;
                    cout<<"FILL UP THE ADMIN FORM"<<endl;
                    cout<<"ADMIN NAME: ";
                    cin>>AdminName;
                    cout<<endl;
                    cout<<"ADMIN EMAIL: ";
                    bool check=true;
            while(check){
                string s;
                cin>>AdminEmail;
                bool check1=true;
                output.open("Admin.txt");
                    while(!output.eof()){
                        output>>s;
                        if(s==AdminEmail){
                            cout<<"THIS EMAIL IS ALREADY IN USE"<<endl;
                        }
                        else{
                            check1=false;
                        }
                    }
                    if(!check1){
                        check=false;
                    }
                }

                    cout<<endl;
                    cout<<"ADMIN PHONE: ";
                    cin>>AdminPh;
                    cout<<endl;
                    cout<<"ADMIN PASSWORD: ";
                    cin>>AdminPass;
                    cout<<endl;
                    input<<AdminEmail<<"\n"<<AdminName<<"\n"<<AdminPh<<"\n"<<AdminPass<<endl;
                }

            }
             if(cnt2==0){
                cout<<"NOT FOUND"<<endl;
             }
             output.close();
             input.close();

             remove("Admin.txt");
             rename("temp.txt", "Admin.txt");
        }
        else{
            cout<<"LOGIN TO UPDATE ADMIN"<<endl;
        }
    }

    //Delete Admin

    void DeleteAdmin(){
        if(AdminId==1){
            cout<<"ENTER ADMIN EMAIL TO DELETE: ";
            string Email;
            cin>>Email;
            bool checkfind=false;
            int cnt=0;
            int cnt2=0;
            string line;
            output.open("Admin.txt");
            input.open("temp.txt");
            while(!output.eof()){
                output>>line;
                if(line==Email){
                    checkfind=true;
                    cnt2++;
                    cnt++;
                }
                else{
                    checkfind=false;
                    if(cnt>0&&cnt<5){
                        cnt++;
                    }
                    else if(cnt==5){
                        cnt=0;
                    }
                    else if(cnt==0){
                        input<<line<<endl;
                    }
                }

            }
             if(cnt2==0){
                cout<<"NOT FOUND"<<endl;
             }
             output.close();
             input.close();

             remove("Admin.txt");
             rename("temp.txt", "Admin.txt");
        }
        else{
            cout<<"LOGIN TO UPDATE ADMIN"<<endl;
        }
    }
    void AdminLogout(){
        AdminId=2;
    }

    //Add Student


    void AddStudent(){
        if(AdminId==1){
            cout<<"FILL UP THE STUDENT FORM"<<endl;
            cout<<"STUDENT NAME: ";
            cin>>StudentName;
            cout<<endl;
            cout<<"STUDENT EMAIL: ";
            output.open("Student.txt");
            if(!is_empty(output)){
            bool check=true;
            while(check){
                string s;
                cin>>StudentEmail;
                bool check1=true;
                output.open("Student.txt");
                    if(!is_empty(output)){
                        while(!output.eof()){
                        output>>s;
                        if(s==StudentEmail){
                            cout<<"THIS EMAIL IS ALREADY IN USE"<<endl;
                        }
                        else{
                            check1=false;
                        }
                    }
                    }
                    else{
                        check1=false;
                    }
                    if(!check1){
                        check=false;
                    }
                    else{
                        cout<<"STUDENT EMAIL: "<<endl;
                    }
                }
            }
            else{
                cin>>StudentEmail;
            }
            cout<<endl;
            cout<<"STUDENT PHONE: ";
            cin>>StudentPh;
            cout<<endl;
            cout<<"STUDENT PASSWORD: ";
            cin>>StudentPass;
            string s="%";
            s=s+StudentPass;
            StudentPass=s;
            cout<<endl;
            input.open("Student.Txt",ios::app);
            input<<StudentEmail<<"\n"<<StudentName<<"\n"<<StudentPh<<"\n"<<StudentPass<<endl;
            input.close();
        }
        else{
            cout<<"PLEASE LOG IN TO ADD STUDENT"<<endl;
        }
    }

    //Update Student

    void EditStudent(){
        if(AdminId==1){
            cout<<"ENTER STUDENT EMAIL TO EDIT: ";
            string Email;
            cin>>Email;
            bool checkfind=false;
            int cnt=0;
            int cnt2=0;
            string line;
            output.open("Student.txt");
            input.open("temp2.txt");
            while(!output.eof()){
                output>>line;
                if(line==Email){
                    checkfind=true;
                    cnt2++;
                    cnt++;
                }
                else{
                    checkfind=false;
                    if(cnt>0&&cnt<5){
                        cnt++;
                    }
                    else if(cnt==5){
                        cnt=0;
                    }
                    else if(cnt==0){
                        input<<line<<endl;
                    }
                }
                if(checkfind){
                    cout<<"Yes"<<endl;
                    cout<<"FILL UP THE STUDENT FORM"<<endl;
                    cout<<"ADMIN NAME: ";
                    cin>>StudentName;
                    cout<<endl;
                    cout<<"ADMIN EMAIL: ";
                    bool check=true;
                    while(check){
                        string s;
                        cin>>StudentEmail;
                        bool check1=true;
                        while(!output.eof()){
                            output>>s;
                            if(s==StudentEmail){
                                cout<<"THIS EMAIL IS ALREADY IN USE"<<endl;
                            }
                            else{
                                check1=false;
                            }
                        }
                        if(!check1){
                            check=false;
                        }
                    }
                    cout<<endl;
                    cout<<"ADMIN PHONE: ";
                    cin>>StudentPh;
                    cout<<endl;
                    cout<<"ADMIN PASSWORD: ";
                    cin>>StudentPass;
                    cout<<endl;
                    input<<StudentEmail<<"\n"<<StudentName<<"\n"<<StudentPh<<"\n"<<StudentPass<<endl;
                }

            }
             if(cnt2==0){
                cout<<"NOT FOUND"<<endl;
             }
             output.close();
             input.close();

             remove("Student.txt");
             rename("temp2.txt", "Student.txt");
        }
        else{
            cout<<"LOGIN TO UPDATE STUDENT"<<endl;
        }
    }

    //Delete Student
    void DeleteStudent(){
        if(AdminId==1){
            cout<<"ENTER STUDENT EMAIL TO DELETE: ";
            string Email;
            cin>>Email;
            bool checkfind=false;
            int cnt=0;
            int cnt2=0;
            string line;
            output.open("Student.txt");
            input.open("temp2.txt");
            while(!output.eof()){
                output>>line;
                if(line==Email){
                    checkfind=true;
                    cnt2++;
                    cnt++;
                }
                else{
                    checkfind=false;
                    if(cnt>0&&cnt<5){
                        cnt++;
                    }
                    else if(cnt==5){
                        cnt=0;
                    }
                    else if(cnt==0){
                        input<<line<<endl;
                    }
                }

            }
             if(cnt2==0){
                cout<<"NOT FOUND"<<endl;
             }
             output.close();
             input.close();

             remove("Student.txt");
             rename("temp2.txt", "Student.txt");
        }
        else{
            cout<<"LOGIN TO DELETE STUDENT"<<endl;
        }
    }

    //View Students

    void ViewStudents(){
        output.open("Student.txt");
        if(!is_empty(output)){
            string line;
            while(!output.eof()){
                output>>line;
                if(line[0]=='%'){
                    continue;
                }
                cout<<line<<endl;
            }
            cout<<endl<<endl;
            output.close();
        }
        else{
            output.close();
            cout<<"NO STUDENT AVAILABLE\nADD A STUDENT?\nY/N"<<endl;
            char c;
            cin>>c;
            if(c=='Y'){
                AddStudent();
            }
        }
    }

};

class Student:public Admin{
public:
    //Student Login

    void IsStudentLoggedIn(){
        output.open("Student.txt");
        if(!is_empty(output)){
        output.close();
        string Email;
        string Pass;
        cout<<"ENTER EMAIL AND PASSWORD TO LOGIN"<<endl;
        cout<<"EMAIL: ";
        cin>>Email;
        cout<<"PASSWORD: ";
        cin>>Pass;
        string s="%";
        s=s+Pass;
        Pass=s;
        output.open("Student.txt");
        bool IsCheckedEmail=false;
        bool IsCheckedPassword=false;
        while(!output.eof()){
            if(!IsCheckedEmail){
                output>>CheckEmail;
            }
            if(CheckEmail==Email){
                IsCheckedEmail=true;
            }
            if(!IsCheckedPassword){
                output>>CheckPassword;
            }
            if(CheckPassword==Pass){
                IsCheckedPassword=true;
                break;
            }
        }
        output.close();
        if(IsCheckedEmail&&IsCheckedPassword){
            cout<<"WELCOME ";;
            StudentId=1;
            int cnt=0;
            string Emailcheck;
            output.open("Student.txt");
            while(!output.eof()){

                //cout<<CurrentName<<" "<<Emailcheck<<endl;
                output>>Emailcheck;
                if(cnt==1){
                    break;
                }
                if(Emailcheck==CheckEmail){
                    cnt++;
                }
                output>>CurrentName;
            }
            cout<<CurrentName<<endl;
            output.close();
        }
        else{
            cout<<"ENTER VALIED EMAIL AND PASSWORD"<<endl;
            StudentId=2;
            IsStudentLoggedIn();
        }
    }
    else{
        cout<<"NO STUDENT AVAILABLE\nCREATE A NEW ADMIN?\nY/N"<<endl;
        char c;
        cin>>c;
        if(c=='Y'){
            AddStudent();
        }
        else{
            StudentId=2;
        }
    }
}
    //Student Logout
    void StudentLogout(){
        StudentId=2;
    }

    //Attempt Test
    void StudentResult(){
        if(StudentId==1){
            string ResultName="Result_of_"+CheckEmail+".txt";
            string line;
            output.open(ResultName.c_str());
            if(!is_empty(output)){
                while(!output.eof()){
                    output>>line;
                    if(line=="#"){
                        cout<<endl;
                    }
                    else{
                        cout<<line<<" ";
                    }
            }
            }
            else{
                cout<<"ATTEMPT ANY TEST TO VIEW YOUR RESULT"<<endl;
            }

        }
        else{
            cout<<"LOG IN TO VIEW YOUR RESULT"<<endl;
        }
    }
    void AttemptTest(){
        if(StudentId==1){
            output.open("Tests.txt");
            if(is_empty(output)){
               cout<<"NO TEST AVAILABLE"<<endl;
            }
            else{
            int TestId;
            int c=0;
            while(!output.eof()){
                output>>TestId;
                c++;
            }
            output.close();
            output.open("Tests.txt");
            while(!output.eof()){
                output>>TestId;
                c--;
                if(c==0){
                    break;
                }
                cout<<"TEST NO: "<<TestId<<endl;
            }
            output.close();
            cout<<"ENTER TEST NO TO ATTEMPT"<<endl;
            int NewTestId;
            cin>>NewTestId;
            stringstream ss;
            ss<<NewTestId;
            string s;
            ss>>s;
            string TestName="Test-"+s+".txt";
            output.open(TestName.c_str());
            string line;
            while(!output.eof()){
                output>>line;
                if(line=="#"){
                    cout<<endl;
                }
                else if(line=="---"){
                    break;
                }
                else if(line=="***"){
                    continue;
                }
                else{
                    cout<<line<<" ";
                }
            }
            cout<<endl;
            output.close();
            stringstream sss;
            sss<<CheckEmail;
            string pp;
            sss>>pp;
            string ResultName="Result_of_"+pp+".txt";
            output.open(TestName.c_str());
            int cnt=0;
            string ans[10];
            int hehe=65;
            for(int i=0;i<4;i++){
                cout<<"ENTER THE ANSWER OF PARAGRAPH "<<char(hehe)<<endl;
                hehe++;
                cin>>ans[i];
            }
            int j=0;
            bool checkans=false;
            while(!output.eof()){
                output>>line;
                if(line=="---"){
                    checkans=true;
                }
                if(checkans==true){
                    if(ans[j]==line){
                        cnt++;
                        j++;
                    }
                }
            }
            output.close();
            output.open(ResultName.c_str());
            if(is_empty(output)){
                input.open(ResultName.c_str());
                input<<"RESULT OF "<<CurrentName<<" # "<<endl;
                input.close();
            }
            input.open(ResultName.c_str(),ios::app);
            input<<"RESULT OF TEST "<<TestId<<" : "<<cnt<<" OUT OF 4 #"<<endl;
        }
        output.close();
      }
      else{
        cout<<"PLEASE LOG IN TO ATTEMPT TEST"<<endl;
      }
    }
};
int main()
{
    cout<<"[1] STUDENT"<<endl;
    cout<<"[2] ADMIN"<<endl;
    cout<<"[3] ABOUT US"<<endl;
    cout<<"[4] EXIT"<<endl;
    cout<<"\n\n SELECT ANY"<<endl;
    while(true){
        int select;
        cin>>select;
        if(select==2){
            Admin admin;
            admin.IsAdminLoggedIn();
            while(true){
            if(admin.AdminId==1){
                cout<<"[1] ADD STUDENT"<<endl;
                cout<<"[2] EDIT STUDENT"<<endl;
                cout<<"[3] DELETE STUDENT"<<endl;
                cout<<"[4] ADD ADMIN"<<endl;
                cout<<"[5] EDIT ADMIN"<<endl;
                cout<<"[6] DELETE ADMIN"<<endl;
                cout<<"[7] VIEW STUDENTS"<<endl;
                cout<<"[8] LOGOUT"<<endl;
                cout<<"SELECT ANY"<<endl;
                int sel2;
                cin>>sel2;
                system("CLS");
                if(sel2==1){
                    admin.AddStudent();
                }
                else if(sel2==2){
                    admin.EditStudent();
                }
                else if(sel2==3){
                    admin.DeleteStudent();
                }
                else if(sel2==4){
                    admin.AddAdmin();
                }
                else if(sel2==5){
                    admin.EditAdmin();
                }
                else if(sel2==6){
                    admin.DeleteAdmin();
                }
                else if(sel2==7){
                    admin.ViewStudents();
                }
                else{
                    admin.AdminLogout();
                    break;
                }
            }
            else{
                break;
            }
          }
        }
        else if(select==1){
            Student student;
            student.IsStudentLoggedIn();
            while(true){
                if(student.StudentId==1){
                    cout<<"[1] ATTEMPT TEST"<<endl;
                    cout<<"[2] VIEW RESULT"<<endl;
                    cout<<"[3] LOGOUT"<<endl;
                    cout<<"SELECT ANY"<<endl;
                    int sel3;
                    cin>>sel3;
                    system("CLS");
                    if(sel3==1){
                        student.AttemptTest();
                    }
                    else if(sel3==2){
                        student.StudentResult();
                    }
                    else{
                        student.StudentLogout();
                        break;
                    }
                }
                else{
                    break;
                }
            }
        }
        else if(select==3){
            cout<<"PORJECT DEVELOPED BY THE POWER PUFFED GIRLS!!!"<<endl;
            getchar();
            system("CLS");
        }
        else{
            break;
        }
        cout<<"[1] STUDENT"<<endl;
        cout<<"[2] ADMIN"<<endl;
        cout<<"[3] ABOUT US"<<endl;
        cout<<"[4] EXIT"<<endl;
        cout<<"\n\n SELECT ANY"<<endl;
    }
    return 0;
}
