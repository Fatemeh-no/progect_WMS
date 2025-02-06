#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>//setw
#include <cctype>//tolower

using namespace std;
struct User{
     string name;
     string pasword;
     int wallet=10;
     bool admin=false;
};

struct fruit{
    string name ;
    int number,price;
    
};

string lower(string n){
    for(int i=0;i<n.length();i++){
        n[i]=tolower(n[i]);
    }
    return n;
}
void buy(string& filename ,string& filename2 ,string n){
       fstream temp(filename2 , ios::in |ios::out);
       fstream fa(filename , ios::in|ios::out);
       string name;
       int f , p;
       if(fa.is_open() &&temp.is_open()){
       while (!fa.eof())
       {  fa>>name>>f>>p;
         if(name==n){
            
            f-=1;
         }
         temp<<name<<setw(17-name.length())<<f<<setw(7)<<p;
         if(name!="endd"){
            temp<<endl;
           
         }else{
           break;
         }

       }
       temp.close();
       fa.close();
      
      }else{
        cout<<"have problm with opening file"<<endl;
      }
       
} 
void copy(string& filename ,string& filename2){
    fstream fafa(filename , ios::out);
    fstream temp(filename2 , ios::in);
    if(fafa.is_open() && temp.is_open()){
    string name;
    int f ,p;
    while (!temp.eof())
    {
        temp>>name>>f>>p;
        fafa<<name<<setw(17-name.length())<<f<<setw(7)<<p;
         if(name!="endd"){
            fafa<<endl;
           
         }else{
           break;
         }
    }
    fafa.close();
    temp.close();
     fafa.open(filename , ios::out | ios::in);
    
    }else{
        cout<<"something wrong with opening file"<<endl;
    }
    
}
void addnew(string& input , string& temp , string n , string p){
      fstream fafa(input ,ios::in);
      fstream fafa2(temp , ios::out);
      string name , f , s;
      if(fafa.is_open() && fafa2.is_open())
     { while (!fafa.eof())
      {
        fafa>>name>>f>>s;
        if(name=="endd"){
             fafa2<<n<<setw(10)<<1<<setw(7)<<p<<endl;
        }
         fafa2<<name<<setw(10)<<f<<setw(7)<<s;
           if(name!="endd"){
             fafa2<<endl;
               
        }else{
           break;
        }
      }
      fafa.close();
      fafa2.close();
}
else{
    cout<<"something wrong with opening file"<<endl;
}
}
void removee(string& input , string& temp , string n){
      fstream fafa(input ,ios::in);
      fstream fafa2(temp , ios::out);
      string name , f , s;
      if(fafa.is_open() && fafa2.is_open())
     { while (!fafa.eof())
      {
        fafa>>name>>f>>s;
        if(name==n){
             continue;
        }else{
         fafa2<<name<<setw(10)<<f<<setw(7)<<s;
          if(name!="endd"){
             fafa2<<endl;   }
        } 
        if(name=="endd"){
             break;  }
      }
      fafa.close();
      fafa2.close();
}
else{
    cout<<"something is wrong with opening file"<<endl;
}
}
void rename(string& input , string& temp , string n1 , string n2 ){
      fstream fafa(input ,ios::in);
      fstream fafa2(temp , ios::out);
      string name , f , s;
      if(fafa.is_open() && fafa2.is_open())
     { while (!fafa.eof())
      {
        fafa>>name>>f>>s;
        if(name==n1){
             fafa2<<n2<<setw(10)<<f<<setw(7)<<s<<endl;
        }else{
         fafa2<<name<<setw(10)<<f<<setw(7)<<s;
           if(name!="endd"){
             fafa2<<endl;
        }else{
          break;
        }
        }
      }
      fafa.close();
      fafa2.close();
}
else{
    cout<<"something is wrong with opening file!"<<endl;
}
}
void price(string& input , string& temp , string n1 , string n2 ){
      fstream fafa(input ,ios::in);
      fstream fafa2(temp , ios::out);
      string name , f , s;
      if(fafa.is_open() && fafa2.is_open())
     { while (!fafa.eof())
      {
        fafa>>name>>f>>s;
        if(name==n1){
             fafa2<<n1<<setw(10)<<f<<setw(7)<<n2<<endl;
        }else{
         fafa2<<name<<setw(10)<<f<<setw(7)<<s;
           if(name!="endd"){
             fafa2<<endl;
        }else{
          break;
        }
        }
      }
      fafa.close();
      fafa2.close();
}
else{
    cout<<"something wrong with opening file"<<endl;
}
}
bool there_is(string& filename ,string n ){
    fstream fa(filename , ios::in|ios::out);
   
       fa.close();
       fa.open(filename , ios::in|ios::out);
       string name , f ,s;
       int x=0;
      while(!fa.eof()){
         fa>>name>>f>>s;
         if(name==n){
            x+=1;
         }
      }
     bool r;
     if(x==0){
       r=false;
     }else{
      r=true;
     }
   fa.close();
  return r;
}



int main(){
  string input ="input.txt";
  string temp = "temp.txt";
   fstream in("input.txt", ios::in);
    if(!in){
        cout<<"Error";
    }
     fstream out("output.txt", ios::out);
    if(!out){
        cout<<"Error";
    }
     
    
    //************************************************************ 
    //معرفی مدیر و مشتری ها
    User* user = new User[5];
      user[0].name="simin";
      user[0].pasword="si1111";
      user[0].admin=true;
      user[1].name="fatemeh";
      user[1].pasword="fa2222";
      user[1].admin=true;
      user[2].name="mehrdad";
      user[2].pasword="me3333";
      user[3].name="nikan";
      user[3].pasword="ni4444";
      user[4].name="ninaa";
      user[4].pasword="555555";
//***********************************************************
    string name, pasword;
    cout<<"Enter your username: ";
    cin>>name;
    cout<<"Enter your password: ";
    cin>>pasword;
    string order1 , order2="-1";
    int i=0;
    while(i<5){
      User* us=&user[i];
      i+=1;
      if(us->name==name && us->pasword==pasword){
        if(us->admin){//if1*****************************manager
          cout<<"Enter -1 to exit"<<endl;
          for(;;){
            string order3;
             cout<<"$ ";cin>>order1;
             if(order1=="-1"){
              break;
             }
             order1 = lower(order1);
             // add newww
             if(order1=="add"){

              cin>>order2;lower(order2);
              cin>>order3;lower(order3);
                 addnew(input , temp , order2 , order3);
                 copy(input , temp);
                in.close();
                in.open("input.txt" , ios::in|ios::out);

             }
            //removeee
            else if (order1=="remove")
            {
                cin>>order2;lower(order2);
                removee(input , temp , order2);
                copy(input , temp);
                in.close();in.open("input.txt" , ios::in|ios::out);
              
            }
            else if(order1=="rename"){
             
              cin>>order2>>order3;lower(order2);lower(order3);
               if(there_is(input , order2)){
              rename(input , temp , order2 , order3);
              copy(input , temp);
               in.open("input.txt" , ios::in |ios::out);}
               else{
                cout<<"we have not it"<<endl;
               }
            }
            else if(order1=="price"){
                cin>>order2>>order3;lower(order2);lower(order3);

                if(there_is(input , order2)){
                price(input , temp , order2 , order3);
                copy(input , temp);
                in.open("input.txt" , ios::in |ios::out);}else{
                  cout<<"we have not that"<<endl;
                }
            }
            else if(order1=="credit"){
              int order3;
                cin>>order2>>order3;
                bool r=true;
                for(int i=2;i<5;i++){
                  if(user[i].name==order2){
                    user[i].wallet+=order3;
                    r=false;
                    break;
                  }
                }
                if(r){
                  cout<<"have not that user"<<endl;
                }
            }else{
              cout<<"is not a right order!!!"<<endl;
            }
          }
        
        }//if1***************************************
        else{//else1***********************costummer
           cout<<"Enter -1 to exit"<<endl;
          while(true){
             cout<<"# ";
             cin>>order1;
             
             if(order1=="-1"){//if2**************
              break;
             }//if2**************
             
             order1 = lower(order1);
            
            
             bool right=false;
              
              if(order1=="buy"){
                  string name;int f,s;
                  in.close();
                  in.open("input.txt" , ios::in | ios::in);
                  cin>>order2;lower(order2);
                  while(!in.eof()){
                    in>>name>>f>>s;
                    if(order2==name){
                          if(f>0){
                               if(us->wallet >=s){
                                   us->wallet -=s;
                                  buy(input, temp , name);
                                  copy(input,temp);
                                  in.close();
                                  in.open("input.txt" , ios::in|ios::out);
                                  cout<<"An/a "<<name<<" was sold to you"<<endl;
                               }else{
                                cout<<"Sorry, not enough stock!"<<endl;
                               }
                          }else{
                            cout<<"Sorry, This fruit is finished."<<endl;
                          }
                           right=true;
                           break;
                    }
                  }
                  if(!right){
                    cout<<"we have not that furit!"<<endl;
                    right=false;
                  }
              }
              else if (order1=="show")
              {
                  cin>>order2;
                 order2 = lower(order2);
                if(order2=="item"){
                  right=true;
                  string name;
                  int f , s;
                  while (!in.eof())
                  {
                    in>>name>>f>>s;
                    if(f>0){
                        cout<<name<<endl;
                    }
                  }in.close();
                  in.open("input.txt");
                }else{
                    string name;
                    int f,s;
                    while (!in.eof())
                    {
                        in>>name>>f>>s;
                        if(order2==name){
                            if(f>0){
                                cout<<name<<setw(5)<<f<<setw(5)<<s<<"$"<<endl;
                                right=true;
                                in.close();
                                in.open("input.txt");
                                break;
                            }
                        }
                    }
                    
                }
              
                if(!right){
                  cout<<"This fruit is not available"<<endl;
                  right=false;
                }
                
              }
              else if(order1=="balance"){
                       cout<<"you have "<<us->wallet<<"$"<<endl;
              }
              else if(order1=="help"){
                    fstream ord("orders.txt" , ios::in);
                cin>>order2;lower(order2);
                if(order2=="item"){
                   string name;
                  while (!ord.eof())
                  { 
                    ord>>name;
                    
                    cout<<name<<endl;
                    
                  }ord.close();
                  ord.open("input.txt");
                }else{
                
                if(order2=="show"){
                  cout<<"You can see the inventory"<<endl;
                }
                else if(order2=="buy"){
                  cout<<"You can buy the desired product"<<endl;
                }
                else if(order2=="balance"){
                  cout<<"You can see your account balance"<<endl;
                }
                else if(order2=="help"){
                  cout<<"It says what does each command do"<<endl;
                }
                else{
                  cout<<"is not a right commend!"<<endl;
                }
                }
                
              }
              else{
                   cout<<"is not a right order!!!"<<endl;
              }

          }
        }//else1*************************
        break;
      }
        
        
         
      
    }
    
    if(i==5 && order1!="-1"){
             cout<<"The password or username entered is wrong";
      }
    


    return 0;
}