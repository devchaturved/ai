#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>inar,gar,dm;
// vector<vector<vector<int>>>
map<vector<vector<int>>,int>mp;
void func(vector<vector<vector<int>>> &v,int k){
	vector<vector<vector<int>>>pa1;
	vector<pair<int,vector<vector<int>>>>vp;
	cout<<"------------------------------------------"<<endl;
	// if(k>20){
	// 	cout<<"NO solution"<<endl;
	// 	return ;
	// }
	if(v.size()==0) {
		cout<<"NO solution"<<endl;return ;
	}
	for(int il=0;il<v.size();il++){
		vector<vector<int>>d=v[il];
		
		if(d==gar){
			cout<<"final state is achieved after " << k-1 << " steps"<<endl;
			// vector<vector<vector<int>>>ot;
			// ot.push_back(d);
			// return ot;
			return ;
		}
		int i1,j1;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(d[i][j]==-1){
					i1=i;j1=j;
				}
			}
		}
		int h;
		cout<<endl;
		cout<<"states after step "<<k+1<<" is "<<endl;
		if(i1-1>=0){
			d[i1][j1]=d[i1-1][j1];
			d[i1-1][j1]=-1;

			h=0;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<d[i][j]<<" ";
					if(gar[i][j]==-1){
					}
					else if(gar[i][j]!=d[i][j]) h++;
				}
				cout<<endl;
			}
			cout<<endl;

			if(mp[d]==0){
				mp[d]++;
				vp.push_back({k+h,d});
			}
			else cout<<"-----this state is repeating-----"<<endl;
				d[i1-1][j1]=d[i1][j1];
				d[i1][j1]=-1;
				cout<<"g(n) = "<<k<<endl;
				cout<<"h(n) = "<<h<<endl;
				cout<<"f(n) = "<<k+h<<endl<<endl;
				
		}
		if(i1+1<3){
			d[i1][j1]=d[i1+1][j1];
			d[i1+1][j1]=-1;

			h=0;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<d[i][j]<<" ";
					if(gar[i][j]==-1){
					}
					else if(gar[i][j]!=d[i][j]) h++;
				}
				cout<<endl;
			}
			cout<<endl;
			if(mp[d]==0){
				mp[d]++;
				vp.push_back({k+h,d});
			}
			else cout<<"-----this state is repeating-----"<<endl;
			d[i1+1][j1]=d[i1][j1];
			d[i1][j1]=-1;
			cout<<"g(n) = "<<k<<endl;
			cout<<"h(n) = "<<h<<endl;
			cout<<"f(n) = "<<k+h<<endl;
			cout<<endl;
		}
		if(j1-1>=0){
			d[i1][j1]=d[i1][j1-1];
			d[i1][j1-1]=-1;
			h=0;
			for(int i =0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<d[i][j]<<" ";
					if(gar[i][j]==-1){
					}
					else if(gar[i][j]!=d[i][j]) h++;
				}
				cout<<endl;
			}
			cout<<endl;
			if(mp[d]==0){
				mp[d]++;
				vp.push_back({k+h,d});
			}
			else cout<<"------this state is repeating------"<<endl;
			d[i1][j1-1]=d[i1][j1];
			d[i1][j1]=-1;
			cout<<"g(n) = "<<k<<endl;
			cout<<"h(n) = "<<h<<endl;
			cout<<"f(n) = "<<k+h<<endl;
			cout<<endl;
		}
		if(j1+1<3){
			d[i1][j1]=d[i1][j1+1];
			d[i1][j1+1]=-1;

			h=0;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<d[i][j]<<" ";
					if(gar[i][j]==-1){
					}
					else if(gar[i][j]!=d[i][j]) h++;
				}
				cout<<endl;
			}
			cout<<endl;
			if(mp[d]==0){
				mp[d]++;
				vp.push_back({k+h,d});
			}else{
				cout<<"-------this state is repeating-----"<<endl;
			}
			d[i1][j1+1]=d[i1][j1];
			d[i1][j1]=-1;
			cout<<"g(n) = "<<k<<endl;
			cout<<"h(n) = "<<h<<endl;
			cout<<"f(n) = "<<k+h<<endl;
			cout<<endl;
		}
		// sort(vp.begin(),vp.end());
		// pa1.push_back(vp[0].second);
		// cout<<endl;
		// for(auto xp : vp) cout<<xp.first<<" ";
		// cout<<endl;
		// for(int i=1;i<vp.size();i++){
		// 	if(vp[i].first==vp[i-1].first) pa1.push_back(vp[i].second);
		// 	else break;
		// }	
	}
	sort(vp.begin(),vp.end());
	pa1.push_back(vp[0].second);
	cout<<endl;
	for(auto xp : vp) cout<<xp.first<<" ";
	cout<<endl;
	for(int i=1;i<vp.size();i++){
		if(vp[i].first==vp[i-1].first) pa1.push_back(vp[i].second);
		else break;
	}
	// cout<<pa1.size()<<endl;
	// cout<<endl;
	cout<<"*******states with minimum huiristic values are ******** "<<endl;
	
	for(int i=0;i<pa1.size();i++){
		vector<vector<int>>pr=pa1[i];
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				cout<<pr[j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"f(n) = "<<vp[i].first<<endl;
	}
	func(pa1,k+1);
}
int main(){
	cout<<"enter initial state "<<endl;
	for(int i=0;i<3;i++){
		vector<int>v;
		for(int j=0;j<3;j++){
			int k;cin>>k;
			v.push_back(k);	
		}
		dm.push_back(v);
		inar.push_back(v);
	} 
	cout<<"enter final state "<<endl;
	for(int i=0;i<3;i++){
		vector<int>v1;
		for(int j=0;j<3;j++){
			int k;cin>>k;
			v1.push_back(k);
		}
		gar.push_back(v1);
	}
	vector<vector<vector<int>>>pa;
	pa.push_back(dm);int k=1;
	func(pa,k);
	return 0;
}