#include "../Headers/User.h"

int User::count=0;

User::User(){
    name="";
    age=0;
    password="";
    email="";
    count++;
    id = count;
    //cout << "u"<< id <<endl;
}

User::User(string a, int b, string c, string d){
    name=a;
    age=b;
    password=c;
    email=d;
    count++;
    id = count;
}

User::User(const User &user){
    name= user.name;
    age= user.age;
    password= user.password;
    email= user.email;
    id = user.id;
}

void User::setName(string n){
    name = n;
}

string User::getName() const{
    return name;
}
/////////////////////////////////////
void User::setPassword(string n){
    password = n;
}
 
string User::getPassword() const{
    return password;
}
/////////////////////////////////////
void User::setAge(int n){
    age = n;
}

int User::getAge() const{
    return age;
}
/////////////////////////////////////
void User::setEmail(string n){
    email = n;
}

string User::getEmail() const{
    return email;
}
/////////////////////////////////////
void User::setId(int n){
    id = n;
}

int User::getId() const{
    return id;
}
/////////////////////////////////////
bool User::operator==(const User& user){
    if(this->name!=user.name || this->email!=user.email || this->age != user.age ||this->id != user.id){
        return false;
    }
    return true;
}
/////////////////////////////////////
void User::operator=(const User& user){
    this->name=user.name;
    this->email=user.email;
    this->age = user.age;
    this->password = user.password;
}
/////////////////////////////////////
istream &operator>>(istream &input, User &user){
    cout<<"Enter the user information in the order"<< endl;
    cout<<"name "<<" age "<<" email "<<" password melek";
    cout<<" (space separation)"<<endl;
    input>> user.name  >> user.age >> user.email >> user.password ;
    return input;
}


////////////////////////////////////
ostream &operator<<(ostream &output, const User &user){
    output<<"============User "<<user.id<<" info ============"<<endl;
    output<<"name : " << user.name;
    output<<" | Age : "<<user.age;
    output<<" | Id : "<<user.id;
    output<<" | Email : "<<user.email<< endl;
    cout<<"================================="<<endl;
    return output;
}
