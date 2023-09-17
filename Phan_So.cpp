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
			cout<<"Phan so da duoc hien thi:\n"<<TuSo<<"/"<<MauSo<<"\n";
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
	PhanSo x;
	x.Nhap();
	while (2){
		if (x.get_Mau()==0){
			cout<<"Mau so bang 0 :)\n";
			cout<<"Thu lai lan sau :))";
			return 0;
		}
		cout<<"Nhap thao tac:\n0: ket thuc chuong trinh.\n1: Hien thi phan so\n";
		cout<<"2: Thay doi Tu hoac mau\n3: Neu muon thuc hien phep cong\n";
		cout<<"4: thuc hien phep tru\n5: Neu muon thuc hien phep nhan\n";
		cout<<"6: thuc hien phep chia\n";
		int so;
		cin>>so;
		if (so==0){
			break;
		}
		//so =1 : hien thi phan so 
		else if (so==1){
			x.Show();
		}
		//so ==2: thay doi tu hoac mau cua phan so 
		else if (so==2){
			float pos,val;
			cout<<"Nhap vao so ban muon thay doi\n";
			cin>>val;
			cout<<"Nhap 1 neu muon doi Tu so, Nhap 2 neu muon doi Mau so\n";
			cin>>pos;
			if (pos==1){
				x.set_TuSo(val);
			}
			else if (pos==2){
				x.set_MauSo(val);
			}
			cout<<"Da doi thanh cong :)\nPhan so hien tai la: ";
			x.out();
		}
		else if (so==3){
			cout<<"Nhap 1 neu muon cong voi mot so.\n2 neu muon cong 2 phan so\n";
			int pos;
			cin>>pos;
			if (pos ==1){
				cout<<"Nhap so can cong\n";
				int val;
				cin>>val;
				x=x+val;
			}
			else if (pos ==2){
				cout<<"Nhap phan so can cong\n";
				PhanSo y;
				y.Nhap();
				x=x+=y;
				x=x.rutgon();
			}
			cout<<"Da cong thanh cong :) \nPhan so hien tai la: ";
			x.out();
		}
		else if (so ==4){
			cout<<"Nhap 1 neu muon tru voi mot so.\n2 neu muon tru 2 phan so\n";
			int pos;
			cin>>pos;
			if (pos ==1){
				cout<<"Nhap so can tru\n";
				int val;
				cin>>val;
				x=x-val;
				
			}
			else if (pos ==2){
				cout<<"Nhap phan so can tru\n";
				PhanSo y;
				y.Nhap();
				x=x-=y;
				x=x.rutgon();
				
			}
			cout<<"Da tru thanh cong :)\nPhan so hien tai la: ";
			x.out();
		}
		else if (so ==5){
			cout<<"Nhap 1 neu muon nhan voi mot so.\n2 neu muon nhan 2 phan so\n";
			int pos;
			cin>>pos;
			if (pos ==1){
				cout<<"Nhap so can nhan\n";
				int val;
				cin>>val;
				x=x*val;
				x=x.rutgon();
				
			}
			else if (pos ==2){
				cout<<"Nhap phan so can nhan\n";
				PhanSo y;
				y.Nhap();
				x=x*=y;
				x=x.rutgon();
				
			}
			cout<<"Da Nhan :) \nPhan so hien tai la: ";
			x.out();
		}
		else if (so ==6){
			cout<<"Nhap 1 neu muon chia voi mot so.\n2 neu muon chia hai phan so\n";
			int pos;
			cin>>pos;
			if (pos ==1){
				cout<<"Nhap so can chia\n";
				int val;
				cin>>val;
				x=x/val;
				x=x.rutgon();
				
			}
			else if (pos ==2){
				cout<<"Nhap phan so can chia\n";
				PhanSo y;
				y.Nhap();
				x=x/=y;
				x=x.rutgon();
				
			}
			cout<<"Da chia hoan tat :) \nPhan so hien tai la: ";
			x.out();
		}
	}
	return 0;
}
