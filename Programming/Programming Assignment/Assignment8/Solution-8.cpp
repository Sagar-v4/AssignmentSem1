#include <iostream>
#include <cstring>
using namespace std;

struct PLAYER{
    char first_name[50],last_name[50],name_of_game[50];
    int age;
}players[4];

struct Fraction{
    float p,q;
    void setData(float p,float q){
        this->p = p;
        this->q = q;
    }
    void add(struct Fraction f1,struct Fraction f2){
        if(f1.q == 0 || f2.q == 0){
            cout<<"Can't Perform Operation.";
            return;
        }
        float dem = f1.q * f2.q;
        float num = f1.p * (dem / f1.q) + f2.p * (dem /f2.q);
        cout<<endl<<f1.p << "/" << f1.q << "+" << f2.p << "/" <<f2.q <<" = " <<num <<"/" <<dem;
    }
    void sub(struct Fraction f1,struct Fraction f2){
        if(f1.q == 0 || f2.q == 0){
            cout<<"Can't Perform Operation.";
            return;
        }
        float dem = f1.q * f2.q;
        float num = f1.p * (dem / f1.q) - f2.p * (dem /f2.q);
        cout<<endl<<f1.p << "/" << f1.q << "-" << f2.p << "/" <<f2.q <<" = " <<num <<"/" <<dem;
    }
    void mul(struct Fraction f1,struct Fraction f2){
        if(f1.q == 0 || f2.q == 0){
            cout<<"Can't Perform Operation.";
            return;
        }
        float dem = f1.q * f2.q;
        float num = f1.p * f2.p;
        cout<<endl<<f1.p << "/" << f1.q << "*" << f2.p << "/" <<f2.q <<" = " <<num <<"/" <<dem;
    }
    void div(struct Fraction f1,struct Fraction f2){
        if(f1.q == 0 || f2.q == 0){
            cout<<"Can't Perform Operation.";
            return;
        }
        float dem = f1.q * f2.p;
        float num = f1.p * f2.q;
        cout<<endl<<f1.p << "/" << f1.q << "/" << f2.p << "/" <<f2.q <<" = " <<num <<"/" <<dem;
    }
};

struct Complex{
    int a,b;
    void setData(int a,int b){
        this->a = a;
        this->b = b;
    }
    void add(struct Complex c1,struct Complex c2){
        cout<<"\nAddition: "<<(c1.a + c2.a)<<"+"<<(c1.b+c2.b)<<"i";
    }
    void sub(struct Complex c1,struct Complex c2){
        cout<<"\nSubtraction: "<<(c1.a - c2.a)<<"+ ( "<<(c1.b-c2.b)<<" )i";
    }
    void mul(struct Complex c1,struct Complex c2){
        int p1 = (c1.a * c2.a) - (c1.b * c2.b);
        int p2 = (c1.a * c2.b) + (c1.b * c2.a);
        cout<<"\nMultiplication: "<<p1 << "+" <<p2<<"i";
    }
    void div(struct Complex c1,struct Complex c2){
        int p1 = (c1.a * c2.a) + (c1.b * c2.b);
        int p2 = (c1.b * c2.a) - (c1.a * c2.b);
        int divisor = (c2.a * c2.a) + (c2.b * c2.b);
        cout<<"\nDivision :"<<p1<<"/"<<divisor<< "+" <<p2<<"/"<<divisor<<"i";
    }
};

void Q1();
void Q2();
void Q3();
void Q4();
void Q5();
void Q6();

void printData();
void printDataPointer();
void sortByAge(struct PLAYER *);
void displayPlayers(struct PLAYER *);
struct PLAYER findPlayer(char name[50]);
bool findRecord(struct PLAYER *,struct PLAYER);

int main()
{
    Q1();
    Q2();
    Q3();
    Q4();
    Q5();
    Q6();
    return 0;
}

void Q1(){
    //a
    {
        printData();
    }
    //b
    {
        printDataPointer();
    }
    //c
    {
        for(int i=0;i<4;i++){
            cout<<"--- Enter Player "<<(i+1)<<" Details : ---";
            cout<<"\nEnter first name : ";
            cin.getline(players[i].first_name,50);
            cout<<"Enter Last name : ";
            cin.getline(players[i].last_name,50);
            cout<<"Enter Age : ";
            cin>>players[i].age;
            cin.ignore();
            cout<<"Enter name of game : ";
            cin.getline(players[i].name_of_game,50);
        }
        cout<<"\n\nQ1(c)";
        for(int i=0;i<4;i++){
            cout<<"\n\n------Player Details-----\nFirst Name : "<<players[i].first_name<<"\nLast Name : "<<players[i].last_name<<"\nAge : "<<players[i].age<<"\nName of the Game : "<<players[i].name_of_game;
        }
    }
    //d
    {
        cout<<"\n\nQ1(d)";
        displayPlayers(players);
    }
}

void Q2(){
    sortByAge(players);
}

void Q3(){
    char name[50];
    cout<<"\nEnter Player Name that you want to find : ";
    cin.getline(name,50);
    struct PLAYER p1 = findPlayer(name);
    if(!p1.age){
        cout<<"Player Not Found.";
    }
    else{
        cout<<"Player Found.";
    }
}

void Q4(){
    struct PLAYER p1;
    cout<<"\nEnter layer'sr First Name : ";
    cin.getline(p1.first_name,50);
    cout<<"Enter Player's Lasr Name : ";
    cin.getline(p1.last_name,50);

    cout<<"Enter Player's Age : ";
    cin>>p1.age;
    cin.ignore();
    cout<<"Enter Name of the Game : ";
    cin.getline(p1.name_of_game,50);

    if(findRecord(players,p1)){
        cout<<"Player Found.";
    }
    else{
        cout<<"Player Not Found.";
    }
}

void Q5(){
    float n1,n2;
    struct Fraction f1,f2,f3;
    cout<<"\nEnter Number 1 Numerator : ";
    cin>>n1;
    cout<<"Enter Number 1 Denominator : ";
    cin>>n2;
    f1.setData(n1,n2);
    cout<<"Enter Number 2 Numerator : ";
    cin>>n1;
    cout<<"Enter Number 2 Denominator : ";
    cin>>n2;
    f2.setData(n1,n2);
    f3.add(f1,f2);
    f3.sub(f1,f2);
    f3.mul(f1,f2);
    f3.div(f1,f2);
}

void Q6(){
    int a,b;
    struct Complex c1,c2,c3;
    cout<<"\nEnter a for c1 : " ;
    cin>>a;
    cout<<"Enter b for c1 : " ;
    cin>>b;
    c1.setData(a,b);
    cout<<"Enter a for c2 : " ;
    cin>>a;
    cout<<"Enter b for c2 : " ;
    cin>>b;
    c2.setData(a,b);
    cout<<"\n\nQ6:";
    c3.add(c1,c2);
    c3.sub(c1,c2);
    c3.mul(c1,c2);
    c3.div(c1,c2);
}

void printData(){
    struct PLAYER p1;
    cout<<"Enter Player's First Name : ";
    cin.getline(p1.first_name,50);
    cout<<"Enter Player's Last Name : ";
    cin.getline(p1.last_name,50);

    cout<<"Enter Player's Age : ";
    cin>>p1.age;
    cin.ignore();
    cout<<"Enter Name of the Game : ";
    cin.getline(p1.name_of_game,50);

    cout<<"\n\nQ1(a)\n------Player Details-----\nFirst Name : "<<p1.first_name<<"\nLast Name : "<<p1.last_name<<"\nAge : "<<p1.age<<"\nName of the Game : "<<p1.name_of_game<<endl;
}

void printDataPointer(){
    struct PLAYER *p1 = new struct PLAYER();
    cout<<"Enter Player's First Name : ";
    cin.getline(p1->first_name,50);
    cout<<"Enter Player's Last Name : ";
    cin.getline(p1->last_name,50);

    cout<<"Enter Player's Age : ";
    cin>>p1->age;
    cin.ignore();
    cout<<"Enter Name of the Game : ";
    cin.getline(p1->name_of_game,50);

    cout<<"\n\nQ1(b)\n------Player Details-----\nFirst Name : "<<p1->first_name<<"\nLast Name : "<<p1->last_name<<"\nAge : "<<p1->age<<"\nName of the Game : "<<p1->name_of_game;
}

void sortByAge(struct PLAYER *ptr){
    cout << "\nQ2"<<endl;
    cout<<ptr->first_name;
    for(int i=0;i<4;i++){
        for(int j=0;j<4-i-1;j++){
            if(ptr[j].age>ptr[j+1].age){
                struct PLAYER p1 = ptr[j];
                ptr[j]= ptr[j+1];
                ptr[j+1] = p1;
            }
        }
    }
    displayPlayers(players);
}

void displayPlayers(struct PLAYER *ptr){
    for(int i=0;i<4;i++){
            cout<<"\n\n------Player Details-----\nFirst Name : "<<ptr->first_name<<"\nLast Name : "<<ptr->last_name<<"\nAge : "<<ptr->age<<"\nName of the Game : "<<ptr->name_of_game;
            ptr++;
    }
}

struct PLAYER findPlayer(char name[50]){
    struct PLAYER p1;
    for(int i=0;i<4;i++){
        int match = strcmp(players[i].first_name,name);
        if(match == 0){
            return players[i];
        }
    }
    return p1;
}

bool findRecord(struct PLAYER *ptr,struct PLAYER p1){
    for(int i=0;i<4;i++){
        int f_name = strcmp(ptr->first_name,p1.first_name);
        int l_name = strcmp(ptr->last_name,p1.last_name);
        int game = strcmp(ptr->name_of_game,p1.name_of_game);
        if(f_name == 0 && l_name== 0 && game == 0 && ptr->age == p1.age){
            return true;
        }
        ptr++;
    }
    return false;
}
