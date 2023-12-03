#include<bits/stdc++.h>
using namespace std;
int convert_int(string s){
    int num = 0, j = s.length();
    for(int i = 0; i < j; ++i)
        if(s[i] < 58 && s[i] > 47) num = num * 10 + s[i] - 48; 
    return num;
}
int convert_time(int time){
    return time / 10000 * 3600 + (time % 10000) / 100 * 60 + time % 100;
}
int user_prob[10005][105] = {}, user_errs[10005] = {}, user_points[10005] = {}, sub_time[86405] = {}, was_sub[86405] = {}, will_sub[86405] = {};
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int num_sub = 0, num_err = 0, point;
    string userID, poblemID, time, status, query, time1;
    cin >> userID;
    while(userID[0] != '#'){
        ++num_sub;
        cin >> poblemID >> time >> status >> point;
        ++sub_time[convert_time(convert_int(time))];
        if(status == "ERR"){
            ++user_errs[convert_int(userID)];
            ++num_err;
        }
        else{
            int uID = convert_int(userID), pID = convert_int(poblemID);
            user_prob[uID][pID] = max(user_prob[uID][pID], point);
        }
        cin >> userID;
    }
    for(int i = 1; i < 86403; ++i){
        was_sub[i] = was_sub[i-1] + sub_time[i-1];
        will_sub[i-1] = num_sub - was_sub[i];
    }
    cin >> query;
    while(query[0] != '#'){
        if(query[8] == 's'){
            cin >> time >> time1;
            cout << num_sub - was_sub[convert_time(convert_int(time))] - will_sub[convert_time(convert_int(time1))] << endl;
        }
        else if(query[1] == 'n'){
            if(query[23] != '\0'){
                cin >> userID;
                cout << user_errs[convert_int(userID)] << endl;
            }
            else{
                cout << num_err << endl;
            }
        }
        else if(query[7] == 'p'){
            cin >> userID;
            int uID = convert_int(userID);
            if(!user_points[uID]){
                for(int i = 0; i < 105; i++){
                    user_points[uID] += user_prob[uID][i];
                }
            }
            cout << user_points[uID] << endl;
        }
        else if(query[7] == 'n'){
            cout << num_sub << endl;
        }
        cin >> query;
    }
}