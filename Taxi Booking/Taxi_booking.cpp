#include <bits/stdc++.h>
using namespace std;

class Taxi{
    public:
        char initialPoint;
        int departureTime;
        int earnings;
        Taxi(){
            initialPoint='A';
            departureTime=0;
            earnings=0;
        }
        void setdepartureTime(int pickTime, char pick, char drop){
            this->departureTime=pickTime + abs(pick-drop);
        }
        void calculateEarnings(char pick, char drop){
            this->earnings =this->earnings + (((abs(pick-drop)*15)-5)*10)+100;
        }

};

class Booking{
    public:
        int pickTime;
        int dropTime;
        char pickUp;
        char dropUp;
        int earnings;
        int customerId;
        int taxiNo;
        Taxi taxi[];
        Booking(int id, char pick, char drop, int pickTime){
            this->customerId = id;
            this->pickUp=pick;
            this->dropUp=drop;
            this->pickTime=pickTime;
        }
        void setdropTime(){
            this->dropTime=pickTime + abs(pickUp-dropUp);
        }
        void calculateEarnings(){
            this->earnings = (((abs(pickUp-dropUp)*15)-5)*10)+100;
        }

        int isAvailable(Taxi t[]){
            int temp=0,min=6;
            for(int i=0;i<4;i++){
                int dis=abs(pickUp-t[i].initialPoint);
                if(pickTime>=t[i].departureTime){
                    if(dis<min){
                        temp=i;
                        min=abs(pickUp-t[i].initialPoint);

                    }
                    else if(dis==min){
                        if(t[i].earnings<t[temp].earnings){
                            temp=i;
                        }
                    }
                }
                
            }   
            if(min!=6){
                taxiNo=temp;
                t[temp].initialPoint=dropUp;
                t[temp].setdepartureTime(pickTime,pickUp,dropUp);
                return taxiNo;
            }
            return -1;
        }
};

int main(){
    Taxi t[4];
    vector<Booking> b;
    int i=0,j=0;
    while(true){
    int ch;
    cout<<"Taxi Booking"<<endl;
    cout<<"1"<<endl;
    cout<<"2"<<endl;
    cout<<"3"<<endl;
    cout<<"Enter Your choice"<<endl;
    cin>>ch;
    if(ch>=3||ch<1){
        if(ch!=3)
            cout<<"Invalid Input"<<endl;
        return 0;
    }
    else if(ch==1){
        int id,pickTime;
        char pick,drop;
        cout<<"Enter CustomerId"<<endl;
        cin>>id;
        cout<<"Pickup point"<<endl;
        cin>>pick;
        cout<<"Drop point"<<endl;
        cin>>drop;
        cout<<"Pickup Time"<<endl;
        cin>>pickTime;
        b.push_back(Booking(id,pick,drop,pickTime));
        int a=b[i].isAvailable(t);
        cout<<a;
        if(a!=-1){
            cout<<"Taxi "<<a<<endl;
            t[a].calculateEarnings(b[i].pickUp,b[i].dropUp);
            b[i].setdropTime();
            b[i].calculateEarnings();
        }
        else{
            cout<<"Booking is Rejected"<<endl;
        }
        i++;
    }
    else if(ch==2){
        cout<<"Taxi N.o:       Total Earnings:"<<endl;
        cout<<("BookingID   CustomerID  From    To  PickUpTime  DropTime    Amount")<<endl;
        for(int k=0;k<4;k++){
            if(t[k].earnings!=0){
                cout<<k+1<<"    " << t[k].earnings<<endl;
            }
        for(int m=0;m<i;m++){
            if(b[m].taxiNo==k){
                cout<<m+1 <<"   "<< b[m].customerId <<"  "<< b[m].pickUp <<"     "<< b[m].dropUp  <<"    "<< b[m].pickTime  <<"  "<< b[m].dropTime <<"   "<< b[m].earnings<<endl;
            }
        }
        }
    }
    else if(ch==3){
        return 0;
    }
    }
    return 0;
}

