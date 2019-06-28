class Solution {
public:
  string removeDuplicates(string S) {
    int len=S.size();
    if (len==1) return S;
    for(int i=0;i<len-1;++i) {
      if (S[i]==' ') continue;
      if (S[i]==S[i+1]) {
        S[i]=S[i+1]=' ';
        while (true) {
          int pi=prei(S,i-1), ni=nexti(S,i+1);
          if (pi<0 || ni >=len) break;
          if (S[pi]==S[ni]) {
            S[pi]=S[ni]=' ';
          }
          else break;
        }
      }
    }
    string res;
    for(int i=0;i<len;++i) {
      if (S[i]!=' ') res+=S[i];
    }
    return res;
  }
  int nexti(string S, int i) {
    int len=S.size();
    while (i<len && S[i]==' ') ++i;
    return i;
  }
  int prei(string S, int i) {
    int len=S.size();
    while (i>=0 && S[i]==' ') --i;
    return i;
  }
};
