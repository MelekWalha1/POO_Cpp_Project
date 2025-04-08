#ifndef USERLIST_H_INCLUDED
#define USERLIST_H_INCLUDED

#include<iostream>
#include<string.h>

#include "../Headers/User.h"

using namespace std;
class UserList
{
 private:
         User* users;
         int capacity;
         int usersCount;
 public:
         UserList();
         UserList(int );
         void addUser(User &); 
         User* searchUser(string );
         User* searchUser(int );
         void deleteUser(int );
         friend ostream &operator<<( ostream& ,const UserList&);
         ~UserList();
};

#endif