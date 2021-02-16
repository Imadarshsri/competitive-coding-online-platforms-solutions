#include<iostream>
#include<string>
using namespace std;

int timeToInt(string t, string thr){
  int time = ((t[0] - '0')*10 + (t[1] - '0'))*100;

  if((time == 1200) && (thr[0] == 'A'))
    time -= 1200;
  else if((time != 1200) && (thr[0] == 'P'))
    time += 1200;

  time = time + ((t[3] - '0')*10) + (t[4] - '0');
  return time;
}

void solve(){
  string p, phr, ans = "";
  cin>>p>>phr;

  int pTime = timeToInt(p, phr);  int n = 0;
  cin>>n;
  while(n--){
    string l, lhr, r, rhr;
    cin>>l>>lhr>>r>>rhr;
    int lTime = timeToInt(l, lhr), rTime = timeToInt(r, rhr);
    if((lTime <= pTime) && (pTime <= rTime)) cout<<"1";
    else cout<<"0";
  }
  cout<<"\n";
}

int main(){
  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}