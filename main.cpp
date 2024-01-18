 # include <iostream>
 # include <vector>
 # include <map>
 # include <string>
 #include <iterator>
 # include <algorithm>
 # include <math.h>
 #include <iomanip>
 
 

 using namespace std;























template <class t1, class t2>
ostream & operator <<(ostream &os,  const map<t1, t2> &m)
{
    cout<<"S.No. "<<"J.No "<<"  Name "<<endl<<endl;
    int i=1;
    for (const auto &p : m)
    {
        os <<left<<setw(8)<<setfill(' ')<<i<< left<<setw(5)<<setfill(' ')<<p.first << p.second<<endl;
        i++;
    }

    return os;
}


template <class t>
void change_strike( vector<t> &v1 )
{
    v1.insert(v1.begin(),v1[1]);
    
    v1.pop_back();

}



void show_over(vector <string> &v)
{
    cout<<"This Over :  | ";
    for (string x : v )
    {
        cout<<x<<" ";
    }
    cout<<endl;
}


void display_operations ()
{
cout<<endl;
cout<<"+-------------------------------------------------+"<<endl;
cout<<"|  KEY  |   OPERATION    |   KEY  |   OPERATION   |"<<endl;
cout<<"+-------+----------------+--------+---------------+"<<endl;
cout<<"|       |                |        |               |"<<endl;
cout<<"|   0   |  add nothing   |   10   |   Bouncer     |"<<endl;
cout<<"|       |                |        |               |"<<endl;
cout<<"|   1   |     add 1      |   11   |   No Ball     |"<<endl;
cout<<"|       |                |        |               |"<<endl;
cout<<"|   2   |     add 2      |   12   |    Wide       |"<<endl;
cout<<"|       |                |        |               |"<<endl;
cout<<"|   3   |     add 3      |   13   |    Bye        |"<<endl;
cout<<"|       |                |        |               |"<<endl;
cout<<"|   4   |     add 4      |   14   |   Leg Bye     |"<<endl;
cout<<"|       |                |        |               |"<<endl;
cout<<"|   5   |     add 5      |   15   |   Boundary    |"<<endl;
cout<<"|       |                |        |               |"<<endl;
cout<<"|   6   |     add 6      |   16   |   Wicket      |"<<endl;
cout<<"+-------------------------------------------------+"<<endl;
cout<<"|      ANY NEGATIVE INTEGER TO END ENTRIES        |"<<endl;
cout<<"+-------------------------------------------------+"<<endl;
cout<<endl;
}






template <class t1 , class t2> void print_table(const map <t1,t2> m)
{
    cout << left << setw(5) << setfill(' ') <<"J.No"<< left << setw(15) << setfill(' ') <<"     Name"<<endl;
    for (const auto &p: m)
    {
        cout << left << setw(9) << setfill(' ') <<p.first<< left << setw(15) << setfill(' ') <<p.second<<endl;
    }
}

//function call    print_tabular(map_name);







class bat_stat
{

    public:


        int total = 0;
        int balls = 0;
        float strike_rate = 0;
        int six = 0;
        int four = 0;

    float get_sr()
    {
        try
        {

            if (balls == 0)
            throw 0;

        return (total*(1.0)/balls)*100.00;
        }

        catch(int)
        {
            return 0;
        }
    }

    virtual void make_pure_virtual() = 0;



};






class bowling_stat
{

    public:

        int dots = 0;
        int over = 0;
        int wickets = 0;
        int runs = 0;
        int maiden = 0;

        float get_eco(int i)
        {
            try {
                if(i == 0 && over == 0)
                    throw over;

                else
                    throw 'a';

            }

            catch(int x)
            {
                return 0;
            }

            catch(...)
            {
                return (runs*(1.0))/((i/float(6))+over);
            }
        }

    virtual void make_pure_virtual() = 0;



};






class player_stat : public bat_stat , public bowling_stat
{


    public: 

    int status = -1 ;
    int j_no;


    private:

    virtual void make_pure_virtual(){};

};








class player 
{

    public:

    vector <int> j_no;

    map <int , string> p_id;
    map <int, player_stat* > player_data;
        
    player_stat* ptr = new player_stat[3];


    player()
    {
        
            int jn;
            string pn;
            int n=1;


        while(n<4)
        {

            cout<<"Fetching in details for player "<<n<<endl<<endl;
            
            cout<<"Jersey Number: ";
            cin>>jn;
            j_no.push_back(jn);

            cout<<"Name: ";
            cin>>pn;
            cout<<endl;
            

            p_id.insert( pair<int , string> (jn,pn));
            player_data.insert( pair<int , player_stat* > (jn, ptr+(n-1)));

            n++;
        }

    }

};











class team : public player
{

    public:


        string t_name;

        int overs = 0;
        int score = 0;
        int wicket = 0;
        int extra = 0;
        float run_rate = 0;

        float get_rr(int del)
        {
            float rr;

            try {

            if (overs==0 && del ==0)
                throw 0;

            rr = score*1.0/((overs*6.0)+del)*6.0;

            run_rate = rr;
            return run_rate;
            }

            catch (int ){

                run_rate = 0;

                return 0;

            }

        }

};









int main()
{

    

    int t_over;
    cout<<"Enter match length in overs:  \t";
    cin>>t_over;
    cout<<endl<<endl<<endl<<endl;
    string name1;
    cout<<"Enter Batting Team's Name: \t";
    cin>>name1;
    cout<<endl<<endl<<endl<<endl;

    string name2;
    cout<<"Enter Fielding Team's' Name: \t";
    cin>>name2;

    system("cls");

    cout<<"---  Enter Player Details for Team "<<name1<<"  ---"<<endl<<endl;

    team t1;
    t1.t_name = name1;

    system("cls");
    
    
    cout<<"---  Enter Player Details for Team "<<name2<<"  ---"<<endl<<endl;


    team t2;
    t2.t_name = name2;
    system("cls");
    
    int legal_del=0;
    int t_wicket=0;


    vector <int> current_batter;
 
    vector <int> current_bowler;

    cout<<t1.p_id;

    cout<<endl<<endl;

    int nb;

    cout<<"Choose 1st Opener Batter [J.No]: "<<endl;
                cin>>nb;
                current_batter.push_back(nb);
                map<int , player_stat* > :: iterator temp6 = (t1.player_data).find(nb);
                (*(temp6->second)).status  = 0;

    cout<<"Choose 2nd Opener Batter [J.No]"<<endl;
                cin>>nb;
                current_batter.push_back(nb);
                temp6 = (t1.player_data).find(nb);
                (*(temp6->second)).status  = 0;

    system("cls");


    cout<<t2.p_id;
    cout<<endl<<endl;
    cout<<"Choose Bowler[J. No]: "<<endl;
                cin>>nb;
                current_bowler.push_back(nb);
    








    while ( (legal_del < (t_over*6)) || (t_wicket < 10) )

    {


        int bouncer = 0;
        int sum_run = 0;
        int sum_extra = 0;

        vector <string> this_over;

        for(int i=0;i<6;i++)
        {

        legal_del++;


        int strike = 1;

            map<int , player_stat* > :: iterator temp9 = (t1.player_data).find(current_batter[0]);
            
            (*(temp9 -> second)).balls +=1 ;   

            
            vector<int> live;
            int x;
            int run = 0;
            int extra_run = 0;

            //TAKES VALES TILL -ve IS NOT DETECTED

            cin.ignore();

            system("cls");
            display_operations();

            
            while( cin>>x && x >= 0 )
            {


                if(x==0)
                {
                    map<int , player_stat* > :: iterator temp = (t2.player_data).find(current_bowler[0]);
                    (*(temp->second)).dots ++;
                }

            live.push_back(x);
            cin.ignore();
            }

            for(int z: live)
            {

                if(bouncer == 1 && z ==10)
                {
                    bouncer = 0;
                    z = 11;
                }

                switch (z)
                {
                    case 0:
                        this_over.push_back("0");
                        break;

                    case 1:
                        this_over.push_back("1");
                        run += 1;
                        strike *= -1;
                        break;

                    case 2:
                        this_over.push_back("2");
                        run += 2;
                        break;

                    case 3:
                        this_over.push_back("3");
                        run += 3;
                        strike *= -1;
                        break;

                    case 4:
                    
                        this_over.push_back("4");
                        run += 4;
                        break;

                    case 5:
                        this_over.push_back("5");
                        run += 5;
                        break;

                    case 6:
                        this_over.push_back("6");
                        run += 6;
                        break;

                    case 10:
                        
                        if (bouncer = 0);
                        {
                            this_over.push_back("0");
                            bouncer++;
                            break;
                        }



                    case 11:
                        this_over.push_back("NB");   
                        legal_del--;
                        extra_run++;
                        i--;
                        {
                            map<int , player_stat* > :: iterator temp = (t2.player_data).find(current_bowler[0]);
                            (*(temp->second)).dots--;
                            (*(temp->second)).runs++;
                        }
                        break;

                    case 12:
                        this_over.push_back("Wd");
                        legal_del--;
                        extra_run++;
                        i--;
                        if(1)
                        {
                            map<int , player_stat* > :: iterator temp = (t2.player_data).find(current_bowler[0]);
                            (*(temp->second)).dots--;
                            (*(temp->second)).runs++;

                        }
                        break;

                    case 13:
                        this_over.push_back("B");
                        extra_run += live[0];
                        run -= extra_run;
                        break;

                    case 14:
                        this_over.push_back("LB");
                        extra_run += live[0];
                        run -= extra_run;
                        break;

                    case 15:
                        
                        if(live[0] == 4)
                        {
                            if(live[1] != (13 || 14))
                            {
                                map<int , player_stat* > :: iterator temp = (t1.player_data).find(current_batter[0]);
                                (*(temp -> second)).four++;
                            }
                        }

                        if(live[0] == 6)
                        {
                            if(live[1] != (13 || 14))
                            {
                                map<int , player_stat* > :: iterator temp2 = (t1.player_data).find(current_batter[0]);
                                (*(temp2 -> second)).six++;
                            }
                        }

                        break;

                    case 16:
                        this_over.push_back("W");
                        if(1)
                        {
                        map<int , player_stat* > :: iterator temp4 = (t1.player_data).find(current_batter[0]);
                        (*(temp4 -> second)).status = 1;
                        map<int , player_stat* > :: iterator temp = (t2.player_data).find(current_bowler[0]);
                        (*(temp -> second)).wickets ++;
                        }
                        t_wicket++;
                        t1.wicket++;

                        break;
                }

            }

            this_over.push_back(" |");





        // batters data updation 



            t1.player_data[current_batter[0]]->total += run;
            t1.score += run;
            t1.score += extra_run;
            
            




            for(int i =0 ; i < current_batter.size() ; i++)
            {
                map<int , player_stat* > :: iterator temp3 = (t1.player_data).find(current_batter[i]);
                        
                if (t_wicket > 1) 
                {
                    cout<<endl<<"ALL OUT!"<<endl;
                    return 0;
                }

                if ( (*(temp3->second)).status  == 1 )
                {
                int nb;


                cout<<"Select new batsman: "<<endl;
                //displays only when key is -1
                cout<<left<<setw(6)<<setfill(' ')<<"J.No"<<"    "<<left<<setw(20)<<setfill(' ')<<"Name"<<endl;
                for(auto itr :  t1.player_data)
                {
                   if(  (itr.second)->status  == -1 )
                        cout<<left<<setw(6)<<setfill(' ')<<itr.first<<"    "<<left<<setw(20)<<setfill(' ')<<t1.p_id[itr.first]<<endl;

                }
                cin>>nb;

                map<int , player_stat* > :: iterator temp5 = (t1.player_data).find(nb);
                (*(temp5->second)).status  = 0;
                replace(current_batter.begin(),current_batter.end(),current_batter[i],nb);

                }

            }



            sum_run += run;
            sum_extra += extra_run;


            if ( strike == -1 )
            {
                change_strike(current_batter);
            }


        // bowlers data updation

            map<int , player_stat* > :: iterator itr_bowl = (t2.player_data).find(current_bowler[0]);

            (*(itr_bowl->second)).runs += run;
            cout<<endl<<endl;




cout<<"LIVE SCORE BOARD :"<<endl;
    

cout<<"------------------------------------------------------------------"<<endl;
cout<<t1.t_name<<"         | "<<t1.score<<"-"<<t1.wicket<<"  | "<<(legal_del/6)<<"."<<i+1<<"  |                  Run Rate:   "<<t1.get_rr(i+1)<<endl;
cout<<"------------------------------------------------------------------"<<endl;
cout<<"*"<<left<<setw(24)<<setfill(' ')<<t1.p_id[current_batter[0]]<<right<<setw(5)<<setfill(' ')<<(t1.player_data[current_batter[0]])->total<<" ["<<t1.player_data[current_batter[0]]->balls<<"]     "<<t1.player_data[current_batter[0]]->four<<"[4]    "<<t1.player_data[current_batter[0]]->six<<"[6]    "<<"     "<<"SR: "<<t1.player_data[current_batter[0]]->get_sr()<<endl;
cout<<" "<<left<<setw(24)<<setfill(' ')<<t1.p_id[current_batter[1]]<<right<<setw(5)<<setfill(' ')<<(t1.player_data[current_batter[1]])->total<<" ["<<t1.player_data[current_batter[1]]->balls<<"]     "<<t1.player_data[current_batter[1]]->four<<"[4]    "<<t1.player_data[current_batter[1]]->six<<"[6]    "<<"     "<<"SR: "<<t1.player_data[current_batter[1]]->get_sr()<<endl;
cout<<"------------------------------------------------------------------"<<endl;
show_over(this_over);
cout<<"------------------------------------------------------------------"<<endl;
cout<<t2.p_id[current_bowler[0]]<<"                  "<<(t2.player_data[current_bowler[0]])->runs<<"-"<<t2.player_data[current_bowler[0]]->wickets <<"             "<<t2.player_data[current_bowler[0]]->over<<"."<<i+1<<"               Eco: "<<t2.player_data[current_bowler[0]]->get_eco(i+1)<<endl;
cout<<"------------------------------------------------------------------"<<endl;


cout<<endl<<endl;


system("pause");


        }







        //over ends

        t_over++;

        map<int , player_stat* > :: iterator temp8 = (t2.player_data).find(current_bowler[0]);
        (*(temp8->second)).over ++;  


        //condition for maiden over
        if(sum_extra == 0 && sum_run ==0)
        {
          map<int , player_stat* > :: iterator temp7 = (t2.player_data).find(current_bowler[0]);

            (*(temp7->second)).maiden ++;  
        }


        // strike change due to over end
        change_strike(current_batter);
        for(int j=0 ; ; j++)
        {

        int new_bowler;


        if (legal_del < t_over*6 )
        {
            cout<<endl<<"INNING ENDS!"<<endl;
        return 0;
        }

        cout<<"Select new bowler: "<<endl;
        print_table(t2.p_id);
        cin>>new_bowler;
        if (new_bowler != current_bowler[0]){
        current_bowler.insert(current_bowler.begin(),new_bowler);
        current_bowler.pop_back();
        break;
        }

        else
        {
            cout<<"This Bowler cant bowl! Select diffrent bowler"<<endl;
        }


        }



        
    }
   










return 0;


}