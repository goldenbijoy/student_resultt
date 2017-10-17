#include <bits/stdc++.h>
using namespace std;

int valid_roll(string l, string k);
string find_result(string z,string k);

int main()
{
    map<int,string> mp;
    mp[1] = "1-1.txt";
    mp[2] = "1-2.txt";
    mp[3] = "2-1.txt";
    mp[4] = "2-2.txt";
    // add more

    cout<<"Welcome"<<endl;
    while(true){
        cout<<"Select index from below :\n";
        cout<<"1. 1st year 1st semester"<<endl;
        cout<<"2. 1st year 2nd semester"<<endl;
        cout<<"3. 2nd year 1st semester"<<endl;
        cout<<"4. 2nd year 2nd semester"<<endl;
        // add more
        int x;
        while(true){
            cin>>x;
            if(x>4/* change x value based on class */ || x<=0){
                cout<<"invalid selection. select again"<<endl;
                continue;
            }
            break;
        }
        string z;
        z = mp[x];
        string k,l;
        l = "CE-16018";
        while(true){
            cout<<"input the roll no of student as CE-16018"<<endl;
            cin>>k;
            x = valid_roll(l,k);
            if(x) break;
            else{
                cout<<"invalid roll no. enter again"<<endl;
                continue;
            }
        }
        string result;
        result = find_result(z,k);
        cout<<"result of roll "<<k<<" is "<<result<<endl;
        cout<<"if u want to search again press 1 else press anything"<<endl;
        cin>>x;
        if(x!=1) break;
        else{
            system("cls");
        }
    }

}

int valid_roll(string l,string k)
{
    string t,z;
    //cout<<l.size()<<" "<<k.size();
    if(l.size()!=k.size()) return 0;
    else{
        t = "CE-";
        z.push_back(k[0]);
        z.push_back(k[1]);
        z.push_back(k[2]);
        //cout<<t<<" "<<z<<endl;
        if(t!=z) return 0;
        if(k[3]<'0' || k[3]>'9') return 0;
        if(k[4]<'0' || k[3]>'9') return 0;
        if(k[5]<'0' || k[3]>'9') return 0;
        if(k[6]<'0' || k[3]>'9') return 0;
        if(k[7]<'0' || k[3]>'9') return 0;
        return 1;
    }
}

string find_result(string z,string k)
{
    string line,result;
    string p;
    p = "file/";
    z = p+z;
    int check = 0;
    ifstream myfile;
    //cout<<z<<endl;
    myfile.open(z);
    while(getline(myfile,line)){
        string z[3];
        //cout<<line<<endl;
        int x = 0;
        stringstream ss(line);
        while(ss>>z[x++]) ;
        if(z[0]==k){
            check = 1;
            result = z[1];
            break;
        }
    }
    myfile.close();
    if(check) return result;
    else return "not found";
}
