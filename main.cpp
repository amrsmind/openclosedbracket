#include <iostream>
#include <stack>

using namespace std;

bool checkclosing(char open,char close){
if(open=='(' &&close==')'){
    return true;
}
if(open=='[' &&close==']'){
    return true;
}
if(open=='{' &&close=='}'){
    return true;
}
return false;
}

string checkbrackets(string input){

stack<char> strstack;
int i=0;
int size = input.size();
bool comment=0;
bool validopen = 0;
bool validclose = 0;
while(i<size){
   if(comment){
    if(i==size-1){
        return "invalid";
    }
    if(input[i]=='*' && input[i+1]=='/'){
        comment=0;
        i+=2;
        continue;
    }
    i++;
    continue;
   }
   else if(!comment){
   if(input[i] == '/'){
       if(i==size-1){
        return "invalid";
       }
        if(input[i+1]=='*'){
    comment = 1;
    i+=2;
    continue;}
    return "invalid";
   }
   if(input[i]=='(' || input[i]=='[' || input[i]=='{'){
        strstack.push(input[i]);
        i++;
        continue;
   }
   else if(input[i]==')' || input[i]==']' || input[i]=='}'){
        if(i==size-1 &&strstack.empty()){
            return "invalid";
        }
       if(checkclosing(strstack.top(),input[i])){
        strstack.pop();
        i++;
        continue;
       }
       else{
        return "invalid";
       }
   }
   else{
    return "invalid";
   }
    i++;
}
}
if(comment){
    return "invalid";
}
if(strstack.empty())
return "valid";
return "invalid";
}
int main()
{
    string test0 = "([{}])(){}[]{[]}";
    string test1 = "({)}";
    string test2 = "({/*)}]]]]]]}*/})";
    string test3 = "({/*[][[]]]]]})";
    string test4 = "[{/*******/}]";
    cout<<checkbrackets(test0)<<endl;
    cout<<checkbrackets(test1)<<endl;
    cout<<checkbrackets(test2)<<endl;
    cout<<checkbrackets(test3)<<endl;
    cout<<checkbrackets(test4)<<endl;


    //checkbrackets(test);(){}[]{[]}
   //checkbrackets("askfmklsmdflkasmf");
//   stack<char> strstack;
//   string test = "sdaf";
//   strstack.push(test[0]);
//   strstack.push(test[1]);
//   cout<<strstack.top()<<endl;



    return 0;
}
