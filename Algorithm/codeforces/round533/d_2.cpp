/*
  Author:  raghav.blacklist1
*/

#include<bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define	ln(a,b)		((a==(b-1))?'\n':' ')
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define MAX			1000005

using namespace std;

int main(void){

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m,p;
  cin>>n>>m>>p;

  ll s[p];
  char mtr[n][m];
  rep(i,0,p)	cin>>s[i];

  string inp;
  rep(i,0,n){

    cin>>inp;
    rep(j,0,m)	mtr[i][j]=inp[j];
  }

  int mark[n][m];
  rep(i,0,n)	rep(j,0,m)	mark[i][j]=0;

  queue < pair <ll,ll> > q[p];
  ll ans[p]={0};

  rep(i,0,n)	rep(j,0,m){

    if(mtr[i][j]=='#')	mark[i][j]=1;
    if(mtr[i][j]=='.' || mtr[i][j]=='#')	continue;

    ans[mtr[i][j]-'1']++;
    mark[i][j]=1;

    if(i-1>=0 && mtr[i-1][j]=='.' && mark[i-1][j]==0){

      q[mtr[i][j]-'1'].push({i-1,j});
    }

    if(i+1<n && mtr[i+1][j]=='.' && mark[i+1][j]==0){

      q[mtr[i][j]-'1'].push({i+1,j});
    }

    if(j-1>=0 && mtr[i][j-1]=='.' && mark[i][j-1]==0){

      q[mtr[i][j]-'1'].push({i,j-1});
    }
    if(j+1<m && mtr[i][j+1]=='.' && mark[i][j+1]==0){

      q[mtr[i][j]-'1'].push({i,j+1});
    }
  }
  int flag=1;
  int mark1[p]={0};
  while(flag){

    rep(ply,0,p){

      rep(i,0,s[ply]){

        queue < pair <ll,ll> > tmp;
        while(!q[ply].empty()){

          auto it=q[ply].front();
          q[ply].pop();
          if(mark[it.F][it.S]==1)	continue;
					
          //cout<<"Player "<<ply+1<<" at "<<it.F<<' '<<it.S<<endl;
          mark[it.F][it.S]=1;
          ans[ply]++;
				

          if(it.F-1>=0 && mtr[it.F-1][it.S]=='.' && mark[it.F-1][it.S]==0){

            tmp.push({it.F-1,it.S});
          }

          if(it.F+1<n && mtr[it.F+1][it.S]=='.' && mark[it.F+1][it.S]==0){

            tmp.push({it.F+1,it.S});
          }

          if(it.S-1>=0 && mtr[it.F][it.S-1]=='.' && mark[it.F][it.S-1]==0){

            tmp.push({it.F,it.S-1});
          }
          if(it.S+1<m && mtr[it.F][it.S+1]=='.' && mark[it.F][it.S+1]==0){

            tmp.push({it.F,it.S+1});
          }
        }
        if(tmp.empty()){

          mark1[ply]=1;
          break;
        }
        while(!tmp.empty()){

          auto it=tmp.front();
          q[ply].push({it.F,it.S});
          tmp.pop();
        }

      }
      flag=0;
      rep(i,0,p)	if(mark1[i]==0)	flag=1;
    }
  }

  rep(i,0,p)	cout<<ans[i]<<ln(i,p);

  return 0;
}
