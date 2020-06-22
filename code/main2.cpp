#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#include "phase_1_nlogn.hpp"

#define f first
#define s second

using namespace std;

int main() {

	srand(time(NULL));

	cout << setprecision(10) << fixed;

	/*int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	map<pair<int,int>,int> m;
	for(int i=0;i<1000;i++){
		m[phase_1_nlogn::random_inversion(v)]++;
	}
	cout<<phase_1_nlogn::inversions(v)<<endl;
	for(auto x:m)cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
	*/
	/*int n1,n2=0;
	cin>>n1;
	//cin>>n2;
	vector<line> h1(n1,line(0,0));
	vector<line> h2(n2,line(0,0));
	for(int i=0;i<n1;i++)cin>>h1[i].m>>h1[i].b;
	//for(int i=0;i<n2;i++)cin>>h2[i];
	int p1,p2;
	//cin>>p1>>p2;
	p1--;p2--;
	pair<double,double> t;
	cin>>t.first>>t.second;
	pair<line,line> sla=phase_1_nlogn::random_intersection(h1,t);
	cout<<sla.first.m<<" "<<sla.first.b<<endl;
	cout<<sla.second.m<<" "<<sla.second.b<<endl;
	cout<<point(sla.first,sla.second).x<<endl;
	cout<<phase_1_nlogn::intersections(h1,t)<<endl;
	//pair<double,double> resp=phase_1_nlogn::new_interval(h1,h2,p1,p2,t);
	//cout<<resp.first<<" "<<resp.second<<endl;*/
	

	
}