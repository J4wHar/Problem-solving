class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int nb_days = day - 1;
        for(int y=1971;y<year;++y){
            nb_days += 365 + (y%4 == 0);
        }
        for(int m=1;m<month;++m){
            if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10){
                nb_days += 31;
            }else if(m==2){
                nb_days += 28;
                //A leap year is exactly divisible by 4 except for century years
                if(year%100 == 0){  //
                    nb_days += ((year/100)%4 == 0);
                }else{
                    nb_days += (year%4 == 0);
                }
            }else{
                nb_days += 30;
            }
        }
        cout << nb_days << endl;
        string ans[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        switch(nb_days%7){
            case 0:
                return ans[5];
            case 1:
                return ans[6];
            case 2:
                return ans[0];
            case 3:
                return ans[1];
            case 4:
                return ans[2];
            case 5:
                return ans[3];
            case 6:
                return ans[4];
        }
        return "";
    }
};