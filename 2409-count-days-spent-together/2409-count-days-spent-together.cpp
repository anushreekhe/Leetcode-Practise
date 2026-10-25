class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        static int no[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int aAm=stoi(arriveAlice.substr(0,2));
        int aAd=stoi(arriveAlice.substr(3,2));
        int lAm=stoi(leaveAlice.substr(0,2));
        int lAd=stoi(leaveAlice.substr(3,2));
        int daa=0;
        for(int i=0;i<aAm-1;i++) daa+=no[i];
        daa+=aAd-1;
        int dal=0;
        for(int i=lAm;i<12;i++) dal+=no[i];
        dal+=no[lAm-1]-lAd;
        vector<int> alice(365,1);
        for(int i=0;i<daa;i++) alice[i]=0;
        for(int i=365-1;i>=365-dal;i--) alice[i]=0;

        int abm=stoi(arriveBob.substr(0,2));
        int abd=stoi(arriveBob.substr(3,2));
        int lbm=stoi(leaveBob.substr(0,2));
        int lbd=stoi(leaveBob.substr(3,2));
        int dba=0;
        for(int i=0;i<abm-1;i++) dba+=no[i];
        dba+=abd-1;
        int dbl=0;
        for(int i=lbm;i<12;i++) dbl+=no[i];
        dbl+=no[lbm-1]-lbd;
        vector<int> bob(365,1);
        for(int i=0;i<dba;i++) bob[i]=0;
        for(int i=365-1;i>=365-dbl;i--) bob[i]=0;

        int count=0;
        for(int i=0;i<365;i++){
            if(alice[i]==1 && bob[i]==1) count+=1;
        }
        return count;
    }
};