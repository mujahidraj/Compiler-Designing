
//token Categorization

#include<iostream>

using namespace std;

char numeric (char n){

cout<<"Numeric Constant"<<endl;


}

char alphanumeric (char a){

cout<<"Not Numeric Constant"<<endl;


}

int main (){

char x;

cin>>x;



if((x >= 'a'&& x <= 'z') || (x >= 'A' && x <= 'Z'))
{
    alphanumeric(x);
}
else
    numeric(x);

    return 0;
}





