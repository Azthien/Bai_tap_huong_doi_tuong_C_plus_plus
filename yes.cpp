#include <bits/stdc++.h>
using namespace std;
int UCLN(int A, int B) {
    if (B == 0)
        return A;
    return UCLN(B, A%B);
}
int BCNN(int a, int b){
	return a*b/ UCLN(a,b);
} 
class PhanSo{
	private : float TuSo,MauSo;
	public :
		int get_Mau(){
			return MauSo;
		}
		void Show(){
			if (TuSo != MauSo)
			cout<<TuSo<<"/"<<MauSo<<"\n";
			else if (TuSo==0){
				cout<<0<<"\n";
			}
			else{
				cout<<1<<"\n";
			}
		}
		void out(){
			if (TuSo != MauSo)
			cout<<TuSo<<"/"<<MauSo<<"\n";
			else if (TuSo==0){
				cout<<0<<"\n";
			}
			else{
				cout<<1<<"\n";
			}	
		}
		void Nhap(){
			cout<<"Nhap Tu So:\n";
			cin>>TuSo;
			cout<<"Nhap MauSo:\n";
			cin>>MauSo;
		}
		float set_TuSo(float x){
			return TuSo =x;
		}
		float set_MauSo(float x){
			return MauSo=x;
		}
		int operator >(PhanSo b){
			if (MauSo==b.MauSo){
				return TuSo>b.TuSo;
			}
			else{
			
				int x=BCNN(MauSo,b.MauSo);
				return TuSo *(x/MauSo) > b.TuSo *(x/b.MauSo);
			}
			
		}
		// Nap chong phep cong
		PhanSo operator + (int a){
			PhanSo kq;
			kq.TuSo = TuSo + a*MauSo;
			kq.MauSo=MauSo;
			return kq;
		}
		//Nap  chong phep cong 2 phan so
		PhanSo operator +=(PhanSo b){
			// neu a va b deu cung mau so thi chi can tinh cong
			PhanSo a;
			a.TuSo=TuSo;
			a.MauSo=MauSo;
			if (a.MauSo==b.MauSo){
				a.TuSo= a.TuSo+ b.TuSo;
				return a;
			}
			//neu khong thi phai quy dong
			else{
				// tim ra boi chung nho nhat cua 2 mau
				// neu mau a la bcnn thi phan so a khon doi
				int x=BCNN(a.MauSo,b.MauSo);
				a.TuSo= a.TuSo *(x/a.MauSo) + b.TuSo *(x/b.MauSo);
				a.MauSo= a.MauSo *(x/a.MauSo);
				return a;
			}
		}
		//rut gon phan so chu lam cc gi nua
		PhanSo rutgon(){
			PhanSo a;
			a.MauSo=MauSo;
			a.TuSo=TuSo;
			int x=UCLN(a.TuSo,a.MauSo);
			a.TuSo =a.TuSo /x;
			a.MauSo =a.MauSo/x;
			return a;
		}
		//nhu phep cong
		PhanSo operator - (int a){
			PhanSo kq;
			kq.TuSo = TuSo - a*MauSo;
			kq.MauSo=MauSo;
			return kq;
		}
		PhanSo operator * (int a){
			PhanSo kq;
			kq.TuSo = TuSo * a;
			kq.MauSo=MauSo;
			return kq;
		}
		PhanSo operator / (int a){
			
			PhanSo kq;
			kq.TuSo = TuSo;
			kq.MauSo=MauSo *a;
			
			return kq;
		}
		PhanSo operator /= (PhanSo a){
			PhanSo kq;
			kq.TuSo = TuSo *a.MauSo;
			kq.MauSo=MauSo *a.TuSo;
			return kq;
		}
		PhanSo operator *= (PhanSo a){
			PhanSo kq;
			kq.TuSo = TuSo * a.TuSo;
			kq.MauSo=MauSo * a.MauSo;
			return kq;
		}
		//nhu phep cong 2 phan so
		PhanSo operator -=(PhanSo b){
			// neu a va b deu cung mau so thi chi can tinh cong
			PhanSo a;
			a.TuSo=TuSo;
			a.MauSo=MauSo;
			if (a.MauSo==b.MauSo){
				a.TuSo= a.TuSo- b.TuSo;
				return a;
			}
			//neu khong thi phai quy dong
			else{
				// tim ra boi chung nho nhat cua 2 mau
				// neu mau a la bcnn thi phan so a khon doi
				int x=BCNN(a.MauSo,b.MauSo);
				a.TuSo= a.TuSo *(x/a.MauSo) - b.TuSo *(x/b.MauSo);
				a.MauSo= a.MauSo *(x/a.MauSo);
				return a;
			}
		}
		
};


int main(){
	cout<<"Nhap n phan so:\n";
	int n;
	cin>>n;
	PhanSo P[n];
	for (int i=0;i<n;i++){
		P[i].Nhap();
	}
	PhanSo s=P[0];
	for (int i=1;i<n;i++){
		s= s+=P[i];
	}
	cout<<"Tong phan so trong mang:\n";
	s=s.rutgon();
	s.Show();
	PhanSo max=P[0];
	for (int i=0;i<n;i++){
		if (P[i]>max){
			max=P[i];
		}
	}
	cout<<"Phan so lon nhat la\n";
	max.Show();
	return 0;
}
