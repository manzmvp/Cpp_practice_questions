// Toll Payment Processing:

// There are n number of points in a highway out of which some points collect toll.
// Each toll has its own charging scheme according to the vehicles and whether or not they
// are a VIP user.
// If they are VIP user, 20% discount apply.
// If the vehicle passes 3 toll gates, it has to pay in all the 3 toll gates according to the
// scheme of respective tolls.
// There were 4 modules.

// 1. Given the details of vehicle type, start and destinationdisplay the total toll paid during
// the journey and print the amount after applying the discount.

// 2. Display the details of all the tolls..like what are all the vehicles(vehicle number) passed
// that respective toll and the amount each vehicle paidand the total amount charged in
// that toll.

// 3. Display the details of all the vehicles.like what are all the journeys did it take the
// start and destination of the same tolls it passed during that journey.amount paid in
// that journey..and the total amount paid by that vehicle.

// 4. Assume the highway as a circular pathwe have to find the short route and identify
// the tolls between that route and calculate the amount.

#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> fee;

class Journey{
    public:
        int start;
        int destination;
        vector<int> path;
        float toll_amount=0;
        float amount_paid=0;
        Journey(int start,int destination,string type){
            this->start=start;
            this->destination=destination;
            string direction;
            if(start>destination){
                direction=abs(start-destination)<(6-abs(start-destination))?"AC":"C";
            }
            else{
                direction=abs(start-destination)<(6-abs(start-destination))?"C":"AC";
            }
            if(direction=="C"){
                int temp=start;
                while(temp!=destination){
                    if(temp==6){
                        (this->path).push_back(temp);
                        temp=1;
                        continue;
                    }
                    (this->path).push_back(temp);
                    temp++;
                }
                (this->path).push_back(temp);

            }
            else{
            int temp=start;
            while(temp!=destination){
                if(temp==1){
                    (this->path).push_back(temp);
                    temp=6;
                    continue;
                }
                (this->path).push_back(temp);
                temp--;
            }
            (this->path).push_back(destination);

        }
        for(auto num:path){
            this->toll_amount+=fee[num];
        }
        if(type=="VIP"){
            this->amount_paid=(80.0/100.0)*(this->toll_amount);
        }
        else{
            this->amount_paid=this->toll_amount;
        }
        }

        
};

class Receipt{
    public:
        int vehicle_number;
        string type;
        int toll_no;
        int toll_amount;
        int amount_paid;
        Receipt(int vehicle_number,string type,int toll_no){
            this->vehicle_number=vehicle_number;
            this->type=type;
            this->toll_no=toll_no;
            this->toll_amount=fee[this->toll_no];
            if(type=="VIP"){
                this->amount_paid=(80.0/100.0)*(this->toll_amount);
            }
            else{
                this->amount_paid=this->toll_amount;
            }
        }
};

class Vehicle{
    public:
        string type;
        int number;
        vector<Journey> data;
        Vehicle(int number, string type){
            this->number=number;
            this->type=type;
        }
};

class Toll{
    public:
        int toll_number;
        vector<Receipt> data;
        Toll(int toll_number){
            this->toll_number=toll_number;
        }
};

int main(){
    vector<Vehicle> Vehicle_list;
    fee[1]=1;
    fee[2]=2;
    fee[3]=3;
    fee[4]=4;
    fee[5]=5;
    fee[6]=6;
    vector<Toll> Toll_list;
    while(true){
    int ch;
    for(int i=1;i<7;i++){
        Toll_list.push_back(Toll(i));
    }
    cout<<"1. Calculate Route"<<endl;
    cout<<"2. Register Travel"<<endl;
    cout<<"3. Display Toll Details"<<endl;
    cout<<"4. Display Vehicle Details"<<endl;
    cout<<"5. Quit"<<endl;
    cout<<"Enter Choice: ";
    cin>>ch;
    if(ch==1){
        string type;
        int start,des;
        cout<<"Enter Vehicle type:";
        cin>>type;
        cout<<"Enter Start:";
        cin>>start;
        cout<<"Enter Destination:";
        cin>>des;
        Journey j = Journey(start,des,type);
        cout<<"Path: "<<endl;
        for(auto path:j.path){
            cout<<path<<endl;
        }
        cout<<"Total-toll-amount: "<<j.toll_amount;        
        cout<<"Total-amount-paid: "<<j.amount_paid;
    }
    else if(ch==2){
        string type;
        int num,start,des;
        cout<<"Enter Vehicle number:";
        cin>>num;
        cout<<"Enter Vehicle type:";
        cin>>type;
        cout<<"Enter Start:";
        cin>>start;
        cout<<"Enter Destination:";
        cin>>des;
        if(Vehicle_list.empty()){
            Vehicle n = Vehicle(num,type);
            Journey j=Journey(start,des,type);
            for(int i=0;i<j.path.size();i++){
                Toll_list[j.path[i] - 1].data.push_back(Receipt(num,type,j.path[i]));
            }
            n.data.push_back(j);
            Vehicle_list.push_back(n);
        }
        else{
            int flag=0;
            for(int i=0;i<Vehicle_list.size();i++){
                if(Vehicle_list[i].number == num){
                    Journey j = Journey(start,des,type);
                    Vehicle_list[i].data.push_back(j);
                    for(int i=0;i<j.path.size();i++){
                        Toll_list[j.path[i] - 1].data.push_back(Receipt(num,type,j.path[i]));
                    }
                    flag=1;
                    break;
            }
        }
            if(flag==0){
                Vehicle n = Vehicle(num,type);
                Journey j=Journey(start,des,type);
                for(int i=0;i<j.path.size();i++){
                    Toll_list[j.path[i] - 1].data.push_back(Receipt(num,type,j.path[i]));
                }
                n.data.push_back(j);
                Vehicle_list.push_back(n);
            }
    }
    }
    else if(ch==3){
        for(auto toll:Toll_list){
            if(!toll.data.empty()){
                cout<<"Toll N.o: "<<toll.toll_number<<endl;
                for(auto receipt:toll.data){
                    cout<<" Vehi N.o: "<<receipt.vehicle_number<<"     Total Amount: "<<receipt.toll_amount<<"      Amount paid: "<<receipt.amount_paid<<endl;
                }
            }
        }
    }
    else if(ch==4){
        for(auto vehicle:Vehicle_list){
            cout<<"Vehicle Number:"<<vehicle.number<<endl;
            int m=1;
            int sum=0;
            for(auto journey:vehicle.data){
                cout<<" Journey:"<<m<<endl;
                m++;
                cout<<"     Start:"<<journey.start<<endl;
                cout<<"     Destination:"<<journey.destination<<endl;
                cout<<"     Amount:"<<journey.amount_paid<<endl;
                sum+=journey.amount_paid;
            }
            cout<<" Total Amount Paid:"<<sum<<endl<<endl;
        }
    }
    else{
        return 0;
    }
    }
    return 0;
}